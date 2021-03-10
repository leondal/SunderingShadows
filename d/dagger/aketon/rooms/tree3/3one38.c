#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "You are standing in what appears to be the room of two elven"+
   " children. Elven children are precious and rare, since elves"+
   " are not the most fertile of races, and having two is rather"+
   " unusual. The floor is carpeted in a large cream rug and there are"+
   " several pictures on the walls. There are two beds on the south"+
   " side of the room. One is covered in sapphire blue blankets while"+
   " the other is covered in dark amethyst ones. There is a small"+
   " pillow that has needlework covering its front on the purple"+
   " bed. There are two small oak nightstands on either side of the"+
   " beds. The one near the blue bed is filled with books while the"+
   " one near the purple bed has some thread and more artsy things.");
   set_smell("default","The room has a light and pleasant smell to it.");
   set_listen("default","You hear the wind whistling through the leaves outside.");
   set_items(([
   ({"wall","walls","pictures"}) : "There are a few pictures hung on"+
   " the walls. The ones on the west side of the room have been"+
   " carefully painted in water colors and they show scenes of the"+
   " forest and a hunter. On the east wall is hung a piece of"+
   " needlepoint depicting a cute grey kitten with green eyes. There"+
   " is also an oil painting of a wild horse running through a meadow.",
   ({"bed","beds"}) : "There are two beds here, a blue one and a purple"+
   " one.",
   ({"blue bed","sapphire bed"}) : "%^BOLD%^%^BLUE%^The blue bed is"+
   " more on the west side of the room. It is covered in thick sapphire"+
   " blankets with matching pillowcases. It is obviously made for a"+
   " younger person. The head board is made of oak and someone has"+
   " carved a bow and arrow in the very center, with leaves and vines"+
   " around it.",
   ({"purple bed","amethyst bed"}) : "%^MAGENTA%^The purple bed is"+
   " more on the east side of the room. It is covered with plush"+
   " amethyst blankets with matching pillowcases. There is another"+
   " small pillow with needlepoint on the front. The head board is made"+
   " of oak and someone has painted a large lavender rose in the center"+
   " of it with green leaves spreading out from it.",
   ({"pillow","needlepoint"}) : "The small pillow rests on the amethyst"+
   " bed and the colors match the rest of the blankets and sheets. On the"+
   " front has been sewn a carefully stitched picture of an elven woman"+
   " with green eyes and dark brown hair, she has a few streaks of"+
   " silver in her hair and she appears a bit older.",
   ({"nightstands","nightstand"}) : "There are two nightstands. The one"+
   " near the blue bed is filled with books on archery, woodsmanship,"+
   " crafting, and athletics. The one near the purple bed is covered"+
   " with some unfinished needlepoint, a multitude of thread colors and"+
   " a nice collection of oil paints.",
   ({"rug","cream rug"}) : "%^YELLOW%^A thick cream rug covers the"+
   " entire floor of this room, it is nice and soft to walk on.",
   "door" : "There is an oak door that leads to the north.",
   ]));
   set_door("oak door",RPATH3+"3one34","north",0);
   set_exits( (["north":RPATH3+"3one34"]) );
}
