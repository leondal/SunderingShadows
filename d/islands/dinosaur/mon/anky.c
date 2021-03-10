#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit DINOS;

void create()
{
    ::create();
    set_name("ankylosaurus");
    set_property("plant eater", 1);
    set_id(({ "dino", "dinosaur", "anky", "ankylosaurus" }));
    set_short("Ankylosaurus");
    set_long(
        "The large dinosaur you are looking at is the Ankylosaurus.  Very large, yet squat to the ground, it is covered in great armor plates, spikes on its sides, and a long tail with a bony knob on the end."
        );
    set_size(3);
    set_hd(12 + random(5), 0);
    set_attack_bonus(random(4) + 2);
    set_max_hp(100 + (8 * query_hd()));
    set_hp(query_max_hp());
    set_exp(query_hd() * 250);
    set_race("dinosaur");
    if (random(2)) {
        set_gender("male");
    }else {
        set_gender("female");
    }
    set_body_type("quadruped");
    add_limb("tail", "tail", 0, 0, 0);
    set_alignment(5);
    set_overall_ac(-7);
    set("aggressive", 15);
    set_attack_limbs(({ "right forepaw", "left forepaw", "tail" }));
    set_attacks_num(2);
    set_base_damage_type("bludgeoning");
    set_damage(3, 5);
    set_hit_funcs((["tail" : (: TO, "tail_hit" :)]));
    set_property("no stab", 1);
    set_moving(1);
    set_speed(15);
}

int tail_hit(object targ)
{
    if (!objectp(targ)) {
        return random(6);
    }

    if (random(2)) {
        return 1;
    }
    tell_object(targ, "%^YELLOW%^The Ankylosaurus bashes you with its great knobby tail!");
    tell_room(ETO, "%^YELLOW%^The Ankylosaurus bashes " + targ->query_cap_name() + " with its great knobby tail!", targ);
    return roll_dice(3, 7);
}

int free_movement()
{
    return 1;
}
