#include <std.h>
#include "short.h"

inherit CITYIN;

void create() {
   object ob;
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light", 2);
   set_property("indoors", 1);
   set_short("%^CYAN%^Seneca Restaurant%^RESET%^");
   set_long(
@STYX
%^CYAN%^This restaurant looks to be recently opened and is still sparsely furnished.  A few tables and chairs are scattered along the walls with lanterns hanging over them that provide most of the lighting in the room.  The oak floor looks fairly clean and the waiter seems to keep things cleaned up and orderly between dealing with the admiring glances of the female patrons.  The heavy oak doors provide a slight sense of security and the mood seems to be a little less tense than in much of the city.
%^RESET%^
STYX
   );
   set_exits( ([
      "west" : "/d/attaya/seneca/street14",
      "north" : "/d/attaya/seneca/road4"
   ]) );
   set_door("oaken door","/d/attaya/seneca/street14","west",0);
   set_open("oaken door",0);
   set_door_description("oaken door", "This door is made of fine-grained "
      "golden oak.");
   "/d/attaya/seneca/street14"->set_open("oaken door",0);
   
   set_door("panel door","/d/attaya/seneca/road4","north",0);
   set_open("panel door",0);
   set_door_description("panel door", "This door is made of fine-grained "
      "golden oak and has eight inset carved panels.  The top four panels "
      "depict various scenes of the jungle and the lower four of the beach "
      "and cliffs.");
   "/d/attaya/seneca/road4"->set_open("panel door",0);
}

void reset() {
  ::reset();
   if(!present("waiter"))
      new("/d/attaya/seneca/mon/waiter")->move(TO);
}

void init() {
	::init();
	add_action("read","read");
}


int read(string str) {
    object obj;
    int i;

    if(str != "menu") return 0;
    obj = present("waiter");
    if(!obj) {
        write("You cannot read the menu, as it is splattered with blood.");
    return 1;
    }
    tell_room(ETP,""+TP->query_cap_name()+" reads over the menu.",TP);
	message("Ninfo","The menu is posted in several languages on the wall.\n",TP);
	message("Ninfo","%^CYAN%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n",TP);
	message("Ninfo","%^CYAN%^The specials we can offer today are:%^RESET%^\n\n",TP);
		message("Ninfo","\tWild boar, a roasted haunch\t\t"+
		" "+(int)obj->get_price("wild boar")+" gold pieces\n",TP);
		message("Ninfo","\tBeef stew, with vegetables\t\t"+
		" "+(int)obj->get_price("beef stew")+" gold pieces\n",TP);
		message("Ninfo","\tPotato soup, with carrots and celery\t"+
		" "+(int)obj->get_price("potato soup")+" gold pieces\n",TP);
		message("Ninfo","\tToasted bread, lightly buttered\t\t"+
		" "+(int)obj->get_price("toasted bread")+" gold pieces\n",TP);
		message("Ninfo","\tBanana nut bread \t\t\t"+
		" "+(int)obj->get_price("banana nut bread")+" gold pieces\n",TP);
            message("Ninfo","\tChocolate Cake, a large slice \t\t"+
           " "+(int)obj->get_price("chocolate cake")+" gold pieces\n",TP);
		message("Ninfo","\tWater \t\t\t\t\t"+
		"  "+(int)obj->get_price("water")+" gold pieces\n",TP);
		message("Ninfo","\tCoffee, steaming and strong \t\t"+
		" "+(int)obj->get_price("coffee")+" gold pieces\n",TP);
		message("Ninfo","\tDark ale \t\t\t\t"+
                " "+(int)obj->get_price("dark ale")+" gold pieces\n",TP);
		message("Ninfo","%^CYAN%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n",TP);
    message("Ninfo", "<buy menu_name> will get Stanshar to serve you.\n", TP);
    return 1;
}
