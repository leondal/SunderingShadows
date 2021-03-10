//frpath5
#include <std.h>;
#include "../bforest.h"
inherit IHRMS+"fredge.c";

void create(){
::create();
set_exits(([
"north":INRMS+"frpath4",
"southwest":INRMS+"fpath8",
]));
}