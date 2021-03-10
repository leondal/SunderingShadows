#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "This is a pretty little house that is brightly colored. A yellow"+
   " rug that matches the door is spread out over the center of the"+
   " room with a white dove in the center of it. There is a long oak"+
   " bench against the north wall with yellow cushions that pad the"+
   " seats. On the west side of the room is a small dinette area"+
   " with a round table seated for two and a sink and counter with"+
   " a few cabinets in the northwest corner. Three painted porcelain"+
   " plates are hung on the east wall, and there is a small dresser"+
   " full of clothes in the southeast corner. In the southwest corner"+
   " is an oak pedestal with a basket of daffodils sitting atop it.");
   set_smell("default","The house smells of cinnamon and vanilla.");
   set_listen("default","The wind rustles through the leaves outside.");
   set_items(([
   ({"rug","yellow rug"}) : "%^YELLOW%^A large, square yellow rug"+
   " covers the middle of the room. In the center is the enlarged"+
   " image of a %^WHITE%^white dove%^YELLOW%^. The middle of the room"+
   " is kept clear, the owner probably practices her dancing or"+
   " other such art form there.%^RESET%^",
   ({"oak bench","bench"}) : "There is an oak bench in the center of"+
   " the north wall. It has been padded with bright yellow cushions and"+
   " appears comfortable enough. It is fairly long and looks as though"+
   " it could hold perhaps six elves.",
   ({"table","round table"}) : "There is a small round table on the"+
   " northwest side of the room. There are only two chairs around it"+
   " but that appears to be all that's needed.",
   "chairs" : "There are two oak chairs seated around the table.",
   ({"counter","sink"}) : "In the northwest corner of the room is a"+
   " short counter with a sink set inside it. Only simple meals could"+
   " be prepared there, but most of the elves like their food fresh"+
   " and simple anyway.",
   "cabinets" : "There are some cabinets above the counter in the"+
   " northwest corner of the room that hold dishes and silverware and"+
   " other simple cooking utensils.",
   ({"plates","painted plates","porcelain plates","east wall"}) : "%^BOLD%^Three"+
   " painted porcelain plates hang on the east wall. The one in the"+
   " center is positioned higher than the other two and it has the"+
   " image of a golden dragon with wings spread out. The one to the"+
   " left of it is completely the opposite, showing a cute and"+
   " fuzzy newly hatched chick, full of innocence and totally helpless."+
   " The plate on the right side has been painted with an eagle soaring"+
   " through the skies with the high sun in the background.%^RESET%^",
   "dresser" : "There is a small oak dresser in the southeast corner"+
   " that is filled with clothes.",
   ({"pedestal","oak pedestal"}) : "An oak pedestal stands up against the"+
   " wall in the southwest corner of the room. A basket of daffodils"+
   " rests on top of it.",
   ({"basket","daffodils"}) : "%^YELLOW%^The daffodils are actually"+
   " growing in a ceramic pot that has been placed inside a large"+
   " wicker basket. All you can see over the top of the basket are the"+
   " beautiful flowers, bright and colorful and full of life.",
   ]));
   set_door("yellow door",RPATH3+"3two7","southeast",0);
   set_exits( (["southeast":RPATH3+"3two7"]) );
}
