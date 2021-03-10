#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   set_property("teleport proof",(25+roll_dice(1,20)));
   set_property("smithy",1);
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("The Tempered Blaze");
   set_short("%^RESET%^%^BLUE%^The Tempered Blaze%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^The Tempered Blaze%^RESET%^\n"
"%^BLUE%^The first thing that strikes you as you enter this vast chamber is the %^BOLD%^%^RED%^h%^YELLOW%^e%^RED%^at"
"%^RESET%^%^BLUE%^, emanating from the forge at the back of the room that sheds a %^RED%^dull crim%^BOLD%^s%^RESET%^"
"%^RED%^on glow %^BLUE%^around the room.  The thick, muggy air fills the rest of the chamber, which offers for display "
"many suits of armor both light and heavy.  A single %^RED%^glossed zurk%^MAGENTA%^hw%^RED%^ood counter %^BLUE%^stands "
"near the large doorway, that frames the %^MAGENTA%^soft gle%^BOLD%^a%^RESET%^%^MAGENTA%^m %^BLUE%^of the lights that "
"line the street to the south.%^RESET%^\n");
   set_smell("default","%^ORANGE%^The thick smell of %^RESET%^smoke %^ORANGE%^and %^BOLD%^%^BLACK%^ir%^RESET%^%^BLUE%^o"
"%^BOLD%^%^BLACK%^n %^RESET%^%^ORANGE%^chokes the room.");
   set_listen("default","%^GREEN%^The regular clang of metal on metal %^RESET%^j%^BOLD%^%^BLACK%^a%^WHITE%^r%^RED%^r"
"%^YELLOW%^s %^RESET%^%^GREEN%^your ears.");

   set_items(([
     ({"wall","walls","roof"}):"%^BLUE%^The walls and roof of this shop are made of %^BOLD%^%^BLACK%^black st%^RESET%^"
"%^ORANGE%^on%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^, a common sight in this city.  They carry no elaborate carvings, as do "
"the upper-class buildings, but are instead marked with smudges of %^BOLD%^%^BLACK%^soot %^RESET%^%^BLUE%^and %^RESET%^s"
"%^BOLD%^%^BLACK%^mok%^RESET%^e%^BLUE%^.%^RESET%^",
     "counter":"%^BLUE%^A long counter of %^RED%^glossed zurk%^MAGENTA%^hw%^RED%^ood %^BLUE%^stands near the chamber's "
"large doorway.  A %^RESET%^list %^BLUE%^of available items and prices sits upon its polished surface.%^RESET%^",
     "forge":"%^BLUE%^At the back of the vast chamber, separated from the main shop by half-walls at either side, lies a "
"broad %^RED%^f%^BOLD%^o%^RESET%^%^RED%^rge %^BLUE%^steaming with heat.  A %^BOLD%^%^BLACK%^bl%^RESET%^a%^BOLD%^%^BLACK%^"
"cken%^RESET%^e%^BOLD%^%^BLACK%^d an%^RESET%^v%^BOLD%^%^BLACK%^il %^RESET%^%^BLUE%^lies upon the floor, close at hand, "
"with tools lined up carefully on a separate bench.  A stone chimney above serves to siphon off the worst of the smoke "
"and heat, but the shop itself is becomes a little uncomfortable to stay in for long periods of time.%^RESET%^",
     ({"armor","suits"}):"%^BLUE%^Varied suits of %^RESET%^ar%^BOLD%^%^BLACK%^mo%^RESET%^r %^BLUE%^fill the room, resting "
"on stands all around the walls.  They range from the heaviest full suits of platemail%^BLUE%^, right down to light suits "
"of %^ORANGE%^leather%^BLUE%^. In common though, they are all %^BOLD%^%^BLACK%^dar%^RESET%^%^ORANGE%^k%^BOLD%^%^BLACK%^ly "
"co%^RESET%^%^GREEN%^l%^BOLD%^%^BLACK%^ored%^RESET%^%^BLUE%^, probably better to serve the wearer in the lightless "
"tunnels of underdark.%^RESET%^",
   ]));
   set_exits(([
     "south":ROOMS"outer9",
   ]));
}

void reset(){
   ::reset();
   if(!present("jhaelolin")) new(MON"jhaelolin")->move(TO);
}