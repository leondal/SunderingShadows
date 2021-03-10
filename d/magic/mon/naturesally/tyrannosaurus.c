// rank 7
#include <std.h>


inherit "/d/magic/mon/naturesally/natureally.c";


void create()
{
    ::create();
    set_id(({"natures ally","tyrannosaurus","dinosaur","looming tyrannosaurus"}));
    set_short("%^RESET%^%^RED%^lo%^BOLD%^o%^RESET%^%^RED%^min%^BOLD%^g %^RESET%^%^RED%^ty%^BOLD%^r%^RESET%^%^RED%^anno%^BOLD%^s%^RESET%^%^RED%^aurus%^RESET%^");
    set_long("%^RESET%^%^RED%^This terrifying carnivore is "
       "over forty feet long and fifteen feet tall at the "
       "hip.  Its small front arms end in two %^BOLD%^%^BLACK%^"
       "claws %^RESET%^%^RED%^while its muscular back legs allow "
       "it to run with amazing speed.  The beast's head is over "
       "six feet long and features a mouth full of vicious "
       "%^RESET%^teeth %^RED%^ranging from three to six inches "
       "each.  One look at this awe-inspiring beast makes it "
       "clear why this creature is known as the king of the dinosaurs.%^RESET%^");
    set_race("dinosaur");
    set_body_type("reptile");
    set_attack_limbs(({"head"}));
    set_base_damage_type("bludgeoning");
}


void my_special(object target) 
{
    if(!objectp(target)) return;
    tell_object(target,"%^BOLD%^%^RED%^The tyrannosaurus bites you viciously, nearly swallowing you whole before dropping you to the ground!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^RED%^The tyrannosaurus bites "+target->QCN+" viciously, nearly swallowing "+target->QO+" whole before dropping "+target->QO+" to the ground!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(70)+mylevel);
    TO->remove_property("magic");
}