#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("hand");
   set_id(({"hand","necklace","leather necklace","hewn hand"}));
   set_short("%^RED%^roughly hewn hand%^RESET%^");
   set_long("This small hand could only have belonged to a small child, or a halfling.  The hand itself is "
"entirely intact, but is roughly hewn at the wrist to remove it from its previous owner.  A leather strap "
"has been roughly lashed around the hand, probably to hold it around the wearer's neck.  Goblinoid runes "
"have been carved into the palm of the hand, though it's uncertain if they carry any real meaning.");
   set_ac(0);
   set_weight(6);
   set_value(5);
   set_size(1);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_property("enchantment",1);
}
