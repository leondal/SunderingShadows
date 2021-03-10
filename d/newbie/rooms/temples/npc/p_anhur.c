//NPC priest for newbietown temples
//Originally a persona by Tiamat for the plot to 
//raise Anhur.  Coded by ~Circe~ 5/28/08

#include <std.h>

inherit NPC;

void create(){
   ::create();
   set_name("Ahrwah");
   set_short("Ahrwah, Lionclaw of the Warhawk");
   set_id(({"npc cleric","cleric", "ahrwah", "Ahrwah", "priestess"}));
   set_long("%^RESET%^%^CYAN%^Ahrwah is a slim human woman, athletic and strong with a healthy %^ORANGE%^sun-washed glow%^RESET%^%^CYAN%^.  She has curly %^BOLD%^%^BLACK%^ebony hair %^RESET%^%^CYAN%^worn up in a ponytail and rich, velvety %^ORANGE%^chocolate brown eyes %^CYAN%^that remind you of portraits from another age."
"  Her haunting eyes are just visible peeking out from the slits of an elaborate %^YELLOW%^headdress%^RESET%^%^CYAN%^.  A %^ORANGE%^copper disk %^CYAN%^rests upon her forehead, sprouting three %^RED%^fi%^BOLD%^er%^RESET%^%^RED%^y %^BOLD%^fe%^BLACK%^a%^RESET%^%^RED%^th%^BOLD%^er%^RESET%^%^RED%^s %^CYAN%^at even intervals, while the rest of the headdress is fashioned"
" into a clever %^YELLOW%^golden mask %^RESET%^%^CYAN%^shaped as a %^RED%^bird of prey %^CYAN%^with the %^ORANGE%^beak %^CYAN%^protecting her nose.  She is wearing loose fitting clothing ideal for desert travel, and the air around her smells warm with rich spices.  You can just barely discern a %^BOLD%^%^BLACK%^tattoo %^RESET%^%^CYAN%^creeping up her neckline.%^RESET%^");
   set_race("human");
   set_gender("female");
   set_alignment(7);
   set_diety("anhur");
   new("/d/magic/symbols/anhur_symbol")->move(TO);
   force_me("wear symbol");
   set_guild_level("cleric",25);
   set_class("cleric");
   add_search_path("/cmds/priest");
   set_spells( ({ "limb attack", "hold person", "cause critical wounds", "hold person" }) );
   set_spell_chance(50);
   set_hd(30,5);
   set_max_hp(200);
   set_hp(200);
   set_exp(10);
   set_stats("strength", 14);
   set_stats("dexterity", 17);
   set_stats("constitution", 15);
   set_stats("intelligence", 14);
   set_stats("charisma", 15);
   set_stats("wisdom", 18);
   set_db("temple_cleric");
   remove_std_db();
}

