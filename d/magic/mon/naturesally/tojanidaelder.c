// rank 8
#include <std.h>


inherit "/d/magic/mon/naturesally/natureally.c";


void create()
{
    ::create();
    set_id(({"natures ally","elder tojanida","tojanida"}));
    set_short("%^RESET%^%^GREEN%^el%^CYAN%^d%^GREEN%^er t%^CYAN%^o%^GREEN%^ja%^CYAN%^n%^GREEN%^ida%^RESET%^");
    set_long("%^RESET%^%^GREEN%^This massive creatures looks like "
       "a cross between a turtle and a spiked crab, though this one "
       "is over nine feet long and weighs more than 500 pounds.  Its "
       "shell is the color of the %^CYAN%^deep sea%^GREEN%^ and features "
       "eight openings so that the tojanida can configure its seven "
       "stalks in whatever way is most convenient.  Each stalk serves a "
       "specific function - four are fitted with paddles for locomotion, "
       "two with claws for defense, and the last holds the creature's "
       "head.  When threatened, the creature is known to grab a victim "
       "and pull him inside the shell, only to expel him through the "
       "unused opening high into the air.%^RESET%^");
    set_race("tojanida");
    set_body_type("reptile");
    set_fake_limbs(({"head","shell","mouth","right claw","left claw","right foreleg","right rear leg","left foreleg","left rear leg"}));
    set_attack_limbs(({"mouth","right claw","left claw"}));
    set_base_damage_type("piercing");
}


void my_special(object target) 
{
    if(!objectp(target)) return;
    tell_object(target,"%^RESET%^%^CYAN%^The %^RESET%^%^GREEN%^el%^CYAN%^d%^GREEN%^er "
       "t%^CYAN%^o%^GREEN%^ja%^CYAN%^n%^GREEN%^ida %^CYAN%^grabs you with its claws, "
       "pulling you into its shell before expelling you high into the air!%^RESET%^");
    tell_object(target,"%^BOLD%^%^GREEN%^You land with a %^CYAN%^splat%^GREEN%^!%^RESET%^");
    tell_room(ETO,"%^RESET%^%^CYAN%^The %^RESET%^%^GREEN%^el%^CYAN%^d%^GREEN%^er t"
       "%^CYAN%^o%^GREEN%^ja%^CYAN%^n%^GREEN%^ida %^CYAN%^grabs "+target->QCN+" "
       "with its claws, pulling "+target->QO+" into its shell before expelling "
       ""+target->QO+" high into the air!%^RESET%^",target);
    tell_room(ETO,"%^BOLD%^%^GREEN%^"+target->QCN+" lands with a %^CYAN%^splat%^GREEN%^!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(80)+mylevel);
    TO->remove_property("magic");
}