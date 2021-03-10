#include <std.h>
#include "../area_stuff.h"

inherit ELDEBARO_MONSTER;
int enraged;

void create()
{
    object ob;
    ::create();

    set_race("minotaur");

    set_id( ({ "minotaur", "dreadhorn", "male minotaur", "massive minotaur", "ancient dreadhorn", "eldebarocreature"}) );
    set_body_type("minotaur");
    set_class("fighter");
    set_alignment(5);
    set_hd(50,12);
    set_hp(5500 + random(451));
    set_max_hp(query_hp());

    set_stats("strength", 24 + random(3));
    set_stats("constitution", 24 + random(4));
    set_stats("dexterity", 11 + random(3));
    set_stats("wisdom", 12 + random(3));
    set_stats("intelligence", 12 + random(3));
    set_stats("charisma", 11 + random(3));
    set_overall_ac(-20);
    set_mob_magic_resistance("average");
    set_property("no death", 1);
    set_gender("male");

    set_name("ancient dreadhorn");

    set_short("%^BOLD%^%^BLACK%^An ancient %^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^r"+
    "%^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^a%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^h%^BOLD%^"+
    "%^RED%^o%^BOLD%^%^BLACK%^r%^BOLD%^%^RED%^n%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This minotaur like creature is covered with "+
    "thick and dark fur. His head is enormous, nearly three feet around, with "+
    "glaring %^BOLD%^%^RED%^red%^BOLD%^%^BLACK%^ eyes set above a pair of flaring "+
    "nostrils. Atop the head of this creature are two %^BOLD%^%^WHITE%^ivory%^BOLD%^"+
    "%^BLACK%^ colored horns, which are both honed to a razor sharp point at the tip and "+
    "each is actually serrated on the outter sides, as if they have been intentionally "+
    "made to almost function like a dagger. They are thinner than what you would "+
    "expect. The dark fur covered body of this creature ripples with mass, most of it muscle, "+
    "that seems barely contained within. Large meaty fists extend from the end of its "+
    "massive arm like appendages. Two ebony hooves rest at the end of its massive "+
    "leg like appendages and give this enormous creature some balance. A heavy "+
    "darkness envelopes this creature. %^RESET%^");

    set_property("add kits",25);
    set("aggressive", 55);
    set_alignment(9);
    set_property("full attacks", 2);

    add_money("silver", 12500 + random(5500));
    add_money("gold", 8500 + random(8500));
    add_money("copper", 25500 + random(65000));
    set_new_exp(40, "boss");
    set_monster_feats(({"rush", "impale", "sweepingblow"}));
    set_func_chance(75);
    set_funcs(({"charge", "pound", "stomp", "charge", "pound", "stomp", "something_evil", "charge", "pound", "stomp", "stomp", "charge", "pound"}));
    enraged = 0;
    ob = new(ELOB+"brutal_allocation");
    if(random(4)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield axe");
    ob = new(ELOB+"brutal_allocation");
    if(random(4)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield axe");
}

void die(object ob)
{
    if(!objectp(ETO)) return ::die(ob);
    tell_room(ETO, "%^BOLD%^%^BLACK%^As the ancient dreadhorn topples over.. the "+
    "tip of one of its horns breaks off and falls to the ground!%^RESET%^");
    new(ELOB+"raw_dreadhorn")->move(ETO);
    return ::die(ob);
}

void stomp(object targ)
{
    string me, limb;
    object *vics;
    int x, dam;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    me = TO->query_short();
    tell_room(ETO, me+"%^BOLD%^%^RED%^ STOMPS%^BOLD%^%^BLACK%^ its massive ebon hooves and a "+
    "wave of energy emanates outward from them!%^RESET%^");
    vics = TO->query_attackers();
    if(!sizeof(vics)) return;
    for(x = 0;x < sizeof(vics);x++)
    {
        if(!objectp(vics[x])) continue;
        if(!objectp(environment(vics[x]))) continue;
        if(environment(vics[x]) != ETO) continue;

        if(vics[x]->reflex_save(26))
        {
            tell_object(vics[x], "%^BOLD%^%^CYAN%^The wave of energy washes over you "+
            "but you are unfazed by it!%^RESET%^");
            tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^CYAN%^ seems unfazed by the wave of "+
            "energy!%^RESET%^", vics[x]);
            continue;
        }
        tell_object(vics[x], "%^BOLD%^%^RED%^The wave of energy washes over you painfully, tearing "+
        "at your flesh!%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^RED%^The wave of energy washes over "+vics[x]->QCN+"%^BOLD%^%^RED%^, tearing "+
        "at "+vics[x]->QP+" flesh!%^RESET%^", vics[x]);
        if(interactive(vics[x])) dam = roll_dice(40, 4);
        else dam = roll_dice(100,4);
        vics[x]->cause_typed_damage(vics[x], vics[x]->return_target_limb(), dam, "force");
        if(!vics[x]->fort_save(20))
        {
            tell_object(vics[x], "%^BOLD%^%^BLACK%^You %^BOLD%^%^RED%^COLLAPSE%^BOLD%^%^BLACK%^ under the "+
            "force of the energy!%^RESET%^");

            tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^RED%^ COLLAPSES%^BOLD%^%^BLACK%^ under the force of the "+
            "energy!%^RESET%^", vics[x]);
            vics[x]->set_tripped(2, "%^BOLD%^%^CYAN%^You are struggling to get back to your feet!%^RESET%^");
        }
        continue;
    }
}


void pound(object targ)
{
    string me, limb;
    int dam;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    if(!objectp(environment(targ))) return;
    if(environment(targ) != ETO) return;
    me = TO->query_short();

    tell_object(targ, me+"%^BOLD%^%^RED% pounds you in the head with its large "+
    "meaty fist!%^RESET%^");

    tell_room(ETO, me+"%^BOLD%^%^RED%^ pounds "+targ->QCN+" in the head with its "+
    "large meaty fist!%^RESET%^");
    dam = roll_dice(35, 4);
    if(targ->fort_save(25)) dam /= 2;
    targ->cause_typed_damage(targ, "head", dam, "bludgeoning");
    if(!random(3)) call_out("pound", 6, targ);
    return;
}

void charge(object targ)
{
    string me, limb;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    me = TO->query_short();

    tell_object(targ, me +"%^BOLD%^%^RED%^ lowers his head and charges directly at you!%^RESET%^");

    tell_room(ETO, me+"%^BOLD%^%^RED%^ lowers his head and charges directly at "+targ->QCN+
    "%^BOLD%^%^RED%^!%^RESET%^", targ);

    if(targ->reflex_save(25))
    {
        tell_object(targ, "%^BOLD%^%^WHITE%^You are able to move out of the way before "+me+
        "%^BOLD%^%^WHITE%^ impales you with its horns!%^RESET%^");
        tell_room(ETO, targ->QCN+"%^BOLD%^%^WHITE%^ is able to move out of the way before "+me+
        "%^BOLD%^%^WHITE%^ impales "+targ->QO+"!%^RESET%^", targ);
        return;
    }
    limb = targ->return_target_limb();

    tell_object(targ, "%^BOLD%^%^BLACK%^You are unable to move out of the way in time and "+
    me+"%^BOLD%^%^BLACK%^ impales your "+limb+" wish its horns!%^RESET%^");

    tell_room(ETO, targ->QCN+"%^BOLD%^%^BLACK%^ is unable to move out of the way in time and "+
    me+"%^BOLD%^%^BLACK%^ impales "+targ->QP+" "+limb+" with its horns!%^RESET%^", targ);

    targ->cause_typed_damage(targ, limb, roll_dice(50, 4), "piercing");

    if(!random(5)) pound(targ);
    return;
}

void set_paralyzed(int time,string message)
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!enraged)
    {
        enraged = 1;
        tell_room(ETO, TO->query_short()+"%^BOLD%^%^GREEN%^ GROWLS%^BOLD%^%^RED%^ in %^BOLD%^%^BLACK%^RAGE%^BOLD%^%^RED%^!%^RESET%^");
        TO->add_attack_bonus(5);
        TO->add_damage_bonus(8);
    }
    return;
}

void set_tripped(int time, string message)
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!enraged)
    {
        enraged = 1;
        tell_room(ETO, TO->query_short()+"%^BOLD%^%^GREEN%^ GROWLS%^BOLD%^%^RED%^ in %^BOLD%^%^BLACK%^RAGE%^BOLD%^%^RED%^!%^RESET%^");
        TO->add_attack_bonus(5);
        TO->add_damage_bonus(8);
    }
    return;
}
