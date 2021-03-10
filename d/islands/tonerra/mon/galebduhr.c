//Added set_max_level to retard cycling - Octothorpe 6/4/09
//galebduhr.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit WEAPONLESS;

void make_me();
void remove_summoned(object ob);
int is_friend();

object* summoned;

void create()
{
    object ob;
    ::create();

    set_name("Galeb Duhr");
    set_id(({ "galeb duhr", "galeb", "duhr", "Galeb Duhr" }));
    set("short", "Galeb Duhr");
    set("long", "This is a large boulder-like creature with appendages resembling hands and feet. It is about 10 feet tall, and blends almost completely into the surrounding rock.");
    set_overall_ac(-15);
    set_race("rock");
    add_limb("right hand", "body", 0, 0, 0);
    add_limb("left hand", "body", 0, 0, 0);
    add_limb("right foot", "body", 0, 0, 0);
    add_limb("left foot", "body", 0, 0, 0);
    add_limb("body", "body", 0, 0, 0);
    set_funcs(({ "summon" }));
    set_func_chance(80);
    set_invis();
    make_me();
    set_attack_limbs(({ "right hand", "left hand", "right foot", "left foot" }));
    set_attacks_num(2);
    set_base_damage_type("bludgeoning");
    set_alignment(5);
    summoned = ({});
    set_property("swarm", 1);
    set_new_exp(25, "normal");
    if (!random(2)) {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("living stone");
        ob->move(TO);
    }
    set_resistance("slashing", 10);
    set_resistance("piercing", 10);
}

void make_me()
{
    int i;
    i = random(3);
    set_hd(i + 15, 8);
    set_exp(2000 + 1000 * i);
    set_hp(query_hd() * 8);
    set_max_level(25);
    set_class("fighter");
    set_mlevel("fighter", query_hd());
    switch (query_hd()) {
    case 15:
        set_damage(2, 8);
        break;

    case 16:
        set_damage(3, 6);
        break;

    case 17:
        set_damage(4, 6);
        break;

    default:
        set_damage(2, 8);
    }
}

void summon(object obj)
{
    int i, j;
    object ob;

    j = random(3);
    for (i = 0; i < j; i++) {
        ob = new(MON + "boulder");
        ob->set_attackers((object)TO->query_attackers());
        ob->move(environment(TO));
        summoned += ({ ob });
        ob->set_caller(TO);
        tell_room(ETO, "%^BOLD%^%^BLUE%^A large boulder rise from the ground to come to the aid of the galeb duhr!");
    }
    set_func_chance(0);
}

void init()
{
    if (random(2) && !TP->is_friend() && !wizardp(TP)) {
        tell_room(ETO, "%^BOLD%^A galeb duhr appears from the rock to attack!");
        TO->set_invis();
        kill_ob(TP, 1);
    }
}

void die(object ob)
{
    int i;
    for (i = 0; i < sizeof(summoned); i++) {
        if (objectp(summoned[i])) {
            summoned[i]->remove();
        }
    }
    return ::die(ob);
}

void remove_summoned(object ob)
{
    if (member_array(ob, summoned) != -1) {
        summoned -= ({ ob });
    }
}

void heart_beat()
{
    if ((object*)TO->query_attackers() == ({})) {
        if (!query_invis()) {
            set_invis();
            set_func_chance(80);
        }
    }else
    if (query_invis()) {
        set_invis();
    }
    ::heart_beat();
}

int test_heart()
{
    return 1;
}

int is_friend()
{
    return 1;
}
