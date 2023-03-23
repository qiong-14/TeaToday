	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 1
	.globl	__Z3sumii                       ; -- Begin function _Z3sumii
	.p2align	2
__Z3sumii:                              ; @_Z3sumii
	.cfi_startproc
; %bb.0:
	add	w0, w1, w0
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	stp	x20, x19, [sp, #-32]!           ; 16-byte Folded Spill
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	bl	__Z9createNumv
	mov	x19, x0
	bl	__Z9createNumv
	add	w0, w0, w19
	bl	__Z6putNumi
	mov	w0, #0
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp], #32             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
