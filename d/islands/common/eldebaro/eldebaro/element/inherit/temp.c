#include <std.h>
#include "../element.h"
inherit ROOM;

void create()
{
    ::create();
	set_short("A carved out cavern");
	set_name("cavern");
    set_long("This appears to be a cavern carved out of the rock and and "+
	"sand on the island.  Huge arching ceilings are over head.  The base "+
	"of the cavern is filled with sand and salt.  There are several tracks"+
	" built to help out with the excavation of this place.");
   set_smell("default","This place smells of earth and sea water.");
   set_listen("default","Slapping of water from the outside fills the cavern.");
   set_property("light",-1);
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
}

void reset(){
int x;
if( !present("elemental")){
 for( x=0; x <2; x++){
 new("/d/magic/mon/priest_eelemental")->move(TO);}
 
  for( x=0; x <2; x++){
 new("/d/islands/common/eldebaro/element/mon/swan")->move(TO);}
 }
}
