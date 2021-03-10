//costume_skeleton.c - skeleton costume for new Seneca
//~Circe~ 12/29/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
string gender;
   ::create();
   set_name("skeleton costume");
   set_id(({"costume","skeleton costume","Skeleton Costume","chilling skeleton costume"}));
   set_short("%^BOLD%^%^BLACK%^chilling %^WHITE%^skeleton %^BLACK%^"+
      "costume%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^A fitted black bodysuit has been "+
      "used in the construction of this ingenious %^WHITE%^"+
      "skeleton %^BLACK%^costume.  Sewed onto the bodysuit "+
      "are brilliantly %^WHITE%^white bone %^BLACK%^appliques, "+
      "creating a convincing image of a skeleton.  No detail "+
      "has been left unattended - skeletal gloves and boots "+
      "cover the wearer's hands and feet, while a hood "+
      "is provided for the head.  A grinning %^WHITE%^mask "+
      "%^BLACK%^has small eyeholes, allowing the actor to "+
      "see during a performance.%^RESET%^");
   set_costume_type("%^BOLD%^%^WHITE%^chilling skeleton");
   set_costume("costume");
   set_value(350);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}