#include "../../newbie.h"
inherit ROOM;

object ob;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("South Crossroads in Offestry");
   set_short("%^RESET%^%^GREEN%^South Crossroads in Offestry");
   set_long("%^RESET%^%^GREEN%^South Crossroads in Offestry%^RESET%^\n"
"You have come to a crossroads here, where Goldstone Road and Shale Street intersect at the southern limits of town.  The "
"cobblestone %^ORANGE%^streets %^RESET%^are smooth beneath your feet, granting passage to the light but steady stream of "
"%^CYAN%^traffic %^RESET%^that passes through the town on a daily basis.  Goldstone Road is bordered on both sides by a "
"jumble of %^RED%^buildings%^RESET%^, the closest of which are the general store on the western corner of the road, and "
"the bank just opposite on the eastern side.  Both have doors that open onto the streets just a few paces away.  A simple "
"wooden %^ORANGE%^palisade %^RESET%^runs along the southern side of Shale Street, separating the town from the wilderness "
"beyond.%^RESET%^\n");
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly to light your way.%^RESET%^");
   set_listen("default","You hear snatches of conversation from passersby.");
   set_smell("default","The air is fresh and clean.");
   set_items(([
     "streets":"%^ORANGE%^The streets are newly cobbled and well-kept, polished smooth by the passage of so many "
"travellers.  Goldstone Road leads towards the square to the north, which serves as the heart of this town.  East and "
"west, Shale Street leads towards the two town gates.%^RESET%^",
     "traffic":"%^CYAN%^A light but steady stream of traffic passes along this street.  Chatter so often fills the air, "
"varying in topic from price bartering, through to tales of grand adventures beyond the gates of the town.%^RESET%^",
     "buildings":"%^RED%^A hodgepodge of buildings rise up along either side of the street.  Their age and vastly varied "
"styles give a unique appearance to the cosy town around you, where no two buildings are the same.  Nearest are a bank "
"and a general store.%^RESET%^",
     "palisade":"%^ORANGE%^A simple palisade of tree trunks runs the length of the southern side of Shale Street.  It "
"rises about six feet from the ground, forming a wooden barrier against the wilderness beyond.  Small gaps between the "
"trunks offer a view of the thick Offestry forest.%^RESET%^",
   ]));
   set_exits(([
     "north":MAINTOWN"sstreet1",
     "west":MAINTOWN"wroad4",
     "east":MAINTOWN"eroad4",
   ]));
   ob = new("/std/bboard");
   ob->set_name("board");
   ob->set_id( ({ "board", "bulletin board", "newbie board" }) );
   ob->set_board_id("ic_offestry_board");
   ob->set_short("The Offestry Bulletin Board");
   ob->set_long("%^RESET%^%^ORANGE%^This corkboard is weathered and old, inviting posts from adventurers who pass through "
"the town.%^RESET%^");
   ob->set_max_posts(50);
   ob->set_location(MAINTOWN"sstreet2.c");
}

void reset(){
   ::reset();
   if(!present("street_light",TO)) new(MISCDIR+"street_light")->move(TO);
}