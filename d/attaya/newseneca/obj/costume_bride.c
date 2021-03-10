//costume_bride.c - bride costume for new Seneca
//~Circe~ 12/23/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("bride costume");
   set_id(({"costume","bride costume","Bride Costume","beautiful bride costume"}));
   set_short("%^BOLD%^%^WHITE%^beautiful bride costume%^RESET%^");
   set_long("A simple, flowing %^BOLD%^white dress %^RESET%^that "+
      "reaches the floor is topped with a layer of %^BOLD%^pristine "+
      "lace%^RESET%^ in this charming bride costume.  The bodice of "+
      "the dress has thin straps, while the lace has been used to "+
      "create long, sheer sleeves.  A thin necklace of %^BOLD%^plastic "+
      "pearls %^RESET%^and a long, %^BOLD%^s%^RESET%^h%^BOLD%^i"+
      "%^RESET%^m%^BOLD%^m%^RESET%^e%^BOLD%^r%^RESET%^i%^BOLD%^n"+
      "%^RESET%^g %^BOLD%^veil%^RESET%^ add the finishing touches "+
      "for this beautiful costume.");
   set_costume_type("%^BOLD%^%^WHITE%^beautiful bride");
   set_costume("costume");
   set_value(350);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}