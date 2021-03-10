//jontar.c - The Old Priest                                 
// Coded by Lujke 29/12/06
#include <std.h>
inherit "/d/shadow/mon/dealer.c";

void create(){
   ::create();
   set_name("Frenshaw");
   set_id( ({"frenshaw","dealer","card dealer", "Frenshaw"}) );
   set_short("Frenshaw, a card dealer");
   set_long("");
   set_gender("male");
   set_race("human");
   set_body_type("human");
   set_hd(70,5);
   set_alignment(5);
   set_max_hp(2500);
   set_hp(query_max_hp());
   set_overall_ac(-30);
   set_class("fighter");
   set_mlevel("fighter",35);
   set_level(35);
   set_stats("wisdom",19);
   set_stats("strength",18);
   set_stats("constitution",18);
   set_stats("intelligence",18);
   set_stats("charisma",16);
   set_stats("dexterity",18);
   set_exp(60);
   set("aggressive",0);
}

