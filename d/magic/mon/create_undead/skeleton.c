#include <std.h>
#include "common.h"

inherit UNDEADINHERIT;

void create(){

    ::create();
    set_name("skeletal champion");
    set_id(({"skeleton","skeletal champion","champion","undead"}));
    set_short("%^BOLD%^%^BLACK%^s%^WHITE%^k%^BLACK%^e%^WHITE%^l%^BLACK%^e%^WHITE%^t%^BLACK%^a%^WHITE%^l %^BLACK%^c%^WHITE%^h%^BLACK%^a%^WHITE%^m%^BLACK%^p%^WHITE%^i%^BLACK%^o%^WHITE%^n%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Before you stands an undead creature, a humanoid skeleton holding a sword and a shield in its skeletal hands. Its bones float in fell aura forming resemblance of a kith being, %^RED%^its eyes glow red with graft of undeath's hatred towards the life.");
    set_race("undead");
    set_gender("male");

    set_size(2);
    set_class("fighter");

    set_guild_level("fighter",6);
    set_level(8);
    set_hd(8,8);

    set_max_hp(random(30)+255);
    set_hp(query_max_hp());

    set_wielding_limbs(({"right hand","left hand"}));
    set_property("undead",1);
    set_body_type("human");
    set_property("full attacks",1);

    set_stats("strength",22);
    set_stats("dexterity",16);
    set_stats("constitution",12);
    set_stats("intelligence",4);
    set_stats("wisdom",4);
    set_stats("charisma",8);

    set_alignment(9);

    {
        object stuff;

        set_property("silent_equip",1);
        stuff = new("/d/common/obj/armour/mshield");
        stuff->set_property("monsterweapon",1);
        stuff->move(TO);
        command("wear shield");
        stuff = new("/d/common/obj/weapon/shortsword");
        stuff->set_property("monsterweapon", 1);
        stuff->move(TO);
        weapon = stuff;
        command("wield sword");
    }

    add_search_path("/cmds/feats");
    add_search_path("/cmds/fighter");

    set_monster_feats(({
                "counter",
                    "reflection",
                    }));

    set_fighter_style("soldier");
    command("message in marches in.");
    command("message out marches $D.");
}
