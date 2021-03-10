//forest31
//this will be the linking room to the road between azha and tharis
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest3.c";

void create(){
::create();
set_exits(([
"north":INRMS+"forest32",
"south":"/d/tharis/road/wroad18",

]));
}
