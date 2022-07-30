module And (
  output wire out,
  input wire a,
  input wire b
);
  wire temp;
  Nand nand0 (
    .out(temp),
    .a(a),
    .b(b)
  );
  Nand nand1 (
    .out(out),
    .a(temp),
    .b(temp)
  );
endmodule
