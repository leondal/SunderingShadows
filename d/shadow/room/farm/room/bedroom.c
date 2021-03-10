#include <std.h>
#include "../farm.h"
inherit ROOM;

void create(){
   	::create();
   	set_property("indoors",1);
   	set_property("light",1);
	set_property("no sticks",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^CYAN%^Piaf Huffelmuffin's Bedroom");
   	set_short("%^CYAN%^Piaf Huffelmuffin's Bedroom");
   	set_long("%^CYAN%^An iron frame bed is nestled against"+
		" the northern wall of this homestead.  A straw "+
		"filled mattress is covered with a %^RESET%^dingy"+
		" white%^CYAN%^ cotton sheet.  Crumpled on the bed"+
		" is a ratty %^GREEN%^quilt%^CYAN%^ and a couple of"+
		" goose feather pillows.  A short nightstand lays "+
		"close to the bed with a %^YELLOW%^brass %^RESET%^"+
		"%^CYAN%^candlestick on it.  Melted clumps of wax "+
		"coat the surface of the table.  Stacked around the"+
		" bed (and even a few on the bed) are numerous tomes"+
		" and journals.  A simple looking dresser is pressed"+
		" against the western wall, with a gnomish contraption"+
		" attached to it.  Near the bed, a ladder leads down "+
		"into the lower parts of the house. %^RESET%^\n");
	set_smell("default","The musty scent of the bed lingers in the air.");
   	set_listen("default","The sound of gears turning can be heard.");
  	set_items(([
      	({"bed","quilt","pillows","blanket"}) : "%^GREEN%^The white "+
			"sheets look to be in need of a good washing.  Their "+
			"white color is dingy and faded.  Crumpled up on the "+
			"bed is a ratty quilt that looks past its prime.  Two"+
			" goose feather pillows lay bunched up on the bed.",
      	({"nightstand"}) : "%^ORANGE%^A wooden nightstand is covered"+
			" with clumps of melted wax.  A bronze candlestick "+
			"rests on the surface of the nightstand, caked in wax"+
			" as well.  Looking closer at the dresser you can see"+
			" four tiny hoses attached to a perforated metal head."+
			"  The hoses join together to a main hose that leads "+
			"out of the home towards the stream.  It almost seems "+
			"as if water was meant to shoot out of these hoses.",
		({"tomes","journals","books"}) : "%^YELLOW%^Tomes and journals"+
			" dealing with mechanical devices and engineering are "+
			"stacked around the bedroom.  A few novels on horticulture"+
			" remain at the bottom of the stacks, looking untouched "+
			"for ages.",  
		({"dresser","contraption"}) : "%^BLUE%^A small wooden "+
			"dresser is nestled against the western wall.  The"+
			" dresser is rather non descript in appearance.  A"+
			" hole is cut into the side of the dresser, allowing"+
			" a rope to enter the side.  The rope is connected to"+
			" a gnomish contraption crafted for what seems to be"+
			" putting away laundered items."
		]));
		set_exits(([ "southwest" : ROOMDIR"study",
				 "southeast" : ROOMDIR"kitchen",
				 "down" : ROOMDIR"work1"
		 ]));
}