#define owner ("abolition")
#include <std.h>

inherit ROOM;
object ship;

void create(){
    ::create();
    set_indoors(0);
set_light(2);
    set_short("Your are on a large sailboat.");
    set_long(
@ABOLITION
%^BOLD%^WHITE%^You are on a large 12 meter sailboat.\n
%^BOLD%^BLUE%^The sailboat is very large, and looks like it is very fast.
The boat is a retired Americas Cup ship.
There are many people waiting to take orders from you.
This ship looks very tough.
ABOLITION
);
set_smell("default","You smell fresh, cold air.");
set_listen("default","You hear the wind filling the sails, and the waves crashing");
ship = new("/d/mine2/virtualocean/boats/"+owner+"ship.c");
 ship->move("/d/shadow/virtual/sea/35,23.sea.c");
}
void init(){
    ::init();
         add_action("sail","sail");
         add_action("scan","scan");
         add_action("leave","leave");
}
int sail(string str){
  if(str != "north" && str != "south" && str != "east" && str != "west" && str != "ocean" && str != "dock"){
write("You can't sail that direction!");
return 1;
}
write("You sail the sailboat "+str+".\n");
    ship->force_me(str);
ship->mon_look();
return 1;
}
int scan(string str){
write("%^BOLD%^WHITE%^Beyond your boat you can see this.\n");
ship->mon_look();
return 1;
}
int leave(string str){
if(str == "ship"){
write("You start down the ladder.");
if(!present("dock",ship))
write("You can't swim!\n You would die!\n");
return 1;
}
this_player()->move(environment(present("dock",ship)));



}
