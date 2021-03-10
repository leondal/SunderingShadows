// changes paid for by Lusell when moved to Tonovi *Styx*  12/5/02
// Minor change by Circe 12/1/07 to Bane rather than Xvim

#include <std.h>
#define ANTI "/d/shadow/room/city/cguild/antipaladin/"
inherit VAULT;

void create() {
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_property("no sticks", 1);
   set_name("Altar room");
   set_short("%^RED%^Altar room%^RESET%^");
   set_long("%^RED%^You have entered a room containing a number of alcoves.  "
	"An %^WHITE%^alabaster altar %^RED%^has been centered in the room and "
	"has a %^BOLD%^%^RED%^crimson cloth %^RESET%^%^RED%^draped from one "
	"end to the other.  There is an %^BOLD%^%^BLACK%^obsidian chalice "
	"%^RESET%^%^RED%^covered and centered on the altar and several "
	"candles burning off to the side.  The alcoves each have a smaller "
	"altar, kneeling benches, and various types of seating.  They each "
	"seem to contain shrines to particular deities.\n"
   );
   set_items(([
    "altar" : "The altar is ornately carved from alabaster, which provides a stark contrast to the %^BOLD%^%^RED%^crimson altar cloth%^RESET%^ draped along its center.",
    ({"shrines", "alcoves", "shrine" }) : "Which alcove or shrine are you looking at?  Currently there are shrines of Lord Shadow and The Faceless One, with the other alcoves empty at present.",
    ({"lord shadow","Lord Shadow"}) : "Dedicated to the Scion of Darkness, this alcove is crafted from %^BOLD%^%^BLACK%^jet black stone %^RESET%^that seems to soak up the light. It features offerings of %^BOLD%^%^BLACK%^da%^RESET%^r%^BOLD%^%^BLACK%^k ge%^RESET%^m%^BOLD%^%^BLACK%^sto%^RESET%^n%^BOLD%^%^BLACK%^es %^RESET%^and wilted %^MAGENTA%^violets%^RESET%^ among golden coins.",
    ({"the faceless one","The Faceless One","faceless one","Faceless One" }) : "This alcove is lined with rich %^BOLD%^%^BLACK%^gray cloth %^RESET%^stitched with %^RED%^three blood-red teardrops%^RESET%^. Nestled among the folds of the cloth are offerings: %^BOLD%^%^BLACK%^masks%^RESET%^, "
"%^YELLOW%^coins%^RESET%^, %^BOLD%^%^BLACK%^sm%^RESET%^o%^BOLD%^%^BLACK%^ky q%^RESET%^u%^BOLD%^%^BLACK%^ar%^RESET%^t%^BOLD%^%^BLACK%^z%^RESET%^, and pieces of %^BOLD%^platinum %^RESET%^shaped into teardrops." 
   ]));

   set_exits(([
	"hall" : ANTI+"hall",
   ]));
   set_door("red door",ANTI+"hall","hall",0);
   set_smell("default", "It smells of candles, incense, and other offerings.");
   set_listen("default", "You hear muffled sounds of activity from the other rooms.");
}
