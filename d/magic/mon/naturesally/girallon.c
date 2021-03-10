// rank 6
#include <std.h>


inherit "/d/magic/mon/naturesally/natureally.c";


void create()
{
    ::create();
    set_id(({"natures ally","girallon","giant girallon"}));
    set_short("%^BOLD%^%^WHITE%^gi%^RESET%^a%^BOLD%^nt g%^RESET%^i%^BOLD%^ra%^RESET%^l%^BOLD%^lon%^RESET%^");
    set_long("%^RESET%^This eight-foot-tall magical cousin of "
       "the gorilla has two sets of powerful arms that it uses "
       "to rend its victims.  It uses its legs and lower arms when "
       "it walks, giving it great bursts of speed while still "
       "leaving its upper arms free for defense.  Covered entirely "
       "in %^BOLD%^snow white fur%^RESET%^, this creature is both "
       "unusual and strangely beautiful in its own right.");
    set_race("girallon");
    set_body_type("human");
    set_fake_limbs(({"head","torso","top right arm","bottom right arm","top left arm","bottom left arm","right leg","left left leg","mouth" }));
    set_attack_limbs(({"mouth","top right arm","bottom right arm","top left arm","bottom left arm"}));
    set_base_damage_type("bludgeoning");
}


void my_special(object target) 
{
    if(!objectp(target)) return;
    tell_object(target,"%^BOLD%^%^WHITE%^The girallon wraps you in its four arms before trying to rip you apart!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^WHITE%^The girallon wraps "+target->QCN+" in all four of its arms before yanking hard, trying to rip "+target->QO+" apart!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(60)+mylevel);
    TO->remove_property("magic");
}