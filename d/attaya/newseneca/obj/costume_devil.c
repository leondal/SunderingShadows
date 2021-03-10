//costume_devil.c - devil costume for new Seneca
//~Circe~ 12/22/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("devil costume");
   set_id(({"costume","devil costume","Devil Costume","sinister devil costume"}));
   set_short("%^BOLD%^%^BLACK%^sinister %^RED%^devil%^BLACK%^ costume%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Thin black fabric has been used to "+
      "create a one-piece bodysuit that is easily donned through a "+
      "slit in the back that ties closed.  Topping the bodysuit "+
      "is a %^RESET%^%^RED%^blood-red cape %^BOLD%^%^BLACK%^"+
      "used to great effect when the actor flourishes it with a "+
      "wicked grin.  A %^RESET%^metal band %^BOLD%^%^BLACK%^topped "+
      "with two %^RED%^red horns %^BLACK%^is provided along with "+
      "a %^RED%^red pitchfork%^BLACK%^.  Finishing the costume "+
      "are the %^BOLD%^red facepaint %^BLACK%^and fake %^RESET%^"+
      "goatee %^BOLD%^%^BLACK%^to complete the illusion.%^RESET%^");
   set_costume_type("%^BOLD%^%^BLACK%^sinister%^RED%^ devil");
   set_costume("costume");
   set_value(350);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}