//costume_pirate.c - pirate costume for new Seneca
//~Circe~ 12/23/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("pirate costume");
   set_id(({"costume","pirate costume","Pirate Costume","swashbuckling pirate costume"}));
   set_short("%^RESET%^%^ORANGE%^swashbuckling%^BOLD%^%^BLACK%^ "+
      "pirate %^RESET%^%^ORANGE%^costume%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^Several layers have been sewn "+
      "together to create this convincing pirate costume.  A "+
      "flowing %^RESET%^white shirt %^ORANGE%^with gathered "+
      "sleeves is topped with a thin leather vest lined in "+
      "%^BOLD%^%^BLACK%^black %^RESET%^%^ORANGE%^and belted "+
      "with a %^BOLD%^%^RED%^red sash %^RESET%^%^ORANGE%^"+
      "tucked beneath a %^BOLD%^%^BLACK%^leather belt%^RESET%^"+
      "%^ORANGE%^.  Flowing %^BOLD%^%^BLACK%^cotton trousers "+
      "%^RESET%^%^ORANGE%^are provided, complete with sewn in "+
      "boot toppers to add to the pirate look.  A leather "+
      "pirate hat and %^BOLD%^%^BLACK%^eyepatch %^RESET%^"+
      "%^ORANGE%^complete the costume.%^RESET%^");
   set_costume_type("%^BOLD%^%^BLACK%^swashbuckling pirate");
   set_costume("costume");
   set_value(500);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}