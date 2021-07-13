// adding hidden portal for hms to go in and out of newbietown *Styx* 9/10/06

#include <std.h>
#include <objects.h>
#include <move.h>

#define NEWB_D "/d/newbie/ooc/newbie_d.c"

inherit ROOM;

void create() {
        ::create();
        set_property("indoors",1);
        set_property("no teleport",1);
        set_property("light",2);
        set_property("no sticks",1);
	set_property("ooc room", 1);
        set_short("%^MAGENTA%^OOC area hub to tutorial/info. rooms");
        set_long("This room leads to the %^BOLD%^<tutorial>%^RESET%^ and a series of %^BOLD%^<info>%^RESET%^ rooms to help answer player's questions about how to get started and get the most from playing in Sundering Shadows.  When you have been through those and are ready to begin your adventure, the exit to the %^BOLD%^<city>%^RESET%^ will take you to the town square of Offestry.  You can return here anytime to look for answers to other questions you may have or to refresh your memory, or you can type %^BOLD%^%^GREEN%^<help hints>%^RESET%^ while anywhere in the game world for additional helpful hints. Please also remember that if you are searching for roleplay, %^BOLD%^%^BLUE%^<rumors> %^RESET%^will tell you where people are currently congretating if you wish to try your hand at seeking them out, OR you can set an RP flag %^YELLOW%^<help flag> %^RESET%^to draw them to you.

There is also a special exit %^CYAN%^%^BOLD%^<portal>%^RESET%^ here, closed to common players.

%^WHITE%^If you would prefer to %^CYAN%^skip Offestry%^WHITE%^ you may use the %^CYAN%^%^BOLD%^<bypass>%^RESET%^ command to leave at this point.%^RESET%^");
        set_items(([
        ]));
        set_exits(([
	"info" : "/d/newbie/ooc/hub_room2",
        "tutorial": "/d/newbie/ooc/hub_room",
        "city": "/d/newbie/rooms/town/square",
	"portal":  "/d/shadow/room/forest/long_pond",
        ]));
        set_pre_exit_functions(({"portal", "city"}),({"GoThroughDoor", "getmap"}));
}

void init()
{
    ::init();
    add_action("bypass_func", "bypass");
}

int bypass_func(string str)
{
    object myRoom, ob;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;

    NEWB_D->spawn_eq(TP, 1);
    NEWB_D->advance_level(TP);
    NEWB_D->spawn_eq(TP, 2);
    NEWB_D->advance_level(TP);
    NEWB_D->spawn_eq(TP, 3);
    NEWB_D->advance_level(TP);
    NEWB_D->spawn_eq(TP, 4);
    NEWB_D->advance_level(TP);
    NEWB_D->spawn_eq(TP, 5);
    NEWB_D->advance_level(TP);
    NEWB_D->advance_level(TP);
    NEWB_D->advance_level(TP);

    TP->add_money("gold",10000);
    if(objectp(ob = present("newbiemassobject", TP))) ob->remove();
    tell_object(TP, "\n%^BOLD%^%^WHITE%^You feel the world around you "+
    "shifting and changing as you suddenly find yourself somewhere "+
    "else!%^RESET%^");
    tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ suddenly shifts and wavers "+
    "before blinking out of existence!", TP);
    myRoom = new("/d/newbie/ooc/trainer");
    myRoom->set_for(TP);
    TP->move_player(myRoom);
    return 1;
}

int getmap() {
    object ob;
    if(!present("map",TP) && !TP->query_true_invis()) {
        tell_object(TP,"%^RED%^An obviously excited town citizen aproaches "+
        "you and exclaims:  %^RESET%^I see you don't have a map of "+
        "the town, we can't have that, take one! If you would like a text-only version of the map, please <request> one!");

        tell_room(TO,"%^RED%^An obviously excited town citizen "+
        "approaches "+TPQCN+"%^RED%^ and says something to "+TP->QO+
        ".%^RESET%^",TP);

        ob = new("/d/newbie/obj/misc/map.c");
        if(ob->move(TP) != MOVE_OK) {
            tell_object(TP,"%^RED%^The citizen frowns and then "+
            "tosses the map at your feet instead.%^RESET%^");
            tell_room(TO,"%^RED%^The citizen frowns and tosses "+
            "a map at "+TPQCN+"%^RED%^'s feet!%^RESET%^",TP);
            ob->move(TO);
        }
        return 1;
    }
    return 1;
}

int GoThroughDoor() {
   if(!userp(TP)) return 0;
   if(avatarp(TP)) return 1;
   if(newbiep(TP)) {
      write("This portal is reserved for high mortals to return from visiting here.  "
	"Please seek out the proper exit to the lands beyond when you are ready.  "
	"If you are not a newbie and are here, you shouldn't be so take the long "
	"way back now please.");
      return 0;
   }
   write("%^YELLOW%^Thank you for doing your part to help the newbies get a "
	"better start on their character development."
   );
   return 1;
}

void reset(){
	::reset();
	if(!present("sign",TO))
	new("/d/newbie/obj/misc/townsign")->move(TO);
}