#include <std.h>

#define COLORS ({"%^BOLD%^%^WHITE%^white%^RESET%^","%^BOLD%^%^BLACK%^black%^RESET%^","%^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^a%^RESET%^y","%^RESET%^%^ORANGE%^brown%^RESET%^"})

inherit DAEMON;

int j, val;
string str;

void create()
{
   ::create();
}

void create_rabbit(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   val = random(10);
   obj->set_type("clothing");
   switch(val) {
      case 0..2:
         obj->set_name("rabbit skin belt");
         obj->set_short(capitalize(str)+" rabbit skin belt");
         obj->set_id(({"rabbitskin","belt",""+str+" rabbit skin belt",""+str+" belt","rabbit skin belt"}));
         obj->set_weight(1);
         obj->set_limbs(({"waist"}));
		obj->set_type("ring");
         obj->set_long("This is a belt made from soft pelt of a "+str+" rabbit.");
         break;
      case 3..4:
         obj->set_name(""+str+" hat");
         obj->set_short("A "+str+" rabbit skin hat");
         obj->set_id(({"rabbitskin","hat","rabbit skin hat",""+str+" rabbit skin hat",""+str+" hat"}));
         obj->set_weight(1);
         obj->set_limbs(({"head"}));
         obj->set_long("This hat has been made from the soft pelt of a"+
         " "+str+" rabbit. The fur is on the inside with a section that"+
         " turns up. The outside of the hat is very soft leather that has"+
         " been dyed to match the fur. This hat will obviously keep you"+
         " quite warm.");
         break;
      case 5..7:
         obj->set_name("rabbit skin boots");
         obj->set_short(capitalize(str)+" rabbit skin boots");
         obj->set_id(({"rabbitskin","boots","pair of boots",""+str+" rabbit skin boots","pair of "+str+" rabbit skin boots",""+str+" boots"}));
         obj->set_weight(2);
         obj->set_limbs(({"left foot","right foot"}));
         obj->set_long("These boots are made from the soft pelt of a "+str+""+
         " rabbit. The fur is on the inside with a collar that turns down"+
         " just above the ankles to show off the pelt. They are comfortable"+
         " and warm, if not the most durable.");
         break;
      case 8..10:
         obj->set_name("rabbit skin gloves");
         obj->set_short(capitalize(str)+" rabbit skin gloves");
         obj->set_id(({"rabbitskin","gloves",""+str+" gloves",""+str+" rabbit skin gloves","rabbit skin gloves"}));
         obj->set_weight(1);
         obj->set_limbs(({"left arm","right arm"}));
         obj->set_long("This is a pair of soft rabbit skin gloves. The skin"+
         " has been dyed "+str+" to match the pelt, which is turned down at"+
         " the cuff. The gloves are warm and very flexible.");
         break;
   }
   obj->set_value(val+1);
}
