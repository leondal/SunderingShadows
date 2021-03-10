//altered silk cloak to add variety.  Circe 5/3/04
#include <std.h>

inherit ARMOUR;

void create() {
   ::create();
   set_name("torque of twilight");
   set_id(({"torque","torque of twilight","amulet"}));
   set_short("%^BOLD%^%^BLACK%^Torque of Tw%^WHITE%^i%^BLACK%^"+
      "li%^WHITE%^g%^BLACK%^ht%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^a shi%^WHITE%^f%^BLACK%^ting"+
      " bl%^WHITE%^a%^BLACK%^ck torque%^RESET%^");
   set_property("repairtype",({ "jewel" }));
   set_long("%^BOLD%^%^BLACK%^This shifting, fli%^WHITE%^c%^BLACK%^"+
      "ke%^WHITE%^r%^BLACK%^ing torque seems made of no other "+
      "material than the stuff of tw%^WHITE%^i%^BLACK%^"+
      "li%^WHITE%^g%^BLACK%^ht itself!  It keeps no constant "+
      "form, instead flowing from one shape to another ceaselessly.  "+
      "The shadows seem to wrap themselves eagerly around the "+
      "wearer's neck, dancing there and providing an unusual "+
      "decoration.");
   set_lore("This fantastic torque is said by some sages to "+
      "have simply appeared on this plane.  None can determine "+
      "a method for creating it here, and it seems that perhaps "+
      "they are made on the shadow plane and appear here through "+
      "some strange twist in a place that must be closely "+
      "connected to or cloaked in shadows.");
   set_property("lore difficulty",13);
   set_weight(2);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_ac(0);
   set_property("enchantment",2);
   set_item_bonus("magic resistance",1);
   set_value(500+random(3)*500);
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
}

int wear_func() {
   if((int)ETO->query_lowest_level() < 20){
      tell_object(ETO,"The shadows refuse to close around your neck!");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^BLACK%^The shadows seem to veil the "+
      "world around you.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^The shadows seem to darken "+
      ""+ETOQCN+"'s countenance as "+ETO->QS+" wears the torque.",ETO);
   return 1;
}

int remove_func() {
   tell_object(ETO,"The world around you brightens as you remove the torque.");
   return 1;
}
