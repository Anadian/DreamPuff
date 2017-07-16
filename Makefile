NAME?=dreampuff
$(info NAME:$(NAME))

ifeq ($(origin GIT_CURRENT),undefined)
GIT_CURRENT=$(shell git-current || ./git-current)
endif #($(origin GIT_CURRENT),undefined)
$(info GIT_CURRENT:$(GIT_CURRENT))

ifeq ($(origin GIT_COMMIT),undefined)
GIT_COMMIT=$(subst commit ,commit-,$(GIT_CURRENT))
endif #($(origin GIT_COMMIT),undefined)
$(info GIT_COMMIT:$(GIT_COMMIT))

#Options
ifeq ($(origin VERBOSE),undefined)
VERBOSE=0
endif #($(origin VERBOSE),undefined)
$(info VERBOSE:$(VERBOSE))

ifeq ($(origin PROCESSOR),undefined)
PROCESSOR=$(shell uname -p)
endif #($(origin PROCESSOR),undefined)
$(info PROCESSOR:$(PROCESSOR))

ifeq ($(origin ARCHITECTURE),undefined)
ARCHITECTURE=$(shell uname -m)
endif #($(origin ARCHITECTURE),undefined)
$(info ARCHITECTURE:$(ARCHITECTURE))

ifeq ($(origin KERNEL),undefined)
KERNEL=$(shell uname -s)
endif #($(origin KERNEL),undefined)
$(info KERNEL:$(KERNEL))

ifeq ($(origin KERNEL_RELEASE),undefined)
KERNEL_RELEASE=$(shell uname -r)
endif #($(origin KERNEL_RELEASE),undefined)
$(info KERNEL_RELEASE:$(KERNEL_RELEASE))

ifeq ($(origin OS),undefined)
ifeq ($(KERNEL),Darwin)
OS=Apple
else
OS=$(shell uname -o)
endif #($(KERNEL),Darwin)
endif #($(origin OS),undefined)
$(info OS:$(OS))

ifeq ($(origin COMPILER),undefined)
ifeq ($(KERNEL),Darwin)
COMPILER=clang
else
COMPILER=gcc
endif #($(KERNEL),Darwin)
endif #($(origin COMPILER),undefined)
$(info COMPILER:$(COMPILER))

SOURCE_DIR?=./source
$(info SOURCE_DIR:$(SOURCE_DIR))
SOURCE?=$(wildcard $(SOURCE_DIR)/*.c)
$(info SOURCE:$(SOURCE))
OBJECTS_DIR?=./OBJECTS
$(info OBJECTS_DIR:$(OBJECTS_DIR))
ifeq ($(wildcard $(OBJECTS_DIR)/*),)
$(shell mkdir $(OBJECTS_DIR))
endif
TMPOBJECTS=$(subst source/,OBJECTS/,$(SOURCE))
OBJECTS?=$(subst .c,.o,$(TMPOBJECTS))
$(info OBJECTS:$(OBJECTS))
INCLUDE_DIR?=./include
$(info INCLUDE_DIR:$(INCLUDE_DIR))
BIN_DIR?=./BIN
$(info BIN_DIR:$(BIN_DIR))
ifeq ($(wildcard $(BIN_DIR)/*),)
$(shell mkdir $(BIN_DIR))
endif
BIN?=$(BIN_DIR)/$(NAME).$(OS)
$(info BIN:$(BIN))

FLAG_STATIC_LIBRARY_SEARCH_DIRECTORIES?=-L/usr/local/lib -L./LIB -L/usr/lib/x86_64-linux-gnu
$(info FLAG_STATIC_LIBRARY_SEARCH_DIRECTORIES:$(FLAG_STATIC_LIBRARY_SEARCH_DIRECTORIES))
FLAG_INCLUDE_SEARCH_DIRECTORIES?=-I/usr/local/include -I$(INCLUDE_DIR)
$(info FLAG_INCLUDE_SEARCH_DIRECTORIES:$(FLAG_INCLUDE_SEARCH_DIRECTORIES))

ifeq ($(origin MIDDLEWARE),undefined)
MIDDLEWARE=SDL2
endif #($(origin MIDDLEWARE),undefined)
$(info MIDDLEWARE:$(MIDDLEWARE))

#Build Conditions
ifeq ($(origin BUILD_CONDITION),undefined)
ifeq ($(origin BUILD_CONDITION_DARWIN_SDL2),undefined)
BUILD_CONDITION_DARWIN_SDL2::=0
ifeq ($(KERNEL),Darwin)
ifeq ($(MIDDLEWARE),SDL2)
BUILD_CONDITION_DARWIN_SDL2::=1
BUILD_CONDITION=Darwin_SDL2
LINK_FLAGS?= -Wl,-lSDL2,-lSDL2_image,-lSDL2_mixer,-lSDL2_ttf
endif #($(MIDDLEWARE),SDL2)
endif #($(KERNEL),Darwin)
endif #($(origin,BUILD_CONDITION_DARWIN_SDL2),undefined)
ifeq ($(origin BUILD_CONDITION_LINUX_SDL2),undefined)
BUILD_CONDITION_LINUX_SDL2::=0
ifeq ($(KERNEL),Linux)
ifeq ($(MIDDLEWARE),SDL2)
BUILD_CONDITION_LINUX_SDL2::=1
BUILD_CONDITION=Linux_SDL2
LINK_FLAGS?= -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm
endif #($(MIDDLEWARE),SDL2)
endif #($(KERNEL),Linux)
endif #($(origin BUILD_CONDITION_LINUX_SDL2),undefined)
endif #($(origin BUILD_CONDITION),undefined)
$(info BUILD_CONDITION:$(BUILD_CONDITION))
$(info LINK_FLAGS:$(LINK_FLAGS))

ifeq ($(VERBOSE),1)
VERBOSE_FLAGS?= -v -print-search-dirs -w -H
endif #($(VERBOSE),1)
$(info VERBOSE_FLAGS:$(VERBOSE_FLAGS))

ifeq ($(origin FLAGS),undefined)
FLAGS=$(FLAG_INCLUDE_SEARCH_DIRECTORIES) $(FLAG_STATIC_LIBRARY_SEARCH_DIRECTORIES) $(LINK_FLAGS) $(VERBOSE_FLAGS)
endif #($(origin FLAGS),undefined)
$(info FLAGS:$(FLAGS))

.PHONY: build-binary install-binary build-library install-library run execute test commit push clean update freshen fresh-install upgrade build-all install-all uninstall-all build all install uninstall debug config help
%.o:
	$(COMPILER) $(INCLUDES) -c $(SOURCE_DIR)/$(subst .o,.c,$(notdir $@)) -o $@
build-binary: $(OBJECTS)
	$(COMPILER) $^ $(FLAGS) -o $(BIN)
install-binary: build-binary
	sudo cp $(BIN) /usr/local/bin
	sudo ln -f /usr/local/bin/$(notdir $(BIN)) /usr/local/bin/$(NAME)
	sudo ln -f $(BIN) ./$(NAME)
uninstall-binary:
	sudo rm -f /usr/local/bin/$(notdir $(BIN)) /usr/local/bin/$(NAME)
build-library: $(OBJECTS)
	$(COMPILER) $^ -o lib$(NAME).o
	ar -r lib$(NAME).a lib$(NAME).o
install-library: build-library
	sudo cp lib$(NAME).a /usr/local/lib/lib$(NAME).a
uninstall-library:
	sudo rm -f /usr/local/lib/lib$(NAME).a
run: build-binary
	$(BIN)
execute: run
test: build-binary
	$(BIN) -t
add:
	git add --all .
commit: add
	git commit -m 'Lazy build message.'
push: commit
	git push origin master
pull:
	git pull origin
clean: 
	rm -rf $(OBJECTSDIR)
	mkdir $(OBJECTSDIR)
update: clean pull
freshen: update build-binary
fresh-install: freshen install
upgrade: update build-binary test
build-all: build-binary build-library
install-all: install-binary install-library
uninstall-all: uninstall-binary uninstall-library
build: build-all
all: build-all
install: install-all
uninstall: uninstall-all
debug: clean build-binary run
config:
help:
	$(info Available commands, with synonyms:)
	$(info help: Display this help message.)
	$(info build-all,build,all: Build both the library and the binary.)
	$(info build-binary: Build the binary only.)
	$(info build-library: Build the library only.)
	$(info install-all,install: Install both the library and the binary.)
	$(info install-binary: Install the binary only.)
	$(info install-library: Install the library only.)
	$(info uninstall-all,uninstall: Uninstall both the library and the binary.)
	$(info uninstall-binary: Uninstall the binary only.)
	$(info uninstall-library: Uninstall the library only.)
	$(info run,execute: Run the binary.)
	$(info test: Run the binary in test mode.)
	$(info add: Add changes and new files to the git repository.)
	$(info commit: Commit to the git repository with a default message.)
	$(info push: Push commits to remote origin.)
	$(info pull: Pull changes from remote origin.)
	$(info clean: Remove objects and temporary file or directories.)
	$(info update: Get the latest changes to the code.)
	$(info freshen: Get the latest changes to the code and rebuild binary.)
	$(info upgrade: Get, build, and test the latest code.)
	$(info fresh-install: Uninstall current libary and binary and install the newest version.)
	$(info debug: Clean, build, and run for rapid debugging.)
	$(info config: Display all the recognised build-configuration variables and their default values for this platform.)
