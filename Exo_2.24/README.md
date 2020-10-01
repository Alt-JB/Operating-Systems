
EXERCICE 2.24
------------------------------------------------------------------------------
Program  : Copier le contenu d'un fichier dans un autre fichier
FileName : OS2.py
Input 1  : test
Input 2  : testCopy
Output 	 : 'The file test is copied in testCopy'
By       : ALTIDOR Jean Bernard T., DUBUCHE Kevin J., THEODORE Barbara G.  
-----------------------------------------------------------------------------

**C code

To compile
gcc OS1.c -o OS1

To save output of strace 
strace ./OS1 &>strace_output_C
------------------------------
**Python code

To compile
chmod +x OS2.py

To save output of strace 
strace ./OS2 &>strace_output_python
-----------------------------------


EXPLICATIONS
-------------
Liste des appels systemes dans "Strace_output_C" selon l'ordre d'occurence :

-Line 1: execve("./copy.o", ["./copy.o"], [/* 28 vars */]) = 0
	int execve(const char *filename, char *const argv[], char *const envp[] );
	Execute le programme sur lequel pointe "filename".

-Line 2: brk(0) = 0x676000
	int brk(void *addr);
	Change la position du "program break",alloue de la memoire au processus.
	
-Line 3: access(/etc/ld.so.nohwcap", F_OK) = -1 ENOENT (No such file or directory)
	int access(const char *pathname, int mode);
	Verifie si l'utilisateur a les permissions requises sur le fichier.
	
-Line 4: mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE| MAP_ANONYMOUS, -1, 0) = 0x7f16f3652000
    	void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
    	Etablie une relation entre l'espace d'adressage virtuel du processus appelant et le fichier.
    	
- Line 6: open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 4
	open(const char *pathname, int flags) = 4
	Ouvre le fichier specifie par "pathname".
	
-Line 7: fstat(4, {st_mode=S_IFREG|0644, st_size=48760, ...}) = 0
	int fstat(int fd, struct stat *buf);
	Retourne le status du fichier.
	
-Line 9: close(4)
	int close(int fd);
	Ferme le descripteur (fd: File Descriptor) pour qu'il ne referencie plus le fichier.
	
-Line 15: mprotect(0x7f16f3228000, 2093056, PROT_NONE) = 0
	int mprotect(void *addr, size_t len, int prot);
	Change la protection de partie de la mémoire [addr,addr+len-1].
	
-Line 21: arch_prctl(ARCH_SET_FS, 0x7f16f3643740)
	int arch_prctl(int code, unsigned long addr);
	Défini l’état spécifique à l’architecture pour le thread ou le processus.
	
-Line 25: munmap(0x7f16f36546000, 48760)
	int munmap(void *addr, size_t length);
	Établie/supprime une projection en mémoire (map/unmap) des fichiers ou des périphériques.
	
-Line 30: write(1, "Enter name of source file: ", 27) = 27
	ssize_t write(int fd, const void *buf, size_t count);
	Écrit dans le descripteur de fichier.
	
-Line 31: read(0, "makefile\n", 1024) = 9
	ssize_t read(int fd, void *buf, size_t count);
	Lit le descripteur de fichier.
	
- Line 53: exit_group(0)
	void exit_group(int status);
	Ferme le processus appelant.
	

	