#!/bin/bash

if [ ! -e "/run/mysqld/mysqld.sock" ]; then #mariadb가 실행 중 인지 확인
	#https://mariadb.com/kb/en/mariadb-install-db/
	#mysqld_safe Starting mariadbd daemon with databases from /var/lib/mysql
	mariadb-install-db --user=mysql --datadir=/var/lib/mysql --skip-test-db
	mkdir -p /run/mysqld
	mysqld & #백그라운드에서 실행

	#https://stackoverflow.com/questions/25503412/how-do-i-know-when-my-docker-mysql-container-is-up-and-mysql-is-ready-for-taking
	while ! mysqladmin ping; do #서버가 준비됬는지 확인
		sleep 1
	done

	#https://snowple.tistory.com/260
	#https://dev.mysql.com/doc/refman/8.0/en/resetting-permissions.html
	mysql -uroot --skip-password -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MARIADB_ROOT_PASSWORD';"
	mysql -uroot -p$MARIADB_ROOT_PASSWORD -e "CREATE DATABASE IF NOT EXISTS $WP_DB_NAME;"
	mysql -uroot -p$MARIADB_ROOT_PASSWORD -e "GRANT ALL PRIVILEGES ON $WP_DB_NAME.* TO '$WP_ADMIN'@'%' IDENTIFIED BY '$WP_ADMIN_PASSWORD';"
	#apply
	mysql -uroot -p$MARIADB_ROOT_PASSWORD -e "FLUSH PRIVILEGES;"
	mysqladmin -uroot -p$MARIADB_ROOT_PASSWORD shutdown
fi

exec mysqld #메인 프로세스로 전환