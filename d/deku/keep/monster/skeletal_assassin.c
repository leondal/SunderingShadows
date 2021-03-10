#include <std.h>
#include <daemons.h>
#include "../keep.h"
#include "/d/deku/inherits/forest.h"

inherit MONSTER;

void create() 
{
    ::create();
    set_name("A Skeletal Assassin");
    set_id(({"skeleton","assassin", "skeletal assassin", "deku_skel_assassin"}));
    set_race("skeleton");
    set_gender("neuter");
    set_short("%^BOLD%^%^WHITE%^A Skeletal Assassin%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This skeletal creature appears humanoid.  "+
    "You are unsure of its exact race in life, but it was most likely a "+
    "human.  Most of its bones have changed color to a dark, almost black "+
    "hue, as a result of some type of unknown magical manipulation.  It stands "+
    "only about five feet in height and looks rather weak, though "+
    "it seems to move about with a quickness that's unlike most of it's undead "+
    "family.  It wears no armor, however, it carries two daggers, "+
    "one of them flaming and the other appears to be almost frozen.%^RESET%^");
    set_body_type("humanoid");
    set_alignment(9);
    set_property("full attacks", 1);
    set_hd(28,1);
    set_class("fighter");
    set_class("thief");
    set_mlevel("thief", 28);
    set_guild_level("thief", 28);
    set_mlevel("fighter", 28);
    set_guild_level("fighter", 28);
    set_size(2);
    set_stats("dexterity", 22);
    set_stats("strength", 17);
    set_property("swarm", 1);
  	set_hp(800 + random(51));
    set_max_hp(query_hp());
    set_new_exp(25, "very high");
    set_overall_ac(-12);
    set_property("no hold", 1);
    set_property("no paralyze", 1);
    new("/d/deku/weapons/fire_dagger")->move(TO);
    command("wield dagger");
    new("/d/laerad/obj/ice_dagger")->move(TO);
    command("wield dagger");
    set_magic_hidden(1);
    command("speech hisses");
    command("speak common");
    set_lang("common", 100);
    add_search_path("/cmds/fighter");
    add_search_path("/cmds/thief");
    set_funcs(({"flash_em"}));
    set_func_chance(25);
    set_speed(80 + random(21));
    set_moving(1);
    set_property("undead", 1);
    set_property("no kill", 1);
    set_monster_feats(({
        "parry",
        "powerattack",
        "shatter",
        "sunder",
        "rush",
        "dodge",
        "mobility",
        "evasion",
        "combat reflexes",	  
    }));	 	
}

void heart_beat() 
{
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!sizeof(TO->query_attackers())) 
    {
        if(!TO->query_magic_hidden()) 
        {
            TO->set_magic_hidden(1);
        }
    }
    return;
}

void init() 
{
    ::init();
    if(!objectp(TP)) return;
    if(!objectp(TO)) return;
    if(TP->query_true_invis()) return;
    if(TP->id("salvirus") || TP->id("blackthornshadowguard")) return;
    if(TP->query_invis()) 
    {
        command("say I can see you... fool...");
    }
    if(objectp(TO) && objectp(TP))
    {
        command("stab "+TPQN);
        command("rush "+TPQN);
        if(!TO->query_scrambling()) 
        {
            command("scramble");
        }
        if(!TO->query_parrying()) 
        {
            command("parry");
        }
    }
}

void flash_em(object targ) 
{
    if(!objectp(TO)) return;
    command("flash");
}

void die(object ob)
{
    object *ppl;
    int x;
    if(base_name(ETO) == KEEPR+"burial_chamber_5") 
    {
        return ::die(TO);
    }
    if(!objectp(ETO)) return ::die(TO);
    ppl = all_living(ETO);
    for(x = 0;x < sizeof(ppl);x++)
    {
        if(!userp(ppl[x])) continue;
        if(!ppl[x]->query("last_burial_name"))
        {
            ppl[x]->set("last_burial_name", "Maltoore");
            continue;
        }
        continue;
    }
    tell_room(ETO, "%^RED%^The skeletal assassin utters quickly%^RESET%^:  "+
    "%^RESET%^Maltoore...");
    return ::die(TO);
}
