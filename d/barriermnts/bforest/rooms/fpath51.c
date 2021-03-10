//fpath51
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"south":INRMS+"fpath50",
"northeast":INRMS+"fpath52",
]));
}