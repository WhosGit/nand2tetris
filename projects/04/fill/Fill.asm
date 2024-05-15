// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen
// by writing 'black' in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen by writing
// 'white' in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// SCREEN KBD

(LOOP3)
@8192
D=A
(LOOP4)
D=D-1
@SCREEN
A=A+D
M=0
@LOOP4
D;JNE

(LOOP1)
@KBD
D=M
@LOOP1
D;JEQ

@8192
D=A
(LOOP2)
D=D-1
@SCREEN
A=A+D
M=-1
@LOOP2
D;JNE

(LOOP5)
@KBD
D=M
@LOOP3
D;JEQ
@LOOP5
0;JMP