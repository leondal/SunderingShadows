#include <std.h>
#include "/d/islands/japan/def.h"

inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create() {
set_indoors(1);
 ::create();
set_light(2);
 set_short("A newly built dock");
 set_long(
@TECHEN
Strange Harbour
This dock is strange in the fact that there are many boats, but each
of them are placed in an order.  The larger ships float in the distence
while the smaller ones are tied to the dock itself.
TECHEN
);
set_exits(([
"north":EXIT "plain-1",
"west" :EXIT "plain-2",
"east" :EXIT "plain-3",
]));
set_smell("default","You smell the salty ocean air carry across this
dangerous land.");
find_object_or_load("d/shadow/virtual/sea/obj/ferryboat2")->move(TO);
set_listen("default","You hear the sounds of waves crashing against the
sandy beaches.");
}
