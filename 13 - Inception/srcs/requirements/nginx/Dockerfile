FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y && \
    apt-get install -y nginx openssl && \
    mkdir -p /etc/nginx/ssl && \
    openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt \
    -keyout /etc/nginx/ssl/inception.key \
    -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=thgaugai.42.fr/UID=login" && \
    mkdir -p /var/run/nginx && \
    mkdir -p /var/www/wordpress && \
    chmod 755 /var/www/wordpress && \
    chown -R www-data:www-data /var/www/wordpress

COPY conf/default.conf /etc/nginx/nginx.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
