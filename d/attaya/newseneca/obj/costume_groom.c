//costume_groom.c - groom costume for new Seneca
//~Circe~ 12/28/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("groom costume");
   set_id(({"costume","groom costume","Groom Costume","dapper groom costume"}));
   set_short("%^BOLD%^%^BLACK%^dapper %^WHITE%^groom "+
      "%^BLACK%^costume%^RESET%^");
   set_long("A dressy %^BOLD%^%^BLACK%^velvet tunic%^RESET%^ "+
      "belted at the waist atop a spotless %^BOLD%^white "+
      "shirt %^RESET%^with billowing sleeves gathered at the "+
      "wrist is the focal point of this costume.  The edges of "+
      "the %^BOLD%^%^BLACK%^tunic %^RESET%^are trimmed in "+
      "%^YELLOW%^gold braid%^RESET%^, matching the %^YELLOW%^"+
      "band %^RESET%^on the %^BOLD%^%^BLACK%^hat %^RESET%^that "+
      "is provided.  The pants are simple %^BOLD%^%^BLACK%^black "+
      "velvet %^RESET%^with attached %^BOLD%^%^BLACK%^boot "+
      "toppers%^RESET%^, making this a quick and easy costume "+
      "to don.");
   set_costume_type("%^BOLD%^%^BLACK%^dapper %^WHITE%^groom");
   set_costume("costume");
   set_value(425);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}