// level 2 halls - rooms with doors

#include <std.h>
#include "../inherit/ruins.h"
inherit VAULT;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",1);
    set_name("Upper corridor of an abandoned building");
    set_short("%^ORANGE%^Upper corridor of an abandoned building%^RESET%^");
    set_smell("default","An old, musty smell brushes at your nose.");
    set_listen("default","Whispers echo off the walls around you... or is that just the wind?");
    set_items(([
      "floor" : "%^ORANGE%^The floor is perfectly level beneath your feet, set with "
"%^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^-coated tiles.  Along the centre of the hallway is a line of "
"old, %^RED%^moroon%^ORANGE%^ carpet.%^RESET%^",
      "carpet" : "%^ORANGE%^A wide line of %^RED%^deep moroon%^ORANGE%^ carpet runs along the centre of "
"the hallway and up to the door, cushioning your steps.  It looks rather old and is smudged with grime, "
"but is otherwise undamaged.%^RESET%^",
      ({"walls","wall"}) : "%^ORANGE%^Thick %^BLACK%^%^BOLD%^dirt%^RESET%^%^ORANGE%^ coats the stone "
"walls on either side of you, though an occasional clearer patch reveals what must have once been "
"detailed patterns upon them; somehow these have been preserved over the ages.  Ornate bordering lines "
"the edges where the walls meet the ceiling, covered in dust and the occasional spiderweb.%^RESET%^",
      "roof" : "%^ORANGE%^The roof reaches high above your head, shrouded in a thick layer of "
"%^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  Beneath the grime, you can just make out the remains of what "
"must have once been elaborately decorated mosaic tiles.  No cracks or damages mar the tiles, even "
"though they must be very old.  Ornate bordering from nearby walls traces along the ceiling's "
"edges, covered in dust and an occasional spiderweb.%^RESET%^",
      ({"dirt","dust"}) : "%^ORANGE%^A thick layer of %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^ coats "
"every visible surface.  The building has probably been abandoned for a long time.%^RESET%^",
      ({"window","windows"}) : "%^ORANGE%^Many high windows of "
"%^MAGENTA%^mu%^BLUE%^lt%^GREEN%^ic%^ORANGE%^ol%^RED%^ou%^MAGENTA%^re%^BLUE%^d%^ORANGE%^ glass are set "
"within the stone walls of the building, shedding weak light into the hallway. However, dirt and dust of "
"ages past has %^BLACK%^%^BOLD%^blackened%^RESET%^%^ORANGE%^ their surfaces, making them impossible to "
"see through.%^RESET%^"
    ]));
}

void set_string(string id, string which, string str) {
   if(!id) return;
   if(!which) return;
   if(!doors) return;
   if(!doors[id]) return;
   if (which == "open") {
     switch(random(3)) {
       case 0:
       str = "The door swings open silently, shedding a little dust onto the carpet.";
       break;
       case 1:
       str = "The door opens with a soft whisper as it brushes along the carpet.";
       break;
       case 2:
       str = "The door slides open soundlessly despite its aged hinges.";
       break;
     }
   }
   else {
     switch(random(3)) {
       case 0:
       str = "The door slides easily shut.";
       break;
       case 1:
       str = "The door closes with a quiet click.";
       break;
       case 2:
       str = "The door offers not a creak as it closes.";
       break;
     }
   }
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
