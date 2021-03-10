#include <std.h>
inherit MONSTER;

create() {
    object ob;
    ::create();
    set_name("priest");
    set_id(({"high cleric","priest","cleric"}));
    set_gender("male");
    set_short("A robed human");
    set_long("This man stands tall and proud, his body cloaked "+
    "with a robe.  His short brown hair is well kept and his "+
    "eyes are an intense blue.  The parts of his flesh that "+
    "are visible beneath his robe are a crisp tan, suggesting "+
    "that this man enjoys the sunlight quite frequently.   "+
    "An aura of unknown origin, which seems horribly out of "+
    "place, lingers about him, leaving you with a sick feeling.");
    set("aggressive",1);
    set_hd(24);
    set_class("cleric");
    set_mlevel("cleric",24);
    set_guild_level("cleric",24); 
    set_race("human");
    set_alignment(6);
    set_stats("strength",12);
    set_stats("wisdom",19);
    set_stats("intelligence",15);
    set_stats("constitution",12);
    set_stats("charisma",17);
    set_stats("dexterity",14);
    set_hp(325 + random(41));
    //set_exp(query_max_hp() * 20);
	set_new_exp(20, "high");
    set_overall_ac(4);
    set_property("swarm",1);
    new("/d/common/obj/weapon/mace")->move(TO);
    command("wield mace");
    if(random(3)) {
        ob=new("/d/deku/armours/ring_p");
        ob->set_property("enchantment",1);
        ob->move(this_object());
        command("wear ring");
    }
    set_spells(({ "flame strike", "limb attack", 
    "cause critical wounds", "darkbolt" }));
    set_spell_chance(50);
    if(random(10) >= 5) {
        new("/d/deku/armours/robe")->move(TO);
    }
    else {
        new("/d/common/obj/armour/robe")->move(TO);
    }
    command("wear robe");
    set_funcs(({"heal"}));
    set_func_chance(25);
}

void heal(object ob) {
    switch(random(100)) {
        case 0..95:
            new("/cmds/spells/c/_cure_critical_wounds.c")->use_spell(TO,TO,20,100,"cleric");
            break;
        case 96..99:
            new("/cmds/spells/h/_heal.c")->use_spell(TO,TO,20,100,"cleric");
            break;
    }
    return;
}
