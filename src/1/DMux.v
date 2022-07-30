module DMux (
  output wire a,
  output wire b,
  input wire in,
  input wire sel
);
  wire not_sel;
  Not not0 (
    .out(not_sel),
    .in(sel)
  );
  And and0 (
    .out(a),
    .a(in),
    .b(not_sel)
  );
  And and1 (
    .out(b),
    .a(in),
    .b(sel)
  );
endmodule
