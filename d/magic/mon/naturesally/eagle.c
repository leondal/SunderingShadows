// rank 1 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"eagle","golden eagle","natures ally"}));
    set_short("%^RESET%^%^ORANGE%^golden eagle%^RESET%^");
    set_long("This noble beast bears an intelligent gleam in its sharp eyes, as its head darts to follow the movement of "
"anything nearby.  A powerful hooked beak leads back to a face swept with golden-brown feathers, darkening around its "
"wings and chest.  Its feet bear vicious talons that could do considerable damage to an opponent.");
    set_race("eagle");
    set_body_type("fowl");
    set_attack_limbs(({"beak","right claw","left claw"}));
    set_base_damage_type("slashing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^YELLOW%^The eagle swoops at your head, raking razor-sharp talons across your scalp!%^RESET%^");
    tell_room(ETO,"%^YELLOW%^The eagle swoops at "+target->QCN+"'s head, raking razor-sharp talons across "+target->QP+" scalp!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(10)+mylevel);
    TO->remove_property("magic");
}