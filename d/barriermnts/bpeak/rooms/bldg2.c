//bldg2
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit CROOM;
int searched;

void create(){
   set_monsters(({TMONDIR +"hillg5.c"}),({random(2)+2}));
   set_repop(40);
::create();
   set_property("indoors",1);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("%^RESET%^Inside the sleeping quarters");
   set_short("%^RESET%^The inside of a large stone building%^RESET%^");
   set_smell("default","The smell of dirt and sweat hangs heavily in the air.");
   set_long((:TO,"ldesc":));
   set_items(([
   "beds":"%^RESET%^%^ORANGE%^The beds are made out of piles of furs and leathers spread out on the hard stone floor.  Each bed is spaced about five feet from the next.%^RESET%^",
   ({"furs","leathers"}):"%^RESET%^%^ORANGE%^The furs and leathers that make up the beds are stinking and old.  Most of them are torn or otherwise in bad repair, but a few of the furs look to be a little newer and are in better condition.%^RESET%^",
   ({"brackets","torch brackets"}):"%^BOLD%^%^BLACK%^Torch brackets are set into the walls at ten foot intervals and the torches inserted in them provide the lighting for the room.%^RESET%^",
   "walls":"The walls here are made of carved stone.  They are not completely smooth, as the stone has been crudely cut.  The stones do however fit amazingly well together.",
  "windows":"The windows in the southern wall overlook the %^ORANGE%^path %^RESET%^below and provide an excellent view of the %^GREEN%^forest %^RESET%^that fills the %^GREEN%^valley %^RESET%^to the south.%^RESET%^", 
  "sacks":"%^RESET%^%^ORANGE%^There are a few sacks next to some of the beds.  Some of them look full and others look fairly empty.%^RESET%^",
 ]));
   set_exits((["northeast":INRMS+"tcliff13"]));
   set_search("bags",(:TO,"search_bags":));
   set_search("sacks",(:TO,"search_bags":));
}
string ldesc(string str){
   return("%^RESET%^This building looks as though it may be the sleeping quarters"
" for the giants that inhabit this cliff.  No cots are here, but %^ORANGE%^furs"
" %^RESET%^and %^ORANGE%^leathers %^RESET%^line the floor against the walls in what"
" looks like uncomfortable beds.  A few sacks lay on the cold stone floor near some"
" of the beds, while others have nothing by them at all.  There are"
" %^BOLD%^%^BLACK%^torch brackets %^RESET%^set into the walls at ten foot intervals,"
" each holding a torch for light.  The southern wall has a few windows carved out of"
" the stone.%^RESET%^\n");
} 
void reset(){
   ::reset();
   searched = 1;
   if(!present("hill giant")){
      new(TMONDIR+"hillg5.c")->move(TO);
  }
}
void search_bags(){
   if(searched <= 0) {               
	tell_object(TP,"You carefully search through all the sacks but they seem to be empty.");
      return;
   }
   if (searched == 1){  
      tell_object(TP,"%^RESET%^%^ORANGE%^You carefully search through the sacks and pull out a few items.%^RESET%^\n");
      tell_room(TO,"%^RESET%^%^ORANGE%^"+TPQCN+" picks up a few of the sacks and dumps the contents onto the floor.", TP);
      switch(random(5)){
         case 0:
            new(OBJD+"bpan.c")->move(TO);
            new(OBJD+"goldnugget.c")->move(TO);
            searched = 0;
         break;
         case 1:
            new(OBJD+"bpan.c")->move(TO);
            new(OBJD+"goldnugget.c")->move(TO);
            new(OBJD+"goldnugget.c")->move(TO);
            searched = 0;
         break;
         case 2:
            new(OBJD+"bpan.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            searched = 0;
         break;
         case 3:
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            new(OBJD+"goldnugget.c")->move(TO);
            searched = 0;
         break;
         case 4:
            new(OBJD+"bpan.c")->move(TO);
            new(OBJD+"goldnugget.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            new("/d/newbie/obj/misc/rock.c")->move(TO);
            searched = 0;
         break;
      }
   }
}



            

