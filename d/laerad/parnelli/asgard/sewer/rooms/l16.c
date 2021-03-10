#include <std.h>
#include "../lizard.h"

inherit LIZ;

/* changing to have inherit use CROOM  *Styx*  6/18/03
object ob;
object *monsArray;
int i;
*/

void create(){
	::create();
//	monsArray = allocate(3);
set_exits(([
   "north":LROOMS+"w2",
   "northeast":LROOMS+"l11",
   "east":LROOMS+"l17",
   "southeast":LROOMS+"w8",
   "south":LROOMS+"w7",
   "southwest":LROOMS+"w6",
   "west":LROOMS+"l15",
   "northwest":LROOMS+"w1"
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