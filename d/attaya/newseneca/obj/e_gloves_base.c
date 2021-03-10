//adapted from Offestry for new Seneca
//~Circe~ 11/25/07
#include <std.h>

#define COLORS ({"%^BOLD%^%^BLACK%^black%^RESET%^",\
"%^RESET%^%^ORANGE%^brown%^RESET%^",\
"%^BOLD%^%^WHITE%^white%^RESET%^",\
"%^BOLD%^%^WHITE%^cream%^RESET%^",\
"%^YELLOW%^tan%^RESET%^",\
"%^BOLD%^%^RED%^red%^RESET%^",\
"%^BOLD%^%^GREEN%^green%^RESET%^",\
"%^BOLD%^%^BLUE%^blue%^RESET%^",\
"%^RESET%^%^MAGENTA%^purple%^RESET%^",\
"%^RESET%^%^CYAN%^blue-green%^RESET%^",\
"%^BOLD%^%^BLACK%^charcoal gray%^RESET%^"})

inherit DAEMON;

int j, val;
string str, FABRIC;

void create_gloves(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   val = random(10)+1;
   switch(val) {
      case 0..2:
         FABRIC = "cotton";
         obj->set_long("This is a pair of light cotton gloves that have "+
         "been dyed a "+str+" shade. They are thin and light, most likely "+
         "meant more for appearance than actually keeping your hands warm.");
         obj->set_wear("The cotton gloves are light and cool against"+
         " your hands.");
         break;
      case 3..8:
         FABRIC = "leather";
         obj->set_long("These leather gloves are in excellent shape.  "+
         "They have been lined with cotton padding for comfort and "+
         "the exterior has been dyed a "+str+" shade.  They would be "+
         "excellent for riding or any activity where you might wish "+
         "to protect your hands a little.");
         obj->set_wear("You slip the leather gloves over your hands.");
         break;
      default:
         FABRIC = "woolen";
         obj->set_long("These woolen gloves are very soft and fuzzy.  "+
         "They will at least keep your hands warm in colder weather, "+
         "though they likely wouldn't offer any protection from the "+
         "elements.  They have been dyed a rich "+str+" shade.");
         obj->set_wear("Your hands feel warmer as you place them in"+
         " the woolen gloves.");
         break;
   }
   obj->set_value(val*5);
   obj->set_name("gloves");
   obj->set_type("clothing");
   obj->set_limbs(({"left arm","right arm"}));
   obj->set_weight(2);
   obj->set_short("A pair of "+str+" "+FABRIC+" gloves");
   obj->set_id(({"gloves","clothing",""+str+" gloves",""+FABRIC+" gloves",""+str+" "+FABRIC+" gloves","pair of gloves","pair of "+str+" "+FABRIC+" gloves","pair of "+str+" gloves","pair of "+FABRIC+" gloves","regular gloves","esteban_clothing"}));
}
