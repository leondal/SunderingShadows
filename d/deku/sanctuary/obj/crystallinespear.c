//Updated to bring in line with area difficulty - Octothorpe 4/15/10

#include <std.h>
inherit "/d/common/obj/weapon/spear_sm.c";

void create(){
	::create();
	set_name("crystalline spear");
	set_id(({ "spear", "short spear", "crystalline spear" }));
	set_short("%^RESET%^%^CYAN%^Crystalline Spear%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^A short spear with a crystal tip%^RESET%^");
	set_long(
@AVATAR
%^CYAN%^Aged %^RESET%^birch wood%^CYAN%^ is used to make the shaft of this spear.  The birch wood has a soft white hue to it with ash grey swirls.  This short spear is about two feet long, looking like something a halfling or gnome might use.  The tip of the spear is made from a pale teal crystal.  The crystal has been shaped into a diamond shape, typical for most spears.  The many facets of the crystal have been left raw and untreaded, giving it a slightly cloudy appearance.  Though the crystal still looks very sharp.

AVATAR
	);
	set_weight(4);
	set_value(300);
	set_lore(
@AVATAR
The crystalline spear is a weapon that has been commonly used in the city of Sanctuary, before the undead horde.  A popular druid of Silvanus, Yalderna, favored such a weapon when he needed to do combat with the followers of Talos, the Storm Lord.  Those that came to be smitten or enthralled by Yalderna's heroic acts soon started to emulate him.  It is not uncommon to still see people talk about the Crystal Thorn of Silvanus, as Yalderna was known to his admires.

AVATAR
	);
	set_property("lore",10);
	set_property("enchantment",3+random(2));
      set_item_bonus("attack bonus",1);
      set_item_bonus("damage bonus",1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" wield a crystal tipped spear in one hand.",ETO);
	tell_object(ETO,"%^CYAN%^You wrap your hand around the spear, watching as the crystal tip seems to become less cloudy.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" unwields the crystal tipped spear.",ETO);
	tell_object(ETO,"%^CYAN%^You unwield the spear, causing the crystal to grow cloudy again.");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 275){
	tell_room(environment(query_wielded()),"%^CYAN%^"+ETOQCN+" slips the tip of their spear into "+targ->QCN+" 's flesh, looking to pass through their defenses with ease.",({ETO,targ}));
	tell_object(ETO,"%^CYAN%^The tip of the spear slips easily into "+targ->QCN+" 's flesh, looking to pass through their defenses with ease.");
	tell_object(targ,"%^CYAN%^"+ETOQCN+" slips the tip of their spear into your flesh, looking to pass through their defenses with ease.");
		return roll_dice(2,4)+2;	}
}