//fpath55
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fpath.c";

void create(){
::create();
set_exits(([
"north":INRMS+"fpath56",
"southeast":INRMS+"frpath2",
"southwest":INRMS+"fpath60"
]));
}