	.file	"Ex60.c"
	.text
	.globl	loop
	.type	loop, @function
loop:
.LFB0:
	.cfi_startproc
	movl	%esi, %ecx
	movl	$1, %edx
	movl	$0, %eax
	jmp	.L2
.L3:
	movq	%rdx, %r8
	andq	%rdi, %r8
	orq	%r8, %rax
	salq	%cl, %rdx
.L2:
	testq	%rdx, %rdx
	jne	.L3
	rep ret
	.cfi_endproc
.LFE0:
	.size	loop, .-loop
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
