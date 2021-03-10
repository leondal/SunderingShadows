//Updated to bring in line with area difficulty - Octothorpe 4/15/10

#include <std.h>
inherit "/d/common/obj/weapon/mclub.c";

void create(){
	::create();
	set_name("lightning rod");
	set_id(({ "rod", "lightning rod" }));
	set_short("%^YELLOW%^Lightning Rod%^RESET%^");
	set_obvious_short("%^YELLOW%^A yellow tinted metal rod%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^This yellow tinted rod is composed of primairy steel.  The rod is about two feet tall and shaped into a cylindar.  Etched into the steel are twisted and jagged lines, that have been filled with electrum.  A smell of ozone seems to be infused in the rod.

AVATAR
	);
	set_weight(6);
	set_value(1100);
	set_lore(
@AVATAR
The Lighting Rod was first created by a cult of priests of Talos, about 500 years ago.  Since then those of Talos have flooded the realms with these lightning infused rods.

AVATAR
	);
	set_property("lore",11);
	set_property("enchantment",3+random(2));
      set_item_bonus("attack bonus",1);
      set_item_bonus("damage bonus",1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+"'s metal rod flashes briefly as "+ETO->QS+" wields it.",ETO);
	tell_object(ETO,"%^YELLOW%^The electrum lines on the rod flash to life as you wield the rod.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^YELLOW%^A thunderous boom echos in the area.",ETO);
	tell_object(ETO,"%^YELLOW%^You release your hold of the rod, causing a thunderous boom to echo in the area.");
	return 1;
}
int hit_func(object targ){
	if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(targ)) return 1;
    if(random(1000) < 200)
    {
        switch(random(65))
        {
            default:
                tell_room(environment(query_wielded()),"%^YELLOW%^"+ETO->QCN+" delivers"+
                    " an electrical jolt to "+targ->QCN+" forcing "+targ->QO+" to"+
                    " recoil back.",({ETO,targ}));
                tell_object(ETO,"%^YELLOW%^You release a portion of the lightning"+
                    " housed within the rod into "+targ->QCN+".");
                tell_object(targ,"%^YELLOW%^"+ETO->QCN+" zaps you with an "+
                    "electrical jolt, causing you to recoil back.");
                return roll_dice(2,4)+1;
                break;

            case 60..65:
                tell_room(environment(ETO),"%^BOLD%^%^BLUE%^A blast of violent"+
                    " air shoots out of "+ETO->QCN+"'s rod, and slams "+
                    "into "+targ->QCN+".",({ETO,targ}));
                tell_object(ETO,"%^BOLD%^%^BLUE%^A blast of violet air"+
                    " shoots out of your rod and slams into "+targ->QCN+".");
                tell_object(targ,"%^BOLD%^%^BLUE%^"+ETO->QCN+" shoots a blast "+
                    "of violent air out of "+ETO->QP+" rod, which slams into you!");
                new("/cmds/spells/a/_airbolt")->use_spell(ETO,targ,20,100,"mage");
            break;
        }    
        return 1;
	}
}
