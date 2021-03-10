#include <std.h>
#include "/d/common/common.h"
inherit "/d/common/inherit/gs_storage";

void create() {
  ::create();
    set_exits( (["up" : "/d/shadow/room/city/gs_store"]) );
}

void reset() {
  ::reset();
}
