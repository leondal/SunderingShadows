#include <std.h>
#include <rooms.h>


int open;
inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_terrain(LIGHT_FOREST);
    set_travel(GAME_TRACK);
    set_short("Cave Entrance");
    set_long("The Shadowlord path abruptly ends, leaving you at the foot of a huge"
" hill in the gnarled woods.  You can only see patches of the blue sky through"
" breaks in the trees and dark clouds.  Before you, the ground drops into a"
" small depression, what may have been a natural pool at one time.  The"
" steep hillside before you is eroded and covered with many warped, fibrous"
" roots from the trees above.\n");
    set_exits((["east":"/d/deku/open/forest54"]));
    set_items(([
    ({"roots","root"}):"%^RESET%^%^ORANGE%^The roots are large and fibrous, gnarled from the years of exposure to the elements.  They stick out of the hillside, eroding the soil away.  It looks as though they could be hiding something behind them.%^RESET%^",
    "trees":"%^RESET%^%^GREEN%^The trees grow tall overhead.%^RESET%^"
    ]));
    set_search("default","%^RESET%^%^ORANGE%^Something behind the roots catches your eye.%^RESET%^");
    set_search("roots",(:TO,"search_pile":));
    open = 0;
}
   void search_pile(){
   if(query_exit("opening")!=ROOM_VOID){
   tell_object(TP,"You've already found the hidden entrance.");
   return ;
   }
   tell_object(TP,"You search around and find an entrance to a cave behind the roots!");
   add_exit("/d/deku/open/cave_r1","opening");
   set_pre_exit_functions(({"opening"}),({"goroots"}));
   return ;
   }
int goroots (){
   if(present("root")){
   tell_object(TP,"The roots seem to actively block your way!!");
   return 1;
   }
   if (open) {
    tell_object(TP,"You move through the roots into the realm of Vexia, the
greenhag.");
    tell_room(ETP, TPQCN+" squeezes through the roots and disappears.",TP);
    return 1;
  }
  open = 1;
  tell_object(TP,"As you try to squeeze through the roots, they come alive and attack.");
  tell_room(ETP,""+TPQCN+" tries to squeeze through the roots but they come alive and attack!", TP);
  new("/d/deku/monster/root")->move(TO);
  new("/d/deku/monster/root")->move(TO);
  new("/d/deku/monster/root")->move(TO);
  return 0;
}
void reset() {
  ::reset();
  if (open) open = 0;
  if(query_exit("opening")){
  remove_exit("opening");
  }
}