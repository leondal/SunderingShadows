//scave2
#include <std.h>
#include <rooms.h>
#include <daemons.h>
inherit PIER;
#include "../yntala.h"

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
   set_exits((["south":INRMS+"scave",
   "north":INRMS+"scave3",
   ]));
   call_out("bye_bye",1);
}
string ldesc(string str){
   return("%^BOLD%^%^BLUE%^You stand in the middle of a raging underground river that has carved its way through"
" this dark cavern.  Though the river itself is only  a few feet deep, it's current is strong and is"
" constantly pulling you towards the south, and to make matters worse, it appears as though the cavern floor"
" inclines sharply to the north, speeding up the current of the already fast moving water!%^RESET%^\n");
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
      if((random(18)-5) > livings[i]->query_stats("strength")|| random(10)+10 > livings[i]->query_stats("dexterity")){
         tell_room(TO,"%^BOLD%^%^BLUE%^"+livings[i]->query_cap_name()+" is taken away by the current!",livings[i]);
         tell_object(livings[i],"You get washed away by the current heading south!");
         if (!livings[i]->query_ghost()){
            livings[i]->move_player(query_exit("south"));
            livings[i]->do_damage("torso",roll_dice(2,10));                  
            tell_room(find_object_or_load(query_exit("south")),"%^BOLD%^%^BLUE%^"+livings[i]->query_cap_name()+" is fighting the current, but gets washed in anyway!%^RESET%^",livings[i]);
         }
      }
   }
   call_out("bye_bye",20);
}