#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"

inherit MONSTER;

mapping myVictims = ([]);
int timer;
void process_victims();

void create() 
{
    object ob;
    string myDesc, *IDs;
    int x;
    ::create();
    switch(random(4)) 
    {
         case 0: 
             set_race("hobgoblin");
             myDesc = "A hobgoblin";
             break;
         case 1:
             set_race("orc");
             myDesc = "An orcish";
             break;
         case 2:
             set_race("goblin");
               myDesc = "A goblin";
             break;
         case 3:
             set_race("kobold");
              myDesc = "A kobold";
             break;
    }

    set_name("rune keeper");
    set_id(({"keeper", "rune keeper", "keeper of the rune", query_race(), "chsaidemob8x"}));

    set_short("%^BOLD%^%^WHITE%^"+myDesc+" r%^BOLD%^%^CYAN%^u"+
    "%^BOLD%^%^WHITE%^n%^BOLD%^%^CYAN%^e %^BOLD%^%^WHITE%^k%^BOLD%^"+
    "%^CYAN%^ee%^BOLD%^%^WHITE%^p%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^"+
    "r%^RESET%^");
    
    set_long("%^BOLD%^%^WHITE%^This creature appears quite confused. "+
    "There is a look of what could be considered immense fear "+
    "in his eyes mixed with a look of bewilderment, as if he is not "+
    "sure why or even how he is here. His body has been rudely carved with "+
    "strange magical %^BOLD%^%^CYAN%^symbols%^BOLD%^%^WHITE%^ which seem "+
    "to occasionally shift, causing him much pain in the process. "+
    "His face is set in an eternal scowl as he is obviously quite "+
    "angry with his current predicament.%^RESET%^");	
         
    set_property("full attacks", 1);
    set_body_type("humanoid");
  //  set_size(2);
    set_class("mage");
    set_guild_level("mage", 22);
	set_mlevel("mage", 22);
   	set_hp(575 + random(126));
    set_new_exp(22, "high");    
    set_stats("strength",20);
    set_stats("intelligence",25);
    set_stats("wisdom",10);
    set_stats("charisma",6);
    set_stats("constitution",22);
    set_stats("dexterity",12);
    set_alignment(9);
    set_property("full attacks",1); 
    set_overall_ac(-12);
    set_spells(({"fireball", "meteor swarm", 
    "lower resistance", "lightning bolt", "dispel magic"}));
    set_spell_chance(45);
    set_funcs(({"growl"}));
    ob = new(CROB+"crater_weapon");
    ob->move(TO);
    //new(CROB+"written_info")->move(TO);
    IDs = (string *)ob->query_id();
    command("wield "+IDs[0]);
    set_func_chance(35);
    set_mob_magic_resistance("average");
    timer = 1;
} 

void heart_beat()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    ::heart_beat();
    timer--;
    if(timer > 0) return;
    if(timer <= 0)
    {
        timer = 10;
        process_victims();
        return;
    }
}

void die(object ob)
{
    mixed *vics;
    int x;
    if(mapp(myVictims)) 
    {
        vics = keys(myVictims);
        if(sizeof(vics)) 
        {
            for(x = 0;x < sizeof(vics);x++)
            {
                if(objectp(vics[x]))
                {
                    tell_object(vics[x], "%^BOLD%^%^WHITE%^You are suddenly totally at ease as "+
                    "the sense of dread lifts from you!%^RESET%^");
                    continue;
                }
            }
        }
    }
    return ::die(ob);
}

void query_victims() { return myVictims; }

void process_victims()
{
    object *vics;
    mixed *tmp = ({});
    int x;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    //tell_room(ETO, "It is getting here & myVictims = "+identify(myVictims));
    if(!mapp(myVictims)) myVictims = ([]);
    vics = keys(myVictims);
    if(!sizeof(vics)) return;
    for(x = 0;x < sizeof(vics);x++)
    {
        if(!objectp(vics[x]))
        { 
            tmp += ({vics[x]});
            continue;
        }
        if(vics[x]->will_save(18) || myVictims[vics[x]] >= 4) 
        {
            tell_object(vics[x], "%^BOLD%^%^WHITE%^You are suddenly totally at ease as "+
            "the sense of dread lifts from you!%^RESET%^");
            tmp += ({vics[x]});
            continue;
        }
        tell_object(vics[x], "%^BOLD%^%^BLACK%^The sense of dread overwhelms you as you "+
        "remember the unnatural growl of "+TO->query_short()+"%^BOLD%^%^BLACK%^!%^RESET%^");
        tell_room(environment(vics[x]), vics[x]->QCN+"%^BOLD%^%^BLACK%^ SCREAMS and runs away "+
        "in terror!%^RESET%^", vics[x]);
        vics[x]->run_away();
        myVictims[vics[x]] += 1;
        continue;
    }
    if(sizeof(tmp)) 
    {
        for(x = 0;x < sizeof(tmp);x++)
        { 
            map_delete(myVictims, tmp[x]);
        }
    }
    return;
}

void add_victim(object targ)
{
    if(!objectp(targ)) return;
    if(!objectp(TO)) return;
    
    if(!mapp(myVictims)) myVictims = ([]);
    if(member_array(targ, keys(myVictims)) != -1) return;
    myVictims += ([targ : 0]);
    return;
}

void growl(object targ)
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;

    command("emoteat "+targ->query_name()+ " %^BOLD%^%^RED%^emits a "+
    "terrifying %^RESET%^%^RED%^g%^BOLD%^r%^RESET%^%^RED%^o%^BOLD%^"+
    "w%^RESET%^%^RED%^l%^BOLD%^%^RED%^ at $N%^RESET%^");

    if(targ->will_save(24)) 
    {
        tell_object(targ, "%^BOLD%^%^WHITE%^You resist the effects of the "+
        "%^RESET%^%^RED%^g%^BOLD%^r%^RESET%^%^RED%^o%^BOLD%^"+
        "w%^RESET%^%^RED%^l%^BOLD%^%^WHITE%^!%^RESET%^");
        
        tell_room(ETO, targ->QCN+"%^BOLD%^%^WHITE%^ seems unfazed by the "+
        "%^RESET%^%^RED%^g%^BOLD%^r%^RESET%^%^RED%^o%^BOLD%^"+
        "w%^RESET%^%^RED%^l%^BOLD%^%^WHITE%^.%^RESET%^", targ);
        return;
    }
    tell_object(targ, "%^BOLD%^%^BLACK%^You are suddenly overtaken with a sense "+
    "of utter dread by the unnatural %^RESET%^%^RED%^g%^BOLD%^r%^RESET%^%^RED%^o%^BOLD%^"+
    "w%^RESET%^%^RED%^l%^BOLD%^%^BLACK%^!%^RESET%^");

    tell_room(ETO, targ->QCN+"%^BOLD%^%^BLACK%^ appears absolutely overwhelmed with "+
    "a sense of utter dread!%^RESET%^", targ);

    targ->run_away();
    add_victim(targ);
    return;
}

