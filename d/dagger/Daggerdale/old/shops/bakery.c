#include <std.h>
inherit ROOM;

void create()
{
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_short("A pleasant bakery");
   set_long(
   "This is a pleasant little bakery in Daggerdale, even if it is a"+
   " bit small. There are a few stools and tables for the customers,"+
   " but not many. There is a large glass counter that is angled to show"+
   " off the pastries and breads. You can see a large kitchen in the"+
   " back that is closed off from the rest of the room. There is a menu"+
   " on a sign next to the counter that lists what can be bought here.");
   set("night long",
   "This is a pleasant little bakery in Daggerdale that is apparently"+
   " closed in the evening hours. There are a few stools and tables for"+
   " the daytime customers, but not many. There is a large glass counter"+
   " that is angled to show off the pastries and fresh breads, but it is"+
   " currently empty. You can see a large kitchen in the back that is closed"+
   " off from the rest of the room. Perhaps you should come back in the"+
   " morning.");
   set_smell("default","You smell the sugar and flour used in baking.");
   set_listen("default","Your stomach grumbles in longing as your nose"+
   " is teased by pleasant smells.");
   set_items(([
   "menu" : "This is a menu that is posted on the counter. It works best"+
   " if you read it instead of just stare at it.",
   ]));
   set_exits(([
   "south" : "/d/dagger/Daggerdale/streets/street7",
   ]));
}

void reset()
{
   ::reset();
//   if(!present("baker") && !objectp("/d/dagger/Daggerdale/shops/npcs/baker")) {
//      ("/d/dagger/Daggerdale/shops/npcs/baker")->move(TO);
//  }
}

void init()
{
	::init();
	add_action("read","read");
}

int read(string str)
{
	object obj;
	int i;

	obj = present("baker");

   if(!present("baker")) {
		write("Someone seems to have killed the baker!");
		return 1;
	}
	if(str == "menu") {
		say(""+TP->query_cap_name()+" reads over the menu.");
		message("Ninfo","The menu reads:\n",TP);
		message("Ninfo","%^CYAN%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n",TP);
		message("Ninfo","\t%^BOLD%^%^MAGENTA%^Raspberry tarts%^RESET%^ \t"+
		" "+(int)obj->get_price("raspberry tarts")+" silver pieces\n",TP);
		message("Ninfo","\t%^BOLD%^%^BLACK%^Chocolate%^RED%^ strawberries%^RESET%^ \t"+
		" "+(int)obj->get_price("chocolate strawberries")+" silver pieces\n",TP);
		message("Ninfo","\tGlazed doughnuts \t"+
		" "+(int)obj->get_price("glazed doughnuts")+" silver pieces\n",TP);
		message("Ninfo","\t%^BOLD%^%^BLACK%^Chocolate%^WHITE%^ eclair%^RESET%^ \t"+
		" "+(int)obj->get_price("chocolate eclair")+" silver pieces\n",TP);
		message("Ninfo","\t%^WHITE%^%^BOLD%^Cream puffs%^RESET%^ \t\t"+
		" "+(int)obj->get_price("cream puffs")+" silver pieces\n",TP);
		message("Ninfo","\t%^YELLOW%^Fruit pastry%^RESET%^ \t\t"+
		" "+(int)obj->get_price("fruit pastry")+" silver pieces\n",TP);
		message("Ninfo","\t%^RED%^Cinnamon pinwheels%^RESET%^\t"+
		" "+(int)obj->get_price("cinnamon pinwheels")+" silver pieces\n",TP);
		message("Ninfo","\tCookie platter \t\t"+
		" "+(int)obj->get_price("cookie platter")+" silver pieces\n",TP);
		message("Ninfo","\tSticky buns\t\t"+
		" "+(int)obj->get_price("sticky buns")+" silver pieces\n",TP);
		message("Ninfo","\t%^YELLOW%^Apple turnover%^RESET%^ \t\t"+
		" "+(int)obj->get_price("apple turnover")+" silver pieces\n",TP);
		message("Ninfo","\t%^BOLD%^%^BLUE%^Blueberry pie%^RESET%^ \t\t"+
		" "+(int)obj->get_price("blueberry pie")+" silver pieces\n",TP);
		message("Ninfo","\t%^BOLD%^%^WHITE%^Tapioca pudding%^RESET%^ \t"+
		" "+(int)obj->get_price("tapioca pudding")+" silver pieces\n",TP);
		message("Ninfo","\tCoffee \t\t\t"+
		" "+(int)obj->get_price("coffee")+" silver pieces\n",TP);
		message("Ninfo","\t%^BOLD%^%^WHITE%^Milk%^RESET%^ \t\t\t"+
		" "+(int)obj->get_price("milk")+" silver pieces\n",TP);
		message("Ninfo","\tHot chocolate \t\t"+
		" "+(int)obj->get_price("hot chocolate")+" silver pieces\n",TP);
		message("Ninfo","\t%^YELLOW%^Buttered bread%^RESET%^\t\t"+
		" "+(int)obj->get_price("buttered bread")+" silver pieces\n",TP);
		message("Ninfo","\t%^BOLD%^%^RED%^Tomato brochette%^RESET%^ \t"+
		" "+(int)obj->get_price("tomato brochette")+" silver pieces\n",TP);
		message("Ninfo","\t%^BOLD%^%^GREEN%^Cucumber sandwiches%^RESET%^\t"+
		" "+(int)obj->get_price("cucumber sandwiches")+" silver pieces\n",TP);
		message("Ninfo","%^CYAN%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n",TP);
		message("Ninfo","<buy dish_name> gets you the food.\n",TP);
		return 1;
	}
}

