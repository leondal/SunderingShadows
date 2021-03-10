//Lothwaite clothing by Circe 12/11/04
#include <std.h>

inherit ARMOUR;

#define COLORS ({"%^BLUE%^navy","%^BOLD%^%^BLUE%^cobalt","%^CYAN%^azure","%^BOLD%^%^CYAN%^sky blue","%^GREEN%^olive green","%^BOLD%^%^GREEN%^pine green","%^RED%^maroon","%^BOLD%^%^RED%^red","%^ORANGE%^russet brown","%^YELLOW%^yellow","%^BOLD%^%^BLACK%^charcoal gray","gray","%^BOLD%^%^WHITE%^white"})

void create(){
   int i;
   string COLOR;
   ::create();
   i = random(sizeof(COLORS));
   COLOR = COLORS[i];
   set_name("fleece vest");
   set_id(({"vest","fleece vest"}));
   set_short(""+COLOR+" fleece vest%^RESET%^");
   set_long("This fleece vest has been dyed "+COLOR+"%^RESET%^.  The "+
      "vest is sleeveless and has been edged with light %^ORANGE%^"+
      "tan leather%^RESET%^, giving it a bit of definition.  It may "+
      "be left open, or drawn closed over a thinner shirt by a series of "+
      "%^ORANGE%^wooden toggles%^RESET%^.");
   set_value(15);
   set_weight(3);
   set_type("ring");
   set_limbs(({"torso"}));
   set_size(3);
}