//mace_of_ibrandul - obvious_short added 10/23/03 by Circe

#include <std.h>

inherit WEAPON;

void create(){
   ::create();
   set_name("mace of ibrandul");
   set_id(({"mace","mace of ibrandul"}));
   set_obvious_short("A diamond-headed mace");
   set_short("%^RED%^Mace of Ibrandul%^RESET%^");
   set_long(
@OLI
   This fine diamond headed mace is the traditional mace
of the followers of Ibrandul. With wicked sharped edges
on the head the mace looks likely to do great damage.
OLI
   );
   set_wc(1,8);
   set_large_wc(1,8);
   set_hit((:TO,"hitme":));
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"removeme":));
   set_size(2);
   set_weight(10);
   set_value(2500);
   set_type("bludgeoning");
   set_prof_type("mace");  // changed to just normal mace 11/23/03 *Styx*
   set_prof_level(40);
   set_property("enchantment",4);
}

int hitme(object targ){
//   if(!objectp(targ)) return random(5);  don't know what this was for since if the target isn't valid you would want to return 0 if anything.  *Styx*
   if((string)targ->query_diety() == "shar")
      return random(10);
   return random(5);
}

int wieldme(){
   if(!interactive(TP)) return 1;
   if((int)TP->query_highest_level() < 30) {
	write("You are not worthy of wielding such a powerful weapon!");
	return 0;
   }
   ETO->set_property("evil item",1);
   return 1;
}

int removeme() {
   ETO->set_property("evil item",-1);
   return 1;
}
