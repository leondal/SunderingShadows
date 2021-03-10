#include <std.h>
#include "../keep.h"

inherit MONSTER;

int do_my_attack(object to) 
{
    object *exits, *alive;
    string *killers, ob, exit;
    int i, people, x, y;

    exits = environment(to)->query_exits();
    i = sizeof(exits);
    for(y = 0;y < i;y++) 
    {
        if(!TP->query_invis()) 
        {
            if(!objectp(to)) return 1;
            exit = exits[y];
            if(environment(to)->query_blocked(exit) != 0) continue;
            to->force_me("block " + exits[y]);
            break;
        }
        break;
    }
    to->force_me("kill "+TPQN);
    if(random(11) >= 6) 
    {
        to->force_me("rush "+TPQN);
    }
    return 1;
}

void do_attack2() 
{
    if(!TP->query_invis()) 
    {
        return call_out("do_my_attack",0,TO);
    }
}   

void create() 
{
    ::create();
    set_race("orc");
    set_gender("male");
    set_class("fighter");
    add_search_path("/cmds/fighter");
    set("aggressive", "do_attack2");
    set_alignment(6);
    set_size(2);
    set_property("full attacks",1);
    set_property("swarm",1);
    set_max_level(25);
    set_monster_feats(({
        "parry",
        "powerattack",
        "shatter",
        "sunder",
   }));
   set_funcs(({"rushit","flashit","flashit"}));
   set_func_chance(30);   	
}

void init() 
{
    ::init();
    if(TP->query_invis()) return;
    if(random(5) >= 3) 
    {
        switch(random(2)) 
        {
            case 0:
                if(TO->query_attack_bonus() > 1) 
                {
                    TO->force_me("emote readies his weapons defensively");
                    TO->set_ac((int)TO->query_ac() - 1);
                    TO->add_attack_bonus(-1);
                }
                break;
            case 1:
                if(TO->query_attack_bonus() < 8) 
                {
                    TO->force_me("emote readies his weapons offensively");
                    TO->set_ac((int)TO->query_ac() + 1);
                    TO->add_attack_bonus(1);
                }
                break;
        }
    }
}

void rushit(object targ) 
{
    TO->force_me("rush "+targ->query_name());
}

void flashit(object targ) 
{
    TO->force_me("flash "+targ->query_name());
}