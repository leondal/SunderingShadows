#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("tonovi sign");
   set_short("A massive marble sign");
   set_id(({"sign","sign post","marble sign"}));
   set_long(
      "This massive sign is made of %^BOLD%^%^BLACK%^deep "+
      "ebony %^RESET%^shot through with veins of "+
      "%^YELLOW%^gold%^RESET%^.  The front has been smoothed "+
      "and polished to a high %^BOLD%^shine%^RESET%^, while "+
      "the back and sides have been left in the rough.  "+
      "The laws of Tonovi have been etched into the front "+
      "and inlaid with %^YELLOW%^gold%^RESET%^.  You should "+
      "most definitely read them before going any further."
   );
   set_weight(1000000);
   set_property("no animate",1);
   set_value(0);
}

void init(){
   ::init();
   add_action("read_me","read");
}

int read_me(string str){
   if(!str) return 0;
   if(!id(str)) return 0;
   tell_object(TP,"You read over the laws carved into the marble sign.");
   tell_room(ETP,""+TPQCN+" reads the laws on the marble sign.",TP);
   TP->more("/d/dagger/tonovi/obj/tonovi_laws");
   return 1;
}