//Lothwaite clothing by Circe 12/4/04
#include <std.h>

inherit ARMOUR;

#define COLORS ({"%^BLUE%^navy","%^BOLD%^%^BLUE%^cobalt","%^CYAN%^azure","%^BOLD%^%^CYAN%^sky blue","%^GREEN%^olive green","%^BOLD%^%^GREEN%^pine green","%^RED%^maroon","%^BOLD%^%^RED%^red","%^ORANGE%^russet brown","%^YELLOW%^yellow","%^BOLD%^%^BLACK%^charcoal gray","gray","%^BOLD%^%^WHITE%^white"})

void create(){
   int i;
   string COLOR;
   ::create();
   i = random(sizeof(COLORS));
   COLOR = COLORS[i];
   set_name("wool tunic");
   set_id(({"tunic","wool tunic","shirt"}));
   set_short(""+COLOR+" wool tunic%^RESET%^");
   set_long("This long woolen tunic reaches the knees and has been dyed "+
      ""+COLOR+"%^RESET%^.  The tunic features an open neck that can be "+
      "pulled closed with thin %^ORANGE%^leather thongs %^RESET%^that run "+
      "from the chest up to the collar.  The collar is short and has been "+
      "designed to fold over slightly, giving the shirt a relaxed appearance.  "+
      "The sleeves are long, reaching just past the wrist, and they may be "+
      "rolled up if need be.");
   set_value(25);
   set_weight(3);
   set_ac(1); //variety for regular robes
   set_type("clothing");
   set_limbs(({"torso"}));
   set_size(3);
}