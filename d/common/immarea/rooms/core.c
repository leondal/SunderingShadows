#include <std.h>

inherit ROOM;

int is_interactive(object ob) {
  if (interactive(TP)) return 1;
  else return 0;
}

void place_board()
{
    object ob;
    if (present("new avatar board", TO)) 
    {
        return;
    }
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "bulletin board", "new avatar board" }) );
    ob->set_board_id("new_avatar_board");
    ob->set("short", "Avatar board");
    ob->set("long", "A large board where the avatars of the realm may post.");
    ob->set_max_posts(300);
    ob->set_location("/d/common/immarea/rooms/core");
    ob->set_restricted_read();
    ob->set_ooc_board(1);    
}

void create()
{
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no scry",1); // added by Lujke 12 November 2007
    set_property("no teleport",1);
    set_short("Avatar's Lounge");
    set_long(
"%^BOLD%^%^RED%^Avatar Lounge%^RESET%^
Commands available:
%^ORANGE%^<push button 1>%^RESET%^ %^BLUE%^--%^RESET%^ avatar stick. 
%^ORANGE%^<push button 2>%^RESET%^ %^BLUE%^--%^RESET%^ ambassador ring
%^ORANGE%^<push button 3>%^RESET%^ %^BLUE%^--%^RESET%^ prof cleaner
%^ORANGE%^<push button 4>%^RESET%^ %^BLUE%^--%^RESET%^ cloning wand
%^ORANGE%^<push button 5>%^RESET%^ %^BLUE%^--%^RESET%^ undercommon wand
%^ORANGE%^<push button 6>%^RESET%^ %^BLUE%^--%^RESET%^ id adder

%^ORANGE%^<pull lever>%^RESET%^    %^BLUE%^--%^RESET%^ cube
%^ORANGE%^<pull cord>%^RESET%^     %^BLUE%^--%^RESET%^ universal remote.
"
    );
    set_exits(([
                   "hub": "hub"
                   ]));
}

void reset() 
{
    ::reset();
    place_board();
}

void init(){
    ::init();
    add_action("push","push");
    add_action("pull","pull");
}


int push(string str) {
   if(!str) {
      write("You might want to <push button #>.");
      return 1;
   }
   if(str == "button 1") { 
      new("/d/common/immortals/wand")->move(TP);
      write("You receive a strange stick.");
      return 1;
   }
   if(str == "button 2") {
      new("/d/common/obj/special/ambassador_ring")->move(TP);
      write("You receive a cool brass ring and might want to <review commands>.");
      return 1;
   }
   if(str == "button 3") { 
      new("/d/common/immortals/prof_clearer.c")->move(TP);
      write("You receive a strange device used to reset profs.");
      return 1;
   }
   if (str == "button 4"){
      new("/d/common/immortals/clone_wand")->move(TP);
      write("You receive a wand that seems a lot like a lot of other wands.");
      return 1;
  }
   if (str == "button 5"){
      new("/d/common/immortals/undercommon_wand")->move(TP);
      write("You receive a wand for granting undercommon to players.");
      return 1;
   }
   if (str =="button 6"){
      new("/d/common/immortals/id_adder")->move(TP);
      write("You recieve a nifty id adder, for adding new ids to mobs. "
           +" You can <read adder> for instructions.");
     return 1;
   }
   return 0;
}

int pull(string str) {
   if(!str) {
      write("You might want to <pull lever/cord>.");
      return 1;
   }
   if(str == "lever") { 
      new("/realms/crystal/obj/cube")->move(TP);
      write("You recieve a strange and magical cube.");
      return 1;
   }
   if(str == "cord") {
      new("/d/common/immortals/universalremote")->move(TP);
      write("You receive the AWESOME new universal remote!");
      return 1;
   }
   return 0;
}

