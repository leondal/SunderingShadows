#include <std.h>
#include "../farm.h"

inherit ROOM;
int count,pixiecount;

void create(){
   ::create();
   set_indoors(1); 
   set_property("light",2);
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_name("Inside the wheelhouse");
   set_short("Inside the wheelhouse");
   set_long("This is the upper floor of the wheel house.  It is "+
      "only half as wide as the bottom floor, with a %^BOLD%^"+
      "railing %^RESET%^protecting you from falling over.  On the "+
      "eastern end, a %^ORANGE%^wooden ladder %^RESET%^leads "+
      "down to the bottom floor.  This small area is crowded with "+
      "all sorts of %^MAGENTA%^experiments%^RESET%^ and strange "+
      "%^CYAN%^contraptions%^RESET%^.  Many %^ORANGE%^tables "+
      "%^RESET%^of differing heights are spread around, and "+
      "each is topped by %^CYAN%^glassware%^RESET%^, a strange "+
      "%^GREEN%^machine %^RESET%^fitted with %^RED%^dials %^RESET%^"+
      "and %^YELLOW%^knobs%^RESET%^, or something else equally "+
      "strange.  Many of the experiments have been hooked to "+
      "%^BOLD%^%^BLUE%^wires %^RESET%^running from the %^YELLOW%^"+
      "cogs %^RESET%^below.  It seems the owner of this unusual "+
      "laboratory has found some way of generating power through "+
      "them - how strange!\n");
   set_items(([
      ({"ladder","wooden ladder"}) : "The ladder is just tall enough "+
         "to reach the upper floor.  If is very narrow and sized for a "+
         "gnome, though it looks sturdy enough to hold a large "+
         "individual.",
      ({"wire","wires"}) : "The wires are attached to various "+
         "experiments in progress, though their exact function is "+
         "unclear.",
      "railing" : "The short railing is clearly sized for a gnome.  "+
         "It allows you to peer down at what is below without "+
         "fear of falling over...well, sort of.",
      ({"table","tables","experiments","contraptions"}) : "The "+
         "experiments are crowded all around this space.  There "+
         "is almost too much to look at!  In particular, five "+
         "different experiments stand out - you could probably "+
         "look at each.",
      "glassware" : "The glassware consists of beakers, vials, "+
         "jars, and simple jugs.  Most contain some sort of "+
         "liquid, although a few of the jars hold hapless "+
         "samples of different insect species.",
      ({"machine","machines"}) : "The machines are well-made "+
         "but unusual at best.  The purpose for them is "+
         "decidedly unclear, but doubtless they serve some "+
         "irreplacable function in the gnome's mind.",
      "experiment 1" : "This particular experiment consists of "+
         "a lone bug in a jar.  The insect is about two inches "+
         "long with a shiny exoskeleton colored %^ORANGE%^"+
         "bronze %^RESET%^with %^BOLD%^%^BLUE%^blue highlights"+
         "%^RESET%^.  Three wires rest in a harness above the "+
         "jar, not far from a metal plate in the jar's lid.  "+
         "It looks as though you could <touch> the wire to the "+
         "plate.\nA small plaque on the jar's base reads '"+
         "Experiment 13743261 - Nightlight'.",
      "experiment 2" : "On a table all by itself, this particular "+
         "experiment must be made for kitchen use.  The floured "+
         "surface of the marble table top is piled with dough "+
         "(gone a little old by now, to be sure).  Poised above "+
         "the dough is a wooden contraption.  It is a wheel fitted "+
         "with numerous webbed feet (thankfully not real feet).  "+
         "There is a metal knob on the side of the wheel, and you "+
         "could probably <turn> it.\nA small plaque under the knob "+
         "reads 'Experiment 4328169 - Dough Kneeder'.",
      "experiment 3" : "This experiment consists of a pair of "+
         "small boots fitted with tightly coiled springs.  "+
         "The springs have been compressed and fitted with "+
         "little hooks to hold them down.  It looks as though "+
         "you could <pull> one hook and all would come free.\n"+
         "A small plaque on the heel of the boot reads '"+
         "Experiment 3271839 - Boingee Boots'.",
      "experiment 4" : "A series of tubes has been bent and "+
         "woven around several posts.  Colorful %^BOLD%^"+
         "%^CYAN%^b%^GREEN%^e%^YELLOW%^a%^MAGENTA%^d%^RED%^s "+
         "%^RESET%^are meticulously spaced around the "+
         "contraption, threaded onto the tubes.  All are "+
         "carefully poised and remain motionless.  The "+
         "experiment has been fitted to a wooden base with a "+
         "brass button you could <press>.\nA small plaque on the base reads "+
         "'Experiment 832610 - Thingama~jig~gie'.",
      "experiment 5" : "This experiement catches your eye for "+
         "its rather mundane look.  It is a simple tea kettle, "+
         "placed on a round quilted cloth.  A series of wires "+
         "runs from the cogs below to the handle of the pot "+
         "with a note that reads, 'Reminder - do not touch!' "+
         "It looks as though you could <lift> the lid on the "+
         "teapot to see what's inside.\nA small plaque on the "+
         "front of the teapot reads 'Experiment 39 - Hot Bath'."
   ]));
   set_smell("default","The clean scent of pine is mixed with an "+
      "acrid odor of flame.");
   set_listen("default","The turning of the water wheel masks other sounds.");
   set_exits(([
      "down" : PATHS"wheelhouse1"
   ]));
}

void init(){
   ::init();
   add_action("touch_em","touch");
   add_action("turn_em","turn");
   add_action("pull_em","pull");
   add_action("press_em","press");
   add_action("lift_em","lift");
}

int touch_em(string str){
   if(!str){
      tell_object(TP,"Perhaps try <touch wire to plate>.");
      return 1;
   }
   if(str == "wire to plate" || str == "the wire to the plate"){
      tell_object(TP,"%^YELLOW%^You touch the wire to the metal "+
         "plate.");
      tell_room(TO,"%^YELLOW%^"+TPQCN+" touches a wire to the "+
         "metal plate of a jar.",TP);
      tell_room(TO,"%^BOLD%^%^BLUE%^Suddenly the insect's protective "+
         "plates open up, exposing iridescent wings.  The room fills "+
         "with a bright %^RED%^p%^RESET%^%^ORANGE%^r%^YELLOW%^i%^GREEN%^"+
         "s%^CYAN%^m%^BLUE%^a%^RESET%^%^BLUE%^t%^MAGENTA%^i%^RED%^c %^YELLOW%^"+
         "light%^BLUE%^!");
      tell_room(TO,"%^CYAN%^After a moment, the insect's wings fold "+
         "down and the room returns to normal.");
      return 1;
   }
   tell_object(TP,"Perhaps try <touch wire to plate>.");
   return 1;
}

int turn_em(string str){
   if(!str){
      tell_object(TP,"Perhaps try <turn knob>.");
      return 1;
   }
   if(str == "undead") return 0;
   if(str == "knob"){
      tell_object(TP,"You turn the knob on the wooden wheel.");
      tell_room(TO,""+TPQCN+" turns the knob on a wooden wheel.",TP);
      tell_room(TO,"%^ORANGE%^The wooden wheel begins turning "+
         "quickly, the little webbed feet pounding into the dough.");
      tell_room(TO,"%^BOLD%^Flour pours everywhere, blanketing "+
         "the area before the feet finally stop!");
      return 1;
   }
   tell_object(TP,"Perhaps try <turn knob>.");
   return 1;
}

int pull_em(string str){
   if(!str){
      tell_object(TP,"Perhaps try <pull hook>.");
      return 1;
   }
   if(str == "hook" || str == "hooks" || str == "one hook"){
      tell_object(TP,"%^BOLD%^You pull the metal hook and the springs "+
         "come loose!");
      tell_room(TO,"%^BOLD%^"+TPQCN+" pulls the metal hook of a "+
         "spring on some boots.",TP);
      tell_room(TO,"%^BOLD%^%^MAGENTA%^The boots begin bouncing "+
         "wildly all over the table!");
      tell_room(TO,"%^MAGENTA%^Finally the boots seem to lose their "+
         "energy and settle down once more.");
      return 1;
   }
   tell_object(TP,"Perhaps try <pull hook>.");
   return 1;
}

int lift_em(string str){
   if(!str){
      tell_object(TP,"Perhaps try <lift lid>.");
      return 1;
   }
   if(str == "lid" || str == "teapot lid"){
      tell_object(TP,"%^BOLD%^You lift the lid off the teapot "+
         "and peer inside.");
      tell_room(TO,"%^BOLD%^"+TPQCN+" lifts the lid off the "+
         "teapot and peers inside.",TP);
      call_out("pixies",3);
      return 1;
   }
   tell_object(TP,"Perhaps try <lift lid>.");
   return 1;
}

int press_em(string str){
   if(!str){
      tell_object(TP,"Perhaps try <press button>.");
      return 1;
   }
   if(str == "button" || str == "the button" || str == "brass button"){
      tell_object(TP,"%^ORANGE%^You press the brass button on "+
         "the wooden base.");
      tell_room(TO,"%^ORANGE%^"+TPQCN+" presses a brass button on "+
         "one of the experiments.",TP);
      tell_room(TO,"%^BOLD%^%^CYAN%^Metal tubes attached to the "+
         "wooden base begin spinning.");
      call_out("spin",3);
      count = 0;
      return 1;
   }
   tell_object(TP,"Perhaps try <press button>.");
   return 1;
}

int spin(){
   switch(count){
      case 0:  tell_room(TO,"%^BOLD%^%^MAGENTA%^The beads slide "+
               "along the tubes, racing around!");
               count++;
               call_out("spin",3);
               break;
      case 1:  tell_room(TO,"%^BOLD%^%^RED%^The beads begin to "+
               "collide, making a clicking sound before they "+
               "bounce off each other and go in opposite directions!");
               count++;
               call_out("spin",3);
               break;
      case 2:  tell_room(TO,"%^BOLD%^%^BLUE%^Surprisingly, the "+
               "beads form a quick melody that sounds much like "+
               "the music of the fae!");
               count++;
               call_out("spin",3);
               break;
      case 3:  tell_room(TO,"%^GREEN%^As the music reaches its "+
               "apex, a tiny faerie pops his head out of a nearby "+
               "jug.  The faerie flits over to the beads and "+
               "begins dancing a jig!");
               count++;
               call_out("spin",3);
               break;
      case 4:  tell_room(TO,"%^YELLOW%^The grin slides from the "+
               "faerie's face as the beads slow and the music "+
               "stops.  He flies back to his jug with slumped "+
               "shoulders and disappears from sight.");
               count = 0;
               break;
      default: tell_room(TO,"Bleh, it's broken.");
      break;
   }
   return 1;
}

int pixies(){
   switch(pixiecount){
      case 0: tell_object(TP,"%^MAGENTA%^To your amazement, you find a "+
         "small colony of pixies lounging about!");
         pixiecount++;
         call_out("pixies",3);
         break;
      case 1: tell_object(TP,"%^GREEN%^It seems they've built a home inside, "+
         "with banks made of %^BOLD%^%^BLACK%^chocolate%^RESET%^%^GREEN%^, "+
         "%^BOLD%^spunsugar grass%^RESET%^%^GREEN%^, and %^BOLD%^%^MAGENTA%^"+
         "gumdrop trees%^RESET%^%^GREEN%^!  Running all around are "+
         "rivers of warm, fragrant tea.");
         pixiecount++;
         call_out("pixies",3);
         break;
      case 2:  tell_object(TP,"%^BOLD%^%^BLUE%^Just as you put the lid back, "+
         "one of them calls out, '%^CYAN%^Hey, you!  You're lettin' "+
         "all the warm air out!%^BLUE%^'");
         pixiecount = 0;
         break;
      default: tell_room(TO,"Bleh, it's broken.");
      break;
   }
   return 1;
}
