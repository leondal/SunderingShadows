//ce1
#include <std.h>
#include <rooms.h>
#include <daemons.h>
#include "../bpeak.h"
inherit ROOM;

void create(){
::create();
   set_property("light",2);
   set_travel(LEDGE);
   set_terrain(ROCKY);
   set_name("%^RESET%^On the ledge of a cliff.");
   set_short("%^RESET%^A very unstable ledge.");
   set_long((:TO,"ldesc":));
   set_smell("default","A bad smell floats out of the cave.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLACK%^The wind howls as it races past you.");
   set_items(([
   "ledge":"%^RESET%^%^ORANGE%^The ledge is made of some sort of very unstable rock that is cracked and crumbling.   More rocks, varying in sizes from pebbles to boulders, line the ledge and look like they've fallen from somewhere further up the cliff.  The ledge itself is only about two feet wide and six feet long.%^RESET%^",
   ({"rocks","rock"}):"%^BOLD%^%^BLACK%^Rocks litter the ledge, looking like they've merely been caught here momentarily on their way down the cliff.%^RESET%^",
   ({"cliff","cliff face"}):"%^RESET%^The cliff face is is sheer here, with the exception of this little ledge.  It is one hundred feet to the bottom and another five hundred or so to the top.  The rocks look to unstable to climb and further though.",
   ({"opening","cave","cave opening"}):"%^BOLD%^%^BLACK%^The opening in the side of the cliff leads into a dark cave.  It is about twenty feet in height and leads into the darkness.  From here you cannot tell where it leads or what is inside.%^RESET%^",
   ]));
   set_search("default", "%^ORANGE%^Nothing here really looks interesting.%^RESET%^");
   set_exits((["cave":INRMS+"bcave1"]));
   set_climb_exits((["descend":({INRMS+"bcliff2",20,4,100})
]));
   call_out("fallen_angels",10);
}
string ldesc(string str){
   return("%^RESET%^This is a very narrow ledge on the %^ORANGE%^cliff %^RESET%^that"
" is perhaps only two feet in width and six feet long.  The"
" %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^BLACK%^c%^RESET%^k%^BOLD%^%^BLACK%^s"
" %^RESET%^are unsteady and constantly %^ORANGE%^crumbling %^RESET%^beneath you,"
" falling down to the path below.  The cliff face is sheer as it extends further up"
" and the rocks look to unstable to climb any further.  A large opening is here,"
" leading into a %^BOLD%^%^BLACK%^cave %^RESET%^that seems to be about twenty feet"
" in height.  The wind races past and you get the feeling that you should probably"
" seek out shelter.%^RESET%^\n");
} 
void fallen_angels(){
   object *livings,*inven;
   int i,j;     
   livings = ({});
   inven =filter_array(all_living(TO),"is_non_immortal_player",FILTERS_D);
   j= sizeof(inven);
   tell_room(TO,"%^BOLD%^%^BLACK%^As rocks fall from somewhere above and hit the ledge, it shakes violently and more rocks begin to crumble and fall!%^RESET%^");
   for(i = 0;i < j;i++){
      if(living(inven[i])) livings += ({inven[i]});
   }      
   j = sizeof(livings); 
      for(i=0;i<j;i++){
         if((random(24)-5) > livings[i]->query_stats("dexterity")){
            tell_room(TO,""+livings[i]->query_cap_name()+" slips on the falling rock and disappears down the cliff!",livings[i]);
            tell_object(livings[i],"You slip on the falling rocks and fall down the cliff!");
            if (!livings[i]->query_ghost()){
               livings[i]->move_player(INRMS+"bcliff2");
               livings[i]->do_damage("torso",roll_dice(2,8));                 
               tell_room(find_object_or_load(INRMS+"bcliff2"),"%^BOLD%^%^BLACK%^"+livings[i]->query_cap_name()+" slides in amongst a pile of falling rocks!%^RESET%^",livings[i]);
             }
          }
       else{
          tell_room(TO,""+livings[i]->query_cap_name()+" stumbles on the falling rocks but manages not to fall!",livings[i]);
          tell_object(livings[i],"You stumble on the falling rocks but manage to keep from falling!");
       }
   }
   call_out("fallen_angels",20);
}

