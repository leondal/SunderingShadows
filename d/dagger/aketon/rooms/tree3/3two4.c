#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "This is a serene room that almost seems to have a reverent"+
   " feel to it. On the north wall a miniature stream slowly feeds"+
   " into a tranquil pond that is lined with the smoothed pebbles of"+
   " a river. The water creates a slight tinkling sound as it enters"+
   " the pond. There is obviously magic at work here, for the pond"+
   " never overflows, yet the river never stops pouring into it."+
   " On the east wall hangs a large circle of wood that has been"+
   " painted sky blue a waterfall cascading into a still pool in the"+
   " center and fern leaves surrounding the edges. A wreath of flowers"+
   " and plants has been hung around the wooden circle. There is a"+
   " blue cushion seated in front of the peaceful scene and a large"+
   " scented candle rests in a pewter holder near the wall. An ash"+
   " chest full of priestly robes sits in the southeast corner. On the"+
   " west side of the room a rectangular dining table has been covered"+
   " in a small chemistry lab, with several pieces of wood and plants"+
   " covered in various forms of mold and disease. It appears someone is"+
   " trying to devise a cure for some of the more tenacious plant"+
   " diseases.");
   set_smell("default","The room holds a lingering scent of light"+
   " ginger.");
   set_listen("default","The wind rustles through the leaves outside.");
   set_items(([
   ({"stream","pond","north wall"}) : "%^BOLD%^%^BLUE%^On the north wall"+
   " a miniature stream slowly feeds into a tranquil pond that is"+
   " lined with the smoothed pebbles of a river. The water creates a"+
   " slight tinkling sound as it enters the pond which is very soothing."+
   " There is obviously magic at work here, for the pond never overflows,"+
   " yet the river never stops pouring into it.%^RESET%^",
   ({"east wall","wooden circle","painting","scene"}) : "On the east"+
   " wall hangs a large circle of wood that has been painted"+
   " %^BOLD%^%^CYAN%^sky blue%^RESET%^ and has the image of a"+
   " %^BOLD%^%^BLUE%^waterfall%^RESET%^ cascading into a still pool in"+
   " the center. Painted %^BOLD%^%^GREEN%^fern leaves%^RESET%^ surround"+
   " the edges of the picture. A wreath of flowers and plants has been"+
   " hung around the wooden circle.",
   ({"flowers","wreath"}) : "A wreath of fresh flowers and plants has"+
   " been placed around the wooden circle on the east wall. The flowers"+
   " are mostly white and lighter colors and have leaves of varying"+
   " shades of green mixed in. It compliments the painting without"+
   " drawing the eye away from the center.",
   ({"cushion","blue cushion"}) : "%^BOLD%^%^CYAN%^A cushion of pale"+
   " blue is seated in front of the wooden circle on the eastern"+
   " wall. It is obviously used for prayer and meditation and a"+
   " large white candle sits in front of it.",
   "candle" : "%^BOLD%^The white candle has several flower petals"+
   " trapped within its wax to make it much prettier. It is very"+
   " large and has been burned about halfway down. It gives off a"+
   " refreshing ginger scent.%^RESET%^",
   ({"holder","candle holder","pewter holder"}) : "A simple pewter"+
   " candle holder contains a large white candle.",
   ({"chest","ash chest"}) : "%^BOLD%^A medium sized ash chest sits"+
   " in the southeast corner, holding several priestly robes and"+
   " other priestly vestements.%^RESET%^",
   ({"table","dining table","rectangular table"}) : "A large rectangular"+
   " dining table on the west side of the room has been covered with"+
   " an alchemy set in someone's attempt to devise a cure to some of"+
   " the more tenacious molds and plant diseases. Several specimens"+
   " with the various diseases are laid out to test the potions on."+
   " It looks as though one of the potions fights off a disease,"+
   " but so far none appear to have eradicated any.",
   ]));
   set_door("ash door",RPATH3+"3two7","southwest",0);
   set_exits( (["southwest":RPATH3+"3two7"]) );
}
