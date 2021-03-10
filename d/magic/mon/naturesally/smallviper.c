// rank 2 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"viper","snake","natures ally"}));
    set_short("%^RESET%^%^ORANGE%^small g%^YELLOW%^o%^RESET%^%^ORANGE%^lden viper%^RESET%^");
    set_long("This snake is only small, perhaps three or four feet in length.  It does not at first appear to be a threat"
", but the creature's alert gaze hints at a beast not to be ignored.  Its scaled hide is a beautiful shade of golden-"
"orange.  A forked tongue darts out regularly to taste the air as it glides forward.");
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
    target->do_damage("torso",random(10)+mylevel);
    TO->remove_property("magic");
}