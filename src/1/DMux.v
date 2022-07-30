module DMux (
  output wire out,
  input wire a,
  input wire b,
  input wire sel
);
  wire not_sel;
  wire temp0, temp1;
  Not not0 (
    .out(not_sel),
    .in(sel)
  );
  And and0 (
    .out(temp0),
    .a(a),
    .b(not_sel)
  );
  And and1 (
    .out(temp1),
    .a(b),
    .b(sel)
  );
  Or or0 (
    .out(out),
    .a(temp0),
    .b(temp1)
  );
endmodule
