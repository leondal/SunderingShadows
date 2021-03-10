//tweaking this to be used for people breaking into vethor's tropies -H 12/29/20
#include <std.h>
#include <terrain.h>

inherit OBJECT;

int tracker;

void create()
{
    ::create();
    set_name("assassins mark");
    set_id( ({ "mark999"}) );
    set_short("");
    set_long("");
    set_weight(0);
    set_property("no animate",1);
    set_heart_beat(2);
    tracker = time() + 3600;
  
}

int set_timer(int x)
{
    tracker = time()+x;
}

void heart_beat()
{
    object creature;
    int level;
    int logintime;

    if(!objectp(ETO))
        return;
    if(!objectp(EETO))
        return;
    if(!interactive(ETO))
        return;
    if(!avatarp(ETO)) //so it doesn't kill cyric
        return;
    //send assassin if not in city
    if (tracker > time())
        return;
    //wait a day before attack
    if(member_array(EETO->query_terrain(), CIVILIZATION) != -1)
        return;
    if(EETO->query_property("no teleport"))
        return;

    logintime = (int)ETO->query_login_time();
    if(time() < logintime+600)
        return;

    creature = new("/d/dagger/Torm/city/thieves/mon/anne");

    tell_room(EETO, "%^RED%^A maid steps out of shadows and attacks "+ ETO->QCN + "!");

    level = ETO->query_base_character_level(); //ten levels above trackee when accounting for fighter levels

    creature->set_property("fighter_attacks_mod",level/4);
    creature->set_property("spell damage resistance",level);
    creature->add_damage_bonus(8+(level/8));
    creature->add_attack_bonus(8+(level/8));
    creature->set_mlevel("fighter",level);
    creature->set_hd(level + 5,20);
    creature->set_max_hp(level * 12 * 4);
    creature->set_hp(level * 12 * 4);
    creature->set_overall_ac(-1 * level -10);
    creature->set_mob_magic_resistance("very high");
    creature->set_property("damage resistance",level/4);
    creature->set_new_exp(level,"boss");
    creature->set_damage(2,level/2);
    creature->set_skill("athletics", level);
    creature->set_skill("stealth", level);

    creature->move(EETO);
    creature->force_me("speak wizish");
    creature->force_me("speech %^BOLD%^%^MAGENTA%^pu%^RESET%^%^MAGENTA%^r%^MAGENTA%^r%^BOLD%^%^BLACK%^ in a %^RESET%^%^MAGENTA%^s%^MAGENTA%^m%^BOLD%^%^MAGENTA%^ok%^RESET%^%^MAGENTA%^y%^BOLD%^%^BLACK%^ voice%^RESET%^");
    creature->force_me("say %^BOLD%^%^MAGENTA%^You have been chosen to %^RED%^die%^MAGENTA%^.%^RESET%^");
    creature->set_target(ETO->query_name());
    creature->kill_ob(ETO);
    creature->force_me("set seal");
    creature->force_me("crit " + ETO);
    TO->remove();
    return;
}
