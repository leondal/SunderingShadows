#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/s/summon_natures_ally.c";

void create() {
    ::create();
    set_spell_name("summon natures ally iii");
    set_spell_level(([ "ranger" : 3,"druid" : 3 ]));
    set_syntax("cast CLASS summon natures ally iii");
}

object createMon(){
    int chooser=random(9);
    switch (chooser) {
        case 0: return new("/d/magic/mon/naturesally/ape.c"); break;
        case 1: return new("/d/magic/mon/naturesally/direweasel.c"); break;
        case 2: return new("/d/magic/mon/naturesally/direwolf.c"); break;
        case 3: return new("/d/magic/mon/naturesally/gianteagle.c"); break;
        case 4: return new("/d/magic/mon/naturesally/lion.c"); break;
        case 5: return new("/d/magic/mon/naturesally/giantowl.c"); break;
        case 6: return new("/d/magic/mon/naturesally/satyr.c"); break;
        case 7: return new("/d/magic/mon/naturesally/constrictor.c"); break;
        case 8: return new("/d/magic/mon/naturesally/largeviper.c"); break;
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
    mymon->set_attacks_num((clevel/10)+2);
    mymon->set_damage(1,(clevel/2)+2);
    mymon->set_overall_ac(10-clevel);
    mymon->set_hd(clevel,10);
    mymon->set_max_hp(clevel * 10);
    mymon->set_hp(clevel * 10);
    mymon->set_property("effective_enchantment", (clevel / 7));
}