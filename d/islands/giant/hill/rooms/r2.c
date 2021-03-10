#include "/d/islands/giant/giant.h"
#include <objects.h>
#include <daemons.h>
inherit ROOM;
int comb = 0;
int mirror = 0;
int pin =0;
int jumped = 0;
int broken = 0;
string combs = " ";
string mirrors = " ";
string pins = " ";



void create(){
  ::create();
   set_property("light",3);
   set_property("indoors",1);
   set_short("%^YELLOW%^Sub-Chief's Room%^RESET%^");
   set_long((:TO,"long_fun":));
   set_smell("default","It smells like slightly musty old furs in here.");
   set_listen("default","You think you hear something breathing now and then.");

   set_items(([ 
      "furs":"%^BOLD%^They appear to come form a variety of animals; such as bear, deer and elk.",
      "bed":"%^BOLD%^The bed is giant sized and appears to have a abnormally large stack of furs on top of it.%^RESET%^",
      "shelf":"%^BOLD%^The shelf is too high for you to clearly see the things on it.  Perhaps you could jump up to it.%^RESET%^",
   ]));

   set_exits(([ 
      "east": HROOM+"h3.c",
   ]));
}

void init(){
   ::init();
   add_action("jump","jump");
   add_action("take","take");
}

int jump(string str) {
   if(comb == 0) combs = "%^BOLD%^Silvered Comb%^RESET%^\n";
   if(mirror == 0) mirrors = "%^YELLOW%^Copper Mirror%^RESET%^\n";
   if(pin == 0) pins = "%^ORANGE%^Gold Pin%^RESET%^\n";
   if((random(this_player()->query_stats("dexterity"))+(this_player()->query_size())) > random(35)){
      say("%^BOLD%^"+this_player()->query_cap_name()+" successfully leaps up to the shelf.%^RESET%^");
      write("%^BOLD%^You successfully leap up to the shelf and see upon it a: \n\n"+
      combs+
      mirrors+
      pins+
      "%^RESET%^");
      jumped += 1;
   } else {
      write("%^RED%^You leap up but fail to correctly grip the shelf! \n%^BOLD%^ In your strugle you manage to break the fragile material the shelf is made out of and bring it crashing to the floor along with you!%^RESET%^");
      say("%^RED%^"+this_player()->query_cap_name()+" leaps up to grab the shelf but any manages to break it's fragile framework and send "+this_player()->query_objective()+"self and the shelf crashing to the floor!%^RESET%^");
      if(time != "night"){
         write("%^BOLD%^All this noise succeeds in waking the sleeping giantess under the furs on the bed!%^RESET%^");
         say("%^BOLD%^All this noise succeeds in waking the sleeping giantess under the furs on the bed!%^RESET%^");
         new(HMON+"subwife.c")->move(this_object());
      }
      new(HMON+"subwife.c")->move(this_object());
      broken = 1;
   }
   if(jumped > 1) {
      write("%^RED%^The increase in weight proves to be too much for the shelf to handle! \n %^BOLD%^ You fall to the floor along with the shelf!");
      say("%^RED%^"+this_player()->query_cap_name()+" leaps up to the shelf, but the increase in weight proves to be too much for the shelf to handle! \n "+this_player()->query_subjective()+" %^BOLD%^Flies down and lands flat on "+this_player()->query_objective()+" back!%^RESET%^");
      this_player()->do_damage(3,4);
      broken = 1;
      if(time != "night"){
         write("%^BOLD%^All this noise succeeds in waking the sleeping giantess under the furs on the bed!%^RESET%^");
         say("%^BOLD%^All this noise succeeds in waking the sleeping giantess under the furs on the bed!%^RESET%^");
         new(HMON+"subwife.c")->move(this_object());
      }
   }
}

int take(string str) {
   if(broken == 1) {
      write("You aren't getting anything now that somebody has smashed the shelf and whatever it once held into smitherines");
      say(this_player()->query_cap_name()+" rummages through the debris that is left but finds nothing left.");
      return 1;
   }
   if(jumped == 0){
      write("You aren't getting anything from down here on the floor");
      return 1;
   }
   if(str == "comb" || str == "silvered comb" && comb == 0) {
      new(HOBJ+"comb.c")->move(this_player());
      write("You grab the comb off the shelf, but lose your grip and fall back to the floor.");
      say(this_player()->query_cap_name()+" grabs a %^BOLD%^Silver Comb%^RESET%^ off the shelf, but loses "+this_player()->query_objective()+" grip and tumbles back to the floor.");
      comb = 1;
      jumped += -1;
   }
   if(str == "mirror" || str == "copper mirror" && mirror == 0) {
      new(HOBJ+"mirror.c")->move(this_player());
      write("You grab the mirror off the shelf, but lose your grip and fall back to the floor.");
      say(this_player()->query_cap_name()+" grabs a %^YELLOW%^Copper Mirror%^RESET%^ off the shelf, but loses "+this_player()->query_objective()+" grip and tumbles back to the floor.");
      mirror = 1;
      jumped += -1;
   }
   if(str == "pin" || str == "gold pin" && pin == 0) {
      new(HOBJ+"pin.c")->move(this_player());
      write("You grab the pin off the shelf, but lose your grip and fall back to the floor.");
      say(this_player()->query_cap_name()+" grabs a %^ORANGE%^Gold Pin%^RESET%^ off the shelf, but loses "+this_player()->query_objective()+" grip and tumbles back to the floor.");
      pin = 1;
      jumped += -1;
   }
}

void reset() {
   ::reset();
   comb = 0;
   mirror = 0;
   pin = 0;
   broken = 0;
   combs = " ";
   mirrors = " ";
   pins = " ";
   if(time == "night"){
      new(HMON+"subwife.c")->move(this_object());
   }
   if(time == "dawn" && present("helen")){
      present("helen")->remove();
   }
}

string long_fun(string str){
   if(broken == 0 && time != "night"){
      str =
         "%^YELLOW%^This appears to be the living quarters of a pretty important "+
         "person.  It is large and has many furs scattered about the floor.  "+
         "There is a large bed piles high with furs in the corner.  There is a "+
         "small shelf about 10 feet off the floor attached to the wall.  The room "+
         "appears to be well kept by Hill Giant standards.%^RESET%^";
   } else if(broken == 1 && time != "night"){
      str =
         "%^YELLOW%^This appears to be the living quarters of a pretty important "+
         "person.  It is large and has many furs scattered about the floor.  "+
         "There is a large bed piles high with furs in the corner.  There was "+
         "one a shelf attached to the wall here, but it appears to have been "+
         "ripped free and has it's contents smashed on the floor.  The small "+
         "fireplace in the corner of the room is unlit.  The room is quite "+
         "well kept for Hill Giant standards.";
   } else if(broken == 0 && time == "night"){
      str =
         "%^YELLOW%^This appears to be the living quarters of a pretty important "+
         "person.  It is large and has many furs scattered about the floor.  "+
         "There is a large bed piles high with furs in the corner.  There is a "+
         "small shelf about 10 feet off the floor attached to the wall.  The "+
         "lit fireplace casts an %^RED%^eeerie glow%^YELLOW%^ about the room and makes the "+
         "%^BLACK%^shadows %^YELLOW%^appear to dance on the wall with every flicker of the flame. "+
         "There is a pot hanging above the fireplace with some sort of stew in "+
         "it.  The room is very well kept by hill giant standards.";
   } else if(broken == 1 && time == "night"){
      str =
         "%^YELLOW%^This appears to be the living quarters of a pretty important "+
         "person.  It is large and has many furs scattered about the floor.  "+
         "There is a large bed piles high with furs in the corner.  There was "+
         "one a shelf attached to the wall here, but it appears to have been "+
         "ripped free and has it's contents smashed on the floor.  The small "+
         "lit fireplace casts an %^RED%^eeerie glow%^YELLOW%^ about the room and makes the "+
         "%^BLACK%^shadows %^YELLOW%^appear to dance on the wall with every flicker of the flame. "+
         "There is a pot hanging above the fireplace with some sort of stew in "+
         "it.  The room is very well kept by hill giant standards.";
   }
   return str;
}
