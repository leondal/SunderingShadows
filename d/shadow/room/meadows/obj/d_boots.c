#include <std.h>

#define COLORS ({"brown","black","gray","white","tan"})

inherit DAEMON;

int j, val;
string str, STYLE;

void create()
{
   ::create();
}

void create_boots(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   val = random(8);
   switch(val) {
      case 0..3:
         STYLE = "riding";
         obj->set_long("These are a pair of tough leather riding boots that"+
         " have been dyed a "+str+" color. They are not very flexible, but"+
         " they come up to the mid-calf and can help protect you while"+
         " riding.");
         obj->set_wear("You slip your feet into the riding boots.");
         obj->set_remove("You remove the stiff riding boots.");
         break;
      case 4..5:
         STYLE = "antelope hide";
         obj->set_long("These are a pair of "+str+" boots made from antelope"+
         " hide. They are flexible as well as somewhat durable and they"+
         " lace all the way up to the knee.");
         obj->set_wear("You lace up the antelope hide boots.");
         obj->set_remove("You unlace the antelope hide boots and slip them off your feet.");
         break;
      case 6..7:
         STYLE = "sheepskin";
         obj->set_long("These are a pair of lovely sheepskin boots. They are"+
         " very soft and have been dyed a "+str+" color. They only reach to"+
         " just past the ankle and probably wouldn't protect you from much,"+
         " but they are comfortable for walking and they look nice.");
         obj->set_wear("You slip into the soft sheepskin boots.");
         obj->set_remove("You reluctantly remove the comfortable boots.");
         break;
   }
   obj->set_name("boots");
   obj->set_short("A pair of "+str+" "+STYLE+" boots");
   obj->set_id(({"boots","leather boots","pair of boots",""+str+" boots",""+str+" leather boots","pair of "+str+" boots",""+STYLE+" boots",""+str+" "+STYLE+" boots"}));
   obj->set_type("clothing");
   obj->set_limbs(({"right foot","left foot"}));
   obj->set_value(val+1);
   obj->set_weight(1);
}
