#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"

inherit MONSTER;

void create() 
{
    object ob;
    int x;
    ::create();
    set_race("spectre");
    set_name("rune keeper");
    set_id(({"rune keeper", "keeper", "keeper of the rune",
    "spectre"}));

    set_short("%^BLUE%^The Rune Keeper%^RESET%^");
    
    set_long("%^BLUE%^This frail creature stands around "+
    "five feet tall.  Its body is mysteriously cloaked "+
    "beneath a %^BOLD%^%^YELLOW%^golden silk robe%^RESET%^%^BLUE%^.  "+
    "You can see none of "+
    "its appendages, as they all seem to be inside of the robe.  "+
    "It doesn't appear very freigtening, yet some type of "+
    "aura that surrounds it, which seems to bend all light, "+
    "suggest otherwise.%^RESET%^");	
    
    set_property("posed", "%^YELLOW%^Surrounded By A Golden Aura%^RESET%^");
    set_property("full attacks", 1);
    set_body_type("humanoid");
    set_size(2);
    set_class("mage");
    set_guild_level("mage", 27);
    set_mlevel("mage", 27);
   	set_hp(645 + random(250));
    
    set_stats("strength",18);
    set_stats("intelligence",25);
    set_stats("wisdom",10);
    set_stats("charisma",6);
    set_stats("constitution",22);
    set_stats("dexterity",12);
    set_alignment(9);
    set_property("full attacks",1); 
    set_overall_ac(-14);
    set_spells(({"fireball", "meteor swarm", 
    "lower resistance", "chain lightning", 
    "lightning bolt", "prismatic spray", 
    "dispel magic"}));
    set_spell_chance(100);
    set_mob_magic_resistance("average");
    command("speech speak softly");
    command("speak wizish");
    ob = new(HHOB"azloths_blessing");
    ob->move(TO);
    command("wear robe");
    if(random(3))
    {
        ob->set_property("monsterweapon", 1);
    }
    set_new_exp(28, "normal");
}

void init()
{
    ::init();
    if(!objectp(TP)) return;
    if(TP->query_true_invis()) return;
    if(TP->is_player()) 
    {
        command("emote cackle");
        command("say I will not give up the stone easily!");
        new("/cmds/spells/b/_blink")->use_spell(TO,TO,27,27,"mage");
    }
    if(TP->is_player() || !random(10)) 
    {
        new("/cmds/spells/f/_fireball")->use_spell(TO, TP,27,27,"mage");
    }
}
