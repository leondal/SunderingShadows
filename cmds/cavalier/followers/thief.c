// test thief monster

#include <std.h>
#include <daemons.h>
inherit "/cmds/cavalier/followers/follower.c";


void create()
{
    object ob, ob2;
    ::create();
    set_class("thief");

    set_id(({ "follower", "retainer" }));
    set_race("human");
    set_exp(2000);
    set_body_type(query_race());
    set_gender("male");
    set_long("This stealthy human is a follower. " + capitalize(query_subjective()) +
             " slinks along doing as he is bid out of dedication to his liege."
             );


    set_money("gold", random(3000));
    set_mob_magic_resistance("very low");
    set_thief_skill("hide in shadows", 95);
    set_thief_skill("move silently", 95);
    set_thief_skill("pick pickets", 95);
    set_thief_skill("open locks", 95);
    set_thief_skill("find/remove traps", 95);
    add_search_path("/cmds/thief");
}

int do_damage(string limb, int damage)
{
    int hold;

    hold = ::do_damage(limb, damage);

    if (living(PO)) {
        command("throw powder at " + PO->query_name());
    }

    if (PO->is_spell() && objectp(PO->query_caster())) {
        command("throw powder at " + PO->query_caster()->query_name());
    }
    return hold;
}

equip_me()
{
    object ob;


    ob = new("/d/tharis/obj/wrist_sheath");
    ob->move(TO);

    ob = new("/d/common/obj/weapon/longsword");
    ob->set_property("enchantment", query_level() / 8);
    ob->move(TO);
    ob->set_property("monsterweapon", 1);
    ob->set_size(query_size());

    ob = new("/d/common/obj/weapon/dagger");
    ob->set_property("enchantment", query_level() / 8);
    ob->move(TO);
    ob->set_property("monsterweapon", 1);

    ob = new("/d/tharis/obj/thief_tools");
    ob->move(TO);

    set_overall_ac(-5);
    ob = new("/d/common/obj/armour/studded");
    ob->set_property("enchantment", query_level() / 8);
    ob->move(TO);
    ob->set_property("monsterweapon", 1);

    ob = new("/d/common/obj/armour/buckler");
    ob->set_property("enchantment", query_level() / 8);
    ob->move(TO);
    ob->set_property("monsterweapon", 1);
}
