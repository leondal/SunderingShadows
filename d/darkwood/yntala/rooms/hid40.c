//hid40
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"endhid.c";

void create(){
::create();
set_exits(([
"north":INRMS+"hid39",
]));
}