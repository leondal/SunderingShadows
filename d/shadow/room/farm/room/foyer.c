#include <std.h>
#include "../farm.h"
inherit VAULT;

void create(){
   	::create();
   	set_property("indoors",1);
   	set_property("light",1);
	set_property("no sticks",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^CYAN%^Piaf Huffelmuffin's Foyer");
   	set_short("%^CYAN%^Piaf Huffelmuffin's Foyer");
   	set_long("%^CYAN%^The foyer to this gnomish style house"+
		" gives you a view of the dusty, dirty, crowded abode"+
		" of Piaf Huffelmuffin.  The open design of the house"+
		" gives you a peek at the other rooms from here.  The "+
		"western section of the home has a %^RED%^fireplace%^CYAN%^ and a "+
		"ratty looking chair.  Across from it, the eastern wall"+
		" houses the kitchen area with a sink full of %^ORANGE%^"+
		"dirty dishes%^CYAN%^."+
		"  The bedroom is across from you, with an unmade %^RESET%^"+
		"bed%^CYAN%^ and a "+
		"pile of books around it.  Flanking the door to the house are"+
		" two large%^YELLOW%^ bronze%^RESET%^%^CYAN%^ statues of "+
		"human warriors wielding polearms."+
		"  The %^WHITE%^%^BOLD%^windows%^RESET%^%^CYAN%^ of the home"+
		" are more like port holes, in odd "+
		"strange shapes.%^RESET%^\n");
	set_smell("default","The air smells dusty and dirty.");
   	set_listen("default","The moving of gears can be heard.");
  	set_items(([
      	({"statues"}) : "%^YELLOW%^Two bronze statues of humans flank"+
			" the doorway.  Adorned in chainmail and simple helms the human"+
			" figures hold tight to a bardiche.  On the left statue a "+
			"button rests on the base, tempting someone to press it.",
      	({"bed","bedroom","books"}) : "%^ORANGE%^A small gnomish sized"+
			" bed takes up most of the northern corner of the home.  "+
			"The unmade bed has a simple wool blanket and cotton sheets"+
			" on it.  Piled around the bed are stacks of books.",
		({"sink","kitchen","dishes"}) : "%^GREEN%^A soapstone sink and "+
			"spigot are mounted to the eastern wall of the homestead."+
			"  The sink is full of a grayish colored water and dirty dishes.",
		({"chair","fireplace","fire"}) : "%^RED%^A brick fireplace rests "+
			"inside the western wall.  Infront of the fireplace a ratty"+
			" old chair rests with a wool blanket tossed over an arm.  "+
			"Stacks of books surround the chair.",
		({"window","windows"}) : "%^BOLD%^Looking more like port holes than "+
			"windows, these glass windows allow Piaf to gaze out at his"+
			" farmland.  The windows are formed into strange and odd "+
			"shapes.  The north window looks like a bunny rabbit.  Looking"+
			" like a goose, the eastern window allows light into the dirty"+
			" kitchen.  A squirrel shaped window rests to the side of the "+
			"chimney to the east."
		]));
		set_exits(([ "northwest" : ROOMDIR"study",
				 "northeast" : ROOMDIR"kitchen",
				"outside" : ROOMDIR"gnomehome"
		 ]));
	set_door("door",ROOMDIR"gnomehome","outside",0);
   	set_door_description("door","The%^ORANGE%^ oak%^RESET%^"+
			" door is covered with sheets of weathered copper, giving"+
			" it a %^GREEN%^greenish%^RESET%^ hue.  Mounted on the front"+
			" of the door is a rabbit's head %^YELLOW%^brass %^RESET%^knocker.");

}
void init(){
::init();
    	add_action("press","press");
	add_action("press","push");
}
int press(string str){
        if(str != "button") 
      return notify_fail("Press what?\n");

      tell_object(TP,"%^YELLOW%^You press the button and the statues start"+
		" to move!\n\nThe statues start to pirouette and twirl gracefully"+
		" as they dance on their bases.");
	tell_room(ETP,"%^YELLOW%^"+TPQCN+" presses the button on the statue's "+
		"base and the statues start to move!\n\nThe statues start to "+
		"pirouette and twirl gracefully as they dance on their bases.",TP);
     	return 1;
}
