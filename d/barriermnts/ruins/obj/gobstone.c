#include <std.h>
#include "../inherit/ruins.h"
inherit "/d/common/obj/weapon/shortsword.c";

void create() {
   ::create();
   set_id(({"stone","goblin stone"}));
   set_name("%^BLACK%^%^BOLD%^sharp-edged stone%^RESET%^");
   set_short("%^BLACK%^%^BOLD%^a sharp-edged stone%^RESET%^");
   set_long("This is nothing more than a rock, sharpened to a nasty edge. What a crude weapon!\n");
   set_weight(4);
   set_property("enchantment",1);
   set_value(10);
}

int isMagic(){
 return 0;
}
