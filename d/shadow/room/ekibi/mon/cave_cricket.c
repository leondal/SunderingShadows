//cave_cricket.c - Mob for low level cave area
//by Circe 3/13/05
#include <std.h>
#include "../ekibi.h"

inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("cave cricket");
    set_short("A chirping cave cricket");
    set_id(({ "cricket", "cave cricket", "chirping cricket", "chirping cave cricket", "insect" }));
    set_long("This cricket dwarfs its normal-sized cousins, standing " +
             "a full three and a half feet tall.  Its body is a dusky " +
             "black-brown that shimmers damply when light hits it.  " +
             "Its back is covered with two plates protecting a pair of " +
             "diaphanous wings while a pair of tall, jointed legs rises " +
             "overhead.  These legs are often used to produce the eerie " +
             "cricket music that fills the caverns.");
    set_gender(random(2) ? "male" : "female");
    set_race("cricket");
    set_body_type("insectoid-winged");
    set_size(2);
    set_alignment(5);
    set_hd(7, 5);
    set("aggressive", 15);
    set_property("swarm", 1);
    set_class("fighter");
    set_mlevel("fighter", 7);
    set_hp(random(10) + 65);
    set_overall_ac(6);
    set_stats("strength", 12);
    set_damage(1, 6);
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_attack_limbs(({ "mouth" }));
    set_exp(165);
    set_max_level(10);
    set_funcs(({ "chirp" }));
    set_func_chance(5);
}

void chirp(object targ)
{
    string name = targ->query_cap_name();
    tell_room(ETO, "%^YELLOW%^The cricket pulls one leg across the other, " +
              "filling the area with a horrendous screech!");
    if (!"daemon/saving_d"->saving_throw(targ, "paralyzation_poison_death", 0)) {
        tell_object(targ, "%^BOLD%^%^RED%^You grab your ears in pain!");
        tell_room(ETO, "%^BOLD%^%^RED%^" + name + " grabs " + targ->QP + " " +
                  "ears in pain!", targ);
        targ->set_paralyzed(2 + random(2), "You are reeling from the noise!");
        targ->do_damage("head", roll_dice(1, 6));
        return;
    }
    tell_object(targ, "%^ORANGE%^Your ears ring, but you fight off the " +
                "sound!");
    return;
}
