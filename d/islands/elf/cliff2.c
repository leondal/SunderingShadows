//cliff
#include <std.h>
#include "elf.h"
inherit INH"cliff";


void create(){
    ::create();

   set_exits(([ "northeast": ROOMS"grove5", 
  "up": ROOMS"stable", 
  "north": ROOMS"cliff3",    ]));

}

string long_desc(){
  
   return("%^CYAN%^The grove comes to an end at the base of "+
"towering cliffs%^RESET%^.%^CYAN%^ Because of the geothermic energy of the grove%^RESET%^,%^CYAN%^ the granite "+
"walls are warm and moist%^RESET%^.%^CYAN%^ Soft moss lines the bottom of the cliffs%^RESET%^,%^CYAN%^ making "+
"them pleasant to touch%^RESET%^.%^CYAN%^ Numerous plants and trees extend up the cliff side "+
"and line the edge of the cliff far above your head%^RESET%^.%^CYAN%^ At the top of the cliff "+
"you can see the massive white walls which were built%^RESET%^,%^CYAN%^ and are now patrolled "+
"by the elves%^RESET%^%^RESET%^.%^CYAN%^"+
"\n"
"There is a path leading up the cliff."
  "  This part of the cliff looks to be terraced into some kind of ranch.");
 
}
string night_desc() {
  return ("%^BLUE%^This granite cliff slopes upward along "+
  "the edge of the grove%^CYAN%^.%^BLUE%^  The cliff face is lower"+
  " to the south and higher to the north%^CYAN%^.%^BLUE%^  "+
  "At night it is impossible to see the top of this cliff%^CYAN%^.%^BLUE%^"+
  "  The stone face of the cliff is warm%^CYAN%^.%^BLUE%^  "+
  "It is covered in patches of moss and ivy%^CYAN%^.%^BLUE%^  "+
  "Light from the night sky does not reach down here as the"+
  " mist blocks out all but the brightest moonlight%^CYAN%^.%^RESET%^"+
   "\n"
   "There is a path leading up the cliff."
  "  This part of the cliff looks to be terraced into some kind of ranch.");
}
