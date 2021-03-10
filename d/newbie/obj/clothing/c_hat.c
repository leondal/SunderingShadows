#include <std.h>
inherit ARMOUR;

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

int j, val;
string str, FABRIC;
void create_hat()
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   val = random(20);
   switch(val) {
      case 0..2:
         FABRIC = "straw";
         set_long("This is a light, wide-brimmed straw hat that has"+
         " been dyed a "+str+" shade. It is great for helping to keep"+
         " the sun out of your eyes, but tends to try and blow away if the"+
         " wind picks up.");
         break;
      case 3..5:
         FABRIC = "hemp";
         set_long("This is a pretty hemp hat that has been dyed a"+
         " "+str+" color. It has a bit of a brim to protect your eyes from"+
         " the sun.");
         break;
      case 6..8:
         FABRIC = "leather";
         set_long("This is a stylishly sleek leather hat that has been"+
         " dyed a "+str+" shade. It will look good on just about anyone.");
         break;
      case 9..11:
         FABRIC = "wool";
         set_long("This is warm wool hat that fits snuggly on your head"+
         " and can even be pulled down to cover your ears. It has been dyed"+
         " a "+str+" color and will undoubtedly help to keep you warm"+
         " in colder climates.");
         break;
      case 12..14:
         FABRIC = "felt";
         set_long("This felt hat has been dyed a "+str+" shade"+
         " and is rather fashionable.");
         break;
      case 15..17:
         FABRIC = "suede";
         set_long("This suede hat is quite nice and is designed in the"+
         " latest of styles and has been dyed a "+str+" shade.");
         break;
      case 18..19:
         FABRIC = "velvet";
         set_long("The velvet hat is very pretty indeed, having been"+
         " dyed a "+str+" shade. It is not terribly practical if the"+
         " weather were bad, but it looks great.");
         break;
   }
   set_value(val);
   if(val < 2) {
      set_value(2);
   }
   set_cointype("silver");
   set_name("hat");
   set_type("clothing");
   set_limbs(({"head"}));
   set_weight(2);
   set_short("A "+str+" "+FABRIC+" hat");
   set_id(({"hat","clothing",""+str+" hat",""+FABRIC+" hat",""+str+" "+FABRIC+" hat"}));
}


void create()
{
   ::create();
   create_hat();  
   set_size(random(3)+1);
}
