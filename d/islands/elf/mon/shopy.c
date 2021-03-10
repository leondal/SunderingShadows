#include <std.h>
#include "../elf.h"
inherit INTERACTIVE;

void create()
{
        ::create();
        remove_std_db();
        remove_dbs(({"miscvendors"}));
        remove_random_act_dbs(({"miscvendorsrandom"}));
        set_items_allowed("misc");
        set_name("Dinendal Nenharma");
        set_short("Dinendal Nenharma, a gold elf");
        set_id(({"shop keeper","elf","dinendal","shop keep","Dinendal"}));
        set_long(
        "Dinedal is an alchemist who likes to show off his"+
		" wares.  He has golden hair and amber eyes and wears"+
		" a bright red robe that is yellow trimmed.  "+
		"Some of the craftsmen trust him with their items"+
		" that he distributes and trades for them.  " );
        set_gender("male");
        set_race("elf");
        set_alignment(1);
        set_hd(20,5);
        set_max_hp(150+random(200));
        set_overall_ac(-7);
        set_class("mage");
        set_class("fighter");
        set_mlevel("mage",20);
        set_mlevel("fighter",20);
        set_level(20);
        set_stats("intelligence",18);
        set_stats("strength",10);
        set_stats("charisma",18);
        set_stats("constitution",15);
        set_stats("dexterity",10);
        set_stats("wisdom",12);
        set_spells(({
        "hideous laughter",
        "magic missile",
        "chain lightning",
        "phantom guardians",
        "fireball",
        "monster summoning vii",
        "web",
        "hold person",
        }));
        set_spell_chance(100);
        set_storage_room(STOR"magic.c");
        set_skill("perception",50);
        add_money("copper",random(100));
        force_me("speech talk proudly");
	    set_spoken("elven");
		set_new_exp(30,"very low");
        set_max_level(35);
		set_base_damage_type("bludgeoning");
		switch (random(18)){
	     case 0: 
             new(OBJ"afire")->move(TO);
			 break;
         case 1:
             new(OBJ"bioun")->move(TO);
			 break;
	     case 2:
             new(OBJ"mr_ring")->move(TO);
			 break;
         case 3:
             new(OBJ"dart")->move(TO);
			 break;
         case 4:
             new(OBJ"sbrooch")->move(TO);
			 break;
         case 5:
             new(OBJ"flower")->move(TO);
			 break;
         case 6:
             new("/d/common/obj/potion/cure_blindness")->move(TO);
			 break;
         case 7:
             new("/d/common/obj/potion/det_invis")->move(TO);
			 break;
         case 8:
             new(OBJ"seed")->move(TO);
			 break;
         case 9:
             new("/d/common/obj/misc/paper")->move(TO);
			 break;
         case 10:
             new("/d/common/obj/misc/canvas")->move(TO);
			 break;
         case 11:
             new("/d/common/obj/misc/book")->move(TO);
			 break;
         case 12:
             new("/d/common/obj/misc/quiver")->move(TO);
			 break;
         case 13:
             new(OBJ"iioun")->move(TO);
			 break;
         case 14:
             new(OBJ"sheath")->move(TO);
			 break;
         case 15:
             new(OBJ"sack")->move(TO);
			 break;
         case 16:
             new("/d/common/obj/lrweapon/larrows")->move(TO);
			 break;
         case 17:
             new(OBJ"cloak")->move(TO);
			 break;
   }
}
