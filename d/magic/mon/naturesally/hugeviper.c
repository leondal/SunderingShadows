// rank 4 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"viper","huge viper","snake","natures ally"}));
    set_short("%^RESET%^%^ORANGE%^huge m%^BOLD%^%^BLACK%^ot%^RESET%^%^ORANGE%^tled viper%^RESET%^");
    set_long("This serpent is impossibly large, nearly twenty feet from nose to tail and big enough to encircle a fully "
"grown man.  Mottled patches of black and gray trail down its pale, scaled hide.  A forked tongue darts out regularly to "
"taste the air, as its small yellow eyes keep a close watch on anything that moves.");
    set_race("viper");
    set_body_type("snake");
    set_attack_limbs(({"mouth"}));
    set_base_damage_type("piercing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^BOLD%^%^GREEN%^The massive viper coils and then leaps forward, sinking its fangs into your skin!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^GREEN%^The massive viper coils and then leaps forward, sinking its fangs into "+target->QCN+"'s skin!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(40)+mylevel);
    TO->remove_property("magic");
}