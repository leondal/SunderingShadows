#include <std.h>
inherit "/d/common/obj/weapon/battle_axe.c";

void create(){
	::create();
	set_name("steel battleaxe");
	set_id(({ "axe", "steel axe", "steel battleaxe", "battleaxe", "battle axe", "steel battle axe" }));
	set_obvious_short("A steel battleaxe");
	set_short("%^BOLD%^%^WHITE%^A st%^RESET%^e%^BOLD%^el "+
    "battleaxe%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^This large and heavy axe is "+
    "made from a solid piece of steel.  The double head of the "+
    "axe is a slightly %^BOLD%^%^BLACK%^darker%^BOLD%^%^WHITE%^ "+
    "hue and is nicked in several spots along the blades, an "+
    "ever present evidence of the amount of use it has seen.  "+
    "The handle of the axe has a wide and deep groove that "+
    "runs down its length, the purpose of which is a complete "+
    "mystery.  The end of the handle is slightly discolored "+
    "and tainted with darker flecks of metal.  It eventually "+
    "mushrooms out and then rounds off.%^RESET%^");

	set_value(1000);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
	set_item_bonus("attack bonus", 1);
}
int wield_func(){
	tell_room(EETO,ETOQCN+"%^RED%^ looks around, preparing for "+
    "battle.%^RESET%^",ETO);
	tell_object(ETO,"%^RED%^You take the axe by "+
    "its %^BLUE%^cold%^RED%^ handle and prepare for battle."+
    "%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(EETO,ETOQCN+"%^RED%^ releases the axe.%^RESET%^",ETO);
	tell_object(ETO,"%^RED%^You release the %^BLUE%^cold%^RESET%^ "+
    "handle of the axe.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 200){
	    tell_room(EETO,ETOQCN+"%^BOLD%^%^GREEN%^ buries "+ETO->QP+
        " axe deep into "+targ->QCN+"%^BOLD%^%^GREEN%^'s "+
        "%^RED%^flesh!%^RESET%^",({ETO,targ}));

	    tell_object(ETO,"%^BOLD%^%^GREEN%^You bury your axe "+
        "deep into "+targ->QCN+"%^BOLD%^%^GREEN%^'s %^RED%^"+
        "flesh%^BOLD%^%^GREEN%^!%^RESET%^");

	    tell_object(targ,"%^BOLD%^%^GREEN%^You scream in pain "+
        "as "+ETOQCN+"%^BOLD%^%^GREEN%^ buries "+ETO->QP+
        " axe deep into your %^RED%^flesh%^BOLD%^%^GREEN%^!"+
        "%^RESET%^");
	    return roll_dice(1,2)+2;
    }
}
