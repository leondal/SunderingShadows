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
string str, FABRIC, STYLE, LENGTH, DESC1, DESC2, X;

void create()
{
   ::create();
}

void create_gown(object obj)
{
   val = random(500);
   j = random(sizeof(COLORS));
   str = COLORS[j];
   switch(val) {
      case 0..200:
         FABRIC = "satin";
         DESC1 = "The gown is made of light and airy satin that is silken"+
         " on the outside and shines slightly in the light.";
         obj->set_wear("The fine satin gown feels nice and light as you slip it on.");
         break;
      case 201..300:
         FABRIC = "suede";
         DESC1 = "The gown is made of a wonderful suede that is nice and"+
         " soft on the outside.";
         obj->set_wear("The suede gown feels wonderfully soft on the outside.");
         break;
      case 301..400:
         FABRIC = "velvet";
         DESC1 = "The gown is made of rich velvet that is incredibly soft"+
         " to the touch and a sheer pleasure to wear.";
         obj->set_wear("The velvet gown caresses your skin as you slip it on.");
         break;
      case 401..500:
         FABRIC = "silk";
         DESC1 = "The gown is made of expensive silk that flows beautifully"+
         " around its wearer, enveloping her in silken delight.";
         obj->set_wear("The silk gown feels simply divine against your skin.");
         break;
   }
   obj->set_name("gown");
   if(str == "aquamarine") {
      X = "An";
   }
   else {
      X = "A";
   }
   obj->set_short("%^RESET%^"+X+" "+str+" "+FABRIC+" gown");
   obj->set_id(({"dagger_clothing","gown",""+str+" gown",""+FABRIC+" gown",""+str+" "+FABRIC+" gown"}));
   obj->set_type("clothing");
   obj->set_limbs(({"torso"}));
   if(val < 50) val = 50;
   obj->set_value(val);
   obj->set_weight(5);
   switch(random(2)) {
      case 0:
         DESC2 = "It has been cut fashionably short, reaching to"+
         " just above the knees.";
         break; 
      case 1:
         DESC2 = "It is a long gown that the nobles more typically wear,"+
         " coming down to the ankles.";
         break; 
   }
   switch(random(2)) {
      case 0:
         obj->set_long("This gown is of fine quality and has been dyed a"+
         " "+str+" shade. "+DESC1+" "+DESC2+"");
         break;
      case 1:
         obj->set_long("This gown is of fine quality and has been dyed a"+
         " "+str+" shade. "+DESC1+" "+DESC2+" Around the neckline of the"+
         " gown polished moonstones have been added for a beautiful touch.");
         break;
   }
}
