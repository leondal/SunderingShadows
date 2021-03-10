//hid17
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"endhid.c";

void create(){
::create();
set_exits(([
"south":INRMS+"hid18",
]));
}