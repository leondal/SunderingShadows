//hid37
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"endhid.c";

void create(){
::create();
set_exits(([
"southeast":INRMS+"hid36",
]));
}