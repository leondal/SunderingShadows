//scave4
#include <std.h>;
#include "../yntala.h"
inherit INRMS+"scave2.c";

void create(){
::create();
set_exits(([
"south":INRMS+"scave3",
"north":INRMS+"oasis",
]));
}
string ldesc(string str){
   return("%^BOLD%^%^BLUE%^You stand in the middle of a raging underground river that has carved its way through"
" this dark cavern.  Though the river itself is only  a few feet deep, it's current is strong and is"
" constantly pulling you towards the south, and to make matters worse, it appears as though the cavern floor"
" inclines sharply to the north, speeding up the current of the already fast moving water.  There is a glimmer of "
"hope howerver, as there seems to be an opening from the cave just to the north, with the sweet signs of the outdoors"
"pouring in!%^RESET%^\n");
} 