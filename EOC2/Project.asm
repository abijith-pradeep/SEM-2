@KBD 
D=M
@50
D=D-A
@temp1
D;JGE
@temp2
D;JLT
(temp1)
@0
D=A
@SCREEN
M=D
@END
D;JGE
(temp2)
@1
D=A
@SCREEN 
M=D
(END)