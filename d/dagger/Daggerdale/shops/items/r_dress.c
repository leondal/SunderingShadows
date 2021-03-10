#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/d_dress"->create_dress(TO);
   add_id("dagger_clothing");
}
