
#include <objects.h>

inherit "std/pier";

void init() {
  ::init();
  add_action("push_button", "push");
  add_action("enter","enter");
}

void create() {
    object ob;
    ::create();
set_light(3);
    set_short("beach park");
    set_long(" "
"You are in a large park.  There are many things to do here.  There is a "
"large pond that has many sailboats on it.  There are many houses lined up "
"around the park.  There is a large sign that has lists of what you can do "
"here, and what stores are close by."
"  There is a small button in the grass.");
set_smell("default","You smell fresh water.");
set_listen("default","You hear people talking all around you!");

    set_exits(([
"portal" : "/d/shadowgate/adv_main",

       ] ));

   ob = new("/std/bboard");
   ob->set_name("board");
   ob->set_id( ({ "board" }) );
   ob->set_board_id("beach");
   ob->set_max_posts(30);
ob->set_location("/d/shadow/room/beach/park1.c");
   ob->set("short", "Park Board");
ob->set("long", "This board is to keep residents posted on what is going on with their neighborhood."
"Feel free to post about anything that you have questions or opinions about here.");


    set_items(([
       "fish" : "You can see tuns of large fish in there!",
      "hill" : "You see alot of people eating on the hill side.",
      "button" : "The button has a note on it reading, \n Push button if you need a fishing pole!",
      "grass" : "The grass has been freashly mown, and there is a button sitting in it.",
         "wrighting" : "Push for fishing pole.",
       "sign" : "The sign reads-%^BOLD%^MAGENTA%^\n"
"      Welcome to the beach front park!.\n"
"      Here is a list of homes, stores, and things to do here.\n"
"\n"
"          HOMES                  STORES             ACTIVITIES\n"
"\n"
"       Sweetsavage             Coffee shop             Fish\n"
"       Zeek                    Armory                  \n"
"       Struphen                Weaponry                \n"
"       Tuco                    General Store   \n"
"                               Restaurant              \n"
"                               Hospital                \n"
"                               Bank                    \n"
"\n"
"       For more imformation look name of what you want to learn more about.\n"
"       Thank You, and enjoy.\n"
"       Sincerly,  Your Town Leader, Zeek.",
        "pond" : "This pond is very large, and you can do alot of things with it!",
      ] ));
set_max_fishing(5);
set_chance(10);
set_max_catch(10);
set_fish( ([ "Troute": 5, "Cat fish": 5,  "Shark": 20, "Eel": 10, "Gold fish": 2, "whale": 20, "rainbow troute": 6, ]) );
}

int push_button(string str) {
 if(!str) {
   notify_fail("push what?\n");
   return 0;
 }
write("You push the small button and a fishing pole apears in your hands.");
say(this_player()->query_cap_name()+" pushes the button, and a fishing pole apears!",this_player());
 new("/d/shadow/room/beach/obj/fishing_rod.c")->move(this_object());
return 1;
}
int enter(string str)
{

  if(str != "sweetsavage" && str != "zeek" && str != "struphen" && str != "tuco" && str != "coffee shop" && str != "weaponry" && str != "armory" && str != "hospital" && str != "bank" && str != "general store" && str != "restaurant")


   {
     write("Enter what?");
     return 1;
   }
  if(str == "sweetsavage"){
say(this_player()->query_cap_name()+" enters Sweetsavage's house.");
this_player()->move_player("/d/shadow/room/beach/homes/sweetsavage1.c");
write("You enter Sweetsavage's house.");
}
  if(str == "zeek"){
say(this_player()->query_cap_name()+" enters Zeek's house.");
this_player()->move("/d/shadow/room/beach/homes/zeek1.c");
write("You enter Zeek's house.");
}

  if(str == "struphen"){
say(this_player()->query_cap_name()+" enters Struphen's house.");
this_player()->move("/d/shadow/room/beach/homes/struphen1.c");
write("You enter Struphen's house.");
}
  if(str == "tuco"){
say(this_player()->query_cap_name()+" enters Tuco's house.");
this_player()->move("/d/shadow/room/beach/homes/tuco1.c");
write("You enter Tuco's house.");
}
  if(str == "coffee shop"){
say(this_player()->query_cap_name()+" enters the Coffee Shop.");
this_player()->move("/d/shadow/room/beach/stores/coffee.c");
write("You enter the Coffee Shop.");
}
  if(str == "weaponry"){
say(this_player()->query_cap_name()+" enters the Weaponry.");
write("You enter the Weaponry");
this_player()->move("/d/shadow/room/beach/stores/weaponry.c");
}
  if(str == "armory"){
say(this_player()->query_cap_name()+" enters the Armory.");
this_player()->move("/d/shadow/room/beach/stores/armory.c");
write("You enter the Armory.");
}
  if(str == "hospital"){
say(this_player()->query_cap_name()+" enters the Hospital.");
this_player()->move("/d/shadow/room/beach/stores/hospital.c");
write("You enter the Hospital.");
}
if(str == "restaurant"){
say(this_player()->query_cap_name()+" enters the Restaurant.");
this_player()->move("/d/shadow/room/beach/stores/restaurant.c");
write("You enter the Restaurant.");
}
  if(str == "bank"){
say(this_player()->query_cap_name()+" enters the Bank.");
this_player()->move("/d/shadow/room/beach/stores/bank.c");
write("You enter the Bank.");
}
  if(str == "general store"){
say(this_player()->query_cap_name()+" enters the General Store.");
this_player()->move("/d/shadow/room/beach/stores/gs_store.c");
write("You enter the General Store.");
}
say( this_player()->query_cap_name() +" enters.");
  return 1;
}

