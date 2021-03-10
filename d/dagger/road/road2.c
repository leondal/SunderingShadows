//modified to use the TOLLROOM inherit - so the other tollbooth room could function in the 
//same manner without having the code inside of it as well - less bulky - Saide 11/10/03
#include <std.h>
//#include "short.h"
#include "/d/dagger/road/short.h"
inherit TOLLROOM;
void create()
{
    ::create();
 set_exits(([
	"east" : RPATH "tollbooth",
	"southwest" : RPATH "road1",
	"northeast" : RPATH "road2b",
 ]));
//        set_pre_exit_functions(({"northeast"}),({"go_through_toll"}));
	payed = ({ });
}

void reset(){
    ::reset();
//  if(!present("human guard")) {
//         new(MPATH "dummy")->move(this_object());
//  }
}

