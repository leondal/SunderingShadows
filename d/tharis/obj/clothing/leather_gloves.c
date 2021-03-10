//leather_gloves - new gloves for SC thieves.  Circe 9/8/04
#include <std.h>;
inherit "/std/armour";

void create(){
   ::create();
   set_name("thin leather gloves");
   set_id(({"gloves","leather gloves","thin gloves","thin leather gloves","thief clothesxx"}));
   set_short("%^BOLD%^%^BLACK%^thin leather gloves%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This thin pair of gloves is made of "+
      "soft, supple black leather.  The leather covers the back of the "+
      "gloves and the edges of the fingers, making them look exactly "+
      "like normal gloves to the casual observer.  However, the "+
      "underside is made of a special leather that has been worked "+
      "with a pattern to provide added grip.  Clearly, these gloves "+
      "were made to aid in delicate tasks.%^RESET%^");
   set_lore("Thin leather gloves of any type have long been prized by "+
      "those who help themselves to the hard earned money of others.  "+
      "The material used in these gloves, however, is a special leather "+
      "formed by a mage named Alraine for a thief friend of his - "+
      "whose name has never been discovered - to aid them in their "+
      "travels together.  The method for making the material was "+
      "later sold for quick cash on the Tharisian black market, "+
      "making the gloves somewhat available, but still not common.");
   set_property("lore difficulty",12);
   set_type("leather");
   set_limbs(({"right hand","left hand"}));
   set_weight(2);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
   if(random(4)){
      set_size(2);
   }else{
      set_size(random(3)+1);
   }
   set_value(5000);
}

int wearme(){
   if(!ETO->is_class("thief")){
      tell_object(ETO,"The gloves don't seem to fit your hands!");
      return 0;
   }
   if((int)ETO->query_class_level("thief") < 11) {
      tell_object(ETO,"The gloves don't seem to fit your hands!");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^BLACK%^You pull on the leather "+
      "gloves and flex your fingers.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" pulls on a pair "+
      "of soft leather gloves.",ETO);
   ETO->add_skill_bonus("thievery",2);
   return 1;
}

int unwearme(){
   tell_object(ETO,"%^BOLD%^%^BLACK%^You pull the gloves off and your "+
      "hands feel a bit more clumsy somehow.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" pulls off "+ETO->QP+" "+
      "soft black gloves.",ETO);
   ETO->remove_skill_bonus("thievery",2);
   return 1;
}
