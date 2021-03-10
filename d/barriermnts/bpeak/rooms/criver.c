//criver
#include <std.h>
#include <rooms.h>
#include <daemons.h>
#include "../bpeak.h"
inherit PIER;
inherit INRMS+"bcave1";

void create(){
::create();
   set_property("no teleport",1);
   set_property("indoors",1);
   set_water_body("river");
   set_name("%^BOLD%^%^BLUE%^A swiftly flowing underground river%^RESET%^.");
   set_short("%^BOLD%^%^BLUE%^A swiftly flowing underground river.");
   set_long((:TO,"ldesc":));
   set_smell("default","%^BLUE%^You cannot smell anything.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLUE%^The sound of rushing water is deafening%^RESET%^.");
   set_exits((["east":INRMS+"redge",
   "west":INRMS+"redge2"]));
   call_out("bye_bye",1);
}
string ldesc(string str){
   return("%^BOLD%^%^BLUE%^You stand in the middle of a swiftly flowing river.  The pull is tremendous and it takes all you have to fight the current.  On the eastern banks you can see nothing but a wall with a strange arch in it.  On the western banks you can see piles and piles of treasures heaped.  Looking towards the lights coming from the south you now realize why this river is moving so quickly...  It is heading straight for a waterfall!%^RESET%^\n");
} 
void bye_bye(){
   object *livings,*inven;
   int i,j;     
   livings = ({});
   inven =filter_array(all_living(TO),"is_non_immortal_player",FILTERS_D);
   j= sizeof(inven);
   tell_room(TO,"%^BOLD%^%^BLUE%^The current rushes past you!%^RESET%^");
    for(i = 0;i < j;i++){
       if(living(inven[i])) livings += ({inven[i]});
    }      
    j = sizeof(livings);       
    for(i=0;i<j;i++){
      if((random(8)+12) > livings[i]->query_stats("strength")){
         tell_room(TO,"%^BOLD%^%^BLUE%^"+livings[i]->query_cap_name()+" is taken away by the current!",livings[i]);
         tell_object(livings[i],"You get washed away by the current, go over the waterfall and end up on a shore somewhere else!");
         if (!livings[i]->query_ghost()){
            livings[i]->move_player(INRMS+"bpath2");
            livings[i]->do_damage("torso",roll_dice(2,10));                  
            tell_room(find_object_or_load(INRMS+"bridge"),"%^BOLD%^%^BLUE%^You can hear "+livings[i]->query_cap_name()+"'s screams as "+livings[i]->query_subjective()+" tumbles over the waterfall and is washed down the river beneath you!%^RESET%^",livings[i]);
         }
      }
   }
   call_out("bye_bye",20);
}
