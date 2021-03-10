//costume_guard.c - guard costume for new Seneca
//~Circe~ 12/28/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

#define COLORS ({"navy blue","olive green","black","tan","gray"})

void create(){
string CLR,color;
   ::create();
   CLR = COLORS[random(sizeof(COLORS))];
   set_name("guard costume");
   set_id(({"costume","guard costume","Guard Costume",""+CLR+" guard costume"}));
   switch(CLR){
      case "navy blue": color = "%^RESET%^%^BLUE%^"; break;
      case "olive green": color = "%^RESET%^%^GREEN%^"; break;
      case "black": color = "%^BOLD%^%^BLACK%^"; break;
      case "tan": color = "%^RESET%^%^ORANGE%^"; break;
      case "gray": color = "%^BOLD%^%^BLACK%^"; break;
      default: color = "uh oh, something's wrong"; break;
   }
   set_short(""+color+""+CLR+" guard costume%^RESET%^");
   set_long("Crafted from "+color+""+CLR+" fabric%^RESET%^, this "+
      "costume is designed to be easy to don.  The pants are "+
      ""+color+""+CLR+" cotton%^RESET%^ with a contrasting "+
      "stripe down the outside of each leg, and they are held up "+
      "by a cleverly designed drawstring.  The top of the pants "+
      "is hidden by the ill-fitting jacket of matching "+
      ""+color+""+CLR+" cotton%^RESET%^ designed to be put on "+
      "over the head, a fact that is disguised by the row of "+
      "buttons sewn into the false opening in the front.  A "+
      "%^BOLD%^%^BLACK%^leather belt %^RESET%^is provided to "+
      "cinch the jacket around the waist, providing a better "+
      "fit.  The finishing touches of the costume are the matching "+
      ""+color+""+CLR+" hat %^RESET%^and %^BOLD%^%^BLACK%^black "+
      "boot toppers%^RESET%^.");
   set_costume_type(""+color+""+CLR+" guard");
   set_costume("costume");
   set_value(400);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}