all: config build
config:
	./source

build:
	cd ..; ndk-build 



.PHONY: build config
