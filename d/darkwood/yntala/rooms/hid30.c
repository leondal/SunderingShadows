//hid30
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"northwest":INRMS+"hid31",
"southeast":INRMS+"hid5"
]));
}