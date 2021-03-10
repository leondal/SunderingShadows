#include "/d/islands/giant/giant.h"

inherit VAULT;
string TOD;

void create(){
   ::create();
    TOD = "/daemon/events_d.c"->query_time_of_day();
   set_property("indoors",1);
   set_property("light",2);
   set_short((:TO,"short_fun":));
   set_long((:TO,"long_fun":));
   set_smell("default","It sells of old wine and charred beef.");
   set_listen("default","You hear the grunts of giants in the backround.");
   set_items(([
      "furs":"%^BOLD%^They appear to come form a variety of animals; such as bear,;deer and elk.%^RESET%^",
      "bed":"%^BOLD%^THis bed is large, even for a giant and has pictures of animals carved into the frame.",
      "table":"The table is made of oak and has large kegs of wine and a clean(kinda) plate on it.",
      "clothes":"The pegs hold up large furs and skins the chief wears as clothing.",
      "chain":"%^WHITE%^This is apparently for a very large animal, perhaps a bear.%^RESET%^",
      "shield":"%^ORANGE%^This is a wood shield reenforced with iron studs, the front displays a engraving of a great battle.",
      "engraving":"%^RED%^From what you can see it looks like a small army of giants marching on a human village.%^RESET%^",
   ]));

   set_exits(([
      "south":HROOM+"h3.c",
   ]));

   set_door("door",HROOM+"h11.c","south","chief key");
   set_open("door",0);
   set_locked("door",0);
}

void reset(){
   ::reset();
   set_open("door",0);
   set_locked("door",0);
    TOD = "/daemon/events_d.c"->query_time_of_day();
    if( TOD == "night" && !present("chief") ){
      new(HMON+"chief.c")->move(TO);
   }
}

string short_fun(string str){
   if(TOD != "night"){
      str = "%^ORANGE%^Chief Glacor's Chambers%^RESET%^";
   } else {
      str = "%^YELLOW%^Chief Glacor's Chambers%^RESET%^";
   }
}

string long_fun(string str){
    if( TOD != "night" ){
      str =
         "%^ORANGE%^This is definately the grandest room you have seen in the keep.  "+
         "By hill giant standards it's magnificent.  It has furs all over the walls "+
         "and floors to keep the draft out.  There is also a bed, two well crafted "+
         "chairs and a table with giant sized kegs of wine on it.  In the corner "+
         "is a huge shield and a large chest.  The fireplace is currently not lit.";
   } else {
      str =
         "%^YELLOW%^This is definately the grandest room you have seen in the keep."+
         "By hill giant standards it's magnificent.  It has furs all over the walls"+
         "and floors to keep the draft out.  There is also a bed, two well crafted"+
         "chairs and a table with giant sized kegs of wine on it.  In the corner"+
         "is a huge shield and a large chest.  The fireplace is lit now with"+
         "a large cauldron hanging above it.  The %^RED%^flames %^YELLOW%^flicker and dance"+
         "and cast many %^BLACK%^shadows %^YELLOW%^on the walls of the chamber.%^RESET%^";
   }
   return str;
}
