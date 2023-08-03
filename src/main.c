#include <getopt.h>
#include "main.h"
//#include "io/io.h"
//#include "matrix/matrix.h"

/*  TITLE:          Main
    DESCRIPTION:    Handles calls to compiled .o file
    PREREQS:        Compile via gcc as main.out
    EXAMPLE:        ./main.out -o "test.txt"
    FLAGS
*/
int main(int argc, char* argv[]){
    //https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
    int aflag = 0; //Option -a
    int rflag = 0; //Option -b
    char* filename=NULL; //Value passed with option -o
    int index;  //Index to hold illegal arguments
    int c;      //Hold output from getopt

    opterr=0;

    //Process the command line arguments
    while ((c=getopt(argc,argv,"aro:")) != -1)
    {
        switch(c){
            case 'a':
                aflag=1;
                break;
            case 'r':
                rflag=1;
                break;
            case 'o':
                filename = optarg;
                break;
            case '?':
                if (optopt=='o')
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n",optopt);
                else 
                    fprintf (stderr, "Unknown option character `\\x%x'.\n",optopt);
                return 1;
            default:
                abort();
        }

        //Print out every possible flag + what setting
        printf("aflag = %d, rflag = %d, fname = %s\n",aflag,rflag,filename);

        //Print all the illegal characters
        for (index=optind; index < argc; index++){
            printf ("Non-option argument %s\n", argv[index]);
        }

        // First check read mode
        if (filename != NULL) {
            //open_file(filename);
        }

        // Check if random mode or normal mode
        if (rflag==1) // random
        {
            printf("\nOWEN PLEASE MAKE THIS CODE :(\n");
        }
        else { // Normal mode, then check for input
            if (aflag==1) // if file specified, read from it
            {
                printf("\nOWEN I WILL MAKE YOU THIS CODE - Read from file\n");
            } else {
                printf("\nOWEN I WILL MAKE YOU THIS CODE - Open input session\n");
            }
        }

        //close_file(filename);
        return 0;
    }
}
