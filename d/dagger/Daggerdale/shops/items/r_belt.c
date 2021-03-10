#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/d_belt"->create_belt(TO);
   add_id("dagger_clothing");
}
