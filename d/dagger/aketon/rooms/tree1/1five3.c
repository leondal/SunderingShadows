#include "/d/dagger/aketon/short.h"
#include <move.h>

#define ITEM_SAVE "/d/save/aketon/1five3"

inherit ROOM;

string fork_owner,knife_owner;

void create() {
   ::create();

   fork_owner = "";
   knife_owner = "";
   restore_me(ITEM_SAVE);
   if(!fork_owner)
      fork_owner = "";
   if(!knife_owner)
      knife_owner = "";
   save_me(ITEM_SAVE);

   if(query_light())
      remove_property("light");
   set_property("light",2);
   set_property("indoors",1);
   set_short("Kitchen on top of the tree");
   set_long("%^GREEN%^Kitchen on top of the tree%^RESET%^
This kitchen is possibly the cleanest kitchen you have ever seen. Not a single "
      "drop of oil, not the smallest piece of garbage can be found here. "
      "White china dishes and plates are put tidily on the shelves over on "
      "the far end of the room. Stoves for baking and cooking are towards "
       "your right. On your left, a large pile of things is placed on top "
      "of the table. Many shiny silver and golden eating utensils are "
       "stored in the crystal cabin beside you.");
   set_items( (["kitchen":"The kitchen is quite large and is built on the "
      "tree branches. It is very clean and tidy.",
      "windows":"You can see the other parts of the house through the "
      "windows.",
      ({"dishes","plates"}):"They are made of white china.",
      "shelves":"Lots of dishes and plates are stored there.",
      "stoves":"Cook use them to cook food.\nOuch! You almost had your "
      "hairs burnt as you get too close one of the stove.",
      "things":"Too many things here, different utilities...",
      "utensils":"These forks and knifes are made of gold or silver!",
      "cabin":"It is made of crystal.",
      "knifes":"Lots knifes here, perhaps you can use some of them.",
      "forks":"A large pile of fork is here."]) );
   set_smell("default","You smell cheese.");
   set_listen("default","It is quiet here.");
   set_exits( (["northeast":RPATH1+"1five2",
      "east":RPATH1+"1five1"]) );
   set_search( "knifes", (: TO,"search_knifes" :) );
   set_search( "forks", (: TO,"search_forks" :) );
}

void search_knifes() {
   object obj;
   if(knife_owner == "") {
      obj = new(AOPATH+"silver_knife");
      if(obj->move(TP) == MOVE_OK) {
         write("You find a strange silver knife!");
         obj->move(TP);
      }
      else
         write("You find a knife but you cannot carry that much!");
   }
   else {
      write("You find nothing special here.");
      write("%^MAGENTA%^A voice whispers to you: %^RESET%^"+
         capitalize(knife_owner)+" took the artifact.");
   }
   save_me(ITEM_SAVE);
}

void search_forks() {
   object obj;
   if(fork_owner == "") {
      obj = new(AOPATH+"silver_fork");
      if(obj->move(TP) == MOVE_OK) {
         write("You find a strange silver fork!");
         obj->move(TP);
      }
      else
         write("You find a fork but you cannot carry that much!");
   }
   else {
      write("You find nothing special here.");
      write("%^MAGENTA%^A voice whispers to you: %^RESET%^"+
         capitalize(fork_owner)+" took the artifact.");
   }
   save_me(ITEM_SAVE);
}

string query_fork_owner() {
   return fork_owner;
}

string query_knife_owner() {
   return knife_owner;
}

void register_item(string item,string who) {
   if(item == "fork")
      fork_owner = who;
   if(item == "knife")
      knife_owner = who;
   save_me(ITEM_SAVE);
}

void reset_item(string item) {
   if(item == "fork")
      fork_owner = "";
   if(item == "knife")
      knife_owner = "";
   save_me(ITEM_SAVE);
}
