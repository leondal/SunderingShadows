#include <std.h>
inherit "/d/common/obj/weapon/club_lg.c";

void create(){
	::create();
	set_name("stone rod");
	set_id(({ "rod", "stone rod" }));
	set_short("%^RESET%^%^ORANGE%^S%^BOLD%^%^BLACK%^"+
		"t%^RESET%^o%^ORANGE%^n%^BOLD%^%^BLACK%^e"+
		"%^RESET%^%^ORANGE%^ Rod%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A large "+
		"%^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^"+
		"o%^RESET%^n%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^ rod");
	set_long(
@AVATAR
%^ORANGE%^This large rod, about four feet tall, is made up of bits of stones infused together.  Granite, Marble, Limestone, and Quartz are just a few that you can make out in this club.  The rod appears to tapper down to a smaller width, possibly a handgrip of sorts.  The massive club is heavy, giving a feeling as if it would make an effective weapon.

AVATAR
	);
	set_weight(9);
	set_value(1100);
	set_lore(
@AVATAR
The Stone Rod is made by priests of Grumbar, who collect a wide collection of rocks and then with the blessings of the Earthlord, infuse them together.  These weapons are alway popular with the faith

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
	tell_room(environment(ETO),"%^ORANGE%^"+ETO->QCN+" hefts up a heavy rod made of stone.",ETO);
	tell_object(ETO,"%^ORANGE%^You heft up the heavy rod, feeling the various textures of rocks.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^ORANGE%^You release the weapon.");
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
            tell_room(environment(query_wielded()),"%^ORANGE%^"+targ->QCN+""+
                " screams out in pain, after "+ETO->QCN+" delivers a bone"+
                " crushing blow to "+targ->QS+".",({ETO,targ}));
            tell_object(ETO,"%^ORANGE%^You swing a solid blow into "+targ->QCN+""+
                ", almost feeling as if the rod itself is granting you the"+
                " strength of the earth.");
            tell_object(targ,"%^ORANGE%^"+ETO->QCN+" delivers a crushing blow to you!");
            return roll_dice(3,4)+1;

        case 60..64:	
            tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" slams "+
                ""+ETO->QP+" rod into the ground, spraying "+targ->QCN+""+
                " with pebbles and stones.",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^BLACK%^You slam your club into the "+
                "ground, spraying "+targ->QCN+" with pebbles and stones.");
            tell_object(targ,"%^BOLD%^%^CYAN%^"+ETO->QCN+" slams his "+
                ""+ETO->QP+" rod into the ground, spraying you with"+
                " pebbles and stones!");
            new("/cmds/spells/e/_earth_reaver")->use_spell(ETO,targ,20,100,"cleric");
            break;
        }
    }
   	return 1;	
}
	
