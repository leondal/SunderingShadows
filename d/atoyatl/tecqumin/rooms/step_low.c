#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(GRASSLANDS);
  set_travel(FOOT_PATH);
  set_name("Near the bottom of a staircase on the side of a ziggurat");
  set_short("Near the bottom of a staircase on the side of a ziggurat");
  set_long( (:TO, "long_desc":) );
  set("night long",(:TO, "night_desc":));

  set_items(([
 "ziggurat":"The ziggurat rises out of the jungle like a mountain, its stepped sides climbing tier by tier until it breaks through the upper canopy to reach the sky. There appears to be some kind of additional structure right at the top.",

  ({"step", "steps", "staircase"}): "The steps are carved from the same stones as the rest of the ziggurat, in smaller blocks to make it possible to walk up them. Despite the shared origin, the stones of the staircase are a noticeably different hue to the rest of the ziggurat. Something, over the years seems to have stained them an odd orangey brown. They are adorned with carved motifs",

 ({"stonework", "motif", "motifs", "carved motif", "carved motifs"}):"The stones on either side of the staircase are decorated with intricately linked carvings and sculptures, mostly of stylised juaguars and feathered serpents",

 ({"jaguar", "jaguars"}):(:TO, "jag_desc" :),
 ({"serpent", "feathered serpent", "serpents", "feathered serpents"}):(:TO, "serp_desc":)

 ]));
  set_smell("default","The scent of the jungle reaches you");
  set_listen("default","The souds of the jungle are all there is to be"
             +" heard.");
}
void init() {
   ::init();
}

string query_path(){
  return ROOMS;
}

string query_name(){
  return base_name(TO)[strlen(ROOMS)..strlen(base_name(TO))-1];
}

string long_desc(){
return "%^ORANGE%^You are at the lower end of a broad stairway leading up"
      +" the side of the ziggurat to the zenith. The stones at the side"
      +" of the stairway are decorated with jaguar motifs and strange,"
      +" feathered serpents. The %^GREEN%^jungle%^RESET%^%^ORANGE%^"
      +" presses in close on every side, its canopies closing out most of"
      +" the sun's rays. Such %^YELLOW%^l%^RESET%^%^ORANGE%^i%^YELLOW%^"
      +"ght %^RESET%^%^ORANGE%^as does break through casts a dappled,"
      +" %^GREEN%^m%^ORANGE%^o%^GREEN%^s%^ORANGE%^a%^BOLD%^%^GREEN%^i"
      +"%^RESET%^%^ORANGE%^c%^RESET%^%^ORANGE%^ pattern on the stones.";
}

string night_desc(){
  return "%^BLUE%^You are at the lower end of a broad stairway leading up"
        +" the side of the ziggurat to the zenith. The %^RESET%^"
        +"%^ORANGE%^stones%^BLUE%^ are covered with %^GREEN%^vines"
        +"%^BLUE%^ and trailing %^GREEN%^creepers%^BLUE%^ which grab at"
        +" your feet in the darkness. The tangled %^BOLD%^%^BLACK%^black"
        +" silhouettes %^RESET%^%^BLUE%^of the %^GREEN%^jungle%^BLUE%^"
        +" press in all around, barely distinguishable against the night"
        +" sky.";
}

string jag_desc(){
  string * str;
  int i, count;
  str =  ({"%^BLUE%^You see a carving of a jaguar climbing downwards.",
    "                @@               ",
    "         .     @  @@@@@,         ",
    "                      @@         ",
    "                     @@          ",
    "                   @@            ",
    "                  @@             ",
    "                 @&              ",
    "                @@               ",
    "                @.@@@@           ",
    "            .@@@@@@@@@@    ..    ",
    "           @@@@#@@@@@@@ @@       ",
    "          /@@@@@@@@@@@@@@@       ",
    "          @@@@@@@@@@@@.@@@       ",
    "         @@.@@@@@@@@@@ @@@@      ",
    "          @@@@@/@@/@@%@@@@@(     ",
    "         @@@(@@@@@@&@ @@ @ @     ",
    "      .@ @&@@@@@@@@@@  .         ",
    "       @(@@@@@@@@%@@@@           ",
    "      #@.@@&@@@@@@@@@@           ",
    "      @@@@@@@  &%@@@@#  ##@@@@@  ",
    "     @@ @@@@@@@@@%%@@.@@@@@*(@@@(",
    "     @@@ @@@@@@@@@@@@@@@@@@@@@ & ",
    "      &@@ @@@@@@@@@@@@.@%@@@@@@  ",
    "        @@@@@@@@@@@@@@@@@@@@@@   ",
    "        @@@@    @@@@@@ &     @@& ",
    "        *# @ @     /@@@@         ",
    "                   @@@@%@@       ",
    "                    @@ @@@&      ",
    "                      @@ @@      ",
    "                        @@@@     ",
    "                          @@@@   ",
    "                          @@@@@#*",
    "                           ../   "});
  count = sizeof(str);
  for (i=0;i<count;i++){
    tell_object(TP, str[i]);
  }
  return "";
}


string serp_desc(){
  string * str;
  int i, count;
  str = ({  "%^BLUE%^You see a carving of a %^BOLD%^%^WHITE%^feathered serpent%^RESET%^%^BLUE%^.%^BOLD%^%^WHITE%^",
"               @ @ % (               ",  
"             %/ @  @   %.&           ",  
"            & . @(. .@,,  @#,@       ",  
"           @.@@@@@@,(@%. @%          ",  
"          @@@@.*#/@@ @, &%/./@,*##   ",  
"         @@#@@%@     .@@#@@          ", 
"            @.      %#     @@@@@,    ",  
"                          *@*,, #@(* ",  
"               @.@ %/# @@&@@@@       ",  
"            @&(%.@@&&& ,@@ *@ @@     ",  
"        @  @@.@&&             @.@    ",  
"    ,   (  @@@@   ,,@@##@@      (    ",  
"     @ * ##/@@*# @@*   .#@ @@(       ",  
"   /  /     @,,.* @      *(#  @      ",  
"     @@..    #@ %@@&@   @@@(@        ",  
"      ,@(//@#@ @.# /@@@%@ % .&       ",  
"         .,   # /#  @@ (,@           ",  
"         %       #@  ,&  /           ",  
"               *%(@@,@/&(            ",  
"                  &@  @              ",  
"                ,#&, .#  *           "});   
  count = sizeof(str);
  for (i=0;i<count;i++){
    tell_object(TP, str[i]);
  }
  return "";
}
