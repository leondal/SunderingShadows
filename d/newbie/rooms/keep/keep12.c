#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keephall";

void create(){ 
   ::create();
   set_long(::query_long() +"  %^CYAN%^Hinges %^RESET%^on the walls suggest "
"that a pair of grand doors once stood barring the way east, but they are long "
"destroyed, leaving the corridor to open onto a vast mess hall.  A little to "
"the west is a %^RED%^staircase %^RESET%^that appears to lead to a floor above "
"this one.  A side room opens off from the southern side of the corridor.\n");
   set_exits(([
     "east" : ROOMS"keep14",
     "west" : ROOMS"keep11",
     "south" : ROOMS"keep13",
   ]));
   add_item("stair","%^RED%^An old spiral staircase lies just off to the side "
"of this hallway, leading upwards to the second floor of the keep.%^RESET%^");
   add_item("stairs","%^RED%^An old spiral staircase lies just off to the side "
"of this hallway, leading upwards to the second floor of the keep.%^RESET%^");
   add_item("staircase","%^RED%^An old spiral staircase lies just off to the "
"side of this hallway, leading upwards to the second floor of the "
"keep.%^RESET%^");
   add_item("hinges","%^CYAN%^Hinges along the wall suggest a pair of grand "
"doors that once barred the way east.  They are long since destroyed, though, "
"leaving the corridor to open onto a vast mess hall, which is in a sorry "
"state.%^RESET%^");
   add_item("doors","%^CYAN%^Hinges along the wall suggest a pair of grand "
"doors that once barred the way east.  They are long since destroyed, though, "
"leaving the corridor to open onto a vast mess hall, which is in a sorry "
"state.%^RESET%^");
   add_item("hall","%^CYAN%^Hinges along the wall suggest a pair of grand "
"doors that once barred the way east.  They are long since destroyed, though, "
"leaving the corridor to open onto a vast mess hall, which is in a sorry "
"state.%^RESET%^");
   add_item("mess hall","%^CYAN%^Hinges along the wall suggest a pair of grand "
"doors that once barred the way east.  They are long since destroyed, though, "
"leaving the corridor to open onto a vast mess hall, which is in a sorry "
"state.%^RESET%^");
   set_door("door",ROOMS"keep13","south",0);
   set_door_description("door","%^ORANGE%^A simple wooden door, scratched and "
"grimy from years of abuse, but still intact.%^RESET%^");
   set_string("door","open","The door squeaks open.");
   set_string("door","close","The door squeaks shut.");
}
