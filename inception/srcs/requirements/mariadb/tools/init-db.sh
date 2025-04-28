#!/bin/sh
echo "Starting MariaDB..."
mariadb-install-db --user=mysql --datadir=/var/lib/mysql > /dev/null 2> /dev/null
mariadbd --user=mysql &

while ! mariadb -u root -h localhost -p${MYSQL_ROOT_PASSWORD} -e "SELECT 1;" >/dev/null 2>&1; do
    echo "Waiting for MariaDB to be ready..."
    sleep 1
done

# Check if the database exists
DB_EXISTS=$(mariadb -u root -h localhost -p${MYSQL_ROOT_PASSWORD} -e "SHOW DATABASES LIKE '${MYSQL_DATABASE}';" | grep "${MYSQL_DATABASE}")

# Check for import at first boot
if [ -z "$DB_EXISTS" ]; then
    echo "Database ${MYSQL_DATABASE} does not exist. Proceeding with configuration..."
    mariadb -u root -h localhost -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}'; FLUSH PRIVILEGES;"
    mariadb -u root -h localhost -p${MYSQL_ROOT_PASSWORD} -e "
        CREATE DATABASE ${MYSQL_DATABASE};
        CREATE USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
        GRANT ALL PRIVILEGES ON *.* TO '${MYSQL_USER}'@'%';
        FLUSH PRIVILEGES;"
    echo "Done creating database"
fi

wait
