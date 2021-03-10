//costume_ninja.c - Ninja costume for new Seneca
//~Circe~ 12/19/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("ninja costume");
   set_id(({"costume","ninja costume","Ninja Costume","mysterious ninja costume"}));
   set_short("%^BOLD%^%^BLACK%^mysterious ninja costume%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This costume is made of a close-"+
      "fitting bodysuit that covers the wearer from head-to-"+
      "toe.  A mask is attached that goes around the head and "+
      "drapes across the face, leaving only the wearer's eyes "+
      "in the open.  Slender split-toed slippers cover the feet, "+
      "and extra fabric has been sewn onto the legs to make it "+
      "seem as though fabric has been wrapped around them.  The "+
      "costume is made to be easily slipped into and out of through "+
      "the use of a cleverly designed slit in the back that ties shut.%^RESET%^");
   set_costume_type("%^BOLD%^%^BLACK%^mysterious ninja%^RESET%^");
   set_costume("costume");
   set_value(350);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}