FROM alpine:3.20

RUN apk update && apk upgrade && \
    apk add vim nginx curl openssl

RUN mkdir -p /etc/nginx/ssl
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=CH/ST=VAUD/L=Lausanne/O=42/OU=42/CN=ilyanar.42.fr/UID=ilyanar"
RUN mkdir -p /var/run/nginx 

RUN mkdir -p /var/www/html
RUN chmod 755 /var/www/html

RUN adduser -S -G www-data www-data || true
RUN chown -R www-data:www-data /var/www/html
ENTRYPOINT ["nginx", "-g", "daemon off;"]
