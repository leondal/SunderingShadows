//fpath2
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
   set_exits(([
   "northeast":INRMS+"fpath1",
   "south":INRMS+"fpath3",
   "west":INRMS+"fpath59",
   "southwest":INRMS+"fpath58",
   "east":INRMS+"bce1",
   ]));
   
}