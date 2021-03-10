//costume_mermaid.c - mermaid costume for new Seneca
//~Circe~ 12/23/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("mermaid costume");
   set_id(({"costume","mermaid costume","Mermaid Costume","glittering mermaid costume"}));
   set_short("%^RESET%^%^GREEN%^g%^CYAN%^l%^GREEN%^i%^CYAN%^t"+
      "%^GREEN%^t%^CYAN%^e%^GREEN%^r%^CYAN%^i%^GREEN%^n%^CYAN%^g "+
      "%^BOLD%^%^GREEN%^mermaid %^RESET%^%^CYAN%^costume%^RESET%^");
   set_long("%^GREEN%^A tight-fitting skirt of %^BOLD%^green "+
      "%^RESET%^%^GREEN%^sewn with %^CYAN%^s%^GREEN%^p%^CYAN%^a"+
      "%^GREEN%^r%^CYAN%^k%^GREEN%^l%^CYAN%^i%^GREEN%^n%^CYAN%^g"+
      "%^GREEN%^ sequins rides low on the hips in this mermaid "+
      "costume.  The material of the skirt fits closely all the "+
      "way to the feet, which are covered in a split fin tail, "+
      "but a clever slit in the back of the skirt allows the "+
      "actress to move.  A top made from two %^RESET%^seashells "+
      "%^GREEN%^strung with felt %^BOLD%^seaweed%^RESET%^%^GREEN%^ "+
      "matches the %^BOLD%^seaweed boa %^RESET%^%^GREEN%^that "+
      "may be draped across the wearer's shoulders.  The finishing "+
      "touch for this costume is a pair of %^BOLD%^%^MAGENTA%^"+
      "pink coral combs %^RESET%^%^GREEN%^used to pull back "+
      "the hair.%^RESET%^");
   set_costume_type("%^RESET%^%^GREEN%^g%^CYAN%^l%^GREEN%^i%^CYAN%^t"+
      "%^GREEN%^t%^CYAN%^e%^GREEN%^r%^CYAN%^i%^GREEN%^n%^CYAN%^g "+
      "%^BOLD%^%^GREEN%^mermaid");
   set_costume("costume");
   set_value(450);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}