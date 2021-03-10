//main_stable.c - working stable for new Seneca
//~Circe~ 11/23/07
#include <std.h>
#include "../seneca.h"
#define MOUNTS "/d/common/mounts/"+

inherit STABLE;

void create(){
  ::create();
  set_terrain(CITY);
  set_travel(PAVED_ROAD);
  set_light(2);
  set_indoors(1);
  set_name("Exotic Animals, Seneca");
  set_short("Exotic Animals, Seneca");
  set_long("%^BOLD%^Exotic Animals, Seneca%^RESET%^\n"+
     "Filled with %^BOLD%^%^BLACK%^iron cages %^RESET%^rather "+
     "than stalls, this stable is perhaps the strangest you've "+
     "seen.  A wide %^ORANGE%^doorway %^RESET%^in the western "+
     "wall is only partially blocked by a half-door.  The top "+
     "half remains open, allowing a view of the %^GREEN%^stable "+
     "grounds %^RESET%^beyond.  There, you occasionally see the "+
     "heads of %^BOLD%^%^BLACK%^elephants%^RESET%^, %^ORANGE%^"+
     "large cats%^RESET%^, and even %^ORANGE%^wild boars %^RESET%^"+
     "pass by!  The mounts sold here are well-trained, but the "+
     "cages stand testament to the care that must be taken with them "+
     "regardless.  Rather than the %^YELLOW%^hay%^RESET%^, %^BOLD%^"+
     "oats%^RESET%^, and %^ORANGE%^carrots %^RESET%^found in most "+
     "stables, this one has an %^CYAN%^icebox %^RESET%^that seems "+
     "to be filled with raw %^RED%^meat%^RESET%^.  A %^ORANGE%^burlap "+
     "sack %^RESET%^labeled '%^BOLD%^%^BLACK%^Truffles%^RESET%^' rests "+
     "among the %^BOLD%^tack %^RESET%^and supplies on %^ORANGE%^wooden "+
     "shelves %^RESET%^placed just west of the door.  It seems the "+
     "stable hands take extra care with these mounts, and all of them "+
     "seem to be in excellent shape.\n\n"+
     "%^RESET%^You can look at the %^MAGENTA%^sign %^RESET%^here "+
     "to see what mounts are for sale.\n");
  set_smell("default","The strong fragrance of hay and musk lingers in the air.");
  set_listen("default","Roars, yawns, and snorts sound all around you.");
  set_exits(([
    "south" : ROOMS"sstreet23",
  ]));
  set_items(([
      ({"cage","cages","iron cage","iron cages"}) : "%^BOLD%^"+
         "%^BLACK%^Tall iron cages with thick bars crowd the stable, "+
         "spaced rather far apart from each other and away from the door.  "+
         "They look quite sturdy, as one would expect given the mounts "+
         "sold here.%^RESET%^",
      ({"doorway","grounds","stable grounds"}) : "The door to the west is "+
         "cut in half, with each part working independently of the other.  "+
         "The top half is opened, allowing a relatively clear view of "+
         "the %^GREEN%^grassy stable grounds %^RESET%^beyond.  Animals "+
         "wander past, obviously out for a bit of exercise.",
      ({"elephant","riding elephant","gray elephant","mottled gray elephant"}) :
         "%^BOLD%^%^BLACK%^Covered with wrinkled m"+
         "%^RESET%^o%^BOLD%^%^BLACK%^t%^RESET%^t%^BOLD%^"+
         "%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^"+
         "gray hide%^BOLD%^%^BLACK%^, this elephant is massive.  "+
         "It has large, thin ears that it flaps often, creating "+
         "a %^CYAN%^breeze%^BLACK%^ to cool the creature.  "+
         "Twin %^WHITE%^ivory tusks %^BLACK%^protrude from either "+
         "side of the prehensile %^RESET%^trunk%^BOLD%^%^BLACK%^.  "+
         "Large %^RESET%^%^ORANGE%^brown eyes %^BOLD%^%^BLACK%^"+
         "with thick lashes survey the scene before the animal, "+
         "belying an intelligence hidden within the massive frame.  "+
         "A %^RESET%^%^ORANGE%^saddle %^BOLD%^%^BLACK%^has been "+
         "placed just below the elephant's head, offering a rider "+
         "a comfortable perch.%^RESET%^",
      ({"boar","riding boar","bristly boar","giant boar","bristly giant boar"}) :
         "%^RESET%^%^ORANGE%^Covered in stiff brown bristles, "+
         "this giant boar has a large head and short, stubby legs.  "+
         "It really doesn't look as if it would be very fast, but "+
         "its compactness and strength likely have their uses.  "+
         "%^RESET%^Tusks %^ORANGE%^protrude about six inches "+
         "from the lower jaw, appearing to be quite nasty weapons.  "+
         "Similar %^RESET%^tusks %^ORANGE%^also extend from the upper "+
         "jaw but bend upwards, and look to be relatively harmless.  "+
         "A saddle has been fitted upon the boar's back, giving a "+
         "rider a place to sit.%^RESET%^",
      ({"jaguar","riding jaguar","spotted jaguar","spotted riding jaguar"}) :
         "%^RESET%^%^ORANGE%^This fantastic creature has sleek "+
         "lines and exquisite %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^"+
         "l%^RESET%^%^ORANGE%^d%^YELLOW%^e%^RESET%^%^ORANGE%^n fur "+
         "combined with powerful muscles.  %^BOLD%^%^BLACK%^Black "+
         "rosettes%^RESET%^%^ORANGE%^, a circle of spots surrounding "+
         "a larger spot, cover the cat's back, while the spots on its "+
         "chest, head, and legs are %^BOLD%^%^BLACK%^solid black%^RESET%^"+
         "%^ORANGE%^.  This jaguar is larger than most, standing about "+
         "five feet at the shoulder and over eight feet in length.  Its "+
         "eyes are a glittering %^YELLOW%^gold%^RESET%^%^ORANGE%^ and "+
         "reveal a predator's intelligence.  Oddly, this one has been "+
         "saddled, as if to allow someone to ride.%^RESET%^",
      ({"tiger","riding tiger","striped tiger","striped riding tiger"}) :
         "%^RESET%^%^ORANGE%^This beautiful animal has sleek "+
         "b%^YELLOW%^a%^WHITE%^n%^BLACK%^d%^RESET%^%^ORANGE%^e"+
         "%^YELLOW%^d %^RESET%^%^ORANGE%^fur.  The face is a deep "+
         "russet across the nose, striped with %^BOLD%^%^BLACK%^black "+
         "%^RESET%^%^ORANGE%^and fading to %^BOLD%^%^WHITE%^white "+
         "%^RESET%^%^ORANGE%^along the neck.  A series of s%^YELLOW%^"+
         "t%^BLACK%^r%^YELLOW%^i%^RESET%^%^ORANGE%^p%^YELLOW%^e%^BLACK%^"+
         "s %^RESET%^%^ORANGE%^runs vertically along the body and rings "+
         "the long tail, which often swishes lazily.  A quick glance "+
         "at this tiger's %^YELLOW%^eyes %^RESET%^%^ORANGE%^and "+
         "%^RESET%^teeth %^ORANGE%^reveal that the animal is anything "+
         "but lazy.  Amazingly, a saddle has been fitted onto the "+
         "breathtaking creature's back, giving a rider a place to sit.%^RESET%^",
      ({"hay","oats","carrots"}) : "You don't see any of those normal "+
         "stable items here.",
      ({"icebox","meat","raw meat"}) : "The icebox is a simple wooden "+
         "construction packed with ice and salt.  It holds raw meat "+
         "for the animals, and it is kept here to help avoid the heat "+
         "in Seneca.",
      ({"sack","burlap sack","truffles","Truffles"}) : "A favorite "+
         "treat of boars, the truffles in the burlap sack are cut "+
         "into pieces so they may be given out a bit at a time.  The "+
         "mushrooms are partially dried, but the boars don't seem to "+
         "mind in the least.",
      ({"tack","supplies","shelves","wooden shelves"}) : "The shelves "+
         "to the west of the door hold saddles, brushes, leather oil, "+
         "bridles, and countless other instruments of grooming and "+
         "tending mounts.  They have been sorted and carefully placed."
  ]));
  set_door("sliding door","/d/attaya/newseneca/rooms/sstreet23","south",0,0);
  set_door_description("sliding door","%^ORANGE%^This wide door "+
     "slides back, leaving a large opening through which to bring "+
     "in mounts.  The door is reinforced with iron bands and has "+
     "an even stronger outer door that can be let down in storms.%^RESET%^");
  set_animal(({"boar","elephant","jaguar","tiger","hippogriff","giant eagle","griffon","pegasus","nightmare"}),({MOUNTS"riding_boar",MOUNTS"riding_elephant",MOUNTS"riding_jaguar",MOUNTS"riding_tiger",MOUNTS"hippogriff",MOUNTS"gianteagle",MOUNTS"flying_griffon",MOUNTS"flying_pegasus",MOUNTS"flying_nightmare"}));
  set_animal_price(({"boar","elephant","jaguar","tiger","hippogriff","giant eagle","griffon","pegasus","nightmare"}),({850,1500,1250,1300,50000,50000,55000,55000,55000}));
  set_stalls(20);
  ::fill_stalls();
   if(query_night()==1){
      set_open("sliding door",0);
      "/d/attaya/newseneca/rooms/sstreet23"->set_open("sliding door",0);
   }else{
      set_open("sliding door",1);
      "/d/attaya/newseneca/rooms/sstreet23"->set_open("sliding door",1);
   }
}

void init(){
	::init();
	add_action("read_sign","read");
}

int read_sign(string str)
{
    if(!str || str != "sign") return 0;
   if(!present("stable hand")){
      tell_object(TP,"The sign seems to be missing.  Perhaps the "+
         "stable hands removed it while they are not working.");
      return 1;
   }
   if(str == "sign") {
      tell_object(TP,"%^BOLD%^This sign tells which mounts are for sale.%^RESET%^\n\n"+
         "      %^ORANGE%^A bristly giant boar%^RESET%^\t\t%^YELLOW%^850 gold\n"+
         "      %^BOLD%^%^BLACK%^A %^BOLD%^%^BLACK%^m%^RESET%^o%^BOLD%^%^BLACK%^t"+
            "%^RESET%^t%^BOLD%^%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^d "+
            "gray riding elephant%^RESET%^\t%^YELLOW%^1500 gold\n"+
         "      %^RESET%^%^ORANGE%^A %^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^p%^RESET%^"+
            "%^ORANGE%^o%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^t%^BOLD%^"+
            "%^BLACK%^e%^RESET%^%^ORANGE%^d riding jaguar%^RESET%^\t\t%^YELLOW%^1250 gold\n"+
         "      %^RESET%^%^ORANGE%^A %^RESET%^%^ORANGE%^sleek %^YELLOW%^r%^RESET%^"+
            "%^ORANGE%^i%^YELLOW%^d%^RESET%^%^ORANGE%^i%^YELLOW%^n"+
            "%^RESET%^%^ORANGE%^g tiger%^RESET%^\t\t%^YELLOW%^1300 gold\n%^RESET%^\n\n"
            "%^RESET%^%^BOLD%^The following mounts are special flying mounts:\n\n"
            "      %^YELLOW%^magnificent %^RESET%^%^BOLD%^winged%^RESET%^ "
            "%^BOLD%^%^BLACK%^hippogriff%^RESET%^\t%^YELLOW%^50,000 gold\n"+
			"      %^RESET%^%^ORANGE%^m%^YELLOW%^a%^RESET%^%^ORANGE%^jestic "+
			"gi%^YELLOW%^a%^RESET%^%^ORANGE%^nt e%^YELLOW%^a%^RESET%^%^ORANGE%^"+
			"gle%^RESET%^\t\t%^YELLOW%^50,000 gold\n"+
			"      %^BOLD%^%^WHITE%^beautiful winged pegasus%^RESET%^\t\t%^YELLOW%^55,000 gold\n"+
			"      %^BOLD%^%^RED%^fie%^YELLOW%^r%^RED%^y %^BLACK%^black nightmare%^RESET%^\t\t%^YELLOW%^55,000 gold\n"+
			"      %^YELLOW%^regal griffon\t\t\t55,000 gold\n");
        if(!TP->query_invis()) {
            say(""+TP->query_cap_name()+" reads a sign.");
        }
		return 1;
	}
}

void reset(){
   ::reset();
   if(!present("stable hand")) new(MON"stable_hand")->move(TO);
}