#include <std.h>
#include "../elf.h"
inherit MONSTER;
void create()
{
        ::create();
        set_name("gold elf");
        set_short("A %^RESET%^%^ORANGE%^bron%^YELLOW%^z%^RESET%^%^ORANGE%^e%^WHITE%^ skinned %^GREEN%^elv%^BOLD%^e%^RESET%^%^GREEN%^n %^RED%^m%^BOLD%^a%^RESET%^%^RED%^g%^BOLD%^e%^RESET%^");
        set_id(({"elf","mage","citizen","elven mage","bronze skin elven mage"}));
        set_long(
"This green-eyed, blonde-haired elf stands upright and wears the distinctive"+
" garmets of Elven Magi.  His flowing robes are adorned with arcane symbols"+
" and there is a golden braided shoulder pad on his left shoulder denoting "+
"his Magely Rank amongst his peers.  A thin ornametal belt binds his robes at"+
" his waist where a series of pouches and a component bag hang.  "+
"With the exception of components stained on his fingers, this fellow "+
"is otherwise spotless.  He walks around gracefully and puts on an air "+
"of superiority that is hard to miss. If he happens to notice you it is"+
" only to look down at you as if you were in the way.");
        set_gender("male");
        set_race("elf");
        set_body_type("humanoid");   
        set_alignment(1);
		set_class("mage");
		set_mlevel("mage",30);
		set_hd(20,20);
		set_hp(random(300)+100);
        set_emotes(10,({
        "The elf notices you approaching and eyes you rudely.",
        "The elf adjusts a book he carries.",
        "The elf looks around and mutters to himself.",
        "The elf pulls out a parchment and reads it quietly.",    
        }),0);
        command("message in walks in with long strides.");
        command("message out leaves $D, his robe flowing behind him.");
        command("speech speak confidently");
        set_speed(9);
	  set_spells(({
       "hold person",
       "greater shout",
	   "lightning bolt",
	   "dispel magic"
   }));
   set_mob_magic_resistance("average");
   set_spell_chance(100);
   add_money("silver",random(2000));
   set_new_exp(31,"very low");
   set_max_level(35);
   set_base_damage_type("bludgeoning");
}
