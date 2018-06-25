NAME		=	ft_retro
FLAGS		=	-Wall -Wextra -Werror
CC			=	clang++ $(FLAGS)

SRC_DIR		=	./src/

SRC_FILES	=	main.cpp \
				GameObject.class.cpp \
				Player.class.cpp \
				Asteroid.class.cpp \
				Bullet.class.cpp \
				Game.class.cpp \
				Star.class.cpp

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(SRC:.cpp=.o)

INCLUDES 	=	-I./include

LINKS		=	-lncurses

all: $(NAME)

.cpp.o: $(SRC)
	@ $(CC) $(INCLUDES) -c $^ -o $@

$(NAME): $(OBJ)
	@ $(CC) $(OBJ) $(LINKS) -o $(NAME)
	@ echo "[+] [$(NAME)] compiled"

clean:
	@ /bin/rm -rf $(OBJ)
	@ echo "[+] [$(NAME)] .o files deleted"

fclean: clean
	@ /bin/rm -rf $(NAME)
	@ echo "[+] [$(NAME)] binary files deleted"

re: fclean all

.PHONY : re fclean clean all