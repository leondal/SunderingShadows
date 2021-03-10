#include <std.h>
#include "/d/common/common.h" //adjusted so it would stop throwing errors - was using <> Circe 8/2/19
inherit "/d/common/inherit/gs_storage";

void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
    set("short", "Shadow's General Store Storage Room");
    set("long", "Supplies and such are stored here.\n");
    set_exits( (["up" : "/d/shadow/room/city/gs_store"]) );
}

void reset() {
  ::reset();
}
