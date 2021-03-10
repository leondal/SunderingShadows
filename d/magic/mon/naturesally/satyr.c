// rank 3 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"satyr","natures ally"}));
    set_short("%^RESET%^%^ORANGE%^fr%^RED%^o%^ORANGE%^lic%^RED%^ki%^ORANGE%^ng satyr%^RESET%^");
    set_long("Looking much like a human, this creature has the legs, tail and horns of a goat.  Ebon hooves strike the "
"ground as the creature moves with a light, almost playful gait, a twinkle in its eye and a curl to the tip of its "
"chestnut-brown beard.  Usually fun-loving, satyrs nonetheless resent intrusions and will forcibly drive away creatures "
"that offend them.");
    set_race("satyr");
    set_gender("male");
    set_body_type("humanoid");
    set_attack_limbs(({"right hand","left hand"}));
    set_base_damage_type("bludgeoning");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^YELLOW%^The satyr lunges forward to headbutt you with its sharp horns!%^RESET%^");
    tell_room(ETO,"%^YELLOW%^The satyr lunges forward to headbutt "+target->QCN+" with its sharp horns!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(30)+mylevel);
    TO->remove_property("magic");
}