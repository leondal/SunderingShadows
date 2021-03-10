#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",3);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "This is the formal dining room of one of the elven homes. There"+
   " is a long rectangular table in the center of the room with place"+
   " seatings for eight. A pretty flower arrangement sits in a porcelain"+
   " vase in the middle of the table. A crystal chandelier hangs down"+
   " from the ceiling over the center of the table, it constantly"+
   " sparkles with mage lights instead of real flames. On the south wall"+
   " of the room is a large cabinet filled with dishes and other"+
   " porcelain plates and pretty, delicate objects. On the west a"+
   " partially closed curtain is hung, revealing a counter and sink as"+
   " well as a stove. The curtain could easily be closed all the way to"+
   " separate that section from the rest of the dining room.");
   set_smell("default","The room smells faintly of nutmeg.");
   set_listen("default","The wind rustles through the leaves outside.");
   set_items(([
   ({"table","dining table"}) : "A large oak dining table takes up"+
   " most of the room, with place seatings laid out for eight people."+
   " A beautiful flower arrangement sits in the center of the table"+
   " in a painted porcelain vase.",
   ({"chandelier","crystal chandelier"}) : "A crystal chandelier hangs"+
   " down over the center of the table. It is created from a golden"+
   " metal and hung by a linked chain from the ceiling. It spreads"+
   " out like a flower with five pretty petals coming to points. Mage"+
   " lights glow softly on the inside, causing the crystals to sparkle"+
   " and dance light over the rest of the room.",
   ({"flower arrangement","flowers"}) : "A lovely flower arrangement"+
   " is in the center of the dining room table. It is made up of"+
   " %^BOLD%^%^CYAN%^blue hydrangeas%^RESET%^, %^YELLOW%^daffodils%^RESET%^,"+
   " %^BOLD%^white carnations%^RESET%^, and some decorative"+
   " %^BOLD%^%^GREEN%^ferns%^RESET%^. It lights up the room well.",
   ({"vase","porcelain vase"}) : "A porcelain vase holds a large"+
   " arrangement of flowers in the center of the dining room table."+
   " The edges of the mouth of the vase are rimmed in gold. Painted"+
   " on the front and back is the image of a nightingale on a branch."+
   " The detail is exquisite and the bird is beautiful.",
   ({"cabinet","dishes","plates"}) : "There is a large cabinet on the"+
   " south side of the room. The top half simply has two glass doors"+
   " and the glass has been etched around the edges with rose buds."+
   " The dishes themsleves are beautiful and they are all decorated"+
   " with bluish purple hydrangeas and ivy. You notice a large serving"+
   " tray, a deep bowl, and a tea pot with dainty cups.",
   ({"counter","sink"}) : "On the west side of the room is a counter"+
   " with a sink. It is obviously for preparing food for the large"+
   " gatherings, and the space is kept neat and tidy.",
   "stove" : "There is a stove on the west side of the room that"+
   " must be heated by magic for you see no place to hold a fire"+
   " beneath it.",
   "curtain" : "There is a large blue curtain that is currently pulled"+
   " half-way back to reveal the small kitchen area where the food is"+
   " prepared. During dinners it can be completely closed to cut off"+
   " that section of the room.",
   ]));
   set_exits( (["north":RPATH3+"3two18"]) );
}
