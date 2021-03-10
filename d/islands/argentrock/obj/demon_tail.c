#include <std.h>
inherit "/d/common/obj/weapon/whip_dagger.c";

void create()
{
    ::create();
    set_name("demon's tail whip");
    set_short("%^BOLD%^%^RED%^D%^BLACK%^e%^RED%^m%^BLACK%^o" +
              "%^RED%^n%^BLACK%^'%^RED%^s Tail Whip%^RESET%^");
    set_obvious_short("%^BOLD%^%^RED%^A red scaled leather whip with a spade shaped tip%^RESET%^");
    set_id(({ "whip", "whip dagger", "tail", "demon's tail whip", "red leather whip", "scale whip" }));
    set_long("%^BOLD%^%^RED%^Crafted from the tail of a demon," +
             " this four feet long whip is covered with fine %^RESET%^%^RED%^" +
             "r%^BOLD%^e%^RESET%^%^RED%^d%^BOLD%^ scales.  The end" +
             " of the tail flares out to create a spade shaped tip." +
             " %^BOLD%^%^BLACK%^S%^RESET%^l%^BOLD%^%^BLACK%^i%^RESET%^" +
             "c%^BOLD%^%^BLACK%^k%^RESET%^ %^BOLD%^%^BLACK%^black" +
             "%^RED%^ leather wraps around the end of the tail, " +
             "forming a handle for this strange whip.  The spade " +
             "shaped tip of the whip appears to have been magically" +
             " given a %^BOLD%^%^WHITE%^keen%^RED%^ edge, making it" +
             " as sharp as steel.");
    set_lore("The fey'ri are a rather resourceful race, though in " +
             "a sickening manner.  Using the tails from the demons " +
             "they slayed to gain control of Argentrock, the fey'ri " +
             "crafted a set of whips.  Using their gift of magic, they" +
             " added a keen edge to the tips of the tail.  This allows" +
             " their whips to slice with the ease of mithril through " +
             "nearly anything.  The fey'ri take great pride in their " +
             "whips, for it reminds them of the victory over the " +
             "demons that once use to live on Argentrock.");
    set_property("lore", 14);
    set_property("enchantment", 4);
    set_item_bonus("spell penetration", 1);
    set_item_bonus("caster level", 1);
    set_hit((: TO, "hitme" :));
    set_value(2000);
    set_wield((: TO, "wield_func" :));
    set_unwield((: TO, "unwield_func" :));
}

int wield_func(string str)
{
    if ((int)ETO->query_lowest_level() < 25) {
        tell_object(ETO, "%^BOLD%^%^RED%^The demon's tail resists your touch!");
        return 0;
    }
    tell_object(ETO, "%^BOLD%^%^RED%^The supple demon's tail writhes" +
                " at your touch.");
    tell_room(environment(ETO), "%^BOLD%^%^RED%^" + ETO->QCN + "'s red " +
              "leather whip writhes as " + ETO->QS + " wraps " + ETO->QP + " " +
              "hand around the black leather handle.", ETO);
    return 1;
}

int unwield_func(string str)
{
    tell_object(ETO, "%^BOLD%^The whip stops writhing about as" +
                " you release the handle.");
    return 1;
}

int hitme(object targ)
{
    int i;
    object* weapons;
    object obj;
    string ids;
    //weapons = targ->query_wielded();
    if (!objectp(TO)) {
        return 1;
    }
    if (!objectp(ETO)) {
        return 1;
    }
    if (!objectp(targ)) {
        return 1;
    }

    if (random(1000) < 250) {
        switch (random(36)) {
        case 0..28:
            tell_room(environment(ETO), "%^RED%^" + ETO->QCN + "" +
                      " cracks " + ETO->QP + " whip at " + targ->QCN + ", the " +
                      "tip of the whip slicing " + targ->QO + ".", ({ ETO, targ }));
            tell_object(ETO, "%^RED%^A sharp crack pierces the air as" +
                        " you slice through " + targ->QCN + " with the tip of" +
                        " your whip.");
            tell_object(targ, "%^RED%^A sharp crack pierces the air " +
                        "around you as " + ETO->QCN + " slices through you with" +
                        " the tip of " + ETO->QP + " whip.");
            targ->do_damage("torso", random(8) + 2);
            break;

        case 29..32:
            tell_room(environment(ETO), "%^BOLD%^%^BLACK%^" + ETO->QCN + "" +
                      " wraps " + ETO->QP + " whip around " + targ->QCN + "'s leg " +
                      "and pulls " + targ->QO + " off balance.", ({ ETO, targ }));
            tell_object(ETO, "%^BOLD%^%^BLACK%^You wrap the whip around" +
                        " " + targ->QCN + "'s leg and pull " + targ->QO + " off balance.");
            tell_object(targ, "%^BOLD%^" + ETO->QCN + " wraps " + ETO->QP + " whip" +
                        " around your leg and pulls you off balance!");
            targ->set_tripped(2, "You are trying to stand back up!");
            targ->do_damage("torso", random(5) + 7);
            break;

        case 33..35:

            weapons = targ->query_wielded();
            if (sizeof(weapons)) {
                if ((int)weapons[0]->query_property("enchantment") < 0) {
                    return 1;
                }

                tell_room(environment(ETO), "%^BOLD%^%^RED%^" + ETO->QCN + "" +
                          " snaps " + ETO->QP + " whip across " + targ->QCN + "'s waist.", ({ ETO, targ }));
                tell_object(ETO, "%^BOLD%^%^RED%^Slashing into" +
                            " " + targ->QCN + "'s waist with the tip of the whip, you" +
                            " slice into them with the spade tip.");
                tell_object(targ, "%^BOLD%^%^RED%^" + ETO->QCN + " slashes " +
                            "" + ETO->QP + " whip across your waist, slashing through" +
                            " your armor!");
                targ->do_damange("waist", random(7) + 7);
                ETO->execute_attack();
                ids = weapons[0]->query_id();
                targ->force_me("unwield " + ids[0] + "");
                //targ->force_me("drop "+ids[0]+"");
                break;
            }

            break;

        default:  tell_object(ETO, "Well now you've done it! :) Please bug" +
                              " this and include what you were doing/fighting when you got" +
                              " this message.");
            break;
        }

        return 1;
    }
}
