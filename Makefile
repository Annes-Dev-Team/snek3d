.PHONY: build

setup:
	bear -- make
	
build:
	c++ src/*.cpp test.cpp -g -Iinclude -o bin/test -lraylib -lenet -framework Cocoa -framework OpenGL -framework IOKit -framework CoreAudio -framework CoreGraphics

web:
	em++ -o bin/web/index.html /usr/local/lib/librlweb.a src/*.cpp test.cpp -Os -Iinclude -s USE_GLFW=3 -s ASYNCIFY --shell-file shell.html -DWEB --preload-file assets

webrun: web
	emrun bin/web/index.html
	
run: build
	./bin/test

debug: build
	lldb bin/test
