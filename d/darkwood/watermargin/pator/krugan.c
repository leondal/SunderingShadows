// Krugan the boatsman
// 04/06/95
// Pator@Shadowgate

#include <boathouse.h>

inherit "/std/monster";

int key_given;

reset() {
  ::reset();
  if (key_given) { 
            key_given = 0;
	   }
	}


void create() {
      object mon;
      object armor;
      ::create();
	set_name("krugan");
	set_id( ({ "krugan", "boatsman" }) );
	set("race", "human");
	set_gender("male");
	set("short", "Krugan the Boatsman");
	set("long", "Krugan the 6 feet tall Boatsman\n");
	set_level(12);
	set_body_type("human");
	set_class("ranger");
  	set("aggressive", 0);
  	set_alignment(3);
  	set_size(2);	
   	set_stats("dexterity",20);
   	set_stats("constitution",20);
	set_overall_ac(6);
   	set_max_mp(60);
   	set_mp(query_max_mp());
	set_hd(12,3);
        set_hp(90);
	set_max_hp(95);
	set_max_sp(query_hp());
 	set_sp(80);
	set_wielding_limbs( ({ "right hand" }) );
	set_languages ( ({"farsi","common","humanish"}) );
	set_emotes(5, ({"Krugan whistles a sailors song",
                        "Krugan says : Hi there. A nice day for a boatride !",
			"Krugan says : Good day .. you want to rent a boat ?",
			"Krugan says : The sails are almost dry.",
			"Krugan says : The key is lost.Darned where is it ?"})
		   ,0);
	set_achats(30,({ "I'll drown you, you insulance !!",
			 "If I had the key, I'ld get my watersword !!" }) );
	        mon = new("/d/shadow/obj/weapon/knife");
		mon->set_name("sailor's knife");
		mon->set_id(({"sailor's knife","knife"}));
		mon->set_short("A sailor's knife");
		mon->set_long("This is a sharp knife for cutting rope and wood.");
		mon->set_wc(4);
                mon->set_hd(1,8);
		mon->set_large_hd(2,10);		
		mon->move(this_object());
      	command("wield knife in right hand");
	armor = new("/d/shadow/obj/armor/leather");
		armor->set_name("sailor's jersey");
		armor->set_id(({"sailor's jersey","jersey"}));
		armor->set_short("A sailor's jersey");
		armor->set_long("This is a striped jersey, usually worn by sailors.");
		armor->set_limbs( ({"torso"}) );
		armor->set_ac(4);
		armor->set_decay_rate(3);
		armor->move(this_object());
      	command("wear jersey");
	
	add_money("silver",random(50));
	add_money("gold",random(5));
	add_money("copper",random(10));
	key_given=0;
}

void catch_tell(string str) {
	object sword;
        string who;

    if(!sscanf(str, "%s gives %*s", who)) { return; }
    if(!present(lower_case(who))) return;
if (interact("gives",str))  {
	if (interact("you",str)) {
			if(interact("key",str)) {
				if (present("iron key")) {
				    tell_room(environment(this_object()),
@GETITEM
Krugan pulls the chest from behind the ropes and turn the key in the lock.
After that he gives the dail a swing and the lock jumps open.  Krugan opens
the chest and get's an item which he gives to you.  He says : "This can be
a very powerfull weapon, but I forgot the words of magic to it .   Use it
well, my brave adventurer !!
GETITEM
							,({this_object()}));
				sword = new(WATERM_BH+"H2Osword1.c");
				sword->move(this_object());
				if (present(lower_case(who))) 	{
				command("give sword to "+who);
			        }
				first_inventory(this_object())->remove();
				 }
				else			    {
				command("drop iron key");
							    }
				key_given = 1;
							}
						  }
				  }
				}
