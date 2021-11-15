#include <HKOS_Macro.h>

//========================== Task ==========================
void    HKOS_Init();
#define HKOS_Task_Schedule_Init(__1, __2) __1.task_table = &__2;
void    HKOS_TASK_CREATE(struct HKOS_Task_t**, void*, ID);
void    HKOS_Start_Scheduler(struct HKOS_Task_t** task_table)
void    HKOS_RUN_NEXT(struct HKOS_Task_t);
#define HKOS_EXIT_CRITICAL()           return;
#define HKOS_EXIT_CRITICAL_RETURN(Val) return Val;
//==========================================================

//======================== Kernel ==========================
int printk(const char*, ...);
int scank(const char*, ...);
//==========================================================

//======================== Shell ===========================
void HKOS_Shell_Start();
//==========================================================