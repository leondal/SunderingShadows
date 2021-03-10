#include <std.h>
#include "../undead.h"

inherit CWEAP"longsword";

create() 
{
   ::create();
   set_name("blessed blade");
   set_id(({"blade","blessed blade", "sword", "long sword", "weapon"}));
   set_obvious_short("A longsword");
   set_short("%^BOLD%^blessed blade%^RESET%^");
   set_long("%^BOLD%^This weapon have been blessed in order to help combat the evil on the island of Graez."+
   "Together with the bold men and women wielding these weapons, they are the last defenders of Graez.%^RESET%^\n");
   set_value(800);
   set_wield((: TO,"extra_wield" :));
   set_hit((: TO,"extra_hit" :));
   set_unwield((: TO,"unwieldme" :));
   set_property("enchantment",3);
}

int extra_wield() 
{
    tell_object(ETO,"%^CYAN%^%^BOLD%^You feel the blessing empowering you!");
    tell_room(EETO,"%^CYAN%^%^BOLD%^"+ETO->QCN+"'s sword gives of a slight bluish glow", ETO);
	set_property("good",1);
    return 1;
}

int extra_hit(object targ) 
{
    if(!objectp(targ)) { return 1; }
    if(!objectp(ETO)) { return 1; }
	targ = ETO->query_current_attacker();

	if(random(100)< 15) {
	if((string)targ->query_race() == "undead") {
        tell_object(ETO,"%^BOLD%^%^CYAN%^Your blade turns bright blue at it hits "+targ->QCN+"!");
        tell_object(targ,ETO->QCN+"'s%^BOLD%^%^CYAN%^ blade turns bright blue as it hits you!");
        tell_room(EETO,ETO->QCN+"'s%^BOLD%^%^CYAN%^ blade turns bright blue as it hits "+targ->QCN+"!",({targ, ETO}));
        targ->do_damage(targ->return_target_limb(),roll_dice(5,6));		
		return 1;
	}
	
	
        tell_object(ETO,"%^CYAN%^Your blades blessing guides you strike against "+targ->QCN+"!");
        tell_object(targ,"%^CYAN%^"+ETO->QCN+"'s hits you with ease!");
        tell_room(EETO,"%^CYAN%^"+ETO->QCN+"'s blade guides itself towards "+targ->QCN+"!",({targ, ETO}));
        targ->do_damage(targ->return_target_limb(),roll_dice(2,6));
    
    return 1;
}
}


int unwieldme() {
	set_property("good",-1);
	return 1;
	}