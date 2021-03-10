//updated description and moved the lore-y bits to be lore
//~Circe~ 5/21/07
#include <std.h>;
#include "../undead.h"

inherit CARMOR"fullplate";

void create() 
{
    ::create();
    set_name("deathplate");
    set_id( ({ "armor", "full plate","plate","medium fullplate", "fullplate" }));
    set_obvious_short("%^BOLD%^%^BLACK%^solid black fullplate%^RESET%^");
    set_short("%^RESET%^D%^BOLD%^%^BLACK%^eath %^RESET%^P%^BOLD%^%^BLACK%^late%^RESET%^");
    
/*    set_long("This is an enormous suit of solid black plate armor. Each "
        "plate is several centimeters in width, and it is due only to the "
        "supernatural strength of the undead infantry that they are "
        "even able to don this impressive armor. But it is powerful "
        "to behold, nonetheless.");
*/
    set_long("%^BOLD%^%^BLACK%^This enormous suit of solid black "
       "armor is fashioned of sinuous metal plates several "
       "centimeters in width.  The shoulders feature two pairs "
       "of spikes, the inner ones shorter than the outer.  Both "
       "sets of spikes curve inward toward the wearer's face, "
       "providing a grisly appearance.  The armor seems not to "
       "tarnish, and it glints faintly in the light.%^RESET%^");
    set_lore("This set of plate mail is known as Death Plate and was "
       "once worn by an undead infantryman on the isle of Graez.  "
       "That island is plaqued by some great evil, but this mail, "
       "unfortunately, reveals little more of the story.");

    set_value(500);
    set_property("enchantment",2);
    set_property("treasure_type", "25D");
    set_wear((:this_object(), "extra_wear":));
    set_remove((:this_object(), "extra_remove":));
    set("dexbonus",-2);
}

// TP in wear and unwear fixed by Circe & Styx to be ETO to fix bugginess  8/2003
int extra_wear()
{
    if(!ETO->is_player()) { return 1; }
    if((int)ETO->query_level() > 18)
    {
        tell_object(ETO,"%^RED%^Your muscles strain under the weight of the mighty Death plate.%^RESET%^");
        return 1;
    }
    tell_object(ETO,"%^BOLD%^%^RED%^You are far to weak for this mighty plate!%^RESET%^");
    return 0;
}

int extra_remove()
{
    tell_object(ETO,"%^MAGENTA%^You feel a great evil leave you as you remove the Death plate.%^RESET%^\n");
    return 1;
}
