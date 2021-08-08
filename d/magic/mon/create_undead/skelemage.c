#include <std.h>
#include "common.h"

inherit UNDEADINHERIT;

void create()
{
    ::create();
    set_name("skelemage");
    set_id(({ "skeleton", "skelemage", "undead", "mage skeleton" }));
    set_short("%^CYAN%^m%^BOLD%^ag%^RESET%^%^CYAN%^e %^BOLD%^%^BLACK%^s%^CYAN%^k%^BLACK%^e%^CYAN%^l%^BLACK%^e%^CYAN%^t%^BLACK%^o%^CYAN%^n%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Before you floats an undead creature, a humanoid skeleton in tattered robes, holding a spellbook. Its bones float in fell aura forming resemblance of a kith being, %^RED%^its eyes glow red with graft of undeath's hatred towards the life.");
    set_race("undead");
    set_gender("male");

    set_size(2);
    set_class("mage");

    set_guild_level("mage", 6);
    set_level(8);
    set_hd(8, 8);

    set_max_hp(random(30) + 255);
    set_hp(query_max_hp());

    set_wielding_limbs(({ "right hand", "left hand" }));
    set_property("undead", 1);
    set_body_type("human");

    set_stats("strength", 10);
    set_stats("dexterity", 18);
    set_stats("constitution", 20);
    set_stats("intelligence", 24);
    set_stats("wisdom", 16);
    set_stats("charisma", 4);

    set_property("flying", 1);

    set_alignment(9);

    add_search_path("/cmds/feats");

    set_spells(({ "touch of fatigue",
                    "touch of sickening",
                    "ray of frost",
                    "shocking grasp",
                    "chill touch", }));
    set_spell_chance(100);
    set_property("specral_hand", 1);

    set_monster_feats(({
                "spell focus",
                "spell penetration",
                "perfect caster",
                    }));

    command("message in floats in.");
    command("message out floats $D.");
}
