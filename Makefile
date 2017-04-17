CFLAGS := -fPIC -O3 -g -Wall -Wno-unused-result 
CC := gcc
MAJOR := 0
MINOR := 1
NAME := link_list
VERSION := $(MAJOR).$(MINOR)
DOXYCONFIG_NAME := link_list.conf 

DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CFLAGS += -DDEBUG_ENABLE
else
    CFLAGS += -DNDEBUG_ENABLE
endif


all: lib test telebook

lib: lib$(NAME).so.$(VERSION)

test: $(NAME)_test

$(NAME)_test: lib$(NAME).so $(NAME)_test.o
	$(CC) $(CFLAGS) $(NAME)_test.c -o $@ -L. -l$(NAME)

telebook: lib$(NAME).so tele_application.o
	$(CC) $(CFLAGS) tele_application.c -o $@ -L. -l$(NAME)

lib$(NAME).so: lib$(NAME).so.$(VERSION)
	ldconfig -v -n .
	ln -s lib$(NAME).so.$(MAJOR) lib$(NAME).so
	doxygen $(DOXYCONFIG_NAME)

lib$(NAME).so.$(VERSION): $(NAME).o
	$(CC)  -shared -Wl,-soname,lib$(NAME).so.$(MAJOR) $^ -o $@ 

clean:
	$(RM) -rf $(NAME)_test *.o *.so* telebook doc/* src/*.o lib/*

.PHONY : all 
