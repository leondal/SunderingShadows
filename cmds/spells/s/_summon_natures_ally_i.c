#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/s/summon_natures_ally.c";

void create() {
    ::create();
    set_spell_name("summon natures ally i");
    set_spell_level(([ "ranger" : 1,"druid" : 1 ]));
    set_syntax("cast CLASS summon natures ally i");
}

object createMon(){
    int chooser=random(6);
    switch (chooser) {
        case 0: return new("/d/magic/mon/naturesally/direrat.c"); break;
        case 1: return new("/d/magic/mon/naturesally/eagle.c"); break;
        case 2: return new("/d/magic/mon/naturesally/monkey.c"); break;
        case 3: return new("/d/magic/mon/naturesally/owl.c"); break;
        case 4: return new("/d/magic/mon/naturesally/smallviper.c"); break;
        case 5: return new("/d/magic/mon/naturesally/wolf.c"); break;
    }
}

void setup_beastie(object mymon) {
    if(!objectp(mymon)) return;
    mymon->set_size(2);
    mymon->set_mlevel("fighter",clevel);
    mymon->set_stats("strength",18);
    mymon->set_stats("intelligence",8);
    mymon->set_stats("dexterity",18);
    mymon->set_stats("wisdom",8);
    mymon->set_stats("charisma",8);
    mymon->set_stats("constitution",14);
    mymon->set_attacks_num((clevel/15)+2);
    mymon->set_damage(1,(clevel/2)+2);
    mymon->set_overall_ac(10-clevel);
    mymon->set_hd(clevel,6);
    mymon->set_max_hp(clevel * 6);
    mymon->set_hp(clevel * 6);
    mymon->set_property("effective_enchantment", (clevel / 7));
}