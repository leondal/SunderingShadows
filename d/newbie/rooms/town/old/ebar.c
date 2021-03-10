#include <std.h>
#include "../../newbie.h"
inherit INH"townmove.c";

void create()
{
	::create();
	set_property("indoors",1);
	set_terrain(STONE_BUILDING);
	set_travel(PAVED_ROAD);
	set_short("Dragon's Blood Bar");
	set_long(
	"%^RED%^You're standing in the Dragon's Blood Bar, which is located on the southeast side of"+
	" town. It has a friendly atmosphere, several tables are talking and laughing"+
	" together as they drink. There are also quite a few people up at the bar as well,"+
	" though it wouldn't be hard to find room here. What strikes you most is that the"+
	" entire establishment is decorated in red. The walls, floor, and ceiling have been"+
	" washed a dark red color. The bar, along with all the stools, chairs, and tables"+
	" are made out of red cherry wood. Even the stool cushions are a dark red. It is easy"+
	" to see how this place got its name. At first it is rather an odd appearance, but"+
	" you adjust to it easily and the place does seem quite friendly."+
    " A %^GREEN%^wooden sign%^RED%^ hangs near the entrance and next to it is a"+
    " %^GREEN%^dartboard%^RED%^ carved from a thicker wood. "+
    " There's a menu at the bar that tells you what is served here."
	);
	set_property("light",2);
	set_smell("default","You can smell the refreshing beverages that the bar serves.");
	set_listen("default","You can hear the other patrons chattering merrily.");
	set_items(([
	({"walls","floor","ceiling"}) : "%^RED%^The walls, floor, and ceiling of the room"+
	" have all been dyed a dark red. It does sort of look like dragon's blood, it has"+
	" a rusty quality to it. You have to wonder how this came about.",
	({"chairs","tables","stools","bar","bar stools"}) : "%^BOLD%^%^RED%^All the chairs, tables,"+
	" and bar stools in the room are made out of red cherry wood. The color is slightly"+
	" brighter than that of the walls. Instead of looking tacky, it actually looks"+
	" surprisingly fitting.",
	"menu" : "There is a menu propped up on the bar. You can read it if you'd like to"+
	" know what's being served here.",
    ({"sign","wood sign","wooden sign"}) : "This appears to be a "+
    "list of some sort, maybe you should read it?",
	]));
	set_exits(([
	"south" : MAINTOWN"eroad4",
	"east" : MAINTOWN"eroad2",
	]));
	
}

void init()
{
	::init();
	add_action("read_menu","read");
}

void reset()
{
    object ob;
	::reset();
	if(!present("barkeep")) {
                find_object_or_load(MON"barkeep1")->move(TO);
	}
    if(!present("dartboard")) {
        ob = new("/d/common/obj/misc/dart_board");
        ob->set_mastery_list("dragons_blood_bar");
        ob->move(TO);
    }
}

int read_menu(string str)
{
    string *names;
	object obj;
	int i, x;

	obj = present("barkeep");

    if((str == "sign" || str == "wooden sign" || str == "wood sign")
    && obj = present("dartboard")) {
        write("These are the folks who WE recognize as masters at "+
        "the game of darts!");
        names = obj->query_mastery_list();
        if(!sizeof(names)) {
            tell_object(TP,"No one has mastered the game yet!");
            return 1;
        }
        for(x = 0;x < sizeof(names);x++) {
            tell_object(TP,"["+(x+1)+"] %^RED%^"+names[x]+"%^RESET%^\n");
        }
        return 1;
    } 

	if(str == "menu" && !present("barkeep")) {
		write("The menu is covered in the barkeepers blood and can't be read!");
		return 1;
	}
	if(str == "menu") {
		say(""+TPQCN+" reads over the menu.");
		message("Ninfo","You look over the menu on the bar, it reads:\n",TP);
		message("Ninfo","%^RED%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n",TP);
		message("Ninfo","\tYarrow Ale \t"+
		" "+(int)obj->get_price("yarrow ale")+" silver pieces\n",TP);
		message("Ninfo","\tAle \t\t"+
		"  "+(int)obj->get_price("ale")+" silver pieces\n",TP);
		message("Ninfo","\tWine \t\t"+
		" "+(int)obj->get_price("wine")+" silver pieces\n",TP);
		message("Ninfo","\tApple Cider \t"+
		"  "+(int)obj->get_price("apple cider")+" silver pieces\n",TP);
            message("Ninfo","\tWater \t\t"+
            "  "+(int)obj->get_price("water")+" silver piece\n",TP);
		message("Ninfo","\tCoffee \t\t"+
		"  "+(int)obj->get_price("coffee")+" silver pieces\n",TP);
		message("Ninfo","\tCheese \t\t"+
		"  "+(int)obj->get_price("cheese")+" silver pieces\n",TP);
		message("Ninfo","\tHam \t\t"+
		"  "+(int)obj->get_price("ham")+" silver pieces\n",TP);
		message("Ninfo","\tSausage \t"+
		"  "+(int)obj->get_price("sausage")+" silver pieces\n",TP);
		message("Ninfo","\tStew \t\t"+
		"  "+(int)obj->get_price("stew")+" silver pieces\n",TP);
		message("Ninfo","\tDuck \t\t"+
		" "+(int)obj->get_price("duck")+" silver pieces\n",TP);
		message("Ninfo","\tCherry Pie \t"+
		"  "+(int)obj->get_price("cherry pie")+" silver pieces\n",TP);
		message("Ninfo","%^RED%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n",TP);
		message("Ninfo","<buy dish_name> gets you the item.\n",TP);
		return 1;
	}
}
