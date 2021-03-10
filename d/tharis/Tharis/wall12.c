// /d/tharis/Tharis/wall12.c //
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_light(2);
    set_indoors(0);
   set_short("The ramparts of the wall around Tharis");
    set_long(
@OLI
        You are on the ramparts of the wall. To the south is
the inside of the bustling city of Tharis.  You can see the
many shops of the commercial section that is directly below
you. The stone battlements have been worn by the weather
but still show their fine craftsmanship. The wall is patrolled
sparsely. The tower at the West Gate is to the southwest. In the
distance on either side are the West and East Walls.
OLI
    );
   set_smell("default","Your senses are accosted by the normal smells of a city.");
   set_listen("default","The city bustles below you.");
    set_exits(([
"west" : "/d/tharis/Tharis/tower6",
"east" : "/d/tharis/Tharis/wall13",
    ] ));
}
void reset(){
int num;
int i;
 ::reset();
  if(!present("patrol")) {
num=random(4);
for(i=0;i<num;i++){
  new("d/tharis/monsters/wall_patrol")->move(TO);
}
} 
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/