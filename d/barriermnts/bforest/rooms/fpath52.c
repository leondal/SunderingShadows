//fpath52
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"southwest":INRMS+"fpath51",
"east":INRMS+"fpath53",
]));
}