#include <std.h>

#define COLORS ({"%^YELLOW%^lion%^RESET%^",\
"%^RESET%^%^ORANGE%^ch%^BOLD%^%^BLACK%^ee%^RESET%^%^ORANGE%^tah%^RESET%^",\
"%^YELLOW%^le%^BLACK%^o%^YELLOW%^p%^BLACK%^a%^YELLOW%^rd%^RESET%^"})

inherit DAEMON;

int j, val;
string str;

void create()
{
   ::create();
}

void create_skin(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   val = random(10);
   switch(val) {
      case 0..2:
         obj->set_name(""+str+" belt");
         obj->set_short("A "+str+" skin belt");
         obj->set_id(({"animalskin","belt",""+str+" skin belt",""+str+" belt"}));
         obj->set_weight(1);
		obj->set_type("ring");
         obj->set_limbs(({"waist"}));
         obj->set_long("This is a belt made from the skin of a "+str+". It"+
         " is of fine quality and seems fairly durable.");
         break;
      case 3..6:
         obj->set_name(""+str+" boots");
         obj->set_short("A pair of "+str+" skin boots");
         obj->set_id(({"animalskin","boots","pair of boots",""+str+" skin boots","pair of "+str+" skin boots",""+str+" boots"}));
		obj->set_type("clothing");
         	obj->set_weight(2);
         	obj->set_limbs(({"left foot","right foot"}));
         	obj->set_long("This is a pair of "+str+" skin boots. The fur is"+
         	" on the outside with a reinforced leather sole. The boots come up"+
         	" to just above the ankle.");
         break;
      case 7..10:
         	obj->set_name(""+str+" tunic");
         	obj->set_short("A "+str+" skin tunic");
         	obj->set_id(({"animalskin","tunic",""+str+" tunic",""+str+" skin tunic"}));
         	obj->set_weight(3);
         	obj->set_type("clothing");
		obj->set_limbs(({"torso"}));
	   	obj->set_ac(1);
         	obj->set_long("The "+str+" skin tunic is excellently made and has"+
         		" been sewn onto a piece of supple leather for extra strength. It"+
         		" looks like it might provide the wearer with a bit of protection.");
         break;
   }
   obj->set_value(val+1);
}
