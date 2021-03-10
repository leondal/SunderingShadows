//cave_inherit - basic inherit for low level caverns
//Circe 3/13/05
#include <std.h>
#include "ekibi.h"

inherit CROOM;

int item;
void pick_critters();

void create(){
   pick_critters();
   ::create();
   set_repop(35);
   set_property("light",0);
   set_terrain(NAT_TUNNEL);
   set_travel(FOOT_PATH);
   set_indoors(1);
   set_name("Ekibi Caverns");
   set_short("%^RESET%^%^MAGENTA%^Ekibi Caverns%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^You are in the Ekibi Caverns%^RESET%^\n"+
      "Dank walls of %^BOLD%^limestone %^RESET%^seem to have been "+
      "carved naturally and perhaps widened by hand.  Steady "+
      "%^CYAN%^rivulets %^RESET%^run down the curving walls to "+
      "the floor, forming small %^CYAN%^puddles %^RESET%^in "+
      "lower lying places.  The cavern seems free from dust, "+
      "but small piles of %^BOLD%^rock %^RESET%^and other "+
      "%^ORANGE%^debris %^RESET%^litter the base of the walls.  "+
      "The floor is somewhat slick, moistened by the dampness "+
      "in the air.\n");
   set_listen("default","The sound of lapping water is masked "+
      "by the chirping of crickets.");
   set_smell("default","The musty fragrance of the cave reaches "+
      "your nose.");
   set_search("default","You notice some of the debris might be "+
      "hiding something.");
   set_search("pile",(:TO,"search_pile":));
   set_search("rock",(:TO,"search_pile":));
   set_search("debris",(:TO,"search_pile":));
   set_items(([
      ({"wall","walls","limestone"}) : "%^BOLD%^The walls are "+
         "carved from damp limestone, which feels soft to the "+
         "touch.  They are far from perfect, seeming to have been "+
         "carved by water rather than by hand.  The walls curve, "+
         "narrowing toward the ceiling.",
      ({"rivulet","rivulets","water"}) : "%^CYAN%^Tiny rivulets "+
         "run down the wall, moistening the limestone and "+
         "causing small creases and crevices.",
      ({"puddle","puddles"}) : "In low-lying places throughout "+
         "the cavern, small puddles can be seen.  They do not "+
         "seem deep enough to drink from without getting a "+
         "mouthful of limestone.",
      ({"piles","pile","rock","debris"}) : "The piles look to "+
         "be mostly rock, though you see bits and pieces of "+
         "insect remains."
   ]));
   item = 1;
}

void reset(){
/*
This has been taken out to let the repop rate handle it
   int active;
   active = has_mobs();
   if(!active){
     if(mons)  mons = ([]);
     pick_critters();
   }
*/
   ::reset();
   if(random(3)) item = 1;
}

void pick_critters(){
   switch(random(20)){
      case 0..6:  break;
      case 7..11:  set_monsters( ({MON"giant_cockroach"}),({1}));
                  break;
      case 12..14:  set_monsters( ({MON"stag_beetle"}),({1}));
                  break;
      case 15:  set_monsters( ({MON"stag_beetle"}),({2}));
                  break;
      case 16..19:  set_monsters( ({MON"cave_cricket"}),({1}));
                  break;
      default:  break;
   }
}

void search_pile(){
   if(present("insect")){
      tell_object(TP,"The insect seems to be in the way.");
      return;
   }
   if(!item){
      tell_object(TP,"It looks as though that's been searched recently.");
      tell_room(ETP,""+TPQCN+" searches the pile but doesn't "+
         "seem to find anything.",TP);
      return;
   }
   if(!random(2)){
      tell_object(TP,"You search through the pile and find something "+
         "hidden!");
      tell_room(ETP,""+TPQCN+" searches the pile and finds something!",TP);
      item = 0;
      "/d/common/daemon/randtreasure_d"->find_stuff(TO,"random");
      return;
   }
   tell_object(TP,"You search the pile but find nothing of "+
      "interest.");
   tell_room(ETP,""+TPQCN+" searches the pile but doesn't "+
      "seem to find anything.",TP);
   item = 0;
   return;
}