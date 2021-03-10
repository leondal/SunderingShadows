//Coded by Diego//

#include <std.h>
#include "../secrets.h"

inherit ROOM;

void create(){
	::create();
	set_name("hidden path");
   set_short("hidden path");
   set_long(
   	"%^RESET%^%^GREEN%^"+
   	"You have left the main path and you are standing "+
   	"in very dense forest.  You feel the limbs of the "+
   	"trees brushing against you.  There is not very "+
   	"much light here because of the trees.  You see a "+
   	"small cave to the west."+
   	"%^RESET%^"
   );
   set_property("indoors",0);
   set_property("light",1);
   set_smell("default","You smell the wholesome musk of a dense forest.");
   set_listen("default","Occassionally a bird churps or a larger "+
   	"animal can be heard moving around.");
   set_items(([
  	]));
   set_exits(([
   	"cave" : STEFANO+"sm_cave",
   	"east" : STEFANO+"path"
	]));
}