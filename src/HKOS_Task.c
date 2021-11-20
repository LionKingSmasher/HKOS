#include <HSOS.h>

Make_Task_Array(HKOSTask, 16);
struct HKOS_Task_t* HKOS_Cur_Task;

void __attribute__((alias(_kexit))) kexit(int);

void __attribute__((weak)) _kexit(int __attribute__((unused)) argc){
	for(;;);
}

static void DefaultHandler() {
	while(1);
}

extern void __attribute__((weak, alias("DefaultHandler"))) HKOS_Timer_ON();

void HKOS_Init(){
	// TODO
}

void HKOS_TASK_CREATE(struct HKOS_Task_t* task_table[], void* func, ID id){
	static int recent_id = 0;
	if(recent_id < 256){
		task_table[recent_id]->HKOS_FUNC_ID   = id;
		task_table[recent_id]->HKOS_TASK_FUNC = func;
		recent_id++;
	}
}

void HKOS_Start_Scheduler(struct HKOS_Task_t* task_table[]){
	if(task_table[])
	HKOS_Timer_ON();
	for(;;){
		HKOS_Task_CTX_SW();
	}
}