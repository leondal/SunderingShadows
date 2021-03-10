//costume_butterfly.c - Butterfly costume for new Seneca
//Description by Eireen
//~Circe~ 11/14/08
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("butterfly costume");
   set_id(({"costume","butterfly costume","Butterfly Costume","elegant butterfly costume"}));
   set_short("%^RESET%^%^MAGENTA%^el%^BOLD%^e%^RESET%^%^MAGENTA%^ga"+
      "%^BOLD%^n%^RESET%^%^MAGENTA%^t bu%^BOLD%^t%^BLACK%^t%^MAGENTA%^e"+
      "%^RESET%^%^MAGENTA%^rf%^BOLD%^l%^RESET%^%^MAGENTA%^y co"+
      "%^BOLD%^%^BLACK%^s%^MAGENTA%^t%^RESET%^%^MAGENTA%^u%^BOLD%^m"+
      "%^RESET%^%^MAGENTA%^e%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This cape appears to be a simple, hooded "+
      "garment of %^BLACK%^s%^RESET%^h%^BOLD%^%^WHITE%^i%^BLACK%^m%^RESET"+
      "%^m%^BOLD%^%^BLACK%^e%^WHITE%^r%^RESET%^i%^BOLD%^%^WHITE%^n%^BLACK%^g "+
      "b%^RESET%^%^BLUE%^l%^BOLD%^%^BLACK%^a%^RESET%^%^BLUE%^c%^BOLD%^"+
      "%^BLACK%^k s%^BOLD%^%^BLUE%^a%^BLACK%^t%^BLUE%^i%^BLACK%^n%^BOLD%^"+
      "%^WHITE%^ covering the wearer from hair to toes, exposing only the "+
      "%^RESET%^%^MAGENTA%^m%^BOLD%^a%^RESET%^%^MAGENTA%^sk%^BOLD%^e%^RESET%^"+
      "%^MAGENTA%^d%^BOLD%^%^WHITE%^ face.  The front edge contains long "+
      "slender sticks in either seam, which, when lifted by the wearer, "+
      "whip open %^BOLD%^%^WHITE%^f%^MAGENTA%^r%^WHITE%^i%^MAGENTA%^l"+
      "%^WHITE%^l%^MAGENTA%^e%^BOLD%^%^WHITE%^d l%^RESET%^a%^BOLD%^c%^RESET%^"+
      "y %^MAGENTA%^w%^BOLD%^%^BLUE%^i%^RESET%^%^MAGENTA%^n%^BOLD%^%^BLUE%^g"+
      "%^RESET%^%^MAGENTA%^s %^BOLD%^%^WHITE%^of varying shades of %^BOLD%^"+
      "%^MAGENTA%^la%^RESET%^%^MAGENTA%^v%^BOLD%^e%^RESET%^%^MAGENTA%^nd"+
      "%^BOLD%^%^MAGENTA%^er %^CYAN%^, %^BOLD%^%^MAGENTA%^pink%^WHITE%^, "+
      "%^MAGENTA%^m%^BOLD%^%^BLACK%^a%^BOLD%^%^MAGENTA%^u%^BOLD%^%^BLACK%^v"+
      "%^BOLD%^%^MAGENTA%^e %^WHITE%^and %^RESET%^%^MAGENTA%^purple %^BOLD%^"+
      "%^WHITE%^l%^RESET%^%^MAGENTA%^a%^BOLD%^%^WHITE%^c%^RESET%^%^MAGENTA%^e"+
      "%^BOLD%^%^WHITE%^.  This movement also exposes a form-fitting "+
      "bodysuit of %^BOLD%^%^BLACK%^s%^RESET%^h%^BOLD%^%^WHITE%^i%^BLACK%^"+
      "m%^RESET%^m%^BOLD%^%^BLACK%^e%^WHITE%^r%^RESET%^i%^BOLD%^%^WHITE%^n"+
      "%^BLACK%^g b%^RESET%^%^BLUE%^l%^BOLD%^%^BLACK%^a%^RESET%^%^BLUE%^c"+
      "%^BOLD%^%^BLACK%^k s%^BOLD%^%^BLUE%^a%^BLACK%^t%^BLUE%^i%^BLACK%^n"+
      "%^BOLD%^%^WHITE%^ practically painted on a %^RESET%^%^CYAN%^lithe"+
      "%^BOLD%^, %^MAGENTA%^graceful %^RED%^female form%^WHITE%^.  The "+
      "sticks can also be secured to straps on the waistband of the "+
      "bodysuit, leaving the wings in place while freeing up the hands "+
      "of the wearer.  Tall heeled boots in exactly the same shade of "+
      "%^BLACK%^black %^WHITE%^as the body suit and a %^RESET%^%^MAGENTA%^"+
      "purple%^BOLD%^%^WHITE%^ and %^BOLD%^%^MAGENTA%^pink %^WHITE%^"+
      "feathered mask complete the outfit.%^RESET%^");
   set_costume_type("%^RESET%^%^MAGENTA%^el%^BOLD%^e%^RESET%^%^MAGENTA%^ga"+
      "%^BOLD%^n%^RESET%^%^MAGENTA%^t bu%^BOLD%^t%^BLACK%^t%^MAGENTA%^e"+
      "%^RESET%^%^MAGENTA%^rf%^BOLD%^l%^RESET%^%^MAGENTA%^y");
   set_costume("costume");
   set_value(400);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}