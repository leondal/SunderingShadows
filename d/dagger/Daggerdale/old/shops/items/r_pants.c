#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/d_pants"->create_pants(TO);
   add_id("dagger_clothing");
}
