// General store storage -- Yves
#include <std.h>
#include "/d/common/common.h"
#include "../argabbr.h"

inherit "/d/common/inherit/gs_storage";

void create() {
  ::create();
    set_property("no teleport",1);
    set_exits( (["up" : PATH+"platform24"]) );
}

void reset() {
  ::reset();
}

