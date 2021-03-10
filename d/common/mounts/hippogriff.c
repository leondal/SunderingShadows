#include <std.h>

inherit "/std/flying_mount.c"; // needs to inherit flying_mount.c to be able to fly -Ares

void create() {    
    ::create();
    set_name("hippogriff");
    set_id( ({"hippogriff","hippo","mount"}) );
    set_short("%^YELLOW%^magnificent %^RESET%^%^BOLD%^winged%^RESET%^ %^BOLD%^%^BLACK%^hippogriff%^RESET%^");
    set_long("%^RESET%^%^YELLOW%^This hippogriff is a beautiful animal whose strong hindquarters "
        "and torso resemble that of a well-built horse that is mottled with g%^RESET%^%^BOLD%^o%^RESET%^%^YELLOW%^lden "
        "highlights, while it's front legs resemble that of a giant eagle with "
        "sharply curved %^BOLD%^%^BLACK%^claws%^RESET%^%^YELLOW%^ that tap along the ground as it walks, creating a "
        "rather distinctive sound.  Large wings are tucked in at the creature's side that would stretch to an "
        "impressive span when in flight.");
    set_level(10);
    set_riding_level(10);  // added for riding nwp by *Styx*  11/14/03
    set_value(2000);
    set_race("hippogriff");
    set_gender("male");
    set_body_type("hippogriff");
    set_size(3);
    set_max_hp(200);
    set_hp(200);
    set_hd(10,4);
    set_hp(200);
    set_overall_ac(5);
    set_exp(10);
    set_max_distance(200);
    set_enter_room("rides in.");
    set_exit_room("leaves riding a hippogriff.");

    set_vehicle_short("%^YELLOW%^magnificent %^RESET%^%^BOLD%^winged%^RESET%^ %^BOLD%^%^BLACK%^hippogriff%^RESET%^");
    add_limb("beak","head",0,0,0);
    add_limb("right leg","torso",0,0,0);
    add_limb("left leg","torso",0,0,0);
    add_limb("torso","torso",0,0,0);
    add_limb("head","torso",0,0,0);
    set_attack_limbs( ({"beak","right leg","left leg"}) );
    set_attacks_num(3);
    set_damage(1,6);
    // stuff below here necessary for flying mounts -Ares

set_flight_delay(900); // this is for a round trip, 2 flights.  Probably has to be longer after testing is done.
    set_flying_prof(30);   // this is the skill required to fly it through the air, different than riding on the ground
    set_ward_pass(25);     // this is the strength to bypass anti teleportation wards



}
