#include <std.h>;
inherit "/std/room";

void create() {
//  object ob;
  ::create();
  set_property("light", 3);
  set_property("indoors", 1);
  set_property("no teleport", 1);
  set_short("Fighters' Class Hall");
  set_listen("default","You can hear the sound of iron and silver being worked.");
  set_smell("default","You smell tanned leather and oil.");
  set_long(
"%^BOLD%^This is the Fighters' Class Hall.%^RESET%^\n"+
"You find youself standing in a secret room nudged behind an old warehouse.\n"+
"Others of your trade come here to exchange stories, post on current events,\n"+
"and drink. The walls, although old, are covered in various weapons and\n"+
"armours. The floor shines brightly up at you under the lights of this room.\n"+
"Your comrades stand, awaiting your stories.\n"
          );
  set_items(([
"walls":"The things on these walls have been here for a very long time.",
"weapons":"All sorts of various weapons line the wall. Oooo, is that a\n"+
"pike?!",
"armours":"Suits of exquisitely crafted armor stand all about the room.",
"floor":"It is shiny.",
"comrades":"Fellow fighters stand around, far from bored."
             ]));
  set_exits(([
      "north":"/d/tharis/Tharis/cguilds/fighter/f_store",
      "out" : "/d/tharis/Tharis/cguilds/fighter/entrance",
      "east":"/d/tharis/Tharis/cguilds/fighter/f_bar"
           ]));
/*
  ob= new(BBOARD);
  ob->set_name("board");
  ob->set_id(({ "board","class board" }));
  ob->set_board_id("fguildboard");
  ob->set_max_posts(30);
  ob->set_location("/d/tharis/Tharis/cguilds/fighter/fhall");
  ob->set_short("The Fighters' Board");
  ob->set_long(
"Fighters post suggestions, ideas, comments, and plans on here.\n"
              );
*/
}
/*

void init(){
    ::init();
    add_action("test_fighter", "remove");
    add_action("test_fighter", "answer");
    add_action("test_fighter", "post");
    add_action("test_fighter", "edit");
}

int test_fighter(){
    if(TP->is_class("fighter") || avatarp(TP)) return 0;
    tell_object(TP, "You can't do that here.");
    return 1;
}
*/
