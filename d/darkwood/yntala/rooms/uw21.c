//uw21
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"dunderwater.c";

void create(){
::create();
set_exits(([
"up":INRMS+"uw22",
"down":INRMS+"uw20"
]));
}