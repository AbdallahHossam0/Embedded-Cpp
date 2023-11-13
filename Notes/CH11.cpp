// > CH 11: C++ Multi-Tasking

// * There are 2 main types of schedulers
// 1- Co-operative Scheduler
// 2- Pre-emptive Scheduler

// # Schedulers uses scheduler algorithms to choose which task to run

// Task is a void to void function

// * For loop scheduler
// Simple - No RAM needed S
// Small code size - No pause
// No return - No Break

// But, you may need tasks to run in certain periods to reduce execution power.

// * you have 3 tasks
// - task a => executed every 2 ms
// - task b => executed every 8 ms
// - task c => executed every 16 ms

// on times 16, 32, 48, 64, ......
// the three task need to be executed so a "Timing Crunch" happened

// # To solve it you need to add offset to each tas with a small valued prime
// numbers
// - task a => executed every 2 ms  => offset 0
// - task b => executed every 8 ms  => offset 7
// - task c => executed every 16 ms => offset 13

// # No tasks intersection

// * The TCB => Task Control Block
// It encapsulates the task scheduling characteristics:

#include <array>

class TCB {
   public:
    typedef void (*functionPtr)(void);
    typedef unsigned short timer_t;
    typedef unsigned short tick_t;

    TCB(const functionPtr f, const timer_t p, const tick_t o = 0)
        : function(f), period(p), offset(o) {}

    bool execute(void);

   private:
    const functionPtr function;
    const timer_t period;
    tick_t offset;
};

void task_a(void) {}
void task_b(void) {}
void task_c(void) {}

std::array<TCB, 3> taskList{TCB(task_a, 2, 0), TCB(task_b, 8, 7),
                            TCB(task_c, 16, 13)};

// # The Scheduler
void scheduler(void) {
    std::find_if(taskList.begin(), taskList.end(),
                 [](TCB& task) -> bool { return task.execute(); });
}
// note => The task wrote first has the highest priority

int main(void) {
    // * init MCAL
    scheduler();
}

// Some complex projects will need more complex schedulers like "Preemptive
// Schedulers" Those schedulers are written with C and assembly as every task
// should be able to save and restore its context you can use the built in C++
// threads to make multithread programs or using well written RTOS-es
