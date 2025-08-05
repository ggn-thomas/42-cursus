FROM debian:bullseye


ARG MYSQL_DATABASE
ARG MYSQL_USER  
ARG MYSQL_PASSWORD
ARG MYSQL_ROOT_PASSWORD

ENV MYSQL_DATABASE=$MYSQL_DATABASE
ENV MYSQL_USER=$MYSQL_USER
ENV MYSQL_PASSWORD=$MYSQL_PASSWORD
ENV MYSQL_ROOT_PASSWORD=$MYSQL_ROOT_PASSWORD

RUN apt update -y && \
    apt upgrade -y && \
    apt install mariadb-server mariadb-client -y && \
    apt clean

RUN mkdir -p /run/mysqld && \
    chown mysql:mysql /run/mysqld && \
    mkdir -p /var/log/mysql && \
    chown mysql:mysql /var/log/mysql

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

RUN mysql_install_db --user=mysql --basedir=/usr --datadir=/var/lib/mysql

EXPOSE 3306

COPY tools/script.sh /script.sh
RUN chmod +x /script.sh

ENTRYPOINT ["/script.sh"]