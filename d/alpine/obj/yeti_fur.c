//  A warm fur for the Yeti, By Killashandra

inherit "/std/armour";
#include "short.h"

void create() {
    ::create();
    set_name("Yeti Fur");
    set("id", ({"fur", "yeti fur","cloak"}) );
    set("short","A warm %^WHITE%^BOLD%^white fur cloak%^RESET%^");
    set("long", 
      "This is the fur hide from a Yeti.  It looks very warm and heavy.\n"
       );
    set_weight(40);
    set("value", 500);
    set_type("clothing");
    set_limbs( ({ "torso" }) );
    set_ac(2);
}
