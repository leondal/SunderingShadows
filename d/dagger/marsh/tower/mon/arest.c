#include <std.h>
inherit WEAPONLESS;

/*
void init() {
   ::init();
   add_action("no_cast","throw");
   add_action("no_cast","toss");
}
*/

void create() {
   ::create();
   set_name("arest");
   set_id(({"arest","half-dragon","warrior"}));
   set_short("%^BOLD%^%^BLUE%^Arest, half-dragon warrior%^RESET%^");
   set_long(
      "%^RESET%^%^BLUE%^Arest is an uncommon half-breed. He is one half human and one half blue dragon."+
      " Most creatues like him are the result of a dragon, polymorphed into human form,"+
      " finding a mate in a human. He retains a humanoid form, but is covered"+
     " in blue scales that are as hard as steel. From his back, a set of large"+
     " wings sprout out, giving him the look of an oversized gargoyle. His eyes"+
      " glow yellow and his teeth are as sharp as any dragon's."
   );
   set_gender("male");
   set_level(50);
   set_hd(50,9);
   set_size(3);
   set_race("half-dragon");
   set_body_type("human");
   set_weight(376);
   set_attacks_num(6);
   set_damage(4,8);
   set_base_damage_type("slashing");
   set_attack_limbs(({"right claw","left claw","jaws"})); 
   set_overall_ac(-15);
   set_class("fighter");
   set_guild_level("fighter",50);
   set_stats("strength",25);
   set_stats("constitution",25);
   set_stats("dexterity",14);
   set_stats("wisdom",12);
   set_stats("intelligence",17);
   set_stats("charisma",19);
   set_alignment(6);
   set_mob_magic_resistance("average");
   set_exp(90000);
   set_max_hp(2200);
   set_hp(2200);
   set_property("no bows", 1);
   add_money("gold",random(100000)+5000);
   set_funcs(({"stone"}));
   set_func_chance(100);
   new("/d/islands/pirates/armor/boa3.c")->move(TO);
   force_me("wear bracers");
}

void stone() {
   new("/cmds/spells/b/_blink")->use_spell(TO,TO,75,100,"mage");
   set_func_chance(0);
}
