//costume_cat.c - Cat costume for new Seneca
//Description by Eireen
//~Circe~ 11/14/08
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("cat costume");
   set_id(({"costume","cat costume","Cat Costume","calico cat costume"}));
   set_short("%^BOLD%^%^WHITE%^c%^BLACK%^a%^YELLOW%^l%^RESET%^i%^ORANGE%^c"+
      "%^BOLD%^%^BLACK%^o %^WHITE%^c%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^t "+
      "%^YELLOW%^c%^WHITE%^o%^RESET%^%^ORANGE%^s%^RESET%^t%^BOLD%^u%^BLACK%^"+
      "m%^RESET%^%^ORANGE%^e%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^A body-hugging jumpsuit crafted from "+
      "%^RESET%^%^ORANGE%^m%^BOLD%^%^WHITE%^u%^BLACK%^l%^ORANGE%^t"+
      "%^BOLD%^%^WHITE%^i%^BLACK%^c%^YELLOW%^o%^RESET%^l%^ORANGE%^o"+
      "%^BOLD%^%^BLACK%^r%^WHITE%^e%^RESET%^%^ORANGE%^d%^MAGENTA%^ plush "+
      "%^BOLD%^%^BLACK%^v%^WHITE%^e%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^"+
      "v%^RESET%^e%^BOLD%^%^WHITE%^t %^RESET%^%^MAGENTA%^covers the "+
      "wearer's entire body except for the hands and feet.  A long "+
      "tail of %^BOLD%^%^BLACK%^s%^RESET%^h%^BOLD%^a%^RESET%^%^ORANGE%^"+
      "d%^BOLD%^%^BLACK%^e%^RESET%^d %^BOLD%^v%^BLACK%^e%^RESET%^"+
      "%^ORANGE%^l%^BOLD%^v%^WHITE%^e%^BLACK%^t%^RESET%^%^MAGENTA%^ "+
      "over some sort of flexible framing adds a touch of realism.  A "+
      "stretchy hood covers the hair of the wearer, with pert, "+
      "triangular ears on the top of the head.  Tall boots of %^BOLD%^"+
      "%^BLACK%^s%^RESET%^h%^BOLD%^a%^RESET%^%^ORANGE%^d%^BOLD%^"+
      "%^BLACK%^e%^RESET%^d %^BOLD%^v%^BLACK%^e%^RESET%^%^ORANGE%^l"+
      "%^BOLD%^v%^WHITE%^e%^BLACK%^t%^RESET%^%^MAGENTA%^ blend seamlessly "+
      "with the legs of the bodysuit, and matching %^ORANGE%^v%^BOLD%^"+
      "%^BLACK%^e%^WHITE%^l%^RESET%^v%^ORANGE%^e%^BOLD%^%^BLACK%^t "+
      "%^RESET%^%^MAGENTA%^gloves encase the fingers, ending in short, "+
      "%^BOLD%^%^WHITE%^cu%^RESET%^rv%^BOLD%^%^BLACK%^i%^WHITE%^ng c"+
      "%^RESET%^%^RED%^l%^BOLD%^%^WHITE%^aws%^RESET%^%^MAGENTA%^.  A "+
      "three-quarter %^RESET%^%^ORANGE%^c%^WHITE%^a%^BOLD%^%^BLACK%^t"+
      "%^WHITE%^-%^YELLOW%^f%^RESET%^a%^ORANGE%^c%^BOLD%^%^BLACK%^e "+
      "%^WHITE%^m%^RESET%^a%^ORANGE%^s%^BOLD%^%^BLACK%^k%^RESET%^%^MAGENTA%^ "+
      "with a %^BOLD%^%^BLACK%^tr%^RESET%^i%^BOLD%^%^BLACK%^ang%^RESET%^u"+
      "%^BOLD%^%^BLACK%^lar %^RESET%^%^BLUE%^nose%^RESET%^%^MAGENTA%^ and "+
      "%^BOLD%^%^WHITE%^l%^BLACK%^o%^WHITE%^ng wh%^BLACK%^i%^WHITE%^sk"+
      "%^BOLD%^%^BLACK%^e%^WHITE%^rs%^RESET%^%^MAGENTA%^ covers all but "+
      "the lower jaw of the wearer which is covered in %^BOLD%^%^WHITE%^"+
      "white greasepaint%^RESET%^%^MAGENTA%^, blending in with a %^BOLD%^"+
      "%^WHITE%^white patch%^RESET%^%^MAGENTA%^ of velvet on the throat "+
      "of the body suit.%^RESET%^");
   set_costume_type("%^BOLD%^%^WHITE%^c%^BLACK%^a%^YELLOW%^l%^RESET%^i%^ORANGE%^c"+
      "%^BOLD%^%^BLACK%^o %^WHITE%^c%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^t");
   set_costume("costume");
   set_value(400);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}