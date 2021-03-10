#include <std.h>
#include "../tharis.h"
inherit VAULT;

// Based on old Tharis City Buildings, Mobs, etc.
// Tharis City Remodle - Created by LoKi in 2009.  
// Fattened Dwarf Remodle - Created in February 2009 by Ari

void create(){
	::create();
		set_property("indoors",1);
		set_property("light",1);
		set_terrain(STONE_BUILDING);
		set_travel(PAVED_ROAD);
		
		set_name("the fattened dwarf");
		set_short("%^BOLD%^%^RED%^The Fattened Dwarf%^RESET%^");
		
		set_long("%^BOLD%^%^RED%^The Fattened Dwarf%^RESET%^\n"+
			"%^RESET%^%^ORANGE%^This quaint place has a %^BOLD%^"+
			"%^BLACK%^dark%^RESET%^%^ORANGE%^ and %^WHITE%^sedate "+
			"%^ORANGE%^atmosphere.  The small, round tables look "+
			"well used and often scrubbed, leaving them clean and "+
			"somewhat %^RESET%^polished%^ORANGE%^.  A few %^BOLD%^"+
			"%^BLACK%^shadowy booths%^RESET%^%^ORANGE%^ occupy one "+
			"wall, each lit by the soft glow of a %^YELLOW%^table "+
			"lantern%^RESET%^%^ORANGE%^. A row of %^CYAN%^windows "+
			"%^ORANGE%^looks out over the busy city market, though "+
			"the wide awning over the front of the building, keeps "+
			"most of the natural lighting from finding its way "+
			"inside.  A large %^RESET%^slate menu %^ORANGE%^has "+
			"been tacked to the wall next to each entrance, "+
			"clearly stating today's specials along with the "+
			"regular menu items.%^RESET%^");

		set_smell("default","\nThe inn is filled with the smell "+
			"of meat, bread and ale.%^RESET%^");
		set_listen("default","A low hum of covered murmurs fills "+
			"the room.%^RESET%^");
		
		set_items(([
		({"tables","round tables"}):"%^RESET%^The tables are made "+
			"of thick planks of oak, likely culled from the famed "+
			"Tharis Forest timber.  Each round slab seems to be "+
			"nothing more then cross-sections of a tree, shorn "+
			"of bark and polished to a rich gleam. Plain looking "+
			"wood benches circle each table, providing a place "+
			"to sit and enjoy a meal or mug of ale.",
		({"booths","booth"}):"%^BOLD%^%^BLACK%^These darkly "+
			"shaded booths are made of thick, well-padded leather "+
			"and feature high backs to offer extra privacy for "+
			"patrons.  Lining the back wall, they sit in near "+
			"darkness but for the rich glow of the little "+
			"lanterns that are placed in the center of each of "+
			"the booth's tables.%^RESET%^",
		({"menu"}):"%^RESET%^The menu looks to have several "+
			"selections written upon it.  You should probably "+
			"read it over so you can order.",
		({"lantern","table lantern"}):"%^YELLOW%^These small "+
			"lanterns are made of iron and look to have seen "+
			"their share of hard times.  Dented and rusted, "+
			"this doesn't prevent them from being used to light "+
			"the dark booths that line the back wall.  With a "+
			"twist of the top half, the slats on the side can "+
			"be shuttered open or closed to reveal the candle "+
			"within.%^RESET%^",
		({"windows","city market","awning","market"}):"%^RESET%^"+
			"%^CYAN%^The north wall features three glass windows "+
			"that look out over the city's market.  A wide "+
			"%^GREEN%^awning%^CYAN%^ extends out over the front "+
			"of the building, casting the windows into shade "+
			"regardless of the season.  With the build up of "+
			"dust on the outside of the windows and the awning "+
			"little light manages to make its way through the "+
			"windows to illuminate the restaurant.%^RESET%^",
		]));
		
		set_exits(([
                "east":ROOMS"north4",
		"west":ROOMS"tharis_hotel2"
		]));
		
		set_door("double doors",ROOMS"tharis_hotel2","west",0);		
}

void init(){
   ::init();
   add_action("read","read");
   if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}

int read(string str){
    object ob;
    int i;
    if(str != "menu")  return 0;
    ob = present("gralesh");
    if(!ob) {
        write("The barkeeper isn't here right now.");
        return 1;
    }
    write("The following great foods are served here at the "+
		"Fattened Dwarf Tavern.");
  
	write("--------------------------------------------------"+
		"---------");
    write("Stuffed Pheasant\t\t\t\t"+ 
		(int)ob->get_price("stuffed pheasant") + " copper");
    write("Tharisian Dark Lager\t\t\t\t"+
		(int)ob->get_price("tharisian dark lager")+" copper");
    write("Mug of Water\t\t\t\t\t"+
		(int)ob->get_price("water")+" copper");
    write("Bread\t\t\t\t\t\t"+ 
		(int)ob->get_price("bread")+" copper");
    write("Dwarven stew\t\t\t\t\t"+ 
		(int)ob->get_price("dwarven stew")+" copper");
    write("Antiochish Wine\t\t\t\t\t"+ 
		(int)ob->get_price("antiochish wine")+" copper");
    write("Fattened Dwarf\t\t\t\t\t"+ 
		(int)ob->get_price("fattened dwarf")+" copper");
	write("--------------------------------------------------"+
		"---------");
    write("<buy dish_name> gets you the food.");
    return 1;
}

void reset(){
    ::reset();
    if(!present("gralesh")) new(MOBS"gralesh")->move(TO);
}