##
## EPSI PROJET, 2020
## GOULARD DE LACAM BAPTISTE
## VIRTUALIZED CHIPS
##

CPP_LDFLAGS	= 	-lsfml-graphics -lsfml-window -lsfml-system

CPP_PCFLAGS	=	-I ./include -std=c++17

CPP_NFLAGS	=	-Wall -Wextra

CPPFLAGS	=	$(CPP_NFLAGS) $(CPP_PCFLAGS) $(CPP_LDFLAGS)

ifneq ($(DEBUG),)
        ifeq ($(DEBUG),1)
                CPP_NFLAGS += -g1
        else ifeq ($(DEBUG),2)
                CPP_NFLAGS += -g2
        else ifeq ($(DEBUG),3)
                CPP_NFLAGS += -g3
        else ifeq ($(DEBUG),gdb)
                CPP_NFLAGS += -ggdb
        else
                CPP_NFLAGS += -g
        endif
endif

SRCDIR	=	$(realpath src)

SRC		=	$(wildcard $(SRCDIR)/*.cpp)

OBJ		=	$(SRC:.cpp=.o)

NAME	=	VCHIPS

CC	=	g++

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
clean:
	-rm $(OBJ)
fclean:	clean
	-rm $(NAME)
re:fclean all

.PHONY: re fclean clean
