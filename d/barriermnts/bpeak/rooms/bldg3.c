//bldg3
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
#include <daemons.h>
inherit CROOM;
int searched;
int searched2;
int searched3;
int ransacked;
int fire;
int burnt;
int lit;




void create(){
::create();
   set_property("indoors",2);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("%^RESET%^Galhyon's building");
   set_short("%^RESET%^The inside of a large stone building%^RESET%^");
   set_smell("default",(:TO,"smell":));
   set_long((:TO,"ldesc":));
   set_items(([
   "bed":(:TO,"bed_desc":),
   ({"furs","leathers"}):(:TO,"fdesc":),
   ({"brackets","torch brackets"}):"%^BOLD%^%^BLACK%^Torch brackets are set into the walls at ten foot intervals and the torches inserted in them provide the lighting for the room during the darkened hours.%^RESET%^",
   "walls":"The walls here are made of carved stone.  They are not completely smooth, as the stone has been crudely cut.  The stones do however fit amazingly well together.",
  "windows":"The windows in the southern wall overlook the %^ORANGE%^path %^RESET%^below and provide an excellent view of the %^GREEN%^forest %^RESET%^that fills the %^GREEN%^valley %^RESET%^to the south.%^RESET%^", 
  "sacks":(:TO,"sdesc":),
  "carvings":"%^RESET%^%^ORANGE%^Carved into the wood of the bed over and over again in child-like scrabble is the name %^YELLOW%^Galhyon.%^RESET%^",
   ({"chair","wooden chair"}):(:TO,"cdesc":),
   ({"table","wooden table"}):(:TO,"tdesc":),
   "skull":(:TO,"skull_desc":),
   "torches":(:TO,"torch_desc":),
 ]));
   set_search("leathers",(:TO,"search_leather":));
   set_search("leather",(:TO,"search_leather":));
   set_search("fur",(:TO,"search_fur":));
   set_search("furs",(:TO,"search_furs":));
   set_search("sacks",(:TO,"search_bags":));
   set_search("bags",(:TO,"search_bags":));
   set_search("bed",(:TO,"search_bed":));
   set_search("default","You could probably search each individual thing in this room, or if you are in a hurry, you can 'ransack the room'.");
   set_exits((["out":INRMS+"kgroom"]));
}
string smell(string str){
   if(fire ==1){
      return("%^BOLD%^%^BLACK%^You choke on all the smoke in the air!%^RESET%^");
   }
   if(burnt==1){
      return("%^BOLD%^%^BLACK%^Everything in here smells burnt.%^RESET%^");
   }
   return("%^RESET%^%^ORANGE%^The smell of dirt and sweat lingers in the air.%^RESET%^");
}
string ldesc(string str){
   if(ransacked <=0){
      return("%^RESET%^This building looks as though it may be the sleeping quarters"
" for whoever lives atop this cliff, and by the looks of it, that person is very"
" large.  %^BOLD%^%^BLACK%^Torch brackets %^RESET%^line the walls in ten foot"
" intervals, but are set ten feet high from the ground.  A bed sits near the"
" southern wall of the building, just beneath a series of windows carved into the"
" %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e."
"  %^RESET%^A few sacks hang from one of the %^BOLD%^%^BLACK%^brackets %^RESET%^and"
" a large, crudely made %^ORANGE%^wooden chair %^RESET%^sets in the corner by an"
" even larger %^ORANGE%^wooden table.%^RESET%^  A few %^ORANGE%^furs %^RESET%^are"
" thrown down by the foot of the bed and are covered with unmatching"
" %^BOLD%^%^BLACK%^dark fur.%^RESET%^\n");
   }
   if(ransacked ==1){
      if(fire ==1){
         return("%^BOLD%^%^RED%^Everything is on fire!  Large flames engulf the chair, table and bed!  %^BOLD%^%^BLACK%^Smoke and haze fills the room, making it difficult to see much else!%^RESET%^\n");
      }
      if(burnt==1){
         return("%^RESET%^This building looks as though it may be the sleeping"
" quarters for whoever lives atop this cliff, and by the looks of it, that person"
" is very large.  %^BOLD%^%^BLACK%^Torch brackets %^RESET%^line the walls in ten foot"
" intervals, but are set ten feet high from the ground.  A %^BOLD%^%^BLACK%^burnt bed"
" %^RESET%^sits near the southern wall of the building, just beneath a series of"
" windows carved into the %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n"
"%^BOLD%^%^BLACK%^e.  %^RESET%^A few piles of %^BOLD%^%^BLACK%^ash %^RESET%^and"
" %^BOLD%^%^BLACK%^charcoaled wood %^RESET%^lay in %^BOLD%^%^WHITE%^steaming"
" %^RESET%^piles on the floor.%^RESET%^\n");
    }
       return("%^RESET%^This place is a mess!  An overturned bed sits in the southern"
" corner of the room just below a string of windows that are carved into the"
" %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e"
" %^RESET%^and the %^ORANGE%^furs %^RESET%^and %^ORANGE%^leathers %^RESET%^that use"
" to line it are now all over the floor.  %^YELLOW%^Straw %^RESET%^is scattered all"
" over the floor and the %^ORANGE%^wooden chair %^RESET%^and %^ORANGE%^table"
" %^RESET%^that use to sit in the corner are now turned over as well.  A few empty"
" sacks are strewn across the room.%^RESET%^\n");
   }
} 
string skull_desc(string str){
   if(query_night()) {
      if(burnt==1){
         return("%^BOLD%^%^BLACK%^The %^RESET%^skull %^BOLD%^%^BLACK%^sits on the floor in the center of a pile of charcoal.%^RESET%^");
       }
      return("%^YELLOW%^The skulls eyes shine most brightly as the skull is illuminated by the lit wax candle inside.  The light pours forth from every crack in the skull, lighting the area around the table with an eerie glow.%^RESET%^");
   }
   return("This skull sits on top of the table and stares with unseeing eyes at the room around it.  A single wax candle stands beneath the skull and you realize that the skull acts as a sick form of a lampshade.");
} 
string torch_desc(string str){
   if(query_night()) {
      return("%^BOLD%^%^RED%^Fire burns brightly on the tips of the torches, the flames licking and dancing along, shedding their light upon the room while their shadows dance upon the stone walls.%^RESET%^");
   }
   return("The torches sit within the brackets unlit.  The light pouring through the windows is more than enough to illuminate the room during the daylight hours.");
} 
string bed_desc(string str){
   if(ransacked==1){
      if(fire==1) {
         return("%^BOLD%^%^RED%^The bed is on fire!%^RESET%^");
      }
      if(burnt==1){
         return("%^BOLD%^%^BLACK%^The bed sits on its side near the southern wall.  The wood is badly burnt and a few burnt pieces of straw and furs still cling to it%^RESET%^.");
     }
  return("The bed lays on its side in the corner.  %^YELLOW%^Straw %^RESET%^lays all over the floor around it, as well as %^ORANGE%^furs %^RESET%^and %^RESET%^leathers%^RESET%^.");
  }
  return("%^RESET%^%^ORANGE%^A very large bed sits over in the furthest corner of"
" the room.  It is made of large tree trunks twined together for sturdiness and is"
" covered with straw to add some softness.  Several stinking layers of dirty furs"
" and leathers cover the straw for comfort and warmth.  There are a few carvings"
" crudely carved into the wood of the bed.%^RESET%^");
} 
string fdesc(string str){
   if(ransacked==1){
      if(fire==1) {
         return("%^BOLD%^%^RED%^The furs are on fire!%^RESET%^");
      }
      if(burnt==1){
         return("%^BOLD%^%^BLACK%^What furs?  All that's left are a few burnt patches of something spread throughout the room%^RESET%^.");
     }
  return("%^RESET%^%^ORANGE%^The furs and leathers are scattered all over the floor!%^RESET%^");
  }
  return("%^RESET%^%^ORANGE%^The furs and leathers covering the bed"
" are stinking and old.  Most of them are torn or otherwise in bad repair, but a few"
" of the furs look to be a little newer and are in better condition.%^RESET%^");
} 
string sdesc(string str){
   if(fire==1) {
      return("%^BOLD%^%^RED%^The sacks are on fire!%^RESET%^");
   }
   if(burnt==1){
      return("%^BOLD%^%^BLACK%^What sacks?  All that's left are a few burnt patches of something spread throughout the room%^RESET%^.");
  }
  return("%^RESET%^%^ORANGE%^A few sacks hang off of one of the brackets by the bed.  They all look empty.%^RESET%^");
} 
string cdesc(string str){
   if(ransacked==1){
      if(fire==1) {
        return("%^BOLD%^%^RED%^The chair is on fire!%^RESET%^");
     }
      if(burnt==1){
         return("%^BOLD%^%^BLACK%^Oops.  What use to be the chair is now just a pile of burnt wood on the floor%^RESET%^.");
     }
  return("%^RESET%^%^ORANGE%^This wooden chair is fairly crudely made and apparently holds little worth as it is tossed to the corner and lays there on its side.%^RESET%^");
  }
  return("%^RESET%^%^ORANGE%^This wooden chair looks to be very"
" old and crudely made.  The wood is unfinished and looks like it was chopped"
" straight from the tree and then bound together to form this chair.  You can even"
" still see strips of bark stuck to the wood, and if you look closely enough you"
" can even still see small patches of moss on the bark.%^RESET%^");
} 
string tdesc(string str){
   if(fire==1) {
      return("%^BOLD%^%^RED%^The table is on fire!%^RESET%^");
   }
   if(burnt==1){
      return("%^BOLD%^%^BLACK%^Oops.  What use to be the table is now just a pile of burnt wood on the floor with a %^RESET%^skull %^BOLD%^%^BLACK%^sitting in the middle of it%^RESET%^.");
  }
  return("%^RESET%^%^ORANGE%^This wooden table is made much in the same fashion as the chair, crude and unfinished.  Setting on top of the table is a plate made of the bone from some poor creature and a skull.%^RESET%^");
} 
void search_leather(){
   if(searched <= 0) {               
	tell_object(TP,"%^RESET%^%^ORANGE%^You carefully search through all the leathers in the room only to find that none of them are useful.%^RESET%^");
      return 1;
   } 
   tell_object(TP,"%^RESET%^%^ORANGE%^You carefully dig through the leather and find some that is in useable condition!%^RESET%^");
   tell_room(ETP,"%^RESET%^%^ORANGE%^"+TPQCN+" digs through the leather and pulls out some that looks useable.%^RESET%^",TP);
   new(OBJD+"leather.c")->move(this_object());
   searched --;
   return 1;
}
void search_furs(){              
	tell_object(TP,"%^RESET%^%^ORANGE%^You carefully search through all the furs in the room only to find that none of them are useful.%^RESET%^");
}
void search_bags(){
   if(searched2 <= 0) {               
	tell_object(TP,"You carefully search through all the sacks but they seem to be empty.");
      return;
   }
   if (searched2 == 1){  
      tell_object(TP,"%^RESET%^%^ORANGE%^You carefully search through the sacks and pull out a few items.%^RESET%^\n");
      tell_room(TO,"%^RESET%^%^ORANGE%^"+TPQCN+" picks up a few of the sacks and dumps the contents onto the floor.", TP);
      switch(random(5)){
         case 0:
            new(OBJD+"bpan.c")->move(TO);
            new(OBJD+"goldnugget.c")->move(TO);
            searched2 = 0;
         break;
         case 1:
            new(OBJD+"bpan.c")->move(TO);
            new(OBJD+"goldnugget.c")->move(TO);
            new(OBJD+"goldnugget.c")->move(TO);
            searched2 = 0;
         break;
         case 2:
            new(OBJD+"bpan.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            searched2 = 0;
         break;
         case 3:
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            new(OBJD+"goldnugget.c")->move(TO);
            searched2 = 0;
         break;
         case 4:
            new(OBJD+"bpan.c")->move(TO);
            new(OBJD+"goldnugget.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            searched2 = 0;
         break;
      }
   }
}
void search_bed(object ob){
   if(searched3 <= 0) {               
	tell_object(TP,"%^RESET%^%^ORANGE%^You carefully sift through all of the straw in the bed only to find nothing.%^RESET%^");
      return 1;
   } 
   tell_object(TP,"%^RESET%^%^ORANGE%^You carefully sift through all of the straw in the bed and pull out a crumpled parchment!%^RESET%^");
   tell_room(ETP,"%^RESET%^%^ORANGE%^"+TPQCN+" digs through the straw in the bed and pulls out a crumpled piece of parchment.%^RESET%^",TP);
   ob = new("/d/magic/scroll");
   ob->set_spell(random(3)+4);
   ob->move(TO); 
   searched3 --;
   return 1;
}
void init(){
  ::init();
  add_action("ransack","ransack");
}
int ransack(string str){
   if(str == "room"||str=="the room"){
      if (ransacked ==1){
         tell_object(TP,"%^BOLD%^%^BLACK%^The room looks like it's already been ransacked.%^RESET%^");
      return 1;
      }
      if (ransacked <=1){     
         if(lit==1){
            switch (random(2)){
               case 0:
                  tell_object(TP,"%^RESET%^%^RED%^You dig wildly through the room without a care in the world, accidently knocking one of the lit torches out of the brackets, setting everything on fire!%^RESET%^");
                  tell_room(TO,"%^RESET%^%^RED%^"+TPQCN+" digs through everything in the room without paying attention to anything and accidentally knocks one of the lit torches over, setting everything in the room on fire!",TP);
                  searched = 0;
                  searched2 =0;
                  ransacked =1;
                  fire =1;
                  call_out("burning",1);
               break;
               case 1:
                  tell_object(TP,"%^RESET%^%^BLUE%^You dig wildly through the room without a care in the world, knocking things over in the process!%^RESET%^");
                  tell_room(TO,"%^RESET%^%^BLUE%^"+TPQCN+" digs through everything in the room without paying attention to anything!",TP);
                  new(OBJD+"leather.c")->move(TO);
                  new(OBJD+"bpan.c")->move(TO);
                  new(OBJD+"goldnugget.c")->move(TO);
                  new("/d/newbie/obj/misc/rock.c")->move(TO);
                  new("/d/newbie/obj/misc/rock.c")->move(TO);
                  new("/d/newbie/obj/misc/rock.c")->move(TO);
                  new("/d/newbie/obj/misc/rock.c")->move(TO);
                  searched3 = 0;
                  searched2 = 0;
                  searched =0;
                  ransacked =1;
               break;
               }
            }
         if(!lit==1){
            tell_object(TP,"%^RESET%^%^BLUE%^You dig wildly through the room without a care in the world, knocking things over in the process!%^RESET%^");
            tell_room(TO,"%^RESET%^%^BLUE%^"+TPQCN+" digs through everything in the room without paying attention to anything and knocks everything over!",TP);
            new(OBJD+"leather.c")->move(TO);
            new(OBJD+"bpan.c")->move(TO);
            new(OBJD+"goldnugget.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            searched2 = 0;
            searched =0;
            searched3 =0;
            ransacked =1;
         return 1; 
         }
      }      
   }
}
void burning(){
   object *livings,*inven;
   int i,j;     
   livings = ({});
   inven =filter_array(all_living(TO),"is_non_immortal_player",FILTERS_D);
   j= sizeof(inven);
   tell_room(TO,"%^BOLD%^%^RED%^The furs and wooden objects spark up into flames!%^RESET%^");
    for(i = 0;i < j;i++){
       if(living(inven[i])) livings += ({inven[i]});
    }      
    j = sizeof(livings);       
    for(i=0;i<j;i++){
      if((random(8)+12) > livings[i]->query_stats("dexterity")){
         tell_room(TO,"%^BOLD%^%^RED%^"+livings[i]->query_cap_name()+" is burnt by the flames!",livings[i]);
         tell_object(livings[i],"You get burnt by the flames!");
         livings[i]->do_damage("torso",roll_dice(2,10));             
      }
   }
   call_out("is_burnt",10);
}
void is_burnt(){
   tell_room(TO,"%^RESET%^%^RED%^The fires in the room slowly die away, leaving nothing but a charcoaled mess!%^RESET%^");
   fire =0;
   burnt =1;
}
void reset() {
   ::reset();
   searched = 1;
   searched2 = 1;
   ransacked = 0;
   fire = 0;
  burnt = 0;
   if(searched3==0){
      switch(random(5)){
         case 0..1:
          searched3 = 1;
         break;
         case 2..4:
          searched3 = 0;
         break;
      return;
      }
   }
   if(query_night()) {
      lit = 1;
   }
   if(!query_night()){
      lit=0;
   }
}

