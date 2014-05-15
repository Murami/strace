	{ 3,	, "read"		},
	{ 3,	, "write"		},
	{ 3,	, "open"		},
	{ 1,	, "close"		},
	{ 2,	, "stat"		},
	{ 2,	, "fstat"		},
	{ 2,	, "lstat"		},
	{ 3,	, "poll"		},
	{ 3,	, "lseek"		},
	{ 6,	, "mmap"		},
	{ 3,	, "mprotect"		},
	{ 2,	, "munmap"		},
	{ 1,	, "brk"			},
	{ 4,	, "rt_sigaction"	},
	{ 4,	, "rt_sigprocmask"	},
	{ 0,	, "rt_sigreturn"	},
	{ 3,	, "ioctl"		},
	{ 4,	, "pread"		},
	{ 4,	, "pwrite"		},
	{ 3,	, "readv"		},
	{ 3,	, "writev"		},
	{ 2,	, "access"		},
	{ 1,	, "pipe"		},
	{ 5,	, "select"		},
	{ 0,	, "sched_yield"		},
	{ 5,	, "mremap"		},
	{ 3,	, "msync"		},
	{ 3,	, "mincore"		},
	{ 3,	, "madvise"		},
	{ 4,	, "shmget"		},
	{ 4,	, "shmat"		},
	{ 4,	, "shmctl"		},
	{ 1,	, "dup"			},
	{ 2,	, "dup2"		},
	{ 0,	, "pause"		},
	{ 2,	, "nanosleep"		},
	{ 2,	, "getitimer"		},
	{ 1,	, "alarm"		},
	{ 3,	, "setitimer"		},
	{ 0,	, "getpid"		},
	{ 4,	, "sendfile"		},
	{ 3,	, "socket"		},
	{ 3,	, "connect"		},
	{ 3,	, "accept"		},
	{ 6,	, "sendto"		},
	{ 6,	, "recvfrom"		},
	{ 3,	, "sendmsg"		},
	{ 3,	, "recvmsg"		},
	{ 2,	, "shutdown"		},
	{ 3,	, "bind"		},
	{ 2,	, "listen"		},
	{ 3,	, "getsockname"		},
	{ 3,	, "getpeername"		},
	{ 4,	, "socketpair"		},
	{ 5,	, "setsockopt"		},
	{ 5,	, "getsockopt"		},
	{ 5,	, "clone"		},
	{ 0,	, "fork"		},
	{ 0,	, "vfork"		},
	{ 3,	, "execve"		},
	{ 1,	, "_exit"		},
	{ 4,	, "wait4"		},
	{ 2,	, "kill"		},
	{ 1,	, "uname"		},
	{ 4,	, "semget"		},
	{ 4,	, "semop"		},
	{ 4,	, "semctl"		},
	{ 4,	, "shmdt"		},
	{ 4,	, "msgget"		},
	{ 4,	, "msgsnd"		},
	{ 5,	, "msgrcv"		},
	{ 3,	, "msgctl"		},
	{ 3,	, "fcntl"		},
	{ 2,	, "flock"		},
	{ 1,	, "fsync"		},
	{ 1,	, "fdatasync"		},
	{ 2,	, "truncate"		},
	{ 2,	, "ftruncate"		},
	{ 3,	, "getdents"		},
	{ 2,	, "getcwd"		},
	{ 1,	, "chdir"		},
	{ 1,	, "fchdir"		},
	{ 2,	, "rename"		},
	{ 2,	, "mkdir"		},
	{ 1,	, "rmdir"		},
	{ 2,	, "creat"		},
	{ 2,	, "link"		},
	{ 1,	, "unlink"		},
	{ 2,	, "symlink"		},
	{ 3,	, "readlink"		},
	{ 2,	, "chmod"		},
	{ 2,	, "fchmod"		},
	{ 3,	, "chown"		},
	{ 3,	, "fchown"		},
	{ 3,	, "lchown"		},
	{ 1,	, "umask"		},
	{ 2,	, "gettimeofday"	},
	{ 2,	, "getrlimit"		},
	{ 2,	,		"getrusage"	},
	{ 1,	,		"sysinfo"	},
	{ 1,	,		"times"		},
	{ 4,	,		"ptrace"	},
	{ 0,	,		"getuid"	},
	{ 3,	,		"syslog"	},
	{ 0,	,		"getgid"	},
	{ 1,	,		"setuid"	},
	{ 1,	,		"setgid"	},
	{ 0,	,		"geteuid"	},
	{ 0,	,		"getegid"	},
	{ 2,	,		"setpgid"	},
	{ 0,	,		"getppid"	},
	{ 0,	,		"getpgrp"	},
	{ 0,	,		"setsid"	},
	{ 2,	,		"setreuid"	},
	{ 2,	,		"setregid"	},
	{ 2,	,		"getgroups"	},
	{ 2,	,		"setgroups"	},
	{ 3,	,		"setresuid"	},
	{ 3,	,		"getresuid"	},
	{ 3,	,		"setresgid"	},
	{ 3,	,		"getresgid"	},
	{ 1,	,		"getpgid"	},
	{ 1,	,		"setfsuid"	},
	{ 1,	,		"setfsgid"	},
	{ 1,	,		"getsid"	},
	{ 2,	,		"capget"	},
	{ 2,	,		"capset"	},
	{ 2,	,	"rt_sigpending"	},
	{ 4,	,	"rt_sigtimedwait"	},
	{ 3,	,    "rt_sigqueueinfo"	},
	{ 2,	,	"rt_sigsuspend"	},
	{ 2,	,	"sigaltstack"	},
	{ 2,	,		"utime"		},
	{ 3,	,		"mknod"		},
	{ 1,	,		"uselib"	},
	{ 1,	,	"personality"	},
	{ 2,	0,	sys_ustat,		"ustat"		},
	{ 2,	TF,	sys_statfs,		"statfs"	},
	{ 2,	TD,	sys_fstatfs,		"fstatfs"	},
	{ 3,	0,	sys_sysfs,		"sysfs"		},
	{ 2,	0,	sys_getpriority,	"getpriority"	},
	{ 3,	0,	sys_setpriority,	"setpriority"	},
	{ 0,	0,	sys_sched_setparam,	"sched_setparam"	},
	{ 2,	0,	sys_sched_getparam,	"sched_getparam"	},
	{ 3,	0,	sys_sched_setscheduler,	"sched_setscheduler"	},
	{ 1,	0,	sys_sched_getscheduler,	"sched_getscheduler"	},
	{ 1,	0,	sys_sched_get_priority_max,	"sched_get_priority_max"	},
	{ 1,	0,	sys_sched_get_priority_min,	"sched_get_priority_min"	},
	{ 2,	0,	sys_sched_rr_get_interval,	"sched_rr_get_interval"	},
	{ 2,	TM,	sys_mlock,		"mlock"		},
	{ 2,	TM,	sys_munlock,		"munlock"	},
	{ 1,	TM,	sys_mlockall,		"mlockall"	},
	{ 0,	TM,	sys_munlockall,		"munlockall"	},
	{ 0,	0,	sys_vhangup,		"vhangup"	},
	{ 3,	0,	sys_modify_ldt,		"modify_ldt"	},
	{ 2,	TF,	sys_pivotroot,		"pivot_root"	},
	{ 1,	0,	sys_sysctl,		"_sysctl"	},
	{ 5,	0,	sys_prctl,		"prctl"		},
	{ 2,	TP,	sys_arch_prctl,		"arch_prctl"	},
	{ 1,	0,	sys_adjtimex,		"adjtimex"	},
	{ 2,	0,	sys_setrlimit,		"setrlimit"	},
	{ 1,	TF,	sys_chroot,		"chroot"	},  /* 161 */
	{ 0,	0,	sys_sync,		"sync"		},  /* 162 */
	{ 1,	TF,	sys_acct,		"acct"		},  /* 163 */
	{ 2,	0,	sys_settimeofday,	"settimeofday"	},  /* 164 */
	{ 5,	TF,	sys_mount,		"mount"		},  /* 165 */
	{ 2,	TF,	sys_umount2,		"umount"	}, /* 166 */
	{ 2,	TF,	sys_swapon,		"swapon"	},  /* 167 */
	{ 1,	TF,	sys_swapoff,		"swapoff"	},  /* 168 */
	{ 4,	0,	sys_reboot,		"reboot"	},  /* 169 */
	{ 2,	0,	sys_sethostname,	"sethostname"	},  /* 170 */
	{ 2,	0,	sys_setdomainname,	"setdomainname"	},  /* 171 */
	{ 1,	0,	sys_iopl,		"iopl"		},  /* 172 */
	{ 3,	0,	sys_ioperm,		"ioperm"	},  /* 173 */
	{ 2,	0,	sys_create_module,	"create_module"	},  /* 174 */
	{ 3,	0,	sys_init_module,	"init_module"	},  /* 175 */
	{ 2,	0,	sys_delete_module,	"delete_module"	},  /* 176 */
	{ 1,	0,	sys_get_kernel_syms,	"get_kernel_syms"},  /* 177 */
	{ 5,	0,	sys_query_module,	"query_module"	},  /* 178 */
	{ 4,	TF,	sys_quotactl,		"quotactl"	},  /* 179 */
	{ 3,	0,	sys_nfsservctl,		"nfsservctl"	},  /* 180 */
	{ 5,	0,	sys_getpmsg,		"getpmsg"	}, /* 181 */
	{ 5,	0,	sys_putpmsg,		"putpmsg"	}, /* 182 */
	{ 5,	0,	sys_afs_syscall,	"afs_syscall"	},  /* 183 */
	{ 3,	0,	sys_tuxcall,		"tuxcall"	}, /* 184 */
	{ 3,	0,	sys_security,		"security"	}, /* 185 */
	{ 0,	0,	sys_gettid,		"gettid"	}, /* 186 */
	{ 3,	TD,	sys_readahead,		"readahead"	}, /* 187 */
	{ 5,	TF,	sys_setxattr,		"setxattr"	}, /* 188 */
	{ 5,	TF,	sys_setxattr,		"lsetxattr"	}, /* 189 */
	{ 5,	TD,	sys_fsetxattr,		"fsetxattr"	}, /* 190 */
	{ 4,	TF,	sys_getxattr,		"getxattr"	}, /* 191 */
	{ 4,	TF,	sys_getxattr,		"lgetxattr"	}, /* 192 */
	{ 4,	TD,	sys_fgetxattr,		"fgetxattr"	}, /* 193 */
	{ 3,	TF,	sys_listxattr,		"listxattr"	}, /* 194 */
	{ 3,	TF,	sys_listxattr,		"llistxattr"	}, /* 195 */
	{ 3,	TD,	sys_flistxattr,		"flistxattr"	}, /* 196 */
	{ 2,	TF,	sys_removexattr,	"removexattr"	}, /* 197 */
	{ 2,	TF,	sys_removexattr,	"lremovexattr"	}, /* 198 */
	{ 2,	TD,	sys_fremovexattr,	"fremovexattr"	}, /* 199 */
	{ 2,	TS,	sys_kill,		"tkill"		}, /* 200 */
	{ 1,	0,	sys_time,		"time"		},  /* 201 */
	{ 6,	0,	sys_futex,		"futex"		}, /* 202 */
	{ 3,	0,	sys_sched_setaffinity,	"sched_setaffinity" },/* 203 */
	{ 3,	0,	sys_sched_getaffinity,	"sched_getaffinity" },/* 204 */
	{ 1,	0,	sys_set_thread_area,	"set_thread_area" }, /* 205 */
	{ 2,	0,	sys_io_setup,		"io_setup"	}, /* 206 */
	{ 1,	0,	sys_io_destroy,		"io_destroy"	}, /* 207 */
	{ 5,	0,	sys_io_getevents,	"io_getevents"	}, /* 208 */
	{ 3,	0,	sys_io_submit,		"io_submit"	}, /* 209 */
	{ 3,	0,	sys_io_cancel,		"io_cancel"	}, /* 210 */
	{ 1,	0,	sys_get_thread_area,	"get_thread_area" }, /* 211 */
	{ 3,	0,	sys_lookup_dcookie,	"lookup_dcookie"}, /* 212 */
	{ 1,	TD,	sys_epoll_create,	"epoll_create"	}, /* 213 */
	{ 4,	0,	printargs,		"epoll_ctl_old"	}, /* 214 */
	{ 4,	0,	printargs,		"epoll_wait_old"}, /* 215 */
	{ 5,	TM,	sys_remap_file_pages,	"remap_file_pages"}, /* 216 */
	{ 3,	TD,	sys_getdents64,		"getdents64"	}, /* 217 */
	{ 1,	0,	sys_set_tid_address,	"set_tid_address"}, /* 218 */
	{ 0,	0,	sys_restart_syscall,	"restart_syscall"}, /* 219 */
	{ 5,	TI,	sys_semtimedop,		"semtimedop"	}, /* 220 */
	{ 4,	TD,	sys_fadvise64,		"fadvise64"	}, /* 221 */
	{ 3,	0,	sys_timer_create,	"timer_create"	}, /* 222 */
	{ 4,	0,	sys_timer_settime,	"timer_settime"	}, /* 223 */
	{ 2,	0,	sys_timer_gettime,	"timer_gettime"	}, /* 224 */
	{ 1,	0,	sys_timer_getoverrun,	"timer_getoverrun"}, /* 225 */
	{ 1,	0,	sys_timer_delete,	"timer_delete"	}, /* 226 */
	{ 2,	0,	sys_clock_settime,	"clock_settime"	}, /* 227 */
	{ 2,	0,	sys_clock_gettime,	"clock_gettime"	}, /* 228 */
	{ 2,	0,	sys_clock_getres,	"clock_getres"	}, /* 229 */
	{ 4,	0,	sys_clock_nanosleep,	"clock_nanosleep"}, /* 230 */
	{ 1,	TP,	sys_exit,		"exit_group"	}, /* 231 */
	{ 4,	TD,	sys_epoll_wait,		"epoll_wait"	}, /* 232 */
	{ 4,	TD,	sys_epoll_ctl,		"epoll_ctl"	}, /* 233 */
	{ 3,	TS,	sys_tgkill,		"tgkill"	}, /* 234 */
	{ 2,	TF,	sys_utimes,		"utimes"	}, /* 235 */
	{ 5,	0,	sys_vserver,		"vserver"	}, /* 236 */
	{ 6,	TM,	sys_mbind,		"mbind"		}, /* 237 */
	{ 3,	TM,	sys_set_mempolicy,	"set_mempolicy"	}, /* 238 */
	{ 5,	TM,	sys_get_mempolicy,	"get_mempolicy"	}, /* 239 */
	{ 4,	0,	sys_mq_open,		"mq_open"	}, /* 240 */
	{ 1,	0,	sys_mq_unlink,		"mq_unlink"	}, /* 241 */
	{ 5,	0,	sys_mq_timedsend,	"mq_timedsend"	}, /* 242 */
	{ 5,	0,	sys_mq_timedreceive,	"mq_timedreceive" }, /* 243 */
	{ 2,	0,	sys_mq_notify,		"mq_notify"	}, /* 244 */
	{ 3,	0,	sys_mq_getsetattr,	"mq_getsetattr"	}, /* 245 */
	{ 4,	0,	sys_kexec_load,		"kexec_load"	}, /* 246 */
	{ 5,	TP,	sys_waitid,		"waitid"	}, /* 247 */
	{ 5,	0,	sys_add_key,		"add_key"	}, /* 248 */
	{ 4,	0,	sys_request_key,	"request_key"	}, /* 249 */
	{ 5,	0,	sys_keyctl,		"keyctl"	}, /* 250 */
	{ 3,	0,	sys_ioprio_set,		"ioprio_set"	}, /* 251 */
	{ 2,	0,	sys_ioprio_get,		"ioprio_get"	}, /* 252 */
	{ 0,	TD,	sys_inotify_init,	"inotify_init"	}, /* 253 */
	{ 3,	TD,	sys_inotify_add_watch,	"inotify_add_watch" }, /* 254 */
	{ 2,	TD,	sys_inotify_rm_watch,	"inotify_rm_watch" }, /* 255 */
	{ 4,	TM,	sys_migrate_pages,	"migrate_pages"	}, /* 256 */
	{ 4,	TD|TF,	sys_openat,		"openat"	}, /* 257 */
	{ 3,	TD|TF,	sys_mkdirat,		"mkdirat"	}, /* 258 */
	{ 4,	TD|TF,	sys_mknodat,		"mknodat"	}, /* 259 */
	{ 5,	TD|TF,	sys_fchownat,		"fchownat"	}, /* 260 */
	{ 3,	TD|TF,	sys_futimesat,		"futimesat"	}, /* 261 */
	{ 4,	TD|TF,	sys_newfstatat,		"newfstatat"	}, /* 262 */
	{ 3,	TD|TF,	sys_unlinkat,		"unlinkat"	}, /* 263 */
	{ 4,	TD|TF,	sys_renameat,		"renameat"	}, /* 264 */
	{ 5,	TD|TF,	sys_linkat,		"linkat"	}, /* 265 */
	{ 3,	TD|TF,	sys_symlinkat,		"symlinkat"	}, /* 266 */
	{ 4,	TD|TF,	sys_readlinkat,		"readlinkat"	}, /* 267 */
	{ 3,	TD|TF,	sys_fchmodat,		"fchmodat"	}, /* 268 */
	{ 3,	TD|TF,	sys_faccessat,		"faccessat"	}, /* 269 */
	{ 6,	TD,	sys_pselect6,		"pselect6"	}, /* 270 */
	{ 5,	TD,	sys_ppoll,		"ppoll"		}, /* 271 */
	{ 1,	TP,	sys_unshare,		"unshare"	}, /* 272 */
	{ 2,	0,	sys_set_robust_list,	"set_robust_list" }, /* 273 */
	{ 3,	0,	sys_get_robust_list,	"get_robust_list" }, /* 274 */
	{ 6,	TD,	sys_splice,		"splice"	}, /* 275 */
	{ 4,	TD,	sys_tee,		"tee"		}, /* 276 */
	{ 4,	TD,	sys_sync_file_range,	"sync_file_range" }, /* 277 */
	{ 4,	TD,	sys_vmsplice,		"vmsplice"	}, /* 278 */
	{ 6,	TM,	sys_move_pages,		"move_pages"	}, /* 279 */
	{ 4,	TD|TF,	sys_utimensat,		"utimensat"	}, /* 280 */
	{ 6,	TD,	sys_epoll_pwait,	"epoll_pwait"	}, /* 281 */
	{ 3,	TD|TS,	sys_signalfd,		"signalfd"	}, /* 282 */
	{ 2,	TD,	sys_timerfd_create,	"timerfd_create"}, /* 283 */
	{ 1,	TD,	sys_eventfd,		"eventfd"	}, /* 284 */
	{ 4,	TD,	sys_fallocate,		"fallocate"	}, /* 285 */
	{ 4,	TD,	sys_timerfd_settime,	"timerfd_settime"}, /* 286 */
	{ 2,	TD,	sys_timerfd_gettime,	"timerfd_gettime"}, /* 287 */
	{ 4,	TN,	sys_accept4,		"accept4"	}, /* 288 */
	{ 4,	TD|TS,	sys_signalfd4,		"signalfd4"	}, /* 289 */
	{ 2,	TD,	sys_eventfd2,		"eventfd2"	}, /* 290 */
	{ 1,	TD,	sys_epoll_create1,	"epoll_create1"	}, /* 291 */
	{ 3,	TD,	sys_dup3,		"dup3"		}, /* 292 */
	{ 2,	TD,	sys_pipe2,		"pipe2"		}, /* 293 */
	{ 1,	TD,	sys_inotify_init1,	"inotify_init1"	}, /* 294 */
	{ 4,	TD,	sys_preadv,		"preadv"	}, /* 295 */
	{ 4,	TD,	sys_pwritev,		"pwritev"	}, /* 296 */
	{ 4,	TP|TS,	sys_rt_tgsigqueueinfo,	"rt_tgsigqueueinfo"}, /* 297 */
	{ 5,	TD,	sys_perf_event_open,	"perf_event_open"}, /* 298 */
	{ 5,	TN,	sys_recvmmsg,		"recvmmsg"	}, /* 299 */
	{ 2,	TD,	sys_fanotify_init,	"fanotify_init"	}, /* 300 */
	{ 5,	TD|TF,	sys_fanotify_mark,	"fanotify_mark"	}, /* 301 */
	{ 4,	0,	sys_prlimit64,		"prlimit64"	}, /* 302 */
	{ 5,	TD|TF,	sys_name_to_handle_at,	"name_to_handle_at"}, /* 303 */
	{ 3,	TD,	sys_open_by_handle_at,	"open_by_handle_at"}, /* 304 */
	{ 2,	0,	sys_clock_adjtime,	"clock_adjtime"	}, /* 305 */
	{ 1,	TD,	sys_syncfs,		"syncfs"	}, /* 306 */
	{ 4,	TN,	sys_sendmmsg,		"sendmmsg"	}, /* 307 */
	{ 2,	TD,	sys_setns,		"setns"		}, /* 308 */
	{ 3,	0,	sys_getcpu,		"getcpu"	}, /* 309 */
	{ 6,	0,	sys_process_vm_readv,	"process_vm_readv"	}, /* 310 */
	{ 6,	0,	sys_process_vm_writev,	"process_vm_writev"	}, /* 311 */
	{ 5,	0,	sys_kcmp,		"kcmp"		}, /* 312 */
	{ 3,	TD,	sys_finit_module,	"finit_module"	}, /* 313 */
