//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("bloodthorn");
    set_id(({ "bloodthorn", "monster", "plant", "vampire vine", "blood thorn", "tree", "thorn" }));
    set_short("A hornwood tree");
    set_long(
        "This looks like a very large hornwood tree. The trunk is a" +
        " light brown shade and completely smooth, it's probably" +
        " one of the lightest plants in this dark forest. The leaves" +
        " are pointed and double-lobed but are a little small for" +
        " a hornwood, especially considering the size of the tree." +
        " There are many vines and creepers growing in the tree, you" +
        " can't imagine how it's stayed so healthy. Peering closer" +
        " at the vines you can see some thorns on the very ends of" +
        " them. This isn't a hornwood tree at all, but a bloodthorn!"
        );
    set_race("tree");
    set_gender("neuter");
    set_body_type("snake");
    set_hd(20, 5);
    set_max_level(25);
    set_size(-3);
    set_overall_ac(3);
    set_level(25);
    set_max_hp(random(150) + 200);
    set_hp(query_max_hp());
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_stats("intelligence", 1);
    set_stats("dexterity", 20);
    set_stats("strength", 18);
    add_limb("trunk", "torso", 0, 0, 0);
    add_limb("vine 1", "trunk", 0, 0, 0);
    add_limb("vine 2", "trunk", 0, 0, 0);
    add_limb("vine 3", "trunk", 0, 0, 0);
    add_limb("vine 4", "trunk", 0, 0, 0);
    add_limb("vine 5", "trunk", 0, 0, 0);
    add_limb("vine 6", "trunk", 0, 0, 0);
    add_limb("vine 7", "trunk", 0, 0, 0);
    add_limb("vine 8", "trunk", 0, 0, 0);
    set_attack_limbs(({ "vine 1", "vine 2", "vine 3", "vine 4", "vine 5", "vine 6", "vine 7", "vine 8" }));
    set_attacks_num(8);
    set_base_damage_type("slashing");
    set_property("no charge", 1);
    set_property("no bows", 1);
    set_damage(1, 4);
    set_hit_funcs((["vine 1" : (: TO, "drain" :)]));
//	set_exp(13500);
    set_new_exp(20, "normal");
    set_property("swarm", 1);
    set("aggressive", 10);
    set_property("no paralyze", 1);
    set_mob_magic_resistance("average");
}

int query_watched()
{
    return 1000000;
}

int drain(object targ)
{
    int health;

    health = targ->query_hp();

    if (!random(6)) {
        tell_object(targ, "%^RED%^A bloodthorn vine catches in your" +
                    " skin and drains some of your blood!");
        tell_room(ETO, "%^RED%^A bloodthorn vine burries itself in" +
                  " " + targ->query_cap_name() + "'s skin and drains some of" +
                  " " + targ->query_possessive() + " blood!", targ);
        targ->do_damage("torso", health / 4);
    }
}
