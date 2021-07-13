#include "../../newbie.h"
inherit ROOM;

void create()
{
  object ob;
  ::create();
  set_property("indoors",0);
  set_property("light",2);
  set_terrain(CITY);
  set_travel(PAVED_ROAD);
  set_name("Offestry town square");
  set_short("%^RESET%^%^GREEN%^Offestry town square%^RESET%^");
  set_long("%^RESET%^%^GREEN%^Offestry town square%^RESET%^\n"
"You are standing in the middle of the town of Offestry, where four cobblestone %^ORANGE%^streets %^RESET%^converge upon "
"this town square.  A light but constant stream of %^CYAN%^traffic %^RESET%^passes through, day and night, as the town "
"serves as a waypoint to the people passing into the greater realm of Sundering Shadows.  The "
"atmosphere is relatively slow and relaxed, in this quiet but prosperous town.  All around you rise a jumbled array of "
"%^RED%^buildings%^RESET%^.  There is a grand "
"%^BOLD%^%^WHITE%^statue%^RESET%^ standing here, drawing the eyes of travellers as they pass by.  Upon the front wall, a "
"%^YELLOW%^sign %^RESET%^has been affixed along with a %^YELLOW%^map %^RESET%^that you could %^ORANGE%^read%^RESET%^.\n");
  set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly to light your way.%^RESET%^");
  set_listen("default","The voices of villagers and travellers trading tales fills the air.");
  set_smell("default","The air is clean and fresh.");
  set_items(([
    "streets":"%^ORANGE%^The streets are newly cobbled and well-kept, polished smooth by the passage of so many "
"travellers.  They radiate outward from the very spot you stand like the rays of a rising sun, leading the way to new "
"beginnings.  Starlight Avenue leads north, Goldstone Road leads southwards, Sunrise Way heads away eastwards, and Sunset way heads to the "
"west.%^RESET%^",
    "traffic":"%^CYAN%^A light but steady stream of traffic passes through this square, coming and going from "
"the streets that radiate outwards into the rest of the town of Offestry.  Chatter so often fills the air, varying in "
"topic from price bartering, through to tales of grand adventures beyond the gates of the town. %^RESET%^",
    "buildings":"%^RED%^A hodgepodge of buildings rise up along either side of the streets as they lead away from the "
"square.  Their age and vastly varied styles give a unique appearance to the cosy town around you, where no two buildings "
"are the same.%^RESET%^",
    "statue":"%^YELLOW%^The plinth upon which this man-sized statue rests, allows it to rise above the throng of traffic"
".  One arm is raised in benediction to all that walk past, while the other points towards the south and the new horizons "
"to be found there.  A line of text has been etched within the plinth at its feet.\n%^WHITE%^'You are a new adventurer, "
"and adventure forth you must.  One day you will leave this place and become a true adventurer, gaining fame, glory, "
"power, or whatever you like, and hopefully one day, being written into the annals of the world as a high mortal, forever "
"remembered. For after you leave, what is left if not memories?'%^RESET%^",
    "map":"%^YELLOW%^There is a rough map attached to the bottom of the sign.  You should try to %^RESET%^%^ORANGE%^read "
"%^YELLOW%^it. %^RESET%^NOTE: If you have requested a text-only version of the map, the ascii version in the room will override it. Please type <read my map> to access the one in your inventory.",
  ]));
  set_exits(([
    "north":MAINTOWN"nstreet1",
    "south":MAINTOWN"sstreet1",
    "east":MAINTOWN"estreet1",
    "west":MAINTOWN"wstreet1",
    "oochub":"/d/newbie/ooc/hub_room3",
  ]));

   ob = new("/std/bboard");
   ob->set_name("board");
   ob->set_id( ({ "board", "bulletin board", "newbie board" }) );
   ob->set_board_id("ic_offestry_board");
   ob->set_short("The Offestry Bulletin Board");
   ob->set_long("%^RESET%^%^ORANGE%^This corkboard is weathered and old, inviting posts from adventurers who pass through "
    "the town.%^RESET%^");
   ob->set_max_posts(50);
   ob->set_location(MAINTOWN"square.c");

}

void init()
{
    object myOb;
    ::init();
    add_action("request_map","request");
    if(!objectp(TO)) return;
    if(!objectp(TP)) return;
    if(!userp(TP)) return;
    if(!objectp(myOb = present("newbiemassobject", TP)) && !avatarp(TP))
    {
        new("/d/newbie/obj/misc/newbie_object.c")->move(TP);
        return;
    }
    return;
}

int request_map(string str){
	 if(!str || (str != "map" && str != "text map"));
	write("The citizen hands you another map.");
        tell_room(ETP,"The citizen hands "+TPQCN+" a piece of paper.",TP);
	new("/d/newbie/obj/offestrytextmap.c")->move(TP);
	return 1;
  }

void reset(){
  ::reset();
  if(!present("street_light",TO)) new(MISCDIR"street_light")->move(TO);
  if(!present("sign",TO)) new("/d/newbie/obj/misc/townsign")->move(TO);
}