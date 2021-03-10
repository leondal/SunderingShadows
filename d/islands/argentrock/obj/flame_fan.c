//updated for Argentrock addition
//Yves 12/8/06
//added bonus for using both fans
//hades 3/24/13
#include <std.h>
inherit "/d/common/obj/weapon/fan.c";

void create()
{
    ::create();
    set_name("fan of the dancing flames");
    set_id(({
        "fan",
        "fan of the dancing flames",
        "red silk fan"
    }));
    set_obvious_short("%^RESET%^%^RED%^A red silk fan%^RESET%^");
    set_short("%^RESET%^%^RED%^Fan of the Dancing %^BOLD%^%^RED%^F%^RESET%^%^RED%^l%^BOLD%^%^RED%^a%^RESET%^%^RED%^m%^BOLD%^%^RED%^e%^RESET%^%^RED%^s%^RESET%^");
    set_long(
        "%^RESET%^%^ORANGE%^Fashioned from %^BOLD%^%^WHITE%^mithril%^RESET%^%^ORANGE%^, this light fan has an "
        "%^BOLD%^%^RED%^elven artistic%^RESET%^%^ORANGE%^ touch to it.  Seven metal sections are "
        "joined together to create this deadly looking fan.  Each "
        "section features intricate shaping and cutting in the thin "
        "plates, each plate made to resemble a %^RED%^dancing %^BOLD%^f%^RESET%^%^RED%^l%^BOLD%^a%^RESET%^%^RED%^m%^BOLD%^e%^RESET%^%^ORANGE%^.  "
        "When the fan is folded up each of the section stack one behind "
        "the other to create a singular image.  Though when the fan is "
        "spread open, a breathtaking image of leaping and twisting %^B_RED%^%^BOLD%^%^RED%^flames%^RESET%^%^ORANGE%^ "
        "unfolds.  The edges of these artistic fans are sharpened to a "
        "fine edge, as well as any sword or dagger.  A faint %^RED%^red lacquer "
        "%^RESET%^%^ORANGE%^covers the surface of the fan, with powdered %^BOLD%^f%^RESET%^%^RED%^i%^ORANGE%^r%^YELLOW%^e "
        "%^RED%^o%^RESET%^%^RED%^p%^ORANGE%^a%^YELLOW%^l%^RED%^s%^RESET%^%^ORANGE%^ infused with the metal.%^RESET%^\n"
        );
    set_lore("A relic from the elven kingdom of Selu'havessthor, this weapon " +
             "was brought to the island of Argentrock by the outcast house " +
             "of Heasirretyn, ancestors of the fey'ri.  This fan was crafted " +
             "for the Flame Dancers, an elite group of warrior/dancers who " +
             "helped to patrol the forests.  The Flame Dancers dressed " +
             "lightly, many of them forsaking the use of armor in favor " +
             "of speed.  These battle-dancers were said to be graceful in" +
             " melee, each movement from them looking like a poetic " +
             "expression of dancing.  Though not as famous as the " +
             "bladesingers, the Flame Dancers were still given the " +
             "utmost respect.  When the fey'ri fled their homeland, " +
             "they took these wonderful fans with them, among other things.");
    set_property("lore difficulty", 12);
    set_property("enchantment", 4);
    set_value(2000);
    set_wield((: TO, "wield_func" :));
    set_unwield((: TO, "unwield_func" :));
    set_hit((: TO, "hit_func" :));
    set_special_material_type("silver");
    set_item_bonus("magic resistance", 4);
    set_item_bonus("caster level", 1);
    set_item_bonus("fire resistance", 20);
}

int wield_func(string str)
{
    if ((int)ETO->query_lowest_level() < 25) {
        tell_object(ETO, "%^RED%^The fan refuses you!");
        return 0;
    }
    tell_object(ETO,
                "%^RED%^Flames dance across the surface of the fan as you slide it open.%^RESET%^"
                );
    tell_room(EETO,
              "%^RED%^Flames dance across the surface of " + ETO->QCN + "'s fan.", ETO
              );
    return 1;
}

int unwield_func(string str)
{
    tell_object(ETO,
                "%^RED%^The flames vanish as you slowly close the fan."
                );
    tell_room(EETO,
              "%^RED%^Flames vanish off the surface of " + ETO->QCN + "'s fan.", ETO
              );


    return 1;
}

int hit_func(object targ)
{
    object diamond;
    targ = ETO->query_current_attacker();
    if (!objectp(ETO)) {
        return 1;
    }
    if (!objectp(targ)) {
        return 1;
    }
    if (random(1000) < 225) {
        if (present("diamond shard", EETO)) {
            diamond = present("diamond shard", EETO);
            diamond->remove();
            diamond = new("/d/islands/argentrock/mon/diamond2");
            diamond->move(EETO);
            diamond->force_me("protect " + ETO->query_name());
            ETO->add_follower(diamond);
            tell_room(EETO, "%^RED%^" + ETO->QCN + "'s fan lets out a stream" +
                      " of fire that seems to dance around the diamond.", ETO);
            tell_object(ETO, "%^RED%^You dance around the diamond and a" +
                        " stream of fire comes circles the gem shard.");
        }
        switch (random(50)) {
        case 0..35:
            tell_object(ETO,
                        "%^BOLD%^%^RED%^You feel your feet being pulled into" +
                        " a dance as you spin around to flank " + targ->QCN + ", tearing" +
                        " into " + targ->QO + " with a flick of your wrist."
                        );
            tell_object(targ,
                        "%^BOLD%^%^RED%^" + ETO->QCN + " dances around to flank you. "
                        "Never breaking " + ETO->QP + " graceful stride, " + ETO->QS + " tears "
                        "into your skin with a flick of " + ETO->QP + " wrist."
                        );
            tell_room(EETO,
                      "%^BOLD%^%^RED%^" + ETO->QCN + " dances around " + targ->QCN +
                      ", flicking " + ETO->QP + " fan into into " + targ->QO + " without "
                      "breaking " + ETO->QP + " graceful movements.", ({ ETO, targ })
                      );
            targ->cause_typed_damage(targ, 0, roll_dice(2, 6), "piercing");
            break;

        case 36..46:
            tell_object(ETO,
                        "%^RED%^You spin under " + targ->QCN + "'s reach. With a flick "
                        "of your wrist you spin the fan in your hand, slicing "
                        + targ->QCN + " open."
                        );
            tell_object(targ,
                        "%^RED%^" + ETO->QCN + " spins under your guard.  Before you "
                        "can even react, " + ETO->QCN + " spins " + ETO->QP + " fan around, "
                        "slicing you open!"
                        );
            tell_room(EETO,
                      "%^RED%^" + ETOQCN + " spins in under " + targ->QCN + "'s guard." +
                      "\nWith a flick of " + ETOQCN + "'s wrist, " + ETO->QP + " fan spins "
                      "around, slicing into " + targ->QCN + ".", ({ ETO, targ })
                      );
            targ->cause_typed_damage(targ, 0, roll_dice(3, 6), "piercing");
            break;

        case 47..49:
            tell_object(ETO,
                        "%^RED%^You feel yourself slipping into an age " +
                        "old dance, your feet and body moving about without a " +
                        "conscious effort."
                        );
            tell_object(targ,
                        "%^RED%^" + ETOQCN + " moves about with such grace and " +
                        "poise as " + ETO->QS + " falls into an ancient dance, " + ETO->QP + " " +
                        "fan flashing around " + ETO->QO + ".  You find yourself entranced " +
                        "by such a seductive and lithe performance."
                        );
            tell_room(EETO,
                      "%^RED%^" + ETOQCN + " moves about with such grace "
                      "and poise as " + ETO->QS + " falls into an ancient dance, "
                      + ETO->QP + " fan flashing around " + ETO->QO + " while " + targ->QCN +
                      " is mesmorized.", ({ ETO, targ })
                      );
            targ->set_paralyzed(random(3) + 4,
                                "%^RED%^You can't take your eyes off the performance!%^RESET%^"
                                );
            break;

        default:
            tell_object(ETO,
                        "Uhoh, you broke it, you bought it.  Please " +
                        "bug what you were doing when you got this message."
                        );
            break;
        }
        return 1;
    }
}
