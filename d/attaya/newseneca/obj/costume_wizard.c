//costume_wizard.c - wizard costume for new Seneca
//~Circe~ 12/28/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("wizard costume");
   set_id(({"costume","wizard costume","Wizard Costume","celestial wizard costume"}));
   set_short("%^RESET%^%^MAGENTA%^celestial w%^RESET%^i%^MAGENTA%^z"+
      "%^RESET%^a%^MAGENTA%^r%^RESET%^d %^MAGENTA%^costume%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^Cheap violet-colored velvet forms "+
      "this wizard robe.  Brilliant %^BOLD%^%^WHITE%^stars %^RESET%^"+
      "%^MAGENTA%^in different sizes are sewn in the fabric, their "+
      "satiny sheen matching the %^BOLD%^%^WHITE%^sash "+
      "%^RESET%^%^MAGENTA%^that secures the waist and the wide "+
      "%^BOLD%^%^WHITE%^bands %^RESET%^%^MAGENTA%^that encircle "+
      "the wrists.  A voluminous %^BOLD%^%^WHITE%^white beard "+
      "%^RESET%^%^MAGENTA%^and %^BOLD%^%^WHITE%^wig %^RESET%^"+
      "%^MAGENTA%^are provided with the costume, as is a slender "+
      "%^ORANGE%^wooden wand%^MAGENTA%^.%^RESET%^");
   set_costume_type("%^RESET%^%^MAGENTA%^celestial wizard");
   set_costume("costume");
   set_value(300);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}