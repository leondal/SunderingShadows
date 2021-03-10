// rank 8
#include <std.h>


inherit "/d/magic/mon/naturesally/natureally.c";


void create()
{
    ::create();
    set_id(({"natures ally","roc","bird"}));
    set_short("%^BOLD%^%^BLACK%^roc%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This roc looks like a truely titanic %^WHITE%^eagle%^BLACK%^.  The bird has a wingspan close to eighty feet wide "
        "and stands over thirty feet tall when standing upright.  Its massive %^RESET%^%^ORANGE%^beak %^BOLD%^%^BLACK%^looks like it could "
        "snip an ogre in half with hardly a thought!%^RESET%^");
    set_race("roc");
    set_body_type("fowl");
    set_fake_limbs(({"beak","head","right wing","left wing","right talon","left talon","head","torso" }));
    set_attack_limbs(({"beak","right talon","left talon"}));
    set_base_damage_type("piercing");
}


void my_special(object target) 
{
    if(!objectp(target)) return;
    tell_object(target,"%^RED%^The roc tears into you with its massive beak!");
    tell_room(ETO,"%^RED%^The roc tears into "+target->QCN+" with its massive beak!",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(80)+mylevel);
    TO->remove_property("magic");
}