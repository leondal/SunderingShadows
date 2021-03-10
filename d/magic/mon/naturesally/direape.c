// rank 4 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"ape","dire ape","monkey","natures ally"}));
    set_short("%^RESET%^fer%^RED%^a%^RESET%^l dire ape%^RESET%^");
    set_long("This beast stands somewhat man-like, taller than a human with arms that reach to the ground with ease.  Its "
"face bears a squashed nose and a tall, flat forehead that nearly hides its tiny eyes.  Powerful muscles ripple under a "
"coat of pale, shaggy fur, allowing movement at surprising speed for such a large beast.  This particular specimen seems "
"even more vicious than most, with a feral, almost demonic gleam in its dark eyes.");
    set_race("ape");
    set_body_type("quadruped");
    set_attack_limbs(({"right forepaw","left forepaw"}));
    set_base_damage_type("bludgeoning");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^YELLOW%^Leaping forward, the ape lifts you bodily from the ground before slamming you down into it with a force that shakes your entire body!%^RESET%^");
    tell_room(ETO,"%^YELLOW%^Leaping forward, the ape lifts "+target->QCN+" bodily from the ground before slamming "+target->QO+" back down into it!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(40)+mylevel);
    TO->remove_property("magic");
}