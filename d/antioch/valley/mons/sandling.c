//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit S_WANDER;

void create()
{
    ::create();
    set_name("sandling");
    set_id(({ "sandling", "monster", "construct" }));
    set_short("Sandling");
    set_long(
        "This is a blob of moving and sliding sand. It has taken the" +
        " vague shape of a human with massive fists. Many sages" +
        " believe that these creatures originated on the Elemental" +
        " Plane of Earth, and you can see why. It does have a very" +
        " odd resembalance to an earth elemental. The face is the" +
        " strangest part of the creature because it doesn't really" +
        " have one. There are no ears or eyes, just a slight lump" +
        " where a nose would be and no lips to speak of. It is very" +
        " disconcerting to be facing an opponent who has no face."
        );
    set_gender("neuter");
    set_race("sandling");
    set_body_type("humanoid");
    set_hd(15, 4);
    set_max_level(20);
    set_size(3);
    set_mob_magic_resistance("average");
    set_overall_ac(3);
    set_alignment(5);
    set_level(15);
    set_stats("intelligence", 1);
    set("aggressive", 25);
    set_property("swarm", 1);
    set_attack_limbs(({ "right hand", "left hand" }));
    set_attacks_num(2);
    set_base_damage_type("bludgeoning");
    set_damage(2, 8);
    set_class("fighter");
    set_mlevel("fighter", 15);
    set_max_hp(random(50) + 75);
    set_hp(query_max_hp());
//	set_exp(2705);
    set_new_exp(15, "normal");
}
