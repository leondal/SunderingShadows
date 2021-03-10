#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
  "%^BOLD%^%^BLACK%^Before the fortress."
  );
  set_long(
  "%^BOLD%^%^BLACK%^Before the fortress.\n"
 "%^RESET%^%^GREEN%^"
  "  You finally stand at the gates of the rose fortress."
  "  A large fountain sits here, once gracing the entrence way along where the path should of lead straight west from here to the entrence to the hedges, now just looking more like a headstone to this dying place."
  "  The hedges looked like once a beautiful garden now choaked and overgrown with brambles that seem to quiver as you draw near."
  "  The sense of decay and rot hang heavy in the air as if something in it was poisoning the landscape."
  "  The ground near the fountain seems soaked with old dried blood where the vines and creepers havent managed to drain it yet from beneath the feet of the knight who stands there."
  "\n"
  );
  set_smell("default",
  "You smell rotting vegitation."
  );
  set_listen("default",
  "The still dead air carries the faint sound of something screeching."
  );
  set_items(([
  "fortress":"The Rose fortresses gates stand closed.   You can see figures on the battlements watching the clearing here with interst.",
  "figures":"Dark cloaked figures keep close to the battlements to avoid any close inspection.",
  "gates":"Massive gates bound in dark steel and sturdy wood.   They're barred from the other side.",
  "hedges":"Once finely kept its now over grown and thich with thorny bramlbes.  You notice the creepers neer the roots are wrapped around something.",
  "creepers":"The roots of the hedges are wrapped around desicated corpses barely recognizable as once being humanoid.",
  "corpses":"Dismembered and now drained entirely of blood.   The draining probably from the creepers and the dismembering from the flamberge in the knights hands.",
  "ground":"Once a cobbled path its now broken as the creeping roots from the hedges claw through it.  Blood stains the cobbles near the fountain.",
  "blood":"Old blood lays pooled around the base of the fountain where the knight patrols and even the creepers seem anxios to stay out of his way.",
  "ceiling":"You're outside.  Its called a sky.",
  "sky":"A greyness has cloaked the skies above you seeming to try to flatten this damned place.",
  "floor":"You're outside.   Its called the ground.",
  "brambles":"Thorny protrusions from the hedges seem withered and gray but seem to twitch as you draw close.",
  ]));
  set_exits(([
  "north":ROOMS"h75.c",
  "west":ROOMS"h56.c",
  "gates":KEEP"k2.c",
  ]));
  new(OBJ"fountain.c")->move(TO);
  new(MON"knight.c")->move(TO);
}
