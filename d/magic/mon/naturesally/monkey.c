// rank 1 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"monkey","natures ally"}));
    set_short("%^RESET%^%^ORANGE%^ag%^RED%^i%^ORANGE%^le monkey%^RESET%^");
    set_long("This monkey bears spindly legs and a prehensile tail, moving as easily with any of these five independant "
"limbs.  Its face bears a squashed nose and beady eyes, surrounded by a frame of short tan fur.  Its fingers move with "
"the dexterity of a skilled pickpocket.  An almost human grin reveals a mouth of sharp, canine teeth.");
    set_race("monkey");
    set_body_type("quadruped");
    set_attack_limbs(({"right forepaw","left forepaw"}));
    set_base_damage_type("bludgeoning");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^BOLD%^%^CYAN%^The monkey leaps onto your shoulder, clawing and biting at your face!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^CYAN%^The monkey leaps onto "+target->QCN+"'s shoulder, clawing and biting at "+target->QP+" face!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(10)+mylevel);
    TO->remove_property("magic");
}