#include <std.h>

inherit "/d/common/inherit/gs_storage";

void create() {
  ::create();
   set_property("no teleport",1);
   set_properties((["light":1, "indoors":1]));
}
