#include "/d/dagger/aketon/short.h"
#include <move.h>

#define ITEM_SAVE "/d/save/aketon/1five5"

inherit ROOM;

string awlpike_owner;

void create() {
   ::create();

   awlpike_owner = "";
   restore_me(ITEM_SAVE);
   if(!awlpike_owner)
      awlpike_owner = "";
   save_me(ITEM_SAVE);

   if(query_light())
      remove_property("light");
   set_property("light",2);
   set_property("indoors",1);
   set_short("Study on top of the tree");
   set_long("%^GREEN%^Study on top of the tree%^RESET%^
The study looks rather like a library more than a study. Oak wood shelves "
      "filled with books line the walls. A large redwood desk sits in the "
      "the room in front of a large window. A wood and leather armchair "
       "is placed behind the table right below the opened window. Beside "
      "the table is a wooden rocking chair and a small crystal cabin. "
      "Put on the desk is a lamp which lights up the room. The floor is "
      "like the rest of the house, covered with beautiful carpet.");
   set_items( (["house":"The house is quite large and is built on the "
      "tree branches.",
      "windows":"You can see the other parts of the house through the "
      "windows.",
      "carpet":"These beautiful carpets are made by craftsmen in Tonovi.",
      "study":"It looks like a small library.",
      "shelves":"The shelves are filled with books.",
      "desk":"It is sitting there quietly. Stationaries are placed tidily "
      "on top.",
      "stationaries":"Stationaries you use to write and stuff.",
      "armchair":"A large armchair for the house owner to sit on.",
      ({"rocker","rocking","chair","rocking chair"}):"You noticed there "
      "is still a little movement.",
      "books":"So many books are here.",
      "cabin":"It must be used by its owner to store things",
      "lamp":"The only source of light in the room."]) );
   set_smell("default","Smells of perfume fill your nostrils.");
   set_listen("default","It is quiet here.");
   set_exits( (["northeast":RPATH1+"1five4"]) );
   set_search("cabin","Many deeds and books are placed in it.");
   set_search("books","Look through the gaps of the books, you notice a "
      "stick-like substance behind it. You wonder if you can get it out "
      "from behind the books.");
}

void init() {
   ::init();
   add_action("shove_func","shove");
}

int shove_func(string str) {
   object obj;
   if(!str || str != "books") {
      notify_fail("You cannot shove that!\n");
      return 0;
   }
   if(str == "books") {
      if( present("naxterr") ) {
         notify_fail("No no not now...\n");
         return 0;
      }
      if(awlpike_owner == "") {
         obj = new(AOPATH+"brass_awlpike");
         if(obj->move(TP) == MOVE_OK) {
            write("You find a brass awlpike from behind the books!");
            obj->move(TP);
            return 1;
         }
         else
            write("You find an awlpike but you cannot carry that much!");
            return 1;
      }
      else {
         write("You realize that was just your imagination.");
         write("%^MAGENTA%^A voice whispers to you: %^RESET%^"+
            capitalize(awlpike_owner)+" took the artifact.");
         return 1;
      }
   }
   save_me(ITEM_SAVE);
   return 1;
}

string query_awlpike_owner() {
   return awlpike_owner;
}

void register_item(string item,string who) {
   if(item == "awlpike")
      awlpike_owner = who;
   save_me(ITEM_SAVE);
}

void reset_item(string item) {
   if(item == "awlpike")
      awlpike_owner = "";
   save_me(ITEM_SAVE);
}
