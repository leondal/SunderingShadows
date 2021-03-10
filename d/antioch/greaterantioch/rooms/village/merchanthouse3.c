#include <std.h>
#include "../../gantioch.h"
#include <daemons.h>

inherit CROOM;
object ob;

int triggered, isrunning;
int do_dragon(int mystate);
int is_running();

void create()
{
    ::create();
    set_property("no teleport",1);
    set_name("merchanthouse3");
    set_property("indoors",1);
    set_property("light",3);
    set_short("%^RESET%^%^CYAN%^In a Bedroom%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This is obviously the master bedroom of the house. It has a massive %^BOLD%^%^MAGENTA%^bed%^BOLD%^%^WHITE%^"+
             " against the wall. There is a large %^RESET%^%^ORANGE%^dresser %^BOLD%^%^WHITE%^against the far wall and the"+
             " the floor is covered in a thick %^BOLD%^%^GREEN%^carpet%^BOLD%^%^WHITE%^. There is a %^BOLD%^%^YELLOW%^bookshelf"+
             " %^BOLD%^%^WHITE%^against the last wall, nearly covering up the only %^BOLD%^%^CYAN%^window %^BOLD%^%^WHITE%^in the room.");

    set_smell("default","\n%^BOLD%^%^YELLOW%^The smell of burning logs is noticeable here.%^RESET%^");
    set_listen("default","%^RESET%^%^RED%^You hear the sounds of dogs, chickens, and small chatter throughout this small area.%^RESET%^");
    triggered = 0;
    isrunning = 0;
    set_exits(([
        "hall"  : HAMLET"merchanthouse2",
	]));
    set_items(([
      "carpet" : "%^BOLD%^%^GREEN%^The carpet is a plush, very bright green - contrasting oddly with the rest of the decor.",
      "bed" : "%^BOLD%^%^MAGENTA%^This heavy comforted bed looks well made. It has a plush top and heavy backboards with a clear lace lining the four long posts of the bed.",
      "dresser" : "%^BOLD%^%^YELLOW%^The dresser is made of heavy spruce and has many drawers.",
      "bookshelf" : "%^RESET%^%^ORANGE%^This looks to be an ordinary bookshelf, which strangely, has no books on it. It is completely empty.",
      "window"  : "%^BOLD%^%^CYAN%^As you look out the window you see the rolling foothills outside.",
   ]) );
}

void init() {
   ::init();
   if(!objectp(TP)) return;
   if(!userp(TP)) return;
   if(TP->query_true_invis()) return;
   //if(member_array("Rescued the Missing Wife",TP->query_mini_quests())!=-1) return;
   if(triggered) return;
   triggered = 1;
   isrunning = 1;
   call_out("do_boss",1,0);
}

int do_boss(int mystate) {
   object thatroom;
   switch(mystate) {
     case 0:
       tell_room(TO,"%^BOLD%^%^RED%^%^As you walk into the room you notice %^BOLD%^%^YELLOW%^Faris %^BOLD%^%^RED%^throw"+
                 " an attractive middle-aged woman onto the bed as she screams loudly!\n%^RESET%^");
     break;
     case 1:
       tell_room(TO,"%^BOLD%^%^CYAN%^Before you can react he jumps on top of her, starting to rip at her top as she continues"+
                 " to cry and fight unsuccessfully.\n%^RESET%^");
     break;
     case 2:
       tell_room(TO,"%^BOLD%^%^YELLOW%^Faris %^BOLD%^%^RED%^suddenly seems to realize your there and looks back to you."+
                 " %^BOLD%^%^YELLOW%^'Excuse me...do you mind?'\n%^RESET%^");
     break;
     case 3:
       tell_room(TO,"%^BOLD%^%^CYAN%^Obviously annoyed, the man pushes the woman down on the bed again, pointing at her."+
                 " %^BOLD%^%^YELLOW%^'Don't you move, whore.' %^BOLD%^%^CYAN%^he says as he walks over to where you are.\n%^RESET%^");
     break;
     case 4:
       tell_room(TO,"%^BOLD%^%^RED%^Rubbing his hands together, %^BOLD%^%^YELLOW%^Faris %^BOLD%^%^RED%^looks at you carefully,"+
                 " then nods to himself slightly. %^BOLD%^%^YELLOW%^'The look about you says that you are here because of her.."+
                 " so...to avoid any misunderstandings with my purchase, I would like to offer you a fair deal to just walk away"+
                 " and not mention to anyone this happened. I will give you twenty thousand gold to just pretend this didn't happen."+
                 " What do you say?' %^BOLD%^%^RED%^The man looks at you curiously, obviously waiting for a response.\n%^RESET%^");
     new(MON"faris")->move(TO);
       isrunning = 0;
       return 1;
     break;
   }
   mystate++;
   call_out("do_boss",5,mystate);
   return 1;
   }


void reset_cinematics() { triggered = 0; }
int is_running() { return isrunning; }
