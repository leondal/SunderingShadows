#include <std.h>
inherit "/d/common/obj/clothing/magerobe.c";

void create() {
   ::create();
   set_name("frost robes");
   set_id(({"robe","robes","dusk robes","dusk robe","tattered robe"}));
   set_obvious_short("%^RESET%^%^CYAN%^A glittering robe%^RESET%^");
   set_short("%^RESET%^%^CYAN%^Frost Robes%^RESET%^");
  set_long("%^RESET%^%^CYAN%^This robe seems to "+
  "be made out of fine strands of ice.  The robe "+
  "is cold to the touch.  It has a blue-white hew"+
  " to it.  It glistens lustrously in the light.%^RESET%^"
    );
set_lore("This robe is a byproduct of the frozen"+
" maidens that haunt glaciers.  The intense cold"+
" that curses the island embodies these items of"+
" clothing.  As such they seem to have a bit of "+
"power to them to resist the cold.");
set_property("lore difficulty",25);
   set_weight(5);
   set_value(2300);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_max_internal_encumbrance(30);
   set_property("enchantment",3+random(2));
   set_wear((:TO,"wear":));
   set_remove((:TO,"unwear":));
   set_item_bonus("bonus_spell_slots_1",1);
   set_item_bonus("cold resistance",5);
}

int wear(){
   tell_object(ETO,"%^CYAN%^You don the robe and it sends a chill down your spine.");
   return 1;
}

int unwear(){
   if(!objectp(ETO)) return 0;
   tell_object(ETO,"%^CYAN%^You disrobe.");
   return 1;
}
