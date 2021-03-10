// This is the avenger for Paladins who are HM and complete paladin quest
// which will be in the drow temple...next area i code. It is the same as
// the avenger wielded by the solar(/d/dagger/drow/mon/solar.c) but does
// not contain the id check(to only allow the solar to wield it)
// Now it contains my imms name...i plan to award this sword to HM
// Paladins who complete the quest. At this point i will have their player
// name in the check so only they can wield it and will create it as an
// independent file...clone it and give it to them. This is the best way
// I see of ensuring no one but a HM paladin who solves the quest can ever
// wield it. So in this respect this sword is not being submitted at this
// time as an item to be added into the game. Only the avenger the solar 
// wields (/d/dagger/drow/obj/avenger.c) is. The sword the solar wields
// is unwieldable by any player unless their name was solar.

#include <std.h>
inherit "/std/weapon";
create() {
    ::create();
    set_name("avenger");
    set_id(({"holy avenger","avenger"}));
    set_short("%^BOLD%^%^WHITE%^Holy Avenger%^RESET%^");
    set_long(
	"%^WHITE%^%^BOLD%^This is the Holy Avenger of the Order of "
	"Paladins. Besides being a tool of destruction against evil "
	"beings, it lends magical protection to the wielder.%^RESET%^"
    );
    set_weight(5);
    set_size(2);
    set_value(5000);
    set_wc(1,8);
    set_large_wc(1,12);
    set_type("slashing");
    set_property("enchantment",5);
    set_wield ( (: TO, "paladin" :) );
    set_hit ( (: TO, "extra_hit" :) );
}
int paladin() {
    if((string)TP->query_name() !="grazzt") {
    write(
	"%^WHITE%^%^BOLD%^You are not able to wield such a fine "
	"weapon!%^RESET%^"
    );
    return 0;
    }
return 1;
}
int extra_hit() {
    object ob;
    int dam,FLAG;
    FLAG = 0;
    ob = ETO->query_current_attacker();
    if( random(100) > 80) {
    if((string)ob->query_alignment() == "chaotic evil") {
    FLAG = 1;
    dam=dam+random(10)+1;
    }
     if((string)ETO->query_name() != "solar") {
	dam=dam+random(15)+10;
    }
    dam=dam+random(10)+5;
    tell_object(ETO,
	"%^WHITE%^%^BOLD%^The sword channels your %^MAGENTA%^holy energy"
   "%^WHITE%^ into its swing!"
	"\n%^BOLD%^%^CYAN%^A bright %^RED%^flash%^CYAN%^ is seen as you "
	"slash at "+ob->query_cap_name()+"!%^RESET%^"
    );    
if (FLAG == 1) {
    tell_object(ETO,
        "\n%^RED%^%^BOLD%^The Avenger tells you: I detect great evil in "
	"our foe.%^RESET%^"
    );
    }
    tell_room(environment(query_wielded()),
    "%^WHITE%^%^BOLD%^The sword wielded by "+ETO->query_cap_name()+" %^MAGENTA%^"
	"sings %^WHITE%^out to the heavens!"
    "\n%^BOLD%^%^CYAN%^A bright %^RED%^flash%^CYAN%^ is seen as "+ETO->query_cap_name()+
        "slashs at "+ob->query_cap_name()+"!%^RESET%^" 
    ,({ETO, ob}));
    tell_object(ob,
        "%^WHITE%^%^BOLD%^The sword wielded by "+ETO->query_cap_name()+" %^MAGENTA%^"
	"sings %^WHITE%^out to the heavens!"
    "\n%^BOLD%^%^CYAN%^A bright %^RED%^flash%^CYAN%^ is seen as "+ETO->query_cap_name()+
        "slashs at you!%^RESET%^"
    );
    return dam;
} else {
    dam=1;
    return dam;
}
}
