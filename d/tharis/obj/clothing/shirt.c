//updated by Circe 9/7/04 with new desc
#include <std.h>;
inherit "/std/armour";

#define FABRICS ({"cotton","linen","silk"})
#define COLORS ({"%^BOLD%^%^BLACK%^black","%^BOLD%^%^BLACK%^du%^RESET%^sk%^BOLD%^%^BLACK%^y gray","%^RESET%^%^BLUE%^midnight blue"})

void create(){
   int i,j;
   string FABRIC, COLOR;
   ::create();
   i = random(sizeof(FABRICS));
   FABRIC = FABRICS[i];
   j = random(sizeof(COLORS));
   COLOR = COLORS[j];
   set_name("shirt");
   set_id(({"shirt"}));
   set_short("a "+COLOR+" "+FABRIC+" shirt%^RESET%^");
   set_long("This well-made shirt is rather simple in design, made "+
      "for comfort and ease of movement rather than an ostentatious "+
      "display of wealth.  Still, the "+FABRIC+" is very high quality, "+
      "and the design is flawless.  It has been dyed "+COLOR+"%^RESET%^, "+
      "a color which would probably allow one to blend into a crowd while "+
      "still looking tasteful.");
   set_type("clothing");
   set_limbs(({"torso"}));
   set_weight(3);
   set_size(2);
   set_value(15);
}
