#include <std.h>

inherit ROOM;

void create() {
  ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_exits( 
	      (["south" : "/d/standard/monastery"]) );
    set("short","The chapel");
    set("long", 
	sprintf("The %s chapel is solemn and ancient with stained glass "
		"windows and dark oak pews.  Most wedding ceremonies "
		"are performed here.  Type <help marriage> for "
		"information on weddings.", mud_name()) );
   set_items(
	     (["pews" : "Ancient oak seats, darkened by eons of "
	         "bottoms resting on them.",
	       "windows" : "The windows show highlights of "
	         "mud history, many of them gorey.",
	       "ceremony" : "The ceremony is only visible when you "
	         "scroll back."]) );
}

