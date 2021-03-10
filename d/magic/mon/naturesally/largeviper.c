// rank 3 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"viper","large viper","snake","natures ally"}));
    set_short("%^RESET%^%^ORANGE%^large sp%^RESET%^ot%^ORANGE%^ted vip%^BOLD%^%^BLACK%^e%^RESET%^r%^RESET%^");
    set_long("This serpent is of impressive size, nearly fifteen feet from nose to tail and certainly capable of taking "
"down more than mere rats and vermin.  Pale spots encircled in black trail down its dark scaly hide.  A forked tongue "
"darts out regularly to taste the air, as its small yellow eyes keep a close watch on anything that moves.");
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
    target->do_damage("torso",random(30)+mylevel);
    TO->remove_property("magic");
}