	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 1
	.globl	__Z3sumii                       ; -- Begin function _Z3sumii
	.p2align	2
__Z3sumii:                              ; @_Z3sumii
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	w0, [sp, #12]
	str	w1, [sp, #8]
	ldr	w8, [sp, #12]
	ldr	w9, [sp, #8]
	add	w0, w8, w9
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	w8, #0
	str	w8, [sp, #12]                   ; 4-byte Folded Spill
	stur	wzr, [x29, #-4]
	bl	__Z9createNumv
	stur	w0, [x29, #-8]
	bl	__Z9createNumv
	stur	w0, [x29, #-12]
	ldur	w0, [x29, #-8]
	ldur	w1, [x29, #-12]
	bl	__Z3sumii
	str	w0, [sp, #16]
	ldr	w0, [sp, #16]
	bl	__Z6putNumi
	ldr	w0, [sp, #12]                   ; 4-byte Folded Reload
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
