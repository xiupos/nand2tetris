circuit = Not

VERILATOR = verilator
blddir = build

NAND = ../Nand/Nand.v

.PHONY: all
all: $(blddir)/V$(circuit)

.PHONY: test
test: $(blddir)/V$(circuit)
	bash test.sh

$(blddir)/V$(circuit): $(circuit).cpp $(circuit).v $(NAND)
	verilator -Wall --Mdir $(blddir) --cc --exe --build $?

.PHONY: clean
clean:
	$(RM) -r $(blddir)
