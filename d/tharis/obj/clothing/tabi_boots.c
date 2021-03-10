//tabi_boots - new shoes for SC thieves.  Circe 9/8/04
#include <std.h>;
inherit "/std/armour";

void create(){
   ::create();
   set_name("tabi boots");
   set_id(({"tabi boots","boots","shoes","thief clothesxx"}));
   set_short("%^BOLD%^%^BLACK%^tabi boots%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This pair of shoes consists of a thin "+
      "leather sole with a split toe.  The leather is held to the "+
      "bottom of the foot while black silk is wrapped all around the "+
      "foot and up the ankle, separating the big toe from the others "+
      "to provide better mobility.%^RESET%^");
   set_lore("Tabi boots are an ancient invention, one still used by "+
      "many who prefer stealth to overt action.  They are quite simple "+
      "in design, but can prove quite effective if one knows how to "+
      "make - and wear - them.  The underworld of Tharis is known "+
      "for making and selling such boots, as they often prove "+
      "profitable to those who are not worried about an assassin's "+
      "dagger in their backs.");
   set_property("lore difficulty",8);
   set_type("clothing");
   set_limbs(({"right foot","left foot"}));
   set_ac(1);
   set_weight(3);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
   if(random(4)){
      set_size(2);
   }else{
      set_size(random(3)+1);
   }
   set_value(8500);
}

int wearme(){
   if(!ETO->is_class("thief")){
      tell_object(ETO,"You can't begin to figure out the wrappings!");
      return 0;
   }
   if((int)ETO->query_class_level("thief") < 11) {
      tell_object(ETO,"You can't begin to figure out the wrappings!");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^BLACK%^You quickly bend down and "+
      "wrap the silk around your feet.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" bends down and "+
      "wraps "+ETO->QP+" feet in black silk.",ETO);
   ETO->add_skill_bonus("athletics",2);
   return 1;
}

int unwearme(){
   tell_object(ETO,"%^BOLD%^%^BLACK%^You unwrap the black silk from "+
      "your feet.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" unwraps the black "+
      "silk from "+ETO->QP+" feet.",ETO);
   ETO->remove_skill_bonus("athletics",2);
   return 1;
}
