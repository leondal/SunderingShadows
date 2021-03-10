//costume_king.c - king costume for new Seneca
//~Circe~ 12/29/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("king costume");
   set_id(({"costume","king costume","King Costume","majestic king costume"}));
   set_short("%^RESET%^%^GREEN%^majestic %^YELLOW%^king "+
      "%^RESET%^%^GREEN%^costume%^RESET%^");
   set_long("%^RESET%^%^GREEN%^Layers of %^BOLD%^green velvet "+
      "%^RESET%^%^GREEN%^slashed to reveal shimmering %^YELLOW%^"+
      "golden satin %^RESET%^%^GREEN%^are fashioned into a long-"+
      "sleeved doublet in this gorgeous costume.  A matching "+
      "%^BOLD%^cape %^RESET%^%^GREEN%^lined with %^MAGENTA%^violet "+
      "satin %^GREEN%^and trimmed with %^YELLOW%^gold braid %^RESET%^"+
      "%^GREEN%^attaches at the shoulders, while a %^YELLOW%^golden "+
      "crown %^RESET%^%^GREEN%^glitters with faux jewels.  Puffy "+
      "%^BOLD%^knee breeches %^RESET%^%^GREEN%^are banded above "+
      "%^BOLD%^%^WHITE%^white leggings%^RESET%^%^GREEN%^, which in "+
      "turn end in %^BOLD%^velvet shoes%^RESET%^%^GREEN%^, providing "+
      "the finishing touch for this kingly costume.%^RESET%^");
   set_costume_type("%^RESET%^%^GREEN%^majestic king");
   set_costume("costume");
   set_value(550);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}