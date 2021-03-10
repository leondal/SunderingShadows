#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit MONSTER;
int exps;

void make_me(int x) 
{
    switch(x) 
	{
		case 0:
            set_short("A kobold with red eyes");
	        set_hd(18 + random(3),1);
      	    set_hp(350 + random(31));
		    set_stats("intelligence",6);
	        if(!random(4)) 
			{ 
                new("/d/common/obj/weapon/shortsword")->move(TO);
                command("wield sword");
            }
            break;
        case 1:
            add_id("sorcerer");
            set_short("A kobold sorcerer");
            //set_property("no bows",1);
            set_class("mage");
            set_mlevel("mage",18);
            set_guild_level("mage",TO->query_level("mage"));
            set_hp(325 + random(31));
            set_spells(({"fireball","scorcher","acid arrow",
            "lower resistance","blink"}));
            set_spell_chance(75);
            set_mob_magic_resistance("average");
            set_stats("intelligence",14);
            if(!random(4)) 
            {
                new("/d/deku/weapons/rune_wand")->move(TO);
                command("wield wand");
            }
            break;
    }
    set_new_exp(18, "normal");
}

void create() 
{
    ::create();
	set_name("kobold");
	set_id(({ "kobold" }) );
	set_race("kobold");
	set_gender("male");
 	set_stats("wisdom",4);
   	set_stats("strength",15);
   	set_stats("charisma",3);
   	set_stats("dexterity",12);
   	set_stats("constitution",14);
   	new("/d/common/obj/weapon/dagger")->move(TO);
    command("wield dagger");
    set("aggressive",13);   
    set_alignment(3);
    set_long("This short reptillian creature has a head that "+
    "almost resembles that of a canine.  Its head is long, "+
    "with a snout that reveals rows of pointed teeth "+
    "when opened.  Its eyes are a strange and glowing %^RED%^"+
    "red%^CYAN%^ that reflect a mixture of curiosity and "+
    "anger.  The top of its head is adorned by two small and "+
    "pointed off-white horns.  The rest of its scaly body is "+
    "a rusty hue that borders on charred black.  Its feet and "+
    "hands are clawed and it sprouts a small and rat like tail.");
}

