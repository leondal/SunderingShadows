#include <std.h>
#include "../kildare.h"
inherit "/d/common/obj/armour/helm";

void create() {
    ::create();
    set_name("iron hat");
    set_id(({"hat","iron hat", "helmet","helm","farmer's hat","Farmer's Hat"}));
    set_obvious_short("A farmer's hat");
    set_short("%^BOLD%^%^BLACK%^Iron Hat%^RESET%^");
    set_long("Often called a farmer's hat, this particular piece of headgear "+
       "has a rounded cap with a wide brim.  At first glance, it seems to be "+
       "made of blackened straw, but upon closer look, it is obvious that "+
       "it is instead made of iron cleverly disguised.  Despite its somewhat "+
       "innocuous appearance, the hat would probably protect the wearer quite "+
       "well, even in battle.  A light gray strip of silk has been tied around "+
       "the circular cap of the hat and may be tied under the chin to keep "+
       "it on securely.  The inside of the hat is fitted with a matching silk "+
       "lining to ensure the comfort of the wearer."
    );
    set_lore(
       "True farmer's hats were often made of straw woven together to form "+
       "the wide brim and circular cap.  However, not long before the peasant "+
       "uprising in the province of Drogheda, the leaders of the serf revolt "+
       "began making cleverly designed weapons and armor, much like this one.  "+
       "From a distance, these hats - as well as the other inventions of the "+
       "time - seemed harmless.  Because of this, great power was amassed before "+
       "the lord of Drogheda had any idea of the planned revolt."
    );
    set_property("lore difficulty",8);
    set_value(30);
    set_property("enchantment",1);
    set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
}

int wearme()
{
   tell_object(ETO,"%^GREEN%^You tie the sash under your chin and feel close to the earth.");
   tell_room(environment(ETO),"%^GREEN%^"+ETO->query_cap_name()+" settles the wide-brimmed "+
      "hat on "+ETO->query_possessive()+" head and looks a little like a farmer.",ETO);
   return 1;
}

int unwearme()
{
   tell_object(ETO,"%^GREEN%^You untie the sash and slip the hat off your head, "+
      "feeling the spirit of the earth recede.");
   tell_room(environment(ETO),"%^GREEN%^"+ETO->query_cap_name()+" unties the sash "+
      "and slips the hat off "+ETO->query_possessive()+" head, looking a little "+
      "more like "+ETO->query_objective()+"self.",ETO);
   return 1;
}
