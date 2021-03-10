#include <std.h>
#include "/d/common/common.h"

inherit "/d/common/inherit/wpn_storage_full.c";

void create() {
  ::create();
    set_exits( (["up" : "/d/shadow/room/city/weapon"]) );
}

void reset() {
  ::reset();
}

