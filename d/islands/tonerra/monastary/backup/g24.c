
#include <std.h>
#include "/d/islands/tonerra/monastary/short.h"
inherit ROOM;


void create(){
object ob;
:: create();

set_light(2);
set_indoors(1);
set_short("
%^GREEN%^Monastary Garden.
");
set_long(
@SEETH
%^BOLD%^%^GREEN%^You are in a beautiful garden. There are many bushes with flowers
of all sorts of colors. Everything looks so very green. The grass is
magnificent in color and texture. After your done admiring the area, you
begin to walk through the path of the dirt road and stone tiles. With 
closer inspection of the stone tile path, you notice that the tiles are 
shaped as scales of an ancient chinese dragon. You notice that it's strange
having a garden within a volcanoe. There must be some unknown artificial
sunlight, as you look up and see the rocky interior of the volcanoe.
SEETH
);

set_items(([
"path" : "The path is lead by the stone tiles in the form os an ancient dragon. This part of the path is in the shape of the dragon's torso, which leads towards the head.",
"bushes" : "Many assorted flowers are found in the bushes.",
"tiles" : "They are stone tiles in a shapes of scales of an ancient dragon. You may look at the path to see what part of the dragon you are on.",
]));

set_exits(([
"southwest" : RPATH "g18.c",
"east" : RPATH "g25.c",
]));

set_smell("default", "The air is wonderfully clean and refreshing.");

}
