#!/bin/bash

# Démarrer MariaDB en arrière-plan
mysqld_safe --user=mysql &

# Attendre que MariaDB soit prêt
echo "Attente du démarrage de MariaDB..."
until mysqladmin ping --silent; do
    sleep 1
done

echo "MariaDB est prêt, configuration de la base de données..."

# Configuration de la base de données
mysql -u root << EOF
CREATE DATABASE IF NOT EXISTS \`$MYSQL_DATABASE\`;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON \`$MYSQL_DATABASE\`.* TO '$MYSQL_USER'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
FLUSH PRIVILEGES;
EOF

echo "Base de données configurée avec succès!"

# Arrêter MariaDB pour le redémarrer proprement
mysqladmin -u root -p$MYSQL_ROOT_PASSWORD shutdown

# Démarrer MariaDB en premier plan
exec mysqld_safe --user=mysql