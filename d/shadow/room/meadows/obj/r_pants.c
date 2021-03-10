#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/d_pants"->create_pants(TO);
   set_size(random(3)+1);
}
