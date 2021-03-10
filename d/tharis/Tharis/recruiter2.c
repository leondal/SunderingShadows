#include <std.h>
      
        inherit ROOM;
      
      void create() {
           ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
   set_property("no teleport",1);
       set_light(2);
       set_indoors(1);
      set_short("Recruiter's Office");
   set_long(
@OLI
	This is the government of Tharis's way of getting 
around its own red tape. It recruits people to do various 
deeds which would take months to okay for official troops. 
This office is decorated with grand paintings of warriors 
and the walls are hung with shiny swords and such. The 
room is small, but well fitted to its purpose. There are 
several notices of people wanted against the government 
for this and that. 
	In the middle of the room is a desk. Behind it sits 
a stone faced man. He is working attentively on something. 
He has a large ragged book next to him. This is obviously the 
recruiter. 
OLI
     );
  set_smell("default","This room smells musty and sweaty.");
 set_listen("default","The bustle of the streets outside creeps in.");
set_exits((["west":"/d/tharis/Tharis/street7",
"north":"/d/tharis/Tharis/market7" ]));
      set_items(([
"desk":"This desk is cluttered with papers. Behind it sits a recruiter .",
"notice":"It reads about certain people wanted for things you don't understand. You notice that they are all elves."
        ] ));
  }
 void reset(){
 ::reset();
	if(!present("recruiter"))
	new("/d/tharis/monsters/recruiter")->move(TO);
}
