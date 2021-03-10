#include <std.h>
#include "/d/antioch/wild/mount/muln/paths.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(NEW_MOUNTS);
   set_travel(DIRT_ROAD);
   set_climate("arctic");
   set_property("light", 1);
   set_property("indoors", 1);
   set_listen("default","%^CYAN%^The icicles chime a haunting song... ");
   set_short("%^BOLD%^%^CYAN%^Glac%^RESET%^%^CYAN%^i%^CYAN%^e%^BOLD%^%^CYAN%^r %^WHITE%^A%^RESET%^%^WHITE%^t%^BOLD%^%^WHITE%^rium%^RESET%^");
   set("night long","%^BOLD%^%^CYAN%^Glac%^RESET%^%^CYAN%^i%^CYAN%^e%^BOLD%^%^CYAN%^r %^WHITE%^A%^RESET%^%^WHITE%^t%^BOLD%^%^WHITE%^rium%^RESET%^
%^CYAN%^You stand in the middle of a huge chamber, with walls made of reflective %^BOLD%^%^WHITE%^ice.%^RESET%^%^CYAN%^ The ceiling of the chamber is %^WHITE%^tra%^WHITE%^n%^WHITE%^s%^WHITE%^pare%^WHITE%^n%^WHITE%^t,%^CYAN%^ with the void of %^BOLD%^%^BLACK%^the %^BLACK%^u%^RESET%^%^MAGENTA%^n%^MAGENTA%^i%^BOLD%^%^BLACK%^ver%^RESET%^%^MAGENTA%^s%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^ shining down inside with the light of %^BOLD%^%^WHITE%^myria%^RESET%^%^WHITE%^d %^BLACK%^%^BOLD%^st%^WHITE%^ars%^BOLD%^%^BLACK%^.%^RESET%^%^CYAN%^ The chamber holds an %^ORANGE%^a%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^ient %^BLACK%^s%^RESET%^%^ORANGE%^h%^ORANGE%^i%^BOLD%^%^BLACK%^p%^RESET%^%^CYAN%^ inside with %^ORANGE%^w%^ORANGE%^ood%^CYAN%^ and %^WHITE%^s%^WHITE%^ail%^WHITE%^s%^CYAN%^ untouched by %^BOLD%^%^BLACK%^time.%^RESET%^%^CYAN%^ The black sail bears a strange %^ORANGE%^s%^BOLD%^%^ORANGE%^ymbol%^RESET%^%^CYAN%^ on it. The ship's deck is full of %^ORANGE%^straw%^CYAN%^ collected to form some kind of huge nest.
");
   set("day long","%^BOLD%^%^CYAN%^Glac%^RESET%^%^CYAN%^i%^CYAN%^e%^BOLD%^%^CYAN%^r %^WHITE%^A%^RESET%^%^WHITE%^t%^BOLD%^%^WHITE%^rium%^RESET%^
%^CYAN%^You stand in the middle of a huge chamber, with walls made of reflective %^BOLD%^%^WHITE%^ice.%^RESET%^%^CYAN%^ The ceiling of the chamber is %^WHITE%^tra%^WHITE%^n%^WHITE%^s%^WHITE%^pare%^WHITE%^n%^WHITE%^t, %^CYAN%^and the canvas of the %^BLUE%^sky%^CYAN%^ and %^BOLD%^%^WHITE%^clou%^RESET%^%^WHITE%^ds%^CYAN%^ can be seen from inside.%^RESET%^%^CYAN%^ The chamber holds an %^ORANGE%^a%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^ient %^BLACK%^s%^RESET%^%^ORANGE%^h%^ORANGE%^i%^BOLD%^%^BLACK%^p%^RESET%^%^CYAN%^ inside with %^ORANGE%^w%^ORANGE%^ood%^CYAN%^ and %^WHITE%^s%^WHITE%^ail%^WHITE%^s%^CYAN%^ untouched by %^BOLD%^%^BLACK%^time.%^RESET%^%^CYAN%^ The black sail bears a strange %^ORANGE%^s%^BOLD%^%^ORANGE%^ymbol%^RESET%^%^CYAN%^ on it. The ship's deck is full of %^ORANGE%^straw%^CYAN%^ collected to form some kind of a huge nest.
");

   set_exits(([
                  "outside":"/d/antioch/wild/mount/trail3"
   ]));
   set_items( ([
                   "ship" : "The ship is ancient, but still holds its shape. Some straw had been placed on the deck to form some kind of nest.",
                   "nest" : "The nest had been made by a large creature.",
                   "straw" : "The straw is fresh, whoever made this nest prefers to nap in a clean bed.",
                   "symbol": "This is an ancient symbol of the Zin'Charu empire, three letters that abbreviate \"Senate and the people\"",
                   "sails":"The fabric is old but untouched by decay.",
                   "ceiling":"The stunning iceglass ceiling is transparent, allowing a clear view of the sky above."
   ]));
   if (!present("muln")) {
       new(MULNZONE + "mon/muln")->move(TO);
   }
}
