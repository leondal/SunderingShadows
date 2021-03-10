#include <std.h>

#define COLORS ({"%^ORANGE%^brown%^RESET%^",\
"%^BOLD%^%^BLACK%^black%^RESET%^",\
"%^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^a%^RESET%^y%^RESET%^",\
"%^BOLD%^%^WHITE%^white%^RESET%^",\
"%^ORANGE%^t%^YELLOW%^a%^RESET%^%^ORANGE%^n%^RESET%^",\
"%^RESET%^light gray",\
"%^BOLD%^%^BLACK%^dark gray%^RESET%^",\
"%^YELLOW%^camel%^RESET%^"})

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
         STYLE = "soft";
         obj->set_long("These are a pair of "+str+" boots made from very"+
         " soft leather. They are meant for walking and look quite"+
         " comfortable. They only reach to about the ankle and they slip"+
         " on easily enough.");
         obj->set_wear("The soft boots feel very comfortable as you slip them on.");
         obj->set_remove("You slip the soft boots off your feet.");
         break;
      case 6..7:
         STYLE = "suede";
         obj->set_long("These are a pair of lovely suede boots. They are"+
         " very soft and have been dyed a "+str+" color. They reach up"+
          " to the tops of your calves and they have a one inch heel. They"+
         " are quite stylish.");
         obj->set_wear("You pull on the suede boots.");
         obj->set_remove("You pull the suede boots off your feet.");
         break;
   }
   obj->set_name("boots");
   obj->set_short("A pair of "+str+" "+STYLE+" boots");
   obj->set_id(({"boots","leather boots","pair of boots",""+str+" boots",""+str+" leather boots","pair of "+str+" boots",""+STYLE+" boots",""+str+" "+STYLE+" boots","dagger_clothing","d_boots"}));
   obj->set_type("clothing");
   obj->set_limbs(({"right foot","left foot"}));
   obj->set_value(val+5);
   obj->set_weight(1);
}
