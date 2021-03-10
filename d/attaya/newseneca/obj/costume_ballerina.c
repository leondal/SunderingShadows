//costume_ballerina.c - ballerina costume for new Seneca
//~Circe~ 12/22/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("ballerina costume");
   set_id(({"costume","ballerina costume","Ballerina Costume","graceful ballerina costume"}));
   set_short("%^BOLD%^%^MAGENTA%^graceful ballerina costume%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^A snuggly fitting bodice crafted "+
      "from %^BOLD%^pink silk %^RESET%^%^MAGENTA%^appears to close "+
      "by means of intricate %^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^"+
      "v%^RESET%^e%^BOLD%^r %^RESET%^r%^BOLD%^i%^RESET%^b%^BOLD%^b"+
      "%^RESET%^o%^BOLD%^n%^RESET%^s %^MAGENTA%^that lace up "+
      "the front.  In reality, the costume has a cleverly designed "+
      "series of three ties in the back that allow the actress to "+
      "slip into it quickly.  A tutu of %^BOLD%^pink tulle %^RESET%^"+
      "%^MAGENTA%^rests around the wearer's hips, revealing the "+
      "legs from mid-thigh downward.  A pair of matching %^BOLD%^"+
      "ballet slippers %^RESET%^%^MAGENTA%^that lace up the calf "+
      "are provided as well.%^RESET%^");
   set_costume_type("%^BOLD%^%^MAGENTA%^graceful ballerina");
   set_costume("costume");
   set_value(400);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}