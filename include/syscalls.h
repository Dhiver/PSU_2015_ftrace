/*
** syscalls.h for ftrace in /home/work/work/projects/PSU_2015_ftrace_doc/PSU_2015_ftrace/include
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
**
** Started on  Wed Apr 20 10:18:08 2016 Bastien DHIVER
** Last update Thu Apr 28 23:08:23 2016 Bastien DHIVER
*/

#ifndef SYSCALLS_H_
# define SYSCALLS_H_

# define QUOTE(stuff)	#stuff

typedef enum		e_types
{
  E_UNKN,
  E_INT,
  E_STR,
  E_ADDR,
  E_STRUC,
  E_SIZE_T,
  E_INT_2,
  E_USI_L,
  E_STRSTR,
  E_LONG,
  E_END
}			t_types;

# define UNKN		E_UNKN
# define INT		E_INT
# define STR		E_STR
# define ADDR		E_ADDR
# define STRUC		E_STRUCT
# define SIZE_T		E_SIZE_T
# define INT_2		E_INT_2
# define USI_L		E_USI_L
# define STRSTR		E_STRSTR
# define LONG		E_LONG

# define S_UNKN		QUOTE(0)
# define S_INT		QUOTE(1)
# define S_STR		QUOTE(2)
# define S_ADDR		QUOTE(3)
# define S_STRUC	QUOTE(4)
# define S_SIZE_T	QUOTE(5)
# define S_INT_2	QUOTE(6)
# define S_USI_L	QUOTE(7)
# define S_STRSTR	QUOTE(8)
# define S_LONG		QUOTE(9)

typedef	struct		s_syscalls
{
  char			*name;
  int			ret;
  char			*args;
}			t_syscalls;

static const t_syscalls	g_syscalls[] =
#ifdef ELF_IS_32_
{{"restart_syscall", INT, ""},
#else
	{{"read", INT, S_INT S_STR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"exit", UNKN, S_INT},
#else
	{"write", INT, S_INT S_STR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"fork", INT, ""},
#else
	{"open", INT, S_STR S_INT},
#endif
#ifdef ELF_IS_32_
	{{"read", INT, S_INT S_STR S_SIZE_T},
#else
	{"close", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"write", INT, S_INT S_STR S_SIZE_T},
#else
	{"stat", INT, S_STR S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"open", INT, S_STR S_INT},
#else
	{"fstat", INT, S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"close", INT, S_INT},
#else
	{"lstat", INT, S_STR S_STRUC},
#endif
#ifndef ELF_IS_32_
	{"waitpid", INT, S_INT S_ADDR S_INT},
#else
	{"poll", INT, S_STRUC S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"creat", INT, S_STR S_INT},
#else
	{"lseek", INT, S_INT S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"link", INT, S_STR S_STR},
#else
	{"mmap", ADDR, S_ADDR S_SIZE_T S_INT S_INT S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"unlink", INT, S_STR},
#else
	{"mprotect", INT, S_ADDR S_SIZE_T S_INT},
#endif
#ifdef ELF_IS_32_
	{"execve", INT, S_STR S_STRSTR S_STRSTR},
#else
	{"munmap", INT, S_ADDR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"chdir", INT, S_STR},
#else
	{"brk", ADDR, S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"time", INT, S_ADDR},
#else
	{"rt_sigaction", INT, S_INT S_STRUC S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"mknod", INT, S_STR S_INT S_INT},
#else
	{"rt_sigprocmask", INT, S_INT S_ADDR S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"chmod", INT, S_STR S_INT},
#else
	{"rt_sigreturn", INT, S_UNKN},
#endif
#ifdef ELF_IS_32_
	{"lchown", INT, S_STR S_INT S_INT},
#else
	{"ioctl", INT, S_INT S_USI_L S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"break", INT, S_UNKN},
#else
	{"pread64", INT, S_INT S_ADDR S_SIZE_T S_INT},
#endif
#ifdef ELF_IS_32_
	{"oldstat", UNKN, S_UNKN},
#else
	{"pwrite64", INT, S_INT S_ADDR S_SIZE_T S_INT},
#endif
#ifdef ELF_IS_32_
	{"lseek", INT, S_INT S_INT S_INT},
#else
	{"readv", INT, S_INT S_STRUC S_INT},
#endif
#ifdef ELF_IS_32_
	{"getpid", INT, ""},
#else
	{"writev", INT, S_INT S_STRUC S_INT},
#endif
#ifdef ELF_IS_32_
	{"mount", INT, S_STR S_STR S_STR S_USI_L S_ADDR},
#else
	{"access", INT, S_STR S_INT},
#endif
#ifdef ELF_IS_32_
	{"umount", INT, S_STR},
#else
	{"pipe", INT, S_INT_2},
#endif
#ifdef ELF_IS_32_
	{"setuid", INT, S_INT},
#else
	{"select", INT, S_INT S_ADDR S_ADDR S_ADDR S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"getuid", INT, ""},
#else
	{"sched_yield", INT, ""},
#endif
#ifdef ELF_IS_32_
	{"stime", INT, S_ADDR},
#else
	{"mremap", ADDR, S_ADDR S_SIZE_T S_SIZE_T S_INT S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"ptrace", LONG, S_INT S_INT S_ADDR S_ADDR},
#else
	{"msync", INT, S_ADDR S_SIZE_T S_INT},
#endif
#ifdef ELF_IS_32_
	{"alarm", SIZE_T, S_SIZE_T},
#else
	{"mincore", INT, S_ADDR S_SIZE_T S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"oldfstat", UNKN, S_UNKN},
#else
	{"madvise", INT, S_ADDR S_SIZE_T S_INT},
#endif
#ifdef ELF_IS_32_
	{"pause", INT, ""},
#else
	{"shmget", INT, S_INT S_SIZE_T S_INT},
#endif
#ifdef ELF_IS_32_
	{"utime", INT, S_STR S_STRUC},
#else
	{"shmat", ADDR, S_INT S_ADDR S_INT},
#endif
#ifdef ELF_IS_32_
	{"stty", INT, S_UNKN},
#else
	{"shmctl", INT, S_INT S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"gtty", INT, S_UNKN},
#else
	{"dup", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"access", INT, S_STR S_INT},
#else
	{"dup2", INT, S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"nice", INT, S_INT},
#else
	{"pause", INT, ""},
#endif
#ifdef ELF_IS_32_
	{"ftime", INT, S_UNKN},
#else
	{"nanosleep", INT, S_STRUC S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"sync", UNKN, ""},
#else
	{"getitimer", INT, S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"kill", INT, S_INT S_INT},
#else
	{"alarm", SIZE_T, S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"rename", INT, S_STR S_STR},
#else
	{"setitimer", INT, S_STRUC S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"mkdir", INT, S_STR S_INT},
#else
	{"getpid", INT, ""},
#endif
#ifdef ELF_IS_32_
	{"rmdir", INT, S_STR},
#else
	{"sendfile", INT, S_INT S_INT S_ADDR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"dup", INT, S_INT},
#else
	{"socket", INT, S_INT S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"pipe", INT, S_INT_2},
#else
	{"connect", INT, S_INT S_STRUC S_INT},
#endif
#ifdef ELF_IS_32_
	{"times", INT, S_STRUC},
#else
	{"accept", INT, S_INT S_STRUC S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"prof", INT, S_UNKN},
#else
	{"sendto", INT, S_INT S_ADDR S_SIZE_T S_INT S_STRUC S_INT},
#endif
#ifdef ELF_IS_32_
	{"brk", ADDR, S_ADDR},
#else
	{"recvfrom", INT, S_INT S_ADDR S_SIZE_T S_INT S_STRUC S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"setgid", INT, S_INT},
#else
	{"sendmsg", INT, S_INT S_STRUC S_INT},
#endif
#ifdef ELF_IS_32_
	{"getgid", INT, ""},
#else
	{"recvmsg", INT, S_INT S_STRUC S_INT},
#endif
#ifdef ELF_IS_32_
	{"signal", INT, S_ADDR S_ADDR},
#else
	{"shutdown", INT, S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"geteuid", INT, ""},
#else
	{"bind", INT, S_INT S_STRUC S_INT},
#endif
#ifdef ELF_IS_32_
	{"getegid", INT, ""},
#else
	{"listen", INT, S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"acct", INT, S_STR},
#else
	{"getsockname", INT, S_INT S_STRUC S_INT},
#endif
#ifdef ELF_IS_32_
	{"umount2", INT, S_STR S_INT},
#else
	{"getpeername", INT, S_INT S_STRUC S_INT},
#endif
#ifdef ELF_IS_32_
	{"lock", INT, S_UNKN},
#else
	{"socketpair", INT, S_INT S_INT S_INT S_INT_2},
#endif
#ifdef ELF_IS_32_
	{"ioctl", INT, S_INT S_USI_L S_STRUC},
#else
	{"setsockopt", INT, S_INT S_INT S_INT S_ADDR S_INT},
#endif
#ifdef ELF_IS_32_
	{"fcntl", INT, S_INT S_INT S_UNKN},
#else
	{"getsockopt", INT, S_INT S_INT S_INT S_ADDR S_INT},
#endif
#ifdef ELF_IS_32_
	{"mpx", INT, S_UNKN},
#else
	{"clone", INT, S_USI_L S_ADDR S_ADDR S_ADDR S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"setpgid", INT, S_INT S_INT},
#else
	{"fork", INT, ""},
#endif
#ifdef ELF_IS_32_
	{"ulimit", INT, S_UNKN},
#else
	{"vfork", INT, ""},
#endif
#ifdef ELF_IS_32_
	{"oldolduname", INT, S_UNKN},
#else
	{"execve", INT, S_STR S_STRSTR S_STRSTR},
#endif
#ifdef ELF_IS_32_
	{"umask", INT, S_INT},
#else
	{"exit", UNKN, S_INT},
#endif
#ifdef ELF_IS_32_
	{"chroot", INT, S_STR},
#else
	{"wait4", INT, S_INT S_ADDR S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"ustat", INT, S_INT S_STRUC},
#else
	{"kill", INT, S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"dup2", INT, S_INT S_INT},
#else
	{"uname", INT, S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"getppid", INT, ""},
#else
	{"semget", INT, S_INT S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"getpgrp", INT, S_INT},
#else
	{"semop", INT, S_INT S_STRUC S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"setsid", INT, ""},
#else
	{"semctl", INT, S_INT S_INT S_INT S_UNKN},
#endif
#ifdef ELF_IS_32_
	{"sigaction", INT, S_INT S_ADDR S_ADDR},
#else
	{"shmdt", INT, S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"sgetmask", LONG, S_UNKN},
#else
	{"msgget", INT, S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"ssetmask", LONG, S_LONG},
#else
	{"msgsnd", INT, S_INT S_ADDR S_SIZE_T S_INT},
#endif
#ifdef ELF_IS_32_
	{"setreuid", INT, S_INT S_INT},
#else
	{"msgrcv", INT, S_INT S_ADDR S_SIZE_T S_LONG S_INT},
#endif
#ifdef ELF_IS_32_
	{"setregid", INT, S_INT S_INT},
#else
	{"msgctl", INT, S_INT S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"sigsuspend", INT, S_ADDR},
#else
	{"fcntl", INT, S_INT S_INT S_UNKN},
#endif
#ifdef ELF_IS_32_
	{"sigpending", INT, S_ADDR},
#else
	{"flock", INT, S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"sethostname", INT, S_STR S_SIZE_T},
#else
	{"fsync", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"setrlimit", INT, S_INT S_STRUC},
#else
	{"fdatasync", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"getrlimit", INT, S_INT S_STRUC},
#else
	{"truncate", INT, S_STR S_INT},
#endif
#ifdef ELF_IS_32_
	{"getrusage", INT, S_INT S_STRUC},
#else
	{"ftruncate", INT, S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"gettimeofday", INT, S_STRUC S_STRUC},
#else
	{"getdents", INT, S_SIZE_T S_STRUC S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"settimeofday", INT, S_STRUC S_STRUC},
#else
	{"getcwd", STR, S_STR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"getgroups", INT, S_INT S_ADDR},
#else
	{"chdir", INT, S_STR},
#endif
#ifdef ELF_IS_32_
	{"setgroups", INT, S_INT S_ADDR},
#else
	{"fchdir", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"select", INT, S_INT S_ADDR S_ADDR S_ADDR S_STRUC},
#else
	{"rename", INT, S_STR S_STR},
#endif
#ifdef ELF_IS_32_
	{"symlink", INT, S_STR S_STR},
#else
	{"mkdir", INT, S_STR S_INT},
#endif
#ifdef ELF_IS_32_
	{"oldlstat", UNKN, S_UNKN},
#else
	{"rmdir", INT, S_STR},
#endif
#ifdef ELF_IS_32_
	{"readlink", INT, S_STR S_STR S_SIZE_T},
#else
	{"creat", INT, S_STR S_INT},
#endif
#ifdef ELF_IS_32_
	{"uselib", INT, S_STR},
#else
	{"link", INT, S_STR S_STR},
#endif
#ifdef ELF_IS_32_
	{"swapon", INT, S_STR S_INT},
#else
	{"unlink", INT, S_STR},
#endif
#ifdef ELF_IS_32_
	{"reboot", INT, S_INT},
#else
	{"symlink", INT, S_STR S_STR},
#endif
#ifdef ELF_IS_32_
	{"readdir", INT, S_USI_L S_ADDR S_USI_L},
#else
	{"readlink", INT, S_STR S_STR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"mmap", ADDR, S_ADDR S_SIZE_T S_INT S_INT S_INT S_INT},
#else
	{"chmod", INT, S_STR S_INT},
#endif
#ifdef ELF_IS_32_
	{"munmap", INT, S_ADDR S_SIZE_T},
#else
	{"fchmod", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"truncate", INT, S_STR S_INT},
#else
	{"chown", INT, S_STR S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"ftruncate", INT, S_INT S_INT},
#else
	{"fchown", INT, S_INT S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"fchmod", INT, S_INT},
#else
	{"lchown", INT, S_STR S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"fchown", INT, S_INT S_INT S_INT},
#else
	{"umask", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"getpriority", INT, S_INT S_INT},
#else
	{"gettimeofday", INT, S_STRUC S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"setpriority", INT, S_INT S_INT S_INT},
#else
	{"getrlimit", INT, S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"profil", INT, S_UNKN},
#else
	{"getrusage", INT, S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"statfs", INT, S_STR S_STRUC},
#else
	{"sysinfo", INT, S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"fstatfs", INT, S_INT S_STRUC},
#else
	{"times", INT, S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"ioperm", INT, S_USI_L S_USI_L S_INT},
#else
	{"ptrace", LONG, S_INT S_INT S_ADDR S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"socketcall", INT, S_INT S_ADDR},
#else
	{"getuid", INT, ""},
#endif
#ifdef ELF_IS_32_
	{"syslog", INT, S_INT S_STR S_INT},
#else
	{"syslog", INT, S_INT S_STR S_INT},
#endif
#ifdef ELF_IS_32_
	{"setitimer", INT, S_STRUC S_STRUC},
#else
	{"getgid", INT, ""},
#endif
#ifdef ELF_IS_32_
	{"getitimer", INT, S_INT S_STRUC},
#else
	{"setuid", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"stat", INT, S_STR S_STRUC},
#else
	{"setgid", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"lstat", INT, S_STR S_STRUC},
#else
	{"geteuid", INT, ""},
#endif
#ifdef ELF_IS_32_
	{"fstat", INT, S_INT S_STRUC},
#else
	{"getegid", INT, ""},
#endif
#ifdef ELF_IS_32_
	{"olduname", INT, S_UNKN},
#else
	{"setpgid", INT, S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"iopl", INT, S_INT},
#else
	{"getppid", INT, ""},
#endif
#ifdef ELF_IS_32_
	{"vhangup", INT, ""},
#else
	{"getpgrp", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"idle", INT, S_UNKN},
#else
	{"setsid", INT, ""},
#endif
#ifdef ELF_IS_32_
	{"vm86old", INT, S_ADDR},
#else
	{"setreuid", INT, S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"wait4", INT, S_INT S_ADDR S_INT S_STRUC},
#else
	{"setregid", INT, S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"swapoff", INT, S_STR},
#else
	{"getgroups", INT, S_INT S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"sysinfo", INT, S_STRUC},
#else
	{"setgroups", INT, S_INT S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"ipc", INT, S_USI_L S_INT S_INT S_INT S_ADDR S_LONG},
#else
	{"setresuid", INT, S_INT S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"fsync", INT, S_INT},
#else
	{"getresuid", INT, S_INT S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"sigreturn", INT, S_UNKN},
#else
	{"setresgid", INT, S_INT S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"clone", INT, S_USI_L S_ADDR S_ADDR S_ADDR S_STRUC},
#else
	{"getresgid", INT, S_INT S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"setdomainname", INT, S_STR S_SIZE_T},
#else
	{"getpgid", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"uname", INT, S_STRUC},
#else
	{"setfsuid", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"modify_ldt", INT, S_INT S_ADDR S_USI_L},
#else
	{"setfsgid", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"adjtimex", INT, S_ADDR},
#else
	{"getsid", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"mprotect", INT, S_ADDR S_SIZE_T S_INT},
#else
	{"capget", INT, S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"sigprocmask", INT, S_INT S_ADDR S_ADDR},
#else
	{"capset", INT, S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"create_module", INT, S_STR S_SIZE_T},
#else
	{"rt_sigpending", INT, S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"init_module", INT, S_ADDR S_USI_L S_STR},
#else
	{"rt_sigtimedwait", INT, S_ADDR S_ADDR S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"delete_module", INT, S_STR S_INT},
#else
	{"rt_sigqueueinfo", INT, S_INT S_INT S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"get_kernel_syms", INT, S_STRUC},
#else
	{"rt_sigsuspend", INT, S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"quotactl", INT, S_INT S_STR S_INT S_INT},
#else
	{"sigaltstack", INT, S_ADDR S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"getpgid", INT, S_INT},
#else
	{"utime", INT, S_STR S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"fchdir", INT, S_INT},
#else
	{"mknod", INT, S_STR S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"bdflush", INT, S_ADDR},
#else
	{"uselib", INT, S_STR},
#endif
#ifdef ELF_IS_32_
	{"sysfs", INT, S_INT},
#else
	{"personality", INT, S_USI_L},
#endif
#ifdef ELF_IS_32_
	{"personality", INT, S_USI_L},
#else
	{"ustat", INT, S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"afs_syscall", UNKN, ""},
#else
	{"statfs", INT, S_STR S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"setfsuid", INT, S_INT},
#else
	{"fstatfs", INT, S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"setfsgid", INT, S_INT},
#else
	{"sysfs", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"_llseek", INT, S_INT S_LONG S_LONG S_ADDR S_INT},
#else
	{"getpriority", INT, S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"getdents", INT, S_SIZE_T S_STRUC S_SIZE_T},
#else
	{"setpriority", INT, S_INT S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"_newselect", UNKN, S_UNKN},
#else
	{"sched_setparam", INT, S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"flock", INT, S_INT S_INT},
#else
	{"sched_getparam", INT, S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"msync", INT, S_ADDR S_SIZE_T S_INT},
#else
	{"sched_setscheduler", INT, S_INT S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"readv", INT, S_INT S_STRUC S_INT},
#else
	{"sched_getscheduler", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"writev", INT, S_INT S_STRUC S_INT},
#else
	{"sched_get_priority_max", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"getsid", INT, S_INT},
#else
	{"sched_get_priority_min", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"fdatasync", INT, S_INT},
#else
	{"sched_rr_get_interval", INT, S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"_sysctl", INT, S_STRUC},
#else
	{"mlock", INT, S_ADDR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"mlock", INT, S_ADDR S_SIZE_T},
#else
	{"munlock", INT, S_ADDR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"munlock", INT, S_ADDR S_SIZE_T},
#else
	{"mlockall", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"mlockall", INT, S_INT},
#else
	{"munlockall", INT, ""},
#endif
#ifdef ELF_IS_32_
	{"munlockall", INT, ""},
#else
	{"vhangup", INT, ""},
#endif
#ifdef ELF_IS_32_
	{"sched_setparam", INT, S_INT S_STRUC},
#else
	{"modify_ldt", INT, S_INT S_ADDR S_USI_L},
#endif
#ifdef ELF_IS_32_
	{"sched_getparam", INT, S_INT S_STRUC},
#else
	{"pivot_root", INT, S_STR S_STR},
#endif
#ifdef ELF_IS_32_
	{"sched_setscheduler", INT, S_INT S_INT S_STRUC},
#else
	{"_sysctl", INT, S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"sched_getscheduler", INT, S_INT},
#else
	{"prctl", INT, S_INT S_USI_L S_USI_L S_USI_L S_USI_L},
#endif
#ifdef ELF_IS_32_
	{"sched_yield", INT, ""},
#else
	{"arch_prctl", INT, S_INT S_USI_L},
#endif
#ifdef ELF_IS_32_
	{"sched_get_priority_max", INT, S_INT},
#else
	{"adjtimex", INT, S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"sched_get_priority_min", INT, S_INT},
#else
	{"setrlimit", INT, S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"sched_rr_get_interval", INT, S_INT S_STRUC},
#else
	{"chroot", INT, S_STR},
#endif
#ifdef ELF_IS_32_
	{"nanosleep", INT, S_STRUC S_STRUC},
#else
	{"sync", UNKN, ""},
#endif
#ifdef ELF_IS_32_
	{"mremap", ADDR, S_ADDR S_SIZE_T S_SIZE_T S_INT S_ADDR},
#else
	{"acct", INT, S_STR},
#endif
#ifdef ELF_IS_32_
	{"setresuid", INT, S_INT S_INT S_INT},
#else
	{"settimeofday", INT, S_STRUC S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"getresuid", INT, S_INT S_INT S_INT},
#else
	{"mount", INT, S_STR S_STR S_STR S_USI_L S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"vm86", INT, S_USI_L S_ADDR},
#else
	{"umount2", INT, S_STR S_INT},
#endif
#ifdef ELF_IS_32_
	{"query_module", INT, S_STR S_INT S_ADDR S_SIZE_T S_ADDR},
#else
	{"swapon", INT, S_STR S_INT},
#endif
#ifdef ELF_IS_32_
	{"poll", INT, S_STRUC S_INT S_INT},
#else
	{"swapoff", INT, S_STR},
#endif
#ifdef ELF_IS_32_
	{"nfsservctl", LONG, S_INT S_STRUC S_ADDR},
#else
	{"reboot", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"setresgid", INT, S_INT S_INT S_INT},
#else
	{"sethostname", INT, S_STR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"getresgid", INT, S_INT S_INT S_INT},
#else
	{"setdomainname", INT, S_STR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"prctl", INT, S_INT S_USI_L S_USI_L S_USI_L S_USI_L},
#else
	{"iopl", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"rt_sigreturn", INT, S_UNKN},
#else
	{"ioperm", INT, S_USI_L S_USI_L S_INT},
#endif
#ifdef ELF_IS_32_
	{"rt_sigaction", INT, S_INT S_STRUC S_STRUC},
#else
	{"create_module", INT, S_STR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"rt_sigprocmask", INT, S_INT S_ADDR S_ADDR},
#else
	{"init_module", INT, S_ADDR S_USI_L S_STR},
#endif
#ifdef ELF_IS_32_
	{"rt_sigpending", INT, S_ADDR},
#else
	{"delete_module", INT, S_STR S_INT},
#endif
#ifdef ELF_IS_32_
	{"rt_sigtimedwait", INT, S_ADDR S_ADDR S_STRUC},
#else
	{"get_kernel_syms", INT, S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"rt_sigqueueinfo", INT, S_INT S_INT S_ADDR},
#else
	{"query_module", INT, S_STR S_INT S_ADDR S_SIZE_T S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"rt_sigsuspend", INT, S_ADDR},
#else
	{"quotactl", INT, S_INT S_STR S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"pread64", INT, S_INT S_ADDR S_SIZE_T S_INT},
#else
	{"nfsservctl", LONG, S_INT S_STRUC S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"pwrite64", INT, S_INT S_ADDR S_SIZE_T S_INT},
#else
	{"getpmsg", UNKN, ""},
#endif
#ifdef ELF_IS_32_
	{"chown", INT, S_STR S_INT S_INT},
#else
	{"putpmsg", UNKN, ""},
#endif
#ifdef ELF_IS_32_
	{"getcwd", STR, S_STR S_SIZE_T},
#else
	{"afs_syscall", UNKN, ""},
#endif
#ifdef ELF_IS_32_
	{"capget", INT, S_INT S_INT},
#else
	{"tuxcall", UNKN, ""},
#endif
#ifdef ELF_IS_32_
	{"capset", INT, S_INT S_INT},
#else
	{"security", UNKN, ""},
#endif
#ifdef ELF_IS_32_
	{"sigaltstack", INT, S_ADDR S_ADDR},
#else
	{"gettid", INT, ""},
#endif
#ifdef ELF_IS_32_
	{"sendfile", INT, S_INT S_INT S_ADDR S_SIZE_T},
#else
	{"readahead", INT, S_INT S_INT S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"getpmsg", UNKN, ""},
#else
	{"setxattr", INT, S_STR S_STR S_ADDR S_SIZE_T S_INT},
#endif
#ifdef ELF_IS_32_
	{"putpmsg", UNKN, ""},
#else
	{"lsetxattr", INT, S_STR S_STR S_ADDR S_SIZE_T S_INT},
#endif
#ifdef ELF_IS_32_
	{"vfork", INT, ""},
#else
	{"fsetxattr", INT, S_INT S_STR S_ADDR S_SIZE_T S_INT},
#endif
#ifdef ELF_IS_32_
	{"ugetrlimit", UNKN, S_UNKN},
#else
	{"getxattr", INT, S_STR S_STR S_ADDR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"mmap2", ADDR, S_ADDR S_SIZE_T S_INT S_INT S_INT S_INT},
#else
	{"lgetxattr", INT, S_STR S_STR S_ADDR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"truncate64", INT, S_STR S_INT},
#else
	{"fgetxattr", INT, S_INT S_STR S_ADDR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"ftruncate64", INT, S_INT S_INT},
#else
	{"listxattr", INT, S_STR S_STR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"stat64", INT, S_STR S_ADDR},
#else
	{"llistxattr", INT, S_STR S_STR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"lstat64", INT, S_STR S_ADDR},
#else
	{"flistxattr", INT, S_INT S_STR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"fstat64", INT, S_INT S_ADDR},
#else
	{"removexattr", INT, S_STR S_STR},
#endif
#ifdef ELF_IS_32_
	{"lchown32", INT, S_STR S_INT S_INT},
#else
	{"lremovexattr", INT, S_STR S_STR},
#endif
#ifdef ELF_IS_32_
	{"getuid32", INT, S_UNKN},
#else
	{"fremovexattr", INT, S_INT S_STR},
#endif
#ifdef ELF_IS_32_
#else
	{"tkill", INT, S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"getgid32", INT, S_UNKN},
#else
	{"time", INT, S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"geteuid32", INT, S_UNKN};
#else
	{"futex", INT, S_ADDR S_INT S_INT S_STRUC S_ADDR S_INT},
#endif
#ifdef ELF_IS_32_
	  {"getegid32", INT, S_UNKN},
#else
	{"sched_setaffinity", INT, S_INT S_SIZE_T S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"setreuid32", INT, S_INT S_INT},
#else
	{"sched_getaffinity", INT, S_INT S_SIZE_T S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"setregid32", INT, S_INT S_INT},
#else
	{"set_thread_area", INT, S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"getgroups32", INT, S_INT S_ADDR},
#else
	{"io_setup", INT, S_SIZE_T S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"setgroups", INT, S_SIZE_T S_ADDR},
#else
	{"io_destroy", INT, S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"fchown32", INT, S_INT S_INT S_INT},
#else
	{"io_getevents", INT, S_SIZE_T S_LONG S_LONG S_STRUC S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"setresuid32", INT, S_INT S_INT},
#else
	{"io_submit", INT, S_INT S_LONG S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"getresuid32", INT, S_ADDR S_ADDR S_ADDR},
#else
	{"io_cancel", INT, S_SIZE_T S_STRUC S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"setresgid32", INT, S_INT S_INT S_INT},
#else
	{"get_thread_area", INT, S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"getresgid32", INT, S_ADDR S_ADDR S_ADDR},
#else
	{"lookup_dcookie", INT, S_SIZE_T S_STR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"chown32", INT, S_STR S_INT S_INT},
#else
	{"epoll_create", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"setuid32", INT, S_INT},
#else
	{"epoll_ctl_old", UNKN, ""},
#endif
#ifdef ELF_IS_32_
	{"setgid32", INT, S_INT},
#else
	{"epoll_wait_old", UNKN, ""},
#endif
#ifdef ELF_IS_32_
	{"setfsuid32", INT, S_INT},
#else
	{"remap_file_pages", INT, S_ADDR S_SIZE_T S_INT S_SIZE_T S_INT},
#endif
#ifdef ELF_IS_32_
	{"setfsgid32", INT, S_INT},
#else
	{"getdents64", INT, S_SIZE_T S_STRUC S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"pivot_root", INT, S_STR S_STR},
#else
	{"set_tid_address", LONG, S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"mincore", INT, S_ADDR S_SIZE_T S_ADDR},
#else
	{"restart_syscall", INT, ""},
#endif
#ifdef ELF_IS_32_
	{"madvise", INT, S_ADDR S_SIZE_T S_INT},
#else
	{"semtimedop", INT, S_INT S_STRUC S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"getdents64", INT, S_SIZE_T S_STRUC S_SIZE_T},
#else
	{"fadvise64", INT, S_INT S_INT S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"fcntl64", INT, S_INT S_INT S_UNKN},
#else
	{"timer_create", INT, S_INT S_STRUC S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"gettid", INT, ""},
#else
	{"timer_settime", INT, S_INT S_INT S_STRUC S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"readahead", INT, S_INT S_INT S_SIZE_T},
#else
	{"timer_gettime", INT, S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"setxattr", INT, S_STR S_STR S_ADDR S_SIZE_T S_INT},
#else
	{"timer_getoverrun", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"lsetxattr", INT, S_STR S_STR S_ADDR S_SIZE_T S_INT},
#else
	{"timer_delete", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"fsetxattr", INT, S_INT S_STR S_ADDR S_SIZE_T S_INT},
#else
	{"clock_settime", INT, S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"getxattr", INT, S_STR S_STR S_ADDR S_SIZE_T},
#else
	{"clock_gettime", INT, S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"lgetxattr", INT, S_STR S_STR S_ADDR S_SIZE_T},
#else
	{"clock_getres", INT, S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"fgetxattr", INT, S_INT S_STR S_ADDR S_SIZE_T},
#else
	{"clock_nanosleep", INT, S_INT S_INT S_STRUC S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"listxattr", INT, S_STR S_STR S_SIZE_T},
#else
	{"exit_group", UNKN, S_INT},
#endif
#ifdef ELF_IS_32_
	{"llistxattr", INT, S_STR S_STR S_SIZE_T},
#else
	{"epoll_wait", INT, S_INT S_STRUC S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"flistxattr", INT, S_INT S_STR S_SIZE_T},
#else
	{"epoll_ctl", INT, S_INT S_INT S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"removexattr", INT, S_STR S_STR},
#else
	{"tgkill", INT, S_INT S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"lremovexattr", INT, S_STR S_STR},
#else
	{"utimes", INT, S_STR S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"fremovexattr", INT, S_INT S_STR},
#else
	{"vserver", UNKN, ""},
#endif
#ifdef ELF_IS_32_
	{"tkill", INT, S_INT S_INT},
#else
	{"mbind", LONG, S_ADDR S_USI_L S_INT S_ADDR S_USI_L S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"sendfile64", SIZE_T, S_INT S_INT S_ADDR S_SIZE_T},
#else
	{"set_mempolicy", LONG, S_INT S_ADDR S_USI_L},
#endif
#ifdef ELF_IS_32_
	{"futex", INT, S_ADDR S_INT S_INT S_STRUC S_ADDR S_INT},
#else
	{"get_mempolicy", INT, S_ADDR S_ADDR S_USI_L S_USI_L S_USI_L},
#endif
#ifdef ELF_IS_32_
	{"sched_setaffinity", INT, S_INT S_SIZE_T S_ADDR},
#else
	{"mq_open", INT, S_STR S_INT},
#endif
#ifdef ELF_IS_32_
	{"sched_getaffinity", INT, S_INT S_SIZE_T S_ADDR},
#else
	{"mq_unlink", INT, S_STR},
#endif
#ifdef ELF_IS_32_
	{"set_thread_area", INT, S_STRUC},
#else
	{"mq_timedsend", INT, S_INT S_STR S_SIZE_T S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"get_thread_area", INT, S_STRUC},
#else
	{"mq_timedreceive", INT, S_INT S_STR S_SIZE_T S_ADDR S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"io_setup", INT, S_SIZE_T S_ADDR},
#else
	{"mq_notify", INT, S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"io_destroy", INT, S_SIZE_T},
#else
	{"mq_getsetattr", INT, S_INT S_STRUC S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"io_getevents", INT, S_SIZE_T S_LONG S_LONG S_STRUC S_STRUC},
#else
	{"kexec_load", LONG, S_USI_L S_USI_L S_STRUC S_USI_L},
#endif
#ifdef ELF_IS_32_
	{"io_submit", INT, S_INT S_LONG S_ADDR},
#else
	{"waitid", INT, S_INT S_ADDR S_INT},
#endif
#ifdef ELF_IS_32_
	{"io_cancel", INT, S_SIZE_T S_STRUC S_STRUC},
#else
	{"add_key", INT, S_STR S_STR S_ADDR S_SIZE_T S_INT},
#endif
#ifdef ELF_IS_32_
	{"fadvise64", INT, S_INT S_INT S_INT S_INT},
#else
	{"request_key", INT, S_STR S_STR S_STR S_INT},
#endif
#ifdef ELF_IS_32_
	{"exit_group", UNKN, S_INT},
#else
	{"keyctl", LONG, S_INT S_UNKN},
#endif
#ifdef ELF_IS_32_
	{"lookup_dcookie", INT, S_SIZE_T S_STR S_SIZE_T},
#else
	{"ioprio_set", INT, S_INT S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"epoll_create", INT, S_INT},
#else
	{"ioprio_get", INT, S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"epoll_ctl", INT, S_INT S_INT S_INT S_STRUC},
#else
	{"inotify_init", INT, ""},
#endif
#ifdef ELF_IS_32_
	{"epoll_wait", INT, S_INT S_STRUC S_INT S_INT},
#else
	{"inotify_add_watch", INT, S_INT S_STR S_INT},
#endif
#ifdef ELF_IS_32_
	{"remap_file_pages", INT, S_ADDR S_SIZE_T S_INT S_SIZE_T S_INT},
#else
	{"inotify_rm_watch", INT, S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"set_tid_address", LONG, S_ADDR},
#else
	{"migrate_pages", LONG, S_INT S_USI_L S_ADDR S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"timer_create", INT, S_INT S_STRUC S_ADDR},
#else
	{"openat", INT, S_INT S_STR S_INT},
#endif
#ifdef ELF_IS_32_
	{"timer_settime", INT, S_INT S_INT S_STRUC S_STRUC},
#else
	{"mkdirat", INT, S_INT S_STR S_INT},
#endif
#ifdef ELF_IS_32_
	{"timer_gettime", INT, S_INT S_STRUC},
#else
	{"mknodat", INT, S_INT S_STR S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"timer_getoverrun", INT, S_INT},
#else
	{"fchownat", INT, S_INT S_STR S_INT S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"timer_delete", INT, S_INT},
#else
	{"futimesat", INT, S_INT S_STR S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"clock_settime", INT, S_INT S_STRUC},
#else
	{"newfstatat", INT, S_INT S_STR S_STRUC S_INT},
#endif
#ifdef ELF_IS_32_
	{"clock_gettime", INT, S_INT S_STRUC},
#else
	{"unlinkat", INT, S_INT S_STR S_INT},
#endif
#ifdef ELF_IS_32_
	{"clock_getres", INT, S_INT S_STRUC},
#else
	{"renameat", INT, S_INT S_STR S_INT S_STR},
#endif
#ifdef ELF_IS_32_
	{"clock_nanosleep", INT, S_INT S_INT S_STRUC S_STRUC},
#else
	{"linkat", INT, S_INT S_STR S_INT S_STR S_INT},
#endif
#ifdef ELF_IS_32_
	{"statfs64", INT, S_STR S_ADDR},
#else
	{"symlinkat", INT, S_STR S_INT S_STR},
#endif
#ifdef ELF_IS_32_
	{"fstatfs64", INT, S_INT S_ADDR},
#else
	{"readlinkat", INT, S_INT S_STR S_STR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"tgkill", INT, S_INT S_INT S_INT},
#else
	{"fchmodat", INT, S_INT S_STR S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"utimes", INT, S_STR S_STRUC},
#else
	{"faccessat", INT, S_INT S_STR S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"fadvise64_64", INT, S_INT S_INT S_INT S_INT},
#else
	{"pselect6", INT, S_INT S_ADDR S_ADDR S_ADDR S_STRUC S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"vserver", UNKN, ""},
#else
	{"ppoll", INT, S_STRUC S_INT S_STRUC S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"mbind", LONG, S_ADDR S_USI_L S_INT S_ADDR S_USI_L S_SIZE_T},
#else
	{"unshare", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"get_mempolicy", INT, S_ADDR S_ADDR S_USI_L S_USI_L S_USI_L},
#else
	{"set_robust_list", LONG, S_STRUC S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"set_mempolicy", LONG, S_INT S_ADDR S_USI_L},
#else
	{"get_robust_list", LONG, S_INT S_ADDR S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"mq_open", INT, S_STR S_INT},
#else
	{"splice", INT, S_INT S_ADDR S_INT S_ADDR S_SIZE_T S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"mq_unlink", INT, S_STR},
#else
	{"tee", INT, S_INT S_INT S_SIZE_T S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"mq_timedsend", INT, S_INT S_STR S_SIZE_T S_SIZE_T},
#else
	{"sync_file_range", INT, S_INT S_SIZE_T S_SIZE_T S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"mq_timedreceive", INT, S_INT S_STR S_SIZE_T S_ADDR S_STRUC},
#else
	{"vmsplice", INT, S_INT S_STRUC S_USI_L S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"mq_notify", INT, S_INT S_STRUC},
#else
	{"move_pages", LONG, S_INT S_LONG S_ADDR S_ADDR S_ADDR S_INT},
#endif
#ifdef ELF_IS_32_
	{"mq_getsetattr", INT, S_INT S_STRUC S_STRUC},
#else
	{"utimensat", INT, S_INT S_STR S_STRUC S_INT},
#endif
#ifdef ELF_IS_32_
	{"kexec_load", LONG, S_USI_L S_USI_L S_STRUC S_USI_L},
#else
	{"epoll_pwait", INT, S_INT S_STRUC S_INT S_INT S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"waitid", INT, S_INT S_ADDR S_INT},
#else
	{"signalfd", INT, S_INT S_ADDR S_INT},
#endif
#ifdef ELF_IS_32_
	{"add_key", INT, S_STR S_STR S_ADDR S_SIZE_T S_INT},
#else
	{"timerfd_create", INT, S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"request_key", INT, S_STR S_STR S_STR S_INT},
#else
	{"eventfd", INT, S_SIZE_T S_INT},
#endif
#ifdef ELF_IS_32_
	{"keyctl", LONG, S_INT S_UNKN},
#else
	{"fallocate", INT, S_INT S_INT S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"ioprio_set", INT, S_INT S_INT S_INT},
#else
	{"timerfd_settime", INT, S_INT S_INT S_STRUC S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"ioprio_get", INT, S_INT S_INT},
#else
	{"timerfd_gettime", INT, S_INT S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"inotify_init", INT, ""},
#else
	{"accept4", INT, S_INT S_STRUC S_ADDR S_INT},
#endif
#ifdef ELF_IS_32_
	{"inotify_add_watch", INT, S_INT S_STR S_INT},
#else
	{"signalfd4", INT, S_INT S_ADDR S_INT},
#endif
#ifdef ELF_IS_32_
	{"inotify_rm_watch", INT, S_INT S_INT},
#else
	{"eventfd2", INT, S_SIZE_T S_INT},
#endif
#ifdef ELF_IS_32_
	{"migrate_pages", LONG, S_INT S_USI_L S_ADDR S_ADDR},
#else
	{"epoll_create1", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"openat", INT, S_INT S_STR S_INT},
#else
	{"dup3", INT, S_INT S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"mkdirat", INT, S_INT S_STR S_INT},
#else
	{"pipe2", INT, S_INT_2 S_INT},
#endif
#ifdef ELF_IS_32_
	{"mknodat", INT, S_INT S_STR S_INT S_INT},
#else
	{"inotify_init1", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"fchownat", INT, S_INT S_STR S_INT S_INT S_INT},
#else
	{"preadv", INT, S_INT S_STRUC S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"futimesat", INT, S_INT S_STR S_STRUC},
#else
	{"pwritev", INT, S_INT S_STRUC S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"fstatat64", INT, S_INT S_ADDR},
#else
	{"rt_tgsigqueueinfo", INT, S_INT S_INT S_INT S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"unlinkat", INT, S_INT S_STR S_INT},
#else
	{"perf_event_open", INT, S_STRUC S_INT S_INT S_INT S_USI_L},
#endif
#ifdef ELF_IS_32_
	{"renameat", INT, S_INT S_STR S_INT S_STR},
#else
	{"recvmmsg", INT, S_INT S_STRUC S_INT},
#endif
#ifdef ELF_IS_32_
	{"linkat", INT, S_INT S_STR S_INT S_STR S_INT},
#else
	{"fanotify_init", INT, S_SIZE_T S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"symlinkat", INT, S_STR S_INT S_STR},
#else
	{"fanotify_mark", INT, S_INT S_SIZE_T S_SIZE_T S_INT S_STR},
#endif
#ifdef ELF_IS_32_
	{"readlinkat", INT, S_INT S_STR S_STR S_SIZE_T},
#else
	{"prlimit64", INT, S_INT S_INT S_STRUC S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"fchmodat", INT, S_INT S_STR S_INT S_INT},
#else
	{"name_to_handle_at", INT, S_INT S_STR S_STRUC S_ADDR S_INT},
#endif
#ifdef ELF_IS_32_
	{"faccessat", INT, S_INT S_STR S_INT S_INT},
#else
	{"open_by_handle_at", INT, S_INT S_STRUC S_INT},
#endif
#ifdef ELF_IS_32_
	{"pselect6", INT, S_INT S_ADDR S_ADDR S_ADDR S_STRUC S_ADDR},
#else
	{"clock_adjtime", UNKN, ""},
#endif
#ifdef ELF_IS_32_
	{"ppoll", INT, S_STRUC S_INT S_STRUC S_ADDR},
#else
	{"syncfs", INT, S_INT},
#endif
#ifdef ELF_IS_32_
	{"unshare", INT, S_INT},
#else
	{"sendmmsg", INT, S_INT S_STRUC S_INT},
#endif
#ifdef ELF_IS_32_
	{"set_robust_list", LONG, S_STRUC S_SIZE_T},
#else
	{"setns", INT, S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"get_robust_list", LONG, S_INT S_ADDR S_ADDR},
#else
	{"getcpu", INT, S_ADDR S_ADDR S_STRUC},
#endif
#ifdef ELF_IS_32_
	{"splice", INT, S_INT S_ADDR S_INT S_ADDR S_SIZE_T S_SIZE_T},
#else
	{"process_vm_readv", INT, S_INT S_STRUC S_USI_L S_STRUC S_USI_L S_USI_L},
#endif
#ifdef ELF_IS_32_
	{"sync_file_range", INT, S_INT S_SIZE_T S_SIZE_T S_SIZE_T},
#else
	{"process_vm_writev", INT, S_INT S_STRUC S_USI_L S_STRUC S_USI_L S_USI_L},
#endif
#ifdef ELF_IS_32_
	{"tee", INT, S_INT S_INT S_SIZE_T S_SIZE_T},
#else
	{"kcmp", INT, S_INT S_INT S_INT S_USI_L S_USI_L},
#endif
#ifdef ELF_IS_32_
	{"vmsplice", INT, S_INT S_STRUC S_USI_L S_SIZE_T},
#else
	{"finit_module", INT, S_INT S_STR S_INT},
#endif
#ifdef ELF_IS_32_
	{"move_pages", LONG, S_INT S_LONG S_ADDR S_ADDR S_ADDR S_INT},
#else
	{"sched_setattr", INT, S_INT S_STRUC S_USI_L},
#endif
#ifdef ELF_IS_32_
	{"getcpu", INT, S_ADDR S_ADDR S_STRUC},
#else
	{"sched_getattr", INT, S_INT S_STRUC S_USI_L S_USI_L},
#endif
#ifdef ELF_IS_32_
	{"epoll_pwait", INT, S_INT S_STRUC S_INT S_INT S_ADDR},
#else
	{"renameat2", INT, S_INT S_STR S_INT S_STR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"utimensat", INT, S_INT S_STR S_STRUC S_INT},
#else
	{"seccomp", INT, S_SIZE_T S_SIZE_T S_ADDR},
#endif
#ifdef ELF_IS_32_
	{"signalfd", INT, S_INT S_ADDR S_INT},
#else
	{"getrandom", INT, S_ADDR S_SIZE_T S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"timerfd_create", INT, S_INT S_INT},
#else
	{"memfd_create", INT, S_STR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"eventfd", INT, S_SIZE_T S_INT},
#else
	{"kexec_file_load", LONG, S_INT S_INT S_SIZE_T S_STR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"fallocate", INT, S_INT S_INT S_INT S_INT},
#else
	{"bpf", INT, S_INT S_ADDR S_SIZE_T},
#endif
#ifdef ELF_IS_32_
	{"timerfd_settime", INT, S_INT S_INT S_STRUC S_STRUC},
#else
	{"execveat", INT, S_INT S_STR S_STRSTR S_STRSTR S_INT},
#endif
#ifdef ELF_IS_32_
	{"timerfd_gettime", INT, S_INT S_STRUC},
#else
	{"userfaultfd", UNKN, ""},
#endif
#ifdef ELF_IS_32_
	{"signalfd4", INT, S_INT S_ADDR S_INT},
#else
	{"membarrier", INT, S_INT S_INT},
#endif
#ifdef ELF_IS_32_
	{"eventfd2", INT, S_SIZE_T S_INT},
#else
	{"mlock2", INT, S_STR S_SIZE_T S_INT},
#endif
#ifdef ELF_IS_32_
	{"epoll_create1", INT, S_INT},
#else
	{"", UNKN, S_UNKN}
	};
#endif
#ifdef ELF_IS_32_
	{"dup3", INT, S_INT S_INT S_INT},
	{"pipe2", INT, S_INT_2 S_INT},
	{"inotify_init1", INT, S_INT},
	{"preadv", INT, S_INT S_STRUC S_INT S_INT},
	{"pwritev", INT, S_INT S_STRUC S_INT S_INT},
	{"rt_tgsigqueueinfo", INT, S_INT S_INT S_INT S_ADDR},
	{"perf_event_open", INT, S_STRUC S_INT S_INT S_INT S_USI_L},
	{"recvmmsg", INT, S_INT S_STRUC S_INT},
	{"fanotify_init", INT, S_SIZE_T S_SIZE_T},
	{"fanotify_mark", INT, S_INT S_SIZE_T S_SIZE_T S_INT S_STR},
	{"prlimit64", INT, S_INT S_INT S_STRUC S_STRUC},
	{"name_to_handle_at", INT, S_INT S_STR S_STRUC S_ADDR S_INT},
	{"open_by_handle_at", INT, S_INT S_STRUC S_INT},
	{"clock_adjtime", UNKN, ""},
	{"syncfs", INT, S_INT},
	{"sendmmsg", INT, S_INT S_STRUC S_INT},
	{"setns", INT, S_INT S_INT},
	{"process_vm_readv", INT, S_INT S_STRUC S_USI_L S_STRUC S_USI_L S_USI_L},
	{"process_vm_writev", INT, S_INT S_STRUC S_USI_L S_STRUC S_USI_L S_USI_L},
	{"kcmp", INT, S_INT S_INT S_INT S_USI_L S_USI_L},
	{"finit_module", INT, S_INT S_STR S_INT},
	{"sched_setattr", INT, S_INT S_STRUC S_USI_L},
	{"sched_getattr", INT, S_INT S_STRUC S_USI_L S_USI_L},
	{"renameat2", INT, S_INT S_STR S_INT S_STR S_SIZE_T},
	{"seccomp", INT, S_SIZE_T S_SIZE_T S_ADDR},
	{"getrandom", INT, S_ADDR S_SIZE_T S_SIZE_T},
	{"memfd_create", INT, S_STR S_SIZE_T},
	{"bpf", INT, S_INT S_ADDR S_SIZE_T},
	{"execveat", INT, S_INT S_STR S_STRSTR S_STRSTR S_INT},
	{"socket", INT, S_INT S_INT S_INT},
	{"socketpair", INT, S_INT S_INT S_INT S_INT_2},
	{"bind", INT, S_INT S_STRUC S_INT},
	{"connect", INT, S_INT S_STRUC S_INT},
	{"listen", INT, S_INT S_INT},
	{"accept4", INT, S_INT S_STRUC S_ADDR S_INT},
	{"getsockopt", INT, S_INT S_INT S_INT S_ADDR S_INT},
	{"setsockopt", INT, S_INT S_INT S_INT S_ADDR S_INT},
	{"getsockname", INT, S_INT S_STRUC S_INT},
	{"getpeername", INT, S_INT S_STRUC S_INT},
	{"sendto", INT, S_INT S_ADDR S_SIZE_T S_INT S_STRUC S_INT},
	{"sendmsg", INT, S_INT S_STRUC S_INT},
	{"recvfrom", INT, S_INT S_ADDR S_SIZE_T S_INT S_STRUC S_ADDR},
	{"recvmsg", INT, S_INT S_STRUC S_INT},
	{"shutdown", INT, S_INT S_INT},
	{"userfaultfd", UNKN, ""},
	{"membarrier", INT, S_INT S_INT},
	{"mlock2", INT, S_STR S_SIZE_T S_INT},
	  {""}
	};
#endif

#endif /* !SYSCALLS_H_*/
