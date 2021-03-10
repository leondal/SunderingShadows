#include <std.h>
#include "../inherits/area_stuff.h"
inherit OUTTER2;

void create() 
{
    ::create();
    set_exits((["north" : CRROOMS+"out17", "southwest" : CRROOMS+"out14", "west" : CRROOMS+"out13", "northwest" : CRROOMS+"out12"]));		

}
