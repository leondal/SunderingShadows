//He's no longer a halfling - I have in mind for him to be some
//very evil, very charismatic, intelligent, human/small devil/small
//demon mix or maybe some type of experiment gone horribly
//wrong - Saide 01/02/04

#include <std.h>
#include "../inherits/area_stuff.h"
#include <daemons.h>
inherit MONSTER;
int has_robe;
string robe_desc;

void create()
{
    object ob, money;
    ::create();
    set_name("humanoid");
    set_id(({"bandit","leader","thief","humanoid"}));
    set_race("humanoid");
    set_body_type("human");
    set_size(1);
    set_short("A slight humanoid with tanned flesh");
    set_class("fighter");
    set_guild_level("fighter",34);
    set_mlevel("fighter",query_guild_level("fighter"));
    set_class("thief");
    set_guild_level("thief",34);
    set_mlevel("thief",query_guild_level("thief"));
    add_search_path("/cmds/thief");
    set("aggressive", "stab_them");
    set_alignment(7);
    set_stats("strength",20);
    set_stats("intelligence",18);
    set_stats("wisdom",15);
    set_stats("dexterity",20);
    set_stats("charisma",17);
    set_stats("constitution",13);
    set_gender("male");
    set_hp(3575 + random(375));
    set_new_exp(32, "boss");
    ob = new("/d/common/obj/weapon/shortsword");
    ob->set_property("enchantment", 5);
    ob->move(TO);
    command("wield sword");
    command("wear leather");
    ob = new("/d/common/obj/weapon/dagger");
    ob->set_property("enchantment", 5);
    ob->move(TO);
    command("wield dagger");
    switch(random(3))
    {
        case 0:
            ob = new("/d/deku/armours/ring_p");
            ob->move(TO);
            ob->set_property("enchantment", 3);
            command("wear ring");
            break;
        case 1:
            ob = new("/d/deku/armours/brobe.c");
            ob->set_property("enchantment", 2);
            ob->move(TO);
            command("wear robe");
            robe_desc = "a %^BLUE%^blue%^RESET%^ and "+
            "%^YELLOW%^yellow%^RESET%^ robe";
            has_robe = 1;
            break;
        case 3:
            new("/d/common/obj/misc/pouch.c")->move(TO);
            new("/d/common/obj/misc/thief_tools.c")->move(TO);
            new("/d/common/obj/misc/flint.c")->move(TO);
            command("put tools in pouch");
            command("wear pouch");
            break;
    }
    if(has_robe == 0)
    {
        if(!random(3))
        {
            ob = new("/d/deku/armours/leather");
            ob->move(TO);
            ob->set_property("enchantment", 2);
            ob->set_item_bonus("stealth", 4);
            ob->set_size(1);
        }
        else
        {
            ob = new("/d/common/obj/armour/leather");
            ob->set_property("enchantment", 5);
            ob->set_size(1);
            ob->move(TO);
        }
        command("wear armor");
        robe_desc = "a suit of %^BOLD%^%^BLACK%^black leather%^RESET%^";
    }

    set_long("%^RESET%^This strange creature wears "+robe_desc+".  His eyes are an "+
    "%^RED%^intense red%^RESET%^ and there is no hair on him to speak "+
    "of.  His gaping mouth is littered with rows of teeth that have been "+
    "%^RED%^sharpened%^RESET%^ in some unnatural manner, apart "+
    "from which there is "+
    "no expression.  The exposed parts of his flesh are a light brown "+
    "and you are unsure if this suggests a tan or is his natural color.  "+
    "An occassional twitch, like a ripple through water, pulses "+
    "through his body and is complimented by a laugh from him.  It is "+
    "obvious that this man is not natural, his small human body has "+
    "several hints of another, more mysterious heritage.  An aura "+
    "of almost tangible superiority or at least confidence lingers "+
    "about him.  He is always armed, yet, doesn't appear afraid or "+
    "even very alert.%^RESET%^");

    add_money("silver",random(2000));
    add_money("gold",random(3250)+1500);
    if(!random(2))
    {
        ob = new(HHOB+"narameons_gauntlet");
        ob->move(TO);
    }

    set_overall_ac(-24);
    set_property("no paralyze",1);
    set_property("no death",1);
    set_property("full attacks",1);
    set_mob_magic_resistance("average");
    set_funcs(({"attack"}));
    set_func_chance(50);
    ob = new("/d/common/obj/potion/healing");
    ob->set_uses(40 + random(21));
    ob->move(TO);
    command("open vial");
    ob = new(HHOB+"dagger_part");
    ob->choose_piece(1);
    ob->move(TO);
    set_monster_feats(({
        "parry",
        "scramble",
        "stab",
    }));
    set_property("no tripped", 1);
}

void heart_beat()
{
    ::heart_beat();
    if(!objectp(TO) || !objectp(ETO)) return;
    if(TO->query_hp() < ((int)TO->query_max_hp() / 4))
    {
        if(present("kit",TO))
        {
            command("open vial");
            command("drink vial");
            command("offer bottle");
            command("drink vial");
            command("offer bottle");
        }
    }
}

void attack(object targ)
{
    if(!objectp(targ) || !objectp(TO)) return;
    switch(random(8))
    {
        case 0..6:
            tell_object(targ,"%^YELLOW%^The humanoid stabs into your "+
            "chest with his shortsword!%^RESET%^");
            tell_room(ETO,"%^YELLOW%^The humanoid stabs into "+
            targ->QCN+"%^YELLOW%^'s chest with his shortsword!",targ);
            set_property("magic",1);
            targ->cause_typed_damage(targ, "torso",roll_dice(14,6), "piercing");
            set_property("magic",-1);
            break;
        case 7:
            tell_object(targ,"%^RED%^The humanoid spins to the "+
            "side and spits a %^BOLD%^%^GREEN%^green goo"+
            "%^RESET%^%^RED%^ into your eyes!%^RESET%^");

            tell_room(ETO,"%^RED%^The humanoid spints to the side "+
            "suddenly and spits a %^BOLD%^%^GREEN%^green goo"+
            "%^RESET%^%^RED%^ into "+targ->QCN+"%^RED%^'s "+
            "eyes!%^RESET%^",targ);
            set_property("magic",1);
            targ->cause_typed_damage(targ, "head",roll_dice(14,6), "acid");
            set_property("magic",-1);
            if(!targ->fort_save(30))
            {
                tell_object(targ,"%^RED%^You scream in pain as "+
                "the %^BOLD%^%^GREEN%^goo%^RESET%^%^RED%^ burns "+
                "into your eyes!%^RESET%^");
                tell_room(ETO,targ->QCN+"%^RED%^ screams out in pain "+
                "as the %^BOLD%^%^GREEN%^goo%^RESET%^%^RED%^ burns "+
                "into "+targ->QP+" eyes!%^RESET%^",targ);
                targ->set_temporary_blinded(12,"%^BOLD%^%^GREEN%^"+
                "The goo has burned your eyes!%^RESET%^");
                break;
            }
            else
            {
                tell_object(targ,"%^RED%^You scream in pain as "+
                "the %^BOLD%^%^GREEN%^goo%^RESET%^%^RED%^ begins "+
                "burning, but quickly wipe it away!%^RESET%^");
                tell_room(ETO,targ->QCN+"%^RED%^ screams in "+
                "pain and then quickly wipes the %^BOLD%^%^GREEN%^"+
                "goo%^RESET%^%^RED%^ from "+targ->QP+" eyes!"+
                "%^RESET%^",targ);
                break;
            }
            break;
    }
}


void stab_them()
{
    if(objectp(TP) && !TP->query_true_invis())
    {
        command("speech say without emotion");
        command("say you have stepped into something "+
        "that was best left alone.");
        command("say now you must perish.");
        add_attack_bonus(4);
        command("stab "+TPQN);
        add_attack_bonus(-4);
        command("kill "+TPQN);
    }
}
