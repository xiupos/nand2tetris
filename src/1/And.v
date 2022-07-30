module And (
  output wire out,
  input wire a,
  input wire b
);
  wire not_out;
  Nand nand0 (
    .out(not_out),
    .a(a),
    .b(b)
  );
  Nand nand1 (
    .out(out),
    .a(not_out),
    .b(not_out)
  );
endmodule
