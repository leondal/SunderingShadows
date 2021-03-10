//forest168
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"fle.c";

void create(){
::create();
set_exits(([
"southeast":INRMS+"forest158",
"north":INRMS+"forest167"
]));
}