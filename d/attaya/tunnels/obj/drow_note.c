#include <std.h>
inherit OBJECT;


void create(){
      set_name("paper");
      set_id(({"paper", "note", "page"}));

      set_short("wadded piece of paper");
      set_long("a filthy, wadded piece of paper, covered with %^RED%^blo"
              +"%^BOLD%^%^RED%^o%^RESET%^%^RED%^d%^RED%^ and %^BOLD%^"
              +"%^BLACK%^drow s%^RESET%^p%^ORANGE%^i%^BOLD%^%^BLACK%^t"
              +"%^RESET%^. It is still just about readable, though."); 
      set("read","Vashud unglazzaraz ngzn rnkazn dzuglrruzchn klepux."
                +" Shnaagh glt unz praalng glt xak vashud munz znch bhag"
                +" grah vashud prollx burrzazn. Uncuntunxlar glaxx slarn"
                +" glt ng minxadzn.\n\n"

                +"The drow was found wandering around. Gut it and burn it"
                +" at the stake if you want the meat cooked. Either way"
                +" make sure it is shared out.");
      set("language", "common");
      set_lore("The strange language at the top of the note sounds like"
               +" the infernal tongue of one of the lower Hells!");
   	set_property("lore difficulty",31);
   	set_weight(2);
   	set_value(200);
}

