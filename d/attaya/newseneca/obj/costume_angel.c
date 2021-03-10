//costume_angel.c - angel costume for new Seneca
//~Circe~ 12/23/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("angel costume");
   set_id(({"costume","angel costume","Angel Costume","pristine angel costume"}));
   set_short("%^BOLD%^%^WHITE%^pristine a%^CYAN%^n%^WHITE%^g"+
      "%^CYAN%^e%^WHITE%^l costume%^RESET%^");
   set_long("%^BOLD%^A pure %^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v"+
      "%^RESET%^e%^BOLD%^r%^RESET%^y %^BOLD%^w%^RESET%^h%^BOLD%^i"+
      "%^RESET%^t%^BOLD%^e gown belted "+
      "with a %^YELLOW%^golden rope %^WHITE%^reaches the wearer's "+
      "ankles in this delicate costume.  The slender sleeves "+
      "are made of %^RESET%^sheer fabric %^BOLD%^and flare at the "+
      "elbows, ending in long points well beneath the wearer's "+
      "fingers.  Expansive %^RESET%^f%^BOLD%^e%^RESET%^a%^BOLD%^t"+
      "%^RESET%^h%^BOLD%^e%^RESET%^r%^BOLD%^y wings arch gracefully "+
      "from between the shoulderblades, while a graceful %^YELLOW%^"+
      "golden halo %^WHITE%^rises overhead, supported by a slender "+
      "wire.  A fake %^YELLOW%^harp %^WHITE%^adds the finishing "+
      "touch to the ensemble.%^RESET%^");
   set_costume_type("%^BOLD%^%^WHITE%^pristine angel");
   set_costume("costume");
   set_value(350);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}