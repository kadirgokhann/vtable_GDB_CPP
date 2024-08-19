
import gdb

class InfoSymbolRange(gdb.Command):
    "Display symbol information for a range of addresses."

    def __init__(self):
        super(InfoSymbolRange, self).__init__("info-symbol-range", gdb.COMMAND_DATA)

    def invoke(self, arg, from_tty):
        args = gdb.string_to_argv(arg)
        if len(args) != 2:
            raise gdb.GdbError("info-symbol-range requires two arguments (start and end address).")
        start = int(args[0], 0)
        end = int(args[1], 0)

        address = start
        while address <= end:
            symbol = gdb.execute(f"info symbol {address}", to_string=True)
            print(f"Address {address:#x}: {symbol.strip()}")
            address += 1

InfoSymbolRange()
