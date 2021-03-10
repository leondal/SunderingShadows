#include <std.h>
#include "../kildare.h"

inherit ARMOUR;

void create()
{
   ::create();
    set_id(({"headband","head band","leather band","leather headband","band"}));
    set_name("band of the owls");
    set_obvious_short("%^RESET%^%^ORANGE%^A leather headband%^RESET%^");
    set_short("%^YELLOW%^Band of the Owls%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This leather band is about an inch and a "+
      "half wide with images of owls in flight burned across the face.  Thin "+
      "leather cords attached to the ends can be used to tie it around your "+
      "forehead.  A long, %^BOLD%^%^WHITE%^snowy white owlfeather %^RESET%^%^ORANGE%^"+
      "dangles from one of the cords.%^RESET%^");
    set_lore("This headband is one of many made originally by a "+
      "band of rangers in service to the Lady of the Forests "+
      "in the foothills of Echoes Mountains.  They were said to "+
      "grant the wearer with extended sight, much like the owl's.");
    set_property("lore difficulty",8);
    set_limbs(({"head"}));
    set_type("clothing");
    set_ac(0);
    set_property("enchantment",1);
    set_weight(3);
    set_size(-1);
    set_item_bonus("sight bonus",3);
    set("value",200);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"unwearme":));
    set_heart_beat(1);
}

int wearme()
{
   object *armor;
   int i,FLAG;
   FLAG = 0;
   if(ETO->query_lowest_level() < 8){
      tell_object(ETO,"%^BOLD%^%^WHITE%^You are not experienced enough to "+
      "wear this headband!");
      return 0;
   }
      tell_object(ETO,"%^RESET%^%^ORANGE%^You tie the headband around your forehead "+
         "and your eyes sting briefly.%^RESET%^");
      tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+TPQCN+" puts on the leather band "+
         "and squints, blinking quickly.%^RESET%^",ETO);
      return 1;
}

int unwearme()
{
   tell_object(ETO,"%^YELLOW%^The room seems to dim as you remove the headband.%^RESET%^");
   return 1;
}