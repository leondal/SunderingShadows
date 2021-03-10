#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/s/summon_natures_ally.c";

void create()
{
    ::create();
    set_spell_name("summon natures ally iix");
    set_spell_level(([ "druid" : 8,]));
    set_syntax("cast CLASS summon natures ally iix");
}

object createMon()
{
    int chooser=random(3);
    switch (chooser)
    {
        case 0: return new("/d/magic/mon/naturesally/roc.c"); break;
        case 1: return new("/d/magic/mon/naturesally/salamandernoble.c"); break;
        case 2: return new("/d/magic/mon/naturesally/tojanidaelder.c"); break;
    }
}

void setup_beastie(object mymon)
{
    if(!objectp(mymon)) return;
    mymon->set_size(2);
    mymon->set_mlevel("fighter",clevel);
    mymon->set_stats("strength",23);
    mymon->set_stats("intelligence",8);
    mymon->set_stats("dexterity",23);
    mymon->set_stats("wisdom",8);
    mymon->set_stats("charisma",8);
    mymon->set_stats("constitution",23);
    mymon->set_attacks_num((clevel/7)+1);
    mymon->set_damage(1,(clevel/2)+10);
    mymon->set_overall_ac(3-clevel);
    mymon->set_hd(clevel,18);
    mymon->set_max_hp(clevel * 18);
    mymon->set_hp(clevel * 18);
    mymon->set_property("effective_enchantment", (clevel / 7));
}
