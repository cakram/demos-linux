include ../../../Makefile.mk

SO_LINK_NAME:=add
SO_NAME:=lib$(SO_LINK_NAME).so
EXE_NAME:=main.$(SUFFIX_BIN)
SO_OBJECTS:=add.o
EXE_OBJECTS:=main.o
# on Intel this usually works without the -fpic but use it none the less
CFLAGS:=-O2 -g3 -fpic -Wall -Werror -I../../include
LDFLAGS:=-Wall -Werror
CC:=gcc
ALL_DEPS:=Makefile

# you can also add -nostdlib to avoid the default behaviour of linking
# with standard C/C++ runtime libraries.
FLAGS_FOR_SHARED_LIB:=-shared
# These are the libraries used by your library
LIBS:=

.PHONY: all
all: $(EXE_NAME)

$(EXE_NAME): $(EXE_OBJECTS) $(SO_NAME) $(ALL_DEPS)
	$(info doing [$@])
	$(Q)$(CC) -o $(EXE_NAME) $(EXE_OBJECTS) -L. -l$(SO_LINK_NAME) -Xlinker -rpath=$(CURDIR)
$(SO_NAME): $(SO_OBJECTS) $(ALL_DEPS)
	$(info doing [$@])
	$(Q)$(CC) $(LDFLAGS) $(FLAGS_FOR_SHARED_LIB) -o $(SO_NAME) $(SO_OBJECTS) $(LIBS)

%.o: %.c
	$(info doing [$@])
	$(Q)$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean: $(ALL_DEPS)
	$(info doing [$@])
	$(Q)-rm -f *.o $(EXE_NAME) $(SO_NAME)

.PHONY: run
run: $(ALL_DEPS)
	$(info doing [$@])
	$(Q)LD_LIBRARY_PATH=. ./$(EXE_NAME)

.PHONY: trace
trace: $(ALL_DEPS)
	$(info doing [$@])
	$(Q)LD_LIBRARY_PATH=. ltrace ./$(EXE_NAME)

.PHONY: trace_only_func
trace_only_func: $(ALL_DEPS)
	$(info doing [$@])
	$(Q)LD_LIBRARY_PATH=. ltrace -e func ./$(EXE_NAME)
