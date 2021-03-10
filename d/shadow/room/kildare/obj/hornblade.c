//hornblade.c

#include <std.h>
#include "../kildare.h"

inherit "/d/common/obj/weapon/shortsword.c";

void create(){
   ::create();
   set_name("hornblade");
   set_id(({"blade","hornblade","horn blade","sword","antler"}));
   set_obvious_short("%^BOLD%^%^BLACK%^A sharpened antler%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Hornblade%^RESET%^");
   set_lore("%^BOLD%^%^BLUE%^Hornblades are the stripped antlers "+
      "of the dread beast peryton.  They are said to be wickedly "+
      "sharp and possess something of the spirit of the beast.  "+
      "Legend has that perytons eat the hearts of humans and other "+
      "humanoids in an attempt to free themselves from this world.  "+
      "They are the twisted creation of an ancient dark deity and "+
      "have no purpose and no hope.  They hate all life and wish "+
      "only to find something better than what they have here."
      );
   set_property("lore difficulty",9);
   set_long("%^BOLD%^%^WHITE%^The long curving %^BOLD%^%^BLACK%^ebony horn "+
      "%^WHITE%^of the peryton is naturally honed to a sharp, curving edge.  "+
      "%^BOLD%^%^BLACK%^Darkened leather %^WHITE%^has been wrapped around the base "+
      "of the antler, providing a strong, comfortable grip.  The natural "+
      "horn of the sword seems lighter than most metals, and it glitters "+
      "%^BOLD%^%^BLACK%^black %^WHITE%^in the light."
      );
   set_property("enchantment",1);
   set("value",500);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((:TO,"extra_hit":));
}
int wield_func(string str) {
   if((int)ETO->query_level() < 10) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^The energy of the beast is too great for you to wield!");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^RED%^You grip the blackened hilt and feel the power "+
      "of the beast flow through you.");
   tell_room(environment(ETO),"%^BOLD%^%^RED%^"+TPQCN+" wields the blackened blade "+
      "with an eager expression.",TP);
   return 1;
}
int unwield_func(string str) {
   tell_object(ETO,"%^RESET%^%^BLUE%^You reluctantly release the weapon and sigh as "+
      "the energy of the beast leaves you feeling powerless.");
   tell_room(environment(ETO),"%^RESET%^%^BLUE%^"+ETO->query_cap_name()+" unwields "+
      "the curved blade and sighs with disappointment.",ETO);
   return 1;
}
int extra_hit(object victim) {
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(victim)) return 1;
   if(!random(10)) {
      tell_object(ETO,"%^BOLD%^%^BLUE%^You thrust the hornblade deeply into your "+
         "foe and twist violently before ripping it out again!");
      tell_object(victim,"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" thrusts "+
         ""+ETO->query_possessive()+" blade into you and twists violently!");
      tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" twists "+
         ""+ETO->query_possessive()+" blade deeply into "+victim->query_cap_name()+" and "+
         "pulls it out savagely!", ({ETO,victim}));
      victim->do_damage("torso",random(5)+2);
      return 0;
   }
   else return 0;
}
