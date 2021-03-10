//teashop.c

#include <std.h>

inherit ROOM;

void create(){
	::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
	set_properties((["light":2,"indoors":1]));
	set("short","Lathis's tea shop");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^Lathis's tea shop%^RESET%^
This hole in the wall exceeds your expectations when you enter. Practically
lost among the other buildings lining the streets of the city, small tables
and booths look to create an intimate atmosphere. The sweet woodland herbs
sooth your tensions just through their fragrances. The walls of the shop 
are lined with examples of the herbs use. Most you recognize from your 
time in the forest, yet you don't allow yourself to presume to know what 
to do with them to make them so delicious and medicinal.
	In a dark corner you see a small table with two chairs. No one seems
to be sitting at that table, and quite deliberately.
OLI
	);
	
	set_exits(([
             "west":"/d/tharis/Tharis/es2side2"
		]));
	set_items(([
                "herbs":"These fabulous herbs have been picked from the surrounding forest.",
            "table":"%^BOLD%^RESERVED%^RESET%^: Master of Rogues.",
		"tables":"These are small round tables meant for two at most three people."
		]));
	
	set_smell("default","The sweet teas give you a slight euphoria.");
	set_listen("default","Your hear the low murmur of the few people sitting at the tables.");
}

void init(){
   ::init();
	
   if(TP->is_class("thief") || TP->is_class("bard")){
      write("%^GREEN%^Welcome brother");
    }
	add_action("herbs","look");
	add_action("press","press");
	add_action("press","push");
   add_action("read","read");
}
	
int herbs(string str){
	if(!str || str != "herbs") return 0;
	
	tell_room(TO,""+TPQCN+" looks over some herbs.",TP);
	write("%^RED%^As you look over the herbs you notice a well concealed button.");
	return 1;
}
	
int press(string str){
	if(!str || str != "button") return notify_fail("Press what?\n");
   if(TP->query_paralyzed() || TP->query_bound() || TP->query_tripped()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(TP->query_unconscious() || TP->query_bound()) {
      return 0;
   }
   if(TP->query_ghost()) {
      return notify_fail("You cannot do that in your immaterial state.\n");
   }
	
	tell_room(TP,"%^RED%^"+TPQCN+" suddenly blinks out of site!",TP);
	write("%^RED%^Suddenly you feel a rush of air and movement.\n"+
		"You find yourself someplace else!");
	TP->move_player("/d/tharis/Tharis/tguild1");
	return 1;
}

void reset(){
  ::reset();
  if(!present("lathis"))
	find_object_or_load("/d/tharis/monsters/lathis")->move(TO);
}

int read(){
    object ob;
    int i;

    ob = present("lathis");
    if(!ob) {
        write("You cannot read the menu, as it is splattered with blood.");
        return 1;
    }
     write("The following great teas are served here at the Teashop");

write("--------------------------------------------------------------------");
    write("Woodroot tea\t\t\t\t"+ (int)ob->get_price("woodroot tea") + " silver");
    write("Gaspers tea\t\t\t\t"+(int)ob->get_price("gaspers tea")+" silver");
   write("Tea and brandy\t\t\t\t "+(int)ob->get_price("tea and brandy")+" silver");
    write("Cut throat tea\t\t\t\t"+ (int)ob->get_price("cut throat tea")+" silver");
    write("-----------------------------------------------------------");
    write("<buy dish name> gets you the food.");
    return 1;
}
