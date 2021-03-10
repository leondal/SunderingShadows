#include <std.h>
#include "../piratedefs.h"

inherit ROOM;
object ob;
void create(){ 
   ::create();
   set_property("no teleport",1);
   set_property("light",0);
   set_property("indoors",1);

   set_short( "Pirate's thieves' storage");

   set_long("Thief item storage for the thieves' guild shop.");
}

void reset(){
    if(!present("climbing tool")){
       ob=new("/d/common/obj/misc/climb_tool");
       ob->set_value(400); 
       ob->move(TO);
    }
    if(!present("picks")){
       ob=new("/d/common/obj/misc/thief_tools");
       ob->set_value(500);
       ob->move(TO);
    }
    if(!present("rope")){
        new("/d/common/obj/misc/rope")->move(TO);
    }
    if(!present("poison")){
       ob=new("/cmds/thief/poison");
       ob->set_value((roll_dice(1,8))*100); 
       ob->move(TO);
       
       ob=new("/cmds/thief/poison");
       ob->set_value((roll_dice(1,8))*100); 
       ob->move(TO);
        
       ob=new("/cmds/thief/poison");
       ob->set_value((roll_dice(1,8))*100); 
       ob->move(TO);
       
       ob=new("/cmds/thief/poison");
       ob->set_value((roll_dice(1,8))*100); 
       ob->move(TO);
     }        

if((roll_dice(1,20))>5) return 0;
    if(!present("container")){
       new(WEAP"venomcontainer")->move(TO);
    }
}


