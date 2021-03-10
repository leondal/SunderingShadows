#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit MONSTER;
int exps;

void make_me(int x)
{
    switch(x) {
        case 0:
            set_short("A gnoll");
            set_hd(18,1);
            set_hp(query_hd() * 14);
            //set_exp(2200);
            set_new_exp(15, "low");
            //exps = query_exp();
            set_stats("strength",14 + random(3));
            new("/d/common/obj/weapon/battle_axe")->move(TO);
            command("wield axe");
            break;
        case 1:
            add_id("warlord");
            set_short("A gnoll warlord");
            set_hd(20,1);
            set_hp((query_hd() * 20) + random(44));
            //set_exp(3000);
            set_new_exp(18, "normal");
            //exps = query_exp();
            set_stats("strength",16 + random(3));
            switch(random(20)) {
                case 0..17:
                    new("/d/common/obj/weapon/battle_axe")->move(TO);
                    break;
                case 18..19:
                    new("/d/deku/weapons/steel_axe")->move(TO);
                    break;
            }
            command("wield axe");
            FENC->fix_nogo(TO);
            break;
        }

        new("/d/common/obj/armour/shield")->move(TO);
        command("wear shield");
        return 1;
}

void create() {
    ::create();
	set_name("gnoll");
	set_race("gnoll");
	set_gender("male");
    set_id(({"gnoll"}));
    set_long("%^YELLOW%^This foul creature towers some "+
    "seven to eight feet high, its body covered with a thick "+
    "coat of dirty %^RED%^reddish-brown%^YELLOW%^ fur.  The "+
    "head of this creature almost mimics that of a narrow "+
    "canine, with its nose as more of a snout and its "+
    "wolf-like ears pulled back in a state of ever alertness.  "+
    "The eyes of this creature are a yellow with flecks of "+
    "%^GREEN%^green%^YELLOW%^ that almost seem to shimmer "+
    "with %^RED%^bloodlust%^YELLOW%^ or at least an insatible "+
    "hunger.  The visible parts of its body are "+
    "composed of segments of sickly gray hide that "+
    "is pulled tight and battle scarred in several spots."+
    "%^RESET%^");
    //set_body_type("humanoid");
    set_alignment(3);
    set("aggressive",20);
    add_search_path("/cmds/fighter");
    set_property("full attacks",1); 
    set_stats("intelligence",12 + random(3));
   	set_stats("wisdom",11 + random(3));
   	set_stats("charisma",5 + random(3));
   	set_stats("dexterity",9 + random(5));
   	set_stats("constitution",8 + random(4)); 
	
}

