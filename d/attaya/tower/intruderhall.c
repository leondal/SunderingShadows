//Octothorpe (3/1/09)
//Attaya, Intruder's Room
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit ROOM;

int doom;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_property("no teleport",1);
   set_property("no pocket space",1);
   //set_storage(1);
   set_travel(SLICK_FLOOR);
   set_terrain(STONE_BUILDING);
   //set_no_clean(1);
   set_had_players(12);
   set_name("Council Chamber");
   set_short("%^BOLD%^%^BLACK%^High Council Chamber of the Kinnesarudan "+
      "Empire%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^High Council Chamber of the Kinnesarudan "+
      "Empire\n "+
      "This is a large, oblong-shaped room that has been smoothly carved "+
      "out of the obisd%^RESET%^i%^BOLD%^%^BLACK%^an cube that you have "+
      "been travelling through.  The room itself lacks any corners, "+
      "leaving the floor, walls, and ceiling to gently curve into each "+
      "other, creating a rounded lozenge shape.  In the center of the "+
      "room, a circular platform rises out of a depression in the floor, "+
      "where ten seats form out of the obsid%^RESET%^i%^BOLD%^%^BLACK%^"+
      "an.  Set in the center of the platform is a softly %^CYAN%^"+
      "glowing %^BOLD%^%^BLACK%^symbol of the Kinnesarudan Empire.  "+
      "At the head of the platform sits a magnificent %^WHITE%^s"+
      "%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^r %^BOLD%^%^BLACK%^"+
      "throne.%^RESET%^\n");
   set_items(([
      ({"room","floor","walls","ceiling"}):"%^BOLD%^%^BLACK%^This room "+
         "has been smoothly carved out of the obisd%^RESET%^i%^BOLD%^"+
         "%^BLACK%^an material from which the cube has been formed "+
         "out of.  There are no signs of tool marks found, which would "+
         "suggest the use of magic to create this chamber.  Everything "+
         "in this room, with the exception of the throne, have been "+
         "carved from the obisd%^RESET%^i%^BOLD%^%^BLACK%^an floor.",
      "obsidian" : "%^BOLD%^%^BLACK%^This room, and obstensively, "+
         "this whole structure appears to be constructed out of one "+
         "massive piece of flawless obsid%^RESET%^i%^BOLD%^%^BLACK%^.",
      "platform" : "%^BOLD%^%^BLACK%^This circular platform rises out "+
         "of the obsid%^RESET%^i%^BOLD%^%^BLACK%^ floor and serves as a "+
         "table for the ten seats situated around it.  At the far end "+
         "of the platform lies the impressive %^WHITE%^s%^RESET%^i"+
         "%^BOLD%^lv%^RESET%^e%^BOLD%^r %^BOLD%^%^BLACK%^throne.  "+
         "The platform forms a raised dais for the throne, allowing "+
         "the ruler of the Kinnesaruda to stand, and be seated above, "+
         "the other occupants of this chamber.  At the center of the "+
         "platform, a %^CYAN%^glowing %^BOLD%^%^BLACK%^symbol of the "+
         "Kinnesarudan Empire has been carved in sunken-relief.",
      "symbol" : " \n "+ 
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,,,%^CYAN%^I,%^BOLD%^%^BLACK%^"+
         ".,,,,,,,,%^CYAN%^-I%^BOLD%^%^BLACK%^,,,,,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,,,%^CYAN%^++%^BOLD%^%^BLACK%^"+
         ".,,,,,,,,%^CYAN%^I+%^BOLD%^%^BLACK%^,,,,,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,,,,%^CYAN%^II%^BOLD%^%^BLACK%^"+
         ".,,,,,,%^CYAN%^?+%^BOLD%^%^BLACK%^.,,,,,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,,,,,,%^CYAN%^??-~+??:%^BOLD%^"+
         "%^BLACK%^,,,,,,,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,,,,,,,.%^CYAN%^,+.%^BOLD%^"+
         "%^BLACK%^,,,,,,,,,,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,,,,,,,,%^CYAN%^,=.%^BOLD%^"+
         "%^BLACK%^,,,,,,,,,,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,,,,,,,,%^CYAN%^,~.%^BOLD%^"+
         "%^BLACK%^,,,,,,,,,,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,,,,,%^CYAN%^,:-----:.%^BOLD%^"+
         "%^BLACK%^,,,,,,,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,,,,%^CYAN%^:+~,,,,,~?:%^BOLD%^"+
         "%^BLACK%^,,,,,,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,,,,%^CYAN%^?,,,,,,,,.?~%^BOLD%^"+
         "%^BLACK%^,,,,,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,,,%^CYAN%^+~,,,,,,,,,~?,%^BOLD%^"+
         "%^BLACK%^..,,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,,,%^CYAN%^-+.-?++++-.++%%^BOLD%^"+
         "%^BLACK%^..,,,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,%^CYAN%^,~,%^BOLD%^%^BLACK%^.,,,,"+
         "%^CYAN%^?.%^BOLD%^%^BLACK%^,,,,.:~,%^BOLD%^%^BLACK%^"+
         ",,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,%^CYAN%^.--%^BOLD%^%^BLACK%^"+
         ",,,,,,,%^CYAN%^+.%^BOLD%^%^BLACK%^,,,,,,%^CYAN%^:-:%^BOLD%^"+
         "%^BLACK%^,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,.,,,,,,,,%^CYAN%^~,%^BOLD%^"+
         "%^BLACK%^,,,,,,,,,,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,,,,,,,,,%^CYAN%^-.%^BOLD%^"+
         "%^BLACK%^,,,,,,,,,,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,,,,,,,,,%^CYAN%^+.%^BOLD%^"+
         "%^BLACK%^,,,,,,,,,,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,,,,,,,,,%^CYAN%^+,%^BOLD%^"+
         "%^BLACK%^,,,,,,,,,,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,,,,,,,,,%^CYAN%^I,%^BOLD%^"+
         "%^BLACK%^,,,,,,,,,,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,,,,,,,,,%^CYAN%^I.%^BOLD%^"+
         "%^BLACK%^,,,,,,,,,,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,,,,,,,,,%^CYAN%^I.%^BOLD%^"+
         "%^BLACK%^,,,,,,,,,,,,,,,,,,, \n "+
         "%^BOLD%^%^BLACK%^,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,, \n ",
      ({"seats","seat"}):"%^BOLD%^%^BLACK%^These ten seats have been "+
         "carved out of the same obisd%^RESET%^i%^BOLD%^%^BLACK%^an "+
         "that the chamber has been formed out of.  They are immobile, "+
         "literally being formed out of the floor itself.  They are "+
         "fairly wide, certainly large enough to accomodate a large "+
         "humanoid.",
      "throne" : "%^BOLD%^%^BLACK%^This throne is nearly suited for a "+
         "giant, with the back of it reaching over ten feet in height.  "+
         "It is fashioned out of %^WHITE%^s%^RESET%^i%^BOLD%^lv%^RESET%^"+
         "e%^BOLD%^r and bears ornate reliefs of various undead, as "+
         "well as some unidentifiable demonic creatures.  Unlike the "+
         "other furniture found in this chamber, the throne does not "+
         "appear to be permanently attached to the floor, although it "+
         "does not look like it would be nearly possible to move "+
         "though.",
   ]));
   set_smell("default","A whiff of decayed flesh catches your nose.");
   set_listen("default","A nearly inaudible hum originates from the "+
      "center of the room.");
   new(MON+"intruder")->move(TO);
}
/*void reset(){
   ::reset();
	  if(doom = 1){
         new(MON+"intruder")->move(TO);
		 doom--;
      }
   remove_exit("portal");  Removing this in favor of pre_exit_func querying for Intruder/Autarkis.  
   This will allow people that come in after the fight is over to get out of the tower without being stuck, 
   seeing that Intruder will spawn only once per boot, as of right now. Octothorpe 3/1/11
}*/
