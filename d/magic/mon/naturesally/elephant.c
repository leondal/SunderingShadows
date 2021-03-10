// rank 6
#include <std.h>


inherit "/d/magic/mon/naturesally/natureally.c";


void create()
{
    ::create();
    set_id(({"natures ally","elephant","lumbering elephant"}));
    set_short("%^BOLD%^%^BLACK%^hu%^RESET%^l%^BOLD%^%^BLACK%^ki%^RESET%^n%^BOLD%^%^BLACK%^g %^RESET%^el%^BOLD%^%^BLACK%^e%^RESET%^pha%^BOLD%^%^BLACK%^n%^RESET%^t%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Standing thirteen feet tall, this "
       "elephant casts a wide shadow.  Its head features a long "
       "trunk offset by two %^RESET%^%^BOLD%^tusks%^BOLD%^%^BLACK%^ "
       "that look sharp enough to skewer a human.  Wide ears spread "
       "to either side of the elephant's head, fanning lightly when "
       "the elephant is standing still and pinning back against its "
       "head when it is angered.  The beast's thick frame and sheer "
       "mass make it a formidable foe in battle.%^RESET%^");
    set_race("elephant");
    set_body_type("quadruped");
    set_fake_limbs(({"head","torso","right front leg","right rear leg","left front leg","left rear leg","right tusk","left tusk" }));
    set_attack_limbs(({"head","right tusk","left tusk"}));
    set_base_damage_type("piercing");
}


void my_special(object target) 
{
    if(!objectp(target)) return;
    tell_object(target,"%^RESET%^%^RED%^The elephant trumpets its rage before charging you with its tusks!%^RESET%^");
    tell_room(ETO,"%^RESET%^%^RED%^The elephant trumpets its rage before charging "+target->QCN+" with its tusks!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(60)+mylevel);
    TO->remove_property("magic");
}