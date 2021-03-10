//ce1
#include <std.h>
#include <rooms.h>
#include <daemons.h>
#include "deep_echo.h"
inherit ROOM;

void create(){
::create();
   set_property("light",-1);
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
   set_name("On the ledge of a cliff.");
   set_short("A very unstable ledge.");
   set_long((:TO,"ldesc":));
   set_smell("default","A bad smell floats out of the cave.");
   set_listen("default","The wind howls as it races past you.");
   set_items(([
   "ledge":"The ledge is made of some sort of very unstable rock that is "
"cracked and crumbling. The ledge itself is only about two feet wide and six "
"feet long.",
  
   ({"cliff","cliff face"}):"The cliff face is is sheer"+
   " here, with the exception of this little ledge."+
   "  It is one hundred feet to the bottom and"+
   " another five hundred or so to the top.  "+
   "The rocks look too unstable to climb or _descend_ easily.",
   ({"opening","cave","cave opening"}):"The opening in"+
   " the side of the cliff leads into a dark cave."+
   "  It is about twenty feet in height and leads"+
   " into the darkness.  From here you cannot tell "+
   "where it leads or what is inside."]));
   set_search("default", "Nothing but wet rocks.");
   set_exits((["east":"/d/shadow/room/mountain/cave30"]));
   set_climb_exits((["descend":({ROOMS"up.c",20,roll_dice(10,8),100})]));

   new(OBJ"sign")->move(TO);
   
}
string ldesc(string str){
   return("%^BOLD%^%^BLACK%^This is a very narrow "+
   "%^RESET%^ledge%^BOLD%^%^BLACK%^ on the %^RESET%^cliff%^BOLD%^%^BLACK%^ that"+
" is perhaps only two feet in width and six feet long.  The"+
" rocks"+
" are slippery from water dripping down. "+
" The cliff face is sheer as it extends "+
"further up and down.  A large %^RESET%^opening%^BOLD%^%^BLACK%^ is here,"+
" leading into a cave that seems to be about twenty feet"+
" in height.  The wind races past.  One is barely able to hold on.\n");
} 



void fallen_angels(){
   object *livings,*inven;
   int i,j,x;     
   livings = ({});
   livings =filter_array(all_living(TO),"is_non_immortal_player",FILTERS_D);
   j= sizeof(inven);
   tell_room(TO,"Wind blows through the area, shaking you on the wet rocks.");     
   j = sizeof(livings);
   if(!sizeof(livings)) return;
      for(i=0;i<j;i++){
         if((random(25)-5) > livings[i]->query_stats("dexterity")){
          tell_room(TO,""+livings[i]->query_cap_name()+ 
             "slips on the wet ledge and disappears down"+
             " the dark chasm!",livings[i]);
          tell_object(livings[i],"You slip and fall down the"+
             " chasm!  You hit several jagged rocks on "+
             "the way down.");
          if (!livings[i]->query_ghost()){
               livings[i]->move_player(ROOMS"up");
			   livings[i]->add_attacker(TO);
          for(x=1;x<10;x++)  
              livings[i]->do_damage("torso",roll_dice(1,8));              
		livings[i]->continue_attack();
		if(!objectp(livings[i])) 
		continue; 
		livings[i]->remove_attacker(TO);
              
tell_room(find_object_or_load(ROOMS"up"),""+
   livings[i]->query_cap_name()+
    " falls down with a thud!",livings[i]);
             }
 
          }
       else{
          tell_room(TO,""+livings[i]->query_cap_name()+
          " slips but manages not to fall!",livings[i]);
          tell_object(livings[i],"You slip but"+
            " manage to keep from falling!");
       }
   }
   call_out("fallen_angels",30+random(30));
}
void init(){
  ::init();
  if(find_call_out("fallen_angels")==-1) 
  fallen_angels();
}
