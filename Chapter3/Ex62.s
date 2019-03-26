	.file	"Ex62.c"
	.text
	.globl	switch3
	.type	switch3, @function
switch3:
.LFB0:
	.cfi_startproc
	cmpl	$4, %edx
	ja	.L9
	movl	%edx, %edx
	jmp	*.L4(,%rdx,8)
	.section	.rodata
	.align 8
	.align 4
.L4:
	.quad	.L3
	.quad	.L5
	.quad	.L6
	.quad	.L7
	.quad	.L8
	.text
.L8:
	movl	$27, %eax
	ret
.L3:
	movq	(%rsi), %rax
	movq	(%rdi), %rdx
	movq	%rdx, (%rsi)
	ret
.L5:
	movq	(%rsi), %rax
	addq	(%rdi), %rax
	movq	%rax, (%rdi)
	ret
.L6:
	movq	$59, (%rdi)
	movq	(%rsi), %rax
	ret
.L7:
	movq	(%rsi), %rax
	movq	%rax, (%rdi)
	movl	$27, %eax
	ret
.L9:
	movl	$12, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	switch3, .-switch3
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
