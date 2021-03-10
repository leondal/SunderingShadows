//Octothorpe (9/6/08)
//Underdark Mining Caverns, Gnomish Scaled Chain Shirt +3

#include <std.h>
inherit "/d/common/obj/armour/schain.c";

void create(){
   ::create();
   set_name("scaled shirt");
   set_id(({"scaled mail","mail","shirt","armor","chain"}));
   set_short("%^RESET%^small shirt of %^BOLD%^%^BLACK%^s%^RESET%^c"+
      "%^BOLD%^%^BLACK%^a%^RESET%^l%^BOLD%^%^BLACK%^e%^RESET%^d mail"+
      "%^RESET%^");
   set_long("This mail shirt is made of a %^BOLD%^mithral%^RESET%^-"+
      "st%^BOLD%^ee%^RESET%^l alloy. The alloy lacks the characteristic "+
      "sheen of %^BOLD%^mithral%^RESET%^, yet retains its integrity and "+
      "light weight. Curiously, this mail shirt is a hybrid between "+
      "scale armor, and a typical mail shirt. %^BOLD%^Mithral %^RESET%^"+
      "scales have been attached to the mail shirt, providing a more "+
      "protective backing than the %^ORANGE%^leather %^RESET%^typically "+
      "found on scale armor.%^RESET%^");
   set_lore("This is the standard issue armor of svirfneblin mining "+
      "expeditions in the Underdark. Due to the hazardous environs, "+
      "normal procedure dictates that half of the party mines while "+
      "the other half watches guard over the mining. The guards wear "+
      "the mail shirts, whereas the miners strip down to leather "+
      "gambesons for comfort. This type of armor is known as lorica "+
      "plumata on the surface, and was a ceremonial armor for generals "+
      "and dignitaries in the ancient past.");
   set_property("lore",12);
   set_size(1);
   set_property("enchantment",3);
   set_value(1000+random(550));
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun(){
   if((int)ETO->query_lowest_level() < 15){
      tell_room(EETO,"%^BOLD%^"+ETOQCN+" has some difficulties putting "+
         "on the scaled shirt.%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^Putting on this scaled shirt seems "+
         "slightly more complicated that you originally thought. "+
         "Perhaps you need more training to figure it out.%^RESET%^");
      return 1;
   }
   tell_room(EETO,"%^BOLD%^The scales make a soothing, metallic "+
      "rustling sound as "+ETOQCN+" wears the armor.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^The scales make a soothing, metallic "+
      "rustling sound as you wear the scaled shirt.%^RESET%^");
   if((string)ETO->query_race() == "gnome") set_item_bonus("dexterity",1);
   else set_item_bonus("dexterity",0);
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^BOLD%^"+ETOQCN+" lightly rustles themselves "+
      "out of the scaled shirt.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^The scales rustle one last time as you "+
      "remove the shirt.%^RESET%^");
   return 1;
}
