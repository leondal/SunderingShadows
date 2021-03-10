//updated to current standards ~Circe~ 7/30/19 - could maybe use some additional love

#include <std.h>
inherit "/d/common/obj/armour/helm.c";

void create(){
   ::create();
   set_name("steel helm");
   set_short("%^RESET%^%^CYAN%^Polished steel helm%^RESET%^");
   set_id(({"polished steel helm","helmet","helm","steel helm"}));
   set_long("This great helm is polished to a high shine but only seems to reflect the dancing images of flames in any light.");
   set_lore("This enormous helm must have been made for a giant.  Its unique property of reflecting firelight makes it probable that this helm came from the fiery depths of the earth, or perhaps that is a trick of the enchantment.");
   set_value(100);
   set_size(3);
   set_property("enchantment",2 + random(2));
}
