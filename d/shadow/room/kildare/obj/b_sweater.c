#include <std.h>
#include "../kildare.h"

#define COLORS ({"bright yellow","pale yellow","cream","ivory","ebony","cornflower blue",\
"pale blue","midnight blue","royal blue","rose","maroon","deep green","pale green",\
"aquamarine","red-orange","bright green","white","bright red","deep red","purple"})

inherit DAEMON;

int j, val;
string str, VAR;

void create()
{
   ::create();
}

void create_sweater(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   VAR = "a";
   if(str == "ivory" || str == "ebony" || str == "aquamarine") {
   VAR = "an";
   }
   val = random(20);
   switch(val) {
      case 0..4:
         obj->set_long("This heavy woolen sweater has been crafted "+
         "to combat even the coldest winters.  It is bulky and a "+
         "little uncomfortable, but will offer some amount of "+
         "comfort in the cold.  It is long-sleeved with a rounded "+
         "neckline and has been dyed "+VAR+" "+str+" color.");
         break;
      case 5..9:
         obj->set_long("Soft, fuzzy wool has been worked into a delicate, "+
         "v-neck sweater that has been dyed "+VAR+" "+str+" color.  It "+
         "seems quite stylish, yet comfortable - something one would probably "+
         "wear to dinner rather than out on the battlefield.");
         break;
      case 10..14:
         obj->set_long("The wool for this sweater has been dyed "+VAR+" "+str+" color.  "+
         "It opens in the front and can be buttoned closed with wooden toggles "+
         "painted to compliment the sweater's color.");
         break;
      case 15..19:
         obj->set_long("This sleeveless sweater is more like a vest, complete with "+
         "a v-neckline.  While it would not be as warm as some sweaters, it seems "+
         "quite nice and is normally worn with another shirt.  This one has been "+
         "dyed "+VAR+" "+str+" color.");
         break;
      }
   obj->set_value(45);
   obj->set_name("sweater");
   obj->set_type("clothing");
   obj->set_limbs(({"torso"}));
   obj->set_weight(5);
   obj->set_lore("This is a finely-tailored sweater made by Mariel "+
      "of Kildare Glen.  A small tag bearing her mark has been "+
      "sewn into it.");
   obj->set_property("lore difficulty",3);
   obj->set_short(""+VAR+" "+str+" woolen sweater");
   obj->set_id(({"sweater","woolen sweater","wool sweater",""+str+" sweater"}));
}
