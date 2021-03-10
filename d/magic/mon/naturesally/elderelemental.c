// rank 9
#include <std.h>


inherit "/d/magic/mon/naturesally/natureally.c";

string *elements = ({ "fire","air","earth","water" });

string get_element() { return elements[random(sizeof(elements))]; }

string element;

void create()
{
    element = get_element();
    ::create();
    set_id(({"natures ally","elemental","elder elemental",""+element+" elemental","elder "+element+" elemental"}));
    switch(element){
       case "fire": element = "%^RESET%^%^RED%^f%^YELLOW%^i%^RED%^r%^RESET%^%^RED%^e";
            break;
       case "air": element = "%^RESET%^%^CYAN%^a%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^r";
            break;
       case "earth": element = "%^RESET%^%^ORANGE%^e%^RESET%^a%^ORANGE%^r%^YELLOW%^t%^RESET%^%^ORANGE%^h";
            break;
       case "water": element = "%^BOLD%^%^BLUE%^w%^CYAN%^a%^WHITE%^t%^CYAN%^e%^BLUE%^r";
            break;
    }
    set_short("%^RESET%^elder "+element+"%^RESET%^ elemental");
    set_long("%^RESET%^Standing over fifteen feet tall, this vaguely humanoid shape "
       "is composed entirely of "+element+"%^RESET%^.  It attacks much "
       "as a human would, but its body is crafted from strands of "
       ""+element+" %^RESET%^that seem to shift and move, adjusting "
       "to the movements of the creature.  Its eyes are filled with "
       ""+element+"%^RESET%^, and a menacing purpose seems to lurk "
       "within those depths.");
    set_race("elemental");
    set_body_type("human");
    set_fake_limbs(({"head","torso","right arm","left arm","right leg","left leg" }));
    set_attack_limbs(({"right arm","left arm","head"}));
    set_base_damage_type("bludgeoning");
}


void my_special(object target) 
{
    if(!objectp(target)) return;
    tell_object(target,"%^BOLD%^%^RED%^The elder "+element+" elemental %^RESET%^%^BOLD%^%^RED%^crushes you violently in the chest!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^RED%^The elder "+element+" elemental %^RESET%^%^BOLD%^%^RED%^crushes "+target->QCN+" violently in the chest!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(90)+mylevel);
    TO->remove_property("magic");
}