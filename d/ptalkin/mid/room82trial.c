#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create(){
::create();
set_property("light", 2);
set_property("indoors", 0);
set_short("A pathway");
set_long("%^BLUE%^You are now walking along white cliffs beside the ocean.  Water laps its way up the side of the cliff, eating away at the dirt and sand.  A small town appears ahead of you, and a dock with rafts.");
set_smell("default", "%^BOLD%^BLUE%^\nThe sea air reaches you, filled with the smell of brine.");
set_listen("default", "%^CYAN%^The waves crashing upon the cliffs drowns out any other sound.");
set_exits (([
"southwest" : PMID+"room81.c"
]));
set_trap_functions(({"southwest"}),({"start_trip"}),({"southwest"}));
set_items(([
"ocean" : "The smell of brine reaches you as you peer down into crystal clear green/blue waters",
"dirt" : "Dirt walls seem to hold up the cliffs, a pale yellow brown colour, with roots from trees sticking out like wild hair",
"sand" : "Sand mixes with the dirt, making you wonder just how safe this cliff really is.",
"cliffs" : "Sixty feet to the ocean is a long way to drop......",
"town" : "A small town appears ahead of you, ramshackle for the most part",
"dock" : "Unlike the town, this dock appears to be well made and exceedingly well maintained.",
"rafts" : "While they appear to be rather small, holding only 3 - 4 individuals, they too, are well made and maintained.",
"trees" : "Mostly saplings appear, but you can see large age`d trees ahead of you.",
"path" : "The pathway now begins to become softer, easier on your feet as evergreen needles accumulate.",
"grassland" : "The grassland holds many scrub trees, tall grasses, large wild flowers, making it difficult to see where you are placing your feet.",
"forest" : "Lush green canopies of leaves cover the horizon.",
"foliage" : "Small plants, creeping ivies and wild flowers make up the foliage under the trees"
]));
}

void reset(){
  ::reset();
if(!trapped("southwest"));
   toggle_trap("southwest");
}

int do_trip() {
  int hurt;
  TP->move_player("/d/ptalkin/mid/roomledge");
  tell_object(TP, "\n%^BOLD%^%^RED%^You scrape yourself on the cliff%^RESET%^\n");
  hurt = (int)TP->query_hp();
  hurt = (hurt > 10) ? 10 : (hurt -1);
  TP->cause_typed_damage(TP, "torso", hurt, "slashing");
  return 1; 
} 

int start_trip() {
    if(!this_player()) { return 1; }
     if(random(99) >= 50) {
       write( 
@TEXT
%^BOLD%^%^WHITE%^As you walk away, your foot slips on the loose pebble
Your feel yourself slipping down the cliff
%^BOLD%^%^GREEN%^HELLLLL
%^BOLD%^%^BLUE%^      LLLLLLLLLL
%^BOLD%^%^YELLOW%^               LLLLLPPPPP
%^BOLD%^%^RED%^                        PPPPPPPPPP
%^WHITE%^%^BOLD%^You can only grab onto loose dirt and some scrub brushes.
You wonder whether they will hold your weight.
Your hand snags a piece of brush and stops your fall.
You see sharks in the waters below.
You can see a small ledge to your left, but can you make it.
You wonder what would happen if you swung over to your left.
TEXT
);
             tell_room(TO, "As "+TPQCN+" walks southwest, "+
                           TP->query_possessive()+ 
                           " foot slips on the loose pebbles.  "+TPQCN+
			   " starts to fall", TP);
	      toggle_trap("southwest");
	      call_out("do_trip", 1, this_player());
              return 1;
    }
    return 0;
}
