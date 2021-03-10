#include "/d/islands/giant/giant.h"

inherit VAULT;
string TOD;

void create(){
   ::create();
    TOD = "/daemon/events_d.c"->query_time_of_day();
   set_property("indoors",1);
   set_property("light",2);
   set_short("%^ORANGE%^Barracks%^RESET%^");
   set_long((:TO,"long_fun":));
   set_smell("default","It reeks of dirty giants here.");
   set_listen("default","You here the grunts and stomping of giants in the backround.");
   set_long((:TO,"long_fun":));
   set_items(([
      "torches":"The torches provide light for the room when it is dark. You notice nothing unusual about them.",
      "bed":"%^ORANGE%^These beds are of simple design and are really nothing more than a thick wooden frame covered with hay and a few ragged furs.",
      "furs":"%^BOLD%^They appear to come form a variety of animals such as bear, deer and elk.  These particular furs are not of quality%^RESET%^",
      "bed":"%^BOLD%^THis bed is large, even for a giant and has pictures of animals carved into the frame.",
      "pegs":"each bed appears to have a wooden peg above it, probably to hold the giant's sack when he goes to sleep.",
   ]));

   set_exits(([
      "south":HROOM+"h3.c",
   ]));

   set_door("door",HROOM+"h7.c","north",0);
   set_open("door",0);
   set_locked("door",0);
}

void reset(){
   ::reset();
   set_open("door",0);
   set_locked("door",0);
    TOD = "/daemon/events_d.c"->query_time_of_day();
   if(TOD == "night" && !present("giant")){
      new(HMON+"grunt2.c")->move(TO);
      new(HMON+"grunt2.c")->move(TO);
      new(HMON+"grunt2.c")->move(TO);
   }
}

string long_fun(string str){
    if( TOD != "night" ){
      str =
         "%^ORANGE%^This appears to be the keep's barracks.  You doubt that all "+
         "of the keep's giants reside here, but a good number do.  It is "+
         "of simple design, the room consists only a few beds with a small "+
         "wooden peg above each.  There are also several torch holders which "+
         "are currently not lit.%^RESET%^";
   } else {
      str =
         "%^YELLOW%^This appear sto be the keep's barracks.  You doubt that all "+
         "of the keep's giants reside here, but a good number do.  It is "+
         "of simple design, the room consists of only a few beds with a small "+
         "wooden peg above each.  There are sveral torches embedded in the "+
         "walls of the room.  They cast flickering %^BLACK%^%^BOLD%^shadows %^YELLOW%^on the walls "+
         "and drip %^RED%^hot%^YELLOW%^ pitch on the stone floor.";
   }
   return str;
}
