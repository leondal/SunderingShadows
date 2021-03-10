//Lothwaite clothing by Circe 12/4/04
#include <std.h>

inherit ARMOUR;

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

void create(){
   string COLOR;
   ::create();
   COLOR = COLORS[random(sizeof(COLORS))];
   set_name("silk shirt");
   set_id(({"shirt","silk shirt"}));
   set_short(""+COLOR+" silk shirt%^RESET%^");
   set_property("repairtype",({ "tailor" }));
   set_long("Created from "+COLOR+" silk%^RESET%^, this shirt is "+
      "simple and elegant in design.  It has a tall collar that "+
      "folds down to sharp points.  The top of the shirt can be "+
      "buttoned for a more formal look or left open for comfort.  "+
      "Buttons made of %^BOLD%^mo%^RESET%^t%^BOLD%^he%^MAGENTA%^r"+
      "%^WHITE%^-of-p%^CYAN%^e%^WHITE%^arl%^RESET%^ run "+
      "down the front of the shirt, but the cuffs have been left "+
      "open for cufflinks of the wearer's choosing.  The long "+
      "sleeves are tapered close to the arms, ending in flared "+
      "cuffs.");
   set_value(100);
   set_weight(1);
   set_type("ring");
   set_limbs(({"torso"}));
}
