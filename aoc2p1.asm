set r0, 1  # X pos
set r1, 1  # Y pos

.lineloop
in r2
eq r3, r2, 10  # Newline?
jf r3, .tryleft
call .printnum
jmp .lineloop

.tryleft
eq r3, r2, 'L'
jf r3, .tryright
jf r0, .lineloop   # X is 0 already
add r0, r0, 32767  # dec
jmp .lineloop

.tryright
eq r3, r2, 'R'
jf r3, .tryup
eq r3, r0, 2
jt r3, .lineloop   # X is 2 already
add r0, r0, 1
jmp .lineloop

.tryup
eq r3, r2, 'U'
jf r3, .trydown
jf r1, .lineloop   # Y is 0 already
add r1, r1, 32767  # dec
jmp .lineloop

.trydown
eq r3, r2, 'D'
jf r3, .lineloop   # Ignore unknown char
eq r3, r1, 2
jt r3, .lineloop   # Y is 2 already
add r1, r1, 1
jmp .lineloop

.printnum
mult r2, r1, 3
add r2, r2, r0
add r2, r2, '1'
out r2
out 10
ret

