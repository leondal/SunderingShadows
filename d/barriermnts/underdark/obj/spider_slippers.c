//boots for drow.  Circe 2/13/05
#include <std.h>
inherit ARMOUR;

int FLAG;

void create(){
   ::create();
   set_id(({"slippers","spider slippers","gray slippers","silk slippers"}));
   set_name("silk slippers");
   set_obvious_short("%^BOLD%^%^BLACK%^gray silk slippers%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Spider Slippers%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^These soft slippers are made of thick "+
      "gray silk that curves smoothly over the toes of the wearer.  "+
      "Rather simple in design, the shoe offers no ornamentation "+
      "save its own shimmering gray color.  Silk ribbons made of "+
      "the same fabric rise from the back of the slippers and can "+
      "be wound around the wearer's ankles and tied.%^RESET%^");
   set_weight(2);
   set_property("enchantment",random(2));
   set_value(350);
   set_lore("These slippers are not fashioned from any ordinary "+
      "silk.  They are actually made from the silk of driders!  "+
      "The deep gray color is common only to drider silk, and "+
      "the smooth texture further confirms this.  While offering "+
      "no particulary unique or exemplary qualities of its own, "+
      "drider silk is nonetheless favored by drow priestesses, who "+
      "wear such slippers as a mark of pride.");
   set_type("clothing");
   set_limbs(({"right foot","left foot"}));
   set_property("lore difficulty",11);
   set_wear((:TO,"wear_me":));
   set_remove((:TO,"unwear_me":));
   if(random(4)){
      FLAG = 0;
   }else{
      FLAG = 1;
   }
}

int wear_me(){
   string myrace = ETO->query_race();
   if(myrace != "drow" && myrace != "half-drow"){
      tell_object(ETO,"You cannot seem to lace the slippers.");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^BLACK%^You lace the silken ribbons "+
      "around your ankles.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" laces the silken "+
      "ribbons around "+ETO->QP+" ankles.",ETO);
   if(FLAG){
      ETO->add_stat_bonus("dexterity",1);
   }
   return 1;
}

int unwear_me(){
   tell_object(ETO,"%^BOLD%^%^BLACK%^You reluctantly slip out of the "+
      "exquisite shoes.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" removes the exquisite "+
      "shoes.",ETO);
   if(FLAG){
      ETO->add_stat_bonus("dexterity",-1);
   }
   return 1;
}
