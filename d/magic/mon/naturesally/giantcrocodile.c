// rank 4 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"crocodile","giant crocodile","natures ally"}));
    set_short("%^RESET%^%^GREEN%^giant crocodile%^RESET%^");
    set_long("This reptile looks much like a normal crocodile except for its size, which approaches more than twenty-five "
"feet from nose to tail.  A predator with a reputation for surprising speed, whether on land or in the water, its "
"greatest weapon is the powerful jaw with which it crushes prey.  Pebbly hide coats the creature from head to tail, "
"colored a dull gray-green that would serve as effective camouflage in the wild.");
    set_race("crocodile");
    set_body_type("reptile");
    add_limb("teeth","head",0,0,0);
    set_attack_limbs(({"teeth"}));
    set_base_damage_type("piercing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^YELLOW%^The crocodile lunges forward and its maw clamps down hard on your leg, nearly crushing your bones!%^RESET%^");
    tell_room(ETO,"%^YELLOW%^The crocodile lunges forward and its maw clamps down hard on "+target->QCN+"'s leg, nearly crushing "+target->QP+" bones!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(40)+mylevel);
    TO->remove_property("magic");
}