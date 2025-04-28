	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 2
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3, 0x0                          ; -- Begin function ft_atof
lCPI0_0:
	.quad	0x3fb999999999999a              ; double 0.10000000000000001
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_ft_atof
	.p2align	2
_ft_atof:                               ; @ft_atof
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	.cfi_def_cfa_offset 64
	str	x0, [sp, #48]
	mov	w8, #-1                         ; =0xffffffff
	str	w8, [sp, #36]
	movi	d0, #0000000000000000
	str	d0, [sp, #40]
	fmov	d0, #1.00000000
	str	d0, [sp, #24]
	str	d0, [sp, #16]
	str	d0, [sp, #8]
	ldr	x8, [sp, #48]
	ldrsb	w8, [x8]
	subs	w8, w8, #45
	cset	w8, ne
	tbnz	w8, #0, LBB0_3
	b	LBB0_1
LBB0_1:
	ldr	w8, [sp, #36]
	add	w8, w8, #1
	str	w8, [sp, #36]
	subs	w8, w8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB0_3
	b	LBB0_2
LBB0_2:
	fmov	d0, #-1.00000000
	str	d0, [sp, #8]
	b	LBB0_3
LBB0_3:
	b	LBB0_4
LBB0_4:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp, #48]
	ldr	w9, [sp, #36]
	add	w9, w9, #1
	str	w9, [sp, #36]
	add	x8, x8, w9, sxtw
	ldrb	w8, [x8]
	subs	w8, w8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB0_11
	b	LBB0_5
LBB0_5:                                 ;   in Loop: Header=BB0_4 Depth=1
	ldr	x8, [sp, #48]
	ldrsw	x9, [sp, #36]
	ldrsb	w8, [x8, x9]
	subs	w8, w8, #46
	cset	w8, ne
	tbnz	w8, #0, LBB0_10
	b	LBB0_6
LBB0_6:
	b	LBB0_7
LBB0_7:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp, #48]
	ldr	w9, [sp, #36]
	add	w9, w9, #1
	str	w9, [sp, #36]
	add	x8, x8, w9, sxtw
	ldrb	w8, [x8]
	subs	w8, w8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB0_9
	b	LBB0_8
LBB0_8:                                 ;   in Loop: Header=BB0_7 Depth=1
	ldr	d0, [sp, #24]
	adrp	x8, lCPI0_0@PAGE
	ldr	d1, [x8, lCPI0_0@PAGEOFF]
	fmul	d0, d0, d1
	str	d0, [sp, #24]
	ldr	d0, [sp, #16]
	fmov	d1, #10.00000000
	fmul	d0, d0, d1
	str	d0, [sp, #16]
	ldr	d0, [sp, #40]
	ldr	d1, [sp, #16]
	ldr	x8, [sp, #48]
	ldrsw	x9, [sp, #36]
	ldrsb	w8, [x8, x9]
	subs	w8, w8, #48
	scvtf	d2, w8
	fmadd	d0, d0, d1, d2
	ldr	d1, [sp, #24]
	fmul	d0, d0, d1
	str	d0, [sp, #40]
	b	LBB0_7
LBB0_9:
	ldr	d0, [sp, #40]
	ldr	d1, [sp, #8]
	fmul	d0, d0, d1
	str	d0, [sp, #56]
	b	LBB0_12
LBB0_10:                                ;   in Loop: Header=BB0_4 Depth=1
	ldr	d0, [sp, #40]
	ldr	x8, [sp, #48]
	ldrsw	x9, [sp, #36]
	ldrsb	w8, [x8, x9]
	subs	w8, w8, #48
	scvtf	d2, w8
	fmov	d1, #10.00000000
	fmadd	d0, d0, d1, d2
	str	d0, [sp, #40]
	b	LBB0_4
LBB0_11:
	ldr	d0, [sp, #40]
	ldr	d1, [sp, #8]
	fmul	d0, d0, d1
	str	d0, [sp, #56]
	b	LBB0_12
LBB0_12:
	ldr	d0, [sp, #56]
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
	stur	w0, [x29, #-8]
	stur	x1, [x29, #-16]
	stur	wzr, [x29, #-20]
	ldur	w8, [x29, #-8]
	subs	w8, w8, #2
	cset	w8, eq
	tbnz	w8, #0, LBB1_3
	b	LBB1_1
LBB1_1:
	ldur	w8, [x29, #-20]
	subs	w8, w8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB1_3
	b	LBB1_2
LBB1_2:
	mov	w8, #-1                         ; =0xffffffff
	stur	w8, [x29, #-4]
	b	LBB1_7
LBB1_3:
	movi	d0, #0000000000000000
	str	d0, [sp, #32]
	b	LBB1_4
LBB1_4:                                 ; =>This Inner Loop Header: Depth=1
	ldr	d0, [sp, #32]
	fmov	d1, #5.00000000
	fcmp	d0, d1
	cset	w8, pl
	tbnz	w8, #0, LBB1_7
	b	LBB1_5
LBB1_5:                                 ;   in Loop: Header=BB1_4 Depth=1
	ldur	x8, [x29, #-16]
	ldr	x0, [x8, #8]
	bl	_ft_atof
	mov	x8, sp
	str	d0, [x8]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	str	x0, [sp, #24]                   ; 8-byte Folded Spill
	bl	_printf
	ldur	x8, [x29, #-16]
	ldr	x0, [x8, #8]
	bl	_ft_atof
	fcvtzs	w8, d0
	stur	w8, [x29, #-20]
	ldur	w8, [x29, #-20]
	add	w8, w8, #10
	stur	w8, [x29, #-20]
	ldur	x8, [x29, #-16]
	ldr	x0, [x8, #8]
	mov	x1, #0                          ; =0x0
	str	x1, [sp, #16]                   ; 8-byte Folded Spill
	bl	_strtof
	ldr	x1, [sp, #16]                   ; 8-byte Folded Reload
	ldur	x8, [x29, #-16]
	ldr	x0, [x8, #8]
	bl	_strtof
	ldr	x0, [sp, #24]                   ; 8-byte Folded Reload
	fcvt	d0, s0
	mov	x8, sp
	str	d0, [x8]
	bl	_printf
	b	LBB1_6
LBB1_6:                                 ;   in Loop: Header=BB1_4 Depth=1
	ldr	d0, [sp, #32]
	fmov	d1, #1.00000000
	fadd	d0, d0, d1
	str	d0, [sp, #32]
	b	LBB1_4
LBB1_7:
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"%f\n"

.subsections_via_symbols
