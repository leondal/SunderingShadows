//updated by Circe 9/7/04 with new desc
#include <std.h>;
inherit "/std/armour";

#define FABRICS ({"cotton","linen","wool","silk","suede"})
#define COLORS ({"%^BOLD%^white","%^RESET%^%^ORANGE%^brown","%^RESET%^%^ORANGE%^t%^YELLOW%^a%^RESET%^%^ORANGE%^n","%^BOLD%^%^BLUE%^blue","%^RESET%^%^BLUE%^navy","%^GREEN%^green","gray","%^RED%^red","%^RESET%^%^ORANGE%^orange","%^BOLD%^%^BLACK%^black"})

void create(){
   int i,j;
   string FABRIC, COLOR;
   ::create();
   i = random(sizeof(FABRICS));
   FABRIC = FABRICS[i];
   j = random(sizeof(COLORS));
   COLOR = COLORS[j];
   set_name("tunic");
   set_id(({"tunic","shirt","tharis tunic"}));
   set_short("a "+COLOR+" "+FABRIC+" tunic%^RESET%^");
   set_long("This fashionable tunic is made of "+COLOR+" "+FABRIC+".  "+
      "%^RESET%^The shirt is classic in design and falls to just below the "+
      "wearer's hips, allowing it to be cinched with a belt if "+
      "desired.  The tunic is long-sleeved and features light "+
      "embroidery along the neck that runs down the front alongside "+
      "the matching buttons.");
   set_type("clothing");
   set_limbs(({"torso"}));
   set_weight(3);
   set_size(random(3)+1);
   set_value(10);
}
