#include <std.h>
#include "../keep.h"

inherit DUNGEON;

void create()
{
    	::create();
    	set_short("%^BOLD%^%^WHITE%^Marble Chamber%^RESET%^");
    
   	set_long("%^BOLD%^%^WHITE%^You find yourself in a massive chamber made "+
	"entirely from %^BOLD%^%^BLACK%^dull marble%^BOLD%^%^WHITE%^, etched "+
	"with numerous %^CYAN%^hieroglyphic symbols%^BOLD%^%^WHITE%^.  A very "+
	"thick and %^RESET%^%^BLUE%^cold %^BOLD%^%^BLACK%^darkness%^BOLD%^"+
	"%^WHITE%^ lingers here, permeating your very %^RED%^being%^BOLD%^"+
	"%^WHITE%^.  You have found yourself in an obviously very unnatural and "+
	"very %^RED%^evil%^BOLD%^%^WHITE%^ dwelling place of creatures you hope not to "+
	"encounter.  Looking down you notice that the floor of this chamber is littered "+
	"with %^BOLD%^%^BLACK%^bones%^BOLD%^%^WHITE%^, some of which still have bits and "+
	"pieces of %^RED%^flesh%^BOLD%^%^WHITE%^ attached.  Directly in the center of this "+
	"chamber is the beginning of what appears to be a very narrow stairwell.  Inset into "+
	"the western wall is a massive %^BOLD%^%^BLACK%^marble door%^BOLD%^%^WHITE%^ and "+
	"an opening in the northern wall leads into darkness.%^RESET%^\n");

    	set_exits(([
		"stairwell": KEEPR + "blacktonguelair5",
		"north" : KEEPR + "blacktonguelair7","west" : KEEPR + "jail1",
    	] ));
	set_items(([
		({"hieroglyphics","symbols"}) : "%^BOLD%^%^BLACK%^These symbols decorate "+
		"the northern, southern, and eastern walls of the room.  Which ones do "+
		"you want to look at?%^RESET%^",
		"bones" : "%^BOLD%^%^WHITE%^These bones are obviously the remains "+
		"of the meal or several meals of some type of beast.  Some of them "+
		"still have pieces of flesh attached, causing you to believe that the "+
		"meals were rather recent.%^RESET%^",
		"flesh" : "%^RED%^There are still bits and pieces of flesh on some "+
		"of the bones that lay here.%^RESET%^",
		"darkness" : "%^BOLD%^%^BLACK%^This darkness is thick and very "+
		"cold.  It permeates your being, soaking into you, and sending "+
		"chills through your body.  You fear what may be concealed by it as "+
		"growls echo from deep within.%^RESET%^",
		"evil" : "%^RED%^Yes... evil and evil alone could dwell in this "+
		"place...%^RESET%^",
		"being" : "%^RED%^Your very being is assaulted by this "+
		"%^RESET%^%^BLUE%^cold%^RED%^, thick, darkness.%^RESET%^",
		"marble" : "%^BOLD%^%^BLACK%^This entire corridor is made from dull "+
		"marble.  It is etched with numerous %^RESET%^%^CYAN%^hieroglyphic "+
		"symbols%^BOLD%^%^BLACK%^.%^RESET%^",
		"floor" : "%^BOLD%^%^BLACK%^The floor of this corridor is littered "+
		"with the %^BOLD%^%^WHITE%^bones%^BOLD%^%^BLACK%^ of "+
		"various creatures.%^RESET%^",
		({"walls","wall"}) : "%^BOLD%^%^WHITE%^The eastern, northern, and "+
		"southern walls of this room are decorated with %^CYAN%^"+
		"hieroglyphics%^BOLD%^%^WHITE%^.  A door with a keyhole in "+
		"the shape of a skull is inset directly in the center of the "+
		"western wall and a corridor extends into darkness on the "+
		"northern wall.%^RESET%^",
		({"east hieroglyphics","east hieroglyphic","east symbol",
		"east symbols","eastern symbols","east",
		"eastern hieroglyphics"}) : "%^CYAN%^These hieroglyphics show "+
		"a %^RED%^dark skinned elf%^CYAN%^ bowing before the throne of "+
		"a massive wolf-like creature.%^RESET%^",
		({"south hieroglyphics","south hieroglyphic","south symbol",
		"south symbols","south","southern symbols",
		"southern hieroglyphics"}) : "%^CYAN%^These hieroglyphics show "+
		"an %^RED%^ogre%^CYAN%^ bowing before the throne of a massive "+
		"wolf-like creature.%^RESET%^",
		({"north hieroglyphics","north hieroglyphic",
		"north symbol","north symbols","north",
		"northern symbols","northern hieroglyphics"}) : "%^CYAN%^These "+
		"hieroglyphics show a %^RED%^half drow%^CYAN%^ bowing before "+
		"the throne of a massive wolf-like creature.%^RESET%^",
		"corridor" : "%^BOLD%^%^BLACK%^This corridor extends into "+
		"darkness to the north.%^RESET%^",
	] ));
	set_door("marble door",KEEPR + "jail1","west","odd skull","lock");
	set_string("marble door", "open", "%^BOLD%^%^BLACK%^The door opens with "+
	"suprising ease.%^RESET%^");
	set_locked("marble door",1,"lock");
	set_lock_description("marble door","lock","This is a very "+
	"large lock.  The keyhole is in the shape of some type of "+
	"oddly shaped %^BOLD%^%^WHITE%^skull%^RESET%^.");
	lock_difficulty("marble door",-101,"lock");
	set_door_description("marble door","%^BOLD%^%^BLACK%^This heavy "+
	"marble door is inset directly in the center of the western wall.  "+
	"The only obvious way to open it is to push on it.  The keyhole "+
	"for the door is directly in the center of it, in the shape of an "+
	"oddly shaped skull.  It is impossible to tell how thick it is.%^RESET%^");

}

