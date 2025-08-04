COMPOSE_FILE := ./srcs/docker-compose.yml
NAME := docker_compose
GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \033[1;33m
NC := \033[0m

.PHONY: build down restart clean kill fclean

build:
	mkdir -p /home/thgaugai/data/mariadb
	mkdir -p /home/thgaugai/data/wordpress
	@echo "$(GREEN)Building images...$(NC)"
	docker-compose -f $(COMPOSE_FILE) up --build -d

kill:
	@echo "$(RED)Killing services...$(NC)"
	docker-compose -f $(COMPOSE_FILE) kill

down:
	@echo "$(RED)Discontinuation of services...$(NC)"
	docker-compose -f $(COMPOSE_FILE) down

clean:
	@echo "$(RED)Cleaning docker resources...$(NC)"
	docker-compose -f $(COMPOSE_FILE) down -v

fclean: clean
	@echo "$(RED)Full clean...$(NC)"
	rm -r /home/thgaugai/data/mariadb
	rm -r /home/thgaugai/data/wordpress
	docker system prune -a -f

restart: clean build



