//study
#include <std.h>
#include <rooms.h>
#include "../yntala.h"
inherit VAULT;
int searched;
int tap;


void create(){
::create();
   set_property("indoors",1);
   set_property("light",-3);
   set_property("no teleport",1);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("%^RESET%^An old study");
   set_short("%^RESET%^An old study%^RESET%^");
   set_listen("default","Whispers and soft hisses seem to float upon the stale air.");
   set_long((:TO,"ldesc":));
   set_items(([
   "carpet":"%^RED%^Rich red carpet lines the floor and is quite plush.  It is still very fresh and remains untouched.",
   "tapestries":"%^BOLD%^%^BLUE%^Deep blue tapestries of the finest quality hang from the walls.  Stars, moons and suns, have been expertly embroidered upon them in depictions of the constellations.",
   ({"bookshelves","oak bookshelves"}):"%^RESET%^%^ORANGE%^Large, heavy oak bookshelves stand neatly against the northern wall behind the large desk that sets in the center of the room.",
   "books":"Many books are still stacked on the bookshelves.",
   ({"desk","oak desk"}):"%^RESET%^%^ORANGE%^This a very large, heavy oak desk that is in excellent shape, a few %^BOLD%^%^WHITE%^papers %^RESET%^%^ORANGE%^still clutter the top of it.",
   "papers":"%^BOLD%^%^WHITE%^A few papers still lay on the top of the desk, they do not appear to have anything written on them.",
   "table":"This is a long table that looks as though it was used to conduct meetings.  Twelve chairs set around it.",
   "chairs":"Twelve plain chairs set around the long table along the eastern wall, and a large, more comfortable chair sets behind the oak desk in the center of the room.",
   "couch":"%^BOLD%^%^BLUE%^A long blue couch sets along the western wall.  It is quite old, but still comfortable looking.  A few pillows have been set along the wooden frame to make it soft.",
   "pillows":"%^BOLD%^%^BLUE%^These are quite obviously pillows made just for this couch and for the sole purpose of making it more comfortable.  They are made of a rich shade of blue and have small tassles hanging from the corners.",
]));
   set_exits((["hall":INRMS+"doorroom"]));
   set_pre_exit_functions(({"west"}),({"go_out"}));
   set_door("door",INRMS+"doorroom","hall","old_key");   
   set_door_description("door","%^RESET%^%^ORANGE%^This is an old, rotting door that doesn't appear to have seen much use in many, many years.  The wooden planks look as though they are about ready to fall apart, but somehow it still stands straight within the stone frame that holds it in place.");
   set_locked("door",1);
   lock_difficulty("door",-70,"lock");
   set_search("shelves",(:TO,"search_pile":));
   set_search("bookshelves",(:TO,"search_pile":));
   set_search("books",(:TO,"search_pile":));
   set_search("bookshelf",(:TO,"search_pile":));
   set_search("tapestries",(:TO,"search_taps":));
   searched = 1;
   tap = 1;
   set_property("unmoved", 1);
}
void reset() {
   ::reset();
   searched = 1 ;
   tap = 1;
   TO->set_property("unmoved", 1);
   query_exit("west");
   remove_exit("west");
}
void init(){
  ::init();
  add_action("push","push");
  add_action("pull","pull");
}
int go_out() { 
   if(TO->query_property("unmoved")) {
      tell_object(TP,"%^RESET%^%^BLUE%^You can't get through that exit with the couch in the way!%^RESET%^");
      return 0;
   }
   return 1;
}

int push(string str){
   if(!str) notify_fail("What are you trying to push?");
   if(str == "couch"||str=="the couch"){
      if(TO->query_property("unmoved")) {
         tell_object(TP,"%^RESET%^%^BLUE%^You walk around to one end of the couch and push it out of the way.%^RESET%^");
         tell_room(TO,""+TPQCN+" walks around to the end of the couch and moves it out of the way.", TP);
         TO->remove_property("unmoved",1);
         return 1;
      }
      if(!TO->query_property("unmoved")) {
         tell_object(TP,"%^RESET%^%^BLUE%^You walk over to the end of the couch and push it back into place.%^RESET%^");
      TO->set_property("unmoved",1);
      return 1;
      }
   }
} 
int pull(string str){
   if(!str) notify_fail("What are you trying to pull?");
   if(str == "western tapestry"||str=="the western tapestry"){
      if (TO->query_property("unmoved")){
         tell_object(TP,"%^RESET%^%^BLUE%^The couch is in the way!%^RESET%^");
         return 1;
      }
      if ((!TO->query_property("unmoved")) && tap == 1){  
         tell_object(TP,"%^RESET%^%^BLUE%^You move the tapestry out of the way and reveal a secret passage!%^RESET%^");
         tell_room(TO,""+TPQCN+" moves the western tapestry out of the way and reveals a secret passage!", TP);
         add_exit(INRMS+"spassage","west");
         tap = 0;
      return 1;
      }
      else{
         tell_object(TP,"%^RESET%^%^BLUE%^You slide the tapestry back into place and cover the exit!%^RESET%^");
         remove_exit("west");
         tap = 1;
      return 1;
      }
   }
   else{
      tell_object(TP,"%^RESET%^%^BLUE%^Are you trying to pull the tapestry to the side?%^RESET%^");
   return 1;
   }
} 


void search_pile() {
   if(searched <= 0) {               
	tell_object(TP,"It would appear that there are no books of value left.");
      return ;
   }
   if (searched == 1) {  
      write("You look over the bookshelf and pull out a book simply titled %^BOLD%^Journal.\n");
      tell_room(TO,""+TPQCN+" reaches up to the bookshelf and pulls down a simple, leatherbound book.", TP);
      new(OBJD+"book.c")->move(TO);
      searched = 0;
      return 1;
   }
}
void search_taps() {
      write("%^RESET%^%^BLUE%^Upon closer inspection it would appear that the western tapestry can be pulled to the side.\n");
      return 1;
}
string ldesc(string str){
   return("This old study has hardly been touched, in fact, it probably looks as fresh as the day it was made."
"  Rich %^RED%^red %^RESET%^carpet lines the floor, and %^BLUE%^deep blue %^RESET%^tapestries hang from the walls."
"  %^ORANGE%^Oak bookshelves %^RESET%^line northern wall, and seem to still have an array of books stacked neatly upon"
" them.  A large %^ORANGE%^oak desk %^RESET%^sets centered in the room, and a few %^BOLD%^%^WHITE%^papers %^RESET%^"
"lay strewn about it.  Along the eastern wall is another long table, surrounded by twelve wooden chairs.  Though"
" those chairs look nothing near as nice as the chair behind the huge %^ORANGE%^desk, %^RESET%^they are still quite"
" comfortable to look at.  Along the western wall is a long, %^BLUE%^blue couch %^RESET%^that has a few plush pillows"
" strewn across it.%^RESET%^");
} 

