#include <std.h>
#include "../../gantioch.h"
#include <daemons.h>

inherit ROOM;

void create()
{
    ::create();
    set_name("mound1");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_short("%^RESET%^%^ORANGE%^Within a Mound%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^The hall continues to wind to the east from here, however, it is becoming wider,"+
			" and wider as you continue down the hall. From the looks of it, it is gradually opening up into"+
			" a wider area ahead. The ground is packed dirt and has slight %^BOLD%^%^YELLOW%^marks%^RESET%^%^ORANGE%^ all across the"+
			" ground. Crude %^RESET%^%^RED%^drawings %^RESET%^%^ORANGE%^cover the walls around you, depicting an"+
			" obvious tribal living area. %^BOLD%^%^WHITE%^A large %^RESET%^%^ORANGE%^wooden %^BOLD%^%^WHITE%^portcullis"+
			" blocks the way to the east. \n\n%^BOLD%^%^CYAN%^The tunnel ends here, blocked by a massive portcullis"+
            " to the east.");

    set_smell("default","\n%^BOLD%^%^BLACK%^The smell stench of rotting sweat and rotting food is apparent here.%^RESET%^");
    set_listen("default","%^RESET%^%^RED%^You hear yips and barks to the east, as if they are cheering.%^RESET%^");

    set_exits(([
		"west"	: MOUND"mound10",
	]));
	set_items(([
      "marks" : "%^RESET%^%^RED%^The marks on the walls are obviously made by a massive clawed creature.",
      "portcullis" : "%^RESET%^%^GREEN%^The portcullis is well made, though looks it looks like you may be able to %^BOLD%^%^YELLOW%^lift %^RESET%^%^GREEN%^it.",
      "drawings" : "%^BOLD%^%^YELLOW%^These tribal paintings depict many things, mostly violent and having the general theme of "+
                   " hunting, killing, and torturing various creatures from animals to elves, humans, gnomes, and other creatures.",
   ]) );
}

void init(){
  ::init();
  add_action("lift","lift");
}

int lift(string str){
  object *capture;
  int i,j;
  if ((str=="portcullis") || (str=="gate")){
  write ("%^BOLD%^%^RED%^As you move to lift the portcullis up, you hear movement behind you. Before you can respond a massive net surrounds you!"
  "\n%^BOLD%^%^GREEN%^The weight of the net puts you to your knees and you struggle to get out. All of a sudden something strikes violently against your head and everything goes %^BOLD%^%^BLACK%^dark%^BOLD%^%^GREEN%^!");
  say((string)TP->query_cap_name() +" goes to lift the portcullis up, rustling is heard around you! Nets fly out and entrap you as the gnolls pounce, smashing with large sticks into you as you are incapacitated.");
  TP->move(MOUND"mound13");
  capture=all_living(TO);
  capture=filter_array(capture, "is_non_immortal",FILTERS_D);
  j=sizeof(capture);
  for(i=0;i<j;i++){
  if((!TP->query_paralyzed()) || (!TP->query_bound()) || (!TP->query_unconscious())){
  if((int)capture[i]->query_highest_level()>10){
  tell_object(capture[i],"%^BOLD%^%^GREEN%^You try to avoid the net but one catches you and you suddenly feel a %^BOLD%^%^RED%^crack %^BOLD%^%^GREEN%^against your head and then everything goes dark!");
  tell_room(environment(capture[i]),""+capture[i]->query_cap_name()+" is hit by a net, and falls to the ground where the gnolls slam clubs into him and he slumps to the ground!",capture[i]);
  capture[i]->move_player(MOUND"mound13");
  }
  }
  }
  }
  return 1;
  }
