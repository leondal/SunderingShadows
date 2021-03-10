//Octothorpe (3/5/17)
//Shadow, Bestiary Bar
//Designed by Kiyoshi

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_climate("temperate");
   set_name("The Bestiary, Shadow");
   set_short("%^WHITE%^T%^RESET%^h%^BOLD%^%^BLACK%^e %^WHITE%^Be"+
      "%^RESET%^s%^BOLD%^%^BLACK%^tiary%^RESET%^");
   set_long("%^WHITE%^T%^RESET%^h%^BOLD%^%^BLACK%^e %^WHITE%^Be"+
      "%^RESET%^s%^BOLD%^%^BLACK%^tiary%^RESET%^\n"+
      "%^RESET%^%^CYAN%^This old tavern has a certain earthy charm "+
      "to it. The first thing to greet your gaze is a %^ORANGE%^m"+
      "%^GREEN%^e%^BOLD%^%^BLACK%^n%^RESET%^%^GREEN%^a%^BOLD%^g%^ORANGE%^"+
      "e%^RESET%^%^ORANGE%^ri%^GREEN%^e %^CYAN%^of heads mounted on the "+
      "far wall, of various common and mythical beasts. A long %^ORANGE%^"+
      "bartop %^CYAN%^stretches along the length of one side of the "+
      "room, surrounded by a collection of %^RED%^le%^BOLD%^%^BLACK%^a"+
      "%^RESET%^%^RED%^th%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^r-%^BOLD%^"+
      "%^BLACK%^top%^RESET%^%^RED%^pe%^BOLD%^%^BLACK%^d %^RESET%^"+
      "%^ORANGE%^bar stools%^CYAN%^. An assortment of various liquors "+
      "in %^BOLD%^%^WHITE%^g%^CYAN%^l%^WHITE%^ass b%^CYAN%^ot%^WHITE%^"+
      "tles %^RESET%^%^CYAN%^is stored behind the bar under the "+
      "watchful gaze of the bartender. The only source of light is a "+
      "towering %^BOLD%^%^BLACK%^co%^RESET%^%^ORANGE%^b%^BOLD%^"+
      "%^BLACK%^ble%^RESET%^%^ORANGE%^st%^BOLD%^%^BLACK%^o%^RESET%^"+
      "%^ORANGE%^n%^BOLD%^%^BLACK%^e %^ORANGE%^f%^RED%^i%^RESET%^%^RED%^"+
      "r%^BOLD%^e%^RESET%^%^RED%^p%^BOLD%^l%^ORANGE%^a%^RED%^c%^RESET%^"+
      "%^RED%^e %^CYAN%^against the opposite wall, casting the corners "+
      "of the room onto shadow. An odd scattering of tables takes up "+
      "the remainder of the %^ORANGE%^s%^BOLD%^t%^RESET%^%^ORANGE%^ra"+
      "%^BOLD%^w%^RESET%^%^ORANGE%^-%^RED%^c%^ORANGE%^o%^BOLD%^v"+
      "%^RESET%^%^ORANGE%^er%^RED%^e%^YELLOW%^d %^RESET%^%^CYAN%^"+
      "floor.%^RESET%^\n");
   set_smell("default","You smell the heady mixture of ale and smoke");
   set_listen("default","You hear the sounds of conversation from "+
      "various patrons.");
   set_items(([
       ({"heads","menagerie","trophies"}) : "%^RESET%^%^CYAN%^There is "+
          "no discernible order to these trophies, and no two are the "+
          "same. They range from smaller heads like an %^ORANGE%^o"+
          "%^BOLD%^sq%^RESET%^%^ORANGE%^u%^BOLD%^i%^RESET%^%^ORANGE%^"+
          "p%^CYAN%^, a %^GREEN%^b%^BOLD%^a%^RESET%^%^GREEN%^si%^BOLD%^"+
          "l%^ORANGE%^i%^GREEN%^s%^RESET%^%^GREEN%^k%^CYAN%^, and a "+
          "%^ORANGE%^s%^RED%^t%^ORANGE%^ag%^CYAN%^, all the way up to "+
          "several impressive ones like the heads of a %^GREEN%^g"+
          "%^BOLD%^r%^RED%^e%^GREEN%^e%^RESET%^%^GREEN%^n d%^BOLD%^r"+
          "%^RED%^a%^GREEN%^k%^RESET%^%^GREEN%^e%^CYAN%^, an %^MAGENTA%^"+
          "u%^BOLD%^mb%^RESET%^%^MAGENTA%^erh%^BOLD%^u%^RED%^l%^MAGENTA%^"+
          "k%^RESET%^%^CYAN%^, and a %^BOLD%^%^BLACK%^b%^RESET%^"+
          "%^ORANGE%^u%^BOLD%^%^BLACK%^ll%^RESET%^%^ORANGE%^e%^BOLD%^"+
          "%^BLACK%^tt%^RESET%^%^ORANGE%^e%^CYAN%^. In one small "+
          "corner though, is the head of a %^GREEN%^g%^RED%^o%^GREEN%^"+
          "blin%^CYAN%^, with a plaque beneath entitled %^YELLOW%^Lil' "+
          "Gnasher%^RESET%^%^CYAN%^.%^RESET%^",
      ({"bar","bartop"}) : "%^RESET%^%^CYAN%^Crafted of %^ORANGE%^r"+
         "%^RED%^i%^ORANGE%^ch ma%^RED%^h%^ORANGE%^oga%^RED%^n%^ORANGE%^"+
         "y%^CYAN%^, the bar has been polished to a respectable "+
         "%^BOLD%^%^BLACK%^s%^RESET%^h%^BOLD%^i%^RESET%^n%^BOLD%^"+
         "%^BLACK%^e%^RESET%^%^CYAN%^. Dents and divots have been "+
         "smoothed out, but it is obvious that the %^ORANGE%^wood "+
         "%^CYAN%^has seen many conflicts and collisions in its "+
         "service to the tavern.%^RESET%^",
      ({"stools","barstools","bar stools"}) : "%^RESET%^%^CYAN%^These "+
         "stools are %^ORANGE%^wooden %^CYAN%^and have three legs each "+
         "and are solid in their construction. A comfortable %^RED%^"+
         "b%^BOLD%^%^BLACK%^u%^RESET%^%^RED%^rgu%^BOLD%^%^BLACK%^nd"+
         "%^RESET%^%^RED%^y %^ORANGE%^leather %^CYAN%^seat tops each "+
         "one.%^RESET%^",
      ({"liquors","bottles"}) : "%^RESET%^%^CYAN%^There is a respectable "+
         "selection of %^ORANGE%^l%^BOLD%^i%^RESET%^%^ORANGE%^q%^BOLD%^"+
         "u%^WHITE%^o%^ORANGE%^r%^RESET%^%^ORANGE%^s %^CYAN%^for your "+
         "typical connoisseur, as well as an assortment of various "+
         "%^BOLD%^%^MAGENTA%^v%^RED%^e%^MAGENTA%^n%^RESET%^%^MAGENTA%^"+
         "o%^BOLD%^m%^RESET%^%^MAGENTA%^s %^CYAN%^and %^BOLD%^%^GREEN%^"+
         "t%^ORANGE%^o%^GREEN%^x%^RESET%^%^GREEN%^i%^BOLD%^n%^RESET%^"+
         "%^GREEN%^s %^CYAN%^for the more adventurous patrons.%^RESET%^",
      "fireplace" : "%^RESET%^%^CYAN%^The %^YELLOW%^f%^RED%^i%^RESET%^"+
         "%^RED%^r%^BOLD%^e%^RESET%^%^RED%^p%^BOLD%^l%^ORANGE%^a%^RED%^"+
         "c%^RESET%^%^RED%^e %^CYAN%^has been constructed with oddly "+
         "shaped and mismatched %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^o"+
         "%^BOLD%^%^BLACK%^bbl%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^sto"+
         "%^RESET%^%^ORANGE%^ne%^BOLD%^%^BLACK%^s %^RESET%^%^CYAN%^that "+
         "have been mortared in place. It has a solid look to it, and "+
         "the hearth is home to an impressive %^YELLOW%^f%^RED%^i"+
         "%^RESET%^%^RED%^r%^BOLD%^e %^RESET%^%^CYAN%^that is constantly "+
         "kept stoked and fed. Two weapons have been mounted above the "+
         "mantle, a large wickedly %^BLUE%^s%^BOLD%^e%^RESET%^%^BLUE%^"+
         "r%^BOLD%^r%^RESET%^%^BLUE%^a%^BOLD%^t%^RESET%^%^BLUE%^e"+
         "%^BOLD%^d %^RESET%^%^BLUE%^b%^BOLD%^a%^RESET%^%^BLUE%^s"+
         "%^BOLD%^t%^RESET%^%^BLUE%^a%^BOLD%^r%^RESET%^%^BLUE%^d "+
         "%^BOLD%^s%^RESET%^%^BLUE%^w%^BOLD%^o%^RESET%^%^BLUE%^r"+
         "%^BOLD%^d %^RESET%^%^CYAN%^and an unadorned %^ORANGE%^longbow"+
         "%^CYAN%^.%^RESET%^",
      ({"floor","straw"}) : "%^RESET%^%^CYAN%^The floor is packed dirt "+
         "with a shallow layer of %^ORANGE%^s%^BOLD%^t%^RESET%^"+
         "%^ORANGE%^r%^BOLD%^a%^RESET%^%^ORANGE%^w %^CYAN%^thrown "+
         "overtop. A couple %^RED%^darkly wet %^CYAN%^patches lead you "+
         "to believe bar fights are far from infrequent and possibly "+
         "fatal here.%^RESET%^"
   ]));
   set_exits(([
      "south" : ROOMS"dolanco2"
   ]));
}

void init()
{
    ::init();
    add_action("read","read");
	add_action("make", "make");
}

void reset()
{
    ::reset();
    if(!present("bron")) {
        new(MON"bron.c")->move(TO);
    }
}

int read(string str)
{
    object ob = present("bron");
    int i;
    if(str == "menu")
    {
        if(!ob)
        {
            write("The barkeeper is not here at the moment.");
            return 1;
        }
        say(""+TPQCN+" reads over the menu.");
        write(
"%^GREEN%^-<>-<>-<>- %^BOLD%^%^BLACK%^The Bestiary %^RESET%^%^GREEN%^-<>-<>-<>-%^WHITE%^

         %^GREEN%^-<>- %^BOLD%^%^BLACK%^Drinks %^RESET%^%^GREEN%^-<>-%^WHITE%^

   %^CYAN%^Beer		   %^BOLD%^%^WHITE%^25 %^RESET%^Silver
   %^CYAN%^Whiskey	   %^BOLD%^%^WHITE%^50 %^RESET%^Silver
   %^CYAN%^Rum	           %^BOLD%^%^WHITE%^50 %^RESET%^Silver
   %^CYAN%^Lil Gnasher	   %^BOLD%^%^WHITE%^60 %^RESET%^Silver
   %^CYAN%^Water	   %^BOLD%^%^WHITE%^10 %^RESET%^Silver

	  %^GREEN%^-<>- %^BOLD%^%^BLACK%^Eats %^RESET%^%^GREEN%^-<>-%^WHITE%^

   %^CYAN%^Meat Sandwich   %^BOLD%^%^WHITE%^30 %^RESET%^Silver
   %^CYAN%^Pork Chop       %^BOLD%^%^WHITE%^40 %^RESET%^Silver
   %^CYAN%^Salty Balls     %^BOLD%^%^WHITE%^25 %^RESET%^Silver

 %^GREEN%^-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-%^WHITE%^");
        return 1;
    }
    return 0;
}

int make(string str){
    if(str != "thief sign") return notify_fail("Make what?\n");
    if(TP->query_invis()){
        tell_object(TP, "You sign to the room that you are a thief.");
        return 1;
    }
    if(!TP->is_class("thief") && !TP->is_class("assassin") &&
!TP->is_class("bard")) {
        tell_object(TP, "Bron gives you a strange look, but shrugs and
motions you towards a door in the back of the room.");
        tell_room(ETP, TPQCN+" makes a strange gesture towards Bron,
then heads towards a door in the back.", TP);
        TP->move_player(ROOMS"thieflounge");
    } else {

tell_object(TP, "You make the thieves sign to Bron, who nods
and discretely motions you towards the door in the back.");
        if(random(40) > (TP->query_stats("dexterity") +
TP->query_stats("intelligence")))
            tell_room(ETP, "You notice "+TPQCN+" making a strange sign to
Bron.", TP);
        TP->move(ROOMS"thieflounge");
                TP->describe_current_room(1);
    }
    return 1;
	
}