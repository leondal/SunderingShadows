//Updated sword - Cythera 5/05\\
#include <std.h>
inherit "/d/common/obj/weapon/broad.c";

void create()
{
   	::create();
   	set_name("broadsword");
   	set_short("%^RESET%^%^ORANGE%^Broadsword of the "+
		"Am%^YELLOW%^b%^RESET%^%^ORANGE%^er Flames%^RESET%^");
   	set_obvious_short("%^RESET%^%^ORANGE%^An amber broadsword%^RESET%^");
   	set_id(({"sword","broadsword","broadsword of the amber flames","+
		""amber sword","amber broadsword"}));
   	set_long("%^ORANGE%^Crafted from a solid piece of amber, "+
		"the surface of this broadsword has been polished to"+
		" a smooth finish.  The edges and tip of the blade have"+
		" been magically sharpened, giving the amber a keen edge."+
		"  Inside the amber blade preserved %^GREEN%^leaves"+
		"%^ORANGE%^ of a fern remain frozen in time.  Coarsely"+
		" woven strips of hemp bind the handle of the broadsword,"+
		" giving some cushion to the wielder.\n"); 
   	set_value(175);
   	set_property("enchantment",1);
	set_lore("The Broadsword of the Amber Flames was said to "+
		"have been a blade once wielded by a ranger of Eldath"+
		" named Priam.  This peace loving ranger was an oddity"+
		" among his more aggressive brothers and sisters, for"+
		" he always use to try to mediate problems before "+
		"reaching for his blades first.  Priam though "+
		"understood that sometimes one must fight, but only "+
		"after all chances for peace to reign have been "+
		"exhausted.  He was well known for his twin broadswords"+
		" made of amber that he wielded in battle, striking "+
		"swiftly to end any conflict as soon as possible.");
   	set_property("lore difficulty",7);

   	set_hit((:TO,"hitme":));
   	set_wield("%^ORANGE%^You feel a calmness fall over you as you wield the sword.");
	set_unwield("%^ORANGE%^The feeling of calmness that washed over you suddenly departs.");
}

int hitme(object targ){
if(!objectp(targ)) return 0;
if(!objectp(ETO)) return 0;
   if(!random(9)) {
      tell_object(ETO,"%^ORANGE%^Amber flames tinged with "+
		"%^GREEN%^green%^ORANGE%^ lick off the sword and burn"+
      	" "+targ->QCN+".");
      tell_object(targ,"%^ORANGE%^Amber flames tinged with "+
		"%^GREEN%^green%^ORANGE%^ lick off of "+ETO->QCN+"'s "+
		"sword and burns you.");
      tell_room(environment(ETO),"%^ORANGE%^Amber flames tinged "+
		"with %^GREEN%^green%^ORANGE%^ lick off of "+ETO->QCN+"'s"+
		" sword and burns "+targ->QCN+".",({ETO,targ}));
      		set_property("magic",1);
     		 	targ->do_damage("torso",random(4)+2);
      		remove_property("magic");
      return 1;
   }
}