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
   "north":LROOMS+"l5",
   "south":LROOMS+"l14",
   "southwest":LROOMS+"l13",
   "west":LROOMS+"l9",
   "northwest":LROOMS+"l4"
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