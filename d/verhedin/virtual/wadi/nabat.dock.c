// Nabat Ferry Dock on the Wadi
// al-Emir, Verhedin Province
// Thorn@ShadowGate
// 12 June 2000
// nabat.dock.c

#include <std.h>

#define FERRY "/d/verhedin/virtual/wadi/obj/nabatferry"

inherit "/d/verhedin/virtual/wadi/dock.c";

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create() {
  set_indoors(0);
  ::create();
  set_light(2);
  set_short("Nabat Ferry, Verhedin Province");
  set_long(
@THORN
%^BOLD%^Nabat Ferry, Verhedin Province%^RESET%^
  The Imperial Northern Highway abruptly starts from here, at a
large dock facing a wide river.  An inscription on an obelisk
written in ten languages proclaims this place to be Nabat Ferry,
a dock which serves boats coming up the Wadi al-Emir from the
great city of Verhedin to the south.  The Wadi al-Emir itself means
River of the Lord, and it truly appears to be a large waterway.
  The Imperial Northern Highway stretches from here into the
distance where it becomes a thin ribbon of brown against the
mountains of Azha Province to the north.
THORN
);
  set_exits(([
        "north" : "/d/verhedin/north/road1"
  ]));
  set_smell("default","You smell the flora and fauna of the river ahead.");
  set_listen("default","You hear the water lapping up against the dock.");
  find_object_or_load(FERRY)->move(TO);
}

