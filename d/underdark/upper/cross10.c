#include <std.h> 
#include "../defs.h" 
inherit INH+"crossroad"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"  %^RESET%^%^ORANGE%^A passage leads off to the south from here, though "
"recent seismic activity has caused a shifting of earth to block the way forward, "
"leaving only the east and west passageway open and free to travel.  A bit of %^BOLD%^%^BLACK%^"+
"inky darkness%^RESET%^%^ORANGE%^ toward the top of the cave-in suggests there might be "+
"a way past.\n%^RESET%^"); 

add_item(({"earth","passage"}),"%^RESET%^%^ORANGE%^The passage southward looks "
"similar to the one you're standing in, though the spill of earth and rock has "
"made travel that direction impossible.%^RESET%^");

add_item(({"crack","darkness","inky darkness"}),"%^BOLD%^%^BLACK%^A narrow crack toward the "+
"ceiling suggest a way over.  Maybe if you wiggled about you could %^RESET%^enter%^BOLD%^"+
"%^BLACK%^ it.%^RESET%^");

   set_exits(([ 
"northwest":UPPER"cross09",
"northeast":UPPER"cross11",
   ])); 
}

void init(){ 
::init(); 
add_action("enter_fun", "enter"); 
} 

int enter_fun(string str){ 
if(!str){ 
tell_object(TP,"Enter what?"); 
return 1; 
} 
if(str == "crack"){ 
tell_object(TP,"You slide through the crack and enter the cavern to "+ 
"the south."); 
tell_room(ETP,""+TPQCN+" slides through the crack on the south "+ 
"wall.",TP); 
TP->move_player("/d/underdark/mines/room/fissure"); 
return 1; 
}
return 0; 
}
