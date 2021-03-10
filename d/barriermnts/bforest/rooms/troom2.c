//troom2
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"treeroom2.c";

void create(){
::create();
set_exits(([
"down":INRMS+"fpath1",
"west":INRMS+"troom1",
"south":INRMS+"troom4",
"southwest":INRMS+"troom3",
]));
}