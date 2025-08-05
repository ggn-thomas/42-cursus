#!/bin/bash

mysqld_safe --user=mysql &

echo "Attente du démarrage de MariaDB..."
until mysqladmin ping --silent; do
    sleep 1
done

echo "MariaDB est prêt, configuration de la base de données..."

mysql -u root << EOF
CREATE DATABASE IF NOT EXISTS \`$MYSQL_DATABASE\`;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON \`$MYSQL_DATABASE\`.* TO '$MYSQL_USER'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
FLUSH PRIVILEGES;
EOF

echo "Base de données configurée avec succès!"

mysqladmin -u root -p$MYSQL_ROOT_PASSWORD shutdown

exec mysqld_safe --user=mysql