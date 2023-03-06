##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compile lib and source or execute unit test
##

# LIBRAIRIE
# ----------------------->
SILENT = @

LIB_NAME =	libutils.a
LIB =	utils
LIB_FOLDER=	../

INCLUDE =	../include/
HEADER =	utils.h

LIB_SRC =	capitalize_string.c \
			compare_string_alpha.c \
			compare_string.c \
			concat_fstring.c \
			dup_functions.c \
			free_table.c \
			get_integer_number.c \
			get_number.c \
			is_a_number.c \
			is_alpha_num.c \
			is_in_string.c \
			lenght_calc_functions.c \
			lowcase_string.c \
			my_realloc.c \
			print_error.c \
			print_string.c \
			read_file.c \
			reverse_string.c \
			search_n_occurence.c \
			sort_word.c \
			str_clear.c \
			str_to_tab.c \
			tab_to_str.c \
			table_append.c \
			table_suppress.c \
			upcase_string.c \
			write_file.c \
			get_next_line.c \
			is_boolean.c

OBJ_FOLDER =	../objects/

LIB_OBJ_FOLDER =	$(OBJ_FOLDER)utils/
LIB_OBJ =	$(patsubst %.c, $(LIB_OBJ_FOLDER)%.o, $(LIB_SRC))
# ----------------------->

# COMPILE
# ----------------------->
all:	directorie	$(LIB)

directorie:
	$(SILENT)mkdir -p $(INCLUDE)
	$(SILENT)mkdir -p $(OBJ_FOLDER)
	$(SILENT)mkdir -p $(LIB_OBJ_FOLDER)

$(LIB):
	$(SILENT)cp $(HEADER) $(INCLUDE)
	$(SILENT)gcc -c $(LIB_SRC) -I $(INCLUDE)
	$(SILENT)mv *.o $(LIB_OBJ_FOLDER)
	$(SILENT)ar rc $(LIB_NAME) $(LIB_OBJ)
	$(SILENT)mv $(LIB_NAME) $(LIB_FOLDER)
# ----------------------->

# CLEAN
# ----------------------->
clean:
	$(SILENT)rm -f *.o
	$(SILENT)rm -rf $(LIB_OBJ_FOLDER)

fclean:	clean
	$(SILENT)rm -f $(LIB_FOLDER)$(LIB_NAME)
	$(SILENT)rm -f $(INCLUDE)$(HEADER)
# ----------------------->

re: clean fclean all

.PHONY: clean re