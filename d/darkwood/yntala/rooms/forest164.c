//forest164
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"fle.c";

void create(){
::create();
set_exits(([
"west":INRMS+"forest165",
"east":INRMS+"forest163",
"north":INRMS+"forest176"
]));
}