//The Faceless One Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns_knights";

void create()
{
    ::create();
    set_name("%^BOLD%^%^BLACK%^Wi%^RESET%^%^RED%^c%^WHITE%^k%^RED%^e%^BOLD%^%^BLACK%^d " +
             "%^RESET%^%^RED%^L%^WHITE%^i%^BOLD%^%^BLACK%^tt%^RESET%^%^RED%^l%^BOLD%^%^BLACK%^e L" +
             "%^RESET%^%^RED%^i%^WHITE%^e%^BOLD%^%^BLACK%^s%^RESET%^");
    set_short("%^BLUE%^s%^BOLD%^h%^RESET%^%^ORANGE%^i%^BOLD%^f%^RESET%^t%^BOLD%^i%^BLACK%^ng " +
              "%^WHITE%^f%^BLUE%^r%^BLACK%^a%^RESET%^%^RED%^c%^BOLD%^%^WHITE%^t%^BLACK%^a%^RESET%^%^RED%^l " +
              "%^BOLD%^%^BLACK%^s%^RESET%^w%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^r%^WHITE%^d");
    set_id(({ "blade", "sword", "wicked little lies", "weapon" }));
    set_long("%^BOLD%^%^BLACK%^This %^ORANGE%^s%^WHITE%^hi%^RESET%^ft%^BOLD%^%^BLUE%^i" +
             "%^RESET%^%^BLUE%^ng %^BOLD%^%^BLACK%^%^BOLD%^%^BLACK%^s%^RESET%^w%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^r%^WHITE%^d"
             " is in constant flux, moving almost like " +
             "%^RESET%^s%^BOLD%^%^BLACK%^mo%^RESET%^k%^BOLD%^%^BLACK%^e or, it never holds the exact " +
             "same shape or color. What could be considered the 'hilt' of the %^BOLD%^%^BLACK%^s%^RESET%^w%^BOLD%^%^BLACK%^o"
             "%^RESET%^%^RED%^r%^WHITE%^d consists of%^RESET%^%^BOLD%^%^BLACK%^a longer, %^CYAN%^thi" +
             "%^RESET%^%^CYAN%^nne%^WHITE%^r %^BOLD%^%^BLACK%^section of the substance that %^WHITE%^c" +
             "%^RESET%^%^BLUE%^o%^YELLOW%^n%^WHITE%^st%^RESET%^%^BLUE%^a%^YELLOW%^n%^BLACK%^t%^WHITE%^l" +
             "%^BLACK%^y pulses with %^WHITE%^s%^ORANGE%^w%^BLACK%^i%^WHITE%^r%^BLUE%^l%^BLACK%^s of " +
             "%^RESET%^%^MAGENTA%^d%^BOLD%^a%^RESET%^r%^BOLD%^%^BLACK%^k energy. The blade-type portion " +
             "is made of the same fluid-type substance, substantially wider and flatter, that " +
             "%^ORANGE%^s%^RESET%^%^BLUE%^h%^WHITE%^i%^BOLD%^%^BLACK%^f%^WHITE%^t%^BLACK%^s and " +
             "%^RESET%^%^RED%^p%^BOLD%^%^BLACK%^u%^WHITE%^l%^BLACK%^s%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^s " +
             "in the wielder's grip.  ");
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
        tell_object(ETO, "%^BOLD%^%^BLACK%^The %^RESET%^%^ORANGE%^s%^BOLD%^%^WHITE%^hi%^RESET%^ft" +
                    "%^BOLD%^%^BLUE%^in%^RESET%^%^BLUE%^g %^BOLD%^%^BLACK%^%^BOLD%^%^BLACK%^s%^RESET%^w%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^r%^WHITE%^d"
                    " extends and shoots numerous " +
                    "t%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^n%^WHITE%^d%^RESET%^%^MAGENTA%^r%^BOLD%^%^WHITE%^i" +
                    "%^BLACK%^l%^RESET%^%^MAGENTA%^s %^BOLD%^%^BLACK%^into %^RESET%^%^RED%^" + targ->QCN + "%^RESET%^");
        tell_object(targ, "%^BOLD%^%^BLACK%^The %^RESET%^%^ORANGE%^s%^BOLD%^%^WHITE%^hi%^RESET%^ft" +
                    "%^BOLD%^%^BLUE%^in%^RESET%^%^BLUE%^g %^BOLD%^%^BLACK%^%^BOLD%^%^BLACK%^s%^RESET%^w%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^r%^WHITE%^d"
                    " wielded by %^BLUE%^" + ETO->QCN + " %^BLACK%^extends " +
                    "and shoots numerous t%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^n%^WHITE%^d%^RESET%^%^MAGENTA%^r%^BOLD%^%^WHITE%^i" +
                    "%^BLACK%^l%^RESET%^%^MAGENTA%^s %^BOLD%^%^BLACK%^into %^RESET%^%^RED%^you!%^WHITE%^");
        tell_room(environment(ETO), "%^BOLD%^%^BLACK%^The %^RESET%^%^ORANGE%^s%^BOLD%^%^WHITE%^hi" +
                  "%^RESET%^ft%^BOLD%^%^BLUE%^in%^RESET%^%^BLUE%^g %^BOLD%^%^BLACK%^%^BOLD%^%^BLACK%^s%^RESET%^w%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^r%^WHITE%^d"
                  " wielded by %^BLUE%^" + ETO->QCN + " %^BLACK%^ext" +
                  "ends and shoots numerous t%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^n%^WHITE%^d%^RESET%^%^MAGENTA%^r%^BOLD%^%^WHITE%^i" +
                  "%^BLACK%^l%^RESET%^%^MAGENTA%^s %^BOLD%^%^BLACK%^into %^RESET%^%^RED%^" + targ->QCN + "!%^WHITE%^", ({ ETO, targ }));

        return random(4) + 8;
    }
}
