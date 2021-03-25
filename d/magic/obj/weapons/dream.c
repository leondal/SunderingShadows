#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
    ::create();
    set_name("%^RESET%^%^CYAN%^W%^BOLD%^%^BLUE%^h%^CYAN%^i%^BLUE%^p %^RESET%^%^CYAN%^of the %^BOLD%^%^BLUE%^D%^CYAN%^r%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^a%^CYAN%^m%^BOLD%^%^BLUE%^s%^RESET%^");
    set_short("%^RESET%^%^CYAN%^W%^BOLD%^%^BLUE%^h%^CYAN%^i%^BLUE%^p %^RESET%^%^CYAN%^of the %^BOLD%^%^BLUE%^D%^CYAN%^r%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^a%^CYAN%^m%^BOLD%^%^BLUE%^s%^RESET%^");
    set_id(({ "weapon", "whip", "whip of the waves" }));
    set_long("%^RESET%^%^CYAN%^Mystically fashioned from pure %^BOLD%^%^BLUE%^water%^RESET%^%^CYAN%^, this swirling whip is held in a tight formation. The water ebbs and flows in a continuous fashion, always in a state of wave-like motions. The pure %^BOLD%^%^BLUE%^water%^RESET%^%^CYAN%^ shifts in hues of %^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^l%^BOLD%^u%^RESET%^%^BLUE%^e%^BOLD%^s%^RESET%^%^CYAN%^ and %^CYAN%^g%^GREEN%^r%^CYAN%^e%^GREEN%^e%^CYAN%^n%^GREEN%^s%^RESET%^%^CYAN%^, from %^BLUE%^dark blue%^RESET%^%^CYAN%^ to %^CYAN%^sea green%^RESET%^%^CYAN%^ to %^BOLD%^%^CYAN%^azure blue%^RESET%^%^CYAN%^, reflecting the many shades of the sea.");
    set_value(0);
    set_damage_type("slashing");
    set_hit((: TO, "hit_func" :));
}

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
        tell_object(ETO, "%^CYAN%^Your whip lashes into " + targ->QCN + ", cutting into " + targ->QP + " flesh.");
        tell_object(targ, "%^CYAN%^%^" + ETO->QCN + "'s whip lashes into you, cutting into your flesh!");
        tell_room(environment(ETO), "%^CYAN%^%^" + ETO->QCN + "'s whip lashes into " + targ->QCN + ", cutting into " + targ->QP + " flesh!", ({ ETO, targ }));

        return random(4)+4;
    }
}
