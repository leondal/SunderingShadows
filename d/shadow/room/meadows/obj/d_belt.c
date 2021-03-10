#include <std.h>

#define COLORS ({"%^BOLD%^%^BLACK%^pitch black",\
"%^BOLD%^%^WHITE%^snow white",\
"%^BOLD%^%^RED%^cardinal red",\
"%^RESET%^%^RED%^blood red",\
"%^RESET%^%^ORANGE%^sunset orange",\
"%^RESET%^%^ORANGE%^walnut brown",\
"%^YELLOW%^goldenrod",\
"%^BOLD%^%^GREEN%^jade green",\
"%^RESET%^%^GREEN%^forest green",\
"%^BOLD%^%^BLUE%^cerulean blue",\
"%^RESET%^%^BLUE%^midnight blue",\
"%^RESET%^%^CYAN%^slate blue",\
"%^BOLD%^%^CYAN%^teal",\
"%^RESET%^%^MAGENTA%^violet",\
"%^BOLD%^%^MAGENTA%^bright pink",\
"%^BOLD%^%^BLACK%^charcoal gray",\
"%^BOLD%^%^GREEN%^emerald green",\
"%^BOLD%^%^BLUE%^sapphire blue",\
"%^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r",\
"%^ORANGE%^g%^BOLD%^o%^RESET%^%^ORANGE%^l%^BOLD%^d",\
"%^BOLD%^%^RED%^ruby red",\
"%^BOLD%^%^WHITE%^light cream",\
"%^BOLD%^%^BLACK%^raven black",\
"%^BOLD%^%^CYAN%^sky blue",\
"%^MAGENTA%^wine",\
"%^BOLD%^%^MAGENTA%^pale pink",\
"%^CYAN%^sea-green"})

inherit DAEMON;

int j, val;
string str, BUCKLE;

void create()
{
   ::create();
}

void create_belt(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   val = random(9);
   switch(val) {
      case 0:
         BUCKLE = "%^YELLOW%^brass%^RESET%^";
         break;
      case 2:
         BUCKLE = "%^ORANGE%^bronze%^RESET%^";
         break;
      case 3:
         BUCKLE = "%^CYAN%^steel%^RESET%^";
         break;
      case 4:
         BUCKLE = "%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r";
         break;
      case 5..6:
         BUCKLE = "%^BOLD%^%^WHITE%^m%^CYAN%^i%^WHITE%^thr%^CYAN%^i%^WHITE%^l%^RESET%^";
         break;
      case 7..8:
         BUCKLE = "%^YELLOW%^gold%^RESET%^";
         break;
   }
   obj->set_long("This is a finely crafted leather belt that has been dyed"+
   " a "+str+"%^RESET%^ color. It has a "+BUCKLE+" buckle.");
   obj->set_value(val+1);
   obj->set_name("belt");
   obj->set_type("ring");
   obj->set_limbs(({"waist"}));
   obj->set_wear("You buckle the "+str+" belt around your waist.");
   obj->set_remove("You unbuckle the belt and remove it.");
   obj->set_weight(1);
   obj->set_short("A "+str+"%^RESET%^ belt");
   obj->set_id(({"belt","leather belt"}));
}
