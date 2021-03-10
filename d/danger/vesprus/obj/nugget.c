#include <std.h>
#include "../vesprus.h"
inherit OBJECT;

void create(){
   int val;
   string str, size;
   ::create();
   val = random(800);
   switch(val){
   case 0..300:
      size = "small ";
      break;
   case 301..599:
      size = "medium ";
      break;
   case 600..799:
      size = "large ";
      break;
   default:
      size = "small";
      break;
   }
   set_long("%^YELLOW%^This is an irregularly shaped "+size+"gold nugget that shines in the light.  It is probably worth a fair amount.%^RESET%^");
   set_short("%^YELLOW%^A gold nugget%^RESET%^");
   set_id(({"gold","gold nugget","nugget","gem"}));
   set_weight(8);
   set_value(val);
}