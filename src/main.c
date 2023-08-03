#include <getopt.h>
#include "main.h"

/*  TITLE:          Main
    DESCRIPTION:    Handles calls to compiled .o file
    PREREQS:        Compile via gcc as main.out
    EXAMPLE:        ./main.out -o "test.txt"
    FLAGS
*/
int main(int argc, char* argv[]){
    //https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
    int aflag = 0; //Option -a
    int bflag = 0; //Option -b
    char* filename=NULL; //Value passed with option -o
    int index;  //Index to hold illegal arguments
    int c;      //Hold output from getopt

    opterr=0;

    //Process the command line arguments
    while ((c=getopt(argc,argv,"abo:")) != -1)
    {
        switch(c){
            case 'a':
                aflag=1;
                break;
            case 'b':
                bflag=1;
                break;
            case 'f':
                filename = optarg;
                break;
            case '?':
                if (optopt=='f')
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
        printf("aflag = %d, bflag = %d, cvalue = %s\n",aflag,bflag,filename);

        //Print all the illegal characters
        for (index=optind; index < argc; index++){
            printf ("Non-option argument %s\n", argv[index]);
        }
        return 0;
    }
}
