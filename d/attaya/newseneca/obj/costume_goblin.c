//costume_goblin.c - goblin costume for new Seneca
//~Circe~ 12/23/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("goblin costume");
   set_id(({"costume","goblin costume","Goblin Costume","ragged goblin costume"}));
   set_short("%^RESET%^%^GREEN%^ragged %^BOLD%^goblin"+
      "%^RESET%^%^GREEN%^ costume%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^Ragged leather scraps fitted into "+
      "a motley assortment of armor pieces make up the bulk of "+
      "this %^GREEN%^goblin %^ORANGE%^costume.  A %^RED%^red "+
      "shirt %^ORANGE%^with numerous holes peeks through "+
      "the armor in several places, while a close-fitting "+
      "%^GREEN%^green bodysuit %^ORANGE%^is made to cover "+
      "the wearer's limbs.  Clawed %^GREEN%^prosthetic feet "+
      "%^ORANGE%^made from stuffed material are provided, as "+
      "well as the scrap cloth to wrap around the wearer's "+
      "ankles to help them blend in.  A %^BOLD%^%^BLACK%^cap "+
      "%^RESET%^%^ORANGE%^lined with bristly %^BOLD%^%^BLACK%^"+
      "black hair %^RESET%^%^ORANGE%^and a fake %^RED%^mace "+
      "%^ORANGE%^complete the costume.%^RESET%^");
   set_costume_type("%^RESET%^%^GREEN%^ragged %^BOLD%^goblin");
   set_costume("costume");
   set_value(350);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}