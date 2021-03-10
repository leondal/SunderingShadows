#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/std/monster";
create(){
  ::create();
  set("aggressive",0);
}

void reset(){
  int time;
  ::reset();
  time = "daemon/events_d"->query_time_of_day();
  if(!objectp(TO) || !objectp(ETO)) return;
  if(time == "twilight" || time == "night") {
    if(ETO->query_property("indoors")) return;
    if(!random(3)){
      switch(random(4)){
      case 0:
        command("emote looks at the approaching mist and suddenly decides "+TO->query_subjective()+"'d rather be indoors somewhere.");
        break;
      case 1:
        command("say My look at the time.  Excuse me.");
        break;
      case 2:
        command("emote watches the sun go down, sighs and hurries away.");
        break;
      case 3:
        command("emote picks up "+TO->query_possessive()+" speed and watches over "+TO->query_possessive()+" shoulder at the approaching mist.");
        break;
      }
    run_away();
    TO->move("/d/shadowgate/void");
    TO->remove();
    }
  }
}
