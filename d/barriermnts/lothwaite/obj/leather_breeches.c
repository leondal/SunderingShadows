//Lothwaite clothing by Circe 12/11/04
#include <std.h>

inherit ARMOUR;

#define COLORS ({"%^RESET%^%^BLUE%^navy",\
"%^BOLD%^%^BLUE%^cobalt",\
"%^RESET%^%^CYAN%^azure",\
"%^BOLD%^%^CYAN%^sky blue",\
"%^RESET%^%^GREEN%^olive green",\
"%^BOLD%^%^GREEN%^pine green",\
"%^RESET%^%^RED%^maroon",\
"%^BOLD%^%^RED%^red",\
"%^RESET%^%^ORANGE%^russet brown",\
"%^YELLOW%^yellow",\
"%^BOLD%^%^BLACK%^charcoal gray",\
"%^RESET%^gray",\
"%^BOLD%^%^WHITE%^white"})

void create(){
   int i;
   string COLOR;
   ::create();
   i = random(sizeof(COLORS));
   COLOR = COLORS[i];
   set_name("leather breeches");
   set_id(({"breeches","leather breeches","pants"}));
   set_short(""+COLOR+" leather breeches%^RESET%^");
   set_long("These unassuming breeches are made of leather dyed a muted "+
      ""+COLOR+"%^RESET%^.  The leather is thick but supple, allowing movement "+
      "while offering protection from brambles and other inconveniences in "+
      "the woods and mountains.  The pants are made full at the ankles, and they "+
      "may be worn over boots or tucked into them.  A lacing front panel and "+
      "belt loops complete this simple pair of pants.");
   set_value(40);
   set_weight(3);
   set_type("clothing");
   set_limbs(({"left leg","right leg"}));
   set_size(3);
}