//Pearl Greatsword, inspired by Crystal's pearl short sword -- Yves
#include <std.h>
inherit "/d/common/obj/weapon/two_hand_sword.c";

void create()
{
    ::create();
    set_name("pearl greatsword");
    set_short("%^BOLD%^%^WHITE%^Pearl Greatsword%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^A pearl handled greatsword%^RESET%^");
    set_id(({
        "sword",
        "greatsword",
        "great sword",
        "pearl sword",
        "pearl greatsword",
        "pearl great sword",
        "pearl handled greatsword"
        "pearl handled great sword"
    }));
    set_long(
        "%^BOLD%^%^WHITE%^This greatsword has a white pearl handle with a hilt that has "
        "been inlaid with a large %^CYAN%^blue pearl%^WHITE%^. Several smaller %^CYAN%^blue "
        "pearls%^WHITE%^ protrude from the handle as well, providing a very good "
        "grip. The %^CYAN%^mithril%^WHITE%^ blade has a brilliant %^CYAN%^whitish-blue%^WHITE%^ luster to "
        "it and is incredibly well crafted.%^RESET%^\n"
        );
    set_lore(
        "%^BOLD%^%^WHITE%^The pearl swords of %^RESET%^%^GREEN%^Argentrock%^BOLD%^%^WHITE%^ are crafted using a special "
        "process that involves heating the %^CYAN%^mithril%^WHITE%^ to its melting point "
        "and mixing in a specific amount of crushed %^CYAN%^blue pearl%^WHITE%^ that has "
        "been harvested from the %^RESET%^Voratae%^BOLD%^%^WHITE%^, an oyster like creature of the "
        "%^RESET%^%^GREEN%^Argentrock%^BOLD%^%^WHITE%^ coast.%^RESET%^"
        );
    set_property("lore", 15);
    set_value(2000);
    set_property("enchantment", 4);
    set_special_material_type("silver");
    set_hit((: TO, "hitme" :));
    set_wield((: TO, "wield_func" :));
    set_unwield((: TO, "unwield_func" :));
}

int wield_func(string str)
{
    tell_object(ETO,
                "%^BOLD%^%^WHITE%^The %^CYAN%^blue pearls%^WHITE%^ on the hilt of the sword fuse to your hands.%^RESET%^"
                );
    return 1;
}

int unwield_func(string str)
{
    tell_object(ETO,
                "%^BOLD%^%^WHITE%^A strange sucking noise is emitted from the %^CYAN%^blue pearls%^WHITE%^ as "
                "they release your hands.%^RESET%^"
                );
    tell_room(environment(ETO),
              "%^BOLD%^%^WHITE%^A strange sucking noise is emitted from " + ETOQCN + "'s sword as "
              + ETO->QS + " unwields it.%^RESET%^", ETO
              );
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
    if (random(1000) < 225) {
        switch (random(36)) {
        case 0..20:
            tell_object(ETO,
                        "%^BOLD%^%^WHITE%^The sword glows slightly and you slice through "
                        + targ->QCN + "'s armor with ease.%^RESET%^"
                        );
            tell_object(targ,
                        "%^BOLD%^%^WHITE%^" + ETOQCN + "'s sword glows slightly and slices right through "
                        "your armor.%^RESET%^"
                        );
            tell_room(environment(ETO),
                      "%^BOLD%^%^WHITE%^" + ETOQCN + "'s sword glows slightly and seems to slice right "
                      "through " + targ->QCN + "'s armor.%^RESET%^", ({ ETO, targ })
                      );
            set_property("magic", 1);
            targ->do_damage("torso", random(10) + 6);
            set_property("magic", -1);
            break;

        case 21..31:
            tell_object(ETO,
                        "%^BOLD%^%^CYAN%^The large blue pearl glows for a moment and warmth washes "
                        "over your body.%^RESET%^"
                        );
            tell_room(environment(ETO),
                      "%^BOLD%^%^CYAN%^The blue pearl in the hilt of " + ETOQCN + "'s sword glows "
                      "briefly.%^RESET%^", ETO
                      );
            ETO->do_damage("torso", -(random(10) + 6));
            targ->do_damage("torso", random(10) + 6);
            break;

        case 32..35:
            tell_object(ETO,
                        "%^BOLD%^%^CYAN%^The large blue pearl glows for a moment and warmth washes "
                        "over your body.%^RESET%^"
                        );
            tell_object(targ,
                        "%^BOLD%^%^CYAN%^The blue pearl in the hilt of " + ETOQCN + "'s sword glows and "
                        "fills your %^RED%^mind%^CYAN%^ with its beauty.%^RESET%^"
                        );
            tell_room(environment(ETO),
                      "%^BOLD%^%^CYAN%^The blue pearl in the hilt of " + ETOQCN + "'s sword glows "
                      "briefly.%^RESET%^", ({ ETO, targ })
                      );
            ETO->do_damage("torso", -(random(14) + 10));
            targ->do_damage("torso", random(14) + 10);
            targ->set_paralyzed(random(8) + 7,
                                "%^BOLD%^%^CYAN%^You are entranced by the blue pearl!%^RESET%^"
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
