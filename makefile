
EXE=final

# Main target
all: $(EXE)

#  MinGW
ifeq "$(OS)" "Windows_NT"
CFLG=-O3 -Wall
LIBS=-lglut32cu -lglu32 -lopengl32
CLEAN=del *.exe *.o *.a
else
#  OSX
ifeq "$(shell uname)" "Darwin"
CFLG=-O3 -Wall -Wno-deprecated-declarations
LIBS=-framework GLUT -framework OpenGL
#  Linux/Unix/Solaris
else
CFLG=-O3 -Wall
LIBS=-lglut -lGLU -lGL -lm
endif
#  OSX/Linux/Unix/Solaris
CLEAN=rm -f $(EXE) *.o *.a
endif

# Dependencies
final.o: final.c fd.h
stage.o: stage.c fd.h
skybox.o: skybox.c fd.h
fatal.o: fatal.c fd.h
loadtexbmp.o: loadtexbmp.c fd.h
errcheck.o: errcheck.c fd.h
falco.o: falco.c fd.h


#  Create archive
final.a:fatal.o loadtexbmp.o errcheck.o stage.o skybox.o falco.o
	ar -rcs $@ $^

# Compile rules
.c.o:
	gcc -c $(CFLG) $<
.cpp.o:
	g++ -c $(CFLG) $<

#  Link
final:final.o final.a
	gcc -O3 -o $@ $^   $(LIBS)

#  Clean
clean:
	$(CLEAN)
