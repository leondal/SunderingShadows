#include <std.h>
#include "../include/tabor.h"
inherit ROOM;

void create() {
   object ob;
	::create();
	set_property("indoors",1);
	set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_property("no sticks", 1);
   set_short("Public Offices, Caer Tabor");
   set_long(
   "%^BOLD%^Public Offices, Caer Tabor%^RESET%^\n"+
   "You are standing in the public offices in Caer Tabor."+
   "  This is where people once came for audiences with city"+
   " officials whenever they were granted.  There is a large desk"+
   " in the center of the room that is raised up on a dais and a"+
   " large ornate chair that the presiding official would have used.  There"+
   " are many smaller desks that look as if they were once used by scribes."
   "  Parchment, quills, and ink are still scattered about the desks.\n"
   );
/* changing due to removing Magistrate - conflicts with board and referring to Shadow's
bounties - *Styx*  11/e/02
   set_long(
   "%^BOLD%^Office of the Magistrate, Tabor%^RESET%^\n"+
   "You are standing in the office of the magistrate in Caer Tabor."+
   "  This is where people can come to request actions to be taken"+
   " against the law breakers of the city.  The accused may also come"+
   " here in an attempt to defend themselves.  There is a large desk"+
   " in the center of the room that is raised up on a dias, upon a"+
   " large ornate chair the magistrate sits to hear the complaints and"+
   " help with rulings, issuing a law bounty if one is decided.  There"+
   " are many scribes about the room in smaller desks that are always"+
   " busy copying the complaints and defenses, and noting the outcomes"+
   " of each case.\n\n"+
   "Against one wall is a board where people may post concerns or "+
   "notes to people involved in cases or other messages related to "
   "the business of the city.\n"
   );
*/
   set_smell("default","The scent of ink and parchment fills the room.");
//   set_listen("default","Scribes are busy copying complaints and filing them away.");
   set_listen("default", "It is fairly quiet except for the echoes off the castle walls.");
   set_items(([
   "dias" : "There is a large wooden dias in the center of the room"+
   " that raises the desk and chair that the magistrate uses up above"+
   " the rest of the room.",
   "chair" : "A large chair carved out of solid bronzewood has been"+
   " carved with the symbols of justice, it sits behind the desk atop"+
   " the dias in the center of the room.",
   "desk" : "A large desk rests upon the dias in the center of the"+
   " room. It is mostly empty except for an ink well, quill, and a"+
   " couple of pieces of parchment that the magistrate may jot notes"+
   " down on if he is inclined, though mostly he leaves such a duty to"+
   " the scribes.",
   "desks" : "There are smaller desks about the room that the scribes"+
   " use to copy down the documents and take notes.",
   "parchment" : "Parchment can be found just about everywhere here,"+
   " most of it covered in carefully printed letters that are drying.",
   "ink well" : "There is an ink well atop the magistrate's desk.",
   "quill" : "There is a pretty white feather quill that the magistrate"+
   " may use to take notes on cases.",
/*   "scribes" : "There are many scribes about the room at all times,"+
   " it seems they are never quite caught up on their work.",
   "board" : "There is a board to one side of the room that can be used"+
   " be jurors, defendants, and accusers to post concerns of cases and"+
   " such.",
*/
   ]));
   set_exits(([
   "west" : ROOMDIR+"castle1",
   ]));
/*
   ob = new(BBOARD);
   ob->set_name("tabor board");
   ob->set_id(({"tabor city board","board","city board" }));
   ob->set_board_id("tabor city board");
   ob->set_max_posts(30);
   ob->set_queue();
   ob->set_location("/d/darkwood/tabor/room/castle2");
   ob->set_short("The Tabor City Board");
   ob->set_long("Please place any reasons, pleas, or arguments for bounty "
      "requests here in addition to your comments of cases.  You may also "
      "post about other issues of note related to business of the city.");
*/
}

void reset() {
   ::reset();
/*  removing magistrate due to conflicts with the board and referring to Shadow's bounties
*Styx*  11/2/02
   if(!present("magistrate")) {
      new(MONDIR+"magistrate")->move(TO);
   }
   if(!present("guard")) {
      new(MONDIR+"guard")->move(TO);
   }
*/
}
