set r3, 0
.loop
call .readint
set r1, r0
call .readint
set r2, r0
call .readint
call .istriangle
jf r0, .nottriangle
add r3, r3, 1
.nottriangle
call .printint
out 32
set r0, r1
call .printint
out 32
set r0, r2
call .printint
out 32
set r0, r3
call .printint
out 10
jmp .loop

# Reads an integer into R0
.readint
set r0, 0
push r1
push r2
.readintvoidwhite
in r1
eq r2, r1, 10  # Void newlines
jt r2, .readintvoidwhite
eq r2, r1, 32  # Void space
jt r2, .readintvoidwhite
.readintreadnum
gt r2, r1, 47  # 1 less than '0'
jf r2, .readintend
gt r2, r1, '9
jt r2, .readintend
# It's a valid digit
mult r0, r0, 10
add r1, r1, 32720  # -48 which is sub r1, r1, '0
add r0, r0, r1
in r1
jmp .readintreadnum
.readintend
pop r2
pop r1
ret

# Input = R0, R1, R2
# Output = bool in R0
.istriangle
push r3
push r4
set r3, 0
add r4, r0, r1
gt r5, r4, r2
jt r5, .istriangleb
jmp .istriangleend
.istriangleb
add r4, r1, r2
gt r5, r4, r0
jt r5, .istrianglec
jmp .istriangleend
.istrianglec
add r4, r0, r2
gt r5, r4, r1
jt r5, .istriangleyes
jmp .istriangleend
.istriangleyes
set r3, 1
.istriangleend
set r0, r3
pop r4
pop r3
ret

# Prints the integer in R0 in hex
.printint
push r0
push r1
push r2
push r3
push r4
set r1, 1  # Mask
.printintmaskloop
and r2, r0, r1
gt r2, r2, 0
push r2   # Push individual binary digits onto the stack
mult r1, r1, 2  # Mask
jt r1, .printintmaskloop
push 0  # Top bit for 16-bit printing is always 0
set r2, 0
.printintdigitloop
set r0, 0
.printintbitloop
pop r1
mult r1, r1, 8
or r0, r0, r1
pop r1
mult r1, r1, 4
or r0, r0, r1
pop r1
mult r1, r1, 2
or r0, r0, r1
pop r1
or r0, r0, r1
call .printhexdigit
add r2, r2, 1
gt r4, r2, 3
jf r4, .printintdigitloop
pop r4
pop r3
pop r2
pop r1
pop r0
ret

.printhexdigit
push r1
and r0, r0, 0xf
gt r1, r0, 9
jt r1, .printhexletter
add r0, r0, '0
jmp .printhexdigitend
.printhexletter
add r0, r0, 87  # 'a' minus 10
.printhexdigitend
out r0
pop r1
ret

