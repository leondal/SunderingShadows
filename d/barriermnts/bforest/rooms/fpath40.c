//fpath40
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"east":INRMS+"fpath39",
"southwest":INRMS+"fpath41",
]));
}