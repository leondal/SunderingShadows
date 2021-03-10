#include <std.h>

inherit ROOM;

void create()
{
  ::create();
  set_property("indoors",0);
  set_property("light",1);
  set_climate("temperate");
  set_short("The Darkwood Forest");
  set("day long","%^GREEN%^The Darkwood Forest%^RESET%^\n"
      "%^BOLD%^%^GREEN%^You travel along the fringes of the forest.%^RESET%^\n"
      "The Darkwood trees grow tall and thick here and not much light, "
      "be it sun or moon gets through. The forest floor is covered in "
      "bushes and leaves. They cover the ground so thickly that it is "
      "almost impossible to see the dirt that lays beneath it. There "
      "are game trails here and there and maybe if you can find one it "
      "will lead you out of here or at least to some form of safety.");
  set("night long","%^BOLD%^%^BLUE%^The Darkwood Forest%^RESET%^\n"
      "It is difficult to see where you are going and it is hard to get "
      "your bearings in this place. The growth here is thick and tangled. "
      "One might think it safer to wait until daylight in order to travel "
      "but then again, who knows what lurks in the shadows here.");
  set_smell("default","The leaves decay here on the forest floor, among "
            "other things.");
  set_listen("default","A bone chilling breeze stirs the bushes and trees.");
  set_items( ([
     "trees"  : "They grow tall and thick. Their upper branches entertwine "
                "causing a canopy that light cant seem to get through "
                "easily.",
     "bushes" : "They cover much of the forest floor and block you from "
                "traveling to far in some directions.",
     "leaves" : "They have fallen from trees and bushes to cover what "
                "little of the forest floor the bushes and trees do not.",
     "trails" : "The trail goes to the south and southeast."
	       ]) );
  set_exits( ([
     "southeast" : "/d/darkwood/forest/df25",
     "south" : "/d/darkwood/forest/df27"
	       ]) );
  }
