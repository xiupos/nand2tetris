module Or (
  output wire out,
  input wire a,
  input wire b
);
  wire not_a, not_b;
  Not not0 (
    .out(not_a),
    .in(a)
  );
  Not not1 (
    .out(not_b),
    .in(b)
  );
  Nand nand0 (
    .out(out),
    .a(not_a),
    .b(not_b)
  );
endmodule
