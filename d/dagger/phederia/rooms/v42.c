#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_short(
  "Dried pigs pen."
  );
  set_long(
  "Dried pigs pen.\n"
  "  There one used to be a great pool of mud here for the hamlets pigs to wallow about in to escape the heat of the sun."
  "  Now its dried and if you can see any pigs they look near dead from the lack of care."
  "  The road lies back to the east."
  "\n"
  );
  set_smell("default",
  "You smell dried pig manure."
  );
  set_listen("default",
  "What animals you can spot seem to be trying to stay quiet to avoid notice."
  );
  set_items(([
  "building":"Its a low, well constructed pig shack.",
  "fences":"The fences have been knocked down in places.",
  "mud":"Its dried mud.",
  "dried mud":"Its dried mud.",
  ]));
  set_exits(([
  "west":ROOMS"v41.c",
  "east":ROOMS"v7.c",
  ]));
}
