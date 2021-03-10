#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/d_statue"->create_statue(TO);
}
