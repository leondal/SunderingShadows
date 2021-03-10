#include <std.h>
inherit WEAPON;

void create()
{
   ::create();
   set_name("diamond studded hammer");
   set_short("A diamond studded hammer");
   set_id(({"hammer","medium hammer","diamond hammer","diamond studded hammer","studded hammer"}));
   set_long("The head of this fine hammer has been coated in silver"+
   " and etched with runes that seem to be constantly swirling on the"+
   " edges of your vision. The head and sides of the hammer have been"+
   " embedded with several small diamonds that protrude slightly,"+
   " allowing them to cut and scratch the surface of whatever it hits."+
   " The handle is made from sturdy ironwood and the bottom part has"+
   " been carefully wrapped in gray leather to give it a better grip.");
   set_weight(7);
   set_value(2500);
   set_wc(1,4);
   set_large_wc(1,4);
   set_type("bludgeoning");
   set_prof_type("medium hammer");
   set_weapon_speed(4);
   set_hit((:TO,"hitme":));
}

int hitme(object targ)
{
   if(!random(6)) {
      tell_object(targ,"%^BOLD%^"+ETO->query_cap_name()+"'s hammer"+
      " slams into you, cutting and scratching you with its diamond"+
      " points.");
      tell_object(ETO,"%^BOLD%^You slam your hammer into "+targ->query_cap_name()+""+
      " and it cuts and scratches "+targ->query_objective()+".");
      tell_room(environment(ETO),"%^BOLD%^"+ETO->query_cap_name()+"'s"+
      " hammer slams into "+targ->query_cap_name()+", cutting and"+
      " scratching "+targ->query_objective()+" with its diamond"+
      " points.",({ETO,targ}));
      targ->do_damage("torso",random(5)+4);
      return 1;
   }
}
