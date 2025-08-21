const pio = @import("std");

pub fn main() !void {
    const stdin = pio.io.getStdIn();

    const reader = stdin.reader();
    pio.debug.print("Welcome to the Zig calculator \n", .{});

    var buffer: [10]u8 = undefined;

    const input = try reader.readUntilDelimiterOrEof(&buffer, '\n');

    pio.debug.print("User's input: .{any}", .{input});
}
