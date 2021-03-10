#include <std.h>
#include "../undead.h"

inherit CREATURE;
string *killers;

int build,reload;
string *outs,*exit_dir;

void do_bow();

int count;

create() 
{    
	::create();
    killers = ({});
    set_name("Elven archer");
    set_id(({"archer", "elf", "elven archer"}));
    set_race("elf");
    set_body_type("human");
	set_gender("male");    
    set_short("%^BOLD%^Elven archer%^RESET%^");
    set_long("This is an elven archer come to aid the valient defenders "
        "of Graez.  He has the typical high cheekbones and detailed features "
        "of his elven brethren, but there is a hollow look in his eyes as if "
        "all the years of war are finally starting to wear on his spirit.");
    set_level(20);
    set_hd(20,0);
    set_exp(3000);
    set_new_exp(25,"normal");
    set_class("fighter");    
    set_property("swarm",1);
    set_property("aggressive",8);
    set_alignment(1);
    set_size(2);    
    set_stats("intelligence",12);    
    set_stats("wisdom",12);    
    set_stats("strength",18);    
    set_stats("charisma",10);    
    set_stats("dexterity",19);    
    set_stats("constitution",16);    
    set_attack_bonus(5);
    set_damage_bonus(3);
    set_hp(200); 
    new(CLRWEAP"larrows.c")->move(TO);
    new(CLRWEAP"longbow.c")->move(TO);
	command("wield bow");    
	new(CARMOR"chain")->move(TO);    
	command("wear chain");    
    add_money("electrum",random(50));    
    add_money("silver",random(20));    
    add_money("copper",random(50));    
}

	
void heart_beat()
{
	count++;
	do_bow();
	::heart_beat();
    return;
}

void do_bow()
{
	int i,j, y,z;
	object ob, *inven, *living_bad;
	string exit,*paths, *ids;
	
	living_bad = ({});
	if(ETO)
    {
		paths = ETO->query_destinations();
		if(j = sizeof(paths))
        {
			for(i=0;i<j;i++)
            {			
				if(ob = find_object_or_load(paths[i]))
                {				
					inven = all_inventory(ob);
					z = sizeof(inven);
				
					for(y=0;y<z;y++)
                    {
						if(interactive(inven[y]))
                        {
							living_bad += ({inven[y]});
						}
                    }
				
					if(z = sizeof(living_bad))
                    {
						y = random(z);
						exit = ETO->query_direction(paths[i]);
						if(!interactive(living_bad[y]))
                        {	
							ids = living_bad[y]->query_id();
                            if(member_array("undead",ids) != -1) { continue; }
							command("shoot "+ids[0]+""+exit);
						}
						else
							command("shoot "+living_bad[y]->query_name()+""+exit);
						break;
					}
				}
			}
		}
	}
	count = 0;
}




