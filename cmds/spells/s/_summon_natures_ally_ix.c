#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/s/summon_natures_ally.c";

void create()
{
    ::create();
    set_spell_name("summon natures ally ix");
    set_spell_level(([ "druid" : 9, "oracle":9 ]));
    set_mystery("nature");
    set_syntax("cast CLASS summon natures ally ix");
}

object createMon()
{
    int chooser=random(2);
    switch (chooser)
    {
        case 0: return new("/d/magic/mon/naturesally/elderelemental.c"); break;
        case 1: return new("/d/magic/mon/naturesally/unicorn.c"); break;
    }
}

void setup_beastie(object mymon)
{
    if(!objectp(mymon)) return;
    mymon->set_size(2);
    mymon->set_mlevel("fighter",clevel);
    mymon->set_stats("strength",25);
    mymon->set_stats("intelligence",8);
    mymon->set_stats("dexterity",25);
    mymon->set_stats("wisdom",8);
    mymon->set_stats("charisma",8);
    mymon->set_stats("constitution",25);
    mymon->set_attacks_num((clevel/7)+1);
    mymon->set_damage(1,(clevel/2)+15);
    mymon->set_overall_ac(0-clevel);
    mymon->set_hd(clevel,20);
    mymon->set_max_hp(clevel * 20);
    mymon->set_hp(clevel * 20);
    mymon->set_property("effective_enchantment", (clevel / 7));
}
