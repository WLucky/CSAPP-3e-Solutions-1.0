	.file	"Ex72.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	aframe
	.type	aframe, @function
aframe:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	$1, -32(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	30(,%rdi,8), %rax
	andq	$-16, %rax
	subq	%rax, %rsp
	leaq	-32(%rbp), %rax
	leaq	15(%rsp), %rcx
	andq	$-16, %rcx
	cmpq	$1, %rdi
	movq	%rax, (%rcx)
	jle	.L10
	movq	%rdi, %r8
	movl	$1, %eax
	subq	$1, %r8
	cmove	%r8, %rax
	cmpq	$4, %r8
	cmovbe	%r8, %rax
	testq	%rax, %rax
	je	.L12
	cmpq	$1, %rax
	movq	%rdx, 8(%rcx)
	movl	$2, %r11d
	je	.L5
	cmpq	$2, %rax
	movq	%rdx, 16(%rcx)
	movl	$3, %r11d
	je	.L5
	cmpq	$4, %rax
	movq	%rdx, 24(%rcx)
	movl	$4, %r11d
	jne	.L5
	movq	%rdx, 32(%rcx)
	movl	$5, %r11d
.L5:
	cmpq	%rax, %r8
	je	.L6
.L4:
	movq	%r8, %r9
	movq	%rdi, %r8
	subq	%rax, %r9
	subq	%rax, %r8
	leaq	-2(%r9), %r10
	shrq	%r10
	addq	$1, %r10
	cmpq	$2, %r8
	leaq	(%r10,%r10), %rbx
	je	.L7
	movq	%rdx, -40(%rbp)
	leaq	8(%rcx,%rax,8), %r8
	xorl	%eax, %eax
	movq	-40(%rbp), %xmm0
	punpcklqdq	%xmm0, %xmm0
.L8:
	addq	$1, %rax
	addq	$16, %r8
	movaps	%xmm0, -16(%r8)
	cmpq	%rax, %r10
	ja	.L8
	addq	%rbx, %r11
	cmpq	%rbx, %r9
	je	.L6
.L7:
	movq	%rdx, (%rcx,%r11,8)
.L6:
	movq	%rdi, -32(%rbp)
.L10:
	movq	(%rcx,%rsi,8), %rax
	movq	-24(%rbp), %rbx
	xorq	%fs:40, %rbx
	movq	(%rax), %rax
	jne	.L26
	movq	-8(%rbp), %rbx
	leave
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
	.p2align 4,,10
	.p2align 3
.L12:
	.cfi_restore_state
	movl	$1, %r11d
	jmp	.L4
.L26:
	call	__stack_chk_fail
	.cfi_endproc
.LFE0:
	.size	aframe, .-aframe
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
