#include <std.h>
#include "../defs.h"
inherit VAULT;

void create(){ 
   ::create();
   set_property("light",0);
   set_property("indoors",1);
   set_property("teleport proof",(35+roll_dice(1,20)));
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Within the Black Spire");
   set_short("%^BLUE%^Within the Black Spire%^RESET%^");
   set_smell("default","%^ORANGE%^The %^GREEN%^ac%^BOLD%^i%^RESET%^%^GREEN%^dic %^ORANGE%^aroma of mingled alchemical "
"components tickles your nose.");
   set_listen("default","%^GREEN%^It is particularly %^CYAN%^q%^GREEN%^ui%^CYAN%^et %^GREEN%^in here.");
   set_items(([
     ({"wall","walls","stalactite"}):"%^BLUE%^All of the spire's smooth walls, as well as the ceiling and floor, are "
"formed of the same %^BOLD%^%^BLACK%^jet-bl%^RESET%^ac%^BOLD%^%^BLACK%^k obs%^RESET%^i%^BOLD%^%^BLACK%^dian%^RESET%^"
"%^BLUE%^.  Its glossy surface shows a faint reflection of the room, with details only truly discernable if one stands "
"directly in front of it.  A %^ORANGE%^m%^YELLOW%^u%^RESET%^%^ORANGE%^t%^RESET%^e%^ORANGE%^d %^BLUE%^glow, likely imbued "
"by magic, emanates from the walls themselves to light the tower, and catches upon tiny fragments of %^GREEN%^o%^ORANGE%^l"
"%^GREEN%^iv%^ORANGE%^i%^GREEN%^ne %^BLUE%^and %^ORANGE%^aug%^BOLD%^%^BLACK%^it%^RESET%^%^ORANGE%^e %^BLUE%^embedded "
"within the stone itself, remnants of its volcanic birth.%^RESET%^",
     ({"roof","ceiling"}):"%^BLUE%^The same %^BOLD%^%^BLACK%^gl%^RESET%^o%^BOLD%^%^BLACK%^ssy-bl%^RESET%^ac%^BOLD%^"
"%^BLACK%^k obs%^RESET%^i%^BOLD%^%^BLACK%^dian%^RESET%^%^BLUE%^ as the walls forms the ceiling above your head.  It emits "
"a %^ORANGE%^m%^YELLOW%^u%^RESET%^%^ORANGE%^t%^RESET%^e%^ORANGE%^d %^BLUE%^glow, shedding soft light around the room and "
"sparkling as it catches upon tiny fragments of %^GREEN%^o%^ORANGE%^l%^GREEN%^iv%^ORANGE%^i%^GREEN%^ne %^BLUE%^and "
"%^ORANGE%^aug%^BOLD%^%^BLACK%^it%^RESET%^%^ORANGE%^e %^BLUE%^that are embedded within the stone itself.%^RESET%^",
     "floor":"%^BLUE%^The floor is formed of the same %^BOLD%^%^BLACK%^gl%^RESET%^e%^BOLD%^%^BLACK%^ami%^RESET%^n%^BOLD%^"
"%^BLACK%^g obs%^RESET%^i%^BOLD%^%^BLACK%^dian%^RESET%^%^BLUE%^ as the rest of the tower, perfectly smooth and unflawed.  "
"Its temperature is surprisingly pleasant to touch, rather than the %^BOLD%^%^CYAN%^chi%^WHITE%^l%^CYAN%^l %^RESET%^"
"%^BLUE%^one would expect from a stone floor.%^RESET%^",
   ]));
}

void init() {
    ::init();
    if(!present("daroldralychaixxx",TP)) new(OBJ"cityward")->move(TP);
}