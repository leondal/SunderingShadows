#include <std.h>
#include "farm.h"

inherit CROOM;

void pick_critters();

void create(){
   pick_critters();
   ::create();
   set_repop(25);
   set_terrain(GRASSLANDS);
   set_travel(RUTTED_TRACK);
   set_name("A dilapidated farmyard");
   set_property("light",3);
   set_property("indoors",0);
   set_short("%^RESET%^%^ORANGE%^A dilapidated farmyard%^RESET%^");
   set_long("This %^GREEN%^farmyard %^RESET%^has certainly seen "+
      "better days.  The odd %^CYAN%^diamond-shaped %^RESET%^"+
      "farmhouse itself stands just south of the banks of a "+
      "%^BOLD%^%^BLUE%^rapidly moving stream%^RESET%^.  A "+
      "fantastic %^ORANGE%^water wheel %^RESET%^churns the stream, "+
      "its noise muffled by the sounds of the farm.  The "+
      "ground here is covered in patchy %^GREEN%^grass%^RESET%^,"+
      "with some areas left clear where it appears heavy "+
      "objects rested for a time.  Samples of those same objects "+
      "can be seen around the area - everything from %^BOLD%^"+
      "mechanical creatures %^RESET%^to %^CYAN%^unusual "+
      "contraptions %^RESET%^of %^BOLD%^gleaming metal%^RESET%^.  "+
      "Common %^RED%^barnyard animals %^RESET%^meander around "+
      "the landscape as well, eating what %^GREEN%^grass "+
      "%^RESET%^there is.  It seems even some of the animals "+
      "have not been spared from the %^BOLD%^mechanical genius "+
      "%^RESET%^of the farmer - several sport various helmets "+
      "and unnatural appendages.  The farther you get from the "+
      "%^CYAN%^farmhouse%^RESET%^, the more dilapidated the "+
      "land becomes.\n");
   set_smell("default","Phew...smells like no one's cleaned up "+
      "after the animals in a long time.");
   set_listen("default","Chickens cluck, cows moo, and something "+
      "goes %^BOLD%^%^WHITE%^CLICK%^RESET%^%^GREEN%^!");
   set_items(([
      ({"land","farmland","ground","grass"}) : "The ground here "+
         "is covered in patchy grass.  It looks as though the "+
         "animals eat whatever they like, and no one bothers "+
         "with the rest of the yard.",
      ({"house","farmhouse","farm house"}) : "The farmhouse is "+
         "shaped a little unusually, rather like a diamond.  "+
         "One tip of the diamond points toward the streams "+
         "north of here, and a %^ORANGE%^water wheel %^RESET%^"+
         "stands just west of it.  There is no entrance from "+
         "this side, though unusually shaped windows twinkle "+
         "occasionally with light.",
      ({"wheel","water wheel"}) : "The water wheel towers over "+
         "the stream, turning continuously.  It is attached to "+
         "a small building that has turned %^BOLD%^silver %^RESET%^"+
         "with age.",
      ({"sream","water","river","streams"}) : "The stream moves "+
         "swiftly around this small farm, nestling it into a "+
         "small valley.  It looks as thought the stream continues "+
         "to the southwest before plunging over falls.",
      ({"contraptions","unusual contraptions","contraption","metal","creatures","mechanical creatures"}) : (:TO,"creature_desc":)
   ]));
   set_search("default","You find only patchy grass and the odd "+
      "bit of metal.");
}

string creature_desc(){
string tmp;
   switch(random(10)){
      case 0:  tmp = "%^ORANGE%^You catch a glimpse of a squirrel "+
                  "as it skitters away, the %^YELLOW%^light "+
                  "%^RESET%^%^ORANGE%^glinting off its metal body.";
               break;
      case 1:  tmp = "%^BOLD%^%^BLACK%^Smoke sputters briefly from "+
                  "a strange metal box hidden in the grass.";
               break;
      case 2:  tmp = "%^BOLD%^A goose flies by, heading toward "+
                  "the stream with a...helmet?! on its head.";
               break;
      case 3:  tmp = "A pitchfork stumbles as it walks on its "+
                  "short legs, heading for a haystack to the west.";
               break;
      case 4:  tmp = "%^CYAN%^A glinting metallic bird trills "+
                  "a song from a treetop branch.";
               break;
      case 5:  tmp = "%^BOLD%^%^MAGENTA%^An ordinary pig grunts "+
                  "and roots through the dirt as it ambles by.";
               break;
      case 6:  tmp = "%^YELLOW%^A group of clucking chickens "+
                  "picks at the ground, moving in a strangely "+
                  "jerky way.";
               break;
      case 7:  tmp = "%^BOLD%^A contraption you have no name "+
                  "for sparkles briefly in the grass.  You see "+
                  "a hook, a box, a crystal triangle, a tangle "+
                  "of wire, and...of all things...a spoon.";
               break;
      case 8:  tmp = "A simple pair of eyeglasses lies in the "+
                  "dust.  Suddenly, you hear a click, and they "+
                  "disappear in a flash, leaving behind a tiny tin "+
                  "soldier!";
               break;
      default: tmp = "%^MAGENTA%^You catch sight of a %^BOLD%^p"+
                  "%^RED%^i%^YELLOW%^n%^GREEN%^w%^CYAN%^h%^BLUE%^e"+
                  "%^MAGENTA%^e%^RED%^l %^RESET%^%^MAGENTA%^"+
                  "spinning in the tall grass.";
               break;
   }
   return("You glance around the farmyard.  "+tmp+"");
}

void pick_critters(){
     switch(random(11)){
        case 0..2:  break;
        case 3:  set_monsters(({MON"cow"}),({1+random(2)}));
                 break;
        case 4:  set_monsters(({MON"cow",MON"turkey"}),({1,1}));
                 break;
        case 5:  set_monsters(({MON"turkey"}),({1+random(2)}));
                 break;
        case 6:  set_monsters(({MON"bird"}),({1}));
                 break;
        case 7:  set_monsters(({MON"scarecrow"}),({1}));
                 break;
        case 8:  set_monsters(({MON"whatsit"}),({1}));
                 break;
        case 9:  set_monsters(({MON"squirrel"}),({1}));
                 break;
        case 10:  set_monsters(({MON"chicken"}),({1+random(2)}));
                 break;
        default: break;
     }
}