#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "This is a pleasant living room in an elven home. In the center of"+
   " the room is a large wooden chair with a padded seat and back that"+
   " is covered in needlepoint. In front of the chair is a cherry wood"+
   " coffee table, and on the north and south sides of the coffee table"+
   " are two couches. Against the north wall is a cherry end table"+
   " with several woodland statues atop it. Hung on the south wall is"+
   " a very large oil painting of a mountain lake. There is a doorway"+
   " to the west.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","The wind rustles through the leaves outside.");
   set_items(([
   ({"chair","wooden chair"}) : "There is a large cherry wood chair"+
   " that has a padded back and seat. Dainty needlepoint has been"+
   " stitched into the padding to show several pink roses against a"+
   " light blue background.",
   ({"coffee table","cherry coffee table"}) : "A cherry wood coffee"+
   " table is in the center of the room. It is flanked by two medium"+
   " sized couches and a chair sits at the far end.",
   ({"couch","couches"}) : "%^BOLD%^%^MAGENTA%^The couches are both"+
   " a pretty shade of mauve. They look like they could fit two people"+
   " each and they are very well padded.%^RESET%^",
   ({"end table","cherry end table"}) : "There is a cherry end table"+
   " against the north wall. Sitting on top of it are several soapstone"+
   " statues of woodland animals.",
   ({"statues","woodland statues"}) : "That statues are carved from"+
   " soapstone. You see a beaver, a pig, a bear, a buck, and a wolf."+
   " They are not very big but they were done in good detail and the"+
   " features are well polished.",
   ({"south wall","painting","oil painting","lake","mountain lake"}) : "On"+
   " the south wall is hung a very large oil painting of a serene"+
   " mountain lake. It is approximately eight feet long and six feet"+
   " deep. The lake is still, with only a few ripples in it from a doe"+
   " that is bent over and drinking from it. The mountains rise high"+
   " in the background, and there are berries and shrubs around the"+
   " lake, along with several other hidden animals. You notice a fox"+
   " on the opposite side, and upon close inspection discover a"+
   " mountain lion that is creeping through the bushes.",
   ]));
   set_door("cherry door",RPATH3+"3two1","southeast",0);
   set_exits( (["southeast":RPATH3+"3two1",
      "west":RPATH3+"3two5"]) );
}
