//frenshaw.c - A card dealer
// Coded by Lujke April 15 2007
#include <std.h>
inherit "/d/shadow/mon/dealer.c";

void create(){
   ::create();
   set_name("Grubcheck");
   set_id( ({"grubcheck","dealer","card dealer", "grubcheck"}) );
   set_short("Grubcheck, a card dealer");
   set_long("Grubcheck is a thickset half-orc, with bulging arms and"
           +" slicked-back black hair, which is thinning on top. He's an"
           +" expert pokiir dealer and generally keeps a game running at"
           +" the Black Orc bar in Torm");
   set_gender("male");
   set_race("half-orc");
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

