//fpath8
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"northeast":INRMS+"frpath5",
"south":INRMS+"fpath9",
"west":INRMS+"fpath38",
]));
}