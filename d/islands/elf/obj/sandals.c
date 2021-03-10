#include <std.h>
inherit "/d/common/obj/clothing/shoes";

void create(){
   ::create();
   set_name("dusk sandals");
   set_id(({"sandal","sandals","tattered sandals","dusk sandals"}));
   set_short("%^RESET%^%^MAGENTA%^dusk sandals%^RESET%^");
   set_obvious_short("%^RESET%^%^MAGENTA%^tattered sandals%^RESET%^");
   set_lore("The footwear looks to be of elven make. "+
   " However, judging by the wear it is likely old and"+
   " should be useless.  The strange glow is likely "+
   "something left behind from the previous owner."+
   "  It seems to radiate loneliness and despair.  ");
   set_property("lore difficulty",30);
   set_long("%^MAGENTA%^These are some dark colored sandals.  They "+
   "have a deep violet fabric that is used to secure "+
   "the foot in place.  The footing is also of a violet "+
   "color and made of what might have been soft leather "+
   "at one time but now is stiff and rough.  Strangely,"+
   " the sandals seem to glow with a dark power.%^RESET%^");
  
   set_size(2);
   set_value(5000);
   set_wear((:TO,"wear_me":));
   set_property("enchantment",3);
   set_item_bonus("endurance",1);
}

int wear_me(){ 
  tell_object(ETO,"%^MAGENTA%^You slip your feet into the sandals and feel like your family has abandoned you.");
  return 1;
}
