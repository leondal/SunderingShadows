//costume_witch.c - witch costume for new Seneca
//~Circe~ 12/19/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("witch costume");
   set_id(({"costume","witch costume","Witch Costume","ugly witch costume"}));
   set_short("%^BOLD%^%^BLACK%^ugly witch costume%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^A flowing black gown in soft "+
      "fabric makes up the base of this costume.  Slits under "+
      "the arms that may be tied shut allow for easy access "+
      "to the costume - an actress may simply slip "+
      "the garment over her head and then tie it to the proper "+
      "fit.  Voluminous sleeves reach points near the wearer's "+
      "fingertips, while the hem brushes the ground.  A "+
      "%^RESET%^nose %^BOLD%^%^BLACK%^molded from clay has "+
      "been provided, complete with a %^RESET%^%^GREEN%^wart "+
      "%^BOLD%^%^BLACK%^on the end.  A tall, pointed hat "+
      "completes the costume, instantly turning anyone into "+
      "a haggard old witch.%^RESET%^");
   set_costume_type("%^BOLD%^%^BLACK%^ugly witch%^RESET%^");
   set_costume("costume");
   set_value(250);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}