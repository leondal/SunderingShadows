//Thinblade of Leaves -- Yves
#include <std.h>
inherit "/d/common/obj/weapon/scimitar.c";

void create()
{
    ::create();
    set_name("elven thinblade");
    set_id(({
        "sword",
        "blade",
        "thinblade",
        "elven thinblade",
        "thinblade of leaves"
    }));
    set_obvious_short("%^BOLD%^%^GREEN%^An elven thinblade%^RESET%^");
    set_short("%^BOLD%^%^GREEN%^Thinblade of Le%^RESET%^%^GREEN%^a%^BOLD%^ves%^RESET%^");
    set_long(
        "%^BOLD%^%^GREEN%^This longsword like exotic weapon seems impossibly thin and "
        "long for its weight. It tapers to a needle-like point, with a "
        "curve to the leading edge that is distinctly %^RESET%^%^CYAN%^elven%^BOLD%^%^GREEN%^. The front "
        "edge of the blade is sharpened along its entire length, and the "
        "back edge is sharpened only for the final quarter near the tip. "
        "It has a basket shaped hilt that resembles le%^RESET%^%^GREEN%^a%^BOLD%^ves, a long grip, "
        "and a heavy pommel. This weapon is intended for thrusting "
        "attacks but is quite capable of slashing as well.%^RESET%^\n"
        );
    set_lore(
        "%^BOLD%^%^GREEN%^The %^RESET%^%^CYAN%^elven%^BOLD%^%^GREEN%^ thinblades and lightblades of %^RESET%^%^GREEN%^Argentrock%^BOLD%^ are crafted "
        "using a special process that involves heating the %^CYAN%^mithril%^GREEN%^ near "
        "its melting point and folding the metal on top of itself before "
        "stretching it long and thin. The process is repeated over and "
        "over until the desired width and length are achieved. Once the "
        "%^CYAN%^blades%^GREEN%^ have been crafted they are imbued with elements of "
        "nature that are brought forth once again when a %^WHITE%^pure%^GREEN%^ hearted "
        "being takes up the blade.%^RESET%^"
        );
    set_property("lore difficulty", 13);
    set_property("enchantment", 4);
    set_special_material_type("silver");
    set_value(3000);
    set_wield((: TO, "wield_func" :));
    set_unwield((: TO, "unwield_func" :));
    set_hit((: TO, "hitme" :));
}

int wield_func(string str)
{
    if (ALIGN->is_evil(ETO)) {
        tell_object(ETO,
                    "%^BOLD%^%^GREEN%^The le%^RESET%^%^GREEN%^a%^BOLD%^ves on the hilt %^BLACK%^wither%^GREEN%^ and refuse to bond with one "
                    "such as you.%^RESET%^"
                    );
        return 0;
    }
    tell_object(ETO,
                "%^BOLD%^%^GREEN%^You wield the thinblade and feel the soft le%^RESET%^%^GREEN%^a%^BOLD%^ves on the hilt "
                "%^YELLOW%^cover%^GREEN%^ your hand.%^RESET%^"
                );
    ETO->set_property("good item", 1);
    return 1;
}

int unwield_func(string str)
{
    tell_object(ETO,
                "%^BOLD%^%^GREEN%^You remove the le%^RESET%^%^GREEN%^a%^BOLD%^ves %^YELLOW%^covering%^GREEN%^ your hand and let the thinblade "
                "slip free.%^RESET%^"
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
    if (random(1000) < 220) {
        switch (random(50)) {
        case 0..34:
            tell_object(ETO,
                        "%^BOLD%^%^GREEN%^You pierce " + targ->QCN + "'s defenses with your thinblade, "
                        "perforating " + targ->QP + " %^YELLOW%^flesh%^GREEN%^ with deadly grace.%^RESET%^"
                        );
            tell_object(targ,
                        "%^BOLD%^%^GREEN%^" + ETOQCN + " pierces your defense with " + ETO->QP + " thinblade, "
                        "perforating your %^YELLOW%^flesh%^GREEN%^ with deadly grace.%^RESET%^"
                        );
            tell_room(environment(ETO),
                      "%^BOLD%^%^GREEN%^" + ETOQCN + " pierces " + targ->QCN + "'s defense with "
                      + ETO->QP + " thinblade, perforating " + targ->QP + " %^YELLOW%^flesh%^GREEN%^ with "
                      "deadly grace.%^RESET%^", ({ ETO, targ })
                      );
            targ->do_damage("torso", random(8) + 4);
            break;

        case 35..40:
            tell_object(ETO,
                        "%^YELLOW%^You lunge at " + targ->QCN + " with a great leap, driving your "
                        "thinblade %^BLACK%^deep%^YELLOW%^ into " + targ->QP + " ribs.%^RESET%^"
                        );
            tell_object(targ,
                        "%^YELLOW%^" + ETOQCN + " lunges at you with a great leap, driving "
                        + ETO->QP + " thinblade %^BLACK%^deep%^YELLOW%^ into your ribs.%^RESET%^"
                        );
            tell_room(environment(ETO),
                      "%^YELLOW%^" + ETOQCN + " lunges at " + targ->QCN + " with a great leap, "
                      "driving " + ETO->QP + " thinblade %^BLACK%^deep%^YELLOW%^ into " + targ->QP + " "
                      "ribs.%^RESET%^", ({ ETO, targ })
                      );
            ETO->execute_attack();
            break;

        case 41..49:
            tell_object(ETO,
                        "%^RED%^An %^BOLD%^%^BLACK%^oily%^RESET%^%^RED%^ substance is secreted by the %^BOLD%^%^GREEN%^le%^RESET%^%^GREEN%^a%^BOLD%^ves%^RESET%^%^RED%^ and coats your "
                        "blade as you stab into " + targ->QCN + ".%^RESET%^"
                        );
            tell_object(targ,
                        "%^RED%^" + ETOQCN + " stabs into you with " + ETO->QP + " thinblade, and "
                        "your muscles seize up!%^RESET%^"
                        );
            tell_room(environment(ETO),
                      "%^RED%^" + ETOQCN + " stabs into " + targ->QCN + " with " + ETO->QP + " "
                      "thinblade.%^RESET%^", ({ ETO, targ })
                      );
            targ->do_damage("torso", random(10) + 8);
            targ->set_paralyzed((random(8) + 7),
                                "%^RED%^Your muscles are seized up!%^RESET%^"
                                );
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
