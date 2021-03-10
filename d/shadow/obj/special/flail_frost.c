#include <std.h>
inherit "/d/common/obj/weapon/flail";

void create(){
	::create();
	set_name("flail of frost");
	set_id(({ "flail", "weapon", "flail of frost" }));
	set_short("%^BOLD%^%^BLUE%^Flail of frost%^RESET%^");
	set_obvious_short("A flail");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This flail has a handle made out of wood that has been colored a light blue.  The chain and the ball are both made from mithril and look as though they would never break.  Across the length of the handle there are white dwarven runes.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
These runes are ancient and beyond your understanding.

AVATAR
	);
	set_weight(15);
	set_value(500);
	set_lore(
@AVATAR
Crafted by the dwarves of mount Uruzbandum, these flails are known to be unbreakable.  Most of them were lost when the dwarven home was raided and destroyed by an orc army, but some have reached the surface world.

AVATAR
	);
	set_type("bludgeoning");
	set_prof_type("flail");
	set_size(2);
	//changed to inherit the common flail - Saide
	//set_wc(1,7);
	//set_large_wc(2,4);
	set_property("enchantment",1);
	set_ac(1);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 300){
	tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETOQCN+"'s flail flashes in a "+
         "bright %^WHITE%^white light %^BLUE%^as it hits "+targ->QCN+""+
         "!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^The flail flashes in a bright "+
         "%^WHITE%^white light %^BLUE%^as it hits "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLUE%^"+ETOQCN+"'s flail flashes in "+
         "a bright %^WHITE%^white light%^BLUE%^ as it hits you!%^RESET%^");
		return roll_dice(2,3)+0;	}
}