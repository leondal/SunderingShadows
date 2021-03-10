//hid5
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"northwest":INRMS+"hid30",
"south":INRMS+"hid4"
]));
}