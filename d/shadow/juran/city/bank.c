#include <std.h>
#include "../juran.h"

inherit BANK;

void create(){
	::create();
   	set_terrain(STONE_BUILDING);
   	set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",-2);
   	set_short("Juran Coin Storage");
	set_long(
		"This is what passes for a bank in this town.  The walls look "+
		"grimey, but sturdy.  The teller and the guard look like they "+
		"can protect the money that is kept here.  The teller sits protected "+
		"at a desk behind iron bars, as is the door into the vault.  "+
		"The guard looks bored, but looks can be deceiving.  Torches "+
		"keep the room well lit."
	);
	set_smell("default","It smells like old coins in here.");
	set_listen("default","You can hear the clink of coins as someone"+
		" counts them in the back.");
	set_items(([
		({"door","bank door"}) : "This large door is fortified by thick"+
			" steel, it would not break easily.",
		({"torch","torches"}) : "Torches are placed in sconces about the"+
			" walls, always lit to bring light to the room since there are"+
			" no windows here.",
		"walls" : "The grimey walls are crafted from sturdy grey stone.",
		"floor" : "The floor could use some sweeping, dust has been"+
			" tracked in by the many customers. It is also paved with the"+
			" same stone that the rest of the building is made of.",
		({"roof","ceiling"}) : "The ceiling is the only part of this"+
			" building that is made from wood. Several large beams support"+
			" it and it is unlikely someone could get in through it.",
		({"desk","mahogany desk"}) : "This large desk is made out of"+
			" mahogany and it contains many drawers for the teller to file"+
			" away papers. The top of the desk has neatly stacked piles of"+
			" papers and some ink with a quill sitting next to it and empty"+
			" sheets of paper off to one side for new transactions. Behind"+
			" the desk is a matching mahogany chair that is padded and looks"+
			" very comfortable.",
		({"chair","mahogany chair"}) : "The mahogany chair perfectly"+
			" matches the desk. It is padded for extra comfort, probably"+
			" because the teller spends so much time sitting in it.",
		"sconces" : "There are sconces placed along the walls of the room"+
			" and lit torches are in them to light the dark bank.",
		({"bars","iron bars"}) : "The metal bars are very thick and would be "+
			"almost impossible to break through. Behind them the teller is "+
			"carefully counting the bank's money.",
		({"stone","stones","grey stones"}) : "The building is constructed"+
			" from blocks of heavy grey stones to insure security.",
		]));
	set_exits(([
		"northeast" : JROOMS+"r24",
	]));
}

void reset(){
	::reset();
	if(!present("bank guard")) new(JMONS+"bank_guard")->move(TO);
	if(!present("bank teller")) new(JMONS+"bank_teller")->move(TO);
	return;
}

string getBankId(){
    return "juran";
}
