#include <std.h>
inherit "/d/common/obj/armour/chain.c";

void create()
{
    ::create();
    set_name("mithril chainmail");
    set("id", ({ "chain", "armor", "chainmail","mithril chainmail"}) );
    set("short", "A suit of mithril chainmail");
    set("long","%^BOLD%^This is a suit of bright shiney Mithril chainmail.  "
        "It was forged by the Dwarves of Mt. Sholkum.  "
        "This is the standard issue armor for the Army of the Dagger Reaches.");
    set("value", 95);
    if(!random(2)) { set_property("enchantment", 1); }
}
