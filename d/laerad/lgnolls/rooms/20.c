//guardroomoom Template  - Essyllis - May - 2014


#include <std.h>
#include "../lgnoll.h"

inherit CROOM;

object ob;
int floorx, ladderx, lanternx;

void pick_critters();



void create() {
    pick_critters();
floorx=0;
ladderx=0;
lanternx=0;
    set_repop(55);
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",0);
    set_name("Guard room");
    set_short("Gnoll guard room.");
    set_long((:TO,"long_desc":));
    set_smell("default","%^ORANGE%^It smells badly of %^RED%^r%^MAGENTA%^o%^RED%^tt%^MAGENTA%^e%^RED%^n m%^MAGENTA%^e%^RED%^at %^ORANGE%^and %^BOLD%^%^BLACK%^o%^RESET%^%^GREEN%^i%^BOLD%^%^BLACK%^ly m%^RESET%^%^GREEN%^u%^BOLD%^%^BLACK%^sk%^RESET%^");
    set_listen("default","%^GREEN%^The floor creaks and gives as you walk on it.%^RESET%^");
	set_exits((["out":ROOMS"6"]));
    set_items
    (([	
        ({"floor", "ground"}) : "The floor here is surprisingly clean of debris and dirt. Some floorboards seem loose as well.",
		({"floorboards","floor boards","floorboard","floor board"}):"Many of the floorboards seem relatively new, as if they have been replaced recently.",
        ({"wall", "walls"}) : "%^RESET%^%^ORANGE%^The walls are made from solid timbers with shooting scars where one could easily fire a crossbow from.",
        ({"lantern"}) : "%^ORANGE%^ The %^YELLOW%^l%^WHITE%^a%^ORANGE%^nt%^WHITE%^e%^ORANGE%^rn%^RESET%^%^ORANGE%^ looks suspiciously %^BOLD%^%^CYAN%^Asgardian%^RESET%^%^ORANGE%^ in design.",
		({"weapons", "weapon racks", "weapon rack"}) : "%^ORANGE%^The %^BOLD%^%^BLACK%^we%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^pons %^RESET%^%^ORANGE%^in the racks are in good condition. But they look like something you would expect to find on a %^CYAN%^knight %^ORANGE%^or %^CYAN%^guard %^ORANGE%^from %^BOLD%^%^CYAN%^Asgard!",
		({"armors", "armor rack", "armor racks"}) : "%^ORANGE%^The %^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^rm%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^r racks are filled with good quality %^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^rm%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^rs, ranging from %^BOLD%^le%^RESET%^%^ORANGE%^a%^BOLD%^th%^RESET%^%^ORANGE%^e%^BOLD%^r %^RESET%^%^ORANGE%^armor to %^WHITE%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^. All of them are wearing the symbol of %^BOLD%^%^CYAN%^Asgard %^RESET%^%^ORANGE%^on them.",
    ]));
	set_search("default","Everything in here is dirty and smells of the gnolls");
	set_search("floor","Some of the floorboards have been replaced recently. They creak whenever you step on them.");
	set_search("floorboard","The floorboards have been replaced in all haste it seems. It wouldn't be much of a challenge to 'lift' the 'floorboards'");
	set_search("floor board","The floorboards have been replaced in all haste it seems. It wouldn't be much of a challenge to 'lift' the 'floorboards'");
	set_search("floorboards","The floorboards have been replaced in all haste it seems. It wouldn't be much of a challenge to 'lift' the 'floorboards'");
	set_search("floor boards","The floorboards have been replaced in all haste it seems. It wouldn't be much of a challenge to 'lift' the 'floorboards'");
	set_search("lantern","This Asgardian looking lantern hangs from the ceiling on a simple hook, it would be easy to 'take' it down.");
}

void init(){
	::init();
	add_action("lift","lift");
	add_action("lower","lower");
	add_action("take","take");
}

string long_desc(){
	if(floorx){
		if(lanternx){
			return("%^ORANGE%^This large guard room is in better shape than anything else in the camp. "+
	"Two large tables are placed at the east and west walls, one with various %^MAGENTA%^items %^ORANGE%^and "+
	"the other with %^RED%^f%^MAGENTA%^o%^RED%^od%^ORANGE%^. Along the west wall %^BOLD%^%^BLACK%^we%^RESET%^a%^BOLD%^%^BLACK%^pon "+
	"%^RESET%^%^ORANGE%^racks have been setup with various weapons. %^BOLD%^%^WHITE%^A%^BLACK%^rm%^WHITE%^o%^BLACK%^r %^RESET%^%^ORANGE%^racks "+
	"fill the east wall. Some floorboards in the middle of the room have been removed."+
	" Underneath them a %^BOLD%^%^BLACK%^very deep circular hole%^RESET%^%^ORANGE%^ can be seen.%^RESET%^\n");
		}
		return("%^ORANGE%^This large guard room is in better shape than anything else in the camp. "+
	"Two large tables are placed at the east and west walls, one with various %^MAGENTA%^items %^ORANGE%^and "+
	"the other with %^RED%^f%^MAGENTA%^o%^RED%^od%^ORANGE%^. Along the west wall %^BOLD%^%^BLACK%^we%^RESET%^a%^BOLD%^%^BLACK%^pon "+
	"%^RESET%^%^ORANGE%^racks have been setup with various weapons. %^BOLD%^%^WHITE%^A%^BLACK%^rm%^WHITE%^o%^BLACK%^r %^RESET%^%^ORANGE%^racks "+
	"fill the east wall. From the ceiling a large %^BOLD%^l%^WHITE%^a%^ORANGE%^nt%^WHITE%^e%^ORANGE%^rn i%^WHITE%^ll%^ORANGE%^u%^WHITE%^m%^ORANGE%^i%^WHITE%^n%^ORANGE%^a%^WHITE%^t%^ORANGE%^e%^WHITE%^s "+
	"%^RESET%^%^ORANGE%^the room at %^BOLD%^%^BLACK%^night%^RESET%^%^ORANGE%^. Some floorboards in the middle of the room have been removed."+
	" Underneath them a %^BOLD%^%^BLACK%^very deep circular hole%^RESET%^%^ORANGE%^ can be seen.%^RESET%^\n");
	}
	if(lanternx){
		return("%^ORANGE%^This large guard room is in better shape than anything else in the camp. "+
	"Two large tables are placed at the east and west walls, one with various %^MAGENTA%^items %^ORANGE%^and "+
	"the other with %^RED%^f%^MAGENTA%^o%^RED%^od%^ORANGE%^. Along the west wall %^BOLD%^%^BLACK%^we%^RESET%^a%^BOLD%^%^BLACK%^pon "+
	"%^RESET%^%^ORANGE%^racks have been setup with various weapons. %^BOLD%^%^WHITE%^A%^BLACK%^rm%^WHITE%^o%^BLACK%^r %^RESET%^%^ORANGE%^racks "+
	"fill the east wall.%^RESET%^\n");
	}
	else{
	return("%^ORANGE%^This large guard room is in better shape than anything else in the camp. "+
	"Two large tables are placed at the east and west walls, one with various %^MAGENTA%^items %^ORANGE%^and "+
	"the other with %^RED%^f%^MAGENTA%^o%^RED%^od%^ORANGE%^. Along the west wall %^BOLD%^%^BLACK%^we%^RESET%^a%^BOLD%^%^BLACK%^pon "+
	"%^RESET%^%^ORANGE%^racks have been setup with various weapons. %^BOLD%^%^WHITE%^A%^BLACK%^rm%^WHITE%^o%^BLACK%^r %^RESET%^%^ORANGE%^racks "+
	"fill the east wall. From the ceiling a large %^BOLD%^l%^WHITE%^a%^ORANGE%^nt%^WHITE%^e%^ORANGE%^rn i%^WHITE%^ll%^ORANGE%^u%^WHITE%^m%^ORANGE%^i%^WHITE%^n%^ORANGE%^a%^WHITE%^t%^ORANGE%^e%^WHITE%^s "+
	"%^RESET%^%^ORANGE%^the room at %^BOLD%^%^BLACK%^night%^RESET%^%^ORANGE%^.%^RESET%^\n");
	}
    }

int take(string str){
	if(!str){notify_fail("What do you want to take?"); return 0;}
	if(present("gnoll",TO)) {notify_fail("%^BOLD%^%^BLACK%^You really couldn't do that without the gnolls noticing!\n"); return 0;}
	if(lanternx) {notify_fail("Someone already taken the lantern."); return 0;}
	if(str != "lantern"){notify_fail("That isn't something you can take.");return 0;}
	else{
		lanternx=1;
		write("You take the lantern off the hook in the ceiling.");
		tell_room(ETP,""+TP->QCN+" takes the lantern off the hook in the ceiling.",TP);
		new(OBJ"lantern")->move(TP);
		return 1;
	}
}	
	
int lift(string str){
	
	if(!str){ notify_fail("What are you trying to lift? You could 'lift floorboards'?\n"); return 0;}
	if(present("gnoll",TO)) {notify_fail("%^BOLD%^%^BLACK%^ You really couldn't do that without the gnolls noticing!\n"); return 0;}
	if(floorx){ notify_fail("It would seem someone already has lifted the floorboards away."); return 0;}
	else{
	floorx=1;
	write("You start lifting the very loose floorboards away, revealing a very deep circular hole beneath them.");
	tell_room(ETP,""+TP->QCN+" starts lifting away the loose floorboards, revealing a large circular hole beneath them",TP);
	set_search("hole","You kick a little rock into the hole. It takes a few seconds before it reaches the floor, meaning there's at least 60"+
	" feet down. You'll need to %^BOLD%^%^BLACK%^lower a ladder%^RESET%^ if you want to go down there!");
	add_item("hole","%^BOLD%^%^BLACK%^This hole looks deep ... Very deep! The sides are clean and smooth, not even climbing tools would help you here. You'd need something to %^RESET%^lower%^BOLD%^%^BLACK%^ yourself down there");
	return 1;}
}
	
int lower(string str){
	object ladderobj;
	
		if(!str) 		{return notify_fail("Lower what?"); return 0;}
		ladderobj = present("ladder",TP);
		if(!objectp(ladderobj)) 	 {return notify_fail("You cannot lower yourself down there. But perhaps if you had a ladder?"); return 0;}
		if(base_name(ladderobj) != "/d/laerad/lgnolls/obj/ladder"){ notify_fail("This ladder doesn't fit."); return 0;}
		if(ladderx)	 {return notify_fail("It seems like a ladder has already been lowered into the hole!"); return 0;}
		if(!floorx)	 {return notify_fail("You need to lift the floodboards away before you can lower the ladder!"); return 0;}
		ladderx=1;
		write("You start lowering the ladder down into the hole. Luckily the ladder is just long enough to reach the floor below!");
		tell_room(ETP,""+TP->QCN+" lowers the ladder down into the hole in the floor.",TP);
		set_exits((["down":ROOMS"d1","out":ROOMS"6"]));
 		ladderobj->remove();
		return 1;
	}

void reset(){
   ::reset();
   floorx=0;
   ladderx=0;
   lanternx=0;
   switch(random(5)){
      case 0..1:  tell_room(TO,"%^BOLD%^%^BLACK%^You hear a %^ORANGE%^li%^RED%^o%^ORANGE%^n's "+
	  "%^RED%^roar %^BLACK%^followed by the death-cry of a %^RESET%^%^ORANGE%^gnoll.");
               break;
      case 2..3:  tell_room(TO,"%^ORANGE%^A %^CYAN%^gust of wind blows %^ORANGE%^through the "+
	  "camp, lifting the %^BOLD%^%^BLACK%^stink %^RESET%^%^ORANGE%^of %^MAGENTA%^death %^ORANGE%^and "+
	  "%^MAGENTA%^decay %^ORANGE%^for a precious few seconds.");
               break;
      case 4:  tell_room(TO,"%^BOLD%^%^BLACK%^A %^RED%^horrible death cry %^BLACK%^of another of the "+
	  "gnoll's victims can he hear from somewhere in the camp.");
               break;
         }
}


void pick_critters(){
   //if(!present("gnoll")){
   switch(random(3)){
        case 0:   set_monsters(
({MOBS"gnollwarrior",MOBS"gnollpriest"}),({random(2)+1,random(2)+1}) );
                   break;
         case 1:   set_monsters(
({MOBS"gnollwarrior",MOBS"gnollbarb"}),({random(2)+1,random(2)+1}) );
                   break;
         case 2:   set_monsters(
({MOBS"gnollpriest",MOBS"gnollbarb"}),({random(2)+1,random(3)+1}) );
                   break;
         
   }
   }


