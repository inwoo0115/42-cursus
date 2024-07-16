all:
	mkdir -p /Users/wonjilee/42-cursus/inception/wordpress
	mkdir -p /Users/wonjilee/42-cursus/inception/mariadb
	docker-compose up

build:
	mkdir -p /Users/wonjilee/42-cursus/inception/wordpress
	mkdir -p /Users/wonjilee/42-cursus/inception/wordpress
	docker-compose up --build

down:
	docker-compose down

re: down
	docker-compose up --build

clean: down
	docker system prune -a

fclean:
	docker-compose down -v
	docker system prune --all --force --volumes
	rm -rf /Users/wonjilee/42-cursus/inception/wordpress
	rm -rf /Users/wonjilee/42-cursus/inception/mariadb

.PHONY	: all build down re clean fclean