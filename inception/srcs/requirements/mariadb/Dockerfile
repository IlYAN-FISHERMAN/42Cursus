FROM alpine:3.20

RUN apk update && apk upgrade && \
    apk add vim mariadb mariadb-client

RUN mkdir -p /var/lib/mysql
RUN mkdir -p /run/mysqld
RUN chown -R mysql:mysql /var/lib/mysql
RUN chown -R mysql:mysql /run/mysqld
COPY conf/mariadb.conf	/etc/mysql/mariadb.conf.d/mariadb.conf
COPY tools/init-db.sh	/etc/mysql/tools/init-db.sh
RUN mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm

EXPOSE 3306
ENTRYPOINT ["sh", "/etc/mysql/tools/init-db.sh"]
