#include <std.h>
#include "../elfisland1.h"

inherit MONSTER;

void create()
{
    ::create();
    set_name("guard");
    set_id(({ "elf", "guard" }));
    set_short("Elven guard");
    set_long(
        "This elven guard is dedicated to protecting villagers and the" +
        " paths leading to the elven village of Synoria."
        );
    set_class("fighter");
    set_guild_level("fighter", 15);
    set_mlevel("fighter", 15);
    set_race("elf");
    set_body_type("humanoid");
    set_gender("male");
    set_hd(15, 8);
    set_alignment(7);
    set_max_hp(145);
    set_hp(145);
    set_overall_ac(2);
    set_languages(({ "elven" }));
    command("speak elven");
    set_size(2);
    set_exp(2500);
    set_wielding_limbs(({ "right hand", "left hand" }));
    new(WEAP + "longsword")->move(TO);
    command("wield sword in left hand");
    new(WEAP + "shortsword")->move(TO);
    command("wield sword in right hand");
    set_property("full attacks", 1);
    set_stats("strength", 16);
    set_stats("constitution", 16);
    set_stats("intelligence", 15);
    set_stats("wisdom", 13);
    set_stats("charisma", 14);
    set_stats("dexterity", 18);
    set_func_chance(45);
    set_funcs(({ "flashit", "rushit", "rushit" }));
    add_search_path("/cmds/fighter");
    set("aggressive", "kill_evil");
    remove_property("swarm");
    set_monster_feats(({
        "parry",
        "powerattack",
        "shatter",
        "sunder",
        "rush"
    }));
}

void init()
{
    ::init();
    if ((string)TP->query_name() == "raider") {
        command("say %^BOLD%^%^GREEN%^Leave our village!%^RESET%^");
        command("kill raider");
    }
}

void rushit(object targ)
{
    TO->force_me("rush " + targ->query_name());
}

void flashit(object targ)
{
    TO->force_me("flash " + targ->query_name());
}

void kill_evil()
{
    string race;
    object shape;
    race = TP->query_race();
    if (objectp(shape = TP->query_property("shapeshifted"))) {
        race = (string)shape->query_shape_race();
    }
    if (objectp(shape = TP->query_property("altered"))) {
        race = (string)shape->query_shape_race();
    }
    if (race == "drow" || race == "half-drow" || race == "goblin" || race == "hobgoblin" ||
        race == "orc" || race == "half-orc" || race == "ogre" || race == "half-ogre" ||
        race == "kobold" || race == "ogre-mage" || race == "bugbear" || race == "wemic" ||
        race == "gnoll" ||
        race == "troll" ||
        race == "ratkin" ||
        race == "wererat") {
        force_me("say %^BOLD%^%^GREEN%^Be gone of this village you evil scum!%^RESET%^");
        force_me("kill " + TP->query_name());
        command("parry");
        return;
    }
}
