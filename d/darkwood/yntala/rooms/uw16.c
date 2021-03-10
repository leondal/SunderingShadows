//uw16
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"dunderwater.c";

void create(){
::create();
set_exits(([
"down":INRMS+"uw17",
"up":INRMS+"uw15"
]));
}