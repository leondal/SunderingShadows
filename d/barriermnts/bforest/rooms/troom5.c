//troom5
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"troom.c";

void create(){
::create();
set_exits(([
"down":INRMS+"fpath1",
"north":INRMS+"troom3",
"east":INRMS+"troom4",
"southwest":INRMS+"troom6",
"southeast":INRMS+"troom7",
]));
}