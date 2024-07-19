all:
	mkdir -p /Users/wonjilee/42-cursus/inception/wordpress
	mkdir -p /Users/wonjilee/42-cursus/inception/mariadb
	docker-compose up

build:
	mkdir -p /Users/wonjilee/42-cursus/inception/wordpress
	mkdir -p /Users/wonjilee/42-cursus/inception/mariadb
	docker-compose up --build

down:
	docker-compose down -v

re: down
	docker-compose up --build

clean:
	docker stop $(docker ps -qa) 2>/dev/null || true
	docker rm $(docker ps -qa) 2>/dev/null || true
	docker rmi -f $(docker images -q) 2>/dev/null || true
	docker volume rm $(docker volume ls -q) 2>/dev/null || true
	docker network rm $(docker network ls -q) 2>/dev/null || true

fclean: 
	docker stop $(docker ps -qa) 2>/dev/null || true
	docker rm $(docker ps -qa) 2>/dev/null || true
	docker rmi -f $(docker images -q) 2>/dev/null || true
	docker volume rm $(docker volume ls -q) 2>/dev/null || true
	docker network rm $(docker network ls -q) 2>/dev/null || true
	rm -rf /Users/wonjilee/42-cursus/inception/wordpress
	rm -rf /Users/wonjilee/42-cursus/inception/mariadb

.PHONY	: all build down re clean fclean