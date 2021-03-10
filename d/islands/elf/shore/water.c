#include <std.h>
#include "../elf.h"
#include <daemons.h>
inherit WATER;

int flag;

void create(){
    ::create();
    set_terrain(DEEP_WATER);
    set_travel(FRESH_BLAZE);
    set_short("Sinking into the sea");
    set_name("freezing in the water");
    set_long("%^BOLD%^You are sinking deeper into the dark sea. \n"
    "%^RESET%^It is very dark.  At the sea floor there are the ruins of what "
	"used to be a stone %^CYAN%^building%^RESET%^.  Little light gets here as the ice "+
  "flows above block the sky.  Hopefully this place is not soon to be you watery grave.");
    set_property("indoors",1);
    set_property("light",-2);
    set_smell("default","You can't smell anything with"+
		" all this water in your nose!");
    set_listen("default","You can hear yourself gurgle"+
	" as you try to scream while you slowly suffocate!");
	 set_exits(([
      "up" : ROOMS"shore/shore1",
      "south" : ROOMS"shore/ruin1",
   ]));
    set_items(([
      (({"ocean","water"})) :
        "The ocean is littered with ice bergs.",
      (({"building"})) : "Only stones show that there was a building here.  You could likely search the room.",
	  (({"ice berg","berg"})) : "Large blocks of ice float in the ocean.",
	   ]));
   set_search("room",(:TO,"search_room":));
}
void init(){
  object *ppl;
  int i;
  ::init();
   ppl=filter_array(all_living(TO),"is_non_immortal_player",FILTERS_D);

  for (i = 0; i < sizeof (ppl); i++){
    if(!objectp(ppl[i])) continue;
	tell_object(ppl[i],
           "%^CYAN%^Wish a splash you start sinking into the frigid sea.");
    if(!"/daemon/saving_throw_d.c"->fort_save(ppl[i],-40)) {
           ppl[i]->set_paralyzed(10,"Your body is in shock from the cold.");
         }
    }
 return;
}
void reset(){
  ::reset();
  if(!present("squid"))new(MON"squid")->move(TO);
  flag = 0;
}
int search_room(string str){
  object chest, pap;
  if (flag == 1) {
  tell_object(TP,"It seems like someone has"+
      " searched around here already.");
  return 1;
  }
  chest = new("/d/common/obj/misc/chest");
  chest->move(TO);
  chest->toggle_lock();
  chest->toggle_closed();
  pap = new("/d/common/obj/misc/paper");
  pap->set("language","elven");
  pap->set("read","%^GREEN%^This is the journal of Oropher Elensar.\n\n"+
       "%^CYAN%^325 SG:%^RESET%^\n  I've started to keep"+
	   " this journal as the governess said it will help"+
	   " me understand what is happening.  There is a "+
	   "war going on and everyone seems to think I'm "+
	   "useless.  I'm almost twelve years old now.  My "+
	   "father was able to use a sword by then.  I should"+
	   " be too.  No one in the elven kingdom seems to"+
	   " think that I'm worth the effort to train.  "+
	   "Well, I'll show them.  I'll come back after we"+
	   " leave and make my grandfather stop this war.  "+
	   "Humans and elves shouldn't fight! \n\n"
	   "So we finally made it to the river.  I got bold and "+
	   "stole a horse.  I'm going to head to the city.  "+
	   "I'm good at riding.  Cerilana always said I was the"+
	   " best.  Sister, we'll see each other soon and you'll"+
	   " be so proud! \n\n"+
       "Well, that didn't go so well.  I made it to the "+
	   "castle and the king wouldn't see me.  They said "+
	   "his son was corrupted by his wife and turned "+
	   "against him.  That I'm nothing.  I am too something!"+
	   "  I'm a prince this is not how you treat princes!  "+
	   "They tossed me in the dungeon.  It stinks down here. \n\n"+
       "I'm soooo hungry, no one has given me any food.  Those "+
	   "rats are starting to look tasty. I have to drink water"+
	   " that drips down the wall.  It is gross.  Sister, I hope "+
	   "you are safe.   It doesn't look like I can save you. \n\n"
       "There is an earthquake!  The castle is falling to bits "+
	   "around me.  I think I'm going to be trapped down here. \n\n"  +
       "So dark, been down here for days, no one is alive I don't"+
	   " think.  Rubble is everywhere.  Please come get me.  "+
	   "I don't want to die down here. \n\n"+
       "What is that?  Water!  Oh no, I'm going to drown "+
	   "alone in the dark.  Please save me someone.  "+
	   "I don't want to die....");
   pap->move(chest);	  
   chest->toggle_lock();
   chest->toggle_closed(); 
   tell_object(TP,"You search the sea "+
	 "floor and find a small chest in the "+
	 "remains of what once was a building.");
  flag =1;
      return 1;
}
