#include "../newbie.h"

inherit VAULT;

void create() {
        object ob;
        ::create();
        set_name("newbie town square");
        set_short("This is the town square of Offestry");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
        set_long(
@NEWBIE
%^BOLD%^%^RED%^Offestry town square%^RESET%^ 
This is the town square for the city of Offestry. Offestry is the largest
civilized area in the demi-plane that welcomes newcomers to Sundering Shadows.  
Here life is much as it is in the world of Sundering Shadows only a little slower,
fewer pressures, and overall easier lives.  A person could live his entire 
life here in quiet contentment.  There is a grand %^CYAN%^statue%^RESET%^ here 
in the square. Its puzzling expression begs you to look it over.  There 
is also a large %^CYAN%^sign%^RESET%^ here that demands your attention.  The %^CYAN%^buildings%^RESET%^ 
of the city rise around you.  Cobblestone %^CYAN%^streets %^RESET%^radiate outward
from this point to different parts of the city, leading you toward your 
life as an adventurer.
NEWBIE
   );
   set_listen("default","The voices of villagers and travelers trading tales fills the air.");
        set_smell("default","The air is clean and fresh.");
        set_property("light",2);
        set_items(([
        "statue":"This grand statue points outward. It has arms pointing in all "+
"directions. It commands you to go forth and explore. You are a new adventurer, "+
"and adventure forth you must. One day you will leave this place and become a "+
"true adventurer, gaining fame, glory, power, or whatever you like, and "+
"hopefully, one day, being written into the annals of the world as a high mortal, "+
"forever remembered. For after you leave, what is left if not memories?",
        "streets":"The streets are cobbled and new. They radiate outward from the very "
"spot you stand. You realize that it's as if you stand on the center of a "+
"sunrise, a new beginning.",
        "sign":"It has some important information.  Read it to gain insight on the "+
"world.",
        "buildings":"The buildings are a jumble of styles and types. They hold the "+
"citizens, businesses and adventure of this small city.",
        ]));
        set_exits(([
      "north":MAINTOWN"nstreet1",
      "south":MAINTOWN"sstreet1",
      "east":MAINTOWN"estreet1",
      "west":MAINTOWN"wstreet1",
      "ooc":"/d/newbie/ooc/hub_room",
      "down":MAINTOWN"boards1",
        ]));
        ob = new("/std/bboard");
        ob->set_name("board");
        ob->set_id( ({ "board", "bulletin board", "newbie board" }) );
        ob->set_board_id("offestry_board");
        ob->set("short", "The Offestry Bulletin Board");
        ob->set("long", "A nice new corkboard for newbies to post ooc comments and concerns about the world here.");
        ob->set_max_posts(50);
        ob->set_location("/d/newbie/rooms/town/square.c");
        find_object_or_load("/d/npc/sarlen");
        "daemon/place_d"->place_in("/d/newbie/rooms/town/",new("/d/npc/sarlen"));
        find_object_or_load(MON"nerussa.c");
        "daemon/place_d"->place_in("/d/newbie/rooms/forest/",new(MON"nerussa"));
        find_object_or_load(MON"musond.c");
        "daemon/place_d"->place_in("/d/newbie/rooms/road/",new(MON"musond"));
}

void init() {
	::init();
}

void reset(){
        ::reset();
        if(!present("street_light",TO))
        new(MISCDIR+"street_light")->move(TO);
        if(!present("sign",TO))
          new("/d/newbie/obj/misc/townsign")->move(TO);
}

