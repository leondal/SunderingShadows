//sewer_room.c

#include <std.h>

inherit ROOM;

void create(){
	int i, j;
	string *names;
	object statue;
	
	::create();
	names = "d/dragon/sewer/statues_d"->query_statues(TO);
	j = sizeof(names);
	if(j){
		for(i = 0;i<j;i++){
			statue = new(OBJECT);
    		statue->set_name(names[i]);
    		statue->set_id(({"statue",names[i]}));
    		statue->set_short("A stone statue of "+capitalize(names[i]));
    		statue->set_weight(10000);
    		statue->set_long("
This was once a famous warrior that journied the lands of Shadowgate.
The accomplishments of this warrior vanished with this stone statue.");
    		statue->move(TO);
    	}
    }
 }

void reset(){
  return;
}
