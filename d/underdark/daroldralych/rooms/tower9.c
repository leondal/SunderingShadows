#include <std.h>
#include "../defs.h"
inherit "/std/lab";

void create(){ 
   ::create();
   set_property("light",0);
   set_property("indoors",1);
   set_property("teleport proof",(25+roll_dice(1,20)));
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Within the Black Spire");
   set_short("%^BLUE%^Within the Black Spire%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Within the Black Spire%^RESET%^\n"
"%^BLUE%^Many different furnishings make up this sizeable room.  Tthe first item to catch your eye is a large rectangular "
"%^CYAN%^mir%^BOLD%^r%^RESET%^%^CYAN%^or%^BLUE%^ which has been propped against the wall to the left, framed in an ornate "
"border of %^BOLD%^%^WHITE%^gl%^YELLOW%^e%^WHITE%^aming%^RESET%^%^BLUE%^ metal.  It reflects the rest of the room upon "
"its clear surface, showing tables and cubbies and all kinds of alchemical instruments.  Several %^RED%^long be%^MAGENTA%^"
"nc%^RED%^hes %^BLUE%^hold trays and tubes and other such items for brewing and mixing, while the entire right-hand wall "
"is taken up by rows of storage cubbies.  The rest of the room holds a similar appearance to the tower, enclosed in "
"%^BOLD%^%^BLACK%^glo%^RESET%^ss%^BOLD%^%^BLACK%^y ob%^RESET%^s%^BOLD%^%^BLACK%^idian %^RESET%^%^BLUE%^that sheds a "
"%^ORANGE%^m%^YELLOW%^u%^RESET%^%^ORANGE%^t%^RESET%^e%^ORANGE%^d %^BLUE%^light around the area seemingly from within.  "
"Only one exit is apparent, through the doorway that leads back to the centre of the spire.%^RESET%^\n");
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
     "doorway":"%^BLUE%^A single doorway provides the only means out of this room, set with a door of polished "
"%^RED%^zurk%^MAGENTA%^hw%^RED%^ood%^RESET%^%^BLUE%^.  It leads back into the centre of the spire.%^RESET%^",
     ({"cubbies","glyph","glyphs","storage cubbies"}):"%^BLUE%^The entire right-hand wall of the room is covered "
"in storage cubbies, each marked with a unique %^GREEN%^gl%^CYAN%^yp%^GREEN%^h%^BLUE%^.  They're obviously designed to "
"hold various magical or alchemical components.%^RESET%^",
     ({"benches","long benches","trays","tubes","tables","instruments"}):"%^BLUE%^Several %^RED%^benches %^BLUE%^"
"are placed around the room, each supporting all kinds of tubes, trays, bowls and other alchemical instruments.%^RESET%^",
   ]));
   set_exits(([
     "east":ROOMS"tower8",
   ]));
   set_door("door",ROOMS"tower8","east",0);
   set_door_description("door","%^BLUE%^This sturdy door is cut from %^RED%^zurk%^MAGENTA%^hw%^RED%^ood %^BLUE%^"
"that has been polished to a dark shine, and shaped with such precision as to fit within the wall seamlessly.  It offers "
"the only apparent way in or out of this room, but has no apparent handle with which to open or close it.%^RESET%^");
   setLabId("daroldralych");
}

void init() {
   ::init();
   if(!present("fine mirror")) new(OBJ"mirror")->move(TO);
}

void set_string(string id, string which, string str) {
   if(!id) return;
   if(!which) return;
   if(!doors) return;
   if(!doors[id]) return;
   if (which == "open") str = "%^BLUE%^A mere touch causes the zurkhwood door to swing open noiselessly.%^RESET%^";
   else str = "%^BLUE%^A mere touch causes the zurkhwood door to swing silently closed.%^RESET%^";
   doors[id][which+" string"] = str;
}

void set_open(string id, int open) {
    if(!id) return;
    if(!doors) return;
    if(!doors[id]) return;
    doors[id]["open"] = open;
    if (open == 1) { set_string(id,"open","stuff"); }
    else { set_string(id,"close","stuff"); }
}