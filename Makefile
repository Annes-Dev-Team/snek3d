.PHONY: build

build:
	c++ src/*.cpp test.cpp -g -Iinclude -o bin/test -lraylib -framework Cocoa -framework OpenGL -framework IOKit -framework CoreAudio -framework CoreGraphics

run: build
	./bin/test

debug: build
	lldb bin/test
