#include <std.h>
#include <daemons.h>
#include "../area_stuff.h"

inherit MONSTER;
int lev;

object stomach;

void create()
{
    ::create();
    set_name("a desert crawler");

    set_id(({"worm", "crawler", "desert crawler", "eldebarocreature"}));

    set_short("%^RESET%^%^ORANGE%^A massive d%^BOLD%^e%^RESET%^%^ORANGE%^s%^BOLD%^"+
    "e%^RESET%^%^ORANGE%^rt cr%^BOLD%^a%^RESET%^%^ORANGE%^wl%^BOLD%^e%^RESET%^%^ORANGE%^r%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^This monstrous worm looks a lot like a giant fluffy catepillar. "+
    "Its entire enormous body, save for its head, is covered with thick fuzz which is coated "+
    "with layer upon layer of sand. Its head is nothing short of %^BOLD%^%^GREEN%^hideous%^RESET%^"+
    "%^ORANGE%^ with a gaping %^BOLD%^%^BLACK%^maw%^RESET%^%^ORANGE%^ down which you can make out "+
    "row upon row of vicious razor sharp fangs which looks as if they would almost shred anything "+
    "the creature happened to swallow before it ever reached the stomach. The fuzz which covers the "+
    "rest of its body is absent and has been replaced by bony plates which seem quite thick. "+
    "There are no eyes that you can ascertain and you have no idea how the creature even knows where it is at.%^RESET%^");

    set_hd(40,2);
    set_hp(1600 + random(401));
    set_max_hp(query_hp());
    set_body_type("worm");
    set_damage(8,6);
    set_attacks_num(4);
    set_attack_limbs(({"mouth", "tail"}));
    set_base_damage_type("piercing");
    set_gender("neuter");
    set_race("worm");
    set_new_exp(40, "high");
    set_alignment(5);
    set_overall_ac(-20);
    set("aggressive", 65);
    set_stats("strength", 25);
    set_stats("intelligence", 1);
    set_stats("wisdom", 1);
    set_stats("constitution", 18);
    set_stats("dexterity", 12);
    set_stats("charisma", 6);
    set_property("full attacks", 1);
    set_func_chance(35);
    set_funcs(({"swallow"}));
    set_resistance("acid", 700);
    set_resistance("fire", 1000);
    set_hit_funcs((["mouth" : (:TO, "vicious_bite":)]));
    set_moving(1);
    set_speed(55);
    set_nogo(({DOCKROOM}));
}

int vicious_bite(object targ)
{
    if(!objectp(targ)) return roll_dice(8,6);
    tell_object(targ, TO->QCN+"%^BOLD%^%^RED%^ sinks several of its fangs deep into you!%^RESET%^");
    
    tell_room(ETO, TO->QCN+"%^BOLD%^%^RED%^ sinks several of its fangs into "+targ->QCN+
    "%^BOLD%^%^RED%^!%^RESET%^", targ);
    
    targ->cause_typed_damage(targ, 0, roll_dice(8,6), "piercing");
}

void burrow()
{
    string Troom, *Trooms;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    Trooms = get_dir(ELROOMSD+"*.c");
    Troom = ELROOMSD + Trooms[random(sizeof(Trooms))];
    
    tell_room(ETO, TO->query_short()+"%^BOLD%^%^RED%^ burrows down "+
    "into the thick and wet sand, disappearing, and the sand caves in "+
    "behind it!%^RESET%^");
    //tell_room(ETO, "Troom variable = "+Troom);
    TO->move(Troom);
    tell_room(ETO, TO->query_short()+"%^BOLD%^%^RED%^ suddenly bursts up "+
    "from beneath the sand!%^RESET%^");
    return;    
}

void swallow(object targ)
{
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    me = TO->query_short();
    
    if(targ->reflex_save(26))
    {
        tell_object(targ, me +"%^BOLD%^%^YELLOW%^ strikes "+
        "quickly but you are able to move just in time and "+
        "its %^BOLD%^%^GREEN%^hideous mouth%^BOLD%^%^YELLOW%^"+
        " seems to snarl at you!%^RESET%^");
        
        tell_room(ETO, me +"%^BOLD%^%^YELLOW%^ strikes quickly "+
        "at "+targ->QCN+"%^BOLD%^%^YELLOW%^ but "+targ->QS+" is "+
        "able to move just in time and its %^BOLD%^%^GREEN%^"+
        "hideous mouth%^BOLD%^%^YELLOW%^ seems to snarl at!%^RESET%^", targ);
        return;
    }
    
    tell_object(targ, me + "%^RESET%^%^ORANGE%^ latches onto you "+
    "with several of its %^BOLD%^%^WHITE%^vicious fangs"+
    "%^RESET%^%^ORANGE%^ and before you realize what "+
    "is happening you are pulled down its %^RED%^fanged%^RESET%^"+
    "%^ORANGE%^ throat!%^RESET%^");

    tell_room(ETO, me + "%^RESET%^%^ORANGE%^ latches onto "+targ->QCN+
    "%^%^RESET%^%^ORANGE%^ with several of its %^BOLD%^%^WHITE%^vicious fangs"+
    "%^RESET%^%^ORANGE%^ and before you realize what is happening "+
    me+" pulls "+targ->QO+" down its %^RED%^fanged%^RESET%^%^ORANGE%^"+
    " throat!%^RESET%^", targ);

    if(!objectp(stomach)) 
    {
        stomach = new(ELOB+"worm_stomach");
        stomach->set_my_worm(TO, targ);
    }
    targ->cause_typed_damage(targ, 0, roll_dice(20, 12), "piercing");
    targ->move(stomach);
    targ->force_me("look");
    if(!random(6)) burrow();
    return;
}


void die(object ob)
{
    object myOb;
    int flag;
    if(objectp(stomach)) stomach->set_my_room(ETO);
    TO->set_property("dying", 1);
    return ::die(ob);
}


