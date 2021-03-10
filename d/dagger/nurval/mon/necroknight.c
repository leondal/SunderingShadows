#include <std.h>

inherit "/std/monster";

/**
 * Necropolitain knights are not mindless undead.
 */
void create()
{
    object weapon;
    int level = 50;

    ::create();
    set_name("knight");
    set_id(({"knight","guard","undead", "graveknight"}));
    set_short("%^BOLD%^%^BLUE%^Grave%^BOLD%^%^BLACK%^knight%^RESET%^");
    set_long("%^RED%^Before you stands a powerful humanoid figure encased into heavy armour, wielding a huge two-handed sword. It's skin is pale gray, ears are bat like and eyes glow red. It has calm demeanor about it, but watches you intently.");
    set_race("guard");
    set_gender("other");

    set_size(2);
    set_class("fighter");

    set("aggressive",2);
    set_property("swarm",0);

    set_nogo(({"/d/dagger/road/p7",
                    "/d/dagger/road/tempusportal",
                    "/d/dagger/road/road35",
                    "/d/dagger/road/road25"
                    }));

    set_level(level);
    set_guild_level("fighter", level);
    set_guild_level("mage", level);
    set_mlevel("fighter", level);
    set_mlevel("mage", level);
    set_hd(level, 10);

    set_max_hp(level * 50 + 100);
    set_hp(query_max_hp());

    set("aggressive", 0);

    set_wielding_limbs(({"right hand","left hand"}));
    set_property("undead", 1);
    set_body_type("human");
    set_property("full attacks", 1);

    set_skill("perception", 40);
    set_skill("athletics", 40);
    set_skill("spellcraft", 40);

    set_stats("strength", 22);
    set_stats("dexterity", 22);
    set_stats("constitution", 10);
    set_stats("intelligence", 18);
    set_stats("wisdom", 18);
    set_stats("charisma", 22);

    set_new_exp("normal", 35);

    set_property("cast and attack", 1);
    set_spells(({"fear",
                    "dictum",
                    "vampiric touch"}));
    set_spell_chance(50);

    set_property("spellturning", 10);
    set_property("fast healing", 5);

    set_alignment(3);

    {
        object stuff;

        stuff = new("/d/common/obj/weapon/bastard_two");
        stuff->set_property("enchantment", 7);
        stuff->set_property("monsterweapon", 1);
        stuff->move(TO);
        command("wield sword");
        stuff = new("/d/common/obj/armour/plate");
        stuff->set_property("enchantment", 7);
        stuff->set_property("monsterweapon", 1);
        stuff->move(TO);
        command("wear plate");
        stuff = new("/d/common/obj/armour/greaves");
        stuff->set_property("enchantment", 7);
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
