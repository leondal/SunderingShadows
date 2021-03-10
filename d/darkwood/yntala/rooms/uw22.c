//uw22
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"dunderwater.c";

void create(){
::create();
set_exits(([
"up":INRMS+"uw13",
"down":INRMS+"uw21"
]));
}