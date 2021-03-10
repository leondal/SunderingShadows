#include <std.h>
#include <daemons.h>
#include "../elfisland1.h"

inherit MONSTER;
object ob;

void create()
{
    ::create();
    set_name("laucian");
    set_id(({ "elf", "guard", "captain", "laurian amakiir" }));
    set_short("Laucian Amakiir, Captain of the Guard");
    set_long(
        "The male high elf before you stands at five and a half feet. His dark" +
        " black hair sharply contrasts with his pale skin. His deep green eyes" +
        " show a finely tuned alertness of his surroundings. He is in charge of" +
        " the daily patrols on the paths to the village and keeping the elves here" +
        " safe from invasion. By the way he carries himself, you can tell he does" +
        " that well."
        );
    set_class("fighter");
    set_guild_level("fighter", 15);
    set_class("thief");
    set_guild_level("thief", 15);
    set_mlevel("fighter", 15);
    set_mlevel("thief", 15);
    set_mob_magic_resistance("average");
    set_race("elf");
    set_body_type("humanoid");
    set_gender("male");
    set_property("no animate", 1);
    set_hd(25, 8);
    set_alignment(4);
    set_max_hp(300);
    set_hp(300);
    set_overall_ac(-10);
    set_size(2);
    set_exp(15000);
    ob = new(SPEC2 + "elfsword");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield longsword");
    ob = new(SPEC2 + "elfsword");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield longsword");
    ob = new(POW);
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    set_languages(({ "elven" }));
    command("speak elven");
    set_property("full attacks", 1);
    set("aggressive", "kill_evil");
    set_stats("strength", 19);
    set_stats("constitution", 16);
    set_stats("intelligence", 15);
    set_stats("wisdom", 17);
    set_stats("charisma", 14);
    set_stats("dexterity", 20);
    set_func_chance(45);
    set_funcs(({ "flashit", "rushit", "rushit" }));
    set_thief_skill("move silently", 95);
    set_thief_skill("hide in shadows", 95);
    add_search_path("/cmds/fighter");
    add_search_path("/cmds/thief");
    set_scrambling(1);
    set_monster_feats(({
        "parry",
        "powerattack",
        "shatter",
        "sunder",
        "rush",
        "dodge",
        "mobility",
        "evasion",
        "scramble",
        "combat reflexes"
    }));
}

void init()
{
    string* evil;
    ::init();
    if (wizardp(TP)) {
        return 1;
    }
    evil = KILLING_D->query_evil_bounties();
    if (member_array(TP->query_name(), evil) != -1) {
        force_me("say %^BOLD%^%^GREEN%^Your evil acts must be stopped!!%^RESET%^");
        force_me("emote moves quicker than you anticipated");
        force_me("stab " + TP->query_name());
        force_me("toss powder at " + TP->query_name());
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
