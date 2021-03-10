//akanar.c - updated by ~Circe~ for new Seneca 12/3/07
#include <std.h>
#include "../seneca.h"

inherit VENDOR;

void create() {
   ::create();
   set_name("akanar");
   set_id(({"Akanar","akanar","clothier","shopkeeper","tailor"}));
   set_short("Akanar the Clothier");
   set("aggressive", 0);
/*
   set_long("
    Akanar is a fine tailor.  He stands about five foot seven and has a portly appearance.  He wears thin specticles.
%^CYAN%^<help shop> will get you a list of shop commands.\n");
*/
   set_long("Akanar is a portly, aging man who stands about five foot "+
      "seven.  His rounded belly is covered in a fabulous %^BLUE%^"+
      "indigo brocade doublet %^CYAN%^worn over a %^RESET%^silver "+
      "shirt%^CYAN%^.  Puffy %^BLUE%^indigo %^CYAN%^and %^RESET%^"+
      "silver %^CYAN%^pantaloons are worn tucked into his %^RESET%^"+
      "silver-buckled %^BOLD%^%^BLACK%^black boots%^RESET%^%^CYAN%^.  "+
      "The top of his head is bald and shiny, surrounded by a fringe "+
      "of %^RESET%^white hair %^CYAN%^he keeps carefully brushed back.  "+
      "Perched atop his nose are a pair of %^RESET%^half-moon spectacles "+
      "%^CYAN%^that he seems to spend as much time peering over as "+
      "through.  Around his shoulders are several %^ORANGE%^measuring "+
      "tapes%^CYAN%^, and a %^BOLD%^%^BLACK%^belt pouch %^RESET%^"+
      "%^CYAN%^at his waist holds %^RESET%^scissors%^CYAN%^ and other "+
      "items.  The finishing touch to his ensemble is the %^RED%^pin "+
      "cushion %^CYAN%^worn around his wrist.");
   set_gender("male");
   set_alignment(2);
   set_race("human");
   add_money("gold", random(500));
   set_property("no attack",1);
   set_level(39);
   set_hd(59,3);
   set_overall_ac(-12); 
   set_max_hp(query_hp());
   set_nwp("tailoring",20);
   set_storage_room(STORAGE"cloth_storage.c");
   set_items_allowed("clothing");
}
