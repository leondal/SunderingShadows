#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit DINOS;

void create()
{
    ::create();
    set_name("diplodocus");
    set_property("plant eater", 1);
    set_short("Diplodocus");
    set_id(({ "dino", "dinosaur", "diplo", "diplodocus" }));
    set_long(
        "This is one of the most gigantic dinosaurs you've ever seen!  Over 80 feet long and looking to weigh more than the city of shadow itself, this great herbivore regards you with a quiet magnificence."
        );
    set_size(3);
    set_hd(20 + random(5), 0);
    set_attack_bonus(random(5) + 1);
    set_max_hp(100 + (10 * query_hd()));
    set_exp(query_hd() * 525);
    set_overall_ac(-1);
    set_hp(query_max_hp());
    set_race("dinosaur");
    if (random(2)) {
        set_gender("male");
    }else {
        set_gender("female");
    }
    set_body_type("quadruped");
    add_limb("tail", "tail", 0, 0, 0);
    set_alignment(5);
    set("aggressive", 4);
    set_attack_limbs(({ "right forepaw", "left forepaw", "tail" }));
    set_hit_funcs((["tail" : (: TO, "tail_whip" :)]));
    set_funcs(({ "trample" }));
    set_func_chance(20);
    set_attacks_num(2);
    set_base_damage_type("bludgeoning");
    set_property("no stab", 1);
    set_damage(3, 6);
    set_moving(1);
    set_speed(25);
    set_property("no stab", 1);
}

int tail_whip(object targ)
{
    if (!objectp(targ)) {
        return random(6);
    }
    if (random(3)) {
        return random(10);
    }

    tell_object(targ, "%^BOLD%^%^MAGENTA%^The tail of the Diplodocus whips around striking you painfully!");
    tell_room(ETO, "%^BOLD%^The Diplodocus whips its tail around, striking " + targ->query_cap_name() + "!", targ);
    return roll_dice(3, 6);
}

int trample(object targ)
{
    if (!"daemon/saving_d"->saving_throw(targ, "paralyzation_poison_death")) {
        tell_object(targ, "%^BOLD%^%^BLUE%^The great Diplodocus rears on its hind legs, and slams its full 15 tons of weight down on you!");
        tell_room(ETO, "%^BOLD%^%^BLUE%^The great Diplodocus rears back, then slams its full weight down onto " + targ->query_cap_name() + "!", targ);
        targ->set_paralyzed(20 + random(10), "The breath has been crushed from your lungs!");
        targ->do_damage("torso", roll_dice(6, 10));
        return 1;
    } else {
        tell_object(targ, "%^BOLD%^%^BLUE%^The great Diplodocus rears on its hind legs, and slams down on you, luckily just grazing you!");
        tell_room(ETO, "%^BOLD%^%^BLUE%^The great Diplodocus rears back, then slams most of its weight down onto " + targ->query_cap_name() + "!", targ);
        targ->set_paralyzed(10 + random(5), "The breath has been crushed from your lungs!");
        targ->do_damage("torso", roll_dice(3, 10));
        return 1;
    }
}

int free_movement()
{
    return 1;
}
