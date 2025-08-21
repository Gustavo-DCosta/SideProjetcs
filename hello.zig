const std = @import("std");

pub fn main() !void {
    const stdout = std.io.getStdOut().writer();
    const stdin = std.io.getStdIn().reader();
    const num: u8 = 5;
    const input: []u8 = undefined;
    try stdout.print("Hello World from ZIG\n", .{});
    try stdout.print("{d}", .{num});
    try stdin.read(input);

    try stdout.print("Read the input sucessfully", .{input});
}
