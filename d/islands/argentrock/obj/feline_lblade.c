//Feline's Grace -- Yves
#include <std.h>
inherit "/d/common/obj/weapon/shortsword.c";

void create()
{
    ::create();
    set_name("elven lightblade");
    set_short("%^BOLD%^%^BLACK%^Fel%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^ne's Gra%^RESET%^%^BLUE%^c%^BOLD%^%^BLACK%^e%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^An elven lightblade%^RESET%^");
    set_id(({
        "sword",
        "blade",
        "lightblade",
        "elven lightblade",
        "feline's grace",
        "felines grace",
    }));
    set_long(
        "%^BOLD%^%^BLACK%^This shortsword like exotic weapon seems impossibly thin and "
        "long for its weight. It tapers to a needle-like point, with a "
        "curve to the leading edge that is distinctly %^RESET%^%^CYAN%^elven%^BOLD%^%^BLACK%^. The front "
        "edge of the blade is sharpened along its entire length, and the "
        "back edge is sharpened only for the final quarter near the tip. "
        "It has a basket shaped hilt that resembles various jungle ca%^RESET%^%^BLUE%^t%^BOLD%^%^BLACK%^s, "
        "a long grip, and a heavy pommel. This weapon is intended for "
        "thrusting attacks but is quite capable of slashing as well.%^RESET%^\n"
        );
    set_lore(
        "%^BOLD%^%^BLACK%^The %^RESET%^%^CYAN%^elven%^BOLD%^%^BLACK%^ thinblades and lightblades of %^RESET%^%^GREEN%^Argentrock%^BOLD%^%^BLACK%^ are crafted "
        "using a special process that involves heating the %^CYAN%^mithril%^BLACK%^ near "
        "its melting point and folding the metal on top of itself before "
        "stretching it long and thin. The process is repeated over and "
        "over until the desired width and length are achieved. Once the "
        "%^CYAN%^blades%^BLACK%^ have been crafted they are imbued with elements of "
        "nature that are brought forth once again when a %^WHITE%^pure%^BLACK%^ hearted "
        "being takes up the blade.%^RESET%^"
        );
    set_property("lore", 13);
    set_property("enchantment", 4);
    set_item_bonus("caster level", 1);
    set_special_material_type("silver");
    set_hit((: TO, "hitme" :));
    set_value(2000);
    set_wield((: TO, "wield_func" :));
    set_unwield((: TO, "unwield_func" :));
}

int wield_func(string str)
{
    if (ALIGN->is_evil(ETO)) {
        tell_object(ETO,
                    "%^BOLD%^%^BLACK%^The ca%^RESET%^%^BLUE%^t%^BOLD%^%^BLACK%^s on the hilt %^RESET%^%^RED%^snarl%^BOLD%^%^BLACK%^ and refuse to bond with one "
                    "such as you.%^RESET%^"
                    );
        return 0;
    }
    tell_object(ETO,
                "%^BOLD%^%^BLACK%^You wield the lightblade and feel a soft %^RESET%^%^CYAN%^purring%^BOLD%^%^BLACK%^ from the ca%^RESET%^%^BLUE%^t%^BOLD%^%^BLACK%^s "
                "on the hilt.%^RESET%^"
                );
    ETO->set_property("good item", 1);
    return 1;
}

int unwield_func(string str)
{
    tell_object(ETO,
                "%^BOLD%^%^BLACK%^The ca%^RESET%^%^BLUE%^t%^BOLD%^%^BLACK%^s stop %^RESET%^%^CYAN%^purring%^BOLD%^%^BLACK%^ and and let the lightblade slip free.%^RESET%^"
                );
    ETO->set_property("good item", -1);
    return 1;
}

int hitme(object targ)
{
    if (!objectp(TO)) {
        return 1;
    }
    if (!objectp(ETO)) {
        return 1;
    }
    if (!objectp(targ)) {
        return 1;
    }
    if (random(1000) < 230) {
        switch (random(36)) {
        case 0..20:
            tell_room(environment(ETO),
                      "%^BOLD%^%^BLACK%^" + ETOQCN + " %^RESET%^%^RED%^snarls%^BOLD%^%^BLACK%^ angrily as " + ETO->QP + " blade slices into "
                      + targ->QCN + ".%^RESET%^", ({ ETO, targ })
                      );
            tell_object(ETO,
                        "%^BOLD%^%^BLACK%^You %^RESET%^%^RED%^snarl%^BOLD%^%^BLACK%^ angrily as you slice deeply into " + targ->QCN + ".%^RESET%^"
                        );
            tell_object(targ,
                        "%^BOLD%^%^BLACK%^" + ETOQCN + " %^RESET%^%^RED%^snarls%^BOLD%^%^BLACK%^ angrily as " + ETO->QS + " brings " + ETO->QP + " "
                        "blade down, slicing deeply into your flesh.%^RESET%^"
                        );
            targ->do_damage("torso", random(8) + 5);
            break;

        case 21..31:
            tell_room(environment(ETO),
                      "%^BLUE%^" + ETOQCN + " gets a burst of %^CYAN%^speed%^BLUE%^ and dodges under "
                      + targ->QCN + "'s guard, then plunges " + ETO->QP + " blade hard "
                      "into " + targ->QP + " chest.%^RESET%^", ({ ETO, targ })
                      );
            tell_object(ETO,
                        "%^BLUE%^You get a burst of %^CYAN%^speed%^BLUE%^ and dodge under " + targ->QCN + "'s "
                        "guard, then plunge your blade deep into " + targ->QP + " chest.%^RESET%^"
                        );
            tell_object(targ,
                        "%^BLUE%^" + ETOQCN + " %^CYAN%^speeds%^BLUE%^ up suddenly and dodges under your guard, "
                        "then plunges " + ETO->QP + " balade deep into your chest.%^RESET%^"
                        );
            ETO->execute_attack();
            break;

        case 32..35:
            tell_room(environment(ETO),
                      "%^CYAN%^" + ETOQCN + " circles behind " + targ->QCN + " in a %^RED%^predatory%^CYAN%^ "
                      "manner and slams " + ETO->QP + " hilt into the back of "
                      + targ->QP + " head.%^RESET%^", ({ ETO, targ })
                      );
            tell_object(ETO,
                        "%^CYAN%^You circle behind " + targ->QCN + " in a %^RED%^predatory%^CYAN%^ manner and "
                        "slam your hilt into the back of " + targ->QP + " head.%^RESET%^"
                        );
            tell_object(targ,
                        "%^CYAN%^" + ETOQCN + " circles behind you in a %^RED%^predatory%^CYAN%^ manner and "
                        "slams " + ETO->QP + " hilt into the back of your head.%^RESET%^"
                        );
            set_property("magic", 1);
            targ->do_damage("torso", random(10) + 10);
            targ->set_paralyzed(random(8) + 7,
                                "%^CYAN%^You are still reeling from the blow to your head.%^RESET%^"
                                );
            set_property("magic", -1);
            break;

        default:
            tell_object(ETO,
                        "Something is broken, or you wouldn't be seeing this "
                        "message. Please bug report what you were doing at the time."
                        );
            break;
        }
        return 1;
    }
}
