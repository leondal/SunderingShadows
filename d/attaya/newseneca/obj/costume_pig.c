//costume_pig.c - pig costume for new Seneca
//~Circe~ 12/23/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("pig costume");
   set_id(({"costume","pig costume","Pig Costume","pink pig costume"}));
   set_short("%^BOLD%^%^MAGENTA%^pink pig costume%^RESET%^");
   set_long("%^BOLD%^%^MAGENTA%^A stuffed pink fleece bodysuit "+
      "covers the wearer from head to toe in this cute little "+
      "piggy costume.  %^BLACK%^Black gloves %^MAGENTA%^and "+
      "%^BLACK%^soft boots %^MAGENTA%^are fashioned for the hands "+
      "and feet, while the wearer's head is covered with a full "+
      "headdress topped with pink ears.  The %^BLACK%^"+
      "eyes %^MAGENTA%^are made from mesh to allow the actor "+
      "to see, and the nose has been constructed with metal "+
      "reinforcements to give it just the right look.  The "+
      "finishing touch is an adorable c%^WHITE%^u%^MAGENTA%^"+
      "r%^WHITE%^l%^MAGENTA%^y pink tail that bounces as "+
      "the wearer walks.%^RESET%^");
   set_costume_type("%^BOLD%^%^MAGENTA%^pink pig");
   set_costume("costume");
   set_value(400);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}