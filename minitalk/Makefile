# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 17:54:07 by rezzahra          #+#    #+#              #
#    Updated: 2022/01/04 18:30:57 by rezzahra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
SERVER=server
CLIENT=client
CLIENTSRC=client.c
SERVERSRC=server.c
CLIENTOBJ=$(CLIENTSRC:.c=.o)
SERVEROBJ=$(SERVERSRC:.c=.o)

FLAGS=-Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

bonus: all

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@
	
$(CLIENT): $(CLIENTOBJ)
	$(CC) $(FLAGS) $(CLIENTOBJ) -o $(CLIENT)
	
$(SERVER): $(SERVEROBJ)
	$(CC) $(FLAGS) $(SERVEROBJ) -o $(SERVER)
clean:
	rm -f *.o

fclean:	clean
	rm -rf $(CLIENT) $(SERVER)

re:	fclean all
