// rank 1 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"owl","snowy owl","natures ally"}));
    set_short("%^BOLD%^%^WHITE%^snowy owl%^RESET%^");
    set_long("This owl's large, round eyes track the motion of any nearby movement with a full turn of its head.  A "
"flat face bears forward-turned, tufted ears and a hooked beak, surrounded by snowy-white feathers that form a full coat "
"for the avian.  Its feet bear vicious talons that could do considerable damage to an opponent.");
    set_race("owl");
    set_body_type("fowl");
    set_attack_limbs(({"beak","right claw","left claw"}));
    set_base_damage_type("slashing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^YELLOW%^The owl darts forward, buffeting you with both wings and slashing with its talons!%^RESET%^");
    tell_room(ETO,"%^YELLOW%^The owl darts forward, buffeting "+target->QCN+" with both wings and slashing with its talons!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(10)+mylevel);
    TO->remove_property("magic");
}