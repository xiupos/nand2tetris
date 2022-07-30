circuit = top1

VERILATOR = verilator
blddir = build

$(blddir)/V$(circuit): $(circuit).cpp $(circuit).v
	verilator -Wall --Mdir $(blddir) --cc --exe --build $?

.PHONY: test
run: $(blddir)/V$(circuit)
	$(blddir)/V$(circuit)

.PHONY: clean
clean:
	$(RM) -r $(blddir) obj_dir
