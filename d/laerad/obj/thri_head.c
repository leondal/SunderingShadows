//Octothorpe (10/17/09)
//Laerad, Thri-kreen Head Helmet

#include <std.h>
inherit "/d/common/obj/armour/helm.c";

void create(){
   ::create();
   set_name("thri-kreen helm");
   set_id(({"head","helmet","thri-kreen head","helm","insectoid","insectoid head"}));
   set_short("%^RESET%^%^ORANGE%^thr%^YELLOW%^i%^RESET%^%^ORANGE%^-kr"+
      "%^YELLOW%^ee%^RESET%^%^ORANGE%^n h%^YELLOW%^e%^ORANGE%^lm%^RESET%^");
   set_obvious_short("%^YELLOW%^i%^RESET%^%^ORANGE%^ns%^YELLOW%^e"+
      "%^RESET%^%^ORANGE%^ct%^YELLOW%^oi%^RESET%^%^ORANGE%^d h%^YELLOW%^"+
          "e%^RESET%^%^ORANGE%^lm%^RESET%^");
   set_long("%^YELLOW%^This helm is nothing more than the severed head "+
      "of an insectoid %^RESET%^%^ORANGE%^thr%^YELLOW%^i%^RESET%^"+
	  "%^ORANGE%^-kr%^YELLOW%^ee%^RESET%^%^ORANGE%^n%^YELLOW%^. The "+
	  "chitinous head is colored in a light, sandy hue. Two spindly "+
	  "antennae protrude out from the forehead of the head. Below the "+
	  "antennae, two %^BOLD%^%^BLACK%^c%^RESET%^o%^BOLD%^%^BLACK%^mp"+
	  "%^RESET%^ou%^BOLD%^%^BLACK%^nd %^RESET%^%^YELLOW%^eyes provide "+
	  "a wide field of view, for its former owner at least. There is "+
	  "a gap in between the mandibles to provide air flow to the "+
	  "wearer.%^RESET%^");
   set_size(2);
   set_property("enchantment",3);
   set_item_bonus("charisma",-2);
   set_item_bonus("dexterity",2);
   set_value(400+random(150));
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun(){
   if((int)ETO->query_lowest_level() < 15){
      tell_room(EETO,"%^BOLD%^"+ETOQCN+" has trouble fitting into the "+
	     "%^RESET%^%^ORANGE%^thr%^YELLOW%^i%^RESET%^%^ORANGE%^-kr"+
		 "%^YELLOW%^ee%^RESET%^%^ORANGE%^n%^YELLOW%^ %^BOLD%^%^WHITE%^"+
		 "head.%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^You are unable to fit your head into the "+
	     "helm properly.%^RESET%^");
      return 0;
   }
   tell_room(EETO,"%^YELLOW%^"+ETOQCN+" dons the %^RESET%^"+
      "%^ORANGE%^thr%^YELLOW%^i%^RESET%^%^ORANGE%^-kr%^YELLOW%^ee"+
	  "%^RESET%^%^ORANGE%^n%^YELLOW%^ head, and the antennae on the head "+
	  "twitch slightly.%^RESET%^",ETO);
   tell_object(ETO,"%^YELLOW%^As you don the helm, your field of view "+
      "is increased greatly by the %^BOLD%^%^BLACK%^c%^RESET%^o%^BOLD%^"+
	  "%^BLACK%^mp%^RESET%^ou%^BOLD%^%^BLACK%^nd %^YELLOW%^eyes.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^YELLOW%^"+ETOQCN+" pulls the insectoid helm off "+
      ""+ETO->QP+" head with a deep breath.%^RESET%^",ETO);
   tell_object(ETO,"%^YELLOW%^You are glad to finally be free of the "+
      "confined %^RESET%^%^ORANGE%^thr%^YELLOW%^i%^RESET%^%^ORANGE%^-kr"+
	  "%^YELLOW%^ee%^RESET%^%^ORANGE%^n%^YELLOW%^ head.%^RESET%^");
   return 1;
}
//non-metal from description while what it inherits is metal - fixing - Saide
int is_metal(){ return 0; }