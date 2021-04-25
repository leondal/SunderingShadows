//updated by Circe 6/13/04 with new desc, lore, etc.
#include <std.h>
inherit "/d/common/obj/armour/shield.c";

void create() {
    ::create();
    set_name("great shield");
    set_id(({"shield","great shield","great","soldier shield","shield of the soldier"}));
    set_obvious_short("A bronze great shield");
    set_short("%^RESET%^%^ORANGE%^Shield of the Soldier%^RESET%^");
    set_long(
      "%^RESET%^%^ORANGE%^This impressive tower shield is made of solid "+
      "bronze, making it incredibly heavy.  However, a series of "+
      "padded leather straps attached to the back makes it much easier "+
      "to handle the weight.  The front of the shield is embossed with "+
      "a fantastic image of a %^RESET%^tall soldier %^ORANGE%^standing "+
      "with %^YELLOW%^spear %^RESET%^%^ORANGE%^raised.  The shield has "+
      "been made so that it looks as if %^YELLOW%^sunlight %^RESET%^"+
      "%^ORANGE%^is eternally glinting off the speartip.  "+
      "A shield similar to this is in his left hand, off to the side, "+
      "and he is geared for battle.  His face is obscured by an "+
      "%^RESET%^ornate helm%^ORANGE%^, and his long hair falls in "+
      "thin braids over his shoulders.%^RESET%^"
    );
    set_lore("These bronze shields were used by the warriors on "+
       "the island of Attaya.  They would form phalanxes, using "+
       "the shields to form impenetrable barriers as they "+
       "moved.  The warriors have all degraded into the skeletal "+
       "phalanxes that prowl the island there, but their tale "+
       "is one not recorded on this shield.  The shield hints at "+
       "a time when Attaya was a more natural place, if not "+
       "more peaceful.");
    set_weight(25);
    set_value(60);
    set_property("enchantment",5);
    set_wear((:TO,"wear_func":));
}
int wear_func(string str) {
   if((int)ETO->query_level() < 25) {
      tell_object(ETO,"%^ORANGE%^You fumble with the straps of the shield,"+
         " but fail to strap it on your arm.%^RESET%^");
      return 0;
   }
   tell_object(ETO,"%^YELLOW%^You strap the heavy shield onto your"+
      " arm.%^RESET%^");
   return 1;
}
