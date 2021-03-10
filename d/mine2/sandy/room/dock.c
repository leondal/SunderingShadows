#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Sandys' dock.");
    set_long(""
"%^BOLD%^WHITE%^You are on a large dock.\n%^RESET%^"
"You are at the dock of sandy!  There are many ships docked here.  There are "
"rows after rows of boats that are owned by many people who use them to explore "
"the great ocean.  You see large waves crash into the break walls, and you can "
"see gulls flying about all over the area.  To the east is the west gate of Sandy."
""
"");

     set_listen("default","You hear waves crash into the break walls.");
     set_smell("default","You the ocean.");
 
    set_exits(([

      "shore" : "/d/mine2/sandy/room/sandy25",


    ] ));
    set_items(([
         "dock" : "The dock is very large, and filled with many ships.",
         "ships" : "Almost all the ships here are 12 meter sailboats.",
         "ocean" : "The ocean is rough, and it is filled with many islands.",
         "waves" : "The waves are large.",
    ] ));
}
void init(){
    ::init();
         add_action("board","board");
}
int board(string str){
if(lower_case(str) != (string)TPQN){
write("You can only board your own ship!");
return 1;
}
if(!present(str+"ship")) {
this_object("/d/mine2/virtualocean/rooms/cloneroom")->move();
return 1;
}
  if(!present(str+"ship")) {
write("You either do not own a ship, or it's not at this island!");
return 1;
}
this_player()->move_player("/d/mine2/virtualocean/boats/"+str+"ship");
return 1;
}
