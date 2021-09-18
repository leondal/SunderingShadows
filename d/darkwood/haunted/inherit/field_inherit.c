#include <std.h>
#include <daemons.h>
#include "../haunted.h"

inherit CVAULT;

void post;
void do_post;

void create(){
/*   switch(random(10)) {
      case 0: break;
      case 1: set_monsters( ({MON"peryton"}),({1+random(2)}));
              break;
      case 2: set_monsters( ({MON"peryfem"}),({random(3)+1}));
              break;
      case 3: set_monsters( ({MON"peryton",MON"peryfem"}),({random(2),1+random(2)}));
              break;
      case 4..5: set_monsters( ({MON"peryton"}),({1}));
              break;
      default:  break;
   }
*/
   ::create();
   set_indoors(0);
   set_property("light",2);
   set_terrain(MEADOWLANDS);
   set_travel(FOOT_PATH);
//   set_repop(35);
   set_name("An overgrown field");
   set_short("%^BOLD%^%^GREEN%^An overgrown field%^RESET%^");
   set_long("%^RESET%^%^GREEN%^This sprawling %^BOLD%^field"
      "%^RESET%^%^GREEN%^ is bounded by a rickety %^ORANGE%^"
      "wooden rail fence %^GREEN%^that has clearly seen better "
      "days.  Any sign of a plow has long since vanished beneath "
      "the wildly growing %^ORANGE%^sickly grass%^GREEN%^ that "
      "reaches taller than a halfling in some places.  The grass "
      "moves constantly, alternately swaying with the %^CYAN%^"
      "breeze%^GREEN%^ and parting with a purpose, as if in the "
      "wake of some unseen creature.  Driven into the ground at random intervals "
      "are %^RESET%^posts %^GREEN%^of the sort used to support "
      "%^ORANGE%^scarecrows%^GREEN%^.%^RESET%^\n");
   set("night long","%^BOLD%^%^BLACK%^The mountains rising to "
      "the north and west block out the stars, casting eerie "
      "%^RESET%^shadows %^BOLD%^%^BLACK%^over the sprawling field.  "
      "%^RESET%^%^ORANGE%^Posts %^BOLD%^%^BLACK%^stand at random "
      "intervals, slender shapes even darker than the night sky.  "
      "The %^RESET%^grasses %^BOLD%^%^BLACK%^move and shake, though "
      "it is impossible to tell if it's the wind - or something more "
      "%^RESET%^%^RED%^sinister%^BOLD%^%^BLACK%^.%^RESET%^\n");
   set_smell("default","%^RESET%^%^ORANGE%^The crisp %^CYAN%^mountain air "
      "%^ORANGE%^is tinged with a hint of %^BOLD%^%^BLACK%^de%^GREEN%^c"
      "%^BLACK%^ay%^RESET%^%^ORANGE%^.%^RESET%^");
   set_listen("default","You hear the rustling of the grass and the scurrying of something small.");
   set_items(([
      ({"post","posts","scarecrow post"}) : "Standing at random intervals "
         "throughout the field are weathered wooden posts.  Each has a "
         "rusty nail and is wrapped with bits of twine as if it once "
         "held a scarecrow... but where have all the scarecrows gone?",
      ({"mountain","mountains"}) : "Rising to the north and west are "
         "the craggy peaks of the mountains surrounding Tabor.  The "
         "peaks are lined with evergreens and topped with snow, hinting "
         "at their height.",
      ({"fence","wooden fence","rail fence"}) : "Surrounding the field "
         "is an old rail fence crafted from weathered wood.  In places, "
         "rails have fallen away, though the posts still stand as a "
         "testament to the once-productive nature of this field.",
      "plow" : "No sign of a plow remains, not even the rutted furrows "
         "that would indicate one had worked this field.",
      ({"grass","sickly grass","wheat","grain"}) : "Wheat and other "
         "grains are mixed among the tall grasses of the field that have "
         "been left to grow uncontrolled.  The grass is thick and tangled, "
         "making travel a little difficult.  Most of the grass is brown "
         "and blighted, clearly falling prey to bugs and fungus - or "
         "perhaps something more sinister."
   ]));
}

void post() {
   int i;
   string *exits, *num;
   if(query_night()) return 1;
   exits = ({}) + TO->query_exits();
   num = ({});
   for(i = 0;i < sizeof(exits);i++) {
      if(num == ({})) {
         num = ({"GoThroughDoor"});
         continue;
      }
         num += ({"GoThroughDoor"});
   }
   if(sizeof(exits) > 0) {
      set_pre_exit_functions(exits,num);
   }       
}

int do_post(){
   int perc;
   if(!objectp(TP)) return 1;
   if(avatarp(TP) && TP->query_true_invis()) return 1;
   if(TP->query_property("flying")){
      if(!random(3)){ 
         tell_object(TP,"You fly easily over the post.");
      }
      return 1;
   }
   if(member_array(TP->query_race(),PLAYER_D->night_races()) != -1){
      if(!random(3)){
         tell_object(TP,"Your superior night vision allows you to easily avoid the post.");
      }
      return 1;
   }
   perc = TP->query_skill("perception");
   if(perc < roll_dice(1,20)) { 
      tell_object(TP,"%^BOLD%^%^BLACK%^As you make your way through "
         "the field, you run right into a post!%^RESET%^");
         if(!TP->query_invis()){
            tell_room(TO,"%^BOLD%^%^BLACK%^"+TPQCN+" runs straight into a post!%^RESET%^",TP);
         }
      TP->set_tripped(1,"You are still trying to get your "
         "bearings. That post really hurt!");
      return 1;
   }
}

int GoThroughDoor(){
   do_post();
   return ::GoThroughDoor();
}
