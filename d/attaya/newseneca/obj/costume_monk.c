//costume_monk.c - monk costume for new Seneca
//~Circe~ 12/29/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
string gender;
   ::create();
   set_name("monk costume");
   set_id(({"costume","monk costume","Monk Costume","stoic monk costume"}));
   set_short("%^RESET%^%^ORANGE%^stoic monk costume%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This costume is made from a loose-"+
      "fitting robe of brown cotton that reaches the wearer's "+
      "ankles.  The opening of the robe fits close around the "+
      "neck and rises in the back to a pointed hood that shades "+
      "the actor's eyes when pulled forward.  A %^RESET%^white "+
      "cord %^ORANGE%^belts the robe, and a string of %^YELLOW%^"+
      "beads %^RESET%^%^ORANGE%^dangles from it in imitation of "+
      "a holy symbol.  A pair of simple sandals made to look "+
      "like leather are provided as well, completing the costume.%^RESET%^");
   set_costume_type("%^RESET%^%^ORANGE%^stoic monk");
   set_costume("costume");
   set_value(300);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}