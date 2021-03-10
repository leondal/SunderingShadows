// rank 2 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"badger","dire badger","feral badger","feral dire badger","natures ally"}));
    set_short("%^BOLD%^%^BLACK%^feral d%^RESET%^i%^BOLD%^%^BLACK%^re badger%^RESET%^");
    set_long("Before you stands a short-legged, heavy-set creature of mostly graying fur, with a pure white stripe from "
"its pointed nose down its back, and black markings either side of its face.  Thick claws upon each limb are perhaps "
"designed primarily for digging, but they would form potential weapons for the beast which has a reputation for ferocity"
".  Worse yet are the razor-sharp teeth, set within a powerful jaw.  This particular specimen seems even more vicious "
"than most, with a feral, almost demonic gleam in its dark eyes.");
    set_race("badger");
    set_body_type("quadruped");
    add_limb("teeth","head",0,0,0);
    add_limb("right claws","right forepaw",0,0,0);
    add_limb("left claws","left forepaw",0,0,0);
    set_attack_limbs(({"teeth","right claws","left claws"}));
    set_base_damage_type("slashing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^BOLD%^%^CYAN%^With a snarl, the badger barrels into you and sends you sprawling!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^CYAN%^With a snarl, the badger barrels into "+target->QCN+" and sends "+target->QO+" sprawling!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(20)+mylevel);
    TO->remove_property("magic");
}