#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/s/summon_natures_ally.c";

void create() 
{
    ::create();
    set_spell_name("summon natures ally vii");
    set_spell_level(([ "druid" : 7 ]));
    set_syntax("cast CLASS summon natures ally vii");
}

object createMon()
{
    int chooser=random(4);
    switch (chooser) 
    {
        case 0: return new("/d/magic/mon/naturesally/diretiger.c"); break;
        case 1: return new("/d/magic/mon/naturesally/greaterelemental.c"); break;
        case 2: return new("/d/magic/mon/naturesally/triceratops.c"); break;
        case 3: return new("/d/magic/mon/naturesally/tyrannosaurus.c"); break;
    }
}

void setup_beastie(object mymon) 
{
    if(!objectp(mymon)) return;
    mymon->set_size(2);
    mymon->set_mlevel("fighter",clevel);
    mymon->set_stats("strength",21);
    mymon->set_stats("intelligence",8);
    mymon->set_stats("dexterity",21);
    mymon->set_stats("wisdom",8);
    mymon->set_stats("charisma",8);
    mymon->set_stats("constitution",20);
    mymon->set_attacks_num((clevel/7)+1);
    mymon->set_damage(1,(clevel/2)+7);
    mymon->set_overall_ac(5-clevel);
    mymon->set_hd(clevel,15);
    mymon->set_max_hp(clevel * 15);
    mymon->set_hp(clevel * 15);
    mymon->set_property("effective_enchantment", (clevel / 7));
}