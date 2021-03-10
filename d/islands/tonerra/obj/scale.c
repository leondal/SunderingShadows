//scale mail - random drop from the reptilian gargantua
//Circe 6/13/04

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit "/d/common/obj/armour/scale";

int is_metal() { return 0; }

void create(){
	::create();
	set_name("reptilian scale mail");
	set_id(({"armor","scale","reptilian scale mail","gargantua scale mail","hide","scale mail","mail"}));
      set_obvious_short("a suit of rocky scale mail");
	set_short("%^BOLD%^%^BLACK%^Hide of the Ga%^RESET%^r"+
         "%^BOLD%^%^BLACK%^gan%^RESET%^tu%^BOLD%^%^BLACK%^a%^RESET%^");
	set_long(
         "%^BOLD%^%^BLACK%^This suit of scale mail looks as though "+
         "it is made from hide, rather than metal scales.  It is "+
         "rocky and bumpy, and it seems to shift in color from "+
         "ebony through %^RESET%^%^GREEN%^mo%^BOLD%^%^BLACK%^tt"+
         "%^RESET%^%^GREEN%^led green %^BOLD%^%^BLACK%^with small "+
         "flakes of %^WHITE%^pure white %^BLACK%^as well.  The "+
         "scales are well-fitted and seem to be attached to the "+
         "hide of the creature itself.  The armor even has small "+
         "spines that run down the wearer's back, and the wearer's "+
         "feet are given extra protection by wide scales that fit "+
         "just over his boots.%^RESET%^");
      set_lore("This scale mail is made from the thick scales plating "+
         "the gigantic creatures known as reptilian gargantuas.  "+
         "Known for their fierce destruction in the jungles of "+
         "Tonerra, they are often hunted or driven away by the "+
         "natives when they stray too close to the village there.  "+
         "When such a kill is made, the hide is brought back to "+
         "the village and made into this stunning suit of scale mail.");
	set_property("enchantment",3+random(2));
      set_value(2430);
      set_wear((:TO,"wearme":));
      set_remove((:TO,"unwearme":));
}
	
int wearme(){
   tell_object(ETO,"%^GREEN%^You feel a fierce strength as you "+
      "wear the scale mail.");
   tell_room(EETO,"%^GREEN%^"+ETOQCN+" wears a suit of rocky scale "+
      "mail and looks fierce.",ETO);
   return 1;
}

int unwearme(){
   tell_object(ETO,"%^GREEN%^You feel strangely calm as you remove "+
      "the armor.");
   tell_room(EETO,"%^GREEN%^"+ETOQCN+" seems to calm as "+ETO->QS+" "+
      "removes the armor.",ETO);
   return 1;
}