#include <std.h>
#include "../dragon.h";


inherit BTOWN;

void create() {
   ::create();
   set_property("light",0);
   set_property("indoors",1);
   set_short("Ruined church");
   set_long(
      "%^BOLD%^%^BLACK%^You're inside the %^RESET%^%^CYAN%^Temple of Alphonsus%^BOLD%^%^BLACK%^. The temple is just as ruined as the"+
      " rest of town. The stained glass windows have been knocked out of the west and"+
      " east walls of the church. This church could have easily held 1000 people, but"+
      " all the seats have been ripped asunder. Looking in the back"+
      " of the church you see a large balcony that has somehow managed to not come crashing down."+
      " Toward the north, you see a large hole in the wall of the church that leads out to the graveyard."+  
      " There is also a set of stairs leading up to the balcony, but you are not sure how sturdy they are."
   );
   set_exits(([
      "up" : TOWN+"balcony",
      "down" : TOWN+"healer",
      "south" : TOWN+"roadW4",
      "hole" : TOWN+"grave8"
   ] ));
   set_items(([
   ] ));
}

