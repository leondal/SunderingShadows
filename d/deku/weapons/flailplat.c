#include <std.h>
inherit "/d/common/obj/weapon/flail.c";

void create(){
	::create();
	set_name("platinum flail");
	set_id(({ "flail", "weapon" }));
	set_short("%^RESET%^platinum flail");
        set_obvious_short("a flail");
	set_long("%^BOLD%^%^WHITE%^The mithril handle of this flail is about three feet but weighs very little. The chain that's between the platinum spike ball and the handle is also mithril. The ball seems to give off a dim light, and the spikes glow a bit brighter.%^RESET%^");
	set_value(2000);
	set_lore("The handles and chains of the platinum flails where crafted by dwarves and sold to an order of human mages in Farwest. The mages had been paid well to create these weapons for the guard of the high king, and they did a good job. The empire eventually fell but most of the flails where found and sold off in various directions.");
    set_property("enchantment",3);
    set_item_bonus("ac bonus", 1);
    set_wield((:TO,"wield_me":));
    set_unwield((:TO,"unwield_me":));
    set_hit((:TO,"hit_func":));
}

int wield_me() {
 tell_object(ETO,"%^BOLD%^%^WHITE%^You feel a protection flow over you from the flail!%^RESET%^");
 return 1;
}

int unwield_me() {
 tell_object(ETO,"%^BOLD%^%^WHITE%^You feel a protection leave you.%^RESET%^");
 return 1;
}

int hit_func(object targ){
	if(random(1000) < 200){
	tell_room(EETO,"%^WHITE%^%^BOLD%^The ball on "+ETO->QCN+"'s flail speeds up, swings around an extra time and impacts heavily upon "+targ->QCN+"%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^WHITE%^%^BOLD%^The ball on the flail speeds up, swings around an extra time and impacts heavily upon "+targ->QCN+"%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->QCN+"'s flail blurs, then smashed into you!%^RESET%^");
		targ->set_paralyzed(roll_dice(2,2)+0);
return 0;	}
}
