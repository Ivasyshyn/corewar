.name "dpozinen"
.comment "comment"

ld %0, r1
ld %4, r2
ld %0, r3

tettteft:
    live %1
    add r1, r2, r3
    zjmp %:tettteft
