    .data
A:  .word 9, 3, 5, 6, 8, 2, 1, 0, 4, 7
    .text
    .globl main
    
main:
    la x10, A
    li x11, 10
    jal x1, sort
    li a7, 10
    ecall
swap:
    slli x6, x11, 2
    add x6, x10, x6
    lw x5, 0(x6)
    lw x7, 4(x6)
    sw x7, 0(x6)
    sw x5, 4(x6)
    jalr x0, 0(x1)
sort:
    addi sp, sp, -4
    sw x1, 0(sp)
    addi x21, x10, 0
    addi x22, x11, 0
    addi x19, x0, 0
for1tst:
    bge x19, x22, exit1
    addi x20, x19, -1
for2tst:
    blt x20, x0, exit2
    slli x5, x20, 2
    add x5, x21, x5
    lw x6, 0(x5)
    lw x7, 4(x5)
    ble x6, x7, exit2
    addi x10, x21, 0
    addi x11, x20, 0
    jal x1, swap
    addi x20, x20, -1
    jal x0, for2tst
exit2:
    addi x19, x19, 1
    jal x0, for1tst
exit1:
    lw x1, 0(sp)
    addi sp, sp, 4
    jalr x0, 0(x1)
