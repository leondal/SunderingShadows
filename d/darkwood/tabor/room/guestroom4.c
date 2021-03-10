//CNC hallways & rooms by Circe 6/1/04

#include <std.h>
#include "../include/tabor.h"

inherit VAULT;

void create() {
  ::create();
  set_terrain(CITY);
  set_travel(DIRT_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_name("Guestroom of the Crown and Castle, Tabor");
  set_short("Guestroom of the Crown and Castle, Tabor");
  set_long(
"%^BOLD%^Guestroom of the Crown and Castle, Tabor%^RESET%^\n"+
"%^MAGENTA%^This small guestroom has few furnishings.  A large bed with "+
"a %^ORANGE%^chestnut frame %^MAGENTA%^stands with its head against "+
"the southern wall.  Just beside it is a hand-woven %^BOLD%^rug "+
"%^RESET%^%^MAGENTA%^dyed a light shade of %^BOLD%^pink%^RESET%^%^MAGENTA%^.  "+
"A tall chest of drawers is along the eastern wall for guests "+
"to use, and a small nightstand is beside the bed.  Atop the "+
"nightstand is a brass lantern with a glass hood.  The colorful "+
"quilt and the few pictures hanging on the walls give the room "+
"a cozy feel.\n"
  );
  set_smell("default","You smell a faint scent of pine.");
  set_listen("default","You hear the muted babble of the socializing guests.");
  set_items(([
     ({"bed","chestnut bed","frame","chestnut bed frame"}) : "The "+
        "bed is simple but looks very comfortable.  The mattress "+
        "seems to be down-filled, and a thick quilt is on top.  "+
        "The quilt is a %^MAGENTA%^p%^RED%^a%^ORANGE%^t%^YELLOW%^c"+
        "%^RESET%^%^GREEN%^h%^CYAN%^w%^BOLD%^%^BLUE%^o%^RESET%^%^BLUE%^"+
        "r%^MAGENTA%^k %^RESET%^of colors and worked into an interesting "+
        "pattern of interlocked rings.",
     "rug" : "%^BOLD%^%^MAGENTA%^The hand-woven rug beside the bed is large and "+
        "oblong.  It is rather thick and seems well-tended.  It "+
        "helps keep your feet off the cold floor when you get out "+
        "of bed in the morning.",
     "pictures" : "The pictures are mostly of various outdoor scenes.  "+
        "You see pastoral meadows, quiet lakes, old growth forests, and "+
        "fields of wildflowers.",
     ({"drawers","chest of drawers"}) : "The chest of drawers matches "+
        "the chestnut bed frame.  It is a little narrow, but has five "+
        "deep drawers guest could use for storage while they are in "+
        "the room.",
     ({"stand","nightstand","lantern"}) : "The low nightstand sitting "+
        "beside the bed is topped with a lace doily.  Sitting in the "+
        "center of the nightstand is a brass lantern, provided for "+
        "the guests' convenience."
  ]));
  set_exits( ([
    "north" : ROOMDIR+"cnchall4"
  ]) );
  set_door("door",ROOMDIR+"cnchall4","north",0);
  set_door_description("door","This is a solid oak door carved with "+
     "the image of a crown hovering above a castle.");
}
