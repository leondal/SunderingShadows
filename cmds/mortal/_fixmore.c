#include <std.h>

inherit DAEMON;

int cmd_fixmore(){
   TP->fixmore(); 
	return 1;
}

int help(){
     write("Will exit you out of <more> should fix most who problem.");
 return 1;
}
