module Not (
  output wire out,
  input wire in
);
  Nand nand0 (
    .out(out),
    .a(in),
    .b(in)
  );
endmodule
