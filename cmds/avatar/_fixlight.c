#include <std.h>


int cmd_fixlight(){
TP->remove_property("light");
write("Light setting repaired.");
	return 1;
}

int help(){
write("Should fix your light property if it looks darker or lighter when you're in the room.");
 return 1;
}
