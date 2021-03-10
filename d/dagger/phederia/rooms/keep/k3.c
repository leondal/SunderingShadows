#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
  "Above the main gates on the walls."
  );
  set_long(
  "Above the main gates on the walls.\n"
  "  You stand on the walls above the gatehouse that leads from the hedges outside to the keep."
  "  A grey gloom hangs over the hedges and hey fade into the distance almost as if embarassed to be seen and taking the horizon with them till you cant tell where the grey sky ends in the distance."
  "  The walls continue north and to the south where you can see stairs leading down to the courtyard."
  "  A black shadow drifts about on the ground in front of the gates reminds you of the undead knight who prevents the new residents from leaving."
  "\n"
  );
  set_smell("default",
  "You can smell the musty oder of the hedges drifting up to you."
  );
  set_listen("default",
  "You can hear the faint clank of the knighs footsteps below you and the screetches of the apes far out in the hedges."
  );
  set_items(([
  "hedges":"You shudder as you think about walking back out past those white apes.",
  "knight":"Endlessly pacing he waits to be laid to rest.",
  "keep":"Its rose walls look like blood dried on granite under the gloom that over shadows everything.",
  "stairs":"To your south you see stairs leading back down to the courtyard.",
  "courtyard":"A few outbuildings lay against the walls and a fountain and private garden are between you and the inner keep.",
  "fountain":"The fountain outside the gates and the in in the courtyard seem identical.",
  "garden":"The garden looks withered and dead although at one time it must of been quite beautiful.",
  ]));
  set_exits(([
  "north":KEEP"k4.c",
  "south":KEEP"k42.c",
  ]));
}
