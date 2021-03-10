#include <std.h>
inherit ROOM;

void create()
{
  ::create();
    set_terrain(CITY);
    set_travel(BACK_ALLEY);
  set_property("light", 1);
  set_short("an Alley");
   set_long("You have wandered into an alley that appears to dead end here. It is rather filthy and garbage has been tossed down here with little care of the stench it is causing. This is not a place you'd choose to spend a lot of your time in.");
  set_smell("default", "Like most alleys it smells horrid here.");
   set_listen("default", "You don't hear much except rats moving about the refuse.");
  set_items( ([
      "garbage" : "It's like any other, dirty filthy and smelly.  But what is one man's garbage can be another man's treasure."
  ]) );
  set_search("garbage",(:TO,"go_down":));
  set_exits( ([
   "east":"/d/tharis/Tharis/alley1",
     "down" : "/d/tharis/Tharis/sewer8"
  ]) );
   set_invis_exits(({"down"}));
}

void go_down(){
        write("%^BOLD%^You find a dark forbiding hole leading down.");
  tell_room(TO,TPQCN+" finds something as "+TP->query_subjective()+" searches the garbage.",TP);
  remove_invis_exit("down");
}

//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }