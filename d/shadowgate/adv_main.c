// Shadowgate Main Adventurer's Hall
// Second Edition
// 970215
// /d/shadowgate/adv_main.c
// 10/29/02 down to ooc boards removed - now remote boards, description updated to one
// Crystal had written since newbies don't start here now, and main board removed *Styx*

#include <std.h>
#include <config.h>


inherit "/std/room";

void create() {
  object ob;

  ::create();
  set_terrain(CITY);
  set_travel(PAVED_ROAD);
  set_property("light", 2);
  set_property("indoors", 1);
   //set_property("no invis",1);
   set_short("Main Adventurers' Hall");
  set_long ("%^CYAN%^BOLD%^Main Adventurers' Hall%^RESET%^\n"+
   "  This is a large hall in the center of town that is frequently the gathering"+
   " place of adventurers.  Many wondrous tales are told here and hot topics are frequently"+
   " discussed. This is also a place where several battles have been waged, despite"+
   " town policy, as is evidenced by the faint blood stains that can no longer be"+
   " removed from places on the floor and walls.  Stairs lead up to a large tower.\n"+
   "%^MAGENTA%^A large map dominates the entire floor.  %^RESET%^It has been made by those"+
   " adventurers who have gone exploring and returned to tell about it and has been"+
   " updated in several places over time. It serves as a rough guide for those eager"+
   " to begin their journeys.\n"
  );

    set_exits( ([
//		"down" : "/d/shadowgate/ombud_hall", (ooc board rooms disabled)
                "southeast" : "/d/shadow/room/city/gs_rd_bk",
                "northwest" : "/d/shadow/room/main/garrison5",
                "up" : "/d/shadowgate/arch/2nd_floor"]) );
/*  ooc boards removed to remote access 10/02
  ob = new("std/bboard");
  ob->set_name("board");
  ob->set_id( ({ "board", "bulletin board", "reality board" }) );
  ob->set_board_id("main_board");
    ob->set_ooc_board(1);
  ob->set("short", "The ShadowGate Reality Board");
  ob->set("long", "An old cork board where the adventurers "
          "who pass through ShadowGate post information on the "
          "reality they have discovered.\n");
  ob->set_max_posts(50);
  ob->set_location("/d/shadowgate/adv_main");
*/

  set_items(
        (["hall" : "A place for a rowdy time!",
        "adventurers" : "They appear to be exchanging tales",
        "tales" : "Tales of past adventures",
        ]) );
//   find_object_or_load("/d/npc/netil");
//       "daemon/place_d"->place_in("/d/shadow/room/city/", find_object_or_load("/d/npc/ticio"));
//   find_object_or_load("/d/npc/finane");
//   find_object_or_load("/d/npc/cutter");
//   find_object_or_load("/d/npc/billeas");
// Please see /daemon/monster_d.c for loading monsters without room load and loading. - garrett.

}


void init(){
    ::init();
  add_action("Look","look");
  add_action("Look","exa");
}

int Look(string str){
    if(!str || (str != "floor" && str != "map")) return 0;
  TP->more("/d/common/text/main_map"); //TP->more("/realms/vetri/map");
        return 1;
}

