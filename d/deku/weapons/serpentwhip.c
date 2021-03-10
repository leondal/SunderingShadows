#include <std.h>
inherit "/d/common/obj/weapon/whip.c";

void create(){
	::create();
	set_name("whip");
	set_id(({ "whip", "serpent", "serpent whip" }));
	set_short("%^RESET%^%^GREEN%^Serpent Whip%^RESET%^");
	set_obvious_short("A snakelike whip");
	set_long("%^GREEN%^This whip is not like most whips.  Instead it seems that it is made up "+
		"of four snakeheads that slither about!  The handle of the whip is made out of "+
		"%^WHITE%^%^BOLD%^silver%^RESET%^%^GREEN%^ and features a serpentine like design etched "+
		"into the metal.%^RESET%^");
	set_value(300);
	set_lore("The Serpent Whip is an icon of a Drow Matron's control of her family as well as "+
		"the female drow's symbol of their place within the faith of Lloth, the Spider Queen.");
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
	//set_item_bonus("damage bonus", 1);
	set_item_bonus("attack bonus", 1);
}
int wield_func(){
	tell_room(EETO,ETO->QCN+"%^GREEN%^ looks unnerved as the whip appears ready to bite the "+
		"hand that wields it.%^RESET%^",ETO);
	tell_object(ETO,"%^GREEN%^The snakes look as if they are ready to bite you, but quickly "+
		"seem to accept your touch.%^RESET%^");
	return 1;
}

int unwield_func(){
	tell_room(EETO,"%^GREEN%^You hear the hissing of snakes.%^RESET%^",ETO);
	tell_object(ETO,"%^GREEN%^The snakes hiss as you release the whip.%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(random(1000) < 200){
	tell_room(EETO,"%^BOLD%^%^GREEN%^One of the serpents on "+ETO->query_cap_name()+"%^BOLD%^"+
		"%^GREEN%^'s whip bites "+targ->query_cap_name()+"%^BOLD%^%^GREEN%^ and does not want to "+
		"let go!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^GREEN%^One of the serpents bites "+targ->query_cap_name()+"%^BOLD%^"+
		"%^GREEN%^ and does not want to let go!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^GREEN%^One of the serpents on "+ETO->query_cap_name()+"%^BOLD%^"+
		"%^GREEN%^'s whip bites you and does not want to let go!%^RESET%^");
	return roll_dice(2,4)+0;	}
}