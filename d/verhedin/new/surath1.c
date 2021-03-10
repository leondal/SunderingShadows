// A pretty little yard
// Thorn@ShadowGate
// 010117
// New City, Verhedin

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/verhedin/include/city.h"

inherit VAULT;

void create() {
  ::create();
  set_property("light", 0);
  set_property("indoors", 1);
  set_short("%^BOLD%^GREEN%^A pretty little yard%^RESET%^");
  set_long(
@THORN
%^BOLD%^GREEN%^A pretty little yard%^RESET%^
You are in a very pretty little yard surrounded by a wrought-iron fence. 
Here you can walk up a path set with flowers and shaded by willows to a 
white house with carved shutters and an ornate verandah which appears to 
have a decent view of the street.

The wrought-iron fence has an iron gate in it where you can gain access 
to the street beyond.
THORN
  );
  set_smell("default", "You can smell the scent of a river amongst the flowers.");
  set_listen("default", "You hear only the wind rustling the willows.");
  set_items(([
    "fence" : "It is a heavy, but artfully crafted fence with ornamental spikes "
              "topping it off.  Of course, ornamental does not mean they won't "
              "seriously hurt you if you tried to climb the fence.",
    "path"  : "Simply a path of stones set into the ground that is lined with "
              "flowers and flowering bushes. ",
    "house" : "This is a fairly elegant looking house for the city,  "
              "actually having a small, private yard and a nice verandah.  "
              "Likely, this is the city home of a petty noble or a wealthy merchant."
  ]));
  set_exits(([
    "gate" : VNEW+"agd1",
    "house" : VNEW+"surath2"
  ]));
  set_door("gate",VNEW+"agd1","gate","surath key");
  set_open("gate",0);
  set_locked("gate",1);
  VNEW+"agd1"->set_open("gate",0);
}

void reset(){
  ::reset();  
}