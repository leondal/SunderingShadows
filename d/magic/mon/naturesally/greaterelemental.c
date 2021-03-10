// rank 7
#include <std.h>


inherit "/d/magic/mon/naturesally/natureally.c";

string *elements = ({ "fire","air","earth","water" });

string get_element() { return elements[random(sizeof(elements))]; }

string element;

void create()
{
    element = get_element();
    ::create();
    set_id(({"natures ally","elemental","greater elemental",""+element+" elemental","greater "+element+" elemental"}));
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
    set_short("%^RESET%^greater "+element+"%^RESET%^ elemental");
    set_long("%^RESET%^Standing over twelve feet tall, this vaguely humanoid shape "
       "is composed entirely of "+element+"%^RESET%^.  It attacks much "
       "as a human would, but its body is crafted from strands of "
       ""+element+" %^RESET%^that seem to shift and move, adjusting "
       "to the movements of the creature.  Its eyes are filled with "
       ""+element+"%^RESET%^, and a menacing purpose seems to lurk "
       "within those depths.");
    set_race("elemental");
    set_body_type("human");
    set_attack_limbs(({"right arm","left arm","head"}));
    set_base_damage_type("bludgeoning");
}


void my_special(object target) 
{
    if(!objectp(target)) return;
    tell_object(target,"%^YELLOW%^The %^RESET%^"+element+" elemental %^RESET%^%^YELLOW%^moves pummels you with %^RESET%^"+element+"%^RESET%^%^YELLOW%^!");
    tell_room(ETO,"%^YELLOW%^The %^RESET%^"+element+" elemental %^RESET%^%^YELLOW%^moves pummels "+target->QCN+" with %^RESET%^"+element+"%^RESET%^%^YELLOW%^!",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(70)+mylevel);
    TO->remove_property("magic");
}