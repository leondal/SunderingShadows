// Garrison Road, Shadow
// Thorn@ShadowGate
// 970215
// City of Shadow 1997 revision

#include <std.h>
#include "/d/shadow/room/shadow.h"

inherit ROOM;

void create() {
  ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
	set_light(2);
	set_indoors(0);  
	set_short("Garrison Road, Shadow");
  set_long(
@SHADOW
%^BOLD%^CYAN%^Garrison Road%^RESET%^
  You are on Garrison Road, leading north from the center of the great
city of Shadow.  To the south, you can see the taller stone
buildings in the center of the city, such as the Adventurer's Hall as
well as the banking district.  
  Right now, you appear to be in the hotel district of the city.  Many
weary traders and travellers take their rest in hotels in the area.  
In fact, there is one to the east of you which beckons with an open 
door for you to come in and rest.
  Garrison Road continues to the north and south.
SHADOW
    );
	set_exits(([
        "south" : "/d/shadow/room/main/garrison4",
        "north" : "/d/shadow/room/main/garrison2",
  "east" : ROOMDIR+"hotel"
  ] ));     
  set_smell("default","You smell the cool fresh air.");
  set_listen("default","You hear the sounds of people moving around the city.");
}

void reset(){
   ::reset();
        if(!present("street_light",TO))
                new(MISCDIR+"street_light")->move(TO);
}
