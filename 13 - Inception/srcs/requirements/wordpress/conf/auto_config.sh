#!/bin/bash

echo "Attente de MariaDB..."
sleep 15

cd /var/www/wordpress

rm -f wp-config.php

echo "Test de connexion à la base de données..."
until mysql -h mariadb -u $WORDPRESS_DB_USER -p$WORDPRESS_DB_PASSWORD -e "SELECT 1" >/dev/null 2>&1; do
    echo "En attente de la base de données..."
    sleep 5
done

echo "Base de données accessible, création de wp-config.php..."

# Créer wp-config.php
wp config create --allow-root \
    --dbname=$WORDPRESS_DB_NAME \
    --dbuser=$WORDPRESS_DB_USER \
    --dbpass=$WORDPRESS_DB_PASSWORD \
    --dbhost=mariadb:3306 \
    --path='/var/www/wordpress'

# Vérifier si WordPress est déjà installé
if ! wp core is-installed --allow-root --path='/var/www/wordpress' 2>/dev/null; then
    echo "Installation de WordPress..."
    
    # Installer WordPress
    wp core install --allow-root \
        --url=$WORDPRESS_URL \
        --title="$WORDPRESS_TITLE" \
        --admin_user=$WORDPRESS_ADMIN_USER \
        --admin_password=$WORDPRESS_ADMIN_PASSWORD \
        --admin_email=$WORDPRESS_ADMIN_EMAIL \
        --path='/var/www/wordpress'
        
    echo "WordPress installé avec succès!"
else
    echo "WordPress déjà installé."
fi

# Changer les permissions
chown -R www-data:www-data /var/www/wordpress
chmod -R 755 /var/www/wordpress

echo "Configuration de PHP-FPM..."

# Configurer PHP-FPM pour écouter sur toutes les interfaces
sed -i 's/listen = \/run\/php\/php7.4-fpm.sock/listen = 0.0.0.0:9000/g' /etc/php/7.4/fpm/pool.d/www.conf
sed -i 's/listen.allowed_clients = 127.0.0.1/;listen.allowed_clients = 127.0.0.1/g' /etc/php/7.4/fpm/pool.d/www.conf

echo "Démarrage de PHP-FPM..."

# Créer le répertoire pour PHP-FPM
mkdir -p /run/php

# Démarrer PHP-FPM en premier plan
php-fpm7.4 -F