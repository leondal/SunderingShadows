#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit MONSTER;

int x;

void create() 
{
    int y, i;
    ::create();
    set_name("golem master");
    set_id( ({"golem master", "master", "javiisees"}));
    set_gender("male");
    set_race("dwarf");
    set_short("%^RED%^Javiisees, The %^YELLOW%^G%^RED%^"+
    "o%^YELLOW%^l%^RED%^e%^YELLOW%^m%^RESET%^%^RED%^ "+
    "Mast%^YELLOW%^e%^RESET%^%^RED%^r%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This ashen skinned Dwarf stands approximately "+
    "three feet tall and carries himself hunched, so his height appears "+
    "even slighter.  Despite this apparently carelessness about him, "+
    "his face reveals a discplined, intelligent, and very very "+
    "angry demeanor.  His eyes are a brilliant, dark, and "+
    "menacing %^RED%^red%^BOLD%^%^BLACK%^, reflecting back "+
    "at you his inner soul.  He carries, readied, a "+
    "red ruby pick.%^RESET%^");
  
    set_body_type("human");
    set_size(1);
    set_alignment(9);
    add_money("gold", 2000 + random(1200));
    x = 26;
    set_hd(x,1);
    set_stats("strength",17);
    set_stats("intelligence",15);
    set_stats("constitution",14);
    set_stats("dexterity",19);
    set_stats("wisdom",9);
    set_stats("charisma",8);
    set_class("fighter");    
    set_mlevel("fighter", x);
    set_class("thief");
    set_mlevel("thief",x);
    set_guild_level("fighter",x);
    set_guild_level("thief",x);
    set_property("full attacks",1);
    set_mob_magic_resistance("average");
    set_hp(700 + random(51));
    //set_exp(12000);
    set_new_exp(25, "very high");
    set_funcs(({"golem_helper"}));
    set_func_chance(25);
    set_max_level(30);
    set("aggressive","kill_things");
    new(DEKU_WEP"ruby_pick")->move(TO);
    command("wield pick");
    set_overall_ac(-8); 
    new(DEKU_ARM"fire_gloves")->move(TO);    
    command("wear gloves");
}

void heart_beat()
{
    object k, *atts;
    int y;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    atts = TO->query_attackers();
    if(!sizeof(atts)) return;
    for(y = 0;y < sizeof(atts);y++) 
    {
        if(atts[y]->id("saidedekufiremon")) 
        {
            TO->remove_attacker(atts[y]);
            atts[y]->remove_attacker(TO);
            return;
        }
    }
}


void golem_helper(object targ) 
{
    int x;
    object ob;
    if(!random(2)) return;
    if(!TO) return;
    command("say you wanna fight?????? Then fight these, you derty "+
    "elf arse!!");
    x = 1 + random(2);
    while(x > 0)	
    {
        tell_room(ETO, "%^BOLD%^%^RED%^A hellfire golem lumbers into "+
        "the room, in protection of Javiisees!%^RESET%^");
        ob = new(DEKU_MON"hellfire_golem");
        ob->move(ETO);
        ob->command("protect golem master");
        ob->command("protect golem master");
        if(!TO) return;
        x--;
    }
}
        

void kill_things() 
{
    if(!objectp(TP)) return;
    if(TP->query_true_invis()) return;

    switch(random(7)) 
    {
        case 0..2:
            command("say you'll have yours, you sneaky FREAK!!!!!!");
            TO->add_attack_bonus(6);
            command("stab "+TPQN);
            TO->add_attack_bonus(-6);
            command("kill "+TPQN);
            return 1;
        case 3..6:
            command("say damn you, damn you to HELL!!!!");
            command("kill "+TPQN);
            command("rush "+TPQN);
            return 1;
    }            
}            
            
void die(object ob) 
{
    tell_room(ETO, "%^BOLD%^%^BLUE%^Javiisees whispers hoarsely:"+
    "%^RESET%^ A dwarven puzzle box can be solved with the "+
    "phrase 'garbage should be collected'... and it should....%^RESET%^");
    return ::die(ob);
}

