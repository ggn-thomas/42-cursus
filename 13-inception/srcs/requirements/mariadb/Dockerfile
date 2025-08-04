# Container basé sur Debian
FROM debian:bullseye

# Variables d'environnement
ARG MYSQL_DATABASE
ARG MYSQL_USER  
ARG MYSQL_PASSWORD
ARG MYSQL_ROOT_PASSWORD

ENV MYSQL_DATABASE=$MYSQL_DATABASE
ENV MYSQL_USER=$MYSQL_USER
ENV MYSQL_PASSWORD=$MYSQL_PASSWORD
ENV MYSQL_ROOT_PASSWORD=$MYSQL_ROOT_PASSWORD

# Installation de MariaDB
RUN apt update -y && \
    apt upgrade -y && \
    apt install mariadb-server mariadb-client -y && \
    apt clean

# Créer les répertoires nécessaires
RUN mkdir -p /run/mysqld && \
    chown mysql:mysql /run/mysqld && \
    mkdir -p /var/log/mysql && \
    chown mysql:mysql /var/log/mysql

# Copier les fichiers de configuration
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# Initialiser la base de données
RUN mysql_install_db --user=mysql --basedir=/usr --datadir=/var/lib/mysql

# Exposer le port
EXPOSE 3306

# Script de démarrage
COPY tools/script.sh /script.sh
RUN chmod +x /script.sh

# Point d'entrée
ENTRYPOINT ["/script.sh"]