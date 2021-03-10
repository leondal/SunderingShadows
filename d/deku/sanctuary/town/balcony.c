#include <std.h>
#include "../dragon.h";


inherit BTOWN;

void create() {
   ::create();
   set_property("light",0);
   set_property("indoors",1);
   set_short("Ruined church");
   set_long(
      "%^BOLD%^%^BLACK%^This is the balcony overlooking the inside of the ravaged temple. There are several"+ 
      " broken benches scattered around what was once the city church. Along the back wall is a"+
      " huge violated organ with most of the pipes missing or broken. You"+
      " would guess that it used to fill the entire church with music. Looking"+
      " over the balcony you see the magnitude of the damage done to the temple below"+ 
      " and the sight is overwhelming."
   );
   set_exits(([
       "down" : TOWN+"church"
   ] ));
   set_items(([
   ] ));
}
