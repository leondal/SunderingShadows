#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(SCRUB_LANDS);
   set_travel(DIRT_ROAD);
   set_name("Small clearing");
   set_short("Small clearing");
   set_long("%^BOLD%^Small clearing%^RESET%^\n"
"The hidden path leads into a small clearing amidst the %^GREEN%^brush%^RESET%^, which seems to be the long-"
"abandoned remains of a street.  A few %^BLACK%^%^BOLD%^cobblestones%^RESET%^ are still set within the "
"ground at your feet, though most are lost beneath the undergrowth.  A heavy grate is secured between some "
"of the cobblestones, though it is old and %^ORANGE%^rusted%^RESET%^ all over.\n");
   set("night long","%^BOLD%^Small clearing%^RESET%^\n"
"The hidden path leads into a small clearing amidst the %^GREEN%^brush%^RESET%^, swathed in the shadows of "
"the %^BLUE%^night%^RESET%^, which seems to be the long-abandoned remains of a street.  A few %^BLACK%^"
"%^BOLD%^cobblestones%^RESET%^ are still set within the ground at your feet, though most are lost beneath "
"the undergrowth.  A heavy grate is secured between some of the cobblestones, though it is old and %^ORANGE%^"
"rusted%^RESET%^ all over.\n");
   set_smell("default","The light, salty smell of the ocean fills the air.");
   set_listen("default","You can hear the distant, crashing waves of the ocean to the south.");

   set_items(([
     ({"trail","path"}):"The bare traces of the path lead back to the south, through the undergrowth.",
     ({"plants","shrubbery","trees","bushes"}):"A thick gathering of %^GREEN%^bushes and trees%^RESET%^ "
"surround the clearing, partially hiding the trail that leads back to the south.",
     "grate":"The grate is old and %^ORANGE%^rusted%^RESET%^, and looks quite heavy.  You'll have to lift it "
"somehow if you want to find a way below it."
    ]));

   set_exits(([
     "south":COVE"thief1",
   ]));
}

void init(){
   ::init();
   add_action("liftem","lift");
}

void reset(){
   ::reset();
   if(member_array("down",TO->query_exits()) != -1) {
     remove_exit("down");
     tell_room(TO,"Someone slams the grate shut from below!");
   }
}

int liftem(string str){
   if(!str) return notify_fail("Lift what?\n");
   if(str != "grate") return notify_fail("What are you trying to lift?\n");
   if(member_array("down",TO->query_exits()) != -1) return notify_fail("The grate has been moved already.\n");
   if((roll_dice(1,20))>(TP->query_stats("strength")))
     return notify_fail("You heave at the grate, but fail to lift it.\n");
   tell_object(TP,"You lift the heavy grate off the hole.");
   tell_room(ETP,""+TPQCN+" lifts the heavy, rusted grate",TP);
   add_exit(COVE"thief3","down");
   return 1;
}
