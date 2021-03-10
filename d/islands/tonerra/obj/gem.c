// /d/tonerra/obj/gem.c
//lowered weight from 25 lbs to 8 lbs to put them more in line with other gems that are IG.  Circe 12/24/03

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

#define NAMES ({"ruby","opal","sapphire","emerald","topaz","diamond","gold nugget"})

inherit OBJECT;

void create(){
   int i,j, val;
   string str, size;

   ::create();
   val = random(1000);
   switch(val){
   case 0..99:
      size = "tiny ";
      set_weight(4);
      break;
   case 100..499:
      size = "small ";
      set_weight(6);
      break;
   case 500..799:
      size = "medium ";
      set_weight(7);
      break;
   case 800..999:
      size = "large ";
      set_weight(9);
      break;
   default:
      size = "";
      set_weight(7);
      break;
   }
   j=random(7);
   str= NAMES[j];
   set_long("This is a "+size+""+str+". It shines in the light and is probably very valuable.");
   set_short("a "+size+""+str);
   set_id(({"gem",str,capitalize(str)}));
   set_value(val);
}

int is_gem(){return 1;}
