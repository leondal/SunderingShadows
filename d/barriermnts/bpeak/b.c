#include <std.h>
#include "bpeak.h"
inherit ROOM;
int searched;

void create(){
::create();
   set_property("light",2);
   set_travel(FOOT_PATH);
   set_terrain(BEACH);
   set_name("%^RESET%^%^ORANGE%^A long a beach%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^A sandy beach%^RESET%^");
   set_long((:TO,"ldesc":));
   set("night long","%^RESET%^%^BLUE%^The %^RESET%^stars %^BOLD%^%^WHITE%^gl"
"%^CYAN%^i%^WHITE%^tt%^CYAN%^e%^WHITE%^r %^RESET%^%^BLUE%^down from the darkened"
" skies and cast their %^RESET%^light %^BLUE%^upon the %^ORANGE%^sandy beach."
"  %^BLUE%^The %^BOLD%^%^WHITE%^moon %^RESET%^%^BLUE%^reflects off of the waters of"
" the %^CYAN%^sea, %^BLUE%^highlighting the %^RESET%^c%^BOLD%^%^WHITE%^r%^RESET%^"
"e%^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^%^WHITE%^s %^RESET%^%^BLUE%^of the"
" %^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^a%^RESET%^v%^CYAN%^e%^BOLD%^%^CYAN%^s"
" %^RESET%^%^BLUE%^as they form and crash softly against the shores.  To the"
" northeast, a %^RESET%^bright %^YELLOW%^light %^RESET%^shines %^BLUE%^out over the"
" %^CYAN%^sea %^BLUE%^from atop a cliff, guiding the ships home as they try to"
" maneuver through the Dagger Straits to the east.  To the south the outline of"
" the great Barrier Mountains can be seen, while to the north the outline of the"
" walls of the seaport city of Torm are still visible.");
   set_smell("default","%^RESET%^%^CYAN%^The smells of salt water and seaweed float in on the ocean breeze.%^RESET%^");
   set_listen("default","%^RESET%^The gentle %^BOLD%^%^WHITE%^roar %^RESET%^of the %^CYAN%^ocean %^RESET%^and the %^BOLD%^%^WHITE%^crashing %^RESET%^of small %^CYAN%^w%^RESET%^a%^BOLD%^%^WHITE%^v%^RESET%^e%^CYAN%^s %^RESET%^is heard.");
   set_items(([
   ({"shores","shore","beach"}):"%^RESET%^%^ORANGE%^The sandy shores of the beach are a light orange in color and get %^BOLD%^%^BLACK%^darker %^RESET%^%^ORANGE%^nearer the %^CYAN%^waters %^ORANGE%^edge where the %^BOLD%^%^BLACK%^wet %^RESET%^%^ORANGE%^sands mark the %^CYAN%^tide %^ORANGE%^line.%^RESET%^",
   ({"water","waters","sea","ocean"}):"%^RESET%^%^CYAN%^The waters of the Dagger Sea reach out endless before you.  %^BOLD%^%^WHITE%^White capped %^CYAN%^w%^BOLD%^%^WHITE%^a%^RESET%^v%^CYAN%^e%^BOLD%^%^WHITE%^s %^RESET%^%^CYAN%^gently roll in on the %^ORANGE%^beach, %^CYAN%^while further out that faint outlines of %^ORANGE%^ships masts %^CYAN%^mark the horizon.%^RESET%^",
   "kelp":"%^RESET%^%^GREEN%^The kelp litters the beach and is a dark green color and looks much like long, slimey vines with elongated, thickly ribbed leaves.  Small, rounded bulbs seem to be attached to them in various places.%^RESET%^",
   "waves":"%^%^BOLD%^%^WHITE%^The waves here are maybe about two or three foot in height.  Nothing to be to frightened of.%^RESET%^",
   ({"shells","seashells"}):"%^RESET%^The %^BOLD%^%^BLACK%^s%^RESET%^e%^BOLD%^%^WHITE%^a%^RESET%^s%^BOLD%^%^WHITE%^h%^BLACK%^e%^RESET%^l%^BOLD%^%^WHITE%^l%^BLACK%^s %^RESET%^litter the beach.  Some of them are broken up into small pieces and mix in with the sands, but a good deal of them still are whole and in good shape.",
   ({"crab","crabs"}):"%^BOLD%^%^BLACK%^More commonly known as hermit crabs, these small creatures are tiny and have made their homes in the various %^RESET%^shells %^BOLD%^%^BLACK%^that litter the %^RESET%^%^ORANGE%^beach.  %^BOLD%^%^BLACK%^They scurry across the %^RESET%^%^ORANGE%^sand %^BOLD%^%^BLACK%^and then quickly bury themselves from view.%^RESET%^",
   "city":"%^RESET%^The outline of the city of Torm can be seen to the north.",
   ({"sand","sands"}):"%^RESET%^%^ORANGE%^The sand is fine and gritty, polished to"
" a dull orange %^RESET%^shine %^ORANGE%^from constantly being turned by the"
" %^BOLD%^%^WHITE%^pounding %^RESET%^%^ORANGE%^of the small %^BOLD%^%^CYAN%^w"
"%^RESET%^%^CYAN%^a%^RESET%^v%^CYAN%^e%^BOLD%^%^CYAN%^s.  %^RESET%^%^ORANGE%^If you"
" look closely enough, you can see that the sand is actually composed of numerous"
" tiny pieces of %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^WHITE%^c%^BLACK%^k,"
" %^RESET%^glass, %^ORANGE%^and %^RESET%^s%^BOLD%^%^WHITE%^e%^BLACK%^a%^WHITE%^s"
"%^RESET%^h%^BOLD%^%^BLACK%^e%^WHITE%^l%^RESET%^l%^BOLD%^%^WHITE%^s.",
   ({"mountains","mountain","Barrier Mountains","barrier mountains"}):"%^RESET%^%^BLUE%^To the southwest, the craggy peaks of the Barrier Mountains loom in the distance.%^RESET%^",
   ({"ships","masts"}):"%^RESET%^%^ORANGE%^The masts of various trade and fishing ships dot the horizon as they sail in and out of the Dagger Straits towards the seaport of Torm.",
   ]));
   set_search("default", "%^ORANGE%^Many things here catch your attention, from the"
" sands at your feet to the gently rolling waves of the ocean.%^RESET%^");
   set_search("sand",(:TO,"search_sand":));
   set_search("sands",(:TO,"search_sand":));
   set_search("beach",(:TO,"search_sand":));
   set_search("waves",(:TO,"search_waves":));
   set_search("water",(:TO,"search_waves":));
   set_search("kelp",(:TO,"search_kelp":));
   set_search("seaweed",(:TO,"search_kelp":));
   set_search("shells",(:TO,"search_shells":));
   set_search("seashells",(:TO,"search_shells":));
}
string ldesc(string str){
   return("%^RESET%^You've walked away from the path leading to Torm and have"
" wandered onto the %^ORANGE%^sandy %^CYAN%^shores %^RESET%^of the %^ORANGE%^beach."
"  %^RESET%^The %^BOLD%^%^CYAN%^clear %^RESET%^%^CYAN%^w%^BLUE%^a%^BOLD%^%^CYAN%^"
"t%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^r%^BLUE%^s %^RESET%^of the"
" %^CYAN%^Dagger Sea %^RESET%^roll up to the %^ORANGE%^shores %^RESET%^in"
" %^BOLD%^%^WHITE%^white capped %^CYAN%^w%^RESET%^%^CYAN%^a%^BLUE%^v%^BOLD%^%^CYAN%^"
"e%^RESET%^%^CYAN%^s %^RESET%^that continually wash up %^GREEN%^kelp,"
" %^RESET%^s%^BOLD%^%^WHITE%^h%^BLACK%^e%^WHITE%^l%^RESET%^l%^BOLD%^%^WHITE%^s,"
" %^RESET%^and other pieces of %^CYAN%^sea life, %^RESET%^leaving them to litter"
" the %^ORANGE%^sands %^RESET%^around you feet. Every once in a while"
" a small %^RESET%^c%^BOLD%^%^BLACK%^r%^RESET%^a%^BOLD%^%^BLACK%^b %^RESET%^"
"can be seen scurrying across the %^ORANGE%^sands %^RESET%^before it burrows down"
" below them."
"
The city of Torm can be seen to the north, while the outline of the %^BLUE%^Barrier"
" Mountains %^RESET%^can be seen looming in the southwest.%^RESET%^\n");
}
void reset() {
   ::reset();
   searched = 1 ;
}
void search_sand() {
   object ob;
   if(searched <= 0) {               
      write("%^RESET%^%^ORANGE%^You bend down to inspect the sand, but notice it looks like it has already been sifted through.");
      tell_room(TO, "%^RESET%^%^ORANGE%^"+TPQCN+" kneels down to look at the sand but then decides against it.",TP);
      return ;
   }
   if (searched == 1) {  
      switch(random(100)){
         case 0:
            write("You bend over and sift your hands through the fine sand, brushing up against something solid as you do.  Grabbing hold of it, you pull it out and set it on the beach for all to see.\n");
            tell_room(TO,""+TPQCN+" bends over and begins to gently sift the sand through "+TP->query_possessive()+" hands before pulling something out and setting in on the beach for you to see.",TP);
            ob = new("/d/magic/scroll");
            ob->set_spell(random(3)+1);
            ob->move(TO);
            searched = 0;
            break;
         case 1..70:
            write("You sift your hands through the sand and let the fine grains run through your fingers, realizing how tiny each piece of sand is, but how large the beach seems.");
            tell_room(TO,""+TPQCN+" reaches down and sifts the small grains of sand through "+TP->query_possessive()+" hand, looking lost in thought.",TP);
            searched = 0;
            break;
         case 71..99:
            write("You scream in pain as something clamps onto the tip of your finger as soon as you stick your hand into the sand!  As you pull your fingers out, a little crab drops off and quickly burrows back into the sand and out of sight.");
           tell_room(TO,""+TPQCN+" screams in pain as "+TP->query_subjective()+" sticks "+TP->query_possessive()+" hand into the sand!",TP);
            TP->do_damage("torso",random(6)+10);
      }
   }
}
void search_waves() {
   write("%^RESET%^%^CYAN%^You run out waist deep into the water and splash around in the waves before you find... more water!  Soaked, you return to the shore.%^RESET%^");
   tell_room(TO,"%^RESET%^%^CYAN%^"+TPQCN+" runs out waist deep into the water and splashes around in the waves before coming back to the shore absolutely soaked.%^RESET%^",TP);
}
void search_kelp() {
   write("%^RESET%^%^GREEN%^Wee! You reach down and touch the slimey kelp, marvelling at the strange texture.%^RESET%^");
   tell_room(TO,"%^RESET%^%^GREEN%^"+TPQCN+" reaches down and picks up some kelp and looks as though "+TP->query_subjective()+" is having alot of fun playing with it.%^RESET%^",TP);
}
void search_shells() {
   write("%^RESET%^You carefully look around at all the %^BOLD%^%^WHITE%^s%^RESET%^%^ORANGE%^h%^RESET%^e%^BOLD%^%^WHITE%^l%^BLACK%^l%^RESET%^%^ORANGE%^s %^RESET%^littering the %^ORANGE%^beach %^RESET%^and find a whole one.");
   tell_room(TO,"%^RESET%^"+TPQCN+" finds a %^BOLD%^%^WHITE%^s%^RESET%^%^ORANGE%^h%^RESET%^e%^BOLD%^%^WHITE%^l%^BLACK%^l %^RESET%^on the %^ORANGE%^beach.%^RESET%^",TP);
   switch(random(5)){
      case 0..3:
         new(OBJD+"shells.c")->move(TO);
      break;
      case 4:
         new(OBJD+"conchshell1.c")->move(TO);
      break;
   }
   return;
}
      




