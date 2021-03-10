#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",-2);
   set_property("indoors",1);
   set_property("teleport proof",(35+roll_dice(1,20)));
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Dark alleyway");
   set_short("%^BLUE%^Dark alleyway%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^Dark alleyway%^RESET%^\n"
"%^BLUE%^This side street leads into the darker spaces between the city's houses.  Smooth %^RESET%^%^ORANGE%^s%^BOLD%^"
"%^BLACK%^t%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^e %^BLUE%^forms the ground beneath your feet, "
"allowing for ease in walking, although it is a little %^ORANGE%^di%^GREEN%^rt%^ORANGE%^y %^BLUE%^in places.  The lack of "
"lightposts in this backstreet causes shadows to cling to every corner and wall, as the back walls of various buildings "
"loom up over you.  More narrow paths and alleyways lead off to either side, some to dead ends, while others simply "
"become lost in %^MAGENTA%^d%^BOLD%^%^BLACK%^ar%^RESET%^%^MAGENTA%^kn%^BOLD%^%^BLACK%^es%^RESET%^%^MAGENTA%^s%^BLUE%^.  "
"Remnants of trash and discarded refuse can be seen amidst the shadows at the wayside, some of which has been piled into "
"makeshift living quarters for the poorest denizens of the city.  Rarely, one of these creatures is daring enough to "
"voice a %^CYAN%^weak %^BLUE%^plea for alms or help, which most often goes ignored, or ends in a strangled gurgle.");
   set_smell("default","%^ORANGE%^The air is a little %^RESET%^mu%^BOLD%^%^BLACK%^st%^RESET%^y %^ORANGE%^here"
", carrying a whiff of rubbish and rot.%^RESET%^");
   set_listen("default","%^RESET%^%^GREEN%^Only occasional %^BLUE%^whispers %^GREEN%^and murmurs are ever "
"heard here.%^RESET%^");
   set_items(([
     ({"darkness","ceiling","air"}):"%^BLUE%^The ceiling is too high up to be seen by normal vision, as you "
"can only see %^MAGENTA%^d%^BOLD%^%^BLACK%^ar%^RESET%^%^MAGENTA%^kn%^BOLD%^%^BLACK%^es%^RESET%^%^MAGENTA%^s %^BLUE%^above "
"you.%^RESET%^",
     ({"beggars","creatures","beggar","trash","refuse"}):"%^BLUE%^Amidst the %^BOLD%^%^BLACK%^tra%^RESET%^%^ORANGE%^s"
"%^BOLD%^%^BLACK%^h %^RESET%^%^BLUE%^discarded at the roadside, it seems some creatures have made their homes, both drow "
"and otherwise.  Mostly they remain mute, letting the world pass them by.  Occasionally one gets the nerve to voice a "
"small plea for aid, but in this city, such signs of %^CYAN%^w%^WHITE%^ea%^CYAN%^kn%^WHITE%^es%^CYAN%^s %^BLUE%^are "
"rarely met with anything but ignorance, a swift kick, or the sharp edge of a dagger.%^RESET%^",
     ({"alley","street","road","ground","stone"}):"%^BLUE%^The %^ORANGE%^st%^BOLD%^%^BLACK%^on%^RESET%^%^ORANGE%^e "
"%^BLUE%^of the street is smooth beneath your feet, although a thin layer of dirt covers much of it, and remnants of "
"rubbish line the edges of the roadside.%^RESET%^",
   ]));
}

void init() {
    ::init();
    if(!present("daroldralychaixxx",TP)) new(OBJ"cityward")->move(TP);
}
