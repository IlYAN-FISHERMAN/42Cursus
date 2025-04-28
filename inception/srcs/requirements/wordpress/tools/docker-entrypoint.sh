while ! mysql -u ${MYSQL_USER} -h ${MYSQL_HOST} -p${MYSQL_PASSWORD} ${MYSQL_DATABASE} -e "SELECT 1;" >/dev/null 2>&1; do
    echo "Waiting for MariaDB to be ready..."
    sleep 1
done

cd /var/www/wordpress
if [ -e wp-config-sample.php ]; then
	sleep 3
	wp core install --url=$DOM_NAME/ \
						--title=$SITE_TITLE\
						--admin_user=$WP_ADMINNAME\
						--admin_password=$WP_ADMINPASS\
						--admin_email=$WP_ADMINMAIL\
						--skip-email\
						--allow-root
	wp user create	$WP_USER\
						$WP_MAIL\
						--user_pass=$WP_USERPASS\
						--role=author\
						--allow-root
	rm wp-config-sample.php
fi

echo "Starting Wordpress"
php-fpm83 -F
