#include <std.h>

inherit VAULT;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("The mansion's library");
    set_long( "The largest room on this floor is this library.  It has many significant architectural details, including a massive hooded fireplace carved with roaring lions, ornate oak pillars, and carved steps for the dais area.  Leaded, glass-paned oak display cases line the walls to the ceiling and are filled with a wide variety of books and Fist artifacts.  The dais has several overstuffed chairs and an enormous divan to relax upon.  %^MAGENTA%^Plush magenta carpeting %^RESET%^covers the floor and muffles your footsteps.  The dais also once led to the quaint backyard patio, complete with benches, herb garden and apple tree that can be seen through the beautiful %^BOLD%^patio doors%^RESET%^."
    );
    set_listen("default","The carpeting and over-stuffed furniture muffle the "
       "sounds very well.");
    set_smell("default","Delicious smells drift in from the dining room.");
    set_items(([
      "dais" : "The dais is raised about three ft. and has a "
         "set of steps set in one side.  It runs the length of one wall and "
         "is spacious enough for several chairs and the enormous divan.",
     "patio door" : "These doors' wooden frames are sealed closed but still "
         "serve to provide an excellent view of the exquisite landscaping on the "
         "patio.  The eight etched glass panels also refract light into small "
         "rainbows that seem to dance across the plaster walls.",
     "carpeting" : "%^MAGENTA%^The carpeting is over an inch thick and so plush "
         "it almost feels like walking on air.",
     ({"cases", "display cases" }) : "The books are an impressive collection "
         "and probably the best have been kept, but artifacts gathered over "
         "years by Fist members fill many of the display cases now.",
     "books" : "The books are all leather bound, well "
         "preserved, and appear to cover a wide variety of topics including "
         "arcane arts, war, history, and even comedy and satire.",
     "chairs" : "They are sturdy but thickly padded and in shades of %^CYAN%^cyan "
         "%^RESET%^, %^BLUE%^blue%^RESET%^, and %^MAGENTA%^magenta%^RESET%^.",

    ] ));
    set_exits(([
       "music" : "/d/guilds/fist/mansion/music",
       "east" : "/d/guilds/fist/mansion/ghall",
       "dining" : "/d/guilds/fist/mansion/dining",
    ] ));
}

void init() {
   ::init();
   add_action("sit", "sit");
}

int sit(string str){
   if(!str) {
     tell_object(TP,"Sit where?");
     return 1;
   }
   if(str == "divan" || str == "on divan") {
      tell_object(TP,"You take a seat on the enormous divan.");
      tell_room(ETP,""+TPQCN+" takes a seat on the enormous divan.",TP);
      return 1;
   }
   if(str == "chair" || str == "in chair") {
     tell_object(TP,"Sit in which chair?");
     return 1;
   }
   if(str == "cyan chair" || str == "in cyan chair") {
      tell_object(TP,"You sink deeply into a %^CYAN%^cyan chair%^RESET%^.");
      tell_room(ETP,""+TPQCN+" sinks deeply into a %^CYAN%^cyan "
         "chair%^RESET%^.",TP);
      return 1;
   }
   if(str == "blue chair" || str == "in blue chair") {
      tell_object(TP,"You sink deeply into a %^BLUE%^blue chair%^RESET%^.");
      tell_room(ETP,""+TPQCN+" sinks deeply into a %^BLUE%^blue "
         "chair%^RESET%^.",TP);
      return 1;
   }
   if(str == "magenta chair" || str == "in magenta chair") {
      tell_object(TP,"You sink deeply into a %^MAGENTA%^magenta chair%^RESET%^.");
      tell_room(ETP,""+TPQCN+" sinks deeply into a %^MAGENTA%^magenta "
         "chair%^RESET%^.",TP);
      return 1;
   }
   if(str == "dais" || str == "on dais") {
      tell_object(TP,"You perch on the edge of the dais.");
      tell_room(ETP,""+TPQCN+" sinks deeply into a %^MAGENTA%^magenta "
         "chair%^RESET%^.",TP);
      return 1;
   }
   return 0;
}