#include <std.h>
#include <daemons.h>
#include "../piratedefs.h"
#include "/d/common/common.h"
inherit ROOM;

object ob;

void create(){ 
   ::create();
   set_name("Thief Guild storage");
   set_short("Thief Guild storage");
   set_long("Storage room for the Thieves Guild.");
   set_property("no teleport",1);
}

void reset(){
   if(!present("climb_tool")){
     ob=new(CMISC"climb_tool");
     ob->set_value(100); 
     ob->move(TO);
   }
   if(!present("picks")) {
     ob=new(CMISC"thief_tools");
     ob->set_value(150);
     ob->move(TO);
   }
   if(!present("rope")) new(CMISC"rope")->move(TO);
   if(random(20) < 15)
   {
       if(!present("poison_vial_object_xxx", TO)) 
       {
           POISON_D->QueryPoisonObject("any", "contact")->move(TO);
           if(!random(2)) POISON_D->QueryPoisonObject("any", "contact")->move(TO);
           POISON_D->QueryPoisonObject("any", "ingested")->move(TO);
           if(!random(2)) POISON_D->QueryPoisonObject("any", "ingested")->move(TO);
           POISON_D->QueryPoisonObject("any", "injury")->move(TO);
        }
   }
      
   if(!present("container") && !random(5)) new(OBJ"venomcontainer")->move(TO);
}


