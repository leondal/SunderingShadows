#include "../shadow.h"
#include <daemons.h>

inherit ROOM;


void create(){
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
	set_indoors(1);
	set_light(2);
	set_property("no teleport", 1);
        set_short("Pendaxin's house");
	set_long(
@MELNMARN
%^BOLD%^You are standing in Pendaxin's home.%^RESET%^
You can see his bed in the corner and his 
desk in the other corner.
MELNMARN
	);
	set_exits(([
	"north":VILLAGEDIR+"mainroad1"
	]));

}
void reset(){
   int tmp,hour;
   object ob;

/*  using master object in the shops, need to change this if he's going to show up here
      tmp    = EVENTS_D->check_time();
      hour   = EVENTS_D->query_hour( tmp );
	if( (hour > 7) && (hour < 17)){
		ob = find_object_or_load(ROOMDIR+"gs_store");
		if(!present("pendaxin",ob)) 
			//new(MONDIR+"pendaxin")->move(ob);
	} else if((hour > 6 && hour < 8) || (hour > 16 && hour < 19))
		return;
	else if(!present("pendaxin",TO)) 
		//new(MONDIR+"pendaxin")->move(TO);
	
*/
	::reset();
}
