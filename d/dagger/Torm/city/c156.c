#include "../tormdefs.h"
inherit TOWN;
void create(){
  ::create();
  set_short(
  "Hidden ladder"
  );
  set_property("indoors",1);
  set_long(
  "You are in a hidden passageway in the mansion that is the Torm townhall."
  "  There is a ladder set in the wall that allows movement."
  "  A hidden hatch allows you to leave undetected into the room it leads to."
  );
  set_exits(([
  "ladder":TCITY+"c157",
  "hatch":TCITY+"c154",
  ]));
  set_items(([
  "walls":"The walls here are dull grey stone.",
  "floor":"The floor here is rough grey stone.",
  ({"ceiling","roof"}):"The ceiling here is rough grey stone.",
  "ladder":"This metal ladder is firmly attatched to the wall.",
  ]));
}
