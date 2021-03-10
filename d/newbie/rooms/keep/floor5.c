#include <std.h>
#include "../inherit/keep.h"
inherit VAULT;

int FOUND;

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_name("A large study");
   set_short("%^CYAN%^A large study");
   set_long("%^CYAN%^A large study%^RESET%^\n"
"You have entered a sizeable study room, with %^ORANGE%^bookshelves %^RESET%^"
"lining the entirety of two walls, the south and east.  A large walnut "
"%^RED%^desk %^RESET%^obscures most of the northern wall, set with a matching "
"%^RED%^chair%^RESET%^.  There are several %^YELLOW%^candle stubs %^RESET%^on "
"the desk, along with some %^BOLD%^%^WHITE%^parchment %^RESET%^and a dried-up "
"%^BLUE%^inkwell%^RESET%^.  A %^CYAN%^painting %^RESET%^hangs above the desk, "
"and a thick wool %^GREEN%^rug %^RESET%^lies across the centre of the floor.  "
"One thing you notice is that nothing in the room appears to be aged or covered "
"in dust, like the rest of the ruined keep.\n");
   set_smell("default","The smell of parchment fills the room.");
   set_listen("default","Everything is fairly quiet here.");
   set_items(([
     ({"floor","rug","wool rug"}) : "%^GREEN%^The floor is fairly free of dust, "
"obscured across the centre by a large wool rug.  It has been dyed a deep "
"forest-green hue, and looks incredibly thick and soft.%^RESET%^",
     ({"desk","chair","inkwell","quill","parchment"}) : "%^RED%^The walnut desk "
"and accompanying chair are in excellent condition, which is surprising when "
"one considers the state of the rest of the keep.  There are still a few sheets "
"of parchment on top, along with a dried up inkwell and quill.  Several candle "
"stubs that have been burned down to nothing attest to the fact that this desk "
"must have been used at one point.  There are also a couple of drawers on one "
"side of the desk.  Perhaps you could %^YELLOW%^search %^RESET%^%^RED%^them to "
"see what they hold?%^RESET%^",
     "drawers" : "%^RED%^The desk has a few drawers that are closed.  They "
"probably just hold parchment and other such supplies, but you never know.  If "
"you're really curious you could always try to %^YELLOW%^search %^RESET%^%^RED%^"
"them to see what is inside.%^RESET%^",
     ({"stubs","candle stubs","candles"}) : "%^YELLOW%^There are at least half "
"a dozen candle stubs on top of the desk, but they've been burned down to "
"nothing.%^RESET%^",
     ({"bookshelf","bookshelves","books"}) : "%^ORANGE%^There are two "
"bookshelves here, one on the east and one on the south.  You can pick one to "
"get a closer look if you want, by using %^YELLOW%^look east bookshelf%^RESET%^"
"%^ORANGE%^ or %^YELLOW%^look south bookshelf%^RESET%^%^ORANGE%^.%^RESET%^",
     ({"east bookshelf","eastern bookshelf"}) : "%^ORANGE%^The bookshelf along "
"the eastern wall is filled with many different types of books.  You see some "
"ranging from histories of various lands, to theories of weather, books on "
"plants and animals, and many other more obscure subjects.%^RESET%^",
     ({"south bookshelf","southern bookshelf"}) : "%^ORANGE%^The books on this "
"shelf are mostly large leather-bound volumes.  There appear to be many maps "
"and several books that you assume are of magic, but the runes move around too "
"quickly for you to read.  One particular %^BOLD%^%^BLACK%^black book %^RESET%^"
"%^ORANGE%^on the far side of one of the top shelves stands out.  It is fairly large and "
"is bound entirely in black leather with no title on the spine.  Perhaps you should take a closer look at it?",
     ({"book","black book"}) : "%^ORANGE%^This %^BOLD%^%^BLACK%^black book "
"%^RESET%^%^ORANGE%^stands out among the rest.  It is large and bound in black "
"leather with no title displayed on the spine.  On closer inspection you find "
"that it doesn't really seem to be a book at all, but a carefully hidden "
"%^YELLOW%^lever %^RESET%^%^ORANGE%^that you could %^YELLOW%^pull%^RESET%^"
"%^ORANGE%^!%^RESET%^",
     "lever" : "%^ORANGE%^The %^BOLD%^%^BLACK%^black book %^RESET%^%^ORANGE%^is "
"actually a carefully concealed lever!  Perhaps you should %^YELLOW%^pull "
"%^RESET%^%^ORANGE%^it and see what happens?%^RESET%^",
     "painting" : "%^CYAN%^There is a large and beautiful oil painting on the "
"western wall.  It is of a hedge maze with a large tower in the center of the "
"maze and is hung in a beautiful walnut frame.%^RESET%^",
   ]));
   set_exits(([
     "west" : ROOMS"floor4",
   ]));
   set_door("door",ROOMS"floor4","west",0);
   set_door_description("door","%^ORANGE%^This door is solid and reinforced "
"with metal bars.  It is aged and worn, but still standing.%^RESET%^");
}

void init() {
   ::init();
   add_action("pull","pull");
   add_action("search_fun","search");
}

void reset() {
   ::reset();
   if(member_array("south",TO->query_exits()) != -1) {
     tell_room(TO,"%^ORANGE%^The southern bookshelf slides back into place, "
"closing the secret passage.%^RESET%^");
     remove_exit("south");
     if(member_array("north",ROOMS"floor6"->query_exits()) != -1) {
       tell_room(ROOMS"floor6","%^ORANGE%^A section of the wall slides "
"across to close the northern passage.%^RESET%^");
       ROOMS"floor6"->remove_exit("north");
     }
   }
   FOUND = 0;
}

int pull(string str) {
   if(str != "book" && str != "lever") return notify_fail("Pull what?\n");
   if(member_array("south",ETP->query_exits()) != -1) {
     tell_object(TP,"%^ORANGE%^You pull the lever and the bookshelf slides shut "
"and closes the secret passage.%^RESET%^");
     tell_room(ETP,"%^ORANGE%^"+TPQCN+" pulls a hidden lever and the bookshelf "
"slides shut and closes the secret passage.%^RESET%^",TP);
     remove_exit("south");
     ROOMS"floor6"->remove_exit("north");
     tell_room(ROOMS"floor6","%^ORANGE%^A section of the wall "
"slides across to close the northern passage.%^RESET%^");
     return 1;
   }
   else {
     tell_object(TP,"%^ORANGE%^You pull the lever and the bookshelf slides to "
"the right, revealing a secret passage leading south.%^RESET%^");
     tell_room(ETP,"%^ORANGE%^"+TPQCN+" pulls a hidden lever and the bookshelf "
"slides to the right, revealing a secret passage leading south.%^RESET%^",TP);
     add_exit(ROOMS"floor6","south");
     ROOMS"floor6"->add_exit(ROOMS"floor5","north");
     tell_room(ROOMS"floor6","%^ORANGE%^The northern wall slides to the "
"side to reveal a way out of the passage.%^RESET%^");
     return 1;
   }
}

int search_fun(string str) {
   if(!str) {
     tell_object(TP,"%^ORANGE%^You take a careful look around the room.  It "
"is oddly clean here, unlike the rest of the keep.  The %^YELLOW%^desk "
"%^RESET%^%^ORANGE%^and the %^YELLOW%^bookshelves %^RESET%^%^ORANGE%^look "
"particularly interesting.%^RESET%^");
     tell_room(ETP,"%^ORANGE%^"+TPQCN+" takes a look around the room"
".%^RESET%^",TP);
     return 1;
   }
   if(str == "desk" || str == "drawers") {
     if(FOUND) {
       tell_object(TP,"%^ORANGE%^You search through the drawers and find "
"nothing of interest, but it does appear as though someone has already "
"searched through here recently.%^RESET%^");
       tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches through the desk's "
"drawers but doesn't seem to find anything.%^RESET%^",TP);
       return 1;
     }
     tell_object(TP,"%^ORANGE%^You search through the drawers and find a "
"rather oddly shaped stone.%^RESET%^");
     tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches through the drawers and "
"appears to find something.%^RESET%^",TP);
     new(OBJ2"stone")->move(ETP);
     FOUND = 1;
     return 1;
   }
   if(str == "bookshelves") {
     tell_object(TP,"%^ORANGE%^You would have to decide if you wish to look "
"at the %^YELLOW%^eastern bookshelf%^RESET%^%^ORANGE%^ or the %^YELLOW%^"
"southern bookshelf%^RESET%^%^ORANGE%^.%^RESET%^");
     return 1;
   }
   return 0;
}
