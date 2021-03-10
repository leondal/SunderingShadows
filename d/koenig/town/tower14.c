#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A Huge Room");
  set_long("%^BOLD%^%^WHITE%^You are now realizing just how large this room is as "
           "you travel through it! It is breathtaking, the shear size of it. "
           "You now stand on the north side of this large room near the "
            "second %^BOLD%^%^BLACK%^fireplace%^BOLD%^%^WHITE%^ in front of the huge %^RESET%^%^ORANGE%^table%^BOLD%^%^WHITE%^ that sits here. "
           "You also notice that there are %^MAGENTA%^tapestries%^BOLD%^%^WHITE%^ hanging on the wall "
           "here as well.%^RESET%^\n");
  set_smell("default", "The pleasant smell of burning wood.");
  set_listen("default", "The only sound it the crackling of the fire and your passing.");
  set_items( ([
     "tapestries" : "There are three tapestries here. You might try looking at them individually.",
     "tapestry 1" : "This is a picture of two very strange looking beings strolling through a very beautiful garden.",
     "tapestry 2" : "This picture seems to move as you look at it. It almost gives you a headache because it moves so fast. It causes you to look away.",
     "tapestry 3" : "You can make out that there is but a single figure, but not what it looks like. Maybe if you take a closer look at the figure?",
     "table" : "It is made of the same stonewood as the gates to this hellish town.",
     "fireplace" : "It is absolutely HUGE."
]) );
  set_exits( ([
     "south" : "/d/koenig/town/tower13",
     "east" : "/d/koenig/town/tower15"
]) );
}
void init() {
  ::init();
  add_action("look_figure", "look");
}
int look_figure(string str){
     if(!str || str != "figure") return 0;
  say(TPQCN+" examines one of the tapestries more closly...");
  say("A pair of shadowy hands suddenly reach out and grab "+TPQCN+"!");
   say(TPQCN+" disappears into the tapestry!");
  write("You examine the figure more closely...");
  write("To your horror a pair of shadowy hands reach out and grab you!");
  write("%^BOLD%^%^RED%^You feel yourself pulled into the tapestry with NO ESCAPE in sight!");
  set_items( ([
     "tapestry 3" : "You can make out a shadowy figure, and it appears to be struggling with "+TPQCN+"!"
]) );
   TP->move_player("/d/koenig/town/tapestry3");
  return 1;
}
