//shadow_circlet.c - Coded by Circe 5/2/04
#include <std.h>

inherit"/std/armour";

void create(){
::create();

   set_name("Crown of the Shadow Dancer");
   set_id(({"crown","shadow crown","crown of the shadow dancer"}));
   set_obvious_short("%^BOLD%^%^BLACK%^A fli%^WHITE%^c%^BLACK%^ke"+
      "r%^WHITE%^i%^BLACK%^ng crown%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Crown of the Shadow Dancer%^RESET%^");
   set_property("repairtype",({ "jewel" }));
   set_long("%^BOLD%^%^BLACK%^This shifting, flickering crown seems "+
      "made of no "+
      "other material than the stuff of shadows themselves!  It keeps "+
      "no constant form, instead flowing from one shape to another "+
      "ceaselessly.  The shadows seems to weave themselves into  the "+
      "wearer's hair, dancing there and providing an unusual "+
      "decoration.%^RESET%^");
   set_lore("This fantastic crown is said by some sages to "+
      "have simply appeared on this plane.  None can determine "+
      "a method for creating it here, and it seems that perhaps "+
      "they are made on the shadow plane and appear here through "+
      "some strange twist in a place that must be closely "+
      "connected to or cloaked in shadows.");
   set_property("lore difficulty",13);
   set_type("clothing"); 
   set_limbs(({"head"}));
   set_ac(0);
   set_property("enchantment",2);
   set_weight(2);
   set_value(750);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
}

int wearme(){
object *armor;
int i,FLAG;
FLAG = 0;
   if((int)ETO->query_lowest_level() < 20){
      tell_object(ETO,"The shadows reject one as weak as you!");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^BLACK%^The shadows weave themselves "+
      "into your hair as you wear the crown.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^The shadows of the crown "+
      "dance as "+ETOQCN+" wears it.",ETO);
   return 1;
}

int unwearme(){
   tell_object(ETO,"%^BOLD%^%^BLACK%^The shadows snag at your hair, "+
      "pulling lightly as you take off the crown.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^The shadows of "+ETOQCN+"'s "+
      "crown seem to pull at "+ETO->QP+" hair as "+ETO->QS+" "+
      "removes the crown.",ETO);
   return 1;
}