##
## Makefile in /home/guerot_a/depots/PSU_2013_myscript
## 
## Made by anthony guerot
## Login   <guerot_a@epitech.net>
## 
## Started on  Sun Mar  2 18:06:05 2014 anthony guerot
## Last update Sun Apr  6 20:25:03 2014 
##

## FILES

NAME		=	strace

SRC		=	main			\
			display_args		\
			display_call		\
			display_return		\
			display_syscallname	\
			is_syscall		\
			parser			\
			trace			\
			syscallent

SRC_EXT		=	.c

## DIRECTORIES

DOBJ		=	obj
DSRC		=	src
DBIN		=	.

## COMPILATION

DINC		=	include

CFLAGS		=	-Wall		\
			-Wextra

## LINKAGE

LIB		=

DLIB		=

LDFLAGS		=

## RUNS

CC		=	gcc
RM		=	rm -rf
MD		=	mkdir -p

####################
## INTERNAL RULES ##
####################

## CONSTANTS

DBGBOOL		=	yes

DBG		=	-g3		\
			-ggdb

WERROR		=	-Werror

## FILES

OBJ		=	$(addsuffix .o, $(SRC))
_SRC		=	$(addsuffix $(SRC_EXT), $(SRC))

## DIRECTORIES

DINC		:=	$(addsuffix /, $(DINC))
DOBJ		:=	$(addsuffix /, $(DOBJ))
DSRC		:=	$(addsuffix /, $(DSRC))
DBIN		:=	$(addsuffix /, $(DBIN))

## COMPILATION ARGS

CINC		=	$(addprefix -I, $(DINC))

COBJ		=	$(addprefix $(DOBJ), $(OBJ))
CSRC		=	$(addprefix $(DSRC), $(_SRC))
CNAME		=	$(addprefix $(DBIN), $(NAME))

## LINKAGE ARGS

LIB		:=	$(addprefix -l, $(LIB))
DLIB		:=	$(addsuffix /, $(DLIB))
DLIB		:=	$(addprefix -L, $(DLIB))

## FLAGS

ifeq ($(DBGBOOL), yes)
	CFLAGS  += $(DBG)
endif

ifeq ($(DBGBOOL), no)
	CFLAGS	+= $(WERROR)
endif

CFLAGS		+=	$(CINC)
LDFLAGS		+=	$(DLIB)		\
			$(LIB)

## MISC RULES

MAKEOBJ		= $(addprefix $(DOBJ), %.o) : $(addprefix $(addprefix $(DSRC), %), $(SRC_EXT))

all:	$(CNAME)

dbg:	$(CNAME)

$(CNAME):	$(COBJ)
		@$(MD) $(DBIN)
		@echo "Linkage : $(CNAME)"
		@$(CC) $(COBJ) -o $(CNAME) $(LDFLAGS)

$(COBJ):	$(MAKEOBJ)
		@$(MD) $(DOBJ)
		@for dir in `cd $(DSRC); ls -d */ 2> /dev/null`; \
		do \
		if [ ! -d "$(DOBJ)$$dir" ];then \
			$(MD) $(DOBJ)$$dir; \
		fi \
		done
		@echo "Compilation : $<"
		@$(CC) -c $< -o $@ $(CFLAGS)

clean:
		@echo "Deleting obj files"
		@$(RM) $(COBJ)

fclean:		clean
		@echo "Deleting executable"
		@$(RM) $(CNAME)

re:		fclean all
redbg:		fclean dbg

.PHONY:		fclean clean all dbg re
