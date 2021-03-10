/ include library standar untuk i/o sehingga dapat melakukan print
// include library agar dapat memanggil syscall
// include library agar dapat menggunakan string
#include  <stdlib.h>

void  parse(char *line, char **argv)
{
     while (*line != '\0') {       
          while (*line == ' ' || *line == '\t' || *line == '\n')
               *line++ = '\0';     
          *argv++ = line;          
          while (*line != '\0' && *line != ' ' && 
                 *line != '\t' && *line != '\n') 
               line++;             
     }
     *argv = '\0';                 
}

void  execute(char **argv)
{
	 // buat variabel bernama pid dengan tipe pid_t
	 // buat variabel status bertipe integer


     if ((pid = fork()) < 0) {     
		  // print ke terminal "*** ERROR: gagal melalukan forking"
          // keluar program dengan kode 1 (kode 1 artinya program keluar dengan kegagalan)
     }
     else if (pid == 0) {          
          if (execvp(*argv, argv) < 0) {     
			   // print ke terminal "*** ERROR: exec gagal"
               // keluar program dengan kode 1 (kode 1 artinya program keluar dengan kegagalan)
          }
     }
     else {                                  
          while (wait(&status) != pid)       
               ;
     }
}

void  main(void)
{
     char  line[1024];             
     char  *argv[64];              

     while (1) {                   
		  // print ke terminal "Shell ->"     
          gets(line);              
          printf("\n");
          // panggil prosedur/fungsi parse 
          if (strcmp(argv[0], "exit") == 0)  
               exit(0);            
 		  // panggil prosedur/fungsi execute           
     }}
