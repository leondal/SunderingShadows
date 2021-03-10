// test ranger monster

#include <std.h>
#include <daemons.h>
inherit "/cmds/cavalier/followers/follower.c";


void create()
{
    object ob;
    ::create();
    set_class("fighter");
    set_id(({ "follower", "retainer" }));
    set_race("human");
    set_exp(2000);
    set_body_type(query_race());
    set_gender("male");
    set_long("This stout fellow is well equiped. He follows his leige lord with dedication and devotion."
             );


    ob = new("/d/common/obj/potion/healing");
    ob->move(TO);
    ob->set_uses(random(25) + 50);
    set_mob_magic_resistance("none");

    set_money("gold", random(3000));
    set_property("full attacks", 1);
    add_search_path("/cmds/fighter");
}

equip_me()
{
    object ob;
    ob = new("/d/common/obj/weapon/longsword");
    ob->set_property("enchantment", query_level() / 8);
    ob->move(TO);
    ob->set_property("monsterweapon", 1);
    ob->set_size(query_size());

    set_overall_ac(-5);
    ob = new("/d/common/obj/armour/fullplate");
    ob->set_property("enchantment", query_level() / 8);
    ob->move(TO);
    ob->set_property("monsterweapon", 1);

    ob = new("/d/common/obj/armour/shield");
    ob->set_property("enchantment", query_level() / 8);
    ob->move(TO);
    ob->set_property("monsterweapon", 1);
}
