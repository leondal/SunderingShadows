#include <std.h>
#include "/d/deku/keep/keep.h"
inherit DAEMON;

#define POTIONS ({ "cure_poison","heal","paralyze","poison","hurt","extra_heal","invisible",\
"det_invis","hurt","weaken", "cure_poison","heal","paralyze","poison","hurt","weaken","heal",\
 "poison","hurt","paralyze","poison","cure_poison","extra_heal","poison","hurt","raging_heal",\
"poison","hurt","paralyze","hurt","weaken","invisible" })

#define ARMOR_ST ({ "chain","robe","coif","scale" })

#define WEAPON_ST ({ "mspear","halberd","warhammer","scimitar","halberd","morningstar",\
"lance","longsword" })

#define SP_STUFF ({ "graniteclub","elazoshammer","frostbitesickle","os_boots",\
	"stonecrusherhammer","stonecutter","deep_red_boots","nalreathswhip","gloom_shield",\
"shieldoflight" })

#define SP_STUFFO ({"boots_of_twilight"})

void potions(object where) {
    object ob;
    int x;
    for(x = 0;x < random(2) + 1;x++) {
        ob = new("/d/common/obj/potion/" + POTIONS[random(sizeof(POTIONS))]);
        ob->move(where);
    }
}

void norm_armors() {
    return new("/d/common/obj/armour/" + ARMOR_ST[random(sizeof(ARMOR_ST))]);
}

void norm_weapons() {
    return new("/d/common/obj/weapon/"+ WEAPON_ST[random(sizeof(WEAPON_ST))]);
}

void special_stuff() {
    switch(random(2)) {
        case 0:
            return new(KEEPO + SP_STUFF[random(sizeof(SP_STUFF))]);
            break;
        case 1:
            return new("/d/deku/armours/"+SP_STUFFO[random(sizeof(SP_STUFFO))]);
            break;
    }
}


void scrolls(object where) {
    object ob;
    int x;
    switch(random(2)) {
        case 0:
            ob = new("/d/magic/scroll");
            ob->set_spell(4 + random(2));
            ob->move(where);    
            break;
        case 1:
            for(x = 0;x < random(2) + 1;x++) {
                ob = new("/d/magic/scroll");
	            ob->set_spell(2 + random(2));
	            ob->move(where);
	        }
            break;
    }
}

void healing_potion(){
    object ob;
    ob = new("/d/common/obj/potion/healing");
    ob->set_uses(random(7) + random(7) + 1);
    return ob;
}		

void do_treasure(object where, string str, int is_chest) {
    if(str == "A") {
        if(random(101) >= 25) {
            switch(random(3)) {
                case 0:
                    healing_potion()->move(where);
			  break;
                case 1:
                    potions(where);
                    break;
                case 2:
                    scrolls(where);
                    break;
            }
        }
        if(random(101) >= 35) {
            switch(random(2)) {
                case 0:
                    norm_weapons()->move(where);
                    break;
                case 1:
                    norm_armors()->move(where);
                    break;
            }
        }
    }
 
    if(str == "B") {
        if(random(101) >= 32) {
            switch(random(3)) {
                case 0:
                    healing_potion()->move(where);
                    break;
                case 1:
                    potions(where);
                    break;
                case 2:
                    scrolls(where);
                    break;
            }
        }
        if(random(101) >= 45) {
            switch(random(2)) {
                case 0:
                    norm_weapons()->move(where);
                    break;
                case 1:
                    norm_armors()->move(where);
                    break;
            }
        }
    }

    if(str == "C") {
        if(random(101) >= 45) {
            switch(random(3)) {
                case 0:
                    healing_potion()->move(where);
				    break;
                case 1:
                    norm_armors()->move(where);
                    break;
                case 2:
                    norm_weapons()->move(where);
            }
        }

        if(random(101) >= 60) {
            switch(random(3)) {
                case 0:
                    scrolls(where);
                    break;
                case 1:
                    scrolls(where);
                    potions(where);
                    break;
                case 2:
                    scrolls(where);
                    potions(where);
                    special_stuff()->move(where);	
                    break;
            }
        }
    }
	if(is_chest)
	{
		where->set_closed(1);
		where->toggle_lock();
		return;
	}
	return;

}
	

void do_random_riddle(object chest)
{
	int x;

	string *random_riddles = ({"Repeat the phrase of the dying "+
	"golem master.", "Werewolves "+
	"dwell in this place, a keep named after its master, what "+
	"is it?", "Who is the murderer, known throughout Deku, who "+
	"wielded two axes, both gruesome?", "A servant of Silvanus, "+
	"who has done forsakken this land, but still I wander these woods, "+
	"who am I?", "Forever lost and gone forever, my red hammer "+
	"lends speed to those who could need it, who am I?", 
	"My flesh offers protection, yet it is cursed, for "+
	"while you wear it, beware, I am close, who am I?", 
	"I'm wicked and bold, I wander the forest, all alone, "+
	"my skin is wrinkled and has lost all tone, who am I?",
	"The lord of this keep, I am, my pets protect me, so "+	
	"I stand, who am I?", "The forest bears my name, "+
	"my nature is hidden, my power can maim, who am I?", 
	"I guard this sword, with all my might, beware my "+
	"wrath should you visit, day or night, of what sword do I speak?", 
	"My slasher is cruel, its bite is more than a lash, "+
	"who am I?", "My hand, though almost as old as dust, "+
	"grants power to those I would not trust, who am I?",
	"My gloves, which help at night, can help the blind and "+
	"grant their sight, who am I?", "I was a ranger in this life, "+
	"now my boots can help the worthy hide from sight, who am I?"});

	string *riddle_answers = ({"garbage should be collected", 
	"keep blacktongue", "komnoel", "drakkan", 
	"elazo", "dralthorak", "old crone", "blacktongue",
	"shadowlord", "soulcrusher", "nalreath", "hagthart",
	"ishnor", "alustian"});

	if(!objectp(chest)) return;
	x = random(sizeof(random_riddles));
	chest->set_open_riddle(random_riddles[x]);
	chest->set_open_riddle_answers(riddle_answers[x]);
	return;
}

void make_treasure_chest(object where, string str, int has_riddle, 
string *riddles)
{
	object chest;
	if(!str) str = "A";
	if(!has_riddle)
	{
		chest = new("/d/common/obj/misc/lkchest");	
		chest->move(where);
		chest->toggle_lock();
		chest->set_closed(0);
		do_treasure(chest, str, 1);
		return;
	}
	if(has_riddle)
	{
		if(!riddles)
		{
			chest = new("/d/common/obj/misc/lkchest");
			do_random_riddle(chest);
			chest->move(where);
			chest->toggle_lock();
			chest->set_closed(0);
			do_treasure(chest,str,1);
			return;
		}	
	}
}

void make_fire_chest(object where, string str, int has_riddle)
{
	object chest;
	if(!str) str = "A";
	if(!has_riddle)
	{
		chest = new("/d/common/obj/misc/chest");
		chest->make_speciality_chest("fire", "large", "lockable");
		chest->move(where);
		chest->toggle_lock();
		chest->set_closed(0);
		do_treasure(chest, str, 1);
		return;
	}
	if(has_riddle)
	{
		chest = new("/d/common/obj/misc/chest");
		chest->make_speciality_chest("fire", "large", "lockable");
		do_random_riddle(chest);
		chest->move(where);
		chest->toggle_lock();
		chest->set_closed(0);
		do_treasure(chest, str, 1);
		return;
	}
}