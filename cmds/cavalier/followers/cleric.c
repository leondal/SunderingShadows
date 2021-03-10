// test cleric monster

#include <std.h>
#include <daemons.h>
inherit "/cmds/cavalier/followers/follower.c";

int healings = 10;


void create()
{
    object ob;
    ::create();
    set_class("cleric");
    set_id(({ "follower", "retainer" }));
    set_race("human");
    set_exp(2000);
    set_body_type(query_race());
    switch (random(2)) {
    case 0:
        set_gender("male");
        break;

    case 1:
        set_gender("female");
        break;
    }
    set_long("This devout priest follows his leige with the intent on adding his spiritual advice."
             );
    set_spells(({ "call lightning", "limb attack" }));
    set_spell_chance(90);
    set_mob_magic_resistance("high");


    ob = new("/d/common/obj/potion/healing");
    ob->move(TO);
    ob->set_uses(random(25) + 25);

    set_money("gold", random(3000));
}

void heart_beat()
{
    ::heart_beat();

    if (!objectp(TO) || !objectp(ETO)) {
        return;
    }

    if (query_hp() < (query_max_hp() / 2) && healings) {
        new("/cmds/priest/_heal")->use_spell(TO, query_name(), 200);
        healings--;
    }
}

equip_me()
{
    object ob;
    ob = new("/d/common/obj/weapon/mstaff");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    ob->set_property("monsterweapon", 1);
    ob->set_size(query_size());

    set_overall_ac(-5);
    ob = new("/d/common/obj/armour/fullplate");
    ob->set_property("enchantment", query_level() / 8);
    ob->move(TO);
    ob->set_property("monsterweapon", 1);
}
