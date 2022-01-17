#include <task.h>

template<unsigned short STK_SIZE>
void HKOS_Task<STK_SIZE>::StartTask() {
	
}

template<unsigned short STK_SIZE>
void HKOS_Task<STK_SIZE>::CreateTask(HKOS_FUNC f, unsigned short priority){
	for(unsigned short i = priority; i < STK_SIZE && this->TaskSTK[i] != NULL; i++)
		this->TaskSTK[i+1] = this->TaskSTK[i];
	this->TaskSTK[priority] = (PVOID)f;
}

