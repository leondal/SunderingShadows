// rank 7
#include <std.h>


inherit "/d/magic/mon/naturesally/natureally.c";


void create()
{
    ::create();
    set_id(({"natures ally","triceratops","dinosaur","plated triceratops"}));
    set_short("%^RESET%^%^ORANGE%^pl%^GREEN%^a%^ORANGE%^ted tri%^RED%^c%^ORANGE%^era%^GREEN%^t%^ORANGE%^ops%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^At twenty-five feet long and "
       "weighing over 20,000 pounds, this hulking beast is a "
       "force to be reckoned with.  Like its much smaller lizard "
       "kin, the triceratops has a wide body narrowing to a slender "
       "tail.  Its head is plated and armored, flaring out to protect "
       "its neck.  Twin horns spring from above its small eyes, while "
       "a third juts out over its beak of a mouth.  Its hide is m"
       "%^RED%^o%^GREEN%^t%^ORANGE%^t%^RED%^l%^GREEN%^e%^ORANGE%^d "
       "with a %^RED%^reddish underbelly%^ORANGE%^ and a %^GREEN%^"
       "greener back%^ORANGE%^.  Given its size and strength, it "
       "could likely defend itself - and its master - quite well.%^RESET%^");
    set_race("dinosaur");
    set_body_type("reptile");
    set_attack_limbs(({"head"}));
    set_base_damage_type("bludgeoning");
}


void my_special(object target) 
{
    if(!objectp(target)) return;
    tell_object(target,"%^BOLD%^The triceratops charges ahead, nearly shattering your ribs as it drives you to the ground!%^RESET%^");
    tell_room(ETO,"%^BOLD%^The triceratops charges "+target->QCN+", driving "+target->QO+" to the ground!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(70)+mylevel);
    TO->remove_property("magic");
}