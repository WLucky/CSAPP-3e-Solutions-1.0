	.file	"Ex73.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	find_range
	.type	find_range, @function
find_range:
.LFB0:
	.cfi_startproc
#APP
# 7 "Ex73.c" 1
	vxorps %xmm1, %xmm1, %xmm1
	vucomiss %xmm1, %xmm0
	jp .P
	ja .A
	jb .B
	je .E
	.A:
	movl $2, %eax
	jmp .Done
	.B:
	movl $0, %eax
	jmp .Done
	.E:
	movl $1, %eax
	jmp .Done
	.P:
	movl $3,%eax
	.Done:
	ret
	
# 0 "" 2
#NO_APP
	ret
	.cfi_endproc
.LFE0:
	.size	find_range, .-find_range
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.section	.text.unlikely
.LCOLDB2:
	.text
.LHOTB2:
	.p2align 4,,15
	.globl	find_range_C
	.type	find_range_C, @function
find_range_C:
.LFB1:
	.cfi_startproc
	pxor	%xmm1, %xmm1
	ucomiss	%xmm0, %xmm1
	ja	.L5
	ucomiss	%xmm1, %xmm0
	jp	.L8
	movl	$1, %eax
	je	.L3
.L8:
	xorl	%eax, %eax
	ucomiss	%xmm1, %xmm0
	setbe	%al
	addl	$2, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L5:
	xorl	%eax, %eax
.L3:
	rep ret
	.cfi_endproc
.LFE1:
	.size	find_range_C, .-find_range_C
	.section	.text.unlikely
.LCOLDE2:
	.text
.LHOTE2:
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC3:
	.string	"Ex73.c"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC4:
	.string	"find_range(f) == find_range_C(f)"
	.section	.text.unlikely
.LCOLDB5:
	.section	.text.startup,"ax",@progbits
.LHOTB5:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pxor	%xmm1, %xmm1
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L14:
	movl	%eax, 12(%rsp)
	movss	12(%rsp), %xmm0
#APP
# 7 "Ex73.c" 1
	vxorps %xmm1, %xmm1, %xmm1
	vucomiss %xmm1, %xmm0
	jp .P
	ja .A
	jb .B
	je .E
	.A:
	movl $2, %eax
	jmp .Done
	.B:
	movl $0, %eax
	jmp .Done
	.E:
	movl $1, %eax
	jmp .Done
	.P:
	movl $3,%eax
	.Done:
	ret
	
# 0 "" 2
#NO_APP
	xorl	%edx, %edx
	ucomiss	%xmm0, %xmm1
	ja	.L11
	ucomiss	%xmm1, %xmm0
	jp	.L18
	movl	$1, %edx
	je	.L11
.L18:
	xorl	%edx, %edx
	ucomiss	%xmm1, %xmm0
	setbe	%dl
	addl	$2, %edx
.L11:
	testl	%edx, %edx
	jne	.L21
	addl	$1, %eax
	cmpl	$-1, %eax
	jne	.L14
	xorl	%eax, %eax
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L21:
	.cfi_restore_state
	movl	$__PRETTY_FUNCTION__.1863, %ecx
	movl	$56, %edx
	movl	$.LC3, %esi
	movl	$.LC4, %edi
	call	__assert_fail
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE5:
	.section	.text.startup
.LHOTE5:
	.section	.rodata
	.type	__PRETTY_FUNCTION__.1863, @object
	.size	__PRETTY_FUNCTION__.1863, 5
__PRETTY_FUNCTION__.1863:
	.string	"main"
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
