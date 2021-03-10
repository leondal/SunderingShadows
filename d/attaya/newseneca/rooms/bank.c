//updated by ~Circe~ 11/19/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit BANK;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light",3);
   set_property("indoors",1);
   set_name("Bank of Attaya, Seneca");
   set_short("%^BOLD%^Bank of Attaya, Seneca%^RESET%^");
   set_long("%^BOLD%^Bank of Attaya, Seneca%^RESET%^\n"+
      "This beautiful structure is made of highly polished "+
      "%^ORANGE%^wood%^RESET%^ that gives the room a soft "+
      "%^BOLD%^glow%^RESET%^.  Stairs to the right and left "+
      "are lined with exquisite %^BOLD%^%^BLUE%^blue runners "+
      "%^RESET%^edged in %^BOLD%^%^RED%^red%^RESET%^ and lead up "+
      "to a wide %^ORANGE%^balcony %^RESET%^near the %^CYAN%^"+
      "ceiling%^RESET%^ that overlooks the room below.  The "+
      "sloped ceiling is made from a mixture of %^ORANGE%^wooden "+
      "%^RESET%^and %^CYAN%^glass %^RESET%^panels, which alternate "+
      "to give a perfect view of the %^BOLD%^%^CYAN%^sky %^RESET%^"+
      "over Seneca.  Beginning at the door is a wide %^BOLD%^"+
      "%^BLUE%^carpet %^RESET%^that matches the runners and "+
      "leads to a series of %^ORANGE%^desks %^RESET%^set amid "+
      "the tall %^ORANGE%^wooden columns %^RESET%^that support "+
      "the ceiling.  On one of the desks, you see a %^BOLD%^"+
      "sign %^RESET%^listing the possible transactions here.\n");
/*
@DESC
The %^CYAN%^Bank of Seneca%^RESET%^ is a large multi-story structure where currencies 
from around the globe are exchanged in volumes that would make your 
head spin. Several desks fill the large lobby and a red carpet leads 
you to the general transaction desks. Carved wood pillars hold up a 
roof that is made mostly of glass panels and stained wood. There are 
also two split levels that open up into this room floors above. There 
is a sign detailing possible transactions posted beside each of the 
main desks.
DESC
   );
*/
   set_items(([
      "stairs" : "Wooden stairs on both the right and left ends of the "+
         "large room curve upward to a balcony above.",
      ({"runner","runners"}) : "%^BOLD%^%^BLUE%^Well-made blue runners "+
         "edged in %^RED%^red %^BLUE%^cover the stairs, leaving a small "+
         "section of %^RESET%^%^ORANGE%^wood %^BOLD%^%^BLUE%^visible to either "+
         "side.%^RESET%^",
      "balcony" : "It looks as those some bank business is conducted "+
         "on the balcony above.  It is likely for more lengthy "+
         "transactions such as loans.  The balcony covers only about one-third "+
         "of the room below and has a %^ORANGE%^wooden railing%^RESET%^.",
      ({"ceiling","panels","wooden panels","glass panels"}) : "The ceiling "+
         "is sloped rather than pointed like most roofs.  It is made of "+
         "alternating panels of %^ORANGE%^wood %^RESET%^and %^CYAN%^glass"+
         "%^RESET%^, all of the same size.  The result is that you can see "+
         "the beautiful sky above Seneca even from in here.",
      "carpet" : "Too wide to be called a runner, this carpet nevertheless "+
         "serves the same function.  It is %^BOLD%^%^BLUE%^blue %^RESET%^"+
         "edged with %^BOLD%^%^RED%^red %^RESET%^and bears the %^BOLD%^"+
         "seal %^RESET%^of Seneca in its center.",
      ({"seal","seal of seneca","seal of Seneca"}) : "%^BOLD%^%^BLUE%^A "+
         "trio of %^YELLOW%^golden fleurs-de-lis "+
         "%^BLUE%^are arranged in an inverted pyramid on a shield of blue edged "+
         "in %^RED%^red%^BLUE%^.%^RESET%^",
      ({"desk","desks"}) : "There are five matching wooden desks spread "+
         "in a neat arc around the room.  Tellers at any of them can "+
         "help you with your transactions.",
      "tellers" : "Several tellers are available to help you "+
         "with your banking needs.",
      ({"column","columns"}) : "%^ORANGE%^Square wooden columns rise in "+
         "orderly rows to help support the ceiling far above.%^RESET%^",
      "sign" : "Reading the sign will instruct you in how to use the bank."
   ]));
   set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   set_smell("default","The metallic fragrance of coins merges with the clean scent of the ocean.");
   set_exits( ([
      "north" : ROOMS"street3"
   ]) );
}

void reset(){
   ::reset();
   if(!present("teller")) new(MON"bank_teller")->move(TO);
   if(!present("guard")) new(MON"city_guard")->move(TO);
}
