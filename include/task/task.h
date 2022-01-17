/*
 *
 *             task/task.h
 *
 *
 *    Devleoper : Shin Hyun Kyu
 *
 *    (c) 2022-01-18 Shin Hyun Kyu. All rights reserved.
 *
 */

typedef int (*HKOS_FUNC)(int, char**);
typedef void VOID, *PVOID;

template<unsigned short STK_SIZE>
class HKOS_Task
{
private:
	unsigned short CURR_STK;      // Current Stack Position
	PVOID TaskSTK[STK_SIZE];  // Task Stack
public:
	HKOS() { CURR_STK = 0; };
	void StartTask();
	void CreateTask(HKOS_FUNC /* Function */, unsigned short /* Priority */);
};