// rank 4 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"tiger","natures ally"}));
    set_short("%^RESET%^%^ORANGE%^dark-br%^BOLD%^%^BLACK%^in%^RESET%^%^ORANGE%^dled tiger%^RESET%^");
    set_long("This powerful beast is built for strength and speed, muscles rippling beneath its dark-brindled coat.  Its "
"tail lashes back and forth in agitation as its sharp gaze scans the area.  Lips occasionally curl back in a snarl to "
"show a vicious set of fangs that could do serious damage.");
    set_race("tiger");
    set_body_type("quadruped");
    add_limb("left claws","left forepaw",0,0,0);
    add_limb("right claws","right forepaw",0,0,0);
    set_attack_limbs(({"right claws","left claws"}));
    set_base_damage_type("slashing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^YELLOW%^The tiger snarls and leaps forward, tearing into you in a frenzy of claws and teeth!%^RESET%^");
    tell_room(ETO,"%^YELLOW%^The tiger snarls and leaps forward, tearing into "+target->QCN+" in a frenzy of claws and teeth!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(40)+mylevel);
    TO->remove_property("magic");
}