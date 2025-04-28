REQ = srcs/requirements

COMPOSEFILE = srcs/docker-compose.yml
COMPOSER = docker compose

SRC =	$(COMPOSEFILE) \
		$(REQ)/mariadb/Dockerfile \
		$(REQ)/nginx/Dockerfile \
		# $(REQ)/wordpress/Dockerfile \

CONFIG =	srcs/.env \

VOLUMES =	srcs_mariadb \
			srcs_wordpress \

DOCKER_IMG =	srcs-mariadb \
				srcs-wordpress \
				srcs-nginx

VOLUME_BIND =	~/data/mariadb \
				~/data/wordpress \


up: $(SRC) $(CONFIG)
		@mkdir -p $(VOLUME_BIND)
		@$(COMPOSER) -f $(COMPOSEFILE) up -d

down: $(SRC)
		@$(COMPOSER) -f $(COMPOSEFILE) down

clean:
		@$(MAKE) down --no-print-directory || echo -n

fclean: clean
		@docker volume rm $(VOLUMES) 2> /dev/null || echo -n
		@docker image rm $(DOCKER_IMG) || true
		@sudo rm -rf $(VOLUME_BIND) || true
		@sudo rm -rf /var/lib/docker/volumes/srcs_* || true

.PHONY = all clean fclean up down
