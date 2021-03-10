#include "../../newbie.h"
inherit ROOM;

object ob;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Goldstone Road in Offestry");
   set_short("%^RESET%^%^GREEN%^Goldstone Road in Offestry");
   set_long("%^RESET%^%^GREEN%^Goldstone Road in Offestry%^RESET%^\n"
"You are nearing the end of Goldstone Road.  The "
"cobblestone %^ORANGE%^street %^RESET%^is smooth beneath your feet, granting passage to the light but steady stream of "
"%^CYAN%^traffic %^RESET%^that passes through the town on a daily basis.  Goldstone Road is bordered on both sides by a "
"jumble of %^RED%^buildings%^RESET%^, the closest of which are the general store on the western corner of the road, and "
"the bank just opposite on the eastern side.  Both have doors that open onto the streets just a few paces away.  A simple "
"wooden %^ORANGE%^palisade %^RESET%^ is visible a little further south, with an opening allowing passage beyond the town. %^RESET%^\n");
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly to light your way.%^RESET%^");
   set_listen("default","You hear snatches of conversation from passersby.");
   set_smell("default","The air is fresh and clean.");
   set_items(([
     "streets":"%^ORANGE%^The streets are newly cobbled and well-kept, polished smooth by the passage of so many "
"travellers.  Goldstone Road leads towards the square to the north, which serves as the heart of this town, and ends a little "+
"further south at one of the town gates.",
     "traffic":"%^CYAN%^A light but steady stream of traffic passes along this street.  Chatter so often fills the air, "
"varying in topic from price bartering, through to tales of grand adventures beyond the gates of the town.%^RESET%^",
     "buildings":"%^RED%^A hodgepodge of buildings rise up along either side of the street.  Their age and vastly varied "
"styles give a unique appearance to the cosy town around you, where no two buildings are the same.  Nearest are a bank "
"and a general store.%^RESET%^",
     "palisade":"%^ORANGE%^A simple palisade a little further south has an opening allowing for passage beyond the town.%^RESET%^",
   ]));
   set_exits(([
     "north":MAINTOWN"sstreet1",
     "south":MAINTOWN"sstreet3",
   ]));
   /*ob = new("/std/bboard");
   ob->set_name("board");
   ob->set_id( ({ "board", "bulletin board", "newbie board" }) );
   ob->set_board_id("ic_offestry_board");
   ob->set_short("The Offestry Bulletin Board");
   ob->set_long("%^RESET%^%^ORANGE%^This corkboard is weathered and old, inviting posts from adventurers who pass through "
"the town.%^RESET%^");
   ob->set_max_posts(50);
   ob->set_location(MAINTOWN"sstreet2.c");*/
}

void reset(){
   ::reset();
   if(!present("street_light",TO)) new(MISCDIR+"street_light")->move(TO);
}