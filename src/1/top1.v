module top1 (
  output wire nand_out,
  output wire not_out,
  output wire and_out,
  output wire or_out,
  output wire xor_out,
  output wire mux_out,
  input wire in,
  input wire a,
  input wire b,
  input wire sel
);
  Nand nand0 (
    .out(nand_out),
    .a(a),
    .b(b)
  );
  Not not0 (
    .out(not_out),
    .in(in)
  );
  And and0 (
    .out(and_out),
    .a(a),
    .b(b)
  );
  Or or0 (
    .out(or_out),
    .a(a),
    .b(b)
  );
  Xor xor0 (
    .out(xor_out),
    .a(a),
    .b(b)
  );
  Mux mux0 (
    .out(mux_out),
    .a(a),
    .b(b),
    .sel(sel)
  );
endmodule
