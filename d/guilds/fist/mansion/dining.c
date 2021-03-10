#include <std.h>

inherit "/d/dagger/Torm/inherits/bar";

void create() {
    ::create();
    set_property("light",0);  //note - it's set to 2 by the inherit already
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("The mansion's dining room");
    set_long(
"The dining room features %^ORANGE%^gleaming sycamore paneling%^RESET%^, a finely tiled fireplace with intricate mantel carvings, and an original hand painted mural.  Several %^RED%^rich mahogany tables%^RESET%^, each with 8-12 appropriately sized and matching high back chairs, are placed around the perimeter.  You also notice some %^CYAN%^thick cushions %^RESET%^stacked in a corner along with a few %^ORANGE%^benches and stools%^RESET%^.  Several serving tables are in the center to display the tantalizing food and drinks that the waiters and waitresses serve from.  This room offers an impressive setting for the masterfully created and presented meals of the mansion's master chef.  Positioned between the pier is an ornately carved and %^YELLOW%^gilded %^RESET%^pier mirror.  The mirror is strategically placed to reflect and maximize the light from a large %^YELLOW%^candelabra %^RESET%^positioned on its table.  It is common to open the pocket doors, allowing music to filter in from the music room."
    );
    set_listen("default","You hear the buzz of conversation all about.");
    set_smell("default","The food smells absolutely delicious.");
    set_items(([
      "mural" : "The mural is a grand scene of a party of adventurers fighting "
        "a magnificent %^BOLD%^%^RED%^red dragon %^RESET%^against a backdrop "
        "of a rugged mountainside.",
      "candelabra" : "The %^YELLOW%^brightly polished brass candelabra%^RESET%^ "
        "has at least twenty arms each with a %^CYAN%^candle that burns brightly "
        "and cleanly but without melting somehow.",
      "pier" : "The wall space between two large bay windows along the "
        "outside wall.",
      ({ "candle", "candles" }) : "On closer inspection you can see that the "
        "candles are really small oil lamps with a tall, thin, reservoir "
        "that has been dipped in wax to look like a candle and using a very "
        "thin, candle-like wick.",
      ({"table", "tables" }): "One is a %^RED%^low table %^RESET%^that seems "
        "designed for the smaller races.  There is a %^RED%^large table "
        "%^RESET%^with extra sturdy chairs, "
        "clearly designed for the weight and stature of large races.  Finally "
        "there are several %^RED%^main tables %^RESET%^designed for normal size "
        "humanoids.",
      "chairs" : "The chairs are ornately carved and match the tables.  A few "
        "have a cushion or two in them where someone smaller has needed a boost.",
      ({"bench", "benches", "stools" }): "The benches and stools seem to be "
         "designed to allow those of larger or smaller stature to sit at "
         "a table not designed for their size.",
       ({"cushion", "cushions" }) : "%^CYAN%^Thick cushions that fit the chair "
         "seats to provide a boost to someone too short for a table.",
    ] ));
    set_exits(([
//       "foyer" : "/d/guilds/fist/mansion/entry",
       "music" : "/d/guilds/fist/mansion/music",
       "north" : "/d/guilds/fist/mansion/ghall",
    ] ));
   set_door("pocket door","/d/guilds/fist/mansion/music","music");
   set_door_description("pocket door","This is actually a pair of doors that "
     "suspend from rollers in tracks in the ceiling rather than hanging on "
     "hinges to swing as most do.  The walls to each side "
     "are hollow and the doors simply slide inside them to open.");
  set_string("pocket door","open","The pocket doors slide smoothly aside into "
     "the spaces inside the walls.");
  set_string("pocket door","close","The pocket doors slide smoothly out from "
     "the space inside the walls to close the room off from the next.");
}

void init() {
   ::init();
   add_action("sit","sit");
}

void reset() {
   ::reset();
   if(random(3)) {
   tell_room(TO,"A busboy wearing a uniform wanders through quietly and "
      "unobtrusively straightening the chairs and cleaning up the empty tables.");
//   if(present("bottle"))  remove("bottle");
   }
   if(!present("waitstaff")) {
     switch(random(2)) {
       case 0:  new("/d/guilds/fist/mon/wait1")->move(TO);    break;
       case 1:  new("/d/guilds/fist/mon/wait2")->move(TO);   break;
     }
   }
}

int sit(string str){
   string size;
   size = TP->query_size();
   if(!str) {
     tell_object(TP,"You should choose a table and sit at it.");
     tell_room(ETP,TPQCN+" seems to be trying to decide where to sit.",TP);
     return 1;
   }
   if(str == "table" || str == "at table") {
     tell_object(TP,"Sit at which table?");
     tell_room(ETP,TPQCN+" wanders around as if trying to decide which table to sit at.",TP);
     return 1;
   }
   if(TP->query_intox() > 500) {
      tell_object(TP,"You stumble around trying to find a chair to sit in.");
      tell_room(ETP,""+TPQCN+" stumbles around, apparently trying to find a "
      "chair to sit in.",TP);
      if(!random(3))  return 1;
   }
   if(str == "low table" || str == "at low table") {
     switch(size) {
       case 1:
          tell_object(TP,"You take a seat at one of the low tables.");
          tell_room(ETP,""+TPQCN+" takes a seat at one of the low tables.",TP);
          break;
       case 2:
          tell_object(TP,"You pull up a short stool but your knees bump as "
            "you sit at the low table.");
          tell_room(ETP,""+TPQCN+" pulls a short stool up to the low table and "
            "sits down a little awkwardly.",TP);
          break;
       case 3:
          tell_object(TP,"You sit on a cushion on the floor at the low table, "
            "looking quite out of place.");
          tell_room(ETP,""+TPQCN+" sits on a cushion on the floor at the low "
            "table, looking quite out of place.",TP);
          break;
     }
   return 1;
   }
   if(str == "main table" || str == "at main table" || str == "main tables") {
     switch(size) {
       case 1:
          tell_object(TP,"You grab a thick cushion for a chair at one of the "
             "main tables, climbing up to sit on it with your feet dangling.");
          tell_room(ETP,""+TPQCN+" grabs a thick cushion for a chair at one "
             "of the main tables, climbing up to sit high enough to reach.",TP);
          break;
       case 2:
          tell_object(TP,"You slide comfortably into a chair at a main table.");
          tell_room(ETP,""+TPQCN+" slides comfortably into a chair at one "
             "of the main tables.",TP);
          break;
       case 3:
          tell_object(TP,"You pull up a short stool but your knees bump as "
            "you sit at one of the main tables.");
          tell_room(ETP,""+TPQCN+" pulls a short stool up to a main table and "
            "sits down a little awkwardly.",TP);
          break;
     }
   return 1;
   }
   if(str == "large table" || str == "at large table") {
     switch(size) {
       case 1:
          tell_object(TP,"You pull one of the tall stools up to the large table, "
             "climbing up to sit with your feet on the rungs.");
          tell_room(ETP,""+TPQCN+" pulls one of the tall stools up to the large "
             "table, climbing up to sit and reach the table.",TP);
          break;
       case 2:
          tell_object(TP,"You grab a thick cushion for a chair at one of the "
             "main tables, climbing up to sit on it with your feet dangling.");
          tell_room(ETP,""+TPQCN+" grabs a thick cushion for a chair at one "
             "of the main tables, climbing up to sit high enough to reach.",TP);
          break;
       case 3:
          tell_object(TP,"You slide comfortably into a massive chair at the "
             "large table.");
          tell_room(ETP,""+TPQCN+" slides comfortably into a massive chair at the "
             "large table.",TP);
          break;
     }
   return 1;  
   }
// in case they try sit chair, etc.
   tell_object(TP,"You should choose a table and sit at it.");
   tell_room(ETP,TPQCN+" seems to be trying to decide where to sit.",TP);
   return 1;
}
