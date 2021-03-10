//updated by Circe with new desc, lore, etc. 6/11/04
#include <std.h>;

inherit ARMOUR;

#define COLORS ({"%^BOLD%^%^WHITE%^white dragon",\
"%^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^d dragon",\
"%^RESET%^%^GREEN%^g%^RESET%^%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^e%^BOLD%^n dragon",\
"%^BOLD%^%^BLACK%^black dragon",\
"%^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^l%^BOLD%^u%^RESET%^%^BLUE%^e%^BOLD%^ dragon",\
"%^RESET%^%^ORANGE%^copper dragon",\
"%^YELLOW%^brass dragon",\
"%^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^l%^RESET%^%^ORANGE%^d%^BOLD%^ dragon",\
"%^YELLOW%^b%^RESET%^%^ORANGE%^r%^YELLOW%^on%^RESET%^%^ORANGE%^z%^YELLOW%^e dragon",\
"%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r%^BOLD%^ dragon"})


void create(){
      int j;
	string str, COLOR;
	::create();
      j = random(sizeof(COLORS));
      COLOR = COLORS[j];
   	set_name("dragonskin cloak");
   	set_id(({"cloak","dragonskin","dragonskin cloak","hide","hide cloak","rough hide cloak"}));
   	set_obvious_short("%^RESET%^%^MAGENTA%^A rough hide cloak%^RESET%^");
   	set_short("%^RESET%^%^MAGENTA%^A "+COLOR+"skin %^RESET%^%^MAGENTA%^cloak%^RESET%^");
   	set_long("%^MAGENTA%^This unusual cloak is made from thick hide "+
      	"that is somewhat rough on the outside. Inside, it has been "+
      	"lined with soft, padded silk dyed to match the "+COLOR+"%^RESET%^"+
		"%^MAGENTA%^ hide. It looks as though this cloak might offer some "+
      	"manner of protection as well as being rather stylish.  "+
		"The cloak is made to drape all the way around "+
      	"the wearer's body and reaches the floor, closing with three "+
      	"small %^CYAN%^steel%^MAGENTA%^ clasps fashioned to look like"+
		" "+COLOR+"s%^RESET%^%^MAGENTA%^. The first is just at the "+
      	"throat, while the other fasten all the way down the chest.%^RESET%^");
   	set_lore("Made from the hide of a young dragon, this cloak "+
      	"is unusual at best! Dragon hide can offer some of the best "+
      	"protection available, though it gets stronger as the dragon "+
      	"ages - and this was clearly a juvenile, judging from the "+
      	"lighter color. Of course, getting such skin can be "+
      	"rather hazardous to one's health in itself!");
   	set_weight(5);
   	set_limbs(({"neck"}));
   	set_type("clothing");
	set_size(random(3)+1);
   	set_value(400);
   	set_ac(0);
   	set_property("enchantment",2);
	set_wear((: TO,"wear_func" :));
   	set_remove((: TO,"remove_func" :));
	
}
int wear_func(){
      	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" pulls the hide cloak"+
	  		" around "+ETO->QP+" shoulders.",ETO);
        	tell_object(ETO,"%^MAGENTA%^You pull the hide cloak around your"+
			" shoulders, clasping it in place.");
        			return 1;
}
int remove_func(){
	  tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" unclasps "+ETO->QP+" "+
			"cloak and pulls it off.",ETO);
        tell_object(ETO,"%^MAGENTA%^You unclasp the cloak and pull it off.");
        			return 1;
}
