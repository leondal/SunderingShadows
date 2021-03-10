// updated to jewelry with new non-stacking armor system. N, 4/19.
#include <std.h>
#include "../kildare.h"
inherit ARMOUR;

void create() {
    ::create();
   set_id(({"necklace","talon necklace","leather necklace","talisman"}));
   set_name("talon necklace");
   set_obvious_short("%^RESET%^%^ORANGE%^A leather necklace%^RESET%^");
   set_short("%^RESET%^%^RED%^Peryton Talisman%^RESET%^");
   set_long(
      "%^RESET%^%^ORANGE%^A simple leather cord supports a three inch "+
      "%^BOLD%^%^WHITE%^talon %^RESET%^%^ORANGE%^stained with %^BOLD%^%^RED%^blood"+
      "%^RESET%^%^ORANGE%^.  The same leather cording has been wrapped "+
      "around the top of the talon, which curves wickedly and is quite sharp.  "+
      "A power of sorts seems to pulsate within.%^RESET%^"
   );
   set_lore("%^BOLD%^%^WHITE%^This talon was taken from a peryton, "+
      "a fierce beast that legend says eats humanoid hearts.  Blood "+
      "clings to the talon, no matter how long it has been since "+
      "the wound was made.  Some sages believe that a peryton's "+
      "talon may be used to help sustain spells for longer "+
      "periods of time.%^RESET%^");
   set_property("lore difficulty",10);
   set_limbs(({"neck"}));
   set_type("ring");
   set_ac(0);
   set_value(150);
   set_weight(5);
set_property("enchantment",2);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
}

int wearme()
{
   if(ETO->query_lowest_level() < 8){
      tell_object(ETO,"%^BOLD%^%^RED%^You are not experienced enough to "+
      "stand the might of the talon!");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^RED%^You tied the leather cord around your neck "+
      "and feel more confident.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^WHITE%^Light glints along the talon as "+
      ""+ETO->query_cap_name()+" ties the leather cord around "+ETO->query_possessive()+" "+
      "neck.",ETO);
   return 1;
}

int unwearme()
{
   tell_object(ETO,"%^BOLD%^%^BLUE%^You feel weaker as you reluctantly untie "+
      "the leather cord.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" slowly unties "+
      "the leather cord with a diappointed frown.%^RESET%^",ETO);
   return 1;
}
