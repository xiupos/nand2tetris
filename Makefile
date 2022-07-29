.PHONY: nand
nand:
	cd $(PWD)/src/Nand && make -f ../build.mk clean test
