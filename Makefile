NAME=dreampuff
ifeq ($(shell uname -s),Darwin)
$(info Building for Mac OSX)
PLATFORM=MacOSX
CC=clang
else ifeq ($(shell uname -o),Android)
$(info Building for Android)
PLATFORM=Android
else ifeq ($(shell uname -o),Cygwin)
$(info Building for Windows)
PLATFORM=Windows
else ifeq ($(shell uname -s),Linux)
$(info Building for Linux)
PLATFORM=Linux
CC=gcc
else
$(info Platform unkown; using defaults)
PLATFORM=Unkown
endif
$(info Using $(CC))
SOURCEDIR=./source
SOURCE=$(wildcard $(SOURCEDIR)/*.c)
OBJECTSDIR=./OBJECTS
ifeq ($(wildcard $(OBJECTSDIR)/*),)
$(shell mkdir $(OBJECTSDIR))
endif
TMPOBJECTS=$(subst source/,OBJECTS/,$(SOURCE))
OBJECTS=$(subst .c,.o,$(TMPOBJECTS))
INCLUDEDIR=./include
BINDIR=./BIN
ifeq ($(wildcard $(BINDIR)/*),)
$(shell mkdir $(BINDIR))
endif
BIN=$(BINDIR)/$(NAME).$(PLATFORM)

BASEFLAGS=-L./LIB -L/usr/lib/x86_64-linux-gnu -L/usr/local/lib
INCLUDES=-I$(INCLUDEDIR) -I/usr/local/include

ifeq ($(BACKEND),)
$(info No backend specified; using SDL2 by default)
BACKEND=SDL2
endif

ifeq ($(PLATFORM),MacOSX)
ifeq ($(BACKEND),SDL2)
$(info Using SDL2)
MOREFLAGS=$(BASEFLAGS) -Wl,-lSDL2,-lSDL2_image,-lSDL2_mixer,-lSDL2_ttf
else ifeq ($(BACKEND),GLFW3)
$(info Using GLFW3)
MOREFLAGS=$(BASEFLAGS),-lglfw3,-lIL,-lILU -framework Cocoa -framework CoreVideo -framework IOKit -framework OpenGL
else ifeq ($(BACKEND),TIGR)
$(info Using TIGR)
MOREFLAGS=$(BASEFLAGS),-lgamepad -framework Cocoa -framework CoreVideo -framework IOKit -framework OpenGL
endif
else ifeq ($(PLATFORM),Linux)
ifeq ($(BACKEND),SDL2)
$(info Using SDL2)
MOREFLAGS=$(BASEFLAGS) -lSDL2 -lSDL2_image -lSDL2_ttf -lm
endif
endif

ifeq ($(VERBOSE),1)
FINALFLAGS=$(MOREFLAGS) -v -print-search-dirs -w -H
else
FINALFLAGS=$(MOREFLAGS)
endif

%.o:
	$(CC) $(INCLUDES) -c $(SOURCEDIR)/$(subst .o,.c,$(notdir $@)) -o $@
all: $(OBJECTS)
	$(CC) $^ $(FINALFLAGS) -o $(BIN)
library: $(OBJECTS)
	$(CC) $^ -o lib$(NAME).o
	ar -r lib$(NAME).a lib$(NAME).o
librarycliutil: $(OBJECTSDIR)/cli.o $(OBJECTSDIR)/delog.o
	$(CC) $^ -o libcliutil.o
	ar -r libcliutil.a libcliutil.o
run: all
	$(BIN)
install: all
	sudo cp $(BIN) /usr/local/bin
	sudo ln -f /usr/local/bin/$(NAME).$(PLATFORM) /usr/local/bin/$(NAME)
	sudo ln -f $(BIN) ./$(NAME)
installlibrary: library
	sudo cp lib$(NAME).a /usr/local/lib/lib$(NAME).a
installlibrarycliutil: librarycliutil
	sudo cp libcliutil.a /usr/local/lib/libcliutil.a
clean: 
	rm -rf $(OBJECTSDIR)
	mkdir $(OBJECTSDIR)
fresh: clean all
	
freshrun: clean run
	
freshinstall: clean all install
	
push:
	git add --all .
	git commit -m 'Lazy build message.'
	git push https://github.com/Anadian/$(NAME) master
pull:
	git pull https://github.com/Anadian/$(NAME)
