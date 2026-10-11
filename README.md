# NanoTekSpice

A digital electronics simulator in C++20. It reads a circuit description file
(`.nts`), builds the corresponding graph of components and simulates it tick by
tick in an interactive shell, using three-state logic (`0`, `1`, `U` for
undefined).

## Supported components

- **Special**: `input`, `output`, `clock`, `true`, `false`, `logger`
- **Elementary gates**: `and`, `or`, `xor`, `not`, `nand`, `nor`
- **4000-series chips**: 4001 (NOR), 4011 (NAND), 4030 (XOR), 4069 (NOT),
  4071 (OR), 4081 (AND), 4008 (4-bit adder), 4013 (D flip-flop),
  4017 (Johnson counter), 4040 (12-bit counter), 4094 (shift register),
  4512 (8-channel selector), 4514 (4-to-16 decoder)
- **Memory**: 2716 (ROM), 4801 (RAM)

Every component implements a common `IComponent` interface and is created
through a factory, so adding a chip never touches the simulation core.

## Usage

```sh
make
./nanotekspice examples/and.nts
```

Shell commands: `input=value` to set an input, `simulate` to run one tick,
`display` to print the state, `loop` to simulate continuously, `exit` to quit.

```
> a=1
> b=1
> simulate
> display
tick: 1
input(s):
  a: 1
  b: 1
output(s):
  s: 1
```

An invalid circuit file (unknown component, bad link, missing section) is
rejected with exit code 84.

The `bonus/` folder adds an SFML graphical window on top of the simulator
(built against SFML 2.x).

## Team

Built by [Tom Blancheton](https://github.com/TomOplomo) and
[Newen Calle](https://github.com/Newen95). Newen's part: the component factory,
the pin mapping of every chip, the logger component, the 2716 ROM and the 4512
and 4514 chips.
