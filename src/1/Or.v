module Or (
  output wire out,
  input wire a,
  input wire b
);
  wire not_a, not_b;
  Nand nand0 (
    .out(out),
    .a(not_a),
    .b(not_b)
  );
  Nand nand1 (
    .out(not_a),
    .a(a),
    .b(a)
  );
  Nand nand2 (
    .out(not_b),
    .a(b),
    .b(b)
  );
endmodule
