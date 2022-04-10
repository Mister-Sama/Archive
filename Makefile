CC = gcc
NAME = archive
SRC = $(shell find ./ -name "*.c")
OBJ = $(SRC:.c=.o)
ECHO = /bin/echo -e
INCLUDE = -I./include
FLAG = -g3 -llapin -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lstdc++ -lm -ldl -lpthread -lopencv_imgproc -lopencv_objdetect -lopencv_video -lopencv_core -lavcall -lusb -std=c11
BANFLAG = -Wextra -Wall -Werror

DEFLT	=	"\033[00m"
PINK	=	"\033[0;36m"
GREEN	=	"\033[1;32m"
TEAL	=	"\033[1;36m"
RED		=	"\033[0;31m"
BLINK 	= 	"\033[1;92m"
SBLINK	= 	"\033[0m"

all:$(NAME)

build :		$(ECHO) $(BLINK) "[SUCCESS]" $(DEFLT)

%.o : %.c
	@ $(CC) -o $@ -c $< $(INCLUDE) $(FLAG) $(BANFLAG) && \
	$(ECHO) $(BLINK) "[OK]"$(SBLINK) $(PINK) $< $(DEFLT) || \
	$(ECHO) $(RED) "[KO]" $(PINK) $< $(DEFLT)

$(NAME):$(OBJ)
	@ $(CC) -o $@ $^ $(INCLUDE) $(FLAG) $(BANFLAG) && \
	$(ECHO) $(BLINK) "[OK]"$(SBLINK) $(PINK) $< $(DEFLT) || \
	$(ECHO) $(RED) "[KO - OBJECT]" $(TEAL) $< $(DEFLT)

clean:
	@ find -name "*.o" -delete && find -name "*~" -delete && \
	$(ECHO) $(BLINK) "[CLEAN SUCCESS]" $(DEFLT)

fclean:
	@find . -name "*.so" -delete -or -name "*.exe" -delete \
	-or -name "*.a" -delete -or -name "*.o" -delete    \
	-or -name "*~" -delete
	@$(ECHO) $(GREEN) "All temporal file deleted!" $(DEFLT)
	@rm $(NAME)
	@$(ECHO) $(GREEN) Executable deleted!" $(DEFLT)

re: 	fclean all

run: $(OUT)
	./$(OUT)

w:
	$(CC) $(SRC) -o $(NAME) $(INCLUDE) $(FLAG)