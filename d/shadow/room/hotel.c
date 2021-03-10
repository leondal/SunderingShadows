#include <std.h>
#include "melnmarn.h"
inherit HOTEL;

void create(){
    ::create();
    set_property( "light" , 3); 
    set_property("indoors" , 1);
    set_short("The Shadow Daemon Hotel");
    set_long(
@MELNMARN
%^BOLD%^The Shadow Daemon Hotel.%^RESET%^
There is a registry counter on the south side of the room.
The clerk will check you in and out. All of the rooms
here are very secure. We have never had a death or theft,
of any players or possessions since we opened.
This hotel has beds for rent. < %^BOLD%^help hotel%^RESET%^ > will get you 
help on renting a room in the hotel.
MELNMARN      
);
    set_listen("default","You hear the shuffling of strangers moving around the hotel.");
    set_smell("default","You hear the sounds of peoplemoving about around you. "); 
    set_search("default","You look around aimlessly, and find nothing worthwhile.");
    set_exits( ([
	"north":ROOMDIR+"ntrproad"
             ]) );
    set_rooms(([
	"westgroup":6,
	"eastgroup":5,
	"southroom":3,
	"singleroom":1,
	"doubleroom":2,
	"tripleroom":3,
	"quadroom":4,
	]));
    set_cost(10);
}
