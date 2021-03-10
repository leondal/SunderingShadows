#include <std.h>

#define COLORS ({"%^BOLD%^%^BLACK%^jet black%^RESET%^",\
"%^BOLD%^%^WHITE%^brilliant white%^RESET%^",\
"%^BOLD%^%^RED%^crimson red%^RESET%^",\
"%^RESET%^%^RED%^scarlet red%^RESET%^",\
"%^RESET%^%^ORANGE%^bright orange%^RESET%^",\
"%^RESET%^%^ORANGE%^walnut brown%^RESET%^",\
"%^YELLOW%^sunshine yellow%^RESET%^",\
"%^BOLD%^%^GREEN%^emerald green%^RESET%^",\
"%^RESET%^%^GREEN%^forest green%^RESET%^",\
"%^BOLD%^%^BLUE%^sapphire blue%^RESET%^",\
"%^BOLD%^%^BLUE%^cobalt blue%^RESET%^",\
"%^RESET%^%^BLUE%^midnight blue%^RESET%^",\
"%^RESET%^%^CYAN%^slate blue%^RESET%^",\
"%^BOLD%^%^CYAN%^aquamarine blue%^RESET%^",\
"%^RESET%^%^MAGENTA%^deep purple%^RESET%^",\
"%^MAGENTA%^plum%^RESET%^",\
"%^BOLD%^%^MAGENTA%^bright pink%^RESET%^",\
"%^BOLD%^%^BLACK%^stormy gray%^RESET%^",\
"%^BOLD%^%^CYAN%^sky blue%^RESET%^",\
"%^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r%^RESET%^",\
"%^ORANGE%^g%^BOLD%^o%^RESET%^%^ORANGE%^l%^BOLD%^d%^RESET%^",\
"%^BOLD%^%^RED%^ruby red%^RESET%^",\
"%^BOLD%^%^WHITE%^light cream%^RESET%^",\
"%^BOLD%^%^BLACK%^raven black%^RESET%^",\
"%^MAGENTA%^wine%^RESET%^",\
"%^BOLD%^%^MAGENTA%^deep pink%^RESET%^",\
"%^CYAN%^sea green%^RESET%^"})

inherit DAEMON;

int i, j, val;
string str, FABRIC, STYLE, DESC1, X;

void create()
{
   ::create();
}

void create_vest(object obj)
{
   val = random(500);
   j = random(sizeof(COLORS));
   str = COLORS[j];
   switch(val) {
      case 0..200:
         FABRIC = "satin";
         DESC1 = "The vest is made of some very soft leather, the outside"+
         " of which has been covered with satin that is smooth to the"+
         " touch and shines in the light.";
         break;
      case 201..300:
         FABRIC = "suede";
         DESC1 = "The vest is made of sturdy suede that is soft on the"+
         " outside. It looks great and is also quite durable.";
         break;
      case 301..400:
         FABRIC = "velvet";
         DESC1 = "The vest is made of rich velvet that is incredibly soft"+
         " to the touch. The inside of the vest is lined with a thin layer"+
         " of leather that has been perfectly dyed to match the velvet"+
         " exterior.";
         break;
      case 401..500:
         FABRIC = "silk";
         DESC1 = "The vest is made entirely of expensive silk that is very"+
         " light. The silk feels wonderful and looks magnificent, but"+
         " you realize the vest would not last long under harsh conditions.";
         break;
   }
   obj->set_name("vest");
   if(str == "aquamarine") {
      X = "An";
   }
   else {
      X = "A";
   }
   obj->set_short("%^RESET%^"+X+" "+str+" "+FABRIC+" vest");
   obj->set_id(({"dagger_clothing","vest",""+str+" vest",""+FABRIC+" vest",""+str+" "+FABRIC+" vest"}));
   obj->set_type("ring");
   obj->set_limbs(({"torso"}));
   if(val < 50) val = 50;
   obj->set_value(val);
   obj->set_weight(1);
   switch(random(2)) {
      case 0:
         obj->set_long("This vest is of fine quality and has been dyed a"+
         " "+str+" shade. "+DESC1+" The vest buttons up the front.");
         obj->set_wear("You slip the vest on and button up the front.");
         obj->set_remove("You unbutton the vest and slip out of it.");
         break;
      case 1:
         obj->set_long("This vest is of fine quality and has been dyed a"+
         " "+str+" shade. "+DESC1+" You notice that the buttons of the vest"+
         " are actually polished moonstones.");
         obj->set_wear("You fasten the moonstone buttons of the vest.");
         obj->set_remove("You undo the moonstone buttons and slip out of the vest.");
         break;
   }
}
