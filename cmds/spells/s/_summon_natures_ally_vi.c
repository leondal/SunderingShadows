#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/s/summon_natures_ally.c";

void create()
{
    ::create();
    set_spell_name("summon natures ally vi");
    set_spell_level(([ "druid" : 6, "oracle":6]));
    set_mystery("nature");
    set_syntax("cast CLASS summon natures ally vi");
}

object createMon()
{
    int chooser=random(6); // increase as we add
    switch (chooser)
    {
        case 0: return new("/d/magic/mon/naturesally/direbear.c"); break;
        case 1: return new("/d/magic/mon/naturesally/hugeelemental.c"); break;
        case 2: return new("/d/magic/mon/naturesally/elephant.c"); break;
        case 3: return new("/d/magic/mon/naturesally/girallon.c"); break;
        case 4: return new("/d/magic/mon/naturesally/megaraptor.c"); break;
        case 5: return new("/d/magic/mon/naturesally/salamander.c"); break;
    }
}

void setup_beastie(object mymon)
{
    if(!objectp(mymon)) return;
    mymon->set_size(2);
    mymon->set_mlevel("fighter",clevel);
    mymon->set_stats("strength",20);
    mymon->set_stats("intelligence",8);
    mymon->set_stats("dexterity",20);
    mymon->set_stats("wisdom",8);
    mymon->set_stats("charisma",8);
    mymon->set_stats("constitution",18);
    mymon->set_attacks_num((clevel/7)+1);
    mymon->set_damage(1,(clevel/2)+6);
    mymon->set_overall_ac(6-clevel);
    mymon->set_hd(clevel,14);
    mymon->set_max_hp(clevel * 14);
    mymon->set_hp(clevel * 14);
    mymon->set_property("effective_enchantment", (clevel / 7));
}
