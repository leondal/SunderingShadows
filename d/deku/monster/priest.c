#include <std.h>
#include "/d/common/common.h"
inherit MONSTER;

create() {
    object ob;
    int x;
    ::create();
    set_name("priest");
    set_id(({"priest","cleric"}));
    set_gender("male");
    set_short("A robed human");
    set_long("This man stands tall and stooped, his body cloaked "+
    "with a robe.  His black hair is dirty, unkept, and falls "+
    "down slightly below his ears, his eyes are intense and "+
    "strangely dark.  The flesh of this man that is visible "+
    "beneath his robe is a ghastly white, as if he has not saw "+
    "sunlight in a very long time.  An aura of unknown origin "+
    "seems to linger about him, leaving you with a sick feeling.");
    set_class("cleric");
    set_mlevel("cleric",20);
    set_guild_level("cleric",20);
    set_stats("strength",9);
    set_stats("wisdom",16);
    set_stats("intelligence",14);
    set_stats("dexterity",10);
    set_stats("constitution",13);
    set_stats("charisma",11);
    set("aggressive",1);
    set_race("human");
    set_hp(245 + random(35));
    //set_exp(query_max_hp() * 20);
	set_new_exp(20, "high");
    set_property("swarm",1);
    set_alignment(3);
    set_overall_ac(4);
    set_spells(({"flame strike","cause critical wounds","cause serious wounds"}));
    set_spell_chance(75);  
    if(random(10) >= 8) {
        new("/d/deku/armours/robe")->move(TO);
    }
    else {
        new("/d/common/obj/armour/robe")->move(TO);
    } 
    command("wear robe"); 

    switch(random(5)) {
        case 0..3 :  RANDGEAR->arm_me(TO, "bluntm", 20, random(2)+1);   break;
        case 4    :  ob = new("/d/deku/weapons/flailplat");
                     ob->move(TO);
                     force_me("wield flail");
                     break;
    } 
    set_funcs(({"heal"}));
    set_func_chance(10);
}

void heal(object ob) {
    switch(random(100)) {
        case 0..98:
            new("/cmds/spells/c/_cure_critical_wounds.c")->use_spell(TO,TO,20,100,"cleric");
            break;
        case 99:
            new("/cmds/spells/h/_heal.c")->use_spell(TO,TO,20,100,"cleric");
            break;
    }
    return;
}