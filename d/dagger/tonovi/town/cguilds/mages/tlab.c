//updated by Circe 5/31/04
// Public Laboratory in the Tower of the Arcane, Tabor
// Thorn@ShadowGate
// 010306
// Tabor
// tlab.c

#include <std.h>
#include "../include/tabor.h"

inherit "/std/lab";

void create(){
   object ob;
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_property("indoors",1);
   set_property("light",2);
//   set_property("no teleport",1);
   set_name("Public Laboratory, Tower of the Arcane, Tabor");
   set_short("Public Laboratory, Tower of the Arcane, Tabor");
   set_long(
@OLI
%^BOLD%^Public Laboratory in the Tower of the %^CYAN%^A%^YELLOW%^r%^CYAN%^c%^YELLOW%^a%^CYAN%^n%^YELLOW%^e%^WHITE%^, Tabor%^RESET%^
%^CYAN%^This is the public %^MAGENTA%^laboratory %^CYAN%^housed within the tower. Here the %^BOLD%^magi 
%^RESET%^%^CYAN%^without laboratories of their own keep small %^ORANGE%^cubbies %^CYAN%^and %^WHITE%^work areas%^CYAN%^. 
Even some magic dabblers keep an area here.  All around you, %^BOLD%^%^MAGENTA%^potions 
%^RESET%^%^CYAN%^bubble and %^WHITE%^mice %^CYAN%^squeak.  Smells of %^YELLOW%^sulfur %^RESET%^%^CYAN%^and %^RED%^carbon %^CYAN%^and such waft 
through the air.  A slight %^BOLD%^%^BLACK%^smoke %^RESET%^%^CYAN%^lingers at the top of the high ceiling.  Dominating the center of the room is an impressive %^BOLD%^%^WHITE%^mirror%^RESET%^%^CYAN%^.

%^RESET%^The command <help laboratory> will instruct you in its use.
OLI
   );

   set_exits(([
           "south" : "/d/darkwood/tabor/room/tfloor4",
      ]));
   set_smell("default","Sulfur, carbon, and smoke fill the air around you.");
   set_listen("default","You hear the bubbling of alchemy and the chanting of test casts.");
   set_door("door","/d/darkwood/tabor/room/tfloor4","south",0);
   set_open("door",0);
   "/d/darkwood/tabor/room/tfloor4"->set_open("door",0);

   setOwner("none");
   setLabId("tabor");
   ob=new("/d/magic/obj/mirror");
   ob->move(TO);
}
