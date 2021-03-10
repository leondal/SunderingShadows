#include <std.h>

inherit "/d/common/obj/armour/leather_plate";

void create() {
    ::create();
    set_name("leather harness");
    set_id(({"harness","leather harness","breastplate","leather"}));
    set_short("%^RESET%^%^ORANGE%^a leather harness%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This harness is crafted of "+
      "aged leather straps that cross over the shoulders and "+
      "around the waist, meeting in the middle at a roughly "+
      "square-shaped breastplate.  The armor is rather "+
      "crude in nature, but it would certainly provide "+
      "some protection, and it seems well-kept despite "+
      "its age.%^RESET%^");
   set_lore("Armor of this type is fashioned by the strange aberrations "+
      "that occasionally appear in the peryton lineage. It is said that "+
      "sometimes these unfortunate offspring possess greater intelligence "+
      "than their kin, making them dangerous foes indeed. Such creatures "+
      "often hoarde whatever they find, making items that are sometimes "+
      "useful and trinkets they find beautiful.");
   set_property("lore difficulty",8);
   if(random(3)) set_property("enchantment",1);
   set_wear((:TO,"extra_wear":));
}

int extra_wear(){
   tell_object(ETO,"%^RESET%^%^ORANGE%^You strap on the "+
      "breastplate and feel more protected.%^RESET%^");
   return 1;
}