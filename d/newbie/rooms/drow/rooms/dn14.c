#include <std.h>
#include "../drownew.h"

inherit CAVERN;
void create()
{
    ::create();
  	set_exits(([
    "southeast" : DNROOMS+"dn18",
    "south" : DNROOMS+"dn17",
    "southwest" : DNROOMS+"dn16",
    "west" : DNROOMS+"dn13"
    ]));
}