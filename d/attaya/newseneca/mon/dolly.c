//toymaker.c - by ~Circe~ for new Seneca 11/25/07
#include <std.h>
#include "../seneca.h"

inherit VENDOR;

void create() {
   ::create();
   set_name("toymaker");
   set_id(({"Toymaker","toymaker","shopkeeper"}));
   set_short("Toymaker, a placeholder");
   set_long("Yup, Toymaker here is a placeholder to see how the "+
      "items load.  I'm sure eventually he should have a description.\n\n"+
      "%^RESET%^%^CYAN%^<%^RESET%^help shop%^CYAN%^> %^RESET%^"+
      "will get you a list of shop commands.\n");
   set_gender("male");
   set_alignment(2);
   set_race("human");
   add_money("gold", random(500));
   set_level(30);
   set_hd(30,20);
   set_hp(200+roll_dice(30,20));
   set_class("fighter");
   set_mlevel("fighter",30);
   set_guild_level("fighter",30);
   set_stats("strength",19);
   set_stats("dexterity",17);
   set_overall_ac(-21); 
   set_max_hp(query_hp());
   set_nwp("tailoring",20);
   set_storage_room(STORAGE"toy_storage.c");
   force_me("speech say in a gruff voice");
   set_items_allowed("misc");
}