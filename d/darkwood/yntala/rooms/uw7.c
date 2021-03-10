//uw7
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"bunderwater.c";

void create(){
::create();
set_exits(([
"south":INRMS+"uw8",
"up":INRMS+"uw6"
]));
}