#include <std.h>
inherit OBJECT;

void init(){
    ::init();
	add_action("imagine","imagine");
	add_action("links","links");
}


void create() {
    ::create();
    set_id( ({"tapestry"}) );
    set_weight(100000);
    set_name("tapestry");
    set("short", "A Tapestry hanging on the wall");
    set("long", "\nYou're looking at a tapestry. As you look at it, it seems " 
                "to fade in and out. You can't make out the picture, "
                "except that there are lots of adventurers hanging "
		"around. Your imagination runs wild.\n");

}

int imagine(string str){
  string myself, where;
  if(!str) return 0;
  if((sscanf(str, "%s in %s", myself, where)) !=2) return 0;
  if(myself != "myself" && where != "") return 0;
  write("Your slowly pulled into the tapestry...");
  say(this_player()->query_cap_name()+" fades into the tapestry...",this_player());

  switch(where){

  case "praxis":
	this_player()->move_player("/d/standard/adv_main");
	break;
  case "shadowgate":	
	this_player()->move_player("/d/shadowgate/adv_main");
	break;
  case "shadow":
	this_player()->move_player("/d/shadow/room/adventure");
	break;
  default :
   	write("Duh, where to ???");break;
	
  }
	write("Your eyes clear, and you find yourself in another place.");
	say(this_player()->query_cap_name()+" fades into reality.",this_player());
  	return 1;
}

void links(){
	write("The current links are:\n");
	write("%^GREEN%^ShadowGate\nShadow\nPraxis\n");
	return 1;
}
