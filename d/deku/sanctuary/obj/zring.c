#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("brotherhood ring");
   set_id(({"ring","brotherhood ring","ring of the arcane brotherhood"}));
   set_short("%^BOLD%^%^RED%^Ring of the Arcane Brotherhood%^RESET%^");
   set_obvious_short("%^BOLD%^%^RED%^ruby %^BOLD%^%^BLACK%^ring%^RESET%^");
   set_long(
      "The band of this ring is made from some sort of blackened metal."+
      " Set in the top of the ring is a ruby that has been cut several times."
   );
   set_lore("This ring is worn by members of the Arcane Brotherhood, and is needed to gain access into their secretive halls.");
   set_property("lore difficulty",15);
   set_type("ring");
   set_ac(0);
   set_weight(0);
   set("value",50);
   set_limbs(({"left hand","right hand"}));
}