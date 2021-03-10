//Serpentblade -- Yves
#include <std.h>
inherit "/d/common/obj/weapon/shortsword.c";

void create()
{
    ::create();
    set_name("elven lightblade");
    set_short("%^RESET%^%^RED%^Se%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^pentblade%^RESET%^");
    set_obvious_short("%^RESET%^%^RED%^An elven lightblade%^RESET%^");
    set_id(({
        "sword",
        "blade",
        "lightblade",
        "serpentblade",
        "elven lightblade"
    }));
    set_long(
        "%^RED%^This shortsword like exotic weapon seems impossibly thin and "
        "long for its weight. It tapers to a needle-like point, with a "
        "curve to the leading edge that is distinctly %^CYAN%^elven%^RED%^. The front "
        "edge of the blade is sharpened along its entire length, and the "
        "back edge is sharpened only for the final quarter near the tip. "
        "It has a basket shaped hilt that resembles various "
        "%^se%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^pents, a long grip, and a heavy pommel. This weapon is "
        "intended for thrusting attacks but is quite capable of slashing "
        "as well.%^RESET%^\n"
        );
    set_lore(
        "%^RED%^The %^CYAN%^elven%^RED%^ thinblades and lightblades of Argentrock are crafted "
        "using a special process that involves heating the %^BOLD%^%^CYAN%^mithril%^RESET%^%^RED%^ near "
        "its melting point and folding the metal on top of itself before "
        "stretching it long and thin. The process is repeated over and "
        "over until the desired width and length are achieved. Once the "
        "%^BOLD%^%^CYAN%^blades%^RESET%^%^RED%^ have been crafted they are imbued with elements of "
        "nature that are brought forth once again when a %^BOLD%^%^WHITE%^pure%^RESET%^%^RED%^ hearted "
        "being takes up the blade.%^RESET%^"
        );
    set_property("lore", 13);
    set_value(2000);
    set_hit((: TO, "hitme" :));
    set_property("enchantment", 4);
    set_special_material_type("silver");
    set_wield((: TO, "wield_func" :));
    set_unwield((: TO, "unwield_func" :));
}

int wield_func(string str)
{
    if (ALIGN->is_evil(ETO)) {
        tell_object(ETO,
                    "%^RED%^The serpents on the hilt %^BOLD%^%^BLACK%^hiss%^RESET%^%^RED%^ and refuse to bond with one "
                    "such as you.%^RESET%^"
                    );
        return 0;
    }
    tell_object(ETO,
                "%^RED%^You wield the lightblade and the se%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^pents on the hilt "
                "%^GREEN%^entwine%^RED%^ themselves around your hand.%^RESET%^"
                );
    ETO->set_property("good item", 1);
    return 1;
}

int unwield_func(string str)
{
    tell_object(ETO,
                "%^RED%^The se%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^pents %^GREEN%^untangle%^RED%^ themselves from your hand and let the "
                "lightblade slip free.%^RESET%^"
                );
    ETO->set_property("good item", -1);
    return 1;
}

int hitme(object targ)
{
    object* weapons;
    string ids;
    if (!objectp(TO)) {
        return 1;
    }
    if (!objectp(ETO)) {
        return 1;
    }
    if (!objectp(targ)) {
        return 1;
    }
    if (random(1000) < 270) {
        switch (random(50)) {
        case 0..34:
            tell_object(targ,
                        "%^RED%^You are %^BOLD%^%^BLACK%^impaled%^RESET%^%^RED%^ with the lightblade as " + ETOQCN + " lunges at "
                        "you%^RESET%^."
                        );
            tell_object(ETO,
                        "%^RED%^You %^BOLD%^%^BLACK%^impale%^RESET%^%^RED%^ the lightblade into " + targ->QCN + " with a lunging "
                        "thrust.%^RESET%^"
                        );
            tell_room(environment(ETO),
                      "%^RED%^" + targ->QCN + " is %^BOLD%^%^BLACK%^impaled%^RESET%^%^RED%^ with the lightblade as " + ETOQCN + " "
                      "lunges at " + targ->QS + "%^RESET%^", ({ ETO, targ })
                      );
            targ->do_damage("torso", random(5) + 4);
            break;

        case 35..46:
            tell_object(targ,
                        "%^YELLOW%^You are knocked off balance by a %^GREEN%^sweeping%^YELLOW%^ attack to your "
                        "shins.%^RESET%^"
                        );
            tell_object(ETO,
                        "%^YELLOW%^You make a %^GREEN%^sweeping%^YELLOW%^ attack at " + targ->QCN + "'s shins and "
                        "knock " + targ->QO + " off balance.%^RESET%^"
                        );
            tell_room(environment(ETO),
                      "%^YELLOW%^" + ETOQCN + " makes a sweeping attack at " + targ->QCN + "'s shins "
                      "and knocks " + targ->QO + " off balance.%^RESET%^", ({ ETO, targ })
                      );
            targ->do_damage("torso", random(10) + 6);
            targ->set_tripped(2,
                              "%^GREEN%^You are trying to get to your feet!%^RESET%^"
                              );
            break;

        case 47..49:
            weapons = targ->query_wielded();
            if (!sizeof(weapons)) {
                return 1;
            }else {
                tell_object(ETO,
                            "%^BOLD%^%^BLACK%^You strike " + targ->QCN + "'s weapon and the %^RESET%^%^RED%^se%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^pents wrap "
                            "around it.%^RESET%^\n%^RED%^Giving a firm tug, you pull the weapon "
                            "loose from " + targ->QP + " hand.%^RESET%^"
                            );
                tell_object(targ,
                            "%^BOLD%^%^BLACK%^" + ETOQCN + " strikes your weapon with " + ETO->QP + " "
                            "lightblade.%^RESET%^\n%^RED%^Somehow, with a tug " + ETO->QS + " manages to "
                            "pull it out of your hands!%^RESET%^"
                            );
                tell_room(EETO,
                          "%^BOLD%^%^BLACK%^" + ETOQCN + " strikes " + targ->QCN + "'s weapon with "
                          + ETO->QP + " lightblade.%^RESET%^\n%^RED%^Somehow, with a tug "
                          + ETO->QO + " manages to pull it out of " + targ->QS + " "
                          "hands!%^RESET%^", ({ ETO, targ })
                          );
                ids = weapons[0]->query_id();
                targ->force_me("unwield " + ids[0] + "");
                return 1;
            }
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
