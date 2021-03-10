//costume_ghost.c - ghost costume for new Seneca
//~Circe~ 12/29/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
string gender;
   ::create();
   set_name("ghost costume");
   set_id(({"costume","ghost costume","Ghost Costume","spooky ghost costume"}));
   set_short("%^BOLD%^%^WHITE%^spooky ghost costume%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This simple costume is made from "+
      "a large, mostly circular sheet of white fabric.  The "+
      "fabric is meant to drape over the wearer's entire body, "+
      "including the head, and it features no decoration "+
      "whatsoever.  The only defining feature of the costume "+
      "are the two %^BLACK%^eyeholes %^WHITE%^cut into the "+
      "head of the sheet, allowing the actor to see.%^RESET%^");
   set_costume_type("%^BOLD%^%^WHITE%^spooky ghost");
   set_costume("costume");
   set_value(250);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}