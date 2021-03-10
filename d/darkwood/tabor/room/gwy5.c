//updated by Circe 6/2/04 with color, etc
// Gwydion Street and Greene Street, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// gwy5.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
  ::create();
  set_travel(DIRT_ROAD);
  set_terrain(CITY);
  set_light(2);
  set_name("Gwydion Street and Greene Street, Tabor");
  set_short("Gwydion Street and Greene Street, Tabor");
  set_long(
@TABOR
%^BOLD%^Gwydion Street and Greene Street, Tabor%^RESET%^
You are at the intersection of %^BOLD%^%^BLUE%^Gwydion Street %^RESET%^and %^GREEN%^Greene Street %^RESET%^in the
town of Tabor.  To the northeast, you can see the summit of %^RED%^Mount Dragon%^RESET%^
in the distance topped by the %^CYAN%^Wizard's Tower %^RESET%^of Tabor.  To the south you
can see a squat %^BOLD%^%^BLACK%^grey stone %^RESET%^building down %^GREEN%^Greene Street%^RESET%^.  To the west,
you can make out what looks like a %^ORANGE%^small building %^RESET%^with a stockade around
it and a wide %^GREEN%^grassy field%^RESET%^.  To the east, you see a small shop 
with a front made of %^BOLD%^%^CYAN%^glass%^RESET%^.  Directly to the north is a 
%^RED%^rowdy bar%^RESET%^, from which raucous laughter seems to pour day and night.

%^BOLD%^%^MAGENTA%^There is a sign you can look at here.

%^BOLD%^%^BLUE%^Gwydion Street %^RESET%^continues to the east and west.
%^GREEN%^Greene Street %^RESET%^continues to the south.
TABOR
    );
  set_exits(([
    "east" : ROOMDIR+"gwy4",
    "west" : ROOMDIR+"gwy6",
    "south" : ROOMDIR+"greene3",
    "north" : ROOMDIR+"pig_and_whistle"
  ]));
  set_listen("default","You hear the sounds of a busy town all around you.");
  set_smell("default","The slightly rank scent of a busy city "+
    "lingers in the air.");
  set_items(([
    "sign" : "%^GREEN%^Greene Street%^RESET%^: South to %^BOLD%^%^BLACK%^Town Gaol %^RESET%^and %^YELLOW%^Caerveron Square\n"+
	       "%^BOLD%^%^BLUE%^Gwydion Street%^RESET%^: East to %^MAGENTA%^Mathowvy Road%^RESET%^, west to the %^GREEN%^Fields of Tempus%^RESET%^",
    "field" : "You think you can see roped off areas in the field as well as archery targets.",
    "building" : "The building is made of grey stone and you think you can see black bars in the windows."
  ]));
 }

void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

