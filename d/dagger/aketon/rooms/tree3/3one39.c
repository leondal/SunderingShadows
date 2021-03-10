#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "You have walked into a cozy study area. There is a large cream couch"+
   " that takes up the center of the room. All along the walls are"+
   " bookshelves filled with different elven manuscripts, as well as"+
   " a book or two written by some other races. While the number of"+
   " books is vast indeed, most of them appear to be fictional stories,"+
   " although you spot a few books on gardening and wood carving. There"+
   " is a small ash stand next to the couch that holds a shaded lamp."+
   " In the southwest corner is a pine chest that holds some clothes in"+
   " it.");
   set_smell("default","The scent of roses is light and pleasant.");
   set_listen("default","The wind rustles through the leaves.");
   set_items(([
   ({"couch","cream couch"}) : "%^YELLOW%^There is a couch in the"+
   " center of the room that looks as though it could fit three humans"+
   " or four elves comfortably. It appears to get quite a bit of use.",
   ({"bookshelves","books","manuscripts"}) : "The walls here are lined"+
   " with various books, most of them are elven but there are a few"+
   " written by other races, such as humans, halflings, and even a"+
   " collection of wemic stories. They all appear to be fictional,"+
   " except for a few books on gardening and wood carving.",
   ({"stand","ash stand"}) : "There is a small table made of light"+
   " ash wood that sits next to the couch. It holds a shaded lamp.",
   ({"lamp","shaded lamp"}) : "There is a shaded lamp on top of the"+
   " ash stand near the couch. It appears to operate by magic, for"+
   " it glows when it is night and is off during the day. The shade"+
   " of the lamp has been painted with a rather pretty picture of a"+
   " white magnolia.",
   ({"chest","pine chest"}) : "The pine chest is in the southwest"+
   " corner of the room. The outside has been carved with lilies and"+
   " vines. You can see that it is full of some rather simple elven"+
   " clothing.",
   ]));
   set_exits( (["northwest":RPATH3+"3one35"]) );
}
