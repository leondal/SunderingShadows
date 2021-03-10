//hid25
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"north":INRMS+"hid24",
"east":INRMS+"hid16",
"south":INRMS+"hid26",
]));
new(TMONDIR+"dknight.c")->move(TO);
}