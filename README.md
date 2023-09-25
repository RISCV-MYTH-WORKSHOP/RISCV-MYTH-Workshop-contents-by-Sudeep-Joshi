# RISC-V_MYTH_Workshopspike pk sum1ton.o
"Microprocessor for You in Thirty Hours" Workshop, offered by for [VLSI System Design (VSD)](https://www.vlsisystemdesign.com/) and [Redwood EDA](https://www.redwoodeda.com/).
Submitted by [Sudeep Joshi](https://www.lindedin.com/in/sudeep-joshi-569951207/).

### Overview of the Days
- 1. Day 1 - Introduction to [RISC-V ISA](https://riscv.org/technical/specifications/) and [RISCV-GNU-TOOLCHAIN](https://github.com/riscv-collab/riscv-gnu-toolchain) and [SPIKE simulator](https://github.com/riscv-software-src/riscv-isa-sim).
- 2. Day 2 - Application Binary Interface(ABI) and Verification flow
- 3. Day 3 - Digital Logic with [TL-Verilog](https://github.com/TL-X-org/tlv_flow_lib) and [Makerchip](https://www.makerchip.com/)
- 4. Day 4 - Basic RISC-V CPU Microarchitecture
- 5. Day 5 - Pipelined RISC-V CPU Microarchitecture

## Day 1 - Introduction to RISC-V, RISC-V GNU Compiler Toolchain and SPIKE Simulator
**RISC-V** is an open-source **Instructioin Set Architecture(ISA)** which has gained significant attention in recent years. It offers flexibility for designing custom processors, making a popular choice for academia and industry. **RV32I** stands for RISC-V 32-bit Integer, which is the base-ISA.
**RISC-V GNU Compiler Toolchain** is the RISC-V C and C++ cross-compiler which allows us to compile C and C++ program in RISC-V ISA and run on simulators.

### [Sum 1 to N program](Day1/sum1ton.c) 
-Following command on the Linux terminal is used to compile the C program.
'''
riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
'''
RISC-V GNU Compiler Toolchain allows two modes of compilation namely, ''' -O1 ''' and ''' -Ofast '''. ''' -Ofast ''' mode asks the compiler to do extensive optimization during the conversion of C to assembly.

To view the compiler assembly code following command is used.
'''
riscv64-unknown-elf-objdump -d sum1ton.o | less
'''
-Generated RISC-V Assembly code:
![sum1ton assembly](Day1/sum1ton_assembly.png)
By looking at the address range of the **<main>** section total number of assembly instructions generated is calculated which came up to 11 for both -O1 and -Ofast modes.

-Same code can be compiled using GNU compiler, which converts it to X86 assembly instructions.
'''
gcc -S -o sum1ton.s sum1ton.c
'''
![sum1ton x86](images/sum1ton_x86.png)


### [While loop program](Day1/whileloop.c)
- RISC-V Assembly
![whileloop riscv](images/whileloop_assembly.png)
- X86 
![whileloop x86](images/whileloop_x86.png)

### SPIKE Simulator
Spike, the RISC-V ISA Simulator, implements a functional model of one or more RISC-V harts.
Following command can be used to invoke SPIKE simulator
'''
spike pk sum1ton.o
'''
for debug mode
'''
spike -d pk sum1ton.o
'''
- SPIKE Step output
![spike output](images/spike.png)
Using spike debug mode program is run until the address 0x100b0 and individual registers are observed.
U


