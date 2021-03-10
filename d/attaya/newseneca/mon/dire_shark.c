//stolen from /d/dagger/arctic/mon/dire_shark and adjusted
#include <std.h>
#include "/d/dagger/arctic/arctic.h"
inherit CREATURE;

void create(){
    ::create();
    set_name("Shark");
    set_id(({"shark","Shark","fish","giant shark","arcticmon"}));
    set_race("shark");
    set_body_type("snake");
    set_gender("male");
    set_size(5);
    set_short("A giant shark");
    set_long("This massive shark is over fifty feet long.  Its skin is a "
        "sleek, glistening gray and it moves with disturbing agility.  The "
        "massive dorsal fin along its back is the size of the sail on a small "
        "ship, and its jaws look as if they could swallow a full grown giant "
        "with ease.  The shark has huge black eyes that are absent any pupils.");
    set_hd(20,1);
    set_level(20);
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_hp(1000);
    set_exp(30000);
    set_property("swarm", 1);
    set_property("water breather",1);
    set_overall_ac(-5);
    set_stats("strength",18);
    set_stats("dexterity",22);
    set_stats("intelligence",4);
    set_stats("wisdom",6);
    set_stats("constitution",22);
    set_stats("charisma",5);
    set_attacks_num(1);
    set_damage(5,10);
    set_base_damage_type("piercing");
    add_limb("razor sharp teeth", "head", 0, 0, 0);
    set_attack_limbs(({"razor sharp teeth"}));
    set("aggressive", 25);
}