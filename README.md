# simLan Interpreter (C Implementation)

This project is a basic interpreter for a simple assembly-like language called **simLan** (short for *Simple Language*). The interpreter is implemented in the C programming language and is capable of reading and executing instructions from a file named `program.TXT`.

---

## 🧠 Features

- Simulates a 32-register virtual machine.
- Supports basic operations:
  - `put`: Assigns a constant to a register.
  - `add`: Adds the value of one register to another.
  - `jmpe`: Jumps to a line if two registers hold equal values.
  - `jmpu`: Unconditional jump to a line number.
  - `prn`: Prints the value of a register.
  - `halt`: Terminates program execution.

---

## 📁 File Structure

- `simLan.c`: Contains the full source code of the interpreter.
- `program.TXT`: The instruction file that contains simLan commands (must be present in the same directory).

---


🔤 simLan Instruction Set
Instruction	Description
put CONST,rx	Assigns the constant CONST to register rx.
add r1,r2	Adds the value in r1 to r2.
jmpe r1,r2,LINE	Jumps to LINE in the file if values in r1 and r2 are equal.
jmpu LINE	Unconditionally jumps to LINE in the file.
prn rx	Prints the integer value of register rx.
halt	Terminates program execution.

⚠️ Notes
Registers are zero-indexed and range from r0 to r31.

Lines are numbered starting from 1 for jump instructions.

The program.TXT file must be placed in the same directory as the executable.

Only valid integer constants are supported (negative values allowed).

👨‍💻 Author
This interpreter was implemented by Abdulrahman Jbaili as a project to learn and simulate low-level instruction parsing in C.
