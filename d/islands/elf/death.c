#include <std.h>
#include "elf.h"
#include <daemons.h>

inherit ROOM;

int flag;

void create(){
    ::create();
     set_property("light",2);
     set_property("indoors",1);
     set_property("no attack",1);
     set_property("no teleport",1);
     set("short","awaiting death");
     set_long("Doesn't look good, you'll die soon.");
     set_smell("default", "You can spell your death coming.");
     set_listen("default", "You can almost hear the grim reaper coming closer.");
   }     
   // stolen from guardsman.c so if they get exicuted, no more bounty
 void remove_fines_and_bounties(object live)
{
    if(!objectp(live)) { return 0; }
    if(!live->is_player()) { return 0; }
    
    if(AREALISTS_D->is_wanted(live,"Ashta'Rathai",TO))
    {
        AREALISTS_D->remove_wanted(live,"Ashta'Rathai",TO);
    }
    if(AREALISTS_D->query_bounty_amount(live,"Ashta'Rathai",TO))
    {
        AREALISTS_D->remove_bounty(live,"Ashta'Rathai",TO);
    }
    if(AREALISTS_D->query_fine_amount(live,"Ashta'Rathai",TO))
    {
        AREALISTS_D->remove_fine(live,"Ashta'Rathai",TO);
    }
    return;
}
   
 void init(){
    if(!avatarp(TP))    
        call_out("cutscene",0,TP, 0);
}
void cutscene(object ob, int flag){
       string *cutscene;
	   cutscene = ({"After what seems like hours of waiting several elves in guard uniforms come in and drag you out of the cage.",
"You are brought before an elderly gold elf man.",
"The gold elf is wearing a yellow and silver robe and regards you with disgust.",
"He says coldly, 'You have been found guilty of crimes against the Tel'Quessir.'",
"He adds, 'The punishment for your crimes will be death by beheading.'",
"Motioning to the guards he says, 'Take this one outside the gates and be done with it.'",
"The guards drag you back to your feet and at spear point lead you outside the city.",
"You are brought before a large block of ice and are roughly made to fall on it with your head against the cold block of ice.",
"They don't ask for any last words as one of the guards draws a rather sharp looking blade.",
"You see them walk up beside you and can hear the movement as the guard readies to behead you.",
"'May the gods sort this one out, for there are no more chances here'  The executioner says as the blade falls true slicing through the back of your neck.",
"Everything goes black... ",
});
        if(!objectp(ob)) return;
        if( flag < sizeof(cutscene) )
		{
                write("%^CYAN%^"+ cutscene[ flag ] + "\n\n");
                flag++;
                call_out("cutscene",8,ob,flag);
        }
        else 
         {       ob->move_player(ROOMS"church");
		         remove_fines_and_bounties(ob);
				 ob->die();
				 
				 return;
		}
}
