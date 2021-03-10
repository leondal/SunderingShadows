#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/s_vest"->create_vest(TO);
   set_size(random(3)+1);
}
