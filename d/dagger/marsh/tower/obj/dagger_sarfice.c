#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";

void create(){
	::create();
	set_name("finely made dagger");
	set_id(({ "dagger", "sacrifical curved dagger", "finely made dagger", "curved dagger" }));
	set_short("%^BOLD%^%^BLUE%^S%^BLACK%^acrificial %^BLUE%^C%^BLACK%^urved %^BLUE%^D%^BLACK%^agger%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^a %^BOLD%^%^BLACK%^f%^BOLD%^%^BLUE%^i%^RESET%^n%^BOLD%^%^BLACK%^e%^BLUE%^l%^BLACK%^y m%^BLUE%^a%^RESET%^%^BLUE%^d%^BOLD%^%^BLACK%^e %^RESET%^%^CYAN%^straight dagger%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^This highly decorated weapon is forged with a titanium core steal which gives the blade an impressive soundness, even under the most grievous of pressures.  A dark %^BOLD%^%^BLACK%^g%^RESET%^%^BLUE%^r%^BOLD%^a%^BLACK%^y-b%^RESET%^%^BLUE%^l%^BOLD%^u%^BLACK%^e %^RESET%^%^CYAN%^in color, the dagger is lined with several hooked teeth along its back edge, the better to rip wounds open with.  The dagger is acid etched with intricate swirls and ridges that follow the length of the weapon and only taper away when they reach the %^RED%^razor edge%^CYAN%^.  The hilt of this spectacular weapon is gilded in %^ORANGE%^gold%^CYAN%^, %^BOLD%^%^WHITE%^platinum %^RESET%^%^CYAN%^and %^YELLOW%^topaz%^RESET%^%^CYAN%^, including the large diamond cut gem that forms the pommel of the blade. A designer's piece to be sure, it would fetch a high price or cut a man's throat equally well.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(1400);
	set_lore(
@AVATAR
Creator of this dagger remains unknown even to the Arch Lich of The Demonsgate. It is rumored it had been forged in ancient times by master smiths and necromancers of assassin guild long since gone. This void touched dagger is embedded with magic of decay. It will harm the opponent int various ways.
AVATAR
	);
	set_property("lore difficulty",40);
	//set_type("piercing");
	//set_prof_type("simple");
	//set_size(1);
	//set_wc(1,4);
	//set_large_wc(1,4);
	set_property("enchantment",5);
    set_item_bonus("dexterity",4);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ))
        return 0;
	if(!objectp(ETO))
        return 0;
    if(!(random(8)))
    {
        switch(random(20))
        {
        case 0..15:
            tell_room(environment(query_wielded()),"%^YELLOW%^"+ETOQCN+"'s "+query_short()+"%^YELLOW%^ rips and tears "+targ->QCN+"'s flesh as it cuts deep!%^RESET%^",({ETO,targ}));
            tell_object(ETO,"%^YELLOW%^Your blade rips and tears "+targ->QCN+"'s flesh as it cuts deep!%^RESET%^");
            tell_object(targ,"%^YELLOW%^"+ETOQCN+"'s "+query_short()+"%^YELLOW%^ rips and tears your flesh as it cuts deep!%^RESET%^");
            return roll_dice(2,8)+1;
            break;
        case 16..17:
            tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^"+ETOQCN+"'s "+query_short()+"%^BOLD%^%^BLUE%^ blast into "+targ->QCN+" with ray of chill!%^RESET%^",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^BLUE%^Your blade discharges blast of chillinto "+targ->QCN+"!%^RESET%^");
            tell_object(targ,"%^BOLD%^%^BLUE%^"+ETOQCN+"'s "+query_short()+"%^BOLD%^%^BLUE%^ discharges blast of chill into you!%^RESET%^");
            "/std/effect/status/fatigued"->apply_effect(targ,random(2)+1);
            return 1;
            break;
        case 18..19:
            tell_room(environment(query_wielded()),"%^BOLD%^%^GREEN%^"+ETOQCN+"'s "+query_short()+"%^BOLD%^%^GREEN%^ blast into "+targ->QCN+" with fell power!%^RESET%^",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^GREEN%^Your blade discharges fell power into "+targ->QCN+"!%^RESET%^");
            tell_object(targ,"%^BOLD%^%^GREEN%^"+ETOQCN+"'s "+query_short()+"%^BOLD%^%^GREEN%^ discharges fell power into you!%^RESET%^");
            "/std/effect/status/sickened"->apply_effect(targ,random(2)+1);
            return 1;
            break;

        }
    }
}
