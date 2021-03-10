// rank 2 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"bear","black bear","natures ally"}));
    set_short("%^BOLD%^%^BLACK%^small black bear%^RESET%^");
    set_long("The brown bear is smaller than its ursine cousins, but nonetheless can be dangerous if provoked.  A pale, "
"narrow muzzle lies above a maw of powerful teeth, set forward upon the curved skull of the beast.  Thick black fur coats "
"the creature's frame, lightening only at the nose and chest.  Usually feeding on vegetation, they still act as "
"carnivores when driven by necessity.");
    set_race("bear");
    set_body_type("quadruped");
    set_attack_limbs(({"right forepaw","left forepaw"}));
    set_base_damage_type("bludgeoning");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^YELLOW%^The bear barrels into you with considerable force, knocking you aside!%^RESET%^");
    tell_room(ETO,"%^YELLOW%^The bear barrels into "+target->QCN+" with considerable force, knocking "+target->QO+" aside!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(20)+mylevel);
    TO->remove_property("magic");
}