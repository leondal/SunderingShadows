//  Created by Grolim, for ShadowGate
//  Coded 18 Jun, 1995
//  Forest around Antioch

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set("short","Before the gate."
     );
  set("long","You are before a huge gate. "
    );
  set_exits( ([
    "south": "/d/antioch/virtual/antiforest/1,6.antiforest",
    ]) );
}

void init() {
  ::init();
}
