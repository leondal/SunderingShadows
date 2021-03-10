//costume_vampire.c - vampire costume for new Seneca
//~Circe~ 12/29/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
string gender;
   ::create();
   set_name("vampire costume");
   set_id(({"costume","vampire costume","Vampire Costume","majestic vampire costume"}));
   switch(random(2)){
      case 0:  gender = "female";
         set_long("%^BOLD%^%^BLACK%^This fitted costume is crafted "+
            "from soft black velvet with crisscrossing black ties "+
            "across the bodice.  A %^RED%^red satin gown %^BLACK%^"+
            "is revealed beneath the open front of the velvet "+
            "cover, reaching all the way to the floor.  The "+
            "fitted sleeves extend well past the wearer's wrists, "+
            "the %^RED%^satin-lined %^BLACK%^velvet ending in "+
            "narrow points near the knees.  A wide black choker "+
            "is provided to be worn around the neck as well "+
            "as velvet shoes for the feet.  The crowning piece "+
            "are the false %^WHITE%^fangs %^BLACK%^that may be "+
            "attached to the teeth.%^RESET%^");
         break;
      default: gender = "male";
         set_long("%^BOLD%^%^BLACK%^A %^RESET%^silvery shirt "+
            "%^BOLD%^%^BLACK%^peeks from beneath a black velvet "+
            "vest in this creative vampire costume.  Smooth "+
            "black pants seem to make the wearer's legs "+
            "disappear, while the crisp black cape lined with "+
            "%^RED%^crimson satin %^BLACK%^is wide enough "+
            "to dramatically cover the wearer's face.  A "+
            "suave cane with a %^RESET%^silver %^BOLD%^%^BLACK%^"+
            "cap adds a personal touch, but the truly defining "+
            "piece of this costume are the two false %^WHITE%^"+
            "fangs %^BLACK%^that may be attached to the wearer's "+
            "teeth.%^RESET%^");
         break;
   }
   set_short("%^RESET%^%^RED%^"+gender+" %^BOLD%^vampire "+
      "%^RESET%^%^RED%^costume%^RESET%^");
   set_costume_type("%^RESET%^%^RED%^"+gender+" %^BOLD%^vampire");
   set_costume("costume");
   set_value(375);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}