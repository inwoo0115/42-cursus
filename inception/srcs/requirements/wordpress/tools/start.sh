#!/bin/bash

ln -s /usr/bin/php81 /usr/bin/php

if [ ! -e "/var/www/html/wp-config.php" ]; then #wordpress 설치여부 확인
	mkdir -p /var/www/html
	cd /var/www/html
	wp core download --allow-root
	wp config create --dbname=$WP_DB_NAME --dbuser=$WP_ADMIN --dbpass=$WP_ADMIN_PASSWORD --dbhost=$MARIADB_HOSTNAME --skip-check
	wp core install --url=$WP_URL --title=$WP_TITLE --admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL
	wp user create $WP_USER $WP_USER_EMAIL --user_pass=$WP_USER_PASSWORD
fi

echo "Wordpress started on :9000"
/usr/sbin/php-fpm81 -F #forground로 실행