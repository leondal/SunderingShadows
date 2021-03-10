// rank 2 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"viper","snake","natures ally"}));
    set_short("%^RESET%^%^GREEN%^green-sca%^BOLD%^l%^RESET%^%^GREEN%^ed viper%^RESET%^");
    set_long("This serpent is nearly eight feet from nose to tail, with bright amber eyes that follow any movement around "
"with a piercing gaze.  Its hide is of a dull forest-green, allowing the creature to move almost unseen in a forest and "
"to spring without warning.  A forked tongue darts out regularly to taste the air as it glides forward.");
    set_race("viper");
    set_body_type("snake");
    set_attack_limbs(({"mouth"}));
    set_base_damage_type("piercing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^BOLD%^%^GREEN%^The viper coils and then leaps forward, sinking its fangs into your skin!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^GREEN%^The viper coils and then leaps forward, sinking its fangs into "+target->QCN+"'s skin!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(20)+mylevel);
    TO->remove_property("magic");
}