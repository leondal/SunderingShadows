#include <std.h>
inherit "/d/common/obj/clothing/breeches";

void create(){
   ::create();
   set_name("breeches of endurance");
   set_id(({"breeches","pants","breeches of endurance","patterned
breeches"}));
   set_obvious_short("%^RESET%^pa%^ORANGE%^tt%^RESET%^erned br%^ORANGE%^ee%^RESET%^ches");
   set_short("%^RESET%^br%^ORANGE%^eec%^RESET%^hes of en%^ORANGE%^du%^RESET%^rance");
   set_lore("These breeches look to be elven or fey'ri craft."+
   "  Likely they are crafted by a master weaver on a "+
   "very good loom.  The runes look to increase the"+
   " endurance of the wearer. ");
   set_property("lore difficulty",30);
   set_long("%^GREEN%^These breeches are masterwork.  They are shades of green"+
   " with %^ORANGE%^brown%^GREEN%^ runes patterned upon them.  The threading "+
   "is extremely small but very %^ORANGE%^durable%^GREEN%^.  It is somewhat "+
   "difficult to tell what they are woven from.  Suffice to say that the "+
   "fabric is light but also strong enough to offer some form of "+
   "protection against the%^ORANGE%^ elements%^RESET%^.  ");
  
   set_size(2);
   set_value(5000);
   set_wear((:TO,"wear_me":));
   set_property("enchantment",5);
   set_item_bonus("endurance",3);
}

int wear_me(){ 
  tell_object(ETO,"%^GREEN%^You pull the pants up and button them.  You feel a burst
of %^CYAN%^stamina.");
  return 1;
}
