//Reskinned Bonestripper by Odin
#include <std.h>
//#include "../defs.h"
#include <daemons.h>
inherit "/d/common/obj/weapon/elvencurvedblade.c";

void create()
{
    ::create();
    set_obvious_short("%^RESET%^%^GREEN%^An %^RESET%^%^WHITE%^adamantium %^RESET%^%^GREEN%^elven curved blade%^RESET%^");
    set_name("Guardian of Tel-Quessir");
    set_short("%^RESET%^%^GREEN%^Gu%^RESET%^%^RED%^a%^GREEN%^rd%^RESET%^%^RED%^i%^GREEN%^an of %^GREEN%^T%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^l-Q%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ess%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^r%^RESET%^");
    set_id(({ "sword", "blade", "elven curved blade", "curved blade", "elven blade", "Guardian of Tel-Quessir", "guardian of tel-quessir", "guardian", "guardian sword" }));;
    set_long("%^RESET%^%^WHITE%^Made of adamantium, this sword is nothing short of a work of art.   Though quite long, the curved blade looks remarkably light weight, easy to handle, and has been honed to an impossibly sharp, %^CYAN%^glowing edge%^RESET%^%^WHITE%^.  The hilt is not wrapped, but left to show the beautiful %^RESET%^%^GREEN%^e%^CYAN%^lv%^GREEN%^en %^RESET%^%^%^WHITE%^carvings within the metal; swirling %^BOLD%^%^GREEN%^v%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^nes %^RESET%^%^%^WHITE%^twist and wrap their way around imagery of elven warriors in winged helms fighting all sorts of ilk, ranging from %^RESET%^%^ORANGE%^terrible beasts %^RESET%^%^%^WHITE%^to %^RESET%^%^RED%^grotesque %^RESET%^%^%^WHITE%^and %^BOLD%^%^RED%^monstrous demons%^RESET%^%^WHITE%^.  The work of the relatively small guard is also nothing short of a master's.  A %^BOLD%^%^WHITE%^silver dragon %^RESET%^%^WHITE%^curls protectively around the %^RESET%^%^GREEN%^elven script %^RESET%^%^WHITE%^etched into the base of the blade, its curled %^BOLD%^%^WHITE%^tail %^RESET%^%^WHITE%^forming one side of the guard, and its outstretched %^BOLD%^%^WHITE%^wings %^RESET%^forming the other.  It's bent head meets the metal of the blades base, almost as though the blade itself were of its breath.  Where from its open maw, %^BOLD%^%^BLACK%^sm%^RESET%^%^WHITE%^o%^BOLD%^%^BLACK%^ke %^BOLD%^%^BLACK%^b%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^ll%^RESET%^%^WHITE%^o%^BOLD%^%^BLACK%^ws %^RESET%^%^WHITE%^forth to lazily curl its way along the entire length of the blade, its journey seeming to end at the very tip.%^RESET%^");
    set_lore("Legend has it that centuries ago, an Elven Bladesinger named Seldanna Trawynn ascended the Crystalline Tower along with her companions in a quest to see Intruder and Autarkis defeated.  Quickly finding themselves in over their heads, the group attempted to escape by slipping past Judatac.  The Rear Guard, however, sensed their approach and quickly engaged the group of would-be heroes.  In a heroic act, Seldanna threw herself full-force at Judatac, effectively sacrificing herself to allow her companions to escape.  This was her weapon, forged by some of the finest bladesmiths in Ashatae'Rathnai.");
    set_language("elven");
    set_read("%^RESET%^%^GREEN%^For the People, proudly we fight and proudly we die.%^RESET%^");
    set_value(random(5000) + 35000);
    set_property("enchantment", 6);
    set_item_bonus("attack bonus", 5);
    set_item_bonus("damage bonus", 5);
    set_item_bonus("strength", 4);
    set_property("lore difficulty", 27);
    set_property("no alter", 1);
    set_property("no curse", 1);
    set_property("able to cast", 1); //this makes it better than Bonestripper but not by much, and fits thematically
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
            tell_room(EETO, "%^BOLD%^The adamantium hilt of the sword begins to %^RED%^glow %^WHITE%^as it burns " + ETOQCN + "'s hand.%^RESET%^", ETO);
            tell_object(ETO, "%^BOLD%^Your hand is burned by the adamantium hilt as you try to wield the sword!%^RESET%^");
            ETO->do_damage("torso", random(70) + 30);
            return 0;
        }
    }
    if (ETO->query_property("master weapon")) {
        tell_object(ETO, "You find it impossible to lift two such mighty weapons!", ETO);
        return 0;
    }
    tell_room(EETO, "%^BOLD%^As " + ETOQCN + " wields the sword, a presence from beyond the grave descends upon " + ETO->QP + ".%^RESET%^", ETO);
    tell_object(ETO, "%^BOLD%^%^WHITE%^As you wield the sword, you feel the presence of your ancestors filling you with knowledge and strength.%^RESET%^");
    ETO->set_property("master weapon", 1);
    return 1;
}

int unwieldme()
{
    tell_room(EETO, "%^BOLD%^%^WHITE%^As " + ETOQCN + " unwields the sword, the presence from beyond the grave fades.%^RESET%^", ETO);
    tell_object(ETO, "%^BOLD%^%^WHITE%^As you unwield the sword, you feel the presence of your ancestors leave you, taking their knowledge and strength with them.%^RESET%^");
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
    if (!random(3)) {
        switch (random(11)) {
        case 0:
            tell_room(EETO, "%^YELLOW%^With a deft flick of the wrist, " + ETOQCN + " brings " + ETO->QP + " blade across " + targ->QCN + "'s eyes!%^RESET%^", ETO);
            tell_object(ETO, "%^YELLOW%^With a deft flick of your wrist, you bring your blade across " + targ->QCN + "'s eyes!%^RESET%^");
            targ->set_tripped(random(3) + 1, "%^RED%^Your eyes are bleeding!%^RESET%^");
            targ->set_temporary_blinded(random(6));
            break;

        case 1..5:  //Better than Bonestripper, causes a free extra hit that ignores 10 DR.
            tell_room(EETO, "%^BOLD%^%^WHITE%^" + ETOQCN + "'s sword %^RED%^slices %^WHITE%^through armor and flesh, biting into " + targ->QCN + "'s bone!%^RESET%^", ETO);
            tell_object(ETO, "%^BOLD%^%^WHITE%^Your sword %^RED%^slices %^WHITE%^through " + targ->QCN + "'s armor and flesh, biting into " + targ->QP + " bone!%^RESET%^");
            TO->set_property("magic", 1);
            targ->cause_typed_damage(targ, targ->return_target_limb(), TO->special_damage(), TO->query_damage_type());
            TO->set_property("magic", -1);
            break;

        case 6..9:  //this is better than bonestripper, esentially a free cleave attack that ignores 10DR, help from Yves on this
            tell_room(EETO, "%^GREEN%^" + ETOQCN + " swings " + ETO->QP + " sword in a wide arc, %^BOLD%^%^RED%^cleaving %^RESET%^%^GREEN%^through multiple targets at once!%^RESET%^", ETO);
            tell_object(ETO, "%^GREEN%^You swing the sword in a wide arc, %^BOLD%^%^RED%^cleaving %^RESET%^%^GREEN%^through multiple targets!%^RESET%^");
            for (i = 0; i < sizeof(attackers); i++) {
                TO->set_property("magic", 1);
                attackers[i]->cause_typed_damage(attackers[i], attackers[i]->return_target_limb(), TO->special_damage(), TO->query_damage_type());
                TO->set_property("magic", -1);
            }
            break;

        case 10:
            tell_room(EETO, "%^RESET%^%^CYAN%^%^" + ETOQCN + " seems to become possessed by " + ETO->QP + " sword, and begins performing a string of furious attacks!%^RESET%^", ETO);
            tell_object(ETO, "%^RESET%^%^CYAN%^You feel as if you are possessed by your ancestors, and you let loose a series of furious attacks!%^RESET%^");
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
        return 0;
    }
    return 0;
}
