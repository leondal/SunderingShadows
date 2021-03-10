//bpath2
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit PIER;
int to_find;
int max;
int tries;
int get_tries(){ return tries;}

void create(){
::create();
   set_property("light",2);
   set_travel(RUTTED_TRACK);
   set_terrain(LIGHT_FOREST);
   set_water_body("river");
   set_name("%^RESET%^%^GREEN%^In the forest%^RESET%^");
   set_short("%^RESET%^%^GREEN%^In the forest%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^RESET%^%^GREEN%^The fresh scent of pine drifts along the breeze.%^RESET%^");
   set_listen("default","%^BOLD%^The song of birds fills the air%^RESET%^.");
   set_items(([
   "cliff":"The cliff rises to about five hundred feet above you.  It is completely sheer with the exception of a ledge where the bridge is and another ledge above that.  Its shadow falls over this part of the forest.",
   "pool":"%^BOLD%^%^BLUE%^A deep pool of water is north of here.  The water from the fall constantly pummels into it, splashing everything in the area.%^RESET%^",
   "river":"%^RESET%^%^CYAN%^The river has just come from the pool created by the waterfall.  It slows down greatly here and gently tumbles over the rocks it drags along.  It is said that places like these are great for panning for gold.%^RESET%^",
   "forest":"%^RESET%^%^GREEN%^This forest is composed of large pine trees.%^RESET%^",
   ({"pine cones","cones"}):"%^RESET%^%^ORANGE%^Pine cones of various sizes litter the forest floor.%^RESET%^",
   ]));
   set_search("default", "%^ORANGE%^Nothing here really looks interesting.%^RESET%^");
   set_exits((["northeast":INRMS+"bpath3",
   /*"northwest":"/d/barriermnts/bforest/rooms/fpath5",
   "west":"/d/barriermnts/bforest/rooms/frpath1"*/]));
   set_max_fishing(4);
   set_chance(17);
   set_max_catch(6);
   set_fish( ([ "Issaquah Trout": 10, "Big Kahuna": 5 ]) );
}
string ldesc(string str){
   return("%^RESET%^%^GREEN%^This is a very peaceful area.  Nestled in a deep"
" ravine, large pine trees reach towards the sky and a %^BOLD%^%^BLUE%^river"
" %^RESET%^%^GREEN%^slowly snakes its way through the trees.  Huge"
" %^BLUE%^mountains %^GREEN%^surround the forest in all directions, but the cliff"
" to the north is the only thing that directly casts a %^BOLD%^%^BLACK%^shadow"
" %^RESET%^%^GREEN%^over the immediate area.  %^ORANGE%^Pine cones %^GREEN%^litter"
" the ground along with pine needles and a few leaves from the low growing"
" vegetation.  Birds sing above you and the occassion forest animal can be seen"
" moving through nearby paths.  To the north the forest clears out at the base of"
" the cliff and a %^BOLD%^%^BLUE%^pool %^RESET%^%^GREEN%^of %^BOLD%^%^BLUE%^deep"
" water %^RESET%^%^GREEN%^fed by a pounding %^BOLD%^%^CYAN%^waterfall"
" %^RESET%^%^GREEN%^can be seen.%^RESET%^\n");
}
void reset(){
   ::reset();
   if(!random(3))
      to_find = random(3);
   else
      to_find = 0;
   if(!max) max = 3;
   tries = (random(8));
}

int is_goldriver(){return 1;}

int query_to_find(){return to_find;}

void set_found(int num){
   if(num <=0) return;
   if(num > to_find) num = to_find;
   to_find -= num;
}

object get_found_ob(){
   if(tries ==0){
      switch(random(100)){
         case 0..98:
            tries+=1;
            return new(OBJD+"goldnugget.c");
         break;
         case 99:
            tries+=1;
            return new("/d/newbie/obj/misc/rock.c");
      break;
      }
   }
   if(tries ==1){
      switch(random(20)){
         case 0..18:
            tries+=1;
            return new(OBJD+"goldnugget.c");
         break;
         case 19:
            tries+=1;
            return new("/d/newbie/obj/misc/rock.c");
      break;
      }
   }
   if(tries ==2){
      switch(random(20)){
         case 0..15:
            tries+=1;
            return new(OBJD+"goldnugget.c");
         break;
         case 16..19:
            tries+=1;
            return new("/d/newbie/obj/misc/rock.c");
      break;
      }
   }
   if(tries ==3){
      switch(random(20)){
         case 0..11:
            tries+=1;
            return new(OBJD+"goldnugget.c");
         break;
         case 12..19:
            tries+=1;
            return new("/d/newbie/obj/misc/rock.c");
      break;
      }
   }
   if(tries ==4){
      switch(random(20)){
         case 0..10:
            tries+=1;
            return new(OBJD+"goldnugget.c");
         break;
         case 11..19:
            tries+=1;
            return new("/d/newbie/obj/misc/rock.c");
      break;
      }
   }
   if(tries ==5){
      switch(random(10)){
         case 0..2:
            tries+=1;
            return new(OBJD+"goldnugget.c");
         break;
         case 3..9:
            tries+=1;
            return new("/d/newbie/obj/misc/rock.c");
      break;
      }
   }
   if(tries ==6){
      switch(random(10)){
         case 0..1:
            tries+=1;
            return new(OBJD+"goldnugget.c");
         break;
         case 2..9:
            tries+=1;
            return new("/d/newbie/obj/misc/rock.c");
      break;
      }
   }
   if(tries ==7){
      switch(random(10)){
         case 0:
            tries+=1;
            return new(OBJD+"goldnugget.c");
         break;
         case 1..9:
            tries+=1;
            return new("/d/newbie/obj/misc/rock.c");
      break;
      }
   }
   if(tries ==8){
      switch(random(10)){
         case 0..1:
            tries+=1;
            return new(OBJD+"goldnugget.c");
         break;
         case 2..99:
            tries+=1;
            return new("/d/newbie/obj/misc/rock.c");
      break;
      }
   }
   if(tries >8){
      switch(random(100)){
         case 0:
            tries+=1;
            return new(OBJD+"goldnugget.c");
         break;
         case 1..99:
            tries+=1;
            return new("/d/newbie/obj/misc/rock.c");
      break;
      }
   }
}


