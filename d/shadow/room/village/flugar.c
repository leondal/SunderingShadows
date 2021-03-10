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
   set_short("Flugar's house");
	set_long(
@MELNMARN
%^BOLD%^You are standing in Flugar's home.%^RESET%^
You can see his bed in the corner and his 
desk in the other corner.
MELNMARN
	);
	set_exits(([
	"south":VILLAGEDIR+"mainroad2"
	]));

}
void reset(){
/*  using master object in the shops, need to change this if he's going to show up here
   int tmp,hour;
   object ob;

      tmp    = EVENTS_D->check_time();
      hour   = EVENTS_D->query_hour( tmp );
	if( (hour > 7) && (hour < 17)){
		ob = find_object_or_load(ROOMDIR+"armor");
		if(!present("flugar",ob)) 
			new(MONDIR+"flugar")->move(ob);
	} else if((hour > 6 && hour < 8) || (hour > 16 && hour < 19))
		return;
	else if(!present("flugar",TO)) 
		new(MONDIR+"flugar")->move(TO);
*/	
	::reset();
}
