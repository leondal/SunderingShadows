//tomb  - Essyllis - May - 2014


#include <std.h>
#include "../lgnoll.h"

inherit CROOM;
int hammerx;

void create() {

    set_repop(70);
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
	hammerx = 0;
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_name("tomb");
    set_short("A paladin's tomb.");
    set_long("%^BOLD%^You have entered a large burial chamber. Like the granite room you just came from, "+
	"this chamber is clearly not of %^BLACK%^gn%^RESET%^%^GREEN%^o%^BOLD%^%^BLACK%^ll%^RESET%^%^GREEN%^i%^BOLD%^%^BLACK%^sh "+
	"%^WHITE%^making. The walls here are made from polished marble in pr%^ORANGE%^i%^WHITE%^st%^ORANGE%^i%^WHITE%^ne "+
	"c%^ORANGE%^o%^WHITE%^nd%^ORANGE%^i%^WHITE%^t%^ORANGE%^i%^WHITE%^on. Clearly the %^BLACK%^gn%^RESET%^%^GREEN%^o%^BOLD%^%^BLACK%^lls "+
	"%^WHITE%^never made it in here. The room itself is perfect a square, each wall 30 feet long and 15 feet tall. In each of the "+
	"corners of the chamber a large %^ORANGE%^braz%^WHITE%^i%^ORANGE%^er %^WHITE%^is burning with what seem to be a "+
	"%^ORANGE%^n%^RED%^e%^ORANGE%^ver-dr%^RED%^y%^ORANGE%^ing fl%^RED%^a%^ORANGE%^me%^WHITE%^, keeping the chamber "+
	"both lit and warm. In the center of the room a large %^CYAN%^sarcophagus %^WHITE%^stands as the only other thing in the chamber.%^RESET%^\n");
    set_smell("default","%^GREEN%^A faint taint of old dust hangs in the still air%^RESET%^");
    set_listen("default","%^ORANGE%^The only sounds is the soft crackling of fire from the %^YELLOW%^braz%^WHITE%^i%^ORANGE%^ers.%^RESET%^");
	set_exits((["south":ROOMS"d1"]));
    set_items
    (([	
        ({"floor", "ground"}) : "A thick layer of dust covers the marble floor, obviously uninterrupted for many years.",
        ({"wall", "walls"}) : "%^BOLD%^%^YELLOW%^Flames %^WHITE%^from the %^YELLOW%^braz%^WHITE%^i%^ORANGE%^ers%^WHITE%^ send %^BLACK%^shadows%^WHITE%^ chasing over the pristine marble walls.",
        ({"brazier","braziers"}) : "%^BOLD%^The %^ORANGE%^braz%^WHITE%^i%^ORANGE%^ers %^WHITE%^bear the symbol of a %^BLACK%^metal-gauntlet %^WHITE%^with a %^CYAN%^watchful %^RESET%^%^CYAN%^eye %^BOLD%^%^WHITE%^on the back of the hand. The %^RED%^fl%^ORANGE%^a%^RED%^m%^ORANGE%^e%^RED%^s %^WHITE%^seem to be burning without fuel.%^RESET%^",
		({"sarcophagus"}) : ((:TO,"lsarcophagus":)),
		({"plaque"}) : ({"%^ORANGE%^This is a golden plaque with words edged into it. You could read it.","%^YELLOW%^Here lies the mortal remains of Carnac the Slayer of Titans.","common"}),
		
    ]));

	 

	
	set_search("floor","%^ORANGE%^The dust is almost a inch thick. No one has been here for a very long time.");
	set_search("corpse","All these gnoll corpses. They weren't just thrown down here. There are obvious signs of combat on all of them.");
	set_search("walls","%^BOLD%^%^WHITE%^Pristine and made of pure marble. But otherwise nothing.");
	set_search("sarcophagus","The hands of the Knight on the sarcophagus seem to be missing a weapon.");
	
}	




void init(){
	::init();
	add_action("place","place");
	add_action("take","take");
}


int place(string str){
	object hammerobj;
	hammerobj = present("hammer",TP);
	if(str != "hammer in knights hands"){notify_fail("Place hammer in knights what?"); return 0;}
	if(!objectp(hammerobj)){ notify_fail("You don't have a hammer to place anywhere"); return 0;}
	if(hammerx){notify_fail("The knight already has a hammer in his hands."); return 0;}
	if(base_name(hammerobj) != OBJ"commandohammer"){notify_fail("Nothing happens as you place this hammer in the knight's hands, so you take it back."); return 0;}
	hammerx=1;
	tell_object(TP,"%^ORANGE%^You walk up and place the Warhammer in the hands of the knight laying on the sarcophagus.");
	tell_room(ETP,""+TP->QCN+"%^RESET%^%^ORANGE%^ walks up and places the Warhammer in the hands of the knight laying on the sarcophagus.",TP);
	hammerobj->remove();
	tell_object(TP,"%^BOLD%^A br%^ORANGE%^i%^WHITE%^ght l%^ORANGE%^i%^WHITE%^g%^ORANGE%^h%^WHITE%^t b%^ORANGE%^l%^WHITE%^i%^ORANGE%^n%^WHITE%^d%^ORANGE%^s %^WHITE%^you momentarily and when you can see again, the %^ORANGE%^hammer %^WHITE%^in the knight's hands has transformed into breath-taking %^RESET%^%^CYAN%^Warhammer %^BOLD%^%^WHITE%^made of %^CYAN%^m%^WHITE%^i%^CYAN%^thr%^WHITE%^i%^CYAN%^l%^WHITE%^!");
	tell_room(ETP,"%^BOLD%^As %^RESET%^"+TP->QCN+" %^BOLD%^places the %^BLACK%^hammer %^WHITE%^in the knight's hands, a %^ORANGE%^br%^WHITE%^i%^ORANGE%^ght l%^WHITE%^i%^ORANGE%^ght b%^WHITE%^l%^ORANGE%^i%^WHITE%^n%^ORANGE%^ds %^WHITE%^you ... When you can see again the weapon in the knight's hands has transformed into a %^RESET%^%^CYAN%^beautiful %^BOLD%^M%^WHITE%^i%^CYAN%^thr%^WHITE%^i%^CYAN%^l %^RESET%^%^CYAN%^warhammer%^BOLD%^%^WHITE%^.",TP);
	
		return 1;}

int take(string str){
	if(!str){notify_fail("Take what?");return 0;}
	if(str != "warhammer"){notify_fail("You cannot take that!");return 0;}
	if(!hammerx){notify_fail("The knight has no weapon to take");return 0;}
	hammerx=0;
	tell_object(TP,"%^ORANGE%^You take the %^BOLD%^%^CYAN%^beautiful %^RESET%^%^CYAN%^warhammer %^ORANGE%^from the hands of the %^BOLD%^knight.");
	tell_room(ETP,""+TP->QCN+" %^ORANGE%^takes the %^BOLD%^%^CYAN%^beautiful %^RESET%^%^CYAN%^warhammer %^ORANGE%^from the hands of the %^BOLD%^knight %^RESET%^%^ORANGE%^on the %^BOLD%^%^BLACK%^sarcophagus.",TP);
	new(OBJ"titanbane")->move(TP);
	return 1;
}	

string lsarcophagus(){
	
	if(hammerx){
	return("%^ORANGE%^The %^BOLD%^%^WHITE%^sarcophagus %^RESET%^%^ORANGE%^is located in the middle of the chamber. "+
	"It is made from what looks to be one solid piece of %^BOLD%^%^WHITE%^marble%^RESET%^%^ORANGE%^. The lid "+
	"%^RESET%^%^ORANGE%^is almost 6 inches thick and would weight far to much "+
	"to move, let alone open. On top of the structure a remarkably detailed "+
	"%^BOLD%^%^WHITE%^marble c%^CYAN%^a%^WHITE%^rvi%^CYAN%^n%^WHITE%^g %^RESET%^%^ORANGE%^of a full-scale "+
	"%^BOLD%^knight %^RESET%^%^ORANGE%^can be seen. He is carved in %^BOLD%^%^BLACK%^full-plate %^RESET%^%^ORANGE%^armor "+
	"with helmet and therefore gives no personal features except the %^BOLD%^%^CYAN%^symbol%^RESET%^ %^ORANGE%^of %^BOLD%^%^CYAN%^a right "+
	"hand gauntlet held upright with its palm forward %^RESET%^%^ORANGE%^which is carved onto the chest of the plate. On "+
	"the base of the sarcophagus a %^BOLD%^g%^RESET%^%^ORANGE%^o%^BOLD%^ld%^RESET%^%^ORANGE%^e%^BOLD%^n "+
	"pl%^RESET%^%^ORANGE%^a%^BOLD%^q%^RESET%^%^ORANGE%^u%^BOLD%^e %^RESET%^%^ORANGE%^has been attached. The hands "+
	"of the %^BOLD%^knight %^RESET%^%^ORANGE%^are folded over his stomach where he is holding a "+
	"%^BOLD%^%^CYAN%^beautiful %^RESET%^%^CYAN%^warhammer.");
	}
	
	return("%^ORANGE%^The %^BOLD%^%^WHITE%^sarcophagus %^RESET%^%^ORANGE%^is located in the middle of the chamber. "+
	"It is made from what looks to be one solid piece of %^BOLD%^%^WHITE%^marble%^RESET%^%^ORANGE%^. The lid "+
	"is almost 6 inches thick and would weight far to much to move, "+
	"let alone open. On top of the structure a remarkably detailed %^BOLD%^%^WHITE%^marble "+
	"c%^CYAN%^a%^WHITE%^rvi%^CYAN%^n%^WHITE%^g %^RESET%^%^ORANGE%^of a full-scale %^BOLD%^knight %^RESET%^%^ORANGE%^can "+
	"be seen. He is carved in %^BOLD%^%^BLACK%^full-plate %^RESET%^%^ORANGE%^armor with helmet and therefore gives no "+
	"personal features except the %^BOLD%^%^CYAN%^symbol %^RESET%^%^ORANGE%^of %^BOLD%^%^CYAN%^a right hand gauntlet held"+
	" upright with its palm forward %^RESET%^%^ORANGE%^which is carved onto the chest of the plate. On the base of the "+
	"sarcophagus a %^BOLD%^g%^RESET%^%^ORANGE%^o%^BOLD%^ld%^RESET%^%^ORANGE%^e%^BOLD%^n "+
	"pl%^RESET%^%^ORANGE%^a%^BOLD%^q%^RESET%^%^ORANGE%^u%^BOLD%^e %^RESET%^%^ORANGE%^has been attached. The hands of the "+
	"%^BOLD%^knight %^RESET%^%^ORANGE%^are folded over his stomach in a way that %^CYAN%^suggests %^ORANGE%^that he should "+
	"be %^CYAN%^holding %^ORANGE%^a %^CYAN%^weapon%^ORANGE%^.");
	
}

void reset(){
   ::reset();
   hammerx=0;
   switch(random(6)){
      case 0..2:  tell_room(TO,"%^BOLD%^%^BLACK%^The granite flakes in the walls %^BOLD%^%^WHITE%^shimmers%^BLACK%^ in the dim light.");
               break;
      case 3..4:  tell_room(TO,"%^ORANGE%^You hear noises from the guard room high above you.");
               break;
      case 5:  tell_room(TO,"%^MAGENTA%^A loud %^BOLD%^%^BLACK%^CRACK %^RESET%^%^MAGENTA%^comes from one of the granite walls. But there is no damage to be seen anywhere.");
               break;
         }
}
