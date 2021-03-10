#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("shark tooth");
	set_id(({ "tooth", "shark tooth", "dagger", "shark tooth dagger" }));
	set_short("%^BOLD%^%^BLACK%^Sh%^RESET%^a%^BOLD%^%^BLACK%^rk%^WHITE%^ T%^RESET%^oo%^BOLD%^%^WHITE%^th %^BLACK%^D%^RESET%^a%^BOLD%^%^BLACK%^gg%^RESET%^e%^BOLD%^%^BLACK%^r%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^large shark tooth%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Shaped much like a arrowhead, this dagger's tip looks like it might be made from a very large %^RESET%^grayish-white %^BOLD%^%^BLACK%^shark's tooth.  A slight %^WHITE%^i%^BLACK%^r%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^de%^WHITE%^s%^BLACK%^c%^CYAN%^e%^BLACK%^nt g%^WHITE%^l%^RESET%^e%^CYAN%^a%^BOLD%^%^BLACK%^m highlights the long, wicked curve which ends in a nasty, razor sharp point.  A strip of %^RESET%^%^ORANGE%^rawhide %^BOLD%^%^BLACK%^has been used to attach a handle of smooth, carved driftwood to the base of the tooth, transforming it into a crude but dangerous weapon.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(500);
	set_lore(
@AVATAR
Tales abound of the danger of shark attacks and the fierceness of their bite due to the shark's sharp teeth.  And many are the rumor of great beasts that can be found deeper in the ocean, which put these lesser cousins to shame.  Every now and again a tooth will wash up on shore in the remains of a dead animal or be found by someone in their nets, the size of these teeth fiercely dwarfing that of an average shark.  It is these find which lead to such legends.  Although proof that there might be truth to the rumors seems to lie within your hand.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,3);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The %^RESET%^"+query_short()+" %^BOLD%^%^BLACK%^glints %^RED%^hungrily %^BLACK%^in the light as "+ETOQCN+" wields it.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RESET%^"+query_short()+" %^BOLD%^%^BLACK%^glints %^RED%^hungrily %^BLACK%^in the light as you wield it.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The curve of "+ETOQCN+"'s %^RESET%^"+query_short()+" %^BOLD%^%^BLACK%^glints with promise as they tuck it away for now.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The curve of your %^RESET%^"+query_short()+" %^BOLD%^%^BLACK%^glints with promise as you tuck it away for now.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^RESET%^%^RED%^The %^RESET%^"+query_short()+"%^RESET%^%^RED%^ wielded by "+ETOQCN+" bites into "+targ->QCN+"'s exposed flesh!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^RED%^The %^RESET%^"+query_short()+" %^RESET%^%^RED%^bites sharply into "+targ->QCN+"'s exposed flesh, tearing out a great chunk!%^RESET%^");
	tell_object(targ,"%^RESET%^%^RED%^You cry out as "+ETOQCN+"'s %^RESET%^"+query_short()+" %^RESET%^%^RED%^rips a piece of your exposed flesh away!%^RESET%^");
		return roll_dice(2,3)+0;	}
}