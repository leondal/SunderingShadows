#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit WEAPONLESS;

object master;
object weapon;
object weapon_2;

void create()
{
    ::create();
    set_money("gold", 0);
    set_money("silver", 0);
    set_money("copper", 0);
    set_money("platinum", 0);
    set_race("undead");
    set_gender("male");
    set_size(2);

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
    set_stats("charisma", 8);

    set_alignment(9);

    add_search_path("/cmds/feats");

}

void control(object caster)
{
    if(!objectp(caster))
        return;
    if(!present(caster,environment(TO)))
        return;
    master = caster;
    call_out("protect",ROUND_LENGTH);
}

void protect()
{
    object *foes, foe;

    if(!objectp(master))
        return;

    call_out("protect", ROUND_LENGTH);
    foes=master->query_attackers();

    foreach(foe in foes)
    {
        if(!objectp(foe))
            continue;
        if(!present(foe,ENV(TO)))
            continue;
        TO->kill_ob(foe);
    }
}

void set_weap_enchant(int level)
{
    if(objectp(weapon))
        if(weapon->is_weapon())
            weapon->set_property("enchantment", level);

    if (objectp(weapon_2))
        if (weapon_2->is_weapon())
            weapon_2->set_property("enchantment", level);
}
