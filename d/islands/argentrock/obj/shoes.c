#include <std.h>
inherit "/d/common/obj/clothing/shoes";

void create(){
   ::create();
   set_name("shoes of stealth");
   set_id(({"shoe","shoes","shoes of stealth"}));
   set_short("%^RESET%^s%^ORANGE%^h%^RESET%^oes of s%^ORANGE%^t%^RESET%^ealth");
   set_obvious_short("%^RESET%^l%^ORANGE%^i%^RESET%^ght l%^ORANGE%^e%^RESET%^ather s%^ORANGE%^h%^RESET%^oes");
   set_lore("These shoes appear to be masterwork products"+
   " of the fey'ri.  They are finely crafted and part of "+
   "the sewing must have been extremely difficult.  The"+
   " magical crafting is obvious.  These shoes are created"+
   " to increased the stealth of the wearer.");
   set_property("lore difficulty",30);
   set_long("These shoes look to be mas%^BOLD%^terw%^RESET%^ork"+
   " leather creations.  Further inspection yields that"+
   " they have %^MAGENTA%^runes%^RESET%^ sown into the "+
   "tongue as well as the %^MAGENTA%^sole%^RESET%^.  Likewise "+
   "there is one %^MAGENTA%^large rune%^RESET%^ covering"+
   " the bottom of the shoe that seems to quiet any noise around it.");
  
   set_size(2);
   set_value(5000);
   set_wear((:TO,"wear_me":));
   set_property("enchantment",4+random(1));
   set_item_bonus("stealth",3);
}

int wear_me(){ 
  tell_object(ETO,"%^MAGENTA%^You lace up the shoes and feel %^RESET%^light%^MAGENTA%^ on your feet.");
  return 1;
}
