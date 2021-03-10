#include <std.h>
inherit OBJECT;

#define GEMS ({"topaz","moonstone","quartz","amethyst","amber","agate","aquamarine","tiger's eye","garnet","onyx","malachite","citrine","bloodstone","tourmaline","citrine","carnelian","hematite"})

void create()
{
   int i, j, val;
   string str;

   ::create();
   j = random(17);
   str = GEMS[j];
   val = random(150);
   switch(val) {
      case 0..40:
         set_long("This is a tiny "+str+". The light catches in the gem and it"+
         " looks like it would sell for a bit of money.");
         set_short("A tiny "+str+"");
         set_weight(1);
         break;
      case 41..80:
         set_long("This is a small "+str+". The light catches in the gem and it"+
         " looks like it would sell for a fair price.");
         set_short("A small "+str+"");
         set_weight(2);
         break;
      case 81..100:
         set_long("This is a polished "+str+". The light reflects off the gem"+
         " beautiful and you could probably get a nice sum of money for it.");
         set_short("A polished piece of "+str+"");
         set_weight(2);
         break;
      case 101..150:
         set_long("This is a cut piece of "+str+" that would no doubt bring in"+
         " quite a bit of money if you could find a buyer.");
         set_short("A cut piece of "+str+"");
         set_weight(2);
         break;
   }
   if(val < 20) {
      set_value(20);
   }
   else {
      set_value(val);
   }
   set_id(({"gem",str}));
   set_name("gem");
}

int is_gem() { return 1; }
