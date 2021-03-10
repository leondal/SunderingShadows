#include <std.h>
#include "../lizard.h"

inherit DEEP1;

/* changing to have inherit use CROOM  *Styx*  6/18/03
object ob;
object *monsArray;
int i;
*/

void create(){
	::create();
//	monsArray = allocate(3);
set_exits(([
   "north":LROOMS+"dw9",
   "northeast":LROOMS+"dw10",
   "east":LROOMS+"dw20",
   "southeast":LROOMS+"dw29",
   "south":LROOMS+"dw28",
   "southwest":LROOMS+"dw27",
   "west":LROOMS+"dw18",
   "down":LROOMS+"dw19d"
 ]));
}

/*
void reset() {
        ::reset();
       for(i = 0;i < sizeof(monsArray);i++){
        	if(!objectp(monsArray[i])){
        		if(!random(5)) {
            		ob = new(LMON+"lman");
            		ob->move(TO);
            		monsArray[i] = ob;
        		}
        		if(!random(10)) {
            		ob = new(LMON+"plead");
            		ob->move(TO);
            		monsArray[i] = ob;
        		}
        		if(!random(20)) {
            		ob = new(LMON+"warlead");
            		ob->move(TO);
            		monsArray[i] = ob;
        		}
		}
	}
}
*/