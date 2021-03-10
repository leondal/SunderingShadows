// /d/tonerra/obj/gem.c

#include <std.h>

#define NAMES ({"amethyst","topaz","quartz crystal","aquamarine","gold nugget","ruby","sapphire","malachite"})

inherit OBJECT;

void create(){
   int i,j, val;
   string str, size, *strs;

   ::create();
   val = random(75)+5;
   j=random(7);
   j = random(8);
   str = NAMES[j];
  set_name("gem");
   set_long("This is a small and unpolished piece of "+str+". It shines in the light and probably has some value.");
   set_short("A small "+str+"");
   strs = explode(str," ");
   strs = strs + ({"gem",str,capitalize(str)});
   set_id(strs);
   set_weight(4);
   set_value(val);
}

int is_gem(){return 1;}
