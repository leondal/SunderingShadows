//tcliff13
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit CROOM;
int safe;
int taken;
int searched;
int dumped;
int flames;
int searched2;
int searched3;

void create(){
   set_monsters(({TMONDIR +"hillg4.c"}),({2}));
   set_repop(40);
::create();
   set_property("light",2);
   set_travel(FOOT_PATH);
   set_terrain(ROCKY);
   set_name("%^RESET%^Entrance of the buildings");
   set_short("%^RESET%^In the courtyard of two stone buildings%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^BOLD%^%^BLACK%^The smell of sweat, poorly kept animals and dirt mixes with the smell of cooking meats.%^RESET%^");
   set_listen("default","%^RESET%^%^ORANGE%^Besides the noise of the wind, the occassional grunt, shout or howl echoes from somewhere around here.%^RESET%^");
   set_items(([
   "mountains":"%^RESET%^%^BLUE%^The peaks of the mountain range hover around you in all directions, including the one that this cliff rests on.  Two stone buildings are built right up against the base of the mountain.%^RESET%^",
   "buildings":"Two stone buildings stand here.  One directly to the west, and the"
" other on the very far edge of the cliff to the southwest.  Each building is over"
" twenty feet tall and is composed of giant slabs of pure granite that have been"
" stacked atop one another.  There are no doors on the buildings, just ten foot"
" wide openings.  The stone itself has been crudely cut, but fit together amazingly"
" well to create fairly sturdy structures.  Standing on either side of each entrance"
" is a stone statue.",
   "statues":"%^BOLD%^%^BLACK%^Unlike the stones that create the buildings, these stone statues are carved with amazing detail out of pure onyx and look as though they are not made by the same makers as the rest of the structures here.  There are four statues in total.",
   "statue 1":"%^BOLD%^%^BLACK%^This ebony statue is the first in a series of four"
" here and sits on the right side of the western buildings entrance.  Carved in"
" amazing detail, the life like image of a wolf stares at you from unseeing eyes."
"  So well has this creation been formed that each hair on its body has been"
" individually carved, each muscle ripples from its body and its position is one"
" that is clearly ready to pounce.%^RESET%^",
   "statue 2":"%^BOLD%^%^BLACK%^This ebony statue is the second in a series of"
" four here and sits on the left side of the western buildings entrance.  Carved"
" in amazing detail, it mirrors the image of the statue to its right.  Each muscle"
" in its body ripples in life like detail and it is clearly ready for battle."
"%^RESET%^",
   "statue 3":"%^BOLD%^%^BLACK%^This statue sits on the right side of the entrance"
" of the southwestern building.  Unlike the two to her right, this creature is"
" carved in the image of a beautiful dark female human.  Silken strands of ebony hair"
" reach past her lithe waistline and dark eyes peer out from her closed but"
" translucent eyelids.  This statue gives you a very uneasy feeling and you wish"
" you hadn't laid eyes on her, but now it is nearly impossible to take them off."
"  She wears very little armor and is covered in only a light material that is"
" perhaps even more sheer than the finest of light silks.  No matter which way you"
" move, the eyes always seem to be watching you, and you cannot help but wonder how"
" such a statue ended up in a place like this.%^RESET%^",
   "statue 4":"%^BOLD%^%^BLACK%^Carved in the same fashion as the other three, this"
" statue west of the southwestern buildings entrance is also in the image of a wolf"
" ready to pounce.  Like the two that sit on either side of the entrance to the"
" western building, this wolf is exquisitely crafted and amazingly life like.  Every"
" inch of its muscular body looks real, and the black onyx shines eerily both by"
" daylight and by the light of the moon.  Curiously, a pendant carved in the image"
" of a spider hangs low around this wolfs neck.%^RESET%^",
   ({"pit","firepit"}):(:TO,"pit_desc":),
   ({"oven","brick oven"}):"%^RESET%^%^RED%^This is a dark red brick oven made of stacked bricks.  A large rock sits over the top, probably to keep the heat in so that the food can cook properly.%^RESET%^",
   "smoke":"%^BOLD%^%^BLACK%^Smoke billows up from the fire pit.%^RESET%^",
   ({"fire","flames"}):(:TO,"flames_desc":),
   ({"bucket","bucket of water","water"}):(:TO,"bucket_desc":),
    "crack":(:TO,"crack_desc":),
   ]));
   set_search("default", "%^ORANGE%^Large footprints can be seen on the ground going in many directions, but it looks like most are heading east.%^RESET%^");
   set_search("firepit",(:TO,"search_pile":));
   set_search("oven",(:TO,"search_oven":));
   set_search("fire",(:TO,"search_pile":));
   set_search("pit",(:TO,"search_pile":));
   set_search("statue 3",(:TO,"search_statue":));
   set_search("crack",(:TO,"search_crack":));
   set_search("statue 4",(:TO,"search_statue4":));
   set_exits((["southwest":INRMS+"bldg2","west":INRMS+"bldg1","east":INRMS+"tcliff1"]));
   safe=0;
}
string ldesc(string str){
   return("%^RESET%^Tall %^BLUE%^mountains %^RESET%^create the background for this"
" area and hover over the two %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^"
"o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^buildings that are built against the base"
" of one.  The buildings are composed of giant slabs of %^BOLD%^%^BLACK%^g"
"%^RESET%^r%^BOLD%^%^WHITE%^a%^BLACK%^n%^RESET%^i%^BOLD%^%^WHITE%^t%^BLACK%^e"
" %^RESET%^stacked atop one another and are about twenty feet in height.  There are"
" no doors on the buildings, just ten foot wide openings that reach from the ground"
" all the way to the %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^WHITE%^o%^BLACK%^n"
"%^RESET%^e%^BOLD%^%^BLACK%^s %^RESET%^that create the roofs.  There are no plants"
" here, just %^ORANGE%^d%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^rt, %^BOLD%^%^BLACK%^r"
"%^BOLD%^%^WHITE%^o%^RESET%^c%^BOLD%^%^BLACK%^k, %^RESET%^and more %^ORANGE%^d"
"%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^rt.  %^RESET%^A large %^RED%^fire"
" %^BOLD%^%^BLACK%^pit %^RESET%^sits in the middle of the area, constantly emitting"
" a %^BOLD%^%^BLACK%^thick black %^BOLD%^%^WHITE%^c%^RESET%^l%^BOLD%^%^BLACK%^o"
"%^RESET%^u%^BOLD%^%^BLACK%^d %^RESET%^of %^BOLD%^%^BLACK%^smoke %^RESET%^that"
" %^BOLD%^%^WHITE%^billows %^RESET%^up towards the sky.  In the center of the"
" %^BOLD%^%^BLACK%^pit %^RESET%^is a crude %^RED%^brick oven %^RESET%^that is"
" probably used to cook some sort of food.  Setting beside the %^BOLD%^%^BLACK%^pit"
" %^RESET%^is a simple %^ORANGE%^clay bucket."
"%^RESET%^\n");
}
string flames_desc(string str){
   if(flames <= 0) {
      return("%^BOLD%^%^BLACK%^The fire looks to have been extinguished.%^RESET%^");
   }
   return("%^BOLD%^%^RED%^Large flames lick around the brick oven in the center of the pit, making it impossible to reach it without getting burnt.");
} 
string pit_desc(string str){
   if(flames <= 0) {
      return("%^BOLD%^%^BLACK%^The fire pit here is quite large, maybe about six feet in diameter.  Large rocks mark the edges of the pit and circle the smoldering wood inside.  A brick oven is placed in the middle of the pit and looks like it is used to cook the food.%^RESET%^");
   }
   return("%^BOLD%^%^RED%^The fire pit here is quite large, maybe about six feet in diameter.  Large rocks mark the edges of the pit and keep the fire contained.  A brick oven is placed in the middle of the pit and looks like it is used to cook the food.%^RESET%^");
}  
string bucket_desc(string str){
   if(dumped <= 0) {
      return("%^RESET%^This is an empty clay bucket.%^RESET%^");
   }
   return("%^RESET%^%^CYAN%^This is a simple clay bucket filled with water, perhaps you can %^RESET%^dump the water over the fire %^CYAN%^to put it out?.%^RESET%^");
}
string crack_desc(string str){
   if(searched2 == 1) {
      return("%^BOLD%^%^BLACK%^You do not notice that here.%^RESET%^");
   }
   return("%^BOLD%^%^BLACK%^A small crack marks the onyx.  It looks as though something may be stuffed inside of it%^RESET%^.");
}                               
void search_pile(){  
   if(safe){
      if(searched <= 0) {               
	   tell_object(TP,"There doesn't seem to be much of interest in there this time.");
      return ;
      }
      if (searched == 1) {  
         tell_object(TP,"%^MAGENTA%^As you dig around the fire pit, your hands connect with something solid.  You pull it out and set it on the ground.%^RESET%^");
         tell_room(ETP,"%^MAGENTA%^"+TPQCN+" digs around the fire pit and pulls something out.",TP);
            new(OBJD+"dwarfsword.c")->move(TO);
      searched = 0;
      return 1;
      } 
   }            
   tell_object(TP,"%^RED%^You reach into the firepit and dig your hands around... OUCH!%^RESET%^");
   tell_room(ETP,""+TPQCN+" screams in pain as "+TP->query_subjective()+" digs around in the fire.%^RESET%^",TP);
   TP->do_damage("torso",random(40)+10);
   return 1;
}
void search_oven(){
   if(taken <= 0) {               
	tell_object(TP,"%^BOLD%^%^BLACK%^You carefully remove the stone covering the oven only to find it empty.%^RESET%^");
      return 1;
   } 
   tell_object(TP,"%^RED%^You carefully remove the stone covering the oven and pull out some freshly cooked fish!%^RESET%^");
   tell_room(ETP,""+TPQCN+" carefully removes the stone covering the oven and pulls out some freshly cooked fish.%^RESET%^",TP);
   new(OBJD+"smokedfish.c")->move(this_object());
   taken --;
   return 1;
}
void search_statue(){
   tell_object(TP,"%^BOLD%^%^BLACK%^You carefully run your hands over the statue, studying every inch of it as you go along.  Reaching down by her feet, you notice a small crack in the onyx there.%^RESET%^");
   tell_room(ETP,"%^BOLD%^%^BLACK%^"+TPQCN+" kneels down and carefully runs "+TP->query_possessive()+" hands over the statue.%^RESET%^",TP);
   searched2 = 0;
   return 1;
}
void search_crack(){
   if(searched2 == 1) {               
	tell_object(TP,"%^BOLD%^%^BLACK%^You do not notice any crack.%^RESET%^");
      return 1;
   } 
   tell_object(TP,"%^RESET%^%^BLUE%^You search through the crack and carefully remove the parchment that has been stuck inside.  Before your very eyes the crack seals itself over and disappears from view!%^RESET%^");
   tell_room(ETP,""+TPQCN+" digs around by the statues foot.%^RESET%^",TP);
   new(OBJD+"parchment2.c")->move(this_object());
   searched2 = 1;
   return 1;
}
void search_statue4(){
   if(searched3 <= 0) {               
	tell_object(TP,"%^BOLD%^%^BLACK%^You carefully run your hands over the statue but find nothing.%^RESET%^");
      return 1;
   } 
   tell_object(TP,"%^BOLD%^%^BLACK%^You run your hands over the statue and remove the spider pendant from its neck.%^RESET%^");
   tell_room(ETP,"%^BOLD%^%^BLACK%^"+TPQCN+" carefully removes the spider pendant from the statue.%^RESET%^",TP);
   new(OBJD+"spidernecklace.c")->move(TO);
   searched3 = 0;
   return 1;
}
void init(){
  ::init();
  add_action("dump","dump");
}
int dump(string str){
   if(!str) {
      if(dumped <= 0) {               
	   tell_object(TP,"%^RESET%^%^ORANGE%^You reach down and grab the clay pot only to find that all the water is gone.%^RESET%^");
         tell_room(ETP,"%^RESET%^%^ORANGE%^"+TPQCN+" reaches down and grabs the clay pot and turns it over but nothing comes out!%^RESET%^",TP);
      return 1;
      } 
      tell_object(TP,"%^BOLD%^%^BLUE%^You idiot, you just fumbled the pot and dumped the water all over the ground.");
      tell_room(ETP,"%^BOLD%^%^BLUE%^In true idiotic fashion, "+TPQCN+" fumbles the pot and dumps the water all over the ground.%^RESET%^",TP);
      dumped = 0;
      return 1;
   }
   if(str == "water over fire"||str=="the water over the fire"||str=="water on fire"||str=="water"){
      if(dumped <= 0) {               
	   tell_object(TP,"%^RESET%^%^ORANGE%^You reach down and grab the clay pot only to find that all the water is gone.%^RESET%^");
         tell_room(ETP,"%^RESET%^%^ORANGE%^"+TPQCN+" reaches down and grabs the clay pot and turns it over the fire but nothing comes out!%^RESET%^",TP);
      return 1;
      } 
      tell_object(TP,"%^RESET%^%^CYAN%^You reach down and grab the clay pot.  Holding it very carefully, you dump the water over the fire and put out the flames.%^RESET%^");
      tell_room(ETP,"%^RESET%^%^CYAN%^"+TPQCN+" takes the clay pot and dumps the water over the fire, putting out the flames%^RESET%^.",TP);
      safe=1;
      flames = 0;
      dumped = 0;
   return 1;
   }
     tell_object(TP,"%^BOLD%^%^BLUE%^You idiot, you just fumbled the pot and dumped the water all over the ground.");
      tell_room(ETP,"%^BOLD%^%^BLUE%^In true idiotic fashion, "+TPQCN+" fumbles the pot and dumps the water all over the ground.%^RESET%^",TP);
     dumped = 0;
  return 1;
}
void reset() {
  ::reset();
  if (safe) safe=0;
  taken = random(3);
  searched = 1;
  dumped = 1;
  flames = 1;
  searched2 = 1;
  searched3 =1;
}




