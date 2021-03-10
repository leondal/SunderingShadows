// rank 3 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"constrictor","boa","boa constrictor","snake","natures ally"}));
    set_short("%^RESET%^%^RED%^heavy boa constrictor%^RESET%^");
    set_long("This serpent is heavily built, possibly as heavy as sixty pounds.  Saddles of darker russet trail down its "
"creamy scaled hide to the tip of its tail, perhaps twelve or thirteen feet from its narrow snout.  Its fangs are not "
"usually venomous, but can offer a painful bite all the same.  A forked tongue darts out regularly to taste the air, as "
"its amber eyes keep a close watch on anything that moves.");
    set_race("constrictor");
    set_body_type("snake");
    set_attack_limbs(({"torso"}));
    set_base_damage_type("bludgeoning");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^BOLD%^%^GREEN%^The constrictor wraps itself around you and squeezes, making you gasp for air!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^GREEN%^The constrictor wraps itself around "+target->QCN+" and squeezes, making "+target->QO+" gasp for air!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(30)+mylevel);
    TO->remove_property("magic");
}