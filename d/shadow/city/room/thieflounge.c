//Titania (6/30/2019)
//The Thief Guild Lounge, Shadow
//Designed by Kiyoshi

#include <std.h>
#include "../defs.h"
inherit "/std/bounty.c";

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_climate("temperate");
   set_name("The Guild Lounge, Shadow");
   set_short("%^BOLD%^%^WHITE%^T%^RESET%^h%^BOLD%^%^BLACK%^e "+
   "%^WHITE%^G%^RESET%^u%^BOLD%^%^BLACK%^ild "+ 
   "%^WHITE%^L%^RESET%^o%^BOLD%^%^BLACK%^unge%^RESET%^");
   set_long("%^RESET%^%^CYAN%^This room is an eyesore of extravagance. "+ 
   "A huge %^ORANGE%^t%^RED%^a%^ORANGE%^b%^RED%^l%^ORANGE%^e "+ 
   "%^CYAN%^dominates the center of the room, surrounded by a "+ 
   "series of mismatched yet finely wrought %^ORANGE%^chairs%^CYAN%^. "+ 
   "Around and below the table, the stone floor has been covered "+ 
   "with a %^BOLD%^%^RED%^d%^MAGENTA%^e%^RED%^e%^RESET%^%^RED%^p "+ 
   "%^BOLD%^c%^MAGENTA%^a%^RED%^r%^RESET%^%^RED%^p%^BOLD%^e%^MAGENTA%^t "+ 
   "%^RESET%^%^CYAN%^that muffles almost all sound. The walls are "+ 
   "covered in %^BOLD%^%^BLACK%^o%^RESET%^d%^BOLD%^d%^RESET%^s "+ 
   "%^CYAN%^and %^GREEN%^e%^BOLD%^n%^ORANGE%^d%^GREEN%^s%^RESET%^%^CYAN%^, "+ 
   "%^ORANGE%^k%^BOLD%^n%^WHITE%^i%^ORANGE%^c%^RESET%^k "+ 
   "%^ORANGE%^kn%^BOLD%^a%^WHITE%^c%^ORANGE%^k%^RESET%^%^ORANGE%^s "+ 
   "%^CYAN%^that are sometimes labeled with small brass plaques "+ 
   "and other times left to mystery, interspersed "+ 
   "%^YELLOW%^c%^WHITE%^a%^RESET%^n%^BOLD%^dl%^RESET%^e "+ 
   "%^BOLD%^h%^RESET%^old%^BOLD%^%^BLACK%^ers "+ 
   "%^RESET%^%^CYAN%^that shed a soft luminescence. "+ 
   "One lone corner has been left largely "+ 
   "%^BOLD%^%^BLACK%^empty%^RESET%^%^CYAN%^. A simple "+ 
   "%^BOLD%^%^BLACK%^cl%^WHITE%^o%^BLACK%^th m%^WHITE%^a%^BLACK%^sk "+ 
   "%^RESET%^%^CYAN%^hangs loosely from the corner, "+ 
   "and all nearby candles have been snuffed out."+
   "\n%^BOLD%^There is a board here, accompanied by a small sign.\n");
   set_smell("default","%^RESET%^%^ORANGE%^The room smells of fine tobacco.%^RESET%^");
   set_listen("default","%^RESET%^%^CYAN%^You can hear the whispers of some distant conversation.%^RESET%^");
   set_items(([
      "table" : "%^RESET%^%^CYAN%^Crafted of "+ 
	  "%^ORANGE%^fi%^RED%^n%^ORANGE%^e o%^RED%^a%^ORANGE%^k%^CYAN%^, "+ 
	  "this table stands on legs carved to resemble draconic "+ 
	  "limbs, ending in clawed talons that pierce the rich carpet "+ 
	  "below. A glossy layer of "+ 
	  "%^BOLD%^%^BLACK%^p%^RESET%^o%^BOLD%^li%^RESET%^s%^BOLD%^%^BLACK%^h "+ 
	  "%^RESET%^%^CYAN%^reveals the intricate "+ 
	  "%^ORANGE%^g%^RED%^r%^ORANGE%^a%^RED%^i%^ORANGE%^n %^CYAN%^of "+ 
	  "the %^ORANGE%^w%^RED%^o%^ORANGE%^o%^RED%^d%^CYAN%^, "+ 
	  "only broken by an intricate carving along the perimeter "+ 
	  "of %^BOLD%^%^BLACK%^cl%^WHITE%^o%^BLACK%^aked m%^WHITE%^e%^BLACK%^n "+ 
	  "%^RESET%^%^CYAN%^stealing from the man before them, ad infinitum.%^RESET%^",
      ({"chair","chairs"}) : "%^RESET%^%^CYAN%^No two "+ 
	  "%^ORANGE%^chairs %^CYAN%^are alike, though "+ 
	  "all of them feature "+ 
	  "%^ORANGE%^f%^BOLD%^a%^WHITE%^n%^ORANGE%^t%^RESET%^%^ORANGE%^a%^BOLD%^s%^WHITE%^t%^ORANGE%^i%^RESET%^%^ORANGE%^c "+ 
	  "%^CYAN%^decorations in their creation. "+ 
	  "Many feature ornamentation in %^BOLD%^%^BLACK%^s%^RESET%^il%^BOLD%^v%^RESET%^e%^BOLD%^%^BLACK%^r%^RESET%^%^CYAN%^, "+ 
	  "%^YELLOW%^g%^WHITE%^o%^ORANGE%^ld%^RESET%^%^CYAN%^, "+ 
	  "and %^BOLD%^%^GREEN%^f%^ORANGE%^i%^GREEN%^n%^RESET%^%^GREEN%^e "+ 
	  "%^BOLD%^%^RED%^g%^MAGENTA%^e%^RED%^m%^RESET%^%^RED%^s%^CYAN%^, "+ 
	  "save for one particularly large chair whose only feature is a "+ 
	  "%^BOLD%^%^BLACK%^mask %^RESET%^%^CYAN%^carved in relief "+ 
	  "on the back.%^RESET%^",
      ({"floor","carpet"}) : "%^RESET%^%^CYAN%^Below the "+ 
	  "%^ORANGE%^t%^RED%^a%^ORANGE%^b%^RED%^l%^ORANGE%^e %^CYAN%^and "+ 
	  "spreading for several feet in each direction is a "+ 
	  "very old, yet very %^RED%^e%^BOLD%^l%^MAGENTA%^e%^RED%^g%^RESET%^%^RED%^a%^BOLD%^n%^MAGENTA%^t "+ 
	  "%^RED%^c%^RESET%^%^RED%^a%^BOLD%^r%^MAGENTA%^p%^RED%^e%^RESET%^%^RED%^t%^CYAN%^. "+ 
	  "Faded with age, the detail and interweaving patterns are still "+ 
	  "impressive. It is a deep carpet, and the sound of your "+ 
	  "footsteps are %^BLUE%^swallowed %^CYAN%^whole.%^RESET%^",
      ({"odds","ends","knick knacks"}) : "%^RESET%^%^CYAN%^The walls are covered "+ 
	  "in strange %^BOLD%^%^WHITE%^i%^RESET%^t%^ORANGE%^e%^BOLD%^m%^RESET%^%^ORANGE%^s%^CYAN%^, "+ 
	  "some of high value and yet many of mundane origin. "+ 
	  "Broken %^BOLD%^%^BLACK%^lo%^RESET%^c%^BOLD%^k%^BLACK%^s%^RESET%^%^CYAN%^, "+ 
	  "an odd %^ORANGE%^k%^BOLD%^e%^RESET%^%^ORANGE%^y%^CYAN%^, "+ 
	  "several %^GREEN%^g%^BOLD%^e%^RESET%^%^GREEN%^m%^BOLD%^m%^ORANGE%^e%^GREEN%^d "+ 
	  "%^MAGENTA%^b%^RED%^a%^MAGENTA%^u%^RESET%^%^MAGENTA%^bl%^BOLD%^e%^RESET%^%^MAGENTA%^s%^CYAN%^, "+ 
	  "and a singular rift key are among the collection. "+ 
	  "Glancing at a few of the "+ 
	  "%^ORANGE%^p%^BOLD%^l%^RESET%^%^ORANGE%^aq%^BOLD%^u%^RESET%^%^ORANGE%^e%^BOLD%^s%^RESET%^%^CYAN%^, "+ 
	  "you realize that each one of these is a trophy, "+ 
	  "a souvenir of some grand heist perpetrated by "+ 
	  "members of the guild. A small feather symbol stands out.%^RESET%^",
	  ({"corner","mask"}) : "%^RESET%^%^CYAN%^Not much stands out "+ 
	  "about the mask. It is of %^BOLD%^%^BLACK%^bl%^WHITE%^a%^BLACK%^ck "+ 
	  "cl%^WHITE%^o%^BLACK%^th%^RESET%^%^CYAN%^, "+ 
	  "with two eye-holes cut out, and hangs loosely. "+ 
	  "This corner of the room is hard to see, due to the "+ 
	  "lack of candlelight, but there appears to be a small "+ 
	  "%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^st%^RESET%^%^ORANGE%^-%^BOLD%^%^BLACK%^ir%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^n "+ 
	  "b%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^wl %^RESET%^%^CYAN%^on the floor. "+ 
	  "Closer inspection shows there is a large pile of "+ 
	  "%^YELLOW%^c%^WHITE%^o%^ORANGE%^in%^WHITE%^s %^RESET%^%^CYAN%^within, "+ 
	  "and the rim of the bowl has been imprinted with "+ 
	  "%^BOLD%^%^WHITE%^%^BLACK%^Th%^WHITE%^e "+ 
	  "%^BLACK%^Sh%^WHITE%^a%^BLACK%^d%^WHITE%^o%^BLACK%^w%^RESET%^%^CYAN%^'%^BOLD%^%^BLACK%^s "+ 
	  "D%^WHITE%^u%^BLACK%^e%^WHITE%^%^RESET%^%^CYAN%^.%^RESET%^",
	  ({"feather","symbol"}) : "There's a small plaque beneath the sigil. Maybe you can read it?",
      ({"sign","board"}) : "%^RESET%^%^ORANGE%^The board is a list of bounties, and the sign details its use. You can read either for more details.%^RESET%^",
      "plaques" : "%^RESET%^%^ORANGE%^There are names and dates printed on plaques near most of the knick knacks and trophies, but there is one lone plaque that stands alone. It is imprinted with the image of a hand, and an arrow pointing downwards.%^RESET%^",
   ]));
   set_exits(([
      "bar" : ROOMS"bestiary",
	  "fence" : ROOMS"thieffence",
	  "training" : "/d/shadow/thief_training/room/entrance",
   ]));
}

void init(){
    ::init();
	add_action("make","make");
	add_action("read","read");
}

int make(string str){
	if(str != "thief sign") return notify_fail("Make what?\n");
	if(TP->query_invis()){
	tell_object(TP, "You sign to the room that you are a thief.");
	return 1;
}
	if(!TP->is_class("thief") && !TP->is_class("assassin") &&
	!TP->is_class("bard")) {
	tell_object(TP, "%^BOLD%^%^BLACK%^Facing a darkened corner, you make a subtle hand gesture and find yourself moved.%^RESET%^");
	tell_room(ETP, "%^BOLD%^%^BLACK%^"+TPQCN+" faces a darkened corner and makes a subtle hand gesture before vanishing.%^RESET%^", TP);
	TP->move_player(ROOMS"sewer16");
} else {
	tell_object(TP, "%^BOLD%^%^BLACK%^Facing a darkened corner, you make a subtle hand gesture and find yourself moved.%^RESET%^");
	if(random(40) > (TP->query_stats("dexterity") +
	TP->query_stats("intelligence")))
	tell_room(ETP, "%^BOLD%^%^BLACK%^"+TPQCN+" faces a darkened corner and makes a subtle hand gesture before vanishing.%^RESET%^", TP);
	TP->move(ROOMS"sewer16");
	TP->describe_current_room(1);
}
return 1;
}

