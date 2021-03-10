//forest155
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"fle.c";

void create(){
::create();
set_exits(([
"north":INRMS+"forest162",
"southwest":INRMS+"forest154"
]));
}