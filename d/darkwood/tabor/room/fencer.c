#include <std.h>
#include "../include/tabor.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",1);
    set_property("no sticks",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("A small room");
   set_short("%^RESET%^%^ORANGE%^A small room%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This small room, hidden from the normal drunken patrons, "
"is cramped, but organized. Along the west and east walls are stacks of shipping crates, "
"piled almost to the ceiling. The north wall is dominated by a %^RED%^large oak "
"desk%^ORANGE%^ with a stack of papers and a giant registry book. Over the desk is a "
"wooden sign with letters scrawled in black.%^RESET%^\n");
   set_smell("default","You can smell very little out of the ordinary");
   set_listen("default","You can hear the sounds of the bar, muffled slightly");
   set_items(([
     "crates" : "%^RESET%^%^ORANGE%^Piled against the east and west walls are shipping "
"crates. They have been stacked well and shouldnt fall any time soon. The lettering on "
"each crate has been %^BLACK%^%^BOLD%^defaced%^RESET%^%^ORANGE%^ and there are no labels "
"on them to hint at where they came from, or whats in them.%^RESET%^",
     "desk" : "%^ORANGE%^This desk has been made from fine oak and looks rather heavy and "
"sturdy. It has been covered with stacks of %^RESET%^%^BOLD%^papers%^RESET%^%^ORANGE%^, a "
"%^YELLOW%^large book%^RESET%^%^ORANGE%^, and a %^BLACK%^%^BOLD%^shriveled "
"head.%^RESET%^",
     "sign" : "%^RESET%^%^ORANGE%^This sign has been scrawled in large black letters with "
"the following %^BLACK%^%^BOLD%^'REMEMBER ALWAYS YOUR BROTHERS AND SISTERS, REMEMBER YOUR "
"QUICKNESS IS YOUR LIFE, AND REMEMBER THAT THE SHADOWS ARE YOUR HAVEN... NEVER FORGET THE "
"SHADOWS, OR THE LORD WHO GIVES THEM'.%^RESET%^",
     "head" : "%^RESET%^%^ORANGE%^This ancient shriveled thing is the bodyless head of "
"some %^BLACK%^%^BOLD%^undead lich%^RESET%^%^ORANGE%^. Its face is twisted into a visage "
"of unholy %^RED%^anger%^RESET%^%^ORANGE%^ and %^RED%^rage%^RESET%^%^ORANGE%^. It has "
"been quite beaten up and scarred, both through nicks and cuts, and through magical fire. "
"It a macabre addition to the desk, and it looks like they've been using it as a "
"paperweight.%^RESET%^",
     "papers" : "%^RESET%^%^BOLD%^Several large stacks of papers domintate the desk. They "
"are obviously in some order, but its a mystery to you as to what means what.%^RESET%^ ",
     "registry" : "%^YELLOW%^Bound in soft leather, this is the master record of all the "
"accounts at the guild. The entire thing however has been written in a complicated code "
"that only guildmasters and a handfull of others understand. This has been done to "
"protect the identity of the 'members'.%^RESET%^",
   ]));
   set_exits(([
     "bar" : ROOMDIR+"pig_and_whistle",
   ]));
}

void reset(){
    ::reset();
  if(!present("peralin")) new(MONDIR+"peralin")->move(TO);
  TO->query("fnord");
}
