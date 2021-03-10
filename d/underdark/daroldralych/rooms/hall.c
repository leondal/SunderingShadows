#include <std.h>
#include "../defs.h"
inherit "/std/rquestroom";

void create(){
   object ob; 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   set_property("teleport proof",(25+roll_dice(1,20)));
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Adventurer's Hall");
   set_short("%^RESET%^%^BLUE%^Adventurer's Hall%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Adventurer's Hall%^RESET%^\n"
"%^BLUE%^This hall is relatively simple in comparison to the other magnificent structures of the city, but is impressive "
"nonetheless.  Its high arched roof is supported by slender %^BOLD%^%^BLACK%^darks%^RESET%^te%^BOLD%^%^BLACK%^el%^RESET%^"
"%^BLUE%^ beams that radiate inward from each corner of the room like the fragile tines of a web.  Two %^CYAN%^or%^GREEN%^"
"n%^CYAN%^a%^GREEN%^te %^BLUE%^paintings decorate the otherwise austere stone walls, facing each other from opposite "
"sides as views of stark contrast.  At the furthest end of the hall is a %^RED%^high desk%^BLUE%^, and a large board "
"pinned with notices.  An extensive %^WHITE%^list %^BLUE%^is affixed to the rear wall, and several ornately carved "
"benches line the walls along each side.  The large, open doorway allows access to the street to the east.%^RESET%^\n");

   set_smell("default","%^RESET%^%^ORANGE%^Somehow despite the depth underground, the air is "
"%^BOLD%^%^WHITE%^cr%^CYAN%^is%^WHITE%^p %^RESET%^%^ORANGE%^and %^GREEN%^clear%^ORANGE%^.%^RESET%^");
   set_listen("default","%^RESET%^%^GREEN%^The %^MAGENTA%^murmur %^GREEN%^of a busy city drifts in from the doorway"
".%^RESET%^");

   set_items(([
     ({"wall","walls","roof","beams"}):"%^BLUE%^The walls and roof of this shop are made of %^BOLD%^%^BLACK%^black "
"st%^RESET%^%^ORANGE%^on%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^, a common sight in this city, against which the ceiling "
"supports of %^BOLD%^%^BLACK%^da%^RESET%^rk%^BOLD%^%^BLACK%^steel %^RESET%^%^BLUE%^gleam like the tines of a giant web.  "
"The walls are bare but clean, with a single %^MAGENTA%^pa%^RED%^i%^MAGENTA%^nti%^RED%^n%^MAGENTA%^g %^BLUE%^affixed at "
"either side of the room.%^RESET%^",
     "desk":"%^BLUE%^There is a %^RED%^high zurk%^MAGENTA%^hw%^RED%^ood desk %^BLUE%^at the end of the hall, beside which "
"stands a large %^RESET%^board %^BLUE%^pinned with notices.%^RESET%^",
     ({"bench","benches"}):"%^BLUE%^Benches of %^RED%^dark zurk%^MAGENTA%^hw%^RED%^ood %^BLUE%^line the walls on either "
"side of the room, carved with slender legs that are surprisingly sturdy, and patterned across their full length with "
"%^BOLD%^%^CYAN%^ch%^GREEN%^a%^CYAN%^ot%^YELLOW%^i%^GREEN%^c %^RESET%^%^BLUE%^etchings that draw the eye and send one's gaze chasing unexpectedly across their length.%^RESET%^",
     ({"painting","paintings"}):"%^BLUE%^There are two paintings here, each affixed to the wall on opposite sides of the "
"room.  They are both %^BOLD%^inked %^RESET%^%^BLUE%^in the same style, though the images they depict are at complete "
"odds with each other.  The first shows a slender female, completely naked and with her snow-white hair whorling around "
"her sensuous %^BOLD%^%^BLACK%^ebon %^RESET%^%^BLUE%^curves like a splash of %^BOLD%^%^WHITE%^s%^CYAN%^e%^BLUE%^a-"
"%^RESET%^%^CYAN%^s%^WHITE%^p%^BOLD%^%^CYAN%^r%^BLUE%^a%^RESET%^%^CYAN%^y%^BLUE%^.  Her hands are outstretched, extended "
"towards the inky blackness of the skyscape above her.  The second image bears no such peaceful poise, instead showing "
"what might be the same female with a %^MAGENTA%^ma%^RED%^l%^BOLD%^i%^MAGENTA%^c%^RESET%^%^MAGENTA%^io%^RED%^u%^MAGENTA%^"
"s %^BLUE%^gleam in her crimson eyes as she slashes a dagger down towards an unseen victim, her hair cast askew to form a "
"writhing %^BOLD%^%^WHITE%^pl%^RESET%^a%^BOLD%^%^WHITE%^tin%^CYAN%^u%^WHITE%^m %^RESET%^%^BLUE%^corona about her angular "
"face.%^RESET%^",
     "list":"%^BLUE%^A long list is pinned to the back wall, which you could probably %^WHITE%^read%^BLUE%^.%^RESET%^",
   ]));
   set_exits(([
     "east":ROOMS"south1",
   ]));

   ob = new("std/bboard");
   ob->set_name("board");
   ob->set_id( ({"board", "notice board", "quest board"}) );
   ob->set_short("%^RESET%^%^ORANGE%^A large notice board%^RESET%^");
   ob->set_long("%^ORANGE%^This large board has been pinned with numerous notices and letters.%^RESET%^");
   ob->set_board_id("daroldralych_quest_board");
   ob->set_max_posts(30);
   ob->set_location(ROOMS"hall");
   set_quest_daemon("/daemon/quests_mid");
}
