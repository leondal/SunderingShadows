#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/d_shorts"->create_shorts(TO);
   add_id("dagger_clothing");
}
