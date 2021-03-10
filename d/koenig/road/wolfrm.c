#include <std.h>
inherit ROOM;

void search_shadows(string str);

int wolf_wait;

void create(){
  	::create();
  	set_property("light",1);
  	set_short("The road to Muileann and the oceans blue.");
  	set("day long", "%^GREEN%^You are walking along a quiet and eerie road.  "+
  		"Looking around, you can see a few trees, lots of open country with "+
  		"tons of rock and, of course, the devastated fields from which you "+
  		"came. There isnt much to look at and you get the feeling you should "+
  		"be moving on quickly.\n");
  	set("night long", "%^BLUE%^This place gives you the creeps by far! Things "+
  		"just dont look the same as they do by day. The shadows here almost "+
  		"seem to move of thier own will and not that of the object they are "+
  		"casting. You decide not to dawdle anymore and hurry on your way!\n");
  	set_items( ([
        	"trees" : "There is wild hemp all over and you notice one willow tree.",
           	"rocks" : "They are just rocks with an aqua colored moss growing all "+
           		"over them.",
          	({"willow","tree","willow tree"}) : "It is old, HUGE, and very beautiful.",
           	"shadows" : "You could swear something is lurking in them...maybe "+
           		"if you DARE to search them!"
     	]) );
  	set_smell("default", "You catch the faint smell of fear and the sea.");
  	set_listen("default","You hear insects and other small noises.");
  	set_exits( ([
     		"south" : "/d/koenig/fields/room/field16",
     		"north" : "/d/koenig/road/room2"
    	]) );
  	wolf_wait = 0;
}

void init(){
  	::init();
  	add_action("search_shadows", "search");
}

int search_shadows(string str){
  	if(str != "shadows" || wolf_wait != 0)return 0;
  	if(present("wolf") || present("shewolf")){
      	tell_object(TP,"Havent you found enough already?  \n");
      	tell_room(ETP,""+TPQCN+" must be INSANE, they are searching "+
			"the shadows for more, RUNNING is a good idea about NOW!",TP);
      	return 1;
    	}
  	wolf_wait = 1;
  	new("/d/koenig/road/mon/wolf.c")->move(TO);
  	new("/d/koenig/road/mon/fwolf.c")->move(TO);
  	tell_object(TP, "A pair of wolves step silently from the shadows.");
  	tell_room(ETP,""+TPQCN+" searches the shifting shadows and finds a "+
  		"pair of wolves.",TP);
  	return 1;
}

void reset(){
  	::reset();
  	if(wolf_wait != 0)wolf_wait--;
}
