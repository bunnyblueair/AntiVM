#include "antivm.h"

__BEGIN_DECLS



// int faccessat(int dirfd, const char *pathname, int mode, int flags);
LIBC_PROTECT(int, faccessat, int dirfd, const char *pathname, int mode, int flags) {

    int ret = syscall(__NR_faccessat, dirfd, pathname, mode, flags);
    return ret;
}


// int fchmodat(int dirfd, const char *pathname, mode_t mode, int flags);
LIBC_PROTECT(int, fchmodat, int dirfd, const char *pathname, mode_t mode, int flags) {

    int ret = syscall(__NR_fchmodat, dirfd, pathname, mode, flags);
    return ret;
}
// int fchmod(const char *pathname, mode_t mode);
LIBC_PROTECT(int, fchmod, const char *pathname, mode_t mode) {

    int ret = syscall(__NR_chmod, pathname, mode);

    return ret;
}


// int fstatat(int dirfd, const char *pathname, struct stat *buf, int flags);
LIBC_PROTECT(int, fstatat, int dirfd, const char *pathname, struct stat *buf, int flags) {

    int ret = syscall(__NR_fstatat64, dirfd, pathname, buf, flags);

    return ret;
}
// int fstat(const char *pathname, struct stat *buf, int flags);
LIBC_PROTECT(int, fstat, const char *pathname, struct stat *buf) {

    int ret = syscall(__NR_fstat64, pathname, buf);

    return ret;
}


// int mknodat(int dirfd, const char *pathname, mode_t mode, dev_t dev);
LIBC_PROTECT(int, mknodat, int dirfd, const char *pathname, mode_t mode, dev_t dev) {

    int ret = syscall(__NR_mknodat, dirfd, pathname, mode, dev);
    return ret;
}
// int mknod(const char *pathname, mode_t mode, dev_t dev);
LIBC_PROTECT(int, mknod, const char *pathname, mode_t mode, dev_t dev) {

    int ret = syscall(__NR_mknod, pathname, mode, dev);
    return ret;
}


// int utimensat(int dirfd, const char *pathname, const struct timespec times[2], int flags);
LIBC_PROTECT(int, utimensat, int dirfd, const char *pathname, const struct timespec times[2],
             int flags) {
    int ret = syscall(__NR_utimensat, dirfd, pathname, times, flags);
    return ret;
}


// int fchownat(int dirfd, const char *pathname, uid_t owner, gid_t group, int flags);
LIBC_PROTECT(int, fchownat, int dirfd, const char *pathname, uid_t owner, gid_t group, int flags) {


    int ret = syscall(__NR_fchownat, dirfd, pathname, owner, group, flags);
    return ret;
}

// int chroot(const char *pathname);
LIBC_PROTECT(int, chroot, const char *pathname) {

    int ret = syscall(__NR_chroot, pathname);

    return ret;
}


// int renameat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath);
LIBC_PROTECT(int, renameat, int olddirfd, const char *oldpath, int newdirfd, const char *newpath) {

    int ret = syscall(__NR_renameat, olddirfd, oldpath, newdirfd, newpath);

    return ret;
}
// int rename(const char *oldpath, const char *newpath);
LIBC_PROTECT(int, rename, const char *oldpath, const char *newpath) {

    int ret = syscall(__NR_rename, oldpath, newpath);

    return ret;
}


// int unlinkat(int dirfd, const char *pathname, int flags);
LIBC_PROTECT(int, unlinkat, int dirfd, const char *pathname, int flags) {

    int ret = syscall(__NR_unlinkat, dirfd, pathname, flags);

    return ret;
}
// int unlink(const char *pathname);
int unlink(const char *pathname) {
#ifdef VMDEBUG
    LOGE("call systemunlink  %d ", pathname);
#endif
    int ret = syscall(__NR_unlink, pathname);

    return ret;
}


int symlinkat(const char *oldpath, int newdirfd, const char *newpath) {

    int ret = syscall(__NR_symlinkat, oldpath, newdirfd, newpath);

    return ret;
}
// int symlink(const char *oldpath, const char *newpath);
int symlink(const char *oldpath, const char *newpath) {

    int ret = syscall(__NR_symlink, oldpath, newpath);

    return ret;
}


// int linkat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath, int flags);
int linkat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath, int flags) {

    int ret = syscall(__NR_linkat, olddirfd, oldpath, newdirfd, newpath, flags);

    return ret;
}
// int link(const char *oldpath, const char *newpath);
int link(const char *oldpath, const char *newpath) {

    int ret = syscall(__NR_link, oldpath, newpath);

    return ret;
}


// int utimes(const char *filename, const struct timeval *tvp);
int utimes(const char *filename, const struct timeval *tvp) {

    int ret = syscall(__NR_utimes, filename, tvp);

    return ret;
}


// int access(const char *pathname, int mode);
int access(const char *pathname, int mode) {

    int ret = syscall(__NR_access, pathname, mode);

    return ret;
}


// int chmod(const char *path, mode_t mode);
int chmod(const char *path, mode_t mode) {

    int ret = syscall(__NR_chmod, path, mode);

    return ret;
}


// int chown(const char *path, uid_t owner, gid_t group);
int chown(const char *path, uid_t owner, gid_t group) {

    int ret = syscall(__NR_chown, path, owner, group);
    return ret;
}


// int lstat(const char *path, struct stat *buf);
int lstat(const char *path, struct stat *buf) {

    int ret = syscall(__NR_lstat64, path, buf);

    return ret;
}


// int stat(const char *path, struct stat *buf);
int stat(const char *path, struct stat *buf) {

    int ret = syscall(__NR_stat64, path, buf);
    return ret;
}


// int mkdirat(int dirfd, const char *pathname, mode_t mode);
int mkdirat(int dirfd, const char *pathname, mode_t mode) {

    int ret = syscall(__NR_mkdirat, dirfd, pathname, mode);

    return ret;
}
// int mkdir(const char *pathname, mode_t mode);
int mkdir(const char *pathname, mode_t mode) {

    int ret = syscall(__NR_mkdir, pathname, mode);

    return ret;
}


// int rmdir(const char *pathname);
int rmdir(const char *pathname) {

    int ret = syscall(__NR_rmdir, pathname);

    return ret;
}


// int readlinkat(int dirfd, const char *pathname, char *buf, size_t bufsiz);
int readlinkat(int dirfd, const char *pathname, char *buf, size_t bufsiz) {

    int ret = syscall(__NR_readlinkat, dirfd, pathname, buf, bufsiz);

    return ret;
}
// ssize_t readlink(const char *path, char *buf, size_t bufsiz);
ssize_t readlink(const char *pathname, char *buf, size_t bufsiz) {

    ssize_t ret = static_cast<ssize_t>(syscall(__NR_readlink, pathname, buf, bufsiz));

    return ret;
}


// int __statfs64(const char *path, size_t size, struct statfs *stat);
int __statfs64(const char *pathname, size_t size, struct statfs *stat) {

    int ret = syscall(__NR_statfs64, pathname, size, stat);

    return ret;
}


// int truncate(const char *path, off_t length);
int truncate(const char *pathname, off_t length) {

    int ret = syscall(__NR_truncate, pathname, length);

    return ret;
}

// int truncate64(const char *pathname, off_t length);
int truncate64(const char *pathname, off_t length) {

    int ret = syscall(__NR_truncate64, pathname, length);

    return ret;
}


// int chdir(const char *path);
int chdir(const char *pathname) {

    int ret = syscall(__NR_chdir, pathname);

    return ret;
}


// int __getcwd(char *buf, size_t size);
int __getcwd(char *buf, size_t size) {
    int ret = syscall(__NR_getcwd, buf, size);
    return ret;
}


// int __openat(int fd, const char *pathname, int flags, int mode);
int __openat(int fd, const char *pathname, int flags, int mode) {

    int ret = syscall(__NR_openat, fd, pathname, flags, mode);

    return ret;
}
// int __open(const char *pathname, int flags, int mode);
int __open(const char *pathname, int flags, int mode) {
    int ret = syscall(__NR_open, pathname, flags, mode);

    return ret;
}

// int lchown(const char *pathname, uid_t owner, gid_t group);
int lchown(const char *pathname, uid_t owner, gid_t group) {

    int ret = syscall(__NR_lchown, pathname, owner, group);

    return ret;
}


int kill(pid_t pid, int sig) {
    int ret = syscall(__NR_kill, pid, sig);
    return ret;
}

__END_DECLS
