#include <std.h>
inherit ROOM;
int count;      
int count2;
      
      void create() {
           ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
       set_light(2);
       set_indoors(1);
      set_short("Office of the deputy patrolman");
   set_long(
@OLI
	This is the office of the deputy in charge of the patrol
units in the city. The room is sparse. The area is filled with 
maps of various places, and things. You notice none of the 
equipment you were expecting. Maybe its somewhere else -- 
maybe.
	The room is ocupied by the current deputy on duty. 
He does not like you being in here.
OLI
     );
  set_smell("default","This room smells as if everything had been just polished.");
 set_listen("default"," ");
         set_exits(([ "east" : "/d/tharis/Tharis/patrolh",
"west":"/d/tharis/Tharis/office_storage"] ));
set_invis_exits(({"west"}));
      set_items(([
       "desk":"This is a large desk. It would need to be searched to find anything.",
       "painting":"This painting is of a magestic woodland scene.",
          ] ));
  }
 void reset(){
	 ::reset();
	if(!present("deputy")) new("/d/tharis/monsters/deputy")->move(TO);
}
void init(){
	::init();
	add_action("search_room","search");
}
int search_room(string str){
	int num;
	write("You search the room thoroughly.");
   tell_room(environment(TO),TPQCN+" searches the room.",TP);
	num = random(6);
	if(num < 3){
			write("You find a concealed door to your west.");
			return 1;
		}
		else {
			write("You find nothing");
	}
}
