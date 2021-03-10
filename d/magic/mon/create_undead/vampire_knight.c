#include <std.h>
#include "common.h"

inherit UNDEADINHERIT;

void create(){

    ::create();
    set_name("vampire");
    set_id(({"vampire knight","vampire","undead","Vampire knight"}));
    set_short("%^RESET%^%^RED%^Vampire %^BOLD%^%^BLACK%^knight%^RESET%^");
    set_long("%^RED%^Before you floats a powerful humanoid figure encased into heavy armour, wielding a huge two-handed sword. It's skin is gray, ears are bat like and eyes glow with undead red hatred towards all living. Despite being in heavy armor it floats above the ground with ease and moves with supernatural agility.");
    set_race("human");
    set_gender("male");

    set_size(2);
    set_class("fighter");

    set_guild_level("fighter",6);
    set_guild_level("mage",6);
    set_level(8);
    set_hd(8,8);

    set_max_hp(random(30)+255);
    set_hp(query_max_hp());

    set_wielding_limbs(({"right hand","left hand"}));
    set_property("undead",1);
    set_property("vampire",1);
    set_body_type("human");
    set_property("full attacks",1);

    set_stats("strength",22);
    set_stats("dexterity",22);
    set_stats("constitution",10);
    set_stats("intelligence",18);
    set_stats("wisdom",18);
    set_stats("charisma",22);

    set_property("cast and attack",1);
    set_spells(({"vampiric touch",
                    "orders oath",
                    "call lightning"}));
    set_spell_chance(25);

    set_alignment(3);

    {
        object stuff;

        stuff = new("/d/common/obj/weapon/bastard_two");
        stuff->set_property("monsterweapon", 1);
        stuff->move(TO);
        weapon = stuff;
        command("wield halberd");
        stuff = new("/d/common/obj/armour/plate");
        stuff->set_property("monsterweapon", 1);
        stuff->move(TO);
        command("wear plate");
        stuff = new("/d/common/obj/armour/greaves");
        stuff->set_property("monsterweapon", 1);
        stuff->move(TO);
        command("wear greaves");
    }

    add_search_path("/cmds/feats");
    add_search_path("/cmds/fighter");

    set_monster_feats(({
                "strength of arm",
                    "blade block",
                    "light weapon",
                    "rush",
                    }));

    set_fighter_style("soldier");
    command("message in floats in.");
    command("message out floats $D.");
}
