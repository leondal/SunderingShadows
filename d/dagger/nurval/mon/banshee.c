#include <std.h>

inherit "/std/monster";

/**
 * Banshees that roam Nurval
 */
void create()
{
    object weapon;
    int level = 60;

    ::create();
    set_name("banshee");
    set_id(({"banshee","undead", "wailing banshee"}));
    set_short("%^BOLD%^%^BLACK%^W%^RESET%^%^MAGENTA%^a%^BOLD%^i%^WHITE%^l%^BLACK%^ing B%^RESET%^%^MAGENTA%^a%^BOLD%^n%^WHITE%^s%^BLACK%^hee%^RESET%^");
    set_long("%^RED%^Before you floats the spectre of a woman, who maybe once was beautiful, but is now a sad reminder of a sad fate. She has long claws, a pale complexion and her face is warped and scarred.");
    set_race("undead");
    set_gender("other");

    set_size(2);
    set_class("mage");

    set("aggressive",2);
    set_property("swarm",0);

    set_nogo(({"/d/dagger/road/p7",
                    "/d/dagger/road/tempusportal",
                    "/d/dagger/road/road35",
                    "/d/dagger/road/road25"
                    }));

    set_level(level);
    set_guild_level("mage", level);
    set_mlevel("mage", level);
    set_hd(level, 4);

    set_max_hp(level * 20 + 100);
    set_hp(query_max_hp());

    set("aggressive", 0);

    set_wielding_limbs(({"right hand","left hand"}));
    set_property("undead", 1);
    set_body_type("human");

    set_skill("perception", 50);
    set_skill("spellcraft", 50);

    set_stats("strength", 14);
    set_stats("dexterity", 20);
    set_stats("constitution", 18);
    set_stats("intelligence", 24);
    set_stats("wisdom", 14);
    set_stats("charisma", 22);

    set_new_exp("normal", 35);

    set_property("cast and attack", 1);
    set_property("weapon resistance", 6);
    set_property("damage resistance", 40);
    set_spells(({"oppression",
                 "wail of the banshee",
                 "dispel magic",
                 "unholy orb",
                 "horrid wilting"}));
                 
    set_spell_chance(90);

    set_property("spellturning", 10);
    set_property("fast healing", 5);

    set_alignment(3);

    add_search_path("/cmds/feats");
    add_search_path("/cmds/mage");

    set_monster_feats(({
                    "spell focus",
                    "spell penetration",
                    "greater spell penetration",
                    "perfect caster",
                    "spell power",
                    "improved spell power",
                    "greater spell power",
                    "rush",
                    }));
    command("message in floats in.");
    command("message out floats $D.");
}
