#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/s/summon_natures_ally.c";

void create()
{
    ::create();
    set_spell_name("summon natures ally v");
    set_spell_level(([ "druid" : 5,]));
    set_domains("animal");
    set_syntax("cast CLASS summon natures ally v");
}


object createMon()
{
    int chooser=random(8); // open this up as more monsters are added
    switch (chooser)
    {
        case 0: return new("/d/magic/mon/naturesally/polarbear.c"); break;
        case 1: return new("/d/magic/mon/naturesally/arrowhawk.c"); break;
        case 2: return new("/d/magic/mon/naturesally/direlion.c"); break;
        case 3: return new("/d/magic/mon/naturesally/griffon.c"); break;
        case 4: return new("/d/magic/mon/naturesally/rhinoceros.c"); break;
        case 5: return new("/d/magic/mon/naturesally/nixie.c"); break;
        case 6: return new("/d/magic/mon/naturesally/greater_satyr.c"); break;
        default: return new("/d/magic/mon/naturesally/janni.c"); break;
    }
}

void setup_beastie(object mymon)
{
    if(!objectp(mymon)) return;
    mymon->set_size(2);
    mymon->set_mlevel("fighter",clevel);
    mymon->set_stats("strength",19);
    mymon->set_stats("intelligence",8);
    mymon->set_stats("dexterity",19);
    mymon->set_stats("wisdom",8);
    mymon->set_stats("charisma",8);
    mymon->set_stats("constitution",16);
    mymon->set_attacks_num((clevel/7)+1);
    mymon->set_damage(1,(clevel/2)+4);
    mymon->set_overall_ac(8-clevel);
    mymon->set_hd(clevel,13);
    mymon->set_max_hp(clevel * 13);
    mymon->set_hp(clevel * 13);
    mymon->set_property("effective_enchantment", (clevel / 7));
}
