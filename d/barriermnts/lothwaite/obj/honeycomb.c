//honeycomb.c - Object for Lothwaite.  Circe 2/14/04
#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("honeycomb");
   set_short("%^RESET%^%^ORANGE%^A sticky honeycomb%^RESET%^");
   set_id(({"honeycomb","comb","honey","honey comb","wax","beeswax"}));
   set_long(
@CIRCE
%^ORANGE%^This thick section of a beehive is made of %^WHITE%^pale wax %^RESET%^%^ORANGE%^dripping with thick, gooey %^YELLOW%^honey%^RESET%^%^ORANGE%^.  The wax has been formed into tiny cells shaped like hexagons that seem to run the width of the honeycomb.  In its raw form like this, the honeycomb is of little use other than getting your hands extremely sticky.  Should you know someone who works with wax or honey, however, it might fetch a nice price.
CIRCE
   );
   set_weight(3);
   set_value(750+random(251));
}

void init(){
   ::init();
   add_action("eat","eat");
}

int eat(string str){
   if(!str) return 0;
   if(str != "comb" && str != "honeycomb") return 0;
   tell_object(TP,"You probably don't want to eat that like it is...bug guts.  Eww.");
   return 1;
}