;====================================================
;                                                   ;
;				   HKOS_Task.asm                    ;
;                                                   ;
;	Developer: Shin Hyun Kyu(GomTaengE)             ;
;	Toolchain: ARM-GCC                              ;
;                                                   ;
;	Last Update: 2021-11-06                         ;
;====================================================

	.extern HKOS_Cur_Task
	.extern HKOSTaskHook

	.global HKOS_Task_CTX_SW
	.global HKOS_Task_SW
	.section .text
	
	.align 1
	.type HKOS_Task_CTX_SW, %function
HKOS_Task_CTX_SW:
	// ================= Push Registers ====================
	stmfd sp!, {lr}
	stmfd sp!, {r0-r12}
	mrs r0, cpsr
	stmfd sp!, {r0}
	//======================================================

	clrex

	//====================== function ======================
	bl HKOSTaskHook
	//======================================================

	// ================= POP Registers =====================
	ldmfd sp!, {r0}
	msr spsr_cxsf, r0
	ldmfd sp!, {r0-r12, pc}^
	// =====================================================
	.size HKOS_Task_CTX_SW, . - HKOS_Task_CTX_SW