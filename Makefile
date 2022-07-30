srcdir = src
chapter = $(dir $(srcdir))

.PHONY: 1
all: 1

1:
	cd $(PWD)/src/$@ && make -f build.mk run

clean:
	cd $(PWD)/src/1 && make -f build.mk clean
