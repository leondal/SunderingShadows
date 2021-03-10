#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keephall2";

void create(){ 
   ::create();
   set_name("Dead end of a ruined keep");
   set_short("%^RESET%^%^CYAN%^Dead end of a ruined keep%^RESET%^");
   set_long(((:TO,"my_long":)));
   set_exits(([
     "north" : ROOMS"keep19",
     "south" : ROOMS"crawler",
   ]));
   set_items(([
     ({"walls","holes","cracks"}) : "%^BLUE%^The stone walls that make up the "
"keep are in poor shape here.  They don't look as if they're about to fall down"
", but there are sizeable holes and cracks running through some blocks, letting "
"in the wind and allowing moisture to creep inside.  %^GREEN%^Moss %^BLUE%^has "
"grown over some sections, making footing dangerous.  %^ORANGE%^Rubble "
"%^BLUE%^is all that remains of the southern wall, hiding whatever lies behind "
"it.%^RESET%^",
     ({"floor","dust","dirt","mud"}) : "%^ORANGE%^The floor is made of stone "
"bricks and is covered in dirt and dust.  Streaks of mud have been tracked "
"through the hallway by something.%^RESET%^",
     "moss" : "%^GREEN%^Patches of moss have grown over the walls and floor.  "
"They are wet and slimy, making footing treacherous in some places.%^RESET%^",
     "rubble" : ((:TO,"rubble_desc":)),
   ]));
   find_object_or_load(ROOMS"crawler");
   set_search("default","%^ORANGE%^Only the %^YELLOW%^rubble %^RESET%^"
"%^ORANGE%^stands out here.%^RESET%^");
   TO->collapse_exit("south",50);
}

void reset() {
   object *pplz;
   int present, i;
   ::reset();
   present = 0;
   if(member_array("south",TO->query_exits()) != -1) {
     pplz = all_living(find_object_or_load(ROOMS"crawler"));
     if(sizeof(pplz)) {
       for(i = 0;i< sizeof(pplz);i++) {
         if(userp(pplz[i]) && !pplz[i]->query_true_invis()) present = 1;
       }
     }
     if(!present) {
       TO->collapse_exit("south",50);
       tell_room(TO,"%^ORANGE%^Stones tumble down the pile of rubble, blocking "
"any way further south.  You will have to %^YELLOW%^dig south%^RESET%^"
"%^ORANGE%^ to get through them.%^RESET%^");
     }
   }
}

string rubble_desc() {
   if(member_array("south",TO->query_exits()) == -1) 
     return("%^ORANGE%^The southern wall has completely fallen in, leaving "
"a great pile of rubble that hides anything behind or beneath it.  You could "
"try to %^YELLOW%^dig south%^RESET%^%^ORANGE%^ to create a way "
"through.%^RESET%^");
   return("%^ORANGE%^The southern wall has completely fallen in, leaving "
"a great pile of rubble that hides anything behind or beneath it.  Fortunately "
"someone has cleared a way through it to the south.%^RESET%^");
}

string my_long() {
   if(member_array("south",TO->query_exits()) == -1)
     return("%^RESET%^%^CYAN%^Dead end of a ruined keep%^RESET%^\n"
"You have reached the dead end of a hallway in a ruined keep.  The "
"%^BLUE%^walls %^RESET%^are in poor shape here, with holes and cracks that let "
"the weather in.  The %^ORANGE%^floor %^RESET%^is covered in dust and dirt, and "
"streaks of mud have been tracked across it.  Patches of %^GREEN%^moss "
"%^RESET%^have crept over the walls and floor, making travel treacherous in "
"some places.  The entire south wall is nothing but %^ORANGE%^rubble%^RESET%^, "
"while the hallway continues back northwards.");
   return("%^RESET%^%^CYAN%^Dead end of a ruined keep%^RESET%^\n"
"You have reached the dead end of a hallway in a ruined keep.  The "
"%^BLUE%^walls %^RESET%^are in poor shape here, with holes and cracks that let "
"the weather in.  The %^ORANGE%^floor %^RESET%^is covered in dust and dirt, and "
"streaks of mud have been tracked across it.  Patches of %^GREEN%^moss "
"%^RESET%^have crept over the walls and floor, making travel treacherous in "
"some places.  The entire south wall is nothing but %^ORANGE%^rubble%^RESET%^, "
"while the hallway continues back northwards.\n");
}
