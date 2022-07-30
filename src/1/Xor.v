module Xor (
  output wire out,
  input wire a,
  input wire b
);
  wire not_a, not_b;
  wire temp0, temp1;
  Not not0 (
    .out(not_a),
    .in(a)
  );
  Not not1 (
    .out(not_b),
    .in(b)
  );
  And and0 (
    .out(temp0),
    .a(a),
    .b(not_b)
  );
  And and1 (
    .out(temp1),
    .a(not_a),
    .b(b)
  );
  Or or0 (
    .out(out),
    .a(temp0),
    .b(temp1)
  );
endmodule
