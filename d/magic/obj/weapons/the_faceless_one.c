//The Faceless One Weapon Spell

#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
    ::create();
    set_name("%^RESET%^%^BOLD%^%^BLACK%^I%^RESET%^%^MAGENTA%^nd%^RED%^omit%^MAGENTA%^abl%^BOLD%^%^BLACK%^e p%^RESET%^%^MAGENTA%^ur%^RED%^pos%^BOLD%^%^BLACK%^e%^RESET%^");
    set_short("%^RESET%^%^BOLD%^%^BLACK%^f%^RESET%^%^RED%^la%^MAGENTA%^w%^BOLD%^%^BLACK%^l%^RESET%^%^RED%^es%^BOLD%^%^BLACK%^s black b%^RESET%^%^RED%^lad%^BOLD%^%^BLACK%^e%^RESET%^");
    set_id(({ "weapon", "flawless black blade", "blade", "indomitable purpose" }));
    set_long("%^BOLD%^%^BLACK%^Plain %^RESET%^%^MAGENTA%^s%^RED%^i%^MAGENTA%^mplici%^RED%^t%^MAGENTA%^y %^BOLD%^%^BLACK%^is what catches your attention about this %^RESET%^%^RED%^u%^MAGENTA%^n%^RED%^usual %^MAGENTA%^weap%^RED%^o%^MAGENTA%^n%^BOLD%^%^BLACK%^. Th%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^n double edged blade itself being perfectly black feels like crafted as one with unusually %^RESET%^%^RED%^c%^MAGENTA%^o%^RED%^mfo%^MAGENTA%^rtab%^RED%^l%^MAGENTA%^e %^BOLD%^%^BLACK%^handle one may grip just to feel it. Two feet of the weapon's length are of f%^RESET%^%^RED%^la%^MAGENTA%^w%^BOLD%^%^BLACK%^l%^RESET%^%^RED%^es%^BOLD%^%^BLACK%^sl%^RESET%^%^RED%^y %^BOLD%^%^BLACK%^straight design, with only the tip breaking it. The blade would be perfectly plain if not for a small %^RESET%^%^RED%^r%^BOLD%^e%^RESET%^%^RED%^d e%^BOLD%^y%^RESET%^%^RED%^e %^BOLD%^%^BLACK%^in the middle of one of its sides %^RESET%^%^RED%^ever w%^MAGENTA%^a%^RED%^tching %^MAGENTA%^you%^BOLD%^%^BLACK%^. But, in the essence, everything speaks to the %^RESET%^%^RED%^p%^MAGENTA%^urpos%^RED%^e %^BOLD%^%^BLACK%^of this blade. %^RESET%^%^RED%^To %^MAGENTA%^end %^RED%^life.%^WHITE%^");
    set_damage_type("slashing");
    set_value(0);
    set_size(1);
    set_hit((: TO, "hit_func" :));
}

//ETO -- you
//targ->QCN -- target name
//ETO->QCN  -- your name

int hit_func(object targ)
{
    targ = ETO->query_current_attacker();
    if (!objectp(ETO)) {
        return 1;
    }
    if (!objectp(targ)) {
        return 1;
    }

    if (!random(10)) {
//targ->QCN
        tell_object(ETO, "%^RED%^With unnatural strength and determination you plunge the dagger into " + targ->QCN + ".");
        tell_object(targ, "%^RED%^" + ETO->QCN + "'s blade pierces your flesh with otherworldly strength");
        tell_room(environment(ETO), "%^RED%^" + ETO->QCN + " serenely pierces " + targ->QCN + "'s flesh with the thin blade.", ({ ETO, targ }));
        return random(4) + 8;
    }
}
