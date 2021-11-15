/*
 *
 *                 HSOS_Macro.h
 *
 *  This is a header file, which has Macros
 *  
 *  Developer: Shin Hyun Kyu(GomTaengE)
 *  
 */

//============== Value IO Macro =================
#define _IN(type)  volatile type
#define _OUT(type) volatile type *
#define _IO(type)  volatile type *
//===============================================

//============ Task Scheduling Macro ============
#define HKOS_FIFO 1u // FIFO
#define HKOS_RR   2u // Round Roubine
//===============================================

//================= Type Macro ==================
typedef int  (*HKOS_RETURN_STATUS_CALLBACK)(int, char**);
typedef void (*HKOS_CALLBACK)(int, char **);
typedef unsigned char u8;
typedef u8 ID;
typedef u8 SCHEDULER;
typedef u8 PRIORITY;
typedef unsigned int u32;
typedef u32 TIME;
//================= Type ID =====================
#define ID_HKOS_RETURN_STATUS_CALLBACK 1u;
#define ID_HKOS_CALLBACK               2u;
//===============================================

struct HKOS_Task_t {
	void* HKOS_TASK_FUNC;
	ID HKOS_FUNC_ID;
	// 1 : HKOS_RETURN STATUS_CALLBACK
	// 2 : HKOS_CALLBACK
};

struct HKOS_Scheduler_t {
	struct HKOS_Task_t* task_table; // Task Table
	TIME ScheduleTime;              // Schedule Time (Only For Round Roubine)
	PRIORITY  priority;             // Set Priority
	SCHEDULER Scheduler;            // Set Scheduler(1: FIFO, 2: RR)
}

#define Make_Task_Array(Name, Size) struct HKOS_Task_t Name[Size];
#define HKOS_FUNC(__T) __T __attribute__((interrupt("IRQ")))