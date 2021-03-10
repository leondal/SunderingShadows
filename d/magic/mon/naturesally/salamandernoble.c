// rank 8
#include <std.h>


inherit "/d/magic/mon/naturesally/natureally.c";


void create()
{
    ::create();
    set_id(({"natures ally","noble salamander","salamander"}));
    set_short("%^YELLOW%^no%^RED%^b%^YELLOW%^le %^RESET%^%^RED%^sa%^YELLOW%^l%^RESET%^%^RED%^a%^BOLD%^m%^RESET%^%^RED%^an%^ORANGE%^d%^RED%^er%^RESET%^");
    set_long("%^RESET%^%^RED%^This serpentine creature stands "
       "over eight feet tall, even with an equally long tail "
       "trailing behind.  Its scales %^BOLD%^g%^YELLOW%^l%^RESET%^"
       "%^ORANGE%^i%^RED%^s%^BOLD%^t%^YELLOW%^e%^RESET%^%^ORANGE%^n "
       "%^BOLD%^%^RED%^red %^RESET%^%^RED%^in the light, making it "
       "seem slimy despite the faint hint of %^BOLD%^%^BLACK%^smoke "
       "%^RESET%^%^RED%^that rises on the air around it.  Despite "
       "its snake-like resemblance, the creature has two arms near "
       "where a human's would be, though both are covered in the "
       "same %^BOLD%^red scales%^RESET%^%^RED%^.  A long, flowing "
       "%^BOLD%^%^BLACK%^black robe %^RESET%^%^RED%^is worn open over the "
       "creature's muscular torso, and it moves with an arrogant confidence.%^RESET%^");
    set_race("salamander");
    set_body_type("human");
    set_fake_limbs(({"head","torso","mouth","right arm","left arm","tail"}));
    set_attack_limbs(({"mouth","right arm","left arm"}));
    set_base_damage_type("slashing");
}


void my_special(object target) 
{
    if(!objectp(target)) return;
    tell_object(target,"%^RESET%^%^RED%^The %^YELLOW%^no%^RED%^b%^YELLOW%^le "
       "%^RESET%^%^RED%^sa%^YELLOW%^l%^RESET%^%^RED%^a%^BOLD%^m%^RESET%^%^RED%^"
       "an%^ORANGE%^d%^RED%^er%^RESET%^%^RED%^ spreads its hands wide, and a "
       "%^BOLD%^fi%^YELLOW%^r%^WHITE%^eb%^YELLOW%^a%^RED%^ll %^RESET%^%^RED%^"
       "bursts forth, scorching you!%^RESET%^");
    tell_room(ETO,"%^RESET%^%^RED%^The %^YELLOW%^no%^RED%^b%^YELLOW%^le "
       "%^RESET%^%^RED%^sa%^YELLOW%^l%^RESET%^%^RED%^a%^BOLD%^m%^RESET%^%^RED%^"
       "an%^ORANGE%^d%^RED%^er%^RESET%^%^RED%^ spreads its hands wide, and a "
       "%^BOLD%^fi%^YELLOW%^r%^WHITE%^eb%^YELLOW%^a%^RED%^ll %^RESET%^%^RED%^"
       "bursts forth, scorching "+target->QCN+"!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(80)+mylevel);
    TO->remove_property("magic");
}