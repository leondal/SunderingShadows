#include <std.h>

inherit "/d/deku/inherits/vexia-lair";

int open;

void create() {
    ::create();
    set_short("Vexia's Well");
    set_long(
@KAYLA
The air in this chamber is very cool and damp.  The walls are 15 ft. high
and curve into an arched ceiling.   In the center of the floor is a 6 ft.
diameter hole that descends into darkness beyond your vision.
KAYLA
    );
    set_exits(([
       "west" : "/d/deku/open/cave_r3i",
       "east" : "/d/deku/open/air"
    ] ));
    set_items(([
      "hole":"On closer inspection you see it opens into a well.",
      "well":"The well drops 80 ft. to an underground pool of fresh water."
          "  There doesn't appear to be a way into it but maybe you should "
          "try to search it anyway."
    ] ));
    open = 0;
}

void init() {
  ::init();
  add_action("search","search");
}

int search(string str) {
  if(!str) {
    write("%^RED%^ Search what?");
    return 1;
  }
  if (str != "well" && str != "hole") {
    write("You cannot search that!");
    return 1;
  }
  if(open) {
    write("It looks like someone already searched the well.");
    return 1;
  }
  open = 1;
  write("%^BOLD%^%^BLACK%^You search the well and find..");
  tell_room(ETP, "%^BOLD%^%^BLACK%^"+TPQCN+" searches the well and finds...", TP);
  new("/d/deku/monster/shadow")->move(TO);
  if(!random(3))   new("/d/deku/monster/shadow")->move(TO);
  return 1;
}

void reset() {
  ::reset();
    if(open && !random(2)) open = 0;
}
