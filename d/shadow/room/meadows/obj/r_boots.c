#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/d_boots"->create_boots(TO);
   set_size(random(3)+1);
}
