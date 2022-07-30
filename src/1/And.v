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
  Not not0 (
    .out(out),
    .in(not_out)
  );
endmodule
