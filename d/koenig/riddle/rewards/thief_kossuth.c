//thief_auril.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHAT;

void create(){
	::create();
	set_name("gold crown");
	set_id(({ "crown", "crown of smoldering flames" }));
	set_short("%^BOLD%^%^RED%^Crown of %^BLACK%^Smo%^YELLOW%^l%^BLACK%^de%^RED%^r%^BLACK%^ing %^RED%^Fl%^RESET%^%^ORANGE%^a%^BOLD%^%^RED%^m%^RESET%^%^ORANGE%^e%^BOLD%^%^RED%^s%^RESET%^");
	set_obvious_short("A golden crown");
	set_long(
@AVATAR
%^BOLD%^%^YELLOW%^This richly decorated crown sparkles with the light of %^RED%^red hued%^YELLOW%^ gems on a gold background.  The way the gems sparkle and the gold shines this crown must be worth a fortune!  Though on a closer inspection you see that instead of gold, the crown is really made of brass.  Instead of being studded with %^RED%^rubies%^YELLOW%^, %^RED%^garnets%^YELLOW%^ and %^RED%^flamedance%^RESET%^ gems, it is only colored glass.  Still the crown looks quite impressive and lavish and more than likely can fool anyone.

AVATAR
	);
	set_lore(
@AVATAR
The Crown of Smoldering Flames was once used by Oscrit the Dandy, a rogue who's quest for power lead him to the faith of Kossuth.  Though Oscrit was the meer son of a stablehand, he managed to reinvent himself to be Oscrit Thelregard the Fourth, the third in line to the Asgardian Throne and descendant of King Flagg.  For many year's Oscrit was able to pass off a cheap brass crown he had made as his "royal" treasure.  Though his true heritage was found out by Lady Delethosa Mordarn, a second cousin twice removed of King Flagg.  His crown is said to still contain his smoldering desire for power and wealth.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" carefully pulls off their lavish gold crown.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You remove the crown off your head.");
	return 1;
}
