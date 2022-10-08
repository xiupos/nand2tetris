circuit = top1

V = verilator
CFLAGS = -std=c++20
blddir = build

$(blddir)/V$(circuit): $(circuit).cpp $(circuit).v
	$(V) -Wall --Mdir $(blddir) -CFLAGS "$(CFLAGS)" --cc --exe --build $?

.PHONY: test
run: $(blddir)/V$(circuit)
	$(blddir)/V$(circuit)

.PHONY: clean
clean:
	$(RM) -r $(blddir) obj_dir
