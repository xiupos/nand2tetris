.PHONY: nand
nand:
	cd $(PWD)/src/Nand && make -f build.mk clean test

not:
	cd $(PWD)/src/Not && make -f build.mk clean test
