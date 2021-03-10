#include <std.h>
#include "../undead.h"

inherit CREATURE;

int FLAG=0;
  
void create() 
{
    ::create();
    set_name("Kartakass");
    set_id(({"kartakass","vampire","master","lord"}));
    set_race("undead");
    set_body_type("human");
    set_gender("male");
    set_short("%^RED%^Kartakass, Lord of the Undead%^RESET%^");
    set_long("Kartakass is hardly the only name for this vile creature, for over the " 
        "course of centuries beings such as he tend to take on many names in order " 
        "to conceal their identity from the order of good.  For the last century " 
        "though this being has gone by the dreaded name of Kartakass.  As he crushed "  
        "villages and pillaged nations with his dark army, that name spread like " 
        "wildfire.  Eventually an army was formed to oppose Kartakass.  This army was " 
        "lead by the Dwarven High King Morock and it was a mighty army indeed.  The " 
        "battle between these two armies lasted for months.  The deaths were " 
        "innumerable, but eventually it looked as though King Morock would finally " 
        "push through the enemy lines and have a clear victory afterwards.  But "  
        "before the King was able to deliver his death blow, a fellow Dwarven Lord, " 
        "and trusted friend, betrayed him.  Without his leadership the Army of Light "  
        "quickly crumbled and was overrun by undead.  With no one left to stand in " 
        "his way Kartakass proceeded to conquer the entire land.  When he was done, he " 
        "forced the people to build him a Tomb, where he might sleep and regain his " 
        "strength for the next battle.  Leaving the Seer in charge of his armies, he " 
        "stayed in his Tomb.  But now you have awakened him, and his fury is " 
        "tremendous!");
    set_class("mage");
    set_mlevel("mage",35);
    set_guild_level("mage",35);
    set("aggressive", "aggfunc");
    set_mob_magic_resistance("average");
    set_alignment(9);
    set_size(2);
    set_hd(35,8);
    set_hp(1000);
    set_spell_chance(100);
    set_spells(({
        "scorcher",
        "magic missile",
        "meteor swarm",
        "powerword stun",
        "lower resistance",
        "fireball",
        "prismatic spray",
        "cone of cold",
              }));
    add_money("gold",2000 + random(3000));
    set_exp(90000);
    set_new_exp(25,"boss");
    new(OBJS"black_heal.c")->move(TO);
    add_money("gold",random(15000)+550);
    add_money("platinum",random(5000)+300);
}

void aggfunc()
{
    if(!objectp(TO))            { return; }
    if(!objectp(ETO))           { return; }
    if(!objectp(TP))            { return; }
    if(TP->query_true_invis())  { return; }

    command("speech say in a hollow, ageless tone");
    command("say Your time has come to an end mortal, prepare to die!");
    command("say %^RED%^Your lifeless body shall soon join my army!%^RESET%^");
    if(!FLAG)
    {
        new("/cmds/spells/b/_blink.c")->use_spell(TO,TO,35,100,"mage");
        new("/cmds/spells/s/_stoneskin.c")->use_spell(TO,"kartakass",35,100,"mage");
        new("/cmds/spells/a/_armor.c")->use_spell(TO,"kartakass",35,100,"mage");
        new("/cmds/spells/d/_dragon_scales.c")->use_spell(TO,TO,35,100,"mage");
        new("/cmds/spells/l/_lower_resistance.c")->use_spell(TO,TPQN,35,100,"mage");
        new("/cmds/spells/m/_monster_summoning_i.c")->use_spell(TO,TP,35,100,"mage");
        new("/cmds/spells/m/_monster_summoning_i.c")->use_spell(TO,TP,35,100,"mage");
        new("/cmds/spells/m/_monster_summoning_i.c")->use_spell(TO,TP,35,100,"mage");

        FLAG = 1;
        TO->kill_ob(TP,0);
        TO->set("aggressive", 25);
        call_out("reset_flag",250,TO);
    }
    return;
}

void heart_beat() 
{
    ::heart_beat();
    if(!objectp(TO))    { return; }
    if(!objectp(ETO))   { return; }
    if(TO->query_hp() < TO->query_max_hp()) { add_hp(roll_dice(2,6)); }
    return;
}

void die(object ob) 
{
    int i;
    if(!objectp(TO))    { return; }
    if(!objectp(ETO))   { return; }

    for(i=0;i<sizeof(filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D));i++)
    {    
        new(OBJS"diamond_ring.c")->move(TO);
    }
    ::die(ob);
    return;
}

void reset_flag()
{
    FLAG = 0;
    TO->set("aggressive", "aggfunc");
    return;
}