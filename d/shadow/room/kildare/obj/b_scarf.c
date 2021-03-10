#include <std.h>
#include "../kildare.h"

#define COLORS ({"blue","green","yellow","red","orange","tan","gray","purple"})
#define SHADES ({"light","dark","deep","pale"})

inherit DAEMON;

int j, k, val;
string str, TYPE;

void create()
{
   ::create();
}

void create_scarf(object obj)
{
   j = random(sizeof(COLORS));
       str = COLORS[j];
   k = random(sizeof(SHADES));
       TYPE = SHADES[k];
   val = random(15);
   switch(val) {
      case 0..4:
         obj->set_long("This long woolen scarf has been dyed a "+TYPE+" "+str+" "+
         "color.  The material is tightly knit and well-made, and the scarf seems "+
         "as though it would keep your neck quite warm.  Small tassles have been "+
         "tied into the ends, giving this plain scarf a bit of decoration.");
         break;
      case 5..9:
         obj->set_long("This woolen scarf is primarily "+TYPE+" "+str+" in color, "+
         "though it alternates with lighter and darker monochromatic stripes.  It "+
         "is very well-made and would certainly keep you warm, and the striped "+
         "pattern makes it rather eye-catching.");
         break;
      case 10..14:
         obj->set_long("This hand-knit scarf has been crafted from soft wool "+
         "dyed a "+TYPE+" "+str+" color.  Running throughout the long scarf "+
         "is an interesting plaid design in lighter and darker shades.  The "+
         "soft texture of the wool would make it comfortable, while the thickness "+
         "assures its warmth.");
         break;
      }
   obj->set_value(35);
   obj->set_name("scarf");
obj->set_type("ring");
   obj->set_limbs(({"neck"}));
   obj->set_weight(3);
   obj->set_lore("This is a finely-tailored scarf made by Mariel "+
      "of Kildare Glen.  A small tag bearing her mark has been "+
      "sewn into it.");
   obj->set_property("lore difficulty",3);
   obj->set_short("A "+TYPE+" "+str+" woolen scarf");
   obj->set_id(({"scarf","woolen scarf","wool scarf",""+str+" scarf"}));
   obj->set_ac(0);
   obj->set_size(2);
}
