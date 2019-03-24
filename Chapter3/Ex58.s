	.file	"Ex58.c"
	.text
	.globl	decode2
	.type	decode2, @function
decode2:
.LFB0:
	.cfi_startproc
	subq	%rdx, %rsi
	movq	%rsi, %rax
	salq	$63, %rax
	sarq	$63, %rax
	imulq	%rsi, %rdi
	xorq	%rdi, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	decode2, .-decode2
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
