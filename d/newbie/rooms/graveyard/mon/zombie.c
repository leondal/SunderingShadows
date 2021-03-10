#include "/d/common/common.h"
#include <std.h>
inherit MONSTER;

void create() {
   ::create();
   set_name("zombie");
   set_id(({"zombie","Zombie","undead","putrid zombie"}));
   set_gender("male");
   set_race("zombie");
   set_short("%^RESET%^%^GREEN%^A putrid zombie%^RESET%^");
   set_long("%^GREEN%^This zombie's flesh is %^ORANGE%^sickly %^GREEN%^and %^BLUE%^rotted%^GREEN%^, with bits "
"of skin hanging off it.  It is clad in %^ORANGE%^tattered rags %^GREEN%^that may once have been clothing, and "
"emits an utterly %^MAGENTA%^putrid %^GREEN%^smell.  Its eyes have a dull, %^YELLOW%^yellowish "
"%^RESET%^%^GREEN%^glow and its %^BOLD%^%^BLACK%^hair %^RESET%^%^GREEN%^is stringy and thin over a mostly bald "
"scalp.  The zombie shambles around on stiff legs, emitting a ghastly %^BLUE%^moan%^GREEN%^.%^RESET%^");
   set_hd(4,1);
   set_property("undead",1);
   set_property("swarm",1);
   set_body_type("human");
   set_class("fighter");
   set_level(4);
   set_size(2);
   set_alignment(9);
   set_stats("intelligence",16);
   set_stats("wisdom",8);
   set_stats("strength",12);
   set_stats("charisma",3);
   set_stats("dexterity",9);
   set_stats("constitution",10);
   set_max_hp(30);
   set_hp(30);
   set("aggressive",20);
   add_money("gold",random(25)+25);
   new(CWEAP"mace")->move(TO);
   command("wield mace");
   set_overall_ac(8);
   set_exp(60);
   set_achats(1,
     ({ "%^RED%^The zombie's eyes seem to glow red.%^RESET%^",
        "%^ORANGE%^The zombie lunges toward your throat!%^RESET%^"
     }) );
   set_new_exp(1, "very low");
}
