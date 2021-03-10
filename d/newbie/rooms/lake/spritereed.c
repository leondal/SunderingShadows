#include <std.h>
inherit OBJECT;

// Aquatic Quest - Offestry Valley - Created in March 2009 by Ari
// For inclusion into the Offestry Valley Upgrade by Nienne

int CHARGES;

void init(){
  ::init();
  add_action("use_reed","use");
}

void create(){
  ::create();
    CHARGES=3;
    set_name("sprite reed");
    set_id(({"reed","piece of reed","reed piece","sprite reed"}));
    set_short("%^ORANGE%^A small piece of reed%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^Only a finger's length long, "+
	"this piece of reed looks like it might have been broken "+
	"off any lake shore plant, except for the faint %^GREEN%^ "+
	"glow%^ORANGE%^ it casts.  Maybe you could %^GREEN%^<use> "+
	"%^ORANGE%^it for something.%^RESET%^");
    set_weight(1);
    set_value(5);
	
	set_lore("A guarded secret amongst the fairies of Offestry "+
	"Forest, these special reeds grow along the shore of "+
	"Cor'Alu Lake.  Tended by the fair folk, they contain a "+
	"faint amount of magic which can be used to cast spells "+
	"such as water breathing upon someone who might not "+
	"otherwise be able to.");
	set_property("lore difficulty",3);
	
}

int use_reed(string str){
  object ob;
  if(TP->query_bound() || TP->query_unconscious()){
    TP->send_paralyzed_message("info",TP);
	return 1;
  }
  
  if(!str){
    notify_fail("What did you want to use?  The reed maybe?");
	return 1;
  }
  
  if(!CHARGES){
    tell_object(TP,"%^ORANGE%^The reed's magic seems to have been "+
	"all used up.  It can't do that any more.");
	return 1;
  }
  
  tell_room(ETO,"%^GREEN%^"+TP->QCN+" places the piece of reed "+
  "to their mouth and breathes some of the magic in.",TP);
  tell_object(TP,"%^GREEN%^You place the piece of reed to your "+
  "mouth and breathe in some of the magic.");
  new("cmds/spells/w/_water_breathing.c")->use_spell(TP,TP,40,100,"cleric");
  CHARGES--;
  return 1;
}
