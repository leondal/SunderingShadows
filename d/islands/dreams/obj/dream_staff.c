//created by Circe 3/26/05
//updated by Circe 10/1/19 to current code and to remove references to old gods

#include <std.h>
#include <daemons.h>
#include "../defs.h"

inherit "/d/common/obj/weapon/quarter_staff";

int FLAG;

void create()
{
    ::create();
    set_name("crystal staff");
    set_id(({ "staff", "crystal staff", "fancy", "stargazer's fancy", "dream staff" }));
    set_obvious_short("%^BOLD%^%^CYAN%^c%^BLUE%^r%^GREEN%^y%^YELLOW%^s%^RED%^t%^MAGENTA%^a%^CYAN%^l staff%^RESET%^");
    set_short("%^RESET%^%^CYAN%^S%^BOLD%^t%^WHITE%^a%^RESET%^r%^CYAN%^g%^BOLD%^a%^WHITE%^z%^RESET%^e%^CYAN%^r%^BOLD%^'%^WHITE%^s %^CYAN%^Fancy%^RESET%^");
    set_long("%^CYAN%^This slender staff is over six feet tall and features an unusual construction.  The top third is a solid piece of %^BOLD%^azure crystal %^RESET%^%^CYAN%^left mostly in the rough.  It is multi-faceted and shot through with %^BOLD%^v%^RESET%^e%^MAGENTA%^i%^BOLD%^%^BLUE%^n%^CYAN%^s %^RESET%^%^CYAN%^of %^BOLD%^%^BLUE%^cobalt%^RESET%^%^CYAN%^, %^MAGENTA%^amethyst%^CYAN%^, and %^RESET%^clear calcite%^CYAN%^.  The %^BOLD%^crystal %^RESET%^%^CYAN%^has been fitted onto a short solid handle of %^BOLD%^%^WHITE%^mithril %^RESET%^%^CYAN%^marked with smooth, thin grooves that make it look much like an old-fashioned broom made of bound rushes.  The handle has three %^BOLD%^%^BLACK%^adamantium bands %^RESET%^%^CYAN%^- one at the top, middle, and bottom.  The bottom band attaches the short handle to a %^BOLD%^%^RED%^s%^RESET%^%^ORANGE%^h%^YELLOW%^i%^GREEN%^m%^CYAN%^m%^BLUE%^e%^RESET%^%^MAGENTA%^r%^BOLD%^%^RED%^i%^RESET%^%^ORANGE%^n%^YELLOW%^g %^CYAN%^crystalline cylinder%^RESET%^%^CYAN%^ sheathed with a narrow ribbon of %^BOLD%^%^BLACK%^adamantium %^RESET%^%^CYAN%^that highlights the swirling %^BOLD%^%^RED%^c%^RESET%^%^ORANGE%^o%^YELLOW%^l%^GREEN%^o%^CYAN%^r%^BLUE%^s %^RESET%^%^CYAN%^inside.  The weapon has a beautiful, ethereal appearance that makes it seem timeless.%^RESET%^");
    set_lore("The crystal used in the Stargazer's Fancy is known to the denizens of the Dream Realm as 'lucindaris' and is said to draw upon the powers of all the elements, binding them in a powerful illusion.  It resists change, and it can only be shaped by the most potent magic.  Even that often results in some simple smoothing and planing, but the crystal's natural shape will ever prevail.  Weapons made of lucindaris are quite rare, and they may only be controlled by those of powerful wills.  - Matylin the Wise, 'An Account of the Dream Realm'");
    set_property("enchantment", 4);
    while ((int)TO->query_property("enchantment") != 4) {
        TO->remove_property("enchantment");
        TO->set_property("enchantment", 4);
    }
    set_item_bonus("spell penetration", 1);
    set_item_bonus("magic resistance", 1);
    set_value(3000);
    set_wield((: TO, "wieldme" :));
    set_unwield((: TO, "unwieldme" :));
    set_hit((: TO, "hitme" :));
    FLAG = 0;
}

int wieldme()
{
    if (member_array("%^BOLD%^%^CYAN%^Lucid Dreams%^RESET%^", ETO->query_mini_quests()) == -1) {
        tell_object(ETO, "You have not earned the right to make use of this item.");
        return 0;
    }
    if ((string)ETO->is_class("mage") || (string)ETO->is_class("cleric") || (string)ETO->is_class("sorcerer") || (string)ETO->is_class("psion") || (string)ETO->is_class("druid")) {
        if (!ETO->query_property("silent_wield")) {
            tell_object(ETO, "%^YELLOW%^The %^BOLD%^%^RED%^c%^RESET%^%^ORANGE%^o%^YELLOW%^l%^GREEN%^o%^CYAN%^r%^BLUE%^s %^YELLOW%^swirl within the base, flaring to life as you wield the " + TO->query_obvious_short() + "!%^RESET%^");
            tell_room(EETO, "%^YELLOW%^The %^BOLD%^%^RED%^c%^RESET%^%^ORANGE%^o%^YELLOW%^l%^GREEN%^o%^CYAN%^r%^BLUE%^s %^YELLOW%^swirl within the base, flaring to life as " + ETOQCN + " wields the " + TO->query_obvious_short() + "!%^RESET%^", ETO);
        }
        set_item_bonus("attack bonus", 1);
        FLAG = 1;
        return 1;
    }
    set_item_bonus("attack bonus", 0);
    if (!ETO->query_property("silent_wield")) {
        tell_object(ETO, "%^CYAN%^You hear a faint whispering at the edge of your perception as you grip the staff.%^RESET%^");
        tell_room(EETO, "%^CYAN%^" + ETOQCN + " hefts the staff and seems to be listening to something unheard.%^RESET%^", ETO);
    }
    return 1;
}

int unwieldme()
{
    if (!ETO->query_property("silent_wield")) {
        if (FLAG) {
            tell_object(ETO, "%^CYAN%^The colors in the staff fade once more as you set it aside, leaving you feeling smaller somehow.%^RESET%^");
            tell_room(EETO, "%^CYAN%^" + ETOQCN + " seems to diminish as " + ETO->QS + " puts aside the staff, and it grows dark.%^RESET%^", ETO);
            FLAG = 0;
            return 1;
        }
        tell_object(ETO, "%^CYAN%^Your mind suddenly grows quiet as you lower the staff.%^RESET%^");
        tell_room(EETO, "%^CYAN%^" + ETOQCN + "'s face suddenly looks clearer as " + ETO->QS + " lowers the staff.%^RESET%^", ETO);
    }
    return 1;
}

int hitme(object targ)
{
    object myspl;
    if (!objectp(ETO)) {
        return 1;
    }
    if (!objectp(targ)) {
        return 1;
    }
    if (!random(5)) {
        switch (random(25)) {
        case 14..24:
            tell_object(ETO, "%^RED%^The crystalline top suddenly flares with a %^BOLD%^red light %^RESET%^%^RED%^that slams into " + targ->QCN + "!%^RESET%^");
            tell_object(targ, "%^RED%^The crystalline top of " + ETOQCN + "'s staff suddenly flares with a %^BOLD%^red light %^RESET%^%^RED%^that slams into you!%^RESET%^");
            tell_room(EETO, "%^RED%^The crystalline top of " + ETOQCN + "'s staff suddenly flares with a %^BOLD%^red light %^RESET%^%^RED%^that slams into " + targ->QCN + "!%^RESET%^", ({ targ, ETO }));
            if (FLAG) {
                tell_object(ETO, "%^RED%^The words of a spell fill your mind!%^RESET%^");
                new("/cmds/spells/s/_scorcher")->use_spell(ETO, targ, 8, 100, "mage");
            }else {
                targ->do_damage(targ->return_target_limb(), roll_dice(1, 4));
            }
            break;

        case 9..13:
            tell_object(ETO, "%^ORANGE%^The crystalline top suddenly flares with an %^YELLOW%^orange light %^RESET%^%^ORANGE%^that slams into " + targ->QCN + "!%^RESET%^");
            tell_object(targ, "%^ORANGE%^The crystalline top of " + ETOQCN + "'s staff suddenly flares with an %^YELLOW%^orange light %^RESET%^%^ORANGE%^that slams into you!%^RESET%^");
            tell_room(EETO, "%^ORANGE%^The crystalline top of " + ETOQCN + "'s staff suddenly flares with an %^YELLOW%^orange light %^RESET%^%^ORANGE%^that slams into " + targ->QCN + "!%^RESET%^", ({ targ, ETO }));
            if (FLAG) {
                tell_object(ETO, "%^ORANGE%^The words of a spell fill your mind!%^RESET%^");
                new("/cmds/spells/s/_scorcher")->use_spell(ETO, targ, 12, 100, "mage");
            }else {
                targ->do_damage(targ->return_target_limb(), roll_dice(2, 4));
            }
            break;

        case 6..8:
            tell_object(ETO, "%^YELLOW%^A sudden yellow light with a green cast bursts forth from the crystal, aiming for " + targ->QCN + "!%^RESET%^");
            tell_object(targ, "%^YELLOW%^A sudden yellow light with a green cast bursts forth from the crystal atop the staff wielded by " + ETOQCN + ", aiming for you!%^RESET%^");
            tell_room(EETO, "%^YELLOW%^A sudden yellow light with a green cast bursts forth from the crystal atop the staff wielded by " + ETOQCN + ", aiming for " + targ->QCN + "!%^RESET%^", ({ targ, ETO }));
            if (FLAG) {
                tell_object(ETO, "%^GREEN%^The words of a spell fill your mind!%^RESET%^");
                new("/cmds/spells/a/_acid_arrow")->use_spell(ETO, targ, 4, 100, "mage");
            }else {
                ETO->set_property("magic", 1);
                targ->do_damage(targ->return_target_limb(), roll_dice(2, 6));
                ETO->set_property("magic", -1);
            }
            break;

        case 3..5:
            tell_object(ETO, "%^GREEN%^The crystal at the end of your staff sends a %^BOLD%^green ray %^RESET%^%^GREEN%^streaking toward " + targ->QCN + "!%^RESET%^");
            tell_object(targ, "%^GREEN%^The crystal at the end of " + ETOQCN + "'s staff sends a %^BOLD%^green ray %^RESET%^%^GREEN%^streaking toward you!%^RESET%^");
            tell_room(EETO, "%^GREEN%^The crystal at the end of " + ETOQCN + "'s staff sends a %^BOLD%^green ray %^RESET%^%^GREEN%^streaking toward " + targ->QCN + "!%^RESET%^", ({ targ, ETO }));
            if (FLAG) {
                tell_object(ETO, "%^GREEN%^The words of a spell fill your mind!%^RESET%^");
                new("/cmds/spells/a/_acid_arrow")->use_spell(ETO, targ, 12, 100, "mage");
            }else {
                ETO->set_property("magic", 1);
                targ->do_damage(targ->return_target_limb(), roll_dice(2, 10));
                ETO->set_property("magic", -1);
            }
            break;

        case 2:
            if ((int)targ->query_stoneSkinned() > 0 || targ->query_property("iron body")) {
                while (objectp(myspl = MAGIC_D->get_spell_from_array(targ->query_property("spelled"), "stoneskin"))) {
                    remove_property_value("spelled", ({ myspl }));
                    myspl->dest_effect();
                }
                while (objectp(myspl = MAGIC_D->get_spell_from_array(targ->query_property("spelled"), "iron body"))) {
                    remove_property_value("spelled", ({ myspl }));
                    myspl->dest_effect();
                }
                tell_object(ETO, "%^BOLD%^%^BLUE%^The crystal atop your staff glows with a deep blue light that bursts forth into " + targ->QCN + "!  Suddenly, the mystical armor protecting " + targ->QCN + " cracks and falls apart!%^RESET%^");
                tell_object(targ, "%^BOLD%^%^BLUE%^The crystal atop " + ETOQCN + "'s staff glows with a deep blue light that bursts forth into you!  Suddenly, the mystical armor protecting you cracks and falls apart!%^RESET%^");
                tell_room(EETO, "%^BOLD%^%^BLUE%^The crystal atop " + ETOQCN + "'s staff glows with a deep blue light that bursts forth into " + targ->QCN + "!  Suddenly, the mystical armor protecting " + targ->QCN + " cracks and falls apart!%^RESET%^", ({ ETO, targ }));
                targ->do_damage("torso", random(3) + 3);
            }
            tell_object(ETO, "%^BOLD%^%^BLUE%^The crystal atop your staff glows with a deep blue light as it slams into " + targ->QCN + "!%^RESET%^");
            tell_object(targ, "%^BOLD%^%^BLUE%^The crystal atop " + ETOQCN + "'s staff glows with a deep blue light as it slams into you!");
            tell_room(EETO, "%^BOLD%^%^BLUE%^The crystal atop " + ETOQCN + "'s staff glows with a deep blue light as it slams into " + targ->QCN + "!", ({ ETO, targ }));
            ETO->set_property("magic", 1);
            targ->do_damage("torso", random(4) + 5);
            ETO->set_property("magic", -1);
            break;

        case 1:
            tell_object(ETO, "%^BLUE%^An indigo haze surrounds the crystal, seeming to darken the room around you.\nSuddenly, the crystal %^BOLD%^flares %^RESET%^%^BLUE%^to light, right into " + targ->QCN + "'s eyes!%^RESET%^");
            tell_object(targ, "%^BLUE%^An indigo haze surrounds the crystal on " + ETOQCN + "'s staff, seeming to darken the room around " + ETO->QO + ".\nSuddenly, the crystal %^BOLD%^flares %^RESET%^%^BLUE%^to light, right into your eyes!%^RESET%^");
            tell_room(EETO, "%^BLUE%^An indigo haze surrounds the crystal on " + ETOQCN + "'s staff, seeming to darken the room around " + ETO->QO + ".\nSuddenly, the crystal %^BOLD%^flares %^RESET%^%^BLUE%^to light, right into " + targ->QCN + "'s eyes!%^RESET%^", ({ ETO, targ }));
            if (!(int)targ->query_constitution() > random(20)) {
                targ->set_temporary_blinded(10, "%^BLUE%^An indigo haze blots out your vision!%^RESET%^");
            }else {
                tell_object(targ, "%^BOLD%^%^BLUE%^You avert your gaze, but the after-image confuses you for a moment!%^RESET%^");
                targ->set_paralyzed(2, "Your eyes are burning!");
            }
            break;

        default:
            tell_object(ETO, "%^MAGENTA%^A sudden %^BOLD%^violet light %^RESET%^%^MAGENTA%^radiates from your staff, bringing with it two illusory images of you!  They attack " + targ->QCN + " before vanishing again!%^RESET%^");
            tell_object(targ, "%^MAGENTA%^A sudden %^BOLD%^violet light %^RESET%^%^MAGENTA%^radiates from " + ETOQCN + "'s staff, and there suddenly seem to be two more of " + ETO->QO + "!  They attack you before vanishing again!%^RESET%^");
            tell_room(EETO, "%^MAGENTA%^A sudden %^BOLD%^violet light %^RESET%^%^MAGENTA%^radiates from " + ETOQCN + "'s staff, and there suddenly seem to be two more of " + ETO->QO + "!  attack " + targ->QCN + " before vanishing again!%^RESET%^", ({ targ, ETO }));
            ETO->execute_attack();
            ETO->execute_attack();
            break;
        }
        return roll_dice(2, 3);
    }
    return roll_dice(1, 4);
}
