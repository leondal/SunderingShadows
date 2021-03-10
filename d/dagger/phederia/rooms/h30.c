#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
  "%^BOLD%^%^BLACK%^"
  "Dead-end in the Hedge Garden."
  );
  set_long(
  "%^BOLD%^%^BLACK%^"
  "Dead-end in the Hedge Garden.\n"
  "%^RESET%^%^GREEN%^"
  "  The path ends suddenly here as the hedges have grown across the path."
  "  Far beyond a mass of hedges you can see the walls and towers of a fortress rise into the gloomy sky."
  "  The hedges looked like once a beautiful garden now choaked and overgrown with brambles that seem to quiver as you draw near."
  "  The sense of decay and rot hang heavy in the air as if something in it was poisoning the landscape."
  "\n"
  );
  set_smell("default",
  "You smell rotting vegitation."
  );
  set_listen("default",
  "The hedges rustle behind you."
  );
  set_items(([
  "fortress":"A fortress is barely seen over the high walls of the hedges.   Once a beutiful rose colored quartz it looks now like granite with dried blood stains.",
  "hedges":"Once finely kept its now over grown and thick with thorny brambles.   They quiver when anything comes near almost reaching out for them.",
  "ground":"Once a cobbled path its now broken as the creeping roots from the hedges claw through it.",
  "ceiling":"You're outside.  Its called a sky.",
  "sky":"A greyness has cloaked the skies above you seeming to try to flatten this damned place.",
  "floor":"You're outside.   Its called the ground.",
  "brambles":"Thorny protrusions from the hedges seem withered and gray but seem to twitch as you draw close.",
  ]));
  set_exits(([
  "south":ROOMS"h31.c",
  ]));
  set_pre_exit_functions(({
  "south"
  }),({"stick_em"}));
}
int stick_em(){
  tell_object(TP,"%^RESET%^%^GREEN%^The blambles claw at you as you try to leave this enclosed area!\n");
  tell_room(ETP,"%^RESET%^%^GREEN%^As "+TPQCN+" goes to leave this dead-end he seems to get to close to a bramble which scratches him!\n",TP);
  TP->do_damage("torso",roll_dice(1,6));
  if(random(20)>18){
  tell_object(TP,"%^RESET%^%^GREEN%^The scratches burn terribly.\n");
  tell_room(ETP,"%^RESET%^%^GREEN%^"+TPQCN+" scratches at the red marks on his skin from the brambles cursing under his breath.\n",TP);
  TP->add_poisoning(random(25)+1);
  }
  return 1;
}
