#include <std.h>

inherit NPC;

void create(){
   ::create();
   set_nwp("forage", 4, 500);
   set_nwp("skinning", 4, 500);
   set_nwp("hunting", 4, 500);
   set_name("doran");
   set_id(({"doran","Doran","wanderer"}));
   set_short("Doran, a wanderer");
   set_long(
@STYX
Doran is a rugged looking man, the outdoor life he's led clearly showing in his deep tan and otherwise weather-beaten skin with the resultant wrinkles.  His dark brown hair is graying and receding around the temples and his thick, unkempt beard is laced with gray as well.  He wears simple leather clothing with a pouch around his waist and you see the hilt of what looks to be a very sturdy looking knife sticking out of a small sheath tied on his thigh.
STYX
);
   set_gender("male");
   set_race("human");
   set_body_type("human");
   set_hd(10,3);
   set_max_level(10);
   set_size(2);
   set_alignment(8);
   set_overall_ac(5);
   set_max_hp(random(10)+60);
   set_hp(query_max_hp());
   set_exp(100);
   set_level(10);
   set_class("mage");
   set_mlevel("mage",10);
   set_guild_level("mage",10);
   set_stats("intelligence", 18);
   set_stats("wisdom", 18);
   set_stats("strength", 10);
   set_stats("charisma", 9);
   set_stats("dexterity", 16);
   set_stats("constitution", 12);
   set_mob_magic_resistance("average");
   set_property("full attacks",1);
   set_property("alignment adjustment",-1);
   add_money("electrum",random(500));
   set_speed(80);
   set_spell_chance(90);
   set_spells(({"hold person","acid arrow","hold person","lightning bolt", "magic missile", "magic missile"}));
   set_spoken("wizish");
   set_emotes(1,({
     "%^MAGENTA%^Doran mutters:%^RESET%^ Kids these days.  They know nothin' about survivin' in the wilderness.",
     "%^MAGENTA%^Doran grins: %^RESET%^Ya here ta learn somethin' or not?",
     "%^MAGENTA%^Doran mutters:  %^RESET%^I s'pose none care ta learn basics like skinning and how to forage for food any more.",
     "%^MAGENTA%^Doran muses: %^RESET%^There's sure more challenge ta life than killin', if kids only realized afore it's too late.",
     "Doran pulls a handful of nuts out of a pouch and munches on them.",
     "Doran offers you a juicy berry but then pops it in his mouth before you can grab it and laughs heartily.",
   }), 0);
        new("/d/newbie/obj/misc/lpouch.c")->move(TO); //added in on advice of Tristan that we need more stealable things in newbieland Ts
}

void init(){
   ::init();
}
