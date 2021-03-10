#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/s/summon_natures_ally.c";

void create() {
    ::create();
    set_spell_name("summon natures ally iv");
    set_spell_level(([ "ranger" : 4,"druid" : 4 ]));
    set_syntax("cast CLASS summon natures ally iv");
}

object createMon(){
    int chooser=random(8);
    switch (chooser) {
        case 0: return new("/d/magic/mon/naturesally/brownbear.c"); break;
        case 1: return new("/d/magic/mon/naturesally/giantcrocodile.c"); break;
        case 2: return new("/d/magic/mon/naturesally/deinonychus.c"); break;
        case 3: return new("/d/magic/mon/naturesally/direape.c"); break;
        case 4: return new("/d/magic/mon/naturesally/direboar.c"); break;
        case 5: return new("/d/magic/mon/naturesally/direwolverine.c"); break;
        case 6: return new("/d/magic/mon/naturesally/hugeviper.c"); break;
        case 7: return new("/d/magic/mon/naturesally/tiger.c"); break;
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
    mymon->set_attacks_num((clevel/8)+1);
    mymon->set_damage(1,(clevel/2)+2);
    mymon->set_overall_ac(10-clevel);
    mymon->set_hd(clevel,12);
    mymon->set_max_hp(clevel * 12);
    mymon->set_hp(clevel * 12);
    mymon->set_property("effective_enchantment", (clevel / 7));
}