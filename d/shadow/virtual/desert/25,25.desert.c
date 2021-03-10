#include <std.h>

inherit ROOM;

int is_virtual() { return 1; }

void create() {
set_indoors(0);
 ::create();
   set_terrain(BARREN);
   set_travel(FOOT_PATH);
 set_light(2);
 set_short("You're in the Desert");
 set_long(
@MELNMARN
%^BOLD%^You are in a vast desert.%^RESET%^
You can see nothing but sand for miles and miles.
The sun beats down on your head.
MELNMARN
 );
 set_exits(([
	"west":"/d/shadow/virtual/desert/25,24.desert",
	"east":"/d/shadow/virtual/desert/25,26.desert",
	"north":"/d/shadow/virtual/desert/24,25.desert",
	"south":"/d/shadow/virtual/desert/26,25.desert",
]));
set_smell("default","The dry desert air fills your nostrils.");
set_listen("default","You can hear the breeze blowing over the sand, it is so quiet here.");
new("/d/laerad/mon/assassin")->move(TO);
}
