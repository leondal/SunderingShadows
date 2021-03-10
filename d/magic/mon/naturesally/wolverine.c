// rank 2 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"wolverine","natures ally"}));
    set_short("%^BOLD%^%^BLACK%^dark-furred wolverine%^RESET%^");
    set_long("This stocky, muscular beast looks most like a bear with a bushy tail.  Such beasts have a reputation for "
"strength and ferocity that far outstrips their size, able to take down creatures many times larger than they.  Its thick"
", oily brown fur darkens at the extremities nearly to black.");
    set_race("wolverine");
    set_body_type("quadruped");
    add_limb("left claws","left forepaw",0,0,0);
    add_limb("right claws","right forepaw",0,0,0);
    set_attack_limbs(({"right claws","left claws"}));
    set_base_damage_type("slashing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^YELLOW%^The wolverine darts forward and sinks its teeth into you, rending flesh with its powerful jaws!%^RESET%^");
    tell_room(ETO,"%^YELLOW%^The wolverine darts forward and sinks its teeth into "+target->QCN+", rending flesh with its powerful jaws!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(20)+mylevel);
    TO->remove_property("magic");
}