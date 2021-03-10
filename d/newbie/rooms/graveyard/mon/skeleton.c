#include <std.h>
#include "/d/common/common.h"
inherit MONSTER;

void create() {
   ::create();
   set_name("skeleton");
   set_id(({ "skeleton","undead" }));
   set_race("undead");
   set_gender("male");
   set("short","%^BOLD%^%^WHITE%^A skeleton%^RESET%^");
   set("long","%^ORANGE%^A creature of the undead, this skeleton is just %^WHITE%^bones %^ORANGE%^that have "
"been cleaned of flesh by time and insects.  Somehow it has been caused to rise and hunt the living, skulking "
"around the graveyard.  Its bones make a %^CYAN%^clicking %^ORANGE%^sound as it moves, and its empty eye "
"sockets glow with tiny pinpricks of %^RED%^light%^ORANGE%^.%^RESET%^");
   set_hd(4,1);
   set_level(4);
   set_body_type("human");
   set_class("fighter");
   set_alignment(9);
   set_size(2);
   set_hp(random(15)+35);
   set_stats("intelligence",6);
   set_stats("wisdom",4);
   set_stats("strength",13);
   set_stats("charisma",3);
   set_stats("dexterity",9);
   set_stats("constitution",7);
   set_max_hp(query_hp());
   set_wielding_limbs( ({ "right hand", "left hand" }) );
   new(CWEAP"fauchard")->move(TO);
   command("wield fauchard");
   add_money("electrum",random(50));
   add_money("gold",random(50));
   set_property("undead",1);
   set_property("swarm",1);
   set("aggressive",20);
   set_overall_ac(9);
   set_exp(80);
   set_new_exp(1, "very low");
}
