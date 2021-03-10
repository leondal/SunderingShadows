//forest178
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"north":INRMS+"forest177",
"southeast":INRMS+"forest134"
]));
}