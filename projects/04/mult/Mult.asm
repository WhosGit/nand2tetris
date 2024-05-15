// Mult.asm
// multiple the value saved in R0 and R1, save the result in R2

@R2
M=0
@R0
D=M
(LOOP)
@END
D;JEQ
@R1
D=M
@R2
M=D+M
@R0
M=M-1
D=M
@LOOP
0;JMP
(END)

@END
0;JMP   // end the program
