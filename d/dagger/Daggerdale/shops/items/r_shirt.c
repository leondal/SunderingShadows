#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/d_shirt"->create_shirt(TO);
   add_id("dagger_clothing");
}
