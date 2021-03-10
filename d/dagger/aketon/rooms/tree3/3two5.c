#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "There is a large window on the west wall that lets light into the"+
   " room. There is a large cushioned chair sitting near the window"+
   " with a wooden stand that has circular piece of lace stretched"+
   " across it. The lace is apparently the latest project, and someone"+
   " is carefully adding delicate pink roses into it. There is a"+
   " dresser on the north side of the room with a large closet full"+
   " of many fine clothes next to it. On the south side of the room"+
   " is a mannequin dressed in a half-finished gown of green silk."+
   " A painting of a bunny rabbit hangs on the south wall.");
   set_smell("default","The room smells pleasantly of warm apples and cinnamon.");
   set_listen("default","The wind rustles through the leaves outside.");
   set_items(([
   "window" : "%^BOLD%^%^CYAN%^There is a large window on the west"+
   " wall that is the only source of light for this room. It has a"+
   " beautiful view that overlooks some of the other trees of Aketon"+
   " that are to the west and north.%^RESET%^",
   ({"chair","padded chair"}) : "There is a large wooden chair that"+
   " is very padded, the seat, back, and even the arms are covered"+
   " in soft cushions. It is probably easy to work or sleep in that"+
   " chair for long periods of time.",
   ({"stand","wooden stand"}) : "There is a wooden stand that holds a"+
   " circular piece of lace stretched tightly in the center. The"+
   " edges of the fabric are held smoothly down so that they do not"+
   " wrinkle or tear, and the material can easily be removed with"+
   " a new piece placed again. It is a simple and yet convenient"+
   " item for those who like to do needlepoint.",
   ({"lace","project"}) : "%^BOLD%^There is a circular piece of white"+
   " lace stretched out over a wooden stand. Several %^MAGENTA%^pink"+
   " roses%^WHITE%^ have been added with slender strands of silk,"+
   " but it is not yet finished. It is quite beautiful, however.%^RESET%^",
   "dresser" : "There is a long dresser with a mirror attached to it"+
   " that leans against the wall. Carefully tucked inside the drawers"+
   " are many different colors and types of silk, as well as several"+
   " bolts of fabric.",
   "closet" : "A large closet sits near the dresser in the northeast"+
   " corner of the room. It holds many dresses, skirts, and tops, all"+
   " of which have had their own special touches added here and there.",
   ({"mannequin","gown","silk gown","green silk gown"}) : "%^BOLD%^%^GREEN%^A mannequin is standing in the southwest corner with"+
   " a half-finished gown of green silk draped over it. The piece"+
   " is definitely a work in progress, but it will be lovely when"+
   " it's finished.%^RESET%^",
   ({"bunny","rabbit","painting","south wall"}) : "There is a painting"+
   " that hangs on the south wall of a cute little bunny rabbit. The"+
   " rabbit is a white cotton tail with a few brown patches and it"+
   " is chewing on a large carrot.",
   ]));
   set_exits( (["east":RPATH3+"3two6"]) );
}
