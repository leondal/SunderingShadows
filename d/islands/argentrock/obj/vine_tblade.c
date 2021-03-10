#include <std.h>
#include "../argabbr.h"
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
        "thinblade of vines"
    }));
    set_obvious_short("%^RESET%^%^GREEN%^An elven thinblade%^RESET%^");
    set_short("%^RESET%^%^GREEN%^Thinblade of V%^BOLD%^i%^RESET%^%^GREEN%^nes%^RESET%^");
    set_long(
        "%^GREEN%^This longsword like exotic weapon seems impossibly thin and "
        "long for its weight. It tapers to a needle-like point, with a "
        "curve to the leading edge that is distinctly %^CYAN%^elven%^GREEN%^. The front "
        "edge of the blade is sharpened along its entire length, and the "
        "back edge is sharpened only for the final quarter near the tip. "
        "It has a basket shaped hilt that resembles v%^BOLD%^i%^RESET%^%^GREEN%^nes, a long grip, "
        "and a heavy pommel. This weapon is intended for thrusting "
        "attacks but is quite capable of slashing as well.%^RESET%^\n"
        );
    set_lore(
        "%^GREEN%^The %^CYAN%^elven%^GREEN%^ thinblades and lightblades of Argentrock are crafted "
        "using a special process that involves heating the %^BOLD%^%^CYAN%^mithril%^RESET%^%^GREEN%^ near "
        "its melting point and folding the metal on top of itself before "
        "stretching it long and thin. The process is repeated over and "
        "over until the desired width and length are achieved. Once the "
        "%^BOLD%^%^CYAN%^blades%^RESET%^%^GREEN%^ have been crafted they are imbued with elements of "
        "nature that are brought forth once again when a %^BOLD%^%^WHITE%^pure%^RESET%^%^GREEN%^ hearted "
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
                    "%^GREEN%^The v%^BOLD%^i%^RESET%^%^GREEN%^nes on the hilt %^BOLD%^%^RED%^recoil%^RESET%^%^GREEN%^ and refuse to bond with one "
                    "such as you.%^RESET%^"
                    );
        return 0;
    }
    tell_object(ETO,
                "%^GREEN%^You wield the thinblade and the v%^BOLD%^i%^RESET%^%^GREEN%^nes on the hilt %^ORANGE%^wrap%^GREEN%^ "
                "themselves over your hand.%^RESET%^"
                );
    ETO->set_property("good item", 1);
    return 1;
}

int unwield_func(string str)
{
    tell_object(ETO,
                "%^GREEN%^You %^ORANGE%^unwrap%^GREEN%^ the v%^BOLD%^i%^RESET%^%^GREEN%^nes from your hand and let the thinblade slip "
                "free.%^RESET%^"
                );
    ETO->set_property("good item", -1);
    return 1;
}

int hitme(object targ)
{
    object ob2;
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
                        "%^GREEN%^You easily %^CYAN%^slip%^GREEN%^ your thinblade through a weak spot in "
                        + targ->QCN + "'s armor.%^RESET%^"
                        );
            tell_object(targ,
                        "%^GREEN%^" + ETOQCN + " %^CYAN%^slips%^GREEN%^ " + ETO->QP + " thinblade through a weak spot "
                        "in your armor.%^RESET%^"
                        );
            tell_room(environment(ETO),
                      "%^GREEN%^" + ETOQCN + " %^CYAN%^slips%^GREEN%^ " + ETO->QP + " thinblade through a weak spot "
                      "in " + targ->QCN + "'s armor.%^RESET%^", ({ ETO, targ })
                      );
            targ->do_damage("torso", random(8) + 3);
            break;

        case 35..46:
            tell_object(ETO,
                        "%^ORANGE%^The %^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^nes%^ORANGE%^ around your hand seem to %^RED%^speed%^ORANGE%^ up your movement, "
                        "allowing you to puncture and slash " + targ->QCN + " several "
                        "times.%^RESET%^"
                        );
            tell_object(targ,
                        "%^ORANGE%^" + ETOQCN + "'s movements %^RED%^speed%^ORANGE%^ to an impossible rate, "
                        "allowing " + ETO->QO + " to puncture and slash you several "
                        "times.%^RESET%^"
                        );
            tell_room(environment(ETO),
                      "%^ORANGE%^" + ETOQCN + "'s movements %^RED%^speed%^ORANGE%^ to an impossible rate, "
                      "allowing " + ETO->QO + " to puncture and slash " + targ->QCN + " "
                      "several times.%^RESET%^", ({ ETO, targ })
                      );
            ETO->execute_attack();
            ETO->execute_attack();
            break;

        case 47..49:
            tell_object(ETO,
                        "%^BOLD%^%^BLACK%^The %^RESET%^%^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^nes%^BOLD%^%^BLACK%^ seem to take control of your hand, moving it "
                        "through a series of ancient gestures.%^RESET%^\n%^BOLD%^%^GREEN%^In a %^WHITE%^flash%^GREEN%^ of color "
                        "a sprite appears at your side.%^RESET%^"
                        );
            tell_room(environment(ETO),
                      "%^BOLD%^%^BLACK%^" + ETOQCN + " starts to move " + ETO->QP + " hand in strange "
                      "gestures.%^RESET%^\n%^BOLD%^%^GREEN%^In a %^WHITE%^flash%^GREEN%^ of color a sprite appears at "
                      + ETO->QP + " side.%^RESET%^", ETO
                      );
            ob2 = new(MON + "sprite.c");
            ob2->move(EETO);
            ob2->force_me("protect " + ETO->query_name());
            ETO->add_follower(ob2);
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
