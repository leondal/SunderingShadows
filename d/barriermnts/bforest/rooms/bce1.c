//bce1
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"broom.c";

void create(){
::create();
   set_long(::query_long()+"\n%^RESET%^%^ORANGE%^The bushes grow up to the base of the cliffedge to the east, making it impossible to go any further in that direction.\n"); 
   set_exits(([
   "north":INRMS+"fpath1",
   "west":INRMS+"fpath2",
   "south":INRMS+"bce2",
   ]));
}