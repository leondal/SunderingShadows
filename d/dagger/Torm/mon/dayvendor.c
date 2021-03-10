#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/std/vendor";

create(){
  ::create();
}

void reset(){
  int time;
  ::reset();
  time = "daemon/events_d"->query_time_of_day();
  if(!objectp(TO) || !objectp(ETO)) return;
  if(time == "twilight" || time == "night") {
  if(!random(3)){
  switch(random(4)){
   case 0:
    command("emote packs his things up and leaves in a hurry.");
    break;
   case 1:
    command("say I'll be back in the morning, I'll see you then?");
    break;
   case 2:
    command("emote grumbles something about the 'missus', packs his things onto a pack animal and leaves.");
    break;
   case 3:
    command("say Well time for a cold one, been a long day.");
    command("emote cracks his back and grabs his things before leaving.");
    break;
   }
  run_away();
  TO->move("/d/shadowgate/void");
  TO->remove();
  }
 }
}
