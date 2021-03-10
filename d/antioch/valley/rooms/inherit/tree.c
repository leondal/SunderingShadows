#include <std.h>
#include "../../valley.h"
inherit ROOM;

void create()
{
        ::create();
   set_terrain(BRANCHES);
   set_travel(FRESH_BLAZE);
   set_property("no charge",1);
   set_property("no multi-charge",1);
   set_charge_message("You can't charge in a tree, you shouldn't even have a horse with you!");
   set_mcharge_message("You can't charge in a tree, you shouldn't even have a horse with you!");
        set_property("outside", 2);
        set_property("light", 2);
   set_short("%^BOLD%^%^GREEN%^In a tree%^RESET%^");
        set_smell("default",
        "You smell the scent of elm leaves."
        );
        set_listen("default",
        "Some birds are chirping in the distance."
        );
}
