#include <std.h>
#include "../../inherit/keep.h"
inherit MONSTER;

void create() {
   ::create();
   set_name("half-ogre");
   set_id(({"half-ogre","halfogre","brutish half-ogre"}));
   set_short("%^RESET%^%^ORANGE%^a brutish half-ogre%^RESET%^");
   set_long("%^GREEN%^This half-ogre is incredibly large, even for one of his race, standing over eight feet "
"tall. He has wirey, greasy %^BOLD%^%^BLACK%^black hair %^RESET%^%^GREEN%^and his skin is a sickly shade of "
"%^YELLOW%^yellow%^RESET%^%^GREEN%^. He is quite ugly, with a large leering %^WHITE%^grin %^GREEN%^on his face "
"showing that he's also missing a couple of teeth. He is fairly %^ORANGE%^dirty %^GREEN%^and appears to use "
"his clothing as a napkin judging by the grease marks.%^RESET%^");
   set_race("half-ogre");
   set_body_type("human");
   set_gender("male");
   set_size(3);
   set("aggressive",25);
   set_property("swarm",1);
   set_level(4);
   set_class("fighter");
   set_mlevel("fighter",6);
   set_max_hp(65);
   set_hp(65);
   set_exp(550);
   set_stats("strength",18);
   set_stats("dexterity",11);
   add_damage_bonus(-3);
   set_ac(6);
   set_alignment(9);
   new(OBJ2"lclub")->move(TO);
   command("wield club");
   new(OBJ2"lrobe")->move(TO);
   command("wear robe");
   add_money("gold",random(100)+20);
   add_money("silver",random(700)+50);
   set_emotes(6,({
     "%^RED%^The half-ogre growls menacingly.%^RESET%^",
     "%^ORANGE%^The half-ogre roars and beats his chest.%^RESET%^",
     "%^BLUE%^The half-ogre stomps his feet angrily.%^RESET%^",
   }),1);
   set_new_exp(1, "very low");
}
