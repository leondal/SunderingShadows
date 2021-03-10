#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/s/summon_natures_ally.c";

void create() {
    ::create();
    set_spell_name("summon natures ally ii");
    set_spell_level(([ "ranger" : 2,"druid" : 2 ]));
    set_syntax("cast CLASS summon natures ally ii");
}

object createMon(){
    int chooser=random(7);
    switch (chooser) {
        case 0: return new("/d/magic/mon/naturesally/blackbear.c"); break;
        case 1: return new("/d/magic/mon/naturesally/crocodile.c"); break;
        case 2: return new("/d/magic/mon/naturesally/direbadger.c"); break;
        case 3: return new("/d/magic/mon/naturesally/direbat.c"); break;
        case 4: return new("/d/magic/mon/naturesally/hippogriff.c"); break;
        case 5: return new("/d/magic/mon/naturesally/mediumviper.c"); break;
        case 6: return new("/d/magic/mon/naturesally/wolverine.c"); break;
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
    mymon->set_attacks_num((clevel/12)+2);
    mymon->set_damage(1,(clevel/2)+2);
    mymon->set_overall_ac(10-clevel);
    mymon->set_hd(clevel,8);
    mymon->set_max_hp(clevel * 8);
    mymon->set_hp(clevel * 8);
    mymon->set_property("effective_enchantment", (clevel / 7));
}