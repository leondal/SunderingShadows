//koenig_gem.c

#include <std.h>

#define NAMES ({"rose quartz", "water opal", "opal", "hematite", "bloodstone", "jade", "smokey quartz", "quartz", "pearl", "black pearl", "aquamarine", "azurite", "turquoise", "citrine", "lapis", "amber", "agate", "jet", "malachite", "peridot"})

inherit OBJECT;

void create(){
   int i,j, val;
   string str, size, *strs;

   ::create();
   val = random(15)+7;
   j = random(20);
   str = NAMES[j];
   set_name("gem");
   set_long("This is a small piece of "+str+" that has been polished and worn "+
      "smooth.  It sparkles in the light and probably has some value.");
   set_short("A small "+str+"");
   strs = explode(str," ");
   strs = strs + ({"gem",str,capitalize(str)});
   set_id(strs);
   set_weight(2);
   set_value(val);
}

int is_gem(){return 1;}
