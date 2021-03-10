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
/*	monsArray = allocate(3);
	ob = new(LMON+"lman");
	ob->move(TO);
*/
set_exits(([
   "east":LROOMS+"dw10",
   "southeast":LROOMS+"dw20",
   "south":LROOMS+"dw19",
   "southwest":LROOMS+"dw18",
   "down":LROOMS+"dw9d"
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