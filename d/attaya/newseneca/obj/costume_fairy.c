//costume_fairy.c - fairy costume for new Seneca
//~Circe~ 12/19/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("fairy costume");
   set_id(({"costume","fairy costume","Fairy Costume","mystical fairy costume"}));
   set_short("%^BOLD%^%^CYAN%^mystical %^MAGENTA%^fairy %^CYAN%^costume%^RESET%^");
   set_long("%^BOLD%^%^CYAN%^Made from layers of thin, "+
      "m%^GREEN%^u%^MAGENTA%^l%^YELLOW%^t%^WHITE%^i%^CYAN%^-"+
      "%^GREEN%^c%^MAGENTA%^o%^YELLOW%^l%^WHITE%^o%^CYAN%^r"+
      "%^GREEN%^e%^MAGENTA%^d %^CYAN%^chiffon, this beautiful "+
      "fairy costume has a close-fitting bodice in %^RESET%^"+
      "%^CYAN%^azure silk %^BOLD%^bordered with %^WHITE%^"+
      "silver%^CYAN%^.  The skirt flares out in all directions, "+
      "the layers of fabric reaching in petaled tiers to the "+
      "wearer's knees.  Matching %^RESET%^%^CYAN%^azure "+
      "slippers %^BOLD%^have been provided, as well as a "+
      "delicate %^YELLOW%^fairy wand%^CYAN%^.  This costume "+
      "takes more time to don than most others, requiring "+
      "the wearer to have help doing up the buttons that run "+
      "along the back.  A pair of %^RESET%^wired wings %^BOLD%^"+
      "%^CYAN%^covered with a thin layer of %^WHITE%^silvery "+
      "chiffon %^CYAN%^complete the ensemble.%^RESET%^");
   set_costume_type("%^BOLD%^%^CYAN%^mystical fairy%^RESET%^");
   set_costume("costume");
   set_value(500);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}