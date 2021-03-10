//oasis
#include <std.h>
#include <rooms.h>
#include "/d/darkwood/yntala/yntala.h"
inherit PIER;
int picked, picked1;

void create(){
::create();
   set_property("outdoors",1);
   set_property("light",1);
   set_property("no teleport",1);
   set_water_body("river");
   set_property("no magic",1);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("%^BOLD%^%^GREEN%^An island oasis");
   set_short("%^BOLD%^%^GREEN%^An island oasis%^RESET%^");
   set_smell("default","%^BOLD%^%^CYAN%^The air is crisp and fresh smelling.");
   set_long((:TO,"ldesc":));
   set_items(([
   "river":"%^RESET%^%^CYAN%^The river that surrounds this island moves at a slow, relaxed pace.   A small branch of it cuts through the island and disappears into the %^BOLD%^%^BLACK%^cave %^RESET%^%^CYAN%^to the south.",
   ({"willow","willow tree"}):"%^BOLD%^%^GREEN%^This beautiful willow tree looks healthy and happy.  It's drooping branches curve gracefully towards the ground, veiling all that may be beneath.%^RESET%^",
   ({"stones","rocks"}):"Scattered about the area, several large stones peek up through the lush grass.  Each stone is smooth to the touch and naturally curved.  An excellent place to sit and relax!",
   "grass":"%^BOLD%^%^GREEN%^The grass here is a lush and healthy.  Standing about a foot in height, it's lush green color sets a perfect backdrop for this island.",
   ({"columns","marble columns"}):"%^BOLD%^Large marble columns once dominated this island, standing tall around the %^CYAN%^pool %^WHITE%^they shelter.  Now however, only a few remain standing, with the majority of them laying broken on the ground, covered by %^RESET%^%^GREEN%^moss %^RESET%^%^BOLD%^and %^RESET%^%^GREEN%^ivy.%^RESET%^",
   "haze":"%^RESET%^%^CYAN%^Covering and surrounding this area is a strange blue haze that crackles with energy, or the absence of.",
   "shores":"%^RESET%^%^GREEN%^The green grass grows all the way to the islands shores, touching the gently flowing water.",
   "pool":"%^BOLD%^%^CYAN%^This pool has been dug into the ground and made with %^WHITE%^white marble %^CYAN%^inlaid with intricate patterns of %^YELLOW%^gold.  %^CYAN%^The water remains crystal clear and looks cleaner than any you could possibly hope to find elsewhere.  Easily forty feet in length and slightly sloped, the western end of the pool is about four feet deep, while the eastern end is more like twelve.  Spaced at even intervals along the edges are large %^WHITE%^marble pots %^CYAN%^that still have thriving %^GREEN%^ferns %^CYAN%^growing in them.",
   "pots":"%^BOLD%^These marble pots are two feet high and about two feet in diameter.  They stand on little carved pedestal type feet and have %^GREEN%^lush ferns %^WHITE%^growing from them.",
    "archway":"This archway has been built into the fence to allow access to the %^BOLD%^%^CYAN%^pool %^RESET%^area within.  It is now covered in mature %^GREEN%^grape vines.",
    ({"grapes","grape vines"}):"%^RESET%^%^GREEN%^These large grape vines grow over the archway in the fence, casting shade over the entry way below them.%^RESET%^",
    ({"wall","stone wall"}):"%^RESET%^This low %^BOLD%^s%^BLACK%^t%^RESET%^o%^BOLD%^%^BLACK%^n%^WHITE%^e %^RESET%^w%^BOLD%^%^BLACK%^a%^RESET%^l%^BOLD%^l %^RESET%^encircles the %^BOLD%^%^CYAN%^pool area %^RESET%^and only stands about two feet in height.  It is completely covered with %^GREEN%^vines %^RESET%^of all sorts, and the archway is covered with mature %^GREEN%^grape vines.%^RESET%^",
    ({"vines","ivy"}):"%^RESET%^%^GREEN%^Green vines snake and twist their way over the %^RESET%^st%^BOLD%^o%^BLACK%^n%^RESET%^e wall %^GREEN%^and %^RESET%^fallen columns, %^GREEN%^covering all but a few small spots with leafy foliage.%^RESET%^",
    ({"orchid","orchids","flowers","wild orchids"}):"%^RESET%^%^MAGENTA%^Growing around the %^BOLD%^%^GREEN%^willow tree %^RESET%^%^MAGENTA%^are several beautiful wild orchids that fill the area with an exotic scent.  You may be able to grab some.%^RESET%^",
]));
   set_exits((["south":INRMS+"scave4"]));
   picked == 4;
   picked1 == 5;
}
string ldesc(string str){
   return("%^BOLD%^%^GREEN%^This beautiful island has somehow managed to avoid the "
"misfortune of the rest of the %^RESET%^%^GREEN%^forest. %^BOLD%^ The"
" %^CYAN%^r%^BLUE%^i%^CYAN%^v%^BLUE%^e%^CYAN%^r %^GREEN%^surrounding it moves at its own leisurely pace"
", with a small fork of it branching through the center of the island before disappearing into the mouth of the"
" %^BLACK%^cave %^GREEN%^at its southern end.  While the rest of the %^RESET%^%^GREEN%^forest"
" %^BOLD%^can be seen in the distance,"
" %^GREEN%^it seems as though it could be a million miles away.  A large willow tree grows in the center of the area,"
" surrounded by lush grass and the occassional wild %^MAGENTA%^or%^RESET%^%^MAGENTA%^c%^BOLD%^h%^RESET%^%^MAGENTA%^i"
"%^BOLD%^d.  %^GREEN%^A few %^WHITE%^m%^BLACK%^a%^RESET%^r%^BOLD%^%^BLACK%^b%^WHITE%^le columns"
" %^GREEN%^rise from the ground at the eastern edges, and surround a %^CYAN%^crystal clear pool %^GREEN%^that has "
"been painstakingly made out of %^WHITE%^white marble %^GREEN%^inlaid with %^YELLOW%^gold.  %^GREEN%^Though the"
" %^WHITE%^columns %^GREEN%^were probably magnificant to view at one point, it appears that most of them have"
" fallen over with the ages, and now lay in broken pieces on the ground.  Wild %^RESET%^%^GREEN%^ivy"
" %^BOLD%^%^GREEN%^and %^RESET%^%^GREEN%^moss%^BOLD%^ now covers them, as well as the low %^RESET%^stone wall"
" %^BOLD%^%^GREEN%^that still stands to surround the area they stood in.  Oddly enough, the %^CYAN%^pool %^GREEN%^"
"itself seems to have stayed in remarkable condition, and the %^CYAN%^water %^GREEN%^still looks clean and pure.  "
"In the center of the %^RESET%^wall, %^BOLD%^%^GREEN%^an arch has been built to allow access inside, and is now"
" covered with %^RESET%^%^MAGENTA%^grape %^BOLD%^%^GREEN%^laden %^RESET%^%^GREEN%^vines."
"  %^BOLD%^Large %^WHITE%^s%^BLACK%^t%^RESET%^o%^BOLD%^n%^BLACK%^e"
"%^WHITE%^s %^GREEN%^peek up from the grass in scattered places throughout the area, offering themselves as a place"
" to sit and relax.  While nothing here seems out of the ordinary, a %^RESET%^%^CYAN%^strange haze"
" %^BOLD%^%^GREEN%^hangs over the area like a dome, disappearing into the surrounding river.%^RESET%^");
} 
void reset() {
   ::reset();
   picked = random(2);
   picked1 = random(5);
}

void init(){
   ::init();
   add_action("pick", "pick");
   add_action("grab", "grab");
}
int pick(string str){
   if(!str) {
      tell_object(TP,"Pick what?");
      return 1;
   }
   if(str != "grapes" && str != "cluster") {
      write("You do not see that here.");
   return 1;
   }
   if(picked <= 0) {               
	tell_object(TP,"%^MAGENTA%^It appears all the grapes are gone.%^RESET%^");
   return 1;
   }
   else{
   tell_object(TP,"%^MAGENTA%^You reach up and pull down a cluster of grapes from the archway.%^RESET%^");
   tell_room(ETP,"%^MAGENTA%^"+TPQCN+" reaches up and pulls down a cluster of grapes from the archway%^RESET%^.",TP);
   new(OBJD+"cluster.c")->move(TP);
   picked --;
   return 1;
   }
}
int grab(string str){
   if(!str) {
      tell_object(TP,"Grab what?");
      return 1;
   }
   if(str != "flower" && str != "orchid") {
      write("You do not see that here.");
   return 1;
   }
   if(picked1 <= 0) {               
   tell_object(TP,"%^MAGENTA%^It appears all the orchids have been taken.%^RESET%^");
   return 1;
   }
   else{
   tell_object(TP,"%^MAGENTA%^You gently pick an orchid.%^RESET%^");
   tell_room(ETP,"%^MAGENTA%^"+TPQCN+" reaches down and picks an orchid%^RESET%^.",TP);
   new(OBJD+"orchid.c")->move(TP);
   picked1 --;
   return 1;
   }
}