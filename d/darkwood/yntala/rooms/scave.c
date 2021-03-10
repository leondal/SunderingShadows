//scave
#include <std.h>
#include <rooms.h>
#include <daemons.h>
inherit PIER;
#include "../yntala.h"

void create(){
::create();
   set_property("indoors",1);
   set_water_body("river");
   set_name("%^BOLD%^%^BLUE%^A swiftly flowing underground river%^RESET%^.");
   set_short("%^BOLD%^%^BLUE%^A swiftly flowing underground river.");
   set_long((:TO,"ldesc":));
   set_smell("default","%^BLUE%^You cannot smell anything.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLUE%^The sound of rushing water is deafening%^RESET%^.");
   set_exits((["north":INRMS+"scave2","waterfall":INRMS+"hid38",
   ]));
   set_pre_exit_functions(({"waterfall"}),({"GoThroughDoor"}));
   call_out("bye_bye",1);
}
string ldesc(string str){
   return("%^BOLD%^%^BLUE%^You stand in the middle of a raging underground river that has carved its way through"
" this dark cavern.  Though the river itself is only  a few feet deep, it's current is strong and is"
" constantly pulling you towards the waterfall to the south!%^RESET%^\n");
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
            livings[i]->move_player(INRMS+"hid3");
            livings[i]->do_damage("torso",roll_dice(2,10));                  
            tell_room(find_object_or_load(INRMS+"hid3"),"%^BOLD%^%^BLUE%^You can hear "+livings[i]->query_cap_name()+"'s screams as "+livings[i]->query_subjective()+" tumbles over the waterfall and lands on the ground in front of you!%^RESET%^",livings[i]);
         }
      }
   }
   call_out("bye_bye",20);
}
int GoThroughDoor() {
   tell_object(TP,"%^RESET%^%^CYAN%^You step onto the slick surface of the rocks and get swept away by the waterfall!");
   tell_room(TO,"%^RESET%^%^CYAN%^"+TPQCN+" steps onto the smooth surface of the rocks and gets swept away by the waterfall!", TP);
   return 1;
}