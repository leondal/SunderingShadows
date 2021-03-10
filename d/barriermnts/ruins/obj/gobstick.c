#include <std.h>
#include "../inherit/ruins.h"
inherit "/d/common/obj/weapon/mspear.c";

void create() {
   ::create();
   set_id(({"stick","goblin stick"}));
   set_name("%^RESET%^%^ORANGE%^broken stick%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^a broken stick%^RESET%^");
   set_long("This is nothing more than a stick with a sharp broken end. What a crude weapon!\n");
   set_weight(5);
   set_property("enchantment",1);
   set_value(10);
}

int isMagic(){
 return 0;
}
