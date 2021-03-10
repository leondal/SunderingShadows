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
   "north":LROOMS+"dw19",
   "northeast":LROOMS+"dw20",
   "east":LROOMS+"dw29",
   "southeast":LROOMS+"dw34",
   "south":LROOMS+"dw33",
   "southwest":LROOMS+"dw32",
   "west":LROOMS+"dw27",
   "northwest":LROOMS+"dw18",
   "down":LROOMS+"dw28d"
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