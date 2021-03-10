// rank 6
#include <std.h>


inherit "/d/magic/mon/naturesally/natureally.c";


void create()
{
    ::create();
    set_id(({"natures ally","megaraptor","dinosaur"}));
    set_short("%^RESET%^%^GREEN%^s%^BOLD%^p%^RESET%^%^GREEN%^o%^BOLD%^t%^RESET%^%^GREEN%^t%^BOLD%^e%^RESET%^%^GREEN%^d %^BOLD%^m%^RESET%^%^GREEN%^e%^BOLD%^g%^RESET%^%^GREEN%^a%^BOLD%^r%^RESET%^%^GREEN%^a%^BOLD%^p%^RESET%^%^GREEN%^t%^BOLD%^o%^RESET%^%^GREEN%^r%^RESET%^");
    set_long("%^RESET%^%^GREEN%^Looking something like a "
       "small tyrannosaurus, this megaraptor is a giant in "
       "its own right.  It stands just over twelve feet tall "
       "but stretches out for twenty-four feet from head to "
       "tail.  Like other raptors, its arms are thin and short "
       "but end in vicious-looking %^BOLD%^%^BLACK%^claws%^RESET%^"
       "%^GREEN%^.  The hide of the creature is a bright shade of "
       "green with a much lighter shade on its %^BOLD%^underbelly"
       "%^RESET%^%^GREEN%^.  Scattered along its back and sides are "
       "darker %^BOLD%^%^BLACK%^s%^RESET%^%^GREEN%^p%^BOLD%^%^BLACK%^"
       "o%^RESET%^%^GREEN%^t%^BOLD%^%^BLACK%^s%^RESET%^%^GREEN%^ that "
       "continue along its neck to its head, which features a mouth "
       "filled with sharp %^RESET%^%^BOLD%^teeth%^RESET%^%^GREEN%^.%^RESET%^");
    set_race("dinosaur");
    set_body_type("reptile");
    set_fake_limbs(({"head","torso","mouth","right arm","left arm","right leg","left leg","tail"}));
    set_attack_limbs(({"mouth","right arm","left arm"}));
    set_base_damage_type("slashing");
}


void my_special(object target) 
{
    if(!objectp(target)) return;
    tell_object(target,"%^BOLD%^%^GREEN%^With blinding speed, the megaraptor "
       "darts out to one side, flanking you. Before you can react, the "
       "megaraptor bites deep into your "+(string)target->return_target_limb()+", "
       "leaving you in excruciating pain!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^GREEN%^With blinding speed, the megaraptor darts out "
       "to one side, flanking "+target->QO+" and biting "+target->QO+" viciously!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(60)+mylevel);
    TO->remove_property("magic");
}