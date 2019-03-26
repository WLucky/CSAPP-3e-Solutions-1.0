	.file	"Ex61.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	cread_alt
	.type	cread_alt, @function
cread_alt:
.LFB0:
	.cfi_startproc
	testq	%rdi, %rdi
	movl	$tmp.1833, %eax
	cmove	%rax, %rdi
	movq	(%rdi), %rax
	ret
	.cfi_endproc
.LFE0:
	.size	cread_alt, .-cread_alt
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.local	tmp.1833
	.comm	tmp.1833,8,8
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
