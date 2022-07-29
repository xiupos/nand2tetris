circuit = Nand

VERILATOR = verilator
blddir = build

.PHONY: all
all: $(blddir)/V$(circuit)

.PHONY: test
test: $(blddir)/V$(circuit)
	bash test.sh

$(blddir)/V$(circuit): $(circuit).cpp $(circuit).v
	verilator -Wall --Mdir $(blddir) --cc --exe --build $?

.PHONY: clean
clean:
	$(RM) -r $(blddir)
