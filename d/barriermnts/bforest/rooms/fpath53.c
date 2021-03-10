//fpath53
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"west":INRMS+"fpath52",
"east":INRMS+"fpath54",
]));
}