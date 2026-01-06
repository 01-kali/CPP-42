#Special Built-in Target
.PHONY: all clean fclean re
.SECONDARY:

#the main fail name
NAME = form

#wish compiler you prefer
CPP = c++

#the header files path
INC = -I./ 

#the flags that i need
CPPFLAGS = $(INC)  -Wall -Wextra -Werror -std=c++98

#creat source and object files
CPPDIRS = .
ODIRS = .bin
SRC = $(foreach dir, $(CPPDIRS), $(wildcard $(dir)/*.cpp))
OBJ = $(patsubst %.cpp, $(ODIRS)/%.o, $(notdir $(SRC)))
vpath %.cpp $(CPPDIRS)

#clean
CL = cl

#fclean
FCL = fcl

#creat form file
all:
	$(call fk_left,$(NAME),all)

#clean all the object files
clean:
	$(call fk_left,$(CL),clean)

#clean the object files and form file
fclean: 
	$(call fk_left,$(FCL),fclean)

#target to full clean and recompil
re: fclean all

#the rule to creat form file
$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

#how to creat the object files
$(ODIRS)/%.o: %.cpp | $(ODIRS)
	$(CPP) $(CPPFLAGS) -c $< -o $@

#creat the object files folder
$(ODIRS):
	mkdir $(ODIRS)

#how to clear object files
$(CL):
	rm -fr $(ODIRS)

#how to remove the object files and the main file
$(FCL):
	rm -fr $(ODIRS) $(NAME)

#reusable scripe to made an animation when make a target
define fk_left
@if [ "$2" = "bonus" ] || [ "$2" = "all" ]; then \
	if make -q $1; then \
	    echo "$1 is up to date."; \
			exit 0; \
	fi; \
fi; \
bash -c ' \
MK="make $1"; \
LOGFILE=$$(mktemp); \
$$MK >$$LOGFILE 2>&1 & MK_PID=$$!; \
echo -n "Compiling $2"; \
while kill -0 $$MK_PID 2>/dev/null; do \
    for i in {1..3}; do \
        echo -n "."; \
        sleep 0.4; \
    done; \
    echo -ne "\rCompiling $2                \rCompiling $2"; \
done; \
wait $$MK_PID; \
STATUS=$$?; \
if [ $$STATUS -ne 0 ]; then \
    echo -e "\033[0;31m\r$2 failed. See the output below:\033[0m"; \
    cat $$LOGFILE; \
else \
    if [ "$2" = "bonus" ] || [ "$2" = "all" ]; then \
       echo -e "\033[0;32m\r$1 Created Successfully.   \033[0m"; \
    else \
       echo -e "\033[0;32m\r$2 finished.    \033[0m"; \
    fi; \
fi; \
rm -f $$LOGFILE; \
'; 
endef
