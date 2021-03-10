#include <std.h>
#include "../defs.h"
inherit HEALER;

void create(){ 
   ::create();
   set_property("light",0);
   set_property("indoors",1);
   set_property("teleport proof",(25+roll_dice(1,20)));
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Healer's alcove");
   set_short("%^MAGENTA%^Healer's alcove%^RESET%^");
   set_long("%^MAGENTA%^Healer's alcove%^RESET%^\n"
"%^BOLD%^%^BLACK%^This sidechamber has its walls, floor and roof made of the same %^RESET%^%^BLUE%^glo%^BOLD%^s%^RESET%^"
"%^BLUE%^sy %^BOLD%^%^BLACK%^obsidian as the rest of the building.  It forms a rough half-sphere, with many shelves "
"curled around the arc of the wall that have been stacked with various %^RESET%^%^WHITE%^ja%^BOLD%^r%^RESET%^%^WHITE%^s "
"%^BOLD%^%^BLACK%^and %^RESET%^%^CYAN%^bot%^MAGENTA%^tl%^CYAN%^es%^BOLD%^%^BLACK%^, some filled and others not.  In the "
"centre of the room is a large wooden table, upon which rest more jars, as well as various %^RESET%^%^GREEN%^h%^ORANGE%^e"
"%^GREEN%^r%^ORANGE%^b%^GREEN%^s%^BOLD%^%^BLACK%^, bowls, and a variety of alchemical devices.%^RESET%^\n");
   set_smell("default","%^ORANGE%^The sharp tang of %^GREEN%^br%^ORANGE%^e%^GREEN%^wed her%^ORANGE%^b%^GREEN%^s %^ORANGE%^"
"tickles at your nose.");
   set_listen("default","%^CYAN%^P%^GREEN%^ra%^CYAN%^y%^GREEN%^er%^CYAN%^s %^GREEN%^of the faithful surround you with a "
"dull %^ORANGE%^mur%^YELLOW%^m%^RESET%^%^ORANGE%^ur %^GREEN%^of sound.");

   set_items(([
     ({"walls","roof","floor"}):"%^BOLD%^%^BLACK%^The walls, roof and floor are all carved from the same %^RESET%^glo"
"%^BOLD%^%^BLACK%^ss%^RESET%^y obs%^BOLD%^%^BLACK%^i%^RESET%^dian%^BOLD%^%^BLACK%^ as the rest of this building.  Several "
"lines of shelving follow the half-arc shape of the back wall and run nearly the full length of the room.%^RESET%^",
     ({"bottles","jars","shelves"}):"%^BOLD%^%^BLACK%^Following the curved line of the wall are many shelves, holding a "
"variety of %^RESET%^%^WHITE%^ja%^BOLD%^r%^RESET%^%^WHITE%^s %^BOLD%^%^BLACK%^and %^RESET%^%^CYAN%^bot%^MAGENTA%^tl"
"%^CYAN%^es%^BOLD%^%^BLACK%^.  Some contain a variety of unidentified powders, liquids, or even small dead creatures, "
"while others are merely empty.%^RESET%^",
     ({"table","obsidian table","herbs","bowls","devices","alchemical devices"}):"%^BOLD%^%^BLACK%^In the centre of the "
"room stands a simple table of polished %^RESET%^%^RED%^zurk%^MAGENTA%^hw%^RED%^ood%^BOLD%^%^BLACK%^.  Upon its smooth "
"top are several alchemical devices for measurement and brewing, as well as a few stone bowls and a scattering of various "
"%^RESET%^%^GREEN%^h%^ORANGE%^e%^GREEN%^r%^ORANGE%^b%^GREEN%^s%^BOLD%^%^BLACK%^.",
     "sign":"%^BOLD%^%^BLACK%^A carefully scribed sign has been secured to the wall.  You should read it.%^RESET%^",
   ]));
   set_exits(([
     "east":ROOMS"temple1",
   ]));
   set_name("shrityrr");
}

void reset(){
   ::reset();
   if(!present("shrityrr")) find_object_or_load(MON"shrityrr")->move(TO);
}
