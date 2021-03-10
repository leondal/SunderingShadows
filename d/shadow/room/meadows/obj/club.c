//updated by Circe 6/7/04 with new desc, lore, etc, by Shar
#include <std.h>
inherit "/d/common/obj/weapon/mclub";

void create()
{
   ::create();
   set_name("club");
   set_obvious_short("An ebony club");
   set_short("%^BOLD%^%^BLACK%^Ebony Club%^RESET%^");
   set_id(({"club","ebony club"}));
   set_long("%^BOLD%^%^BLACK%^A cylindrical length of ebony has "+
      "been polished to a high glossy sheen.  The ebony wood is "+
      "etched with deep grooves that have been filled in with "+
      "molten %^RESET%^%^ORANGE%^b%^YELLOW%^ra%^RESET%^%^ORANGE%^"+
      "ss%^BOLD%^%^BLACK%^.  The design on the club seems to echo "+
      "natural themes, though they are hard to discern.%^RESET%^");
   set_lore("The Ebony Club is another relic left over from a great "
"battle that took place in these parts.  When the orcish hordes "
"threatened the land and the people an order of druids swept down "
"onto the area to protect the forest and meadow lands.  The Druids "
"were known as the Ebony Owls, and were dedicated to Silvanus.  Given "
"that druids shun most attention and fame, there have been conflicting "
"reports of what happened to the Ebony Owls.  Some claim that like the "
"rangers of Mielikki, they were wiped out by the horde.");
   set_property("lore difficulty",8);
   set_value(250);
   if(!random(3)) set_property("enchantment",1);
   set_hit((:TO,"hitme":));
}

int hitme(object targ)
{
   if(!objectp(targ)) return 5;
   if(!random(6)) {
      tell_object(ETO,"%^BOLD%^You deliver a devastating blow to "+
         ""+targ->QCN+" with your club!");
      tell_object(targ,"%^BOLD%^"+ETOQCN+" delivers a"+
      " devastating blow to you!");
      tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" delivers"+
      " a devastating blow to "+targ->QCN+"!",({ETO,targ}));
      targ->do_damage("torso",random(3)+3);
      return 1;
   }
   if(!random(8)) {
      tell_object(ETO,"%^RED%^You slam "+targ->QCN+" so hard"+
      " that the club vibrates in your hand.");
      tell_object(targ,"%^RED%^"+ETOQCN+" slams "+ETO->QP+""+
      " club into you with incredible force!");
      tell_room(environment(ETO),"%^RED%^"+ETOQCN+" slams"+
      " "+targ->query_cap_name()+" incredibly hard with "+ETO->QP+""+
      " club.",({ETO,targ}));
      targ->do_damage("torso",random(5)+4);
      return 1;
   }
}

