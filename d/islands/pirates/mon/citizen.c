#include <std.h>
#include "../piratedefs.h"
inherit MONSTER;

create() {
   ::create();
   set_name("citizen");
   set_id( ({"thief","thug","citizen" }) );
   set_short("citizen");
   set_level(8);
   set_long("This is one of the unpleasant citizens of the pirate's cove.  He looks like he's sizing you up "
"as you walk past.  Or maybe he's just sizing up your purse.");
   set_gender("male");
   set_alignment(6);
   switch(random(10)) {
     case 0..4:
     set_race("human");
     set_size(2);
     break;
     case 5..7:
     set_race("half-elf");
     set_size(2);
     break;
     case 8:
     set_race("halfling");
     set_size(1);
     break;
     case 9:
     set_race("half-orc");
     set_size(2);
     break;
   }
   set_hd(6,6);
   set_hp(40+random(10));
   set_max_hp(query_hp());
   set("aggressive", 3);
   add_money("silver", random(30));
   set_body_type("human");
   set_class("thief");
   set_mlevel("thief",6);
   set_guild_level("thief",6);
   add_search_path("/cmds/thief");
   set_thief_skill("move silently",90);
   set_thief_skill("hide in shadows",90);
   set_thief_skill("pick pockets",80);
   set_scrambling(1);
   set_speed(random(20)+50);
   new("/d/common/obj/weapon/dagger")->move(TO);
   command("wield dagger");
   toggle_steal();
}