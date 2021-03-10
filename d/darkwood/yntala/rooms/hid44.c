//hid44
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"endhid.c";

void create(){
::create();
set_exits(([
"northwest":INRMS+"hid43",
]));
}