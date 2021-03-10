// High Mortal board
// Do not clone this board, without set_location(string dest) it won't
// work properly. Check /std/bboard.c for details.
// Obsidian@ShadowGate 5/6/00

#include <std.h>

string maker;

inherit BBOARD;

void set_maker(string who);
string query_maker();

void set_maker(string who){ maker = who; }

string query_maker(){ return maker; }

void init(){
   if((string)TPQN == maker) ::init();
}

void create(){
   ::create();
   set_name("high mortal board");
   set_id( ({"hmboard","hm board","high-mortal board"}) );
   set_board_id("high_mortal_board");
   set_short("The High Mortal board");
   set_long("This a mystic, magically created illusionary board for "
      "High Mortals in ShadowGate to discuss current MUD issues.\n");
   set_max_posts(100);
   set_heart_beat(30);
}

string query_long(string junk){
   if(avatarp(TP) || (string)TPQN == maker) return ::query_long(junk);
   else return "You do not notice that here.";
}

string query_short(){
   if(avatarp(TP) || (string)TPQN == maker) return ::query_short();
   else return 0;
}

void heart_beat(){
   if(!objectp(TO) || !objectp(ETO)) return;
   if(!present(maker,ETO)) remove();
}
