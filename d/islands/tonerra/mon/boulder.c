// boulder.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit WEAPONLESS;

void set_caller(object ob);
int is_friend();
object caller;

void create()
{
    ::create();
    set_name("boulder");
    set_id(({ "boulder", "Boulder" }));
    set("short", "boulder");
    set_long("This is a large boulder that blends almost completely into the surrounding rock.");
    set_hd(15, 8);
    set_overall_ac(-5);
    set_class("fighter");
    set_mlevel("fighter", 15);
    set_exp(100);
    set_race("rock");
    add_limb("body", "body", 0, 0, 0);
    set_attack_limbs(({ "body" }));
    set_attacks_num(1);
    set_damage(4, 6);
    set_base_damage_type("bludgeoning");
    set_alignment(5);
    set_property("swarm", 1);
    set_new_exp(25, "normal");
    set_resistance("slashing", 10);
    set_resistance("piercing", 10);
}

void heart_beat()
{
    if ((object*)caller->query_attackers() == ({})) {
        caller->remove_summoned(TO);
        caller->set_func_chance(80);
        tell_room(ETO, "%^BLUE%^The boulder fades back into the surrounding rock!");
        TO->remove();
    }
    if (!objectp(TO)) {
        return;
    }
    ::heart_beat();
}

void set_caller(object ob)
{
    caller = ob;
}

int is_friend()
{
    return 1;
}
