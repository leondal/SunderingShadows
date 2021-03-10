#include <std.h>
#include "/realms/lujke/tecqumin/tecqumin.h"
#define WEMIC "/realms/lujke/wemic/rooms/"
#define BUILDER "/realms/lujke/d/atoyatl/maze_d.c"

inherit OBJECT;

void create(){
  ::create();
      set_id(({"builder", "maze builder", "maze"}));
      set_short("a virtual maze builder");
      set_long("a strange looking box with a few buttons on it, that" 
              +" seems to be spilling out randomly generated mazes onto"
              +" sheets of paper."); 
 
   	set_lore("It is widely rumoured that Lujke disapproves of mazes on"
              +" principle, beacuse He can never find His way round them."
              +" However, legend has it that on one momentous Sunday"
              +" morning He thought to Himself and spake thusly: 'If we"
              +" are to have mazes, and it seemeth that we are, then they"
              +" should be good mazes, that are different every time,"
              +" that the munchkin among you shall be as lost as the"
              +" newbie.' And as He spake, so it came to be. And much"
              +" rejoicing was there from the tower of the Immortals, and"
              +" much wailing and gnashing of teeth was to be heard among"
              +" those who are kin to munch.");
   	set_property("lore difficulty",31);
   	set_weight(2);
   	set_value(2);
}

void init(){
  ::init();
  add_action("make_maze", "create");
  add_action("clear_maze", "clear");
  add_action("place", "place");

}

int make_maze(string str){
  BUILDER->set_doornames(({"door"}));
  BUILDER->set_doordescs(({"a standard wooden door, with a two tumbler lock"
                   +" arrangement."}));
  BUILDER->set_roompath(JUNG_ROOM);
  BUILDER->set_southroom(WEMIC + "path14.c");
  BUILDER->set_northroom(JUNG_ROOM + "j_link1.c");
  BUILDER->set_eastroom(JUNG_ROOM + "j_link8a.c");  
  BUILDER->set_special_rooms( ({JUNG_ROOM + "jung_clearing.c", JUNG_ROOM + "jung_waterhole"}) );
  BUILDER->init_maze(5, 5, JUNG_ROOM, "j_maze", 50, TP);
  tell_object(TP,"Okay, you built a maze");
  return 1;
}

int clear_maze(string str){
  BUILDER->clear_maze(JUNG_ROOM+"j_maze", 10);
  return 1;
}