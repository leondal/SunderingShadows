#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("petrified staff");
	set_id(({ "staff", "gorgon's staff", "quarterstaff", "petrified staff" }));
	set_short("%^BOLD%^%^RED%^The %^BLACK%^Gorgon's%^BLACK%^ Staff%^RESET%^");
	set_obvious_short("A stone grey petrified staff");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Made of what looks to be stone at first, this petrified wood staff is about six feet long.  The petrified wood still carries some uneven texture to it, giving a rough quality to this staff.  Mounted at the top of the staff is the minature carving of a bull's head in marble.  The bull's head features what looks to be rune encrusted horns.  The eyes of the bull have been painted a deep %^RED%^red%^BLACK%^ color.  It looks as if a sneer has been etched on the bull's face, giving it an angry unhappy look.  A collar of %^WHITE%^ivory%^BLACK%^ rests around the bull's neck and looks to be how the carving is mounted to the staff.

AVATAR
	);
	set_weight(7);
	set_value(1200);
	set_lore(
@AVATAR
The Gorgon's Staff is rumored to grant one a minor mastery over the earth.  It is said that the staff was petrified by a gorgon's breath, and that Tandelunias, a geomancer mage of Grumbar, then bathed the staff in the gorgon's blood.  The resourceful mage though it seems is rumored to have been able to shrink down the gorgon's head and preserved it magically, thus topping this odd staff.

AVATAR
	);
	set_property("lore",12);
	set_type("bludgeoning");
	set_prof_type("staff");
	set_size(3);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",3+random(2));
	set_ac(2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" wraps both hands around the stone grey staff.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You wrap both hands around the hefty staff, feeling how solid it is.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" looks rather happy to have a rest from wielding the stone staff.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You unwield the staff, giving your hands a rest from the solid staff.");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^ORANGE%^"+ETOQCN+" looks to "+targ->QCN+" as their staff crumbles away to a pile of levitating stones.  The stones fly out to bash "+targ->QCN+" before the staff reforms in "+ETOQCN+" 's hands!",({ETO,targ}));
	tell_object(ETO,"%^ORANGE%^The bull's eyes begin to glow %^RED%^red%^ORANGE%^ and shimmer causing the staff to crumble in your hands into a pile of levitating stones.  The stones fly out to "+targ->QCN+" and bash them soundly.  In an instant the staff %^RED%^reforms%^ORANGE%^ in your hands!");
	tell_object(targ,"%^ORANGE%^"+ETOQCN+" looks to you  as their staff crumbles away to a pile of levitating stones.  The stones fly out to bash you soundly before the staff reforms in "+ETOQCN+" 's hands!");
		set_property("magic",1);
		return roll_dice(3,4)+1;
		set_property("magic",-1);
	}
}