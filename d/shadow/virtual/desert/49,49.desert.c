#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }

void create() {
 ::create();
   set_terrain(BARREN);
   set_travel(FOOT_PATH);
   set_climate("desert");
 set_indoors(0);
 set_light(2);
 set_short("You are in the Desert");
 set_long(
@DESERT
%^BOLD%^You are in a vast desert.%^RESET%^
There is a great sea to the east and a great marsh to the south.
Sand and desert are everywhere else.
DESERT
 );
 set_exits(([
        "west":"/d/shadow/virtual/desert/49,48.desert",
        "south":"/d/islands/pirates/caves/canyon1",
        "north":"/d/shadow/virtual/desert/48,49.desert"
]));
set_smell("default","You can smell the fresh ocean air blowing from the east.");
set_listen("default","You can hear the crashing ocean waves to the east.");
}

void reset(){
 int r;
 ::reset();
 if(!present("chest")){
   r = random(2);
   if(r==0) new("/d/hm_quest/chests/chest17")->move(TO);
   else new("/d/hm_quest/chests/chest18")->move(TO);
 }
}
