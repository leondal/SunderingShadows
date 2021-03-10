#include <std.h>

inherit ROOM;

void create() {
::create();
   set_terrain(HEAVY_FOREST);
   set_travel(FOOT_PATH);
set_property("light", 2);
set_short("Road into the woods");
set_long(
"You have come upon a path in the woods.  Not much more than a dirt trail, at first you almost passed by it thinking it was just a deer path, but there are definate marks of human travel, and it looks like at one time there were cobblestones along it.  The forest all around you hides many things from view."
);

set_smell("default", "On the air is the strong scent of pine from the great evergreen trees, which starts to overwhelms you");
set_listen("default", "You can hear the call of a hawk in the distance over the other normal sounds");

set_items( ([
"woods" : "You can't see much on this path, but you think you can see the top of a dome to the southwest, over the treetops.",
"path" : "It is a dirt path, but as you look closer, you get an impression that it was once covered with cobblestones.",
"marks" : "Some of the marks of people are defiantely more recent, but you can recognise much older signs of travel too.",
]) );

set_exits( ([
"northeast" : "/d/dagger/road/stella/sroad2",
"east" : "/d/dagger/road/stella/sroad4",
]) );
}
