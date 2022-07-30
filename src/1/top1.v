module top1 (
  output wire nand_out,
  output wire not_out,
  output wire and_out,
  input wire a,
  input wire b
);
  Nand nand0 (
    .out(nand_out),
    .a(a),
    .b(b)
  );
  Not not0 (
    .out(not_out),
    .in(a)
  );
  And and0 (
    .out(and_out),
    .a(a),
    .b(b)
  );
endmodule
