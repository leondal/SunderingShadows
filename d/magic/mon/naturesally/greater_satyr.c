// rank 5 beastie
// coded by ~Circe~ 4/27/13
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"satyr","sprite","natures ally"}));
    set_short("%^RESET%^%^RED%^a cu%^ORANGE%^n%^RED%^ni%^RESET%^n%^RED%^g sa%^ORANGE%^t%^RED%^yr%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^Looking much like a human, this "
       "creature has the legs, %^BOLD%^%^BLACK%^tail%^RESET%^%^ORANGE%^, "
       "and %^RESET%^horns %^ORANGE%^of a goat.  %^BOLD%^%^BLACK%^Ebon "
       "hooves %^RESET%^%^ORANGE%^strike the ground as the creature moves "
       "with a light, almost playful gait, a twinkle in its eye and a "
       "curl to the tip of its chestnut-brown beard.  Usually fun-loving, "
       "satyrs nonetheless resent intrusions and will forcibly drive away "
       "creatures that offend them.  This satyr seems taller than some of "
       "its cousins, and the breadth of its shoulders add an element of menace.%^RESET%^");
    set_race("satyr");
    set_gender("male");
    set_body_type("humanoid");
    set_attack_limbs(({"right hand","left hand"}));
    set_base_damage_type("bludgeoning");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^RESET%^%^RED%^The satyr's hooves paw at the ground before he charges forward, goring you!%^RESET%^");
    tell_room(ETO,"%^RESET%^%^RED%^The satyr's hooves paw at the ground before he charges forward, goring "+target->QCN+"!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(50)+mylevel);
    TO->remove_property("magic");
}