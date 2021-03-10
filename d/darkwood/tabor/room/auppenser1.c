#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
  ::create();
  set_travel(RUTTED_TRACK);
  set_terrain(OLD_MOUNTS);
  set_light(2);
  set_indoors(0);
  set_name("A faint footpath");
  set_short("A faint footpath");
  set_long(
     "This path can barely be distinguished as one at a "+
     "quick glance.  Boulders and rubble impede your step, "+
     "making it clear that this path has fallen into disrepair.  "+
     "The travel up the mountainside is steep, though it seems "+
     "to be winding its way toward some goal.  Gazing upward, "+
     "the path becomes more clearly defined as it zigzags its "+
     "way up the steep mountain face.\n"
    );
  set_exits(([
    "east" : "/d/koenig/streams/path7",
    "north" : ROOMDIR+"auppenser2"
  ]));
  set_listen("default","The mountain air is crisp and cool.");
  set_smell("default","The wind whistles through the mountains.");
  set_items(([
     ({"boulder","boulders","rubble","rocks"}) : "Rubble strewn "+
        "along the path hints at its lack of use.  Large boulders "+
        "force the trail to skirt around in a few places, though "+
        "passage is still not treacherous.",
     ({"mountain","mountainside","goal"}) : "It is unclear what "+
        "the trail is leading to.  The mountainside here is rather "+
        "steep, making travel difficult."
  ]));
}
