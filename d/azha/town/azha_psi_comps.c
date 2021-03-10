//updated by ~Circe~ 10/18/07 for new crystal/storage room downstairs
#include <std.h>
inherit ROOM;

string mylong;

void create(){
	::create();
	set_travel(PAVED_ROAD);
      set_terrain(CITY);
	set_light(2);
	set_indoors(1);
	set_name("Striated Cognizance");
	set_short("Striated Cognizance");
	set_long((:TO,"longdesc":));
	set_smell("default","The pungent fragrance of incense "+
         "permeates the room.");
	set_listen("default","A gentle humming seems to fill the air.");
	set_items( ([
         ({"stair","stairs","steps","step"}) : "The western wall "+
            "of the room has been shaped into a grand staircase, "+
            "with each step being wide enough for a person to sit "+
            "comfortably.  No cushions pad the steps, but it seems "+
            "as though the shopkeeper spends most of his time "+
            "lightly perched upon them in meditation.",
         ({"cases","chests"}) : "The cases and chests are crafted "+
            "of various woods in different shades, all adding "+
            "to the harmony of the shop.  Each chest and case "+
            "holds gems arranged in a pleasing manner.",
         ({"gems","gem"}) : "The gems are shaped into every "+
            "cut imaginable and consist of every color.  It "+
            "seems nothing has been left out of this dazzling "+
            "display!"
    ]) );
    set_search("default","As you search around the room, you notice "+
       "that something seems unusual along the eastern wall.");
    set_search("wall","You find a "+
       "staircase along the eastern wall leading down.  "+
       "Why didn't you notice that before?");
    set_search("eastern wall","You find a "+
       "staircase along the eastern wall leading down.  "+
       "Why didn't you notice that before?");
    set_search("east wall","You find a "+
       "staircase along the eastern wall leading down.  "+
       "Why didn't you notice that before?");
    set_exits(([
        "east" : "/d/azha/town/center1",
        "up" : "/d/azha/town/portal",
        "down" : "/d/azha/town/crystal"
    ]));
   set_invis_exits(({"down"}));
}

void reset(){
   ::reset();
   if(!present("abbas")) {
      find_object_or_load("/d/azha/mon/abbas")->move(TO);
   }
}

void longdesc(){
   mylong = "%^BOLD%^Striated Cognizance, Azha%^RESET%^\n"+
      "Crafted purely from pristine %^BOLD%^white marble walls%^RESET%^, "+
      "this shop conveys a sense of %^MAGENTA%^opulence %^RESET%^despite its relative "+
      "simplicity.  The western wall of the shop has been worked into "+
      "a series of %^BOLD%^stairs%^RESET%^, each one wide enough to "+
      "allow someone to sit cross-legged upon it comfortably.  The "+
      "owner of this austere shop can often be sitting upon one of "+
      "the steps, deep in %^CYAN%^meditation%^RESET%^.  Spaced around the "+
      "shop are various %^ORANGE%^wooden cases %^RESET%^and "+
      "%^ORANGE%^chests %^RESET%^filled with %^BOLD%^%^CYAN%^gems %^RESET%^of all shapes, sizes, "+
      "and %^BOLD%^%^GREEN%^c%^CYAN%^o%^WHITE%^l%^BLUE%^o%^RESET%^%^MAGENTA%^r%^YELLOW%^"+
      "s%^RESET%^.  The cases are raised to different heights, offering "+
      "an asthetically pleasing balance to the eye.  There is no "+
      "mundane counter or vulgar cash box "+
      "to sully the shop, though the shopkeeper must clearly make a "+
      "decent living to support such a grand building.\n\n";
	//added by Saide - was in the debug.log file 
	//bad argument to call other - figuring if 
	//TP is invalid, its going to bug
  	if(objectp(TP)) 
	{
		if(TP->is_class("psion"))
		{
      		mylong += "%^BOLD%^A faint shimmering light to the east catches "+
	         	"your eye, revealing a concealed stairway leading down.%^RESET%^\n\n";
   		}
	}
	mylong += "%^RESET%^<help shop> will give you help on how to use the shop.\n";
   	return mylong;
}