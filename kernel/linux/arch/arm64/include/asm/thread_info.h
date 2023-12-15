#ifndef __ASM_THREAD_INFO_H
#define __ASM_THREAD_INFO_H

#include <stdint.h>

struct task_struct;
typedef unsigned long mm_segment_t;

#define TIF_SIGPENDING 0 /* signal pending */
#define TIF_NEED_RESCHED 1 /* rescheduling necessary */
#define TIF_NOTIFY_RESUME 2 /* callback before returning to user */
#define TIF_FOREIGN_FPSTATE 3 /* CPU's FP state is not current's */
#define TIF_UPROBE 4 /* uprobe breakpoint or singlestep */
#define TIF_MTE_ASYNC_FAULT 5 /* MTE Asynchronous Tag Check Fault */
#define TIF_NOTIFY_SIGNAL 6 /* signal notifications exist */
#define TIF_SYSCALL_TRACE 8 /* syscall trace active */
#define TIF_SYSCALL_AUDIT 9 /* syscall auditing */
#define TIF_SYSCALL_TRACEPOINT 10 /* syscall tracepoint for ftrace */
#define TIF_SECCOMP 11 /* syscall secure computing */
#define TIF_SYSCALL_EMU 12 /* syscall emulation active */
#define TIF_MEMDIE 18 /* is terminating due to OOM killer */
#define TIF_FREEZE 19
#define TIF_RESTORE_SIGMASK 20
#define TIF_SINGLESTEP 21
#define TIF_32BIT 22 /* 32bit process */
#define TIF_SVE 23 /* Scalable Vector Extension in use */
#define TIF_SVE_VL_INHERIT 24 /* Inherit SVE vl_onexec across exec */
#define TIF_SSBD 25 /* Wants SSB mitigation */
#define TIF_TAGGED_ADDR 26 /* Allow tagged user addresses */
#define TIF_SME 27 /* SME in use */
#define TIF_SME_VL_INHERIT 28 /* Inherit SME vl_onexec across exec */

#define _TIF_SIGPENDING (1 << TIF_SIGPENDING)
#define _TIF_NEED_RESCHED (1 << TIF_NEED_RESCHED)
#define _TIF_NOTIFY_RESUME (1 << TIF_NOTIFY_RESUME)
#define _TIF_FOREIGN_FPSTATE (1 << TIF_FOREIGN_FPSTATE)
#define _TIF_SYSCALL_TRACE (1 << TIF_SYSCALL_TRACE)
#define _TIF_SYSCALL_AUDIT (1 << TIF_SYSCALL_AUDIT)
#define _TIF_SYSCALL_TRACEPOINT (1 << TIF_SYSCALL_TRACEPOINT)
#define _TIF_SECCOMP (1 << TIF_SECCOMP)
#define _TIF_SYSCALL_EMU (1 << TIF_SYSCALL_EMU)
#define _TIF_UPROBE (1 << TIF_UPROBE)
#define _TIF_SINGLESTEP (1 << TIF_SINGLESTEP)
#define _TIF_32BIT (1 << TIF_32BIT)
#define _TIF_SVE (1 << TIF_SVE)
#define _TIF_MTE_ASYNC_FAULT (1 << TIF_MTE_ASYNC_FAULT)
#define _TIF_NOTIFY_SIGNAL (1 << TIF_NOTIFY_SIGNAL)

#define _TIF_WORK_MASK                                                                               \
    (_TIF_NEED_RESCHED | _TIF_SIGPENDING | _TIF_NOTIFY_RESUME | _TIF_FOREIGN_FPSTATE | _TIF_UPROBE | \
     _TIF_MTE_ASYNC_FAULT | _TIF_NOTIFY_SIGNAL)

#define _TIF_SYSCALL_WORK \
    (_TIF_SYSCALL_TRACE | _TIF_SYSCALL_AUDIT | _TIF_SYSCALL_TRACEPOINT | _TIF_SECCOMP | _TIF_SYSCALL_EMU)

struct thread_info
{
    unsigned long flags; /* low level flags */
    mm_segment_t addr_limit; /* address limit */
    // from 3.7 to 4.9
    struct task_struct *task; /* main task structure */
    char _others[0];
};

/*
 * low level task data that entry.S needs immediate access to.
 */
// struct thread_info {
// 	unsigned long flags; /* low level flags */
// 	mm_segment_t addr_limit; /* address limit */
// #ifdef CONFIG_ARM64_SW_TTBR0_PAN
// 	u64 ttbr0; /* saved TTBR0_EL1 */
// #endif
// 	union {
// 		u64 preempt_count; /* 0 => preemptible, <0 => bug */
// 		struct {
// #ifdef CONFIG_CPU_BIG_ENDIAN
// 			u32 need_resched;
// 			u32 count;
// #else
// 			u32 count;
// 			u32 need_resched;
// #endif
// 		} preempt;
// 	};
// #ifdef CONFIG_SHADOW_CALL_STACK
// 	void *scs_base;
// 	void *scs_sp;
// #endif
// };

#endif