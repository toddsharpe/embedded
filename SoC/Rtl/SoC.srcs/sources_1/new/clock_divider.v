`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/20/2023 08:34:05 PM
// Design Name: 
// Module Name: clock_divider
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module clock_divider
    #(parameter FREQ = 8)(
    input clk,
    input reset,
    output reg clk_div
    );

localparam count_max = 100000000 / (FREQ / 2);

reg [31:0] counter;

always @ (posedge(clk))
begin
    if (reset)
        counter <= 32'b0;
    else if (counter == count_max - 1)
        counter <= 32'b0;
    else
        counter <= counter + 1;
end

always @ (posedge(clk))
begin
    if (reset)
        clk_div <= 1'b0;
    else if (counter == count_max - 1)
        clk_div <= ~clk_div;
    else
        clk_div <= clk_div;
end

endmodule