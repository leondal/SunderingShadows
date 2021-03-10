//Octothorpe (3/30/09)
//Attaya, Bonestripper
//Based on Winter's Touch two-handed sword
///d/dagger/arctic/winterstouch.c
//Updated by Odin to incorporate universal double damage function 8/12/2019

#include <std.h>
#include "../defs.h"
#include <daemons.h>
inherit "/d/common/obj/weapon/two_hand_sword.c";

void create()
{
    ::create();
    set_obvious_short("%^BOLD%^%^BLACK%^a bl%^RESET%^a%^BOLD%^%^BLACK%^" +
                      "ckened serrated claymore%^RESET%^");
    set_short("%^BOLD%^%^WHITE%^Bone%^RED%^str%^RESET%^%^RED%^i%^BOLD%^" +
              "pp%^RESET%^%^RED%^e%^BOLD%^r%^RESET%^");
    set_name("Bonestripper");
    set_id(({ "sword", "claymore", "two handed sword", "bonestripper", "bone stripper" }));
    set_long("%^BOLD%^%^BLACK%^The blade of this sword measures six feet " +
             "in length from hilt to tip.  Instead of a %^RESET%^met%^BOLD%^" +
             "a%^RESET%^llic %^BOLD%^%^BLACK%^color, the blade is deep bl" +
             "%^RESET%^a%^BOLD%^%^BLACK%^ck matte hue, offering nigh a " +
             "polished gleam off of the metal.  Undulating serrated edges " +
             "slither along the blade, lending it a distinctly sinister " +
             "quality.  The hilt has been fashioned out of a polished %^WHITE%^" +
             "bone%^BOLD%^%^BLACK%^, it is impossible to determine the type, " +
             "or origin of it.%^RESET%^");
    set_lore("The origins of this claymore are shrouded, but the legends " +
             "surrounding it center upon Intruder.  It has been suggested by " +
             "some that Bonestripper was Intruder's favored blade even when " +
             "he walked the realms as a mortal. Other theories posit that the " +
             "sword houses what is left of Intruder's soul, or even serves as " +
             "the source of his immortal might.  The blood that streams down " +
             "the blade, from tip to hilt, is said to be the blood of all " +
             "the unfortunate souls to have met their end on its blackened " +
             "steel.");
    set_value(random(5000) + 35000);
    set_property("enchantment", 6);
    set_item_bonus("attack bonus", 5);
    set_item_bonus("damage bonus", 5);
    set_item_bonus("strength", 4);
    set_property("lore difficulty", 27);
    set_property("no alter", 1);
    set_hit((: TO, "hitme" :));
    set_wield((: TO, "wieldme" :));
    set_unwield((: TO, "unwieldme" :));
}

int wieldme()
{
    if (base_name(ETO) == "/d/attaya/mon/intruder") {
        return 1;
    }
    if (base_name(ETO) != "/d/attaya/mon/intruder") {
        if ((int)ETO->query_highest_level() < 25 || member_array("Life force of the Kinnesaruda has faded, Intruder and Autarkis are defeated", ETO->query_mini_quests()) == -1) {
            tell_room(EETO, "%^BOLD%^The bone hilt of the sword begins to " +
                      "%^RED%^glow %^WHITE%^as it burns " + ETOQCN + "'s hand.%^RESET%^", ETO);
            tell_object(ETO, "%^BOLD%^Your hand is burned by the bone hilt " +
                        "as you try to wield the sword!%^RESET%^");
            ETO->do_damage("torso", random(70) + 30);
            return 0;
        }
    }
    if (ETO->query_property("master weapon")) {
        tell_object(ETO, "You find it impossible to lift two such mighty " +
                    "weapons!", ETO);
        return 0;
    }
    tell_room(EETO, "%^BOLD%^As " + ETOQCN + " wields the sword, a stream " +
              "of %^RESET%^%^RED%^blood %^BOLD%^%^WHITE%^begins to stream down " +
              "the blade from its tip.%^RESET%^", ETO);
    tell_object(ETO, "%^BOLD%^As you wield the sword, a stream of " +
                "%^RESET%^%^RED%^blood %^BOLD%^%^WHITE%^begins to stream down " +
                "the blade from the tip.%^RESET%^");
    ETO->set_property("evil item", 1);
    ETO->set_property("master weapon", 1);
    return 1;
}

int unwieldme()
{
    tell_room(EETO, "%^BOLD%^As " + ETOQCN + " unwields the sword, the stream " +
              "of %^RESET%^%^RED%^blood %^BOLD%^%^WHITE%^ceases to flow down " +
              "the blade.%^RESET%^", ETO);
    tell_object(ETO, "%^BOLD%^As you unwield the sword, the stream of " +
                "%^RESET%^%^RED%^blood %^BOLD%^%^WHITE%^ceases to flow down " +
                "the blade.%^RESET%^");
    ETO->set_property("evil item", -1);
    ETO->set_property("master weapon", -1);
    return 1;
}

int special_damage()
{
    int sdamage;
    string bonus_stat;
    int mysize;
    mysize = (int)ETO->query_size();
    if (mysize == 1) {
        mysize++;             //run small creatures as normal size please.
    }
    mysize -= (int)TO->query_size();
    if (FEATS_D->usable_feat(ETO, "weapon finesse") && (mysize >= 0)) { // if has-feat & weapon is smaller than/equal to user
        bonus_stat = "dexterity";
    }else {
        bonus_stat = "strength";
    }
    sdamage = TO->query_wc() + (int)TO->query_property("enchantment") + (int)ETO->query_damage_bonus() + (int)BONUS_D->new_damage_bonus(ETO, ETO->query_stats(bonus_stat));
    return sdamage;
}

int hitme(object targ)
{
    object* attackers, room;
    int i;
    attackers = ETO->query_attackers();
    attackers = filter_array(attackers, "is_non_immortal", FILTERS_D);

    if (!objectp(targ)) {
        return 0;
    }
    if (random(1000) > 750) {
        switch (random(11)) {
        case 0:
            tell_room(EETO, "%^YELLOW%^With a deft flick of the wrist, " +
                      "%^RED%^blood %^YELLOW%^flings off of " + ETOQCN + "'s " +
                      "sword, hitting " + targ->QCN + "'s eyes!%^RESET%^", ETO);
            tell_object(ETO, "%^YELLOW%^With a deft flick of your wrist, " +
                        "some of the %^RED%^blood %^YELLOW%^streaming down your " +
                        "blade flings off, splattering in " + targ->QCN + "'s " +
                        "eyes!%^RESET%^");
            targ->set_tripped(random(3) + 1, "%^RED%^The blood burns your " +
                              "eyes!%^RESET%^");
            targ->set_temporary_blinded(random(6));
            break;

        case 1..5:
            tell_room(EETO, "%^BOLD%^" + ETOQCN + "'s sword %^RED%^cleaves " +
                      "%^WHITE%^through armor and flesh, biting into " +
                      "" + targ->QCN + "'s bone!%^RESET%^", ETO);
            tell_object(ETO, "%^BOLD%^Your sword %^RED%^cleaves %^WHITE%^" +
                        "through " + targ->QCN + "'s armor and flesh, biting into " +
                        "" + targ->QP + " bone!%^RESET%^");
            TO->set_property("magic", 1);
            targ->cause_typed_damage(targ, targ->return_target_limb(), TO->special_damage(), TO->query_damage_type());
            TO->set_property("magic", -1);
            break;

        case 6..9:
            tell_room(EETO, "%^BLUE%^" + ETOQCN + " swings " + ETO->QP + " sword " +
                      "in a wide arc, %^RED%^slicing through multiple targets " +
                      "at once!%^RESET%^", ETO);
            tell_object(ETO, "%^BLUE%^You swing the sword in a wide " +
                        "arc, %^RED%^slicing %^BLUE%^through multiple " +
                        "targets!%^RESET%^");
            for (i = 0; i < sizeof(attackers); i++) {
                TO->set_property("magic", 1);
                attackers[i]->cause_typed_damage(attackers[i], attackers[i]->return_target_limb(), TO->special_damage(), TO->query_damage_type());
                TO->set_property("magic", -1);
            }
            break;

        case 10:
            tell_room(EETO, "%^MAGENTA%^" + ETOQCN + " seems to become " +
                      "possessed by " + ETO->QP + " sword, and begins performing " +
                      "a string of furious attacks!%^RESET%^", ETO);
            tell_object(ETO, "%^MAGENTA%^You feel as if you are possessed " +
                        "by the sword, and you let loose a series of furious " +
                        "attacks!%^RESET%^");
            ETO->execute_attack();
            if (!random(3)) {
                ETO->execute_attack();
            }
            if (!random(30)) {
                TO->set_property("magic", 1);
                ETO->execute_attack();
                TO->set_property("magic", -1);
            }
            break;
        }
    }
    return 1;
}
