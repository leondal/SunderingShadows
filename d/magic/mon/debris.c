//debris for the first level kineticist power Control Object

#include <std.h>
inherit WEAPONLESS;

void create(){
    ::create();
    set_name("debris");
    set_id(({"debris","monster","summoned monster"}));
    set_gender("neuter");
    set_short("debris");
    set_long(
        "%^RESET%^%^ORANGE%^This piece of debris is a collection of "
        "matter particles, forming a shapeless lump in shades of brown, "
        "green, and gray. It hovers in the air, dodging quickly if anyone "
        "tries to grab it.%^RESET%^");       
    set_race("debris");
    set_body_type("snake");
    set_size(1);
    remove_limb("mouth");
    remove_limb("head");
    remove_limb("tail");
    add_limb("debris shard","torso",0,0,0);
    set_attack_limbs(({"debris shard"}));
    set_base_damage_type("bludgeoning");
    set_exp(1);
    set_stats("intelligence",12);
    set_stats("wisdom",12);
    set_stats("strength",14);
    set_stats("charisma",8);
    set_stats("dexterity",18);
    set_stats("constitution",7);
}


void setup_debris(object caster){
    int num;

    if(!objectp(caster)) { return; }
    if(!objectp(TO)) { return; }

    num = (int)caster->query_guild_level("psion");
    if(!num) { num = (int)caster->query_lowest_level(); }

    set_level(num/2);
    set_hd(num/2,6);
    set_max_hp(roll_dice(3,num/2) + 50);
    set_hp(query_max_hp());
    set_attacks_num(0);
    set_overall_ac(10-num);
    set_damage(1,6);
    return;
}
