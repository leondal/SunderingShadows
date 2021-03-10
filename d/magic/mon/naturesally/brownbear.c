// rank 4 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"bear","brown bear","natures ally"}));
    set_short("%^RESET%^%^ORANGE%^massive brown bear%^RESET%^");
    set_long("The brown bear is one of the largest of its species, a heavily built predator able to scare away lesser "
"carnivores through sheer intimidation.  A darkened muzzle lies above a maw of powerful teeth, set forward upon the "
"concave skull of the beast.  The forepaws sport powerful claws, used as much for digging as for combat.  For a beast of "
"its size, it can move with surprising speed when provoked.");
    set_race("bear");
    set_body_type("quadruped");
    set_attack_limbs(({"right forepaw","left forepaw"}));
    set_base_damage_type("bludgeoning");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^YELLOW%^The bear lunges forward to grab at you in a hug that makes your bones creak!%^RESET%^");
    tell_room(ETO,"%^YELLOW%^The bear lunges forward to grab at "+target->QCN+" in a hug that makes "+target->QP+" bones creak!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(40)+mylevel);
    TO->remove_property("magic");
}