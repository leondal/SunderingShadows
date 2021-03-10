// rank 4 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"deinonychus","dinosaur","natures ally"}));
    set_short("%^RESET%^%^GREEN%^agile de%^BOLD%^i%^RESET%^%^GREEN%^nonychus%^RESET%^");
    set_long("Small for a dinosaur, this raptor still stands at nearly the height of a man.  The creature bears a cold "
"reptilian gaze, sweeping above a maw filled with curved, blade-like teeth.  With only short forelimbs, the creature "
"could at first be dismissed until looking upon its balanced hind legs, upon each of which lies a large, sickle-shaped "
"talon used to cause horrific damage to prey.");
    set_race("deinonychus");
    set_body_type("reptile");
    add_limb("left talon","left rear foot",0,0,0);
    add_limb("right talon","right rear foot",0,0,0);
    add_limb("teeth","head",0,0,0);
    set_attack_limbs(({"right talon","left talon","teeth"}));
    set_base_damage_type("slashing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^YELLOW%^The raptor leaps forward on its powerful hind legs and then shifts its weight, slashing upwards with a talon in a move so sudden it nearly disembowels you!%^RESET%^");
    tell_room(ETO,"%^YELLOW%^The raptor leaps forward on its powerful hind legs and then shifts its weight, slashing upwards with a talon in a move so sudden it nearly disembowels "+target->QCN+"!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(40)+mylevel);
    TO->remove_property("magic");
}