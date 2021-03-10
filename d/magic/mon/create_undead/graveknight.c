#include <std.h>
#include "common.h"

inherit UNDEADINHERIT;

void create()
{
    ::create();
    set_name("graveknight");
    set_id(({ "skeleton", "graveknight", "undead" }));
    set_short("%^BOLD%^%^BLACK%^g%^RED%^r%^BLACK%^a%^RED%^v%^BLACK%^e%^RED%^k%^BLACK%^n%^RED%^i%^BLACK%^g%^RED%^h%^BLACK%^t%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Before you stands an undead creature, a humanoid skeleton holding a halberd in its skeletal hands. Its bones float in fell aura forming resemblance of a kith being, %^RED%^its eyes glow red with graft of undeath's hatred towards the life.");
    set_race("undead");
    set_gender("male");

    set_size(2);
    set_class("fighter");

    set_guild_level("fighter", 6);
    set_level(8);
    set_hd(8, 8);

    set_max_hp(random(30) + 255);
    set_hp(query_max_hp());

    set_wielding_limbs(({ "right hand", "left hand" }));
    set_property("undead", 1);
    set_body_type("human");
    set_property("full attacks", 1);

    set_stats("strength", 22);
    set_stats("dexterity", 16);
    set_stats("constitution", 12);
    set_stats("intelligence", 4);
    set_stats("wisdom", 4);
    set_stats("charisma", 4);

    set_alignment(9);

    {
        object stuff;

        stuff = new("/d/common/obj/weapon/halberd");
        stuff->set_property("monsterweapon", 1);
        stuff->move(TO);
        weapon = stuff;
        command("wield halberd");
        stuff = new("/d/common/obj/armour/chain");
        stuff->set_property("monsterweapon", 1);
        stuff->move(TO);
        command("wear chain");
    }

    add_search_path("/cmds/feats");
    add_search_path("/cmds/fighter");

    set_monster_feats(({
                "strength of arm",
                    "blade block",
                    "mounted combat",
                    "ride-by attack",
                    "light weapon",
                    }));

    set_fighter_style("soldier");
    command("message in marches in.");
    command("message out marches $D.");
}
