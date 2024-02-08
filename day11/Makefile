#========================================#
#=========  GENERAL VARIABLES:  =========#
#========================================#

NAME			:=	AoC-23

OBJ_DIR			:=	OBJ
SRC_DIR			:=	src
INC_DIR			:=	inc
LIB_DIR			:=	lib

SRC				:=	code.cpp

OBJ_1			:=	$(SRC:%.cpp=$(OBJ_DIR)/%.o)
OBJ_2			:=	$(SRC:%.cpp=$(OBJ_DIR)/%2.o)
SRC				:=	$(SRC:%=$(SRC_DIR)/%)
DEP				:=	$(OBJ_1:.o=.d)	\
					$(OBJ_2:.o=.d)
DIR_LIST		:=	$(sort $(dir $(OBJ_1)))

-include $(DEP)

#============= COMPILATION ==============#

INCLUDE			:=	-I $(INC_DIR)

CC				:=	c++
CFL				:=	-Wall -Wextra -Wpedantic

ifndef DEBUG
CFL				+=	-g -D DEBUG=1
endif

ifndef NOMSG
CFL				+=	-D MSG=1
endif

ifdef FSAN
CFL				+=	 -fsanitize=address,undefined
endif

COMPILE			:=	$(CC) $(CFL)

INFO_FL			:=											\
$(if $(findstring -std=c++98,$(CFL)),c++98)					\
$(if $(findstring -g,$(CFL)),-g)							\
$(if $(findstring address,$(CFL)),addr)						\
$(if $(findstring undefined,$(CFL)),undef)					\


#========================================#
#============== RECIPIES  ===============#
#========================================#

1:$(DIR_LIST) exe1

2:$(DIR_LIST) exe2

$(DIR_LIST):
	@mkdir -p $@

exe1: $(OBJ_1)
	@echo ""
	@$(COMPILE) $(INCLUDE) $(OBJ_1) -o $(NAME)
	@echo "$(COMPILE) $(INCLUDE) $(CYAN)$(notdir $(OBJ_1))$(RESET) -o $(NAME)"

exe2: $(OBJ_2)
	@echo ""
	@$(COMPILE) $(INCLUDE) $(OBJ_2) -o $(NAME)_2
	@echo "$(COMPILE) $(INCLUDE) $(CYAN)$(notdir $(OBJ_2))$(RESET) -o $(NAME)_2"

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	@$(COMPILE) $(INCLUDE) -MMD -o $@ -c $< 
	@echo "$(CYAN)COMPILE $(INFO_FL) $(notdir $(<:%.c=%))$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(BOLD)CLEANING $(NAME)$(RESET)"

fclean: clean 
	@rm -f $(NAME) $(NAME)_2

re: fclean 1 2

#========================================#
#============ MISCELLANEOUS =============#
#========================================#

.PHONY: all clean fclean re debug rebug  1 2 exe1 exe2

.DEFAULT_GOAL := 1

#=============== COLOURS ================#

OS		:=	$(shell uname -r)

ifneq ($(OS), 6.3.6-arch1-1)
	BOLD	:= \033[1m
	RED		:= \033[31;1m
	GREEN	:= \033[32;1m
	CYAN	:= \033[36;1m
	RESET	:= \033[0m
endif