// rank 7
#include <std.h>


inherit "/d/magic/mon/naturesally/natureally.c";


void create()
{
    ::create();
    set_id(({"natures ally","tiger","dire tiger"}));
    set_short("%^RESET%^%^BOLD%^%^RED%^d%^BLACK%^i%^RED%^r%^BLACK%^e %^RED%^t%^BLACK%^i%^RED%^g%^BLACK%^e%^RED%^r%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This creature looks almost exactly like a tiger, except it's twice the normal size.  The beast's maw is filled "
        "with %^RESET%^sharp fangs%^ORANGE%^, the longest of which are over a foot in length.  It looks like it weighs close to five thousand pounds and "
        "moves with all the %^RED%^predatory speed %^RESET%^of its much smaller cousins!");
    set_race("dire tiger");
    set_body_type("quadruped");
    set_fake_limbs(({"maw","right front claw","right rear claw","left front claw","left rear claw","right front leg","left front leg","right real leg","left rear leg","torso","tail" }));
    set_attack_limbs(({"maw","right front claw","right rear claw","left front claw","left rear claw"}));
    set_base_damage_type("slashing");
}


void my_special(object target) 
{
    if(!objectp(target)) return;
    tell_object(target,"%^RED%^The dire tiger bites deep into your shoulder and starts thrashing your midsection with its razor sharp claws!");
    tell_room(ETO,"%^RED%^The dire tiger bites deep into "+target->QCN+"'s shoulder and starts raking "+target->QP+" midsection with its razor sharp claws!",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(70)+mylevel);
    TO->remove_property("magic");
}