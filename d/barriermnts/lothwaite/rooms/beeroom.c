//beeroom.c - For Lothwaite, the firbolg village.  Circe 1/11/04
#include <std.h>
#include "../lothwaite.h"
inherit ROOM;
int dead_bees;
int item;

void create() {
   ::create();
   set_property("indoors",0); 
   set_property("light",2);
   set_terrain(OLD_MOUNTS);
   set_travel(RUTTED_TRACK);
   set_name("A small rise"); 
   set_short("A small rise");
   set_long( (: TO, "ldesc" :) );
   set_items(([
      ({"tree","lone tree"}) : "The tall tree in the center of this small "+
         "clearing stands tall over the floor of the rise.  In some of the "+
         "lower branches, %^YELLOW%^b%^BLACK%^e%^YELLOW%^e%^BLACK%^s %^RESET%^"+
         "have built a sizeable %^ORANGE%^hive%^RESET%^.",
      ({"nest","hive","beehive"}) : "The sprialling hive is a brilliant "+
         "yellow-orange and looks almost sticky.  It seems almost dripping "+
         "with honey!",
      ({"bees","swarm"}) : "Dozens of tiny %^YELLOW%^yellow %^RESET%^and "+
         "%^BOLD%^%^BLACK%^black %^RESET%^%^YELLOW%^b%^BLACK%^e"+
         "%^YELLOW%^e%^BLACK%^s %^RESET%^buzz protectively around the "+
         "%^ORANGE%^hive%^RESET%^.  They fill the air here, dancing about "+
         "on the wind over your head.",
      ({"trees","forest","vines","vine"}) : "Twisting vines are thick along the "+
         "ground of the forest, though they have left this circle clear.  They "+
         "climb the tall evergreens as well, leaving only the lone tree in the "+
         "center bare.",
      ({"rise","ground","land","rocky land"}) : "The rocky mountainside rises "+
         "here to form this small clearing.  The path below forms a rocky trough "+
         "carved through the mountainside."
   ]));
   set_exits(([
      "south" : PATHEXIT"pathway7"
   ]));
   set_property("treestride_possible",1);
   set_smell("default","The sweet scent of honey is fresh on the breeze.");
   set_listen("default","The incessant buzzing of %^YELLOW%^b%^BLACK%^e%^YELLOW%^e"+
      "%^BLACK%^s %^RESET%^%^GREEN%^fills the air.");
   set_search("default","The beehive seems most intriguing.");
   set_search("hive",(:TO,"search_hive":));
   set_search("beehive",(:TO,"search_hive":));
   dead_bees = 0;
   item = 0;
}

string ldesc(){
      return("This clear patch of %^ORANGE%^rocky %^RESET%^land is "+
         "on a rise, making it a good bit higher than the %^ORANGE%^trail "+
         "%^RESET%^below.  %^GREEN%^Vines %^RESET%^encircle the entire area, "+
         "effectively blocking your way in every direction but back down to "+
         "the %^ORANGE%^trail%^RESET%^.  Strangely, the %^GREEN%^trees %^RESET%^"+
         "here form a %^BOLD%^%^BLACK%^ring %^RESET%^around one %^BLUE%^lone "+
         "tree %^RESET%^in the center.  Dozens of %^YELLOW%^b%^BLACK%^e"+
         "%^YELLOW%^e%^BLACK%^s %^RESET%^buzz around the tree with their "+
         "activity focused on a large %^ORANGE%^hive%^RESET%^.\n");
}

int search_hive(string str){
   if(str != "hive" && str != "beehive"){
      return 0;
   }
   if(!dead_bees){
      tell_object(TP,"%^BOLD%^%^MAGENTA%^As you search the hive, countless buzzing "+
         "%^YELLOW%^bees %^MAGENTA%^swarm out and attack!");
      tell_room(TO,"%^BOLD%^%^MAGENTA%^"+TPQCN+" stirs up the hive, causing "+
         "countless %^YELLOW%^bees %^MAGENTA%^to attack!",TP);
      call_out("bee_swarm", 1, TP);
      dead_bees = 1;
      return 1;
   }
   if(!item){
      if(present("bee")){
         tell_object(TP,"You can't get to the hive with the bees swarming around it!");
         return 1;
      }
      tell_object(TP,"%^YELLOW%^You reach into the sticky hive and pull out something "+
         "dripping in honey.");
      tell_room(ETP,"%^YELLOW%^"+TPQCN+" reaches into the sticky hive and pulls out "+
         "something.",TP);
      switch(random(4)){
         case 0..2:  new(OBJ"honeycomb")->move(TP);
                  break;
         case 3:  new(OBJ"honeycomb")->move(TP); 
                  new(OBJ"honeycomb")->move(TP);
                  break;
      }
      item = 1;
      return 1;
   }
   tell_object(TP,"The hive looks smashed as if someone has recently destroyed it.");
   tell_room(TO,""+TPQCN+"'s hands get sticky as "+TP->QS+" searches the hive.",TP);
   return 1;
}

void bee_swarm(){
   int num,i;
   tell_room(TO,"%^YELLOW%^Bees spew out from the hive!");
   num = random(6)+10;
   for(i=0;i<num;i++){
      new(MON"giantbee")->move(TO);
      continue;
   }
   return;
}

void reset(){
   ::reset();
   if(!random(3)){
      dead_bees = 0;
   }
   if(!random(4)){
      item = 0;
   }
}