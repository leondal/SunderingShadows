#include <std.h>
#include "/d/islands/argentrock/argabbr.h"

inherit ROOM;

int lifted;
void create() {
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set("short","%^BOLD%^%^RED%^The bedroom");
    set("long","%^BOLD%^%^RED%^The bedroom
%^RESET%^%^CYAN%^This is a bedroom. A simple %^ORANGE%^bed%^CYAN%^ with teak frames is sitting in here against the wall. A small desk and a %^ORANGE%^ch%^BOLD%^%^ORANGE%^a%^RESET%^%^ORANGE%^ir%^CYAN%^ are located beneath the %^BOLD%^%^BLUE%^w%^CYAN%^in%^BLUE%^d%^BLUE%^o%^CYAN%^w.%^RESET%^%^CYAN%^ A %^CYAN%^m%^BLUE%^ir%^CYAN%^r%^BLUE%^or%^CYAN%^ stands on the opposite of the bed. Two %^ORANGE%^ca%^BOLD%^%^ORANGE%^n%^RESET%^%^ORANGE%^delstic%^BOLD%^%^ORANGE%^k%^RESET%^%^ORANGE%^s%^CYAN%^ with a black %^BOLD%^%^BLACK%^ca%^BLACK%^n%^BLACK%^dle%^RESET%^%^CYAN%^ on each one light up the room. Everything in this room is so tidy and clean. It is so ordered like no one has ever slept in here.%^RESET%^
");
   set_property("indoors",1);
    set_property("no teleport",1);
   set_property("light",2);
    set_listen("default","Sounds of the forest come through the window.");
    set_smell("default","Smells of the forest fill up the room.");
    set_items( (["bed":"A bed made of teak. It looks comfortable.",
      "desk":"This is a small desk beneath the window. Some papers and "+
       "stationary are on the desk.",
      "chair":"An ordinary wooden chair.",
      "window":"You can see the forest view outside the window.",
      "mirror":"You see your own reflection inside the mirror.",
      "candlesticks":"Each candlestick has a black candle mounted in it.",
      "candle":"This is a strange black candle burning with a black "+
      "mystical flame."]) );
   set_exits( (["door":PATH+"arghouse6"]) );
   lifted = 0;
}

void init() {
   ::init();
   add_action("lift_func","lift");
}

void reset() {
   ::reset();
}

int lift_func(string str) {
   if(!str) return 0;
   if(lifted && str == "bed")
      return notify_fail("It has been lifted already!\n");
   if(str == "bed") {
       tell_object(TP,"As you lift the bed, you find a hidden long box.");
       tell_room(TO,TPQCN+" lifts the bed and finds a box.",TP);
      new(OBJ+"long_box")->move(TO);
      lifted = 1;
      return 1;
   }
   return 0;
}
