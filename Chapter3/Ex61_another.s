	.file	"Ex61_another.c"
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
	je	.L6
	movq	i.1834(%rip), %rax
	ret
	.p2align 4,,10
	.p2align 3
.L6:
	movq	0, %rax
	ud2
	.cfi_endproc
.LFE0:
	.size	cread_alt, .-cread_alt
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.local	i.1834
	.comm	i.1834,8,8
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
