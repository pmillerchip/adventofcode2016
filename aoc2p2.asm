set r0, 0  # X pos
set r1, 2  # Y pos

.lineloop
set r4, r0     # R4 = new X
set r5, r1     # R5 = new Y
in r2
eq r3, r2, 10  # Newline?
jf r3, .tryleft
call .getkeypad
out r2
out 10
jmp .lineloop

.tryleft
eq r3, r2, 'L
jf r3, .tryright
add r4, r4, 32767  # dec
jmp .testkey

.tryright
eq r3, r2, 'R
jf r3, .tryup
add r4, r4, 1
jmp .testkey

.tryup
eq r3, r2, 'U
jf r3, .trydown
add r5, r5, 32767  # dec
jmp .testkey

.trydown
eq r3, r2, 'D
jf r3, .lineloop   # Ignore unknown char
add r5, r5, 1

.testkey
push r0
push r1
set r0, r4
set r1, r5
call .getkeypad
pop r1
pop r0
# At this point R2 is the new key
eq r3, r2, 'x
jt r3, .lineloop
# Move to new key
set r0, r4
set r1, r5
jmp .lineloop

.keypad
data 'x
data 'x
data '1
data 'x
data 'x

data 'x
data '2
data '3
data '4
data 'x

data '5
data '6
data '7
data '8
data '9

data 'x
data 'A
data 'B
data 'C
data 'x

data 'x
data 'x
data 'D
data 'x
data 'x

# Returns key in R2
.getkeypad
gt r3, r0, 4  #  Is X off the keypad?
jt r3, .getkeypadret
gt r3, r1, 4  #  Is Y off the keypad?
jt r3, .getkeypadret
mult r3, r1, 5
add r3, r3, r0
add r3, r3, .keypad
rmem r2, r3
ret
.getkeypadret
set r2, 'x'
ret

