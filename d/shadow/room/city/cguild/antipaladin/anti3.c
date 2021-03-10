// under construction from upgrades Lusell is working on getting done *Styx*  3/8/03
 
#include <std.h>
#define ANTI "/d/shadow/room/city/cguild/antipaladin/"
inherit VAULT;

void create(){
  :: create();
  set_terrain(WOOD_BUILDING);
  set_travel(PAVED_ROAD);

  set_property("light",1);
  set_property("indoors",1);
  set_property("no sticks", 1);
//   set_property("no teleport",1);
  set_short("An empty room");
  set_long("This is currently an empty room that appears to still be under construction.  The walls remain unfinished and there isn't much to look at.  It's been swept clean and looks as if it simply awaits some future purpose.");
    set_smell("default","It smells a little musty from disuse. ");
    set_listen("default","You don't hear much except the sounds you make.");
    set_items( ([
    ]) );
    set_exits( ([
	"hall" : ANTI+"hall",
    ]) );
    set_door("brown door", ANTI+"hall","hall",0);
}
