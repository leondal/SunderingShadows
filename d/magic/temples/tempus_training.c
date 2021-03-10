//training room for Tempus's temple. 
//Desc by Taeryn.  ~Circe~ 4/1/05
#include <std.h>
inherit ROOM;
int curlit;

void create(){
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
   set_name("Training Arena");
   set_short("Training Arena");
   set_long("%^RESET%^%^RED%^This is a large outdoor arena made of the "+
      "same thick stone as the armory.  The walls are lined with "+
      "%^ORANGE%^wooden racks %^RED%^holding generic weaponry; swords, "+
      "spears, maces, daggers, halberds, and flails are all hung in an "+
      "orderly manner.  This room would almost resemble a torture "+
      "chamber due to all the sharp instruments, that is, if it "+
      "weren't for the warriors constantly training and sparring "+
      "against one another.  Glancing up you can see that there "+
      "is a complete lack of a ceiling.  Those who wish to train "+
      "and test themselves here must endure the elements, "+
      "similar to those engaging in serious battle.  You notice "+
      "the %^ORANGE%^soil %^RED%^is kept slightly %^BOLD%^%^CYAN%^"+
      "wet%^RESET%^%^RED%^, and as a result the %^WHITE%^a%^CYAN%^"+
      "i%^WHITE%^r %^RED%^is free of dust from shuffling feet and "+
      "rolling bodies.  Around the perimeter of this great arena "+
      "are two stone steps so spectators will have a place to sit "+
      "out of the way, and tired warriors a place to relax.  Just "+
      "above these steps, mounted on the walls are several %^BOLD%^"+
      "%^RED%^torches %^RESET%^%^RED%^that could be lit on a dark "+
      "night.%^RESET%^\n");
   set_smell("default","%^RESET%^%^ORANGE%^The scent of blood and "+
      "sweat is thick here, but not overpowering as the open air "+
      "allows for some refuge.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLACK%^You hear the almost "+
      "deafening ring of metal weapons clashing together.  "+
      "There is the occasional grunt, yelp, and loud curse.  "+
      "The spectators murmur and shake with laughter as they watch "+
      "their friends and foes demonstrate their battle prowess.");
   set_items(([
      ({"ground","sand"}) : "%^RESET%^%^ORANGE%^The ground "+
         "here is shallow sand kept wet in "+
         "order to minimize the blinding clouds of dust that "+
         "would otherwise be kicked up by maneuvering warriors.",
      ({"step","steps"}) : "%^BOLD%^%^BLACK%^Ah, a place to "+
         "rest your tired bones, or catch a good fight if you "+
         "are more for watching than engaging.%^RESET%^",
      ({"torch","torches"}) : "The torches are set into the wall "+
         "and could probably lighten the room on a dark night.  "+
         "You could try to <light> or <douse> the torches as "+
         "needed.",
      ({"ceiling","sky"}) : (:TO,"sky_desc":)
   ]));
   set_exits(([
      "southwest" : "/d/magic/temples/tempus"
   ]));
   curlit = 0;
}

string sky_desc() {
   if(query_night()) {
     return(
"%^RESET%^%^BLUE%^The sky is a beautiful midnight blue "+
"in hue, almost %^BOLD%^%^BLACK%^black%^RESET%^%^BLUE%^.  "+
"However the %^BOLD%^%^WHITE%^st%^BLACK%^ar%^WHITE%^li"+
"%^BLACK%^g%^WHITE%^ht %^RESET%^%^RED%^and the rays of the "+
"%^BOLD%^%^WHITE%^moon %^RESET%^%^RED%^bathe the arena in an "+
"eerie light.  On a particularly %^BOLD%^%^BLACK%^dark night"+
"%^RESET%^%^BLUE%^, the %^RED%^torches %^BLUE%^can be %^BOLD%^"+
"%^YELLOW%^lit %^RESET%^%^BLUE%^in order for everyone to see "+
"clearly.%^RESET%^"
     );
   } else {
     return(
"%^BOLD%^%^CYAN%^Gazing upwards your eyes are assaulted by "+
"the glorious light of the %^BOLD%^%^YELLOW%^s%^WHITE%^u"+
"%^YELLOW%^n%^RESET%^%^WHITE%^-%^ORANGE%^sc%^RED%^o%^ORANGE%^"+
"r%^BOLD%^%^YELLOW%^ch%^RESET%^%^ORANGE%^ed %^BOLD%^%^CYAN%^sky.  "+
"The open ceiling provides no other view than sky for as far as "+
"the eye can see.  Passing %^BLUE%^cl%^WHITE%^o%^CYAN%^u%^RESET%^"+
"%^BLUE%^ds %^BOLD%^%^CYAN%^cause %^BLACK%^sh%^WHITE%^ad%^BLACK%^o"+
"%^WHITE%^w%^BLACK%^s %^CYAN%^to play across the arena.%^RESET%^"
     );
   }
}

void init(){
   ::init();
   add_action("light_torches","light");
   add_action("douse_torches","douse");
}

/*light torches should increase the amount of light in the room by 1 each time */
int light_torches(string str) {
   if(!str || str != "torch") {
      tell_object(TP,"Try <light torch>");
      return 1;
   }
   if(!query_night()){
      tell_object(TP,"It's daytime!  Why would you need to "+
         "light the torches?");
      return 1;
   }
   if(curlit < 3){
      tell_object(TP,"You strike a flint and light one of the "+
         "torches, brightening the training area.");
      tell_room(ETP,""+TPQCN+" strikes the flint and lights a "+
         "torch.",TP);
      set_property("light",1);
      curlit ++;
      return 1;
   }
   tell_object(TP,"All the torches in the area are lit!");
   return 1;
}

/*douse torches should decrease the amount of light in the room by 1 each time */
int douse_torches(string str) {
   if(!str || str != "torch") {
      tell_object(TP,"Try <douse torch>");
      return 1;
   }
   if(curlit > 0){
      tell_object(TP,"You bash the torch against the wall, "+
         "putting it out.");
      tell_room(ETP,""+TPQCN+" bashes the torch against the "+
         "wall, putting it out amid sparks.",TP);
      set_property("light",-1);
      curlit --;
      return 1;
   }
   tell_object(TP,"All the torches in the area are dark!");
   return 1;
}
