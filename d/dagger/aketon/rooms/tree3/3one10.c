#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "You are standing in a pleasant home that has been decorated in"+
   " a more ancient style. There are four marble pedestals about"+
   " three feet in height that stand in each corner of the room. The"+
   " two on the western end of the room each hold a ceramic statue of"+
   " a sitting lion. The two on the eastern side of the room hold"+
   " exotic plants. The plant in the northeast corner is a vine with"+
   " purple leaves. The plant on the southeast corner has a reddish"+
   " vine with small white blossoms. In the center of the room is a"+
   " dining table that could seat six but only has four chairs. In"+
   " the center of the table is a chess board with intricately"+
   " carved marble pieces, a game already appears to be in progress,"+
   " although some of the pieces have started to gather dust. On the"+
   " northern wall is a large tapestry of a manticore in flight."+
   " Across from it on the southern wall is a tapestry of an angel"+
   " with wings spread and a holy avenger in its hands. To the"+
   " southwest is another doorway.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","The wind rustles through the leaves outside.");
   set_items(([
   ({"table","dining table"}) : "There is a large rectangular sandalwood"+
   " dining table in the center of the room. It could hold six people,"+
   " but there are only four chairs around it. On one side of the"+
   " table a chess board with detailed marble figurines stands with a"+
   " game already in progress. The game must be taking a very long time"+
   " however, for dust has begun to gather on some of the pieces.",
   "chairs" : "There are four sandalwood chairs surrounding the dining"+
   " table.",
   ({"board","chess board"}) : "There is a chess board on one side of"+
   " the dining table. The pieces are intricately carved of black and"+
   " white marble, but they are not the standard pieces. They seem to"+
   " fit the theme in the room, in place of the standard pawns are fauns,"+
   " the rooks are treants, the knights are manticores, the bishops are"+
   " mermen with tridents, and the queen has fairy wings.",
   ({"pedestals","marble pedestals"}) : "There are four marble pedestals"+
   " in this room, one in each of the corners. The two on the west"+
   " wall have lion statues on top of them, the two on the east wall"+
   " both have plants. The one in the northeast corner has a vine with"+
   " purple leaves, and the one in the southeast corner has a red vine"+
   " with white blossoms.",
   ({"lions","ceramic lions","statues","lion statues"}) : "The lion"+
   " statues are sitting proudly atop the pedestals, a paw is raised on"+
   " each of them, the one in the northwest has the its right paw raised"+
   " and the other one has its left paw raised.",
   "purple vine" : "%^MAGENTA%^This vine is sitting atop the pedestal"+
   " in the northeast corner. It has sent purple tendrils down that"+
   " reach halfway to the floor. It is rather pretty to look at, and"+
   " very unusual.%^RESET%^",
   "red vine" : "%^RED%^There is a red vine on the marble pedestal in"+
   " the southeast corner. It has a fine layer of spikey hair growing"+
   " along the edges of the vine, and the leaves are rimmed in red. It"+
   " has a few tiny %^BOLD%^%^WHITE%^white blossoms%^RESET%^%^RED%^ on"+
   " it that give it a slightly softer look.%^RESET%^",
   ({"manticore tapestry","north wall","northern wall"}) : "There is a"+
   " tapestry of a large manticore in flight on the northern wall."+
   " The colors are very bright and the tapestry is quite life-like,"+
   " you almost expect the manticore to come swooping into the room!",
   ({"angel tapestry","south wall","southern wall"}) : "On the southern"+
   " wall is a beautiful tapestry of an angel holding a holy avenger."+
   " The angel has blonde hair and blue eyes with long white wings"+
   " that are slightly spread. He seems to be standing on a cloud and"+
   " he has a rather determined look on his face, as though he's going"+
   " to go after the manticore any second now.",
   ]));
   set_door("chestnut door",RPATH3+"3one11","east",0);
   set_exits( (["east":RPATH3+"3one11",
      "southwest":RPATH3+"3one15"]) );
}
