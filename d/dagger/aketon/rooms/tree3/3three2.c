#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("A garden in Aketon");
   set_long("%^GREEN%^A garden in Aketon%^RESET%^\n"+
   "This is a beautiful garden room that is mostly devoted to ginger."+
   " Tall red ginger plants grow in the back of two large troughs of"+
   " earth on the west and east. Growing up front is the slightly"+
   " shorter blue ginger with some bluebonnets mixed in. On the north"+
   " is a trough filled with white and yellow ginger. There are two"+
   " large pots of fire lilies in the northwest and northeast corners.");
   set_smell("default","The smells of the are garden pleasant.");
   set_listen("default","The wind rustles gently through the leaves.");
   set_items(([
   "red ginger" : "%^BOLD%^%^RED%^Tall red ginger plants are growing"+
   " in the back of the troughs on the west and east side. They have"+
   " large %^RESET%^%^GREEN%^dark green leaves%^BOLD%^%^RED%^ and"+
   " the ginger flowers cover the tops of several of the stalks, often"+
   " earning it the name torch ginger for its flaming red flowers.%^RESET%^",
   "blue ginger" : "%^BOLD%^%^BLUE%^The blue ginger is a shorter plant,"+
   " growing two to three feet in height. The leaves are a bit smaller"+
   " than that of other ginger plants, as are the flowers, which are"+
   " a dark purplish blue shade and grow along the tops of the stalks.%^RESET%^",
   "bluebonnets" : "%^BLUE%^Bluebonnets are mixed in with the blue"+
   " ginger. They are smaller plants that look like snap dragons with"+
   " their large blue bonnets on top falling over the smaller lower"+
   " petal of the plant. They are very pretty.%^RESET%^",
   "white ginger" : "%^BOLD%^The white ginger grows in the northern"+
   " trough. It stands about five feet in height and has delicate white"+
   " flowers with a small spray coming out of the center. The white"+
   " ginger smells the best and tends to overpower the other plants.%^RESET%^",
   "yellow ginger" : "%^YELLOW%^Yellow ginger is growing in the northern"+
   " trough, mixed in with the white ginger. The plants are about five"+
   " feet tall and it has delicate yellow petals that surround a small"+
   " yellow spray that protrudes from the center of the flower.%^RESET%^",
   "fire lilies" : "%^BOLD%^%^RED%^The fire lilies are growing in pots"+
   " in the northwest and northeast corners of the room. They are"+
   " rather unusual, small stamens of yellow and red come out from the"+
   " top of a stalk to make a large sphere that looks like a ball of"+
   " fire. They are quite full and very pretty, with few leaves and"+
   " they only grow about a foot tall.%^RESET%^",
   ({"troughs","earth troughs"}) : "There are large troughs that have"+
   " been filled with earth and planted with various plants here.",
   ]));
   set_exits( (["southeast":RPATH3+"3three1"]) );
}
