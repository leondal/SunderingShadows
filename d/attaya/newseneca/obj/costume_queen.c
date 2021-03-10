//costume_queen.c - queen costume for new Seneca
//~Circe~ 12/29/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("queen costume");
   set_id(({"costume","queen costume","queen Costume","majestic queen costume"}));
   set_short("%^RESET%^%^GREEN%^elegant %^YELLOW%^queen "+
      "%^RESET%^%^GREEN%^costume%^RESET%^");
   set_long("%^RESET%^%^GREEN%^This costume is made from soft "+
      "%^BOLD%^green velvet%^RESET%^%^GREEN%^ made to fit snugly "+
      "by means of a slit in either side and a series of ties "+
      "for adjustments.  The bodice conforms to the wearer's "+
      "body and is detailed with lines of %^YELLOW%^gold "+
      "piping%^RESET%^%^GREEN%^.  The sleeves are puffed up at "+
      "the shoulders before tapering to slender points on the "+
      "backs of the hands.  A full skirt has been decorated with "+
      "%^YELLOW%^embroidery%^RESET%^%^GREEN%^ and is divided "+
      "in the front to reveal a %^YELLOW%^golden lace panel "+
      "%^RESET%^%^GREEN%^beneath.  The highlight of the costume "+
      "is the delicate %^YELLOW%^crown %^RESET%^%^GREEN%^set with sparkling "+
      "faux gems.%^RESET%^");
   set_costume_type("%^RESET%^%^GREEN%^majestic queen");
   set_costume("costume");
   set_value(550);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}