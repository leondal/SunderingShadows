// added the headstone Darum requested for his & Marika's baby 11/24/06 *Styx*
//Updated cherry tree now that it is 20+ years old :)  ~Circe~ 5/27/07

#include <std.h>
inherit ROOM;

void create() {
        ::create();
        set_property("indoors",0);
        set_property("light",2);
        set_terrain(LIGHT_FOREST);
        set_travel(FOOT_PATH);
        set_name("Entrance to the grove");
        set_short("%^GREEN%^Entrance to the grove%^RESET%^");
        set_long("%^GREEN%^Here in the entrance to an ancient "+
           "grove, an eerie%^RESET%^ %^BOLD%^%^WHITE%^mist"+
           "%^RESET%^ %^GREEN%^creeps around your feet adding to the "+
           "mysterious feel of the ruins of the temple.  Once great "+
           "%^BOLD%^%^WHITE%^m%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^"+
           "%^WHITE%^r%^RESET%^%^WHITE%^b%^RESET%^%^BOLD%^%^WHITE%^l"+
           "%^RESET%^%^WHITE%^e%^RESET%^ %^BOLD%^%^WHITE%^p%^RESET%^"+
           "%^WHITE%^i%^RESET%^%^BOLD%^%^WHITE%^l%^RESET%^%^WHITE%^l"+
           "%^RESET%^%^BOLD%^%^WHITE%^a%^RESET%^%^WHITE%^r%^RESET%^"+
           "%^BOLD%^%^WHITE%^s %^RESET%^%^GREEN%^now lay crumbled in "+
           "partial ruin, strangled and overrun by creeping i%^RESET%^"+
           "%^RED%^v%^RESET%^%^GREEN%^y and long grass, giving it a "+
           "strange, ethereal beauty.  Low hanging v%^YELLOW%^i"+
           "%^RESET%^%^GREEN%^n%^RESET%^%^YELLOW%^e%^RESET%^%^GREEN%^s "+
           "create a low ceiling over the pathway that winds its way "+
           "deeper into the grove.  A flourishing mature %^RED%^"+
           "cherry tree %^GREEN%^stands near the path leading north, "+
           "its branches rising up out of the fog.  "
           "%^GREEN%^Under the tree, you notice a %^BOLD%^%^BLACK%^small "
	   "engraved headstone %^RESET%^%^GREEN%^visible through "
	   "the %^BLUE%^s%^WHITE%^w%^BLUE%^i%^WHITE%^r%^BLUE%^l%^WHITE%^"
	   "i%^BLUE%^n%^WHITE%^g%^GREEN%^ fog.%^RESET%^\n"
        );
        set_items(([
           "mist" : "%^BLUE%^An eerie mist clings to your feet and "+
              "flows through the grass.%^RESET%^",
           "ivy" : "%^GREEN%^The creeping ivy has snaked its way around "+
              "the old stone ruins.%^RESET%^",
           "vines" : "%^YELLOW%^Strange vines hang precariously from "+
              "overhanging branches, covered in e%^RESET%^%^RED%^x"+
              "%^RESET%^%^BLUE%^o%^RESET%^%^GREEN%^t%^RESET%^%^MAGENTA%^i"+
              "%^RESET%^%^YELLOW%^c flowers.%^RESET%^",
           ({"pillars","ruined pillars","ruins"}) : "BOLD%^%^WHITE%^These "+
              "once prominent pillars now lay crumbled, covered in"+
              "%^RESET%^ %^GREEN%^ivy and moss.%^RESET%^",
           ({"tree","cherry tree"}) : "%^RED%^The cherry tree "+
              "features supple, graceful limbs supporting "+
              "%^RESET%^silvery%^RED%^-%^GREEN%^green leaves "+
              "%^RED%^and fragrant %^BOLD%^%^MAGENTA%^cherry "+
              "blossoms%^RESET%^%^RED%^.  The tree has matured over "+
              "time and seems quite at home in the lush forest surroundings.",
	   ({"stone","headstone"}) : "%^BOLD%^%^BLACK%^ Hidden in "
	      "the swirling fog under the %^RED%^cherry %^GREEN%^tree"
	      "%^BOLD%^%^BLACK%^, you see the small headstone.  Images "
	      "of %^BOLD%^%^WHITE%^u%^RESET%^n%^BOLD%^i%^RESET%^c%^BOLD%^"
	      "o%^RESET%^r%^BOLD%^n%^RESET%^s%^BOLD%^%^BLACK%^ have been "
	      "masterfully carved into the stone, surrounding a plaque "
	      "in the middle. The plaque reads %^YELLOW%^Damar Lynwey.%^RESET%^"
        ]));
        set_smell("default","%^BOLD%^%^BLUE%^The intoxicating scent of lilacs "+
           "and other wild flowers fill the air.%^RESET%^");
        set_listen("default","%^BOLD%^%^WHITE%^The pathway is "+
           "surprisingly quiet.%^RESET%^");
        set_exits(([
           "south" : "/d/magic/temples/mielikki_center",
 	     "north" : "/d/tharis/road/eroad24"
        ]));
}
