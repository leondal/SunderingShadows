
#include <std.h>

#include "/d/stella/short.h"

inherit ROOM;

void init(){
	::init();
/*  removing chance for a star here so it can't be used to kill the mundanoid *Styx* 8/2003
       	if (interactive(TP)) {
	  do_random_encounters(({OPATH"nova.c"}),5,1);
       	}
*/
	add_action("read_plaque","read");
}

void reset(){
        ::reset();
        if (!present("mundanoid")) new(MPATH "mund_nw.c")->move(TO);
        }

void create(){
      ::create();
      set_name("Star Maze");
      set_short("%^RED%^Star Maze");
      set_terrain(BARREN);
      set_travel(FRESH_BLAZE);
      set_property("indoors",1);
      set_property("light",1);
      set_long(
	     "%^RED%^You are in a starry maze.  You are surrounded by deep darkness.  "
	     "The only light comes from millions of tiny stars which surround "
	     "you on all sides.  As your eyes adapt to the dark, you notice "
	     "faint shimmering RED lines leading off into the darkness.  "
       );
      set_search("default","You notice a small plaque set into the wall!");
      set_listen("default",
        "You hear nothing ... a complete absence of any sound. "
      );
      set_smell("default",
        "You smell nothing!"
      );
      set_items(([
        "stars":"There are millions of shimmering stars in every direction.  ",
	"plaque":"This is a small black plaque with shimmering, starry letters.  ",
        "lines":"You occasionally see a faint line heading off in some direction.  "
        "This is your only source of orientation."
       ]));
      set_exits(([
         "north": MAZEPATH "boo8",
         "south": MAZEPATH "boo6",
         "southwest": MAZEPATH "boo4"
       ]));
}


int read_plaque(string str){
  
        if (!str) {
          notify_fail("Read what?\n");
          return 0; }
        if (str=="plaque") {
          if (present("mundanoid",ETP)){
            say("The Mundanoid prevents "+TPQCN+" from reading a plaque!\n",TP);
            tell_object(TP,"The mundanoid steps between you and the plaque!\n");
          } else {
            say(TPQCN +" reads over a small plaque on the wall!\n",TP);
            tell_object(TP,"The plaque is inscribed with the word: BOOTES!\n");
          }
        }
        return 1;
      }
