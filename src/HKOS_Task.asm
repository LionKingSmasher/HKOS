;====================================================
;                                                   ;
;				   HKOS_Task.asm                    ;
;                                                   ;
;	Developer: Shin Hyun Kyu(GomTaengE)             ;
;	Toolchain: ARM-GCC                              ;
;                                                   ;
;	Last Update: 2021-11-06                         ;
;====================================================

	.global HKOS_Task_CTX_SW
	.global HKOS_Task_SW
	.section .text
	
	.align 1
	.thumb_func
	.type HKOS_Task_CTX_SW, %function
HKOS_Task_CTX_SW:
	stmfd sp!, {pc}
	stmfd sp!, {lr}
	stmfd sp!, {r0-r12}
	mrs r0, cpsr
	tst lr, #1
	orrne r0, r0, #0x20
	stmfd sp!, {r0}
	ldmfd sp!, {r0}
	msr spsr_cxsf, r0
	ldmfd sp!, {r0-r12, lr, pc}^
	.size HKOS_Task_CTX_SW, . - HKOS_Task_CTX_SW