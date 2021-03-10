//uw17
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"dunderwater.c";

void create(){
::create();
set_exits(([
"down":INRMS+"uw18",
"up":INRMS+"uw16"
]));
}