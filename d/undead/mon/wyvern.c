#include <std.h>
#include "../undead.h"

inherit CREATURE;

void create() 
{
    ::create();
    set_name("%^YELLOW%^%^BOLD%^Wyvern%^RESET%^");
    set_id(({"wyvern","dragon"}));
    set_short("%^YELLOW%^%^BOLD%^Wyvern%^RESET%^");
    set_long("Wyverns are the distant relatives of dragons.  These monsters act very "
        "much like dragons, except they are much more stupid.  They are very aggressive, "
        "and wyverns will always attack if given an opportunity.  Their body is like "
        "that of a dragon, except they have no arms.  Their tail is like that of a "
        "scorpion, and they can easy lash out with it over their head while hovering "
        "in the air.  Its skin is a light brown and its eyes bright red.");
    set_overall_ac(-3);
    set_race("wyvern");
    set_body_type("dragon");
    add_limb("tooth filled maw", "head", 0, 0, 0);
    add_limb("right front claw", "right foreleg", 0, 0, 0);
    add_limb("left front claw", "left foreleg", 0, 0, 0);
    add_limb("right rear claw", "right rear leg", 0, 0, 0);
    add_limb("left rear claw", "left rear leg", 0, 0, 0);
    add_limb("right wing", "right wing", 0, 0, 0);
    add_limb("left wing", "left wing", 0, 0, 0);
    add_limb("tail", "tail", 0, 0, 0);
    set_attack_limbs(({"tooth filled maw",
                       "right front claw",
                       "left front claw",
                       "right rear claw",
                       "left rear claw",
                       "right wing",
                       "left wing",
                       "tail"
                    }));
    set_attacks_num(5);
    set_hd(25,8);
    set_damage(2,10);
    set_hp(1500);
    set_exp(65000);
    set_new_exp(25,"very high");
    set_speed(25);
    nogo("one");
    set_size(3);
    set_stats("strength",21);
    set_stats("dexterity",18);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_alignment(7);
    set_emotes(6, ({"%^RED%^The Wyvern %^RESET%^%^BOLD%^*SREECHES*%^RESET%^%^RED%^ with berserk %^BOLD%^FURY%^RESET%^%^RED%^!",
        "%^YELLOW%^The Wyvern stares at you through its %^RED%^glowing red%^RESET%^%^YELLOW%^ eyes!", }),1);
    set_hit_funcs((["tail":(:TO,"venom":)]));
    set_speed(60);
    add_money("gold",random(20000)+550);
    add_money("platinum",random(1000)+30);
}

void venom(object targ)
{
    if(!ROLLSAVE(targ,PPD))
    {
        tell_object(targ,"%^YELLOW%^You feel the Wyvern's poison enter your bloodstream!%^RESET%^");
        tell_room(ETO,"%^YELLOW%^You see the Wyvern's stinger strike "+targ->QCN+"!",targ);
        targ->add_poisoning(50);
        targ->do_damage("head",roll_dice(5,10));
        return;
    }
    return;
}

void aggfunc()
{
    if(TP->query_true_invis()) { return; }
    TO->kill_ob(TP,1);
    tell_room(ETO,"%^BOLD%^Wyvern %^YELLOW%^screeches%^RESET%^%^BOLD%^ loudy and lunges "
        "for "+TP->QCN+"!%^RESET%^",TP);
    tell_object(TP,"%^BOLD%^Wyvern %^YELLOW%^screeches%^RESET%^%^BOLD%^ loudly and lunges "
        "for you!%^RESET%^");
    return;
}
