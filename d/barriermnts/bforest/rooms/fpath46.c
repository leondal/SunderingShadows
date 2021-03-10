//fpath46
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"west":INRMS+"fpath43",
"east":INRMS+"fpath47",
]));
}