// /d/tonerra/obj/gem.c

#include <std.h>

#define NAMES ({"amethyst","topaz","quartz crystal","gold nugget","ruby","sapphire","malachite"})

inherit OBJECT;

void create(){
   int i,j, val;
   string str, size, *strs;

   ::create();
   val = random(100)+5;
   j=random(7);
   j = random(7);
   str = NAMES[j];
   set_name("gem");
   set_long("This is a medium, highly polished piece of "+str+". It sparkles in
the light and probably has some value.");
   set_short("A medium "+str+"");
   strs = explode(str," ");
   strs = strs + ({"gem",str,capitalize(str)});
   set_id(strs);
   set_weight(4);
   set_value(val);
}

int is_gem(){return 1;}
