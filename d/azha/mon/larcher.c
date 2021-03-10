// Imperial Light Archer
// Thorn@ShadowGate
// 000914
// Imperial Army of Tsarven
// larcher.c

#include <std.h>
#include "/d/shadow/mon/melnmarn.h"

// Name of bow that this archer uses
#define MY_BOW_NAME "Tsarvani light recurved bow"

inherit MONSTER;

int build,reload;
string *outs,*exit_dir;

void do_check();
void do_bow();
int is_hunting_me(object agg);

int count;

create() {  
  ::create();
  set_name("archer");
  set_id( ({"light archer","an archer", "archer" }) );
  set("race", "human");
  set_gender("male");
  set("short", "Imperial Light Archer");
  set_long(
@TSARVEN
  This is a light archer of the Tsarvani Imperial Army.  Soldiers of the
Imperial Army are well-trained, well-equipped and numerous.  They
fight to protect the Empire and to promote the causes of justice
that the Empire seeks to promote.  Light archers are skilled irregular
troops able to handle both bow and scimitar for deployment in a variety
of tasks.
TSARVEN
  );
  set_class("ranger"); 
  set_level(15);  
  set_hd(15,0);     
  set_exp(1500);  
  set_body_type("human");  
  set_property("full attacks",1);
  set("aggressive", 1);  
  set_alignment(7);  
  set_size(2);  
  set_stats("intelligence",12);  
  set_stats("wisdom",12);  
  set_stats("strength",18);  
  set_stats("charisma",10);  
  set_stats("dexterity",14);  
  set_stats("constitution",16);
  set_skill("recurved bow", 200);  
  set_max_mp(0);  
  set_mp(query_max_mp());  
  set_max_hp(150);
  set_max_sp(query_hp());  
  set_sp(query_max_sp());   
  set_wielding_limbs( ({ "right hand", "left hand" }) );  
  new(LRWEAPONDIR+"arrows")->move(this_object());  
  new("/d/azha/equip/recurved_bow")->move(this_object());  
  command("wield bow in right hand and left hand");  
  new("/d/azha/equip/scimitar")->move(this_object());  
  new("/d/azha/equip/scimitar")->move(this_object());  
  new(ARMORDIR+"chain")->move(this_object());  
  command("wear armor");  
  add_money("electrum",random(10));  
  add_money("silver",random(10));  
  add_money("gold",random(40));  
  add_money("copper",random(20));  
  enable_commands();
}

void start_heart(){   
    set_heart_beat(1);
}
    
void heart_beat(){
  count++;
  do_check();
  if(objectp(query_weapon("right hand")))
  if((string)query_weapon("right hand")->query_name() != "scimitar" && count > 5)
    do_bow();
  ::heart_beat();
}

void do_bow(){
  int i,j, y,z;
  object ob, *inven, *living_bad;
  string exit,*paths, *ids; 
  living_bad = ({});
  if(ETO){
    paths = ETO->query_destinations();
    if(j = sizeof(paths)){
      for(i=0;i<j;i++){
        
        if(ob = find_object_or_load(paths[i])){
          
          inven = all_inventory(ob);
          z = sizeof(inven);
          
          for(y=0;y<z;y++)
            if(is_hunting_me(inven[y])){
              living_bad += ({inven[y]});
          }     
          if(z = sizeof(living_bad)){
            y = random(z);
            exit = ETO->query_direction(paths[i]);
            if(!interactive(living_bad[y])){    
              ids = living_bad[y]->query_id();
              command("shoot "+ids[0]+" 1 "+exit);
              command("shoot "+ids[0]+" 1 "+exit);
              command("shoot "+ids[0]+" 1 "+exit);
              command("shoot "+ids[0]+" 1 "+exit);
            }
            else
            command("shoot "+living_bad[y]->query_name()+" 1 "+exit);
            command("shoot "+living_bad[y]->query_name()+" 1 "+exit);
            command("shoot "+living_bad[y]->query_name()+" 1 "+exit);
            command("shoot "+living_bad[y]->query_name()+" 1 "+exit);
           break;
          }
        }
      }
    }
  }
  count = 0;
}

void do_check(){
    object *weapons;
    int i;
    
    weapons = TO->query_wielded();
    if(sizeof(weapons)){
        if((string)weapons[0]->query_name() != MY_BOW_NAME){
            if((object *)TO->query_attackers() == ({})){
                command("unwield sword");
                command("unwield sword 2");
                command("wield bow in right hand and left hand");
            }
        } else 
            if((string)weapons[0]->query_name() == MY_BOW_NAME){
                if((object *)TO->query_attackers() != ({})){
                    command("unwield bow");
                    command("wield scimitar in right hand");
                    command("wield scimitar 2 in left hand");
                }
            }
        }
    if(!present("arrows"))
        new("/d/shadow/obj/lrweapon/arrows")->move(TO);
}

int is_hunting_me(object agg) {
	object *hunted;
	
	if(!living(agg)) return 0;
	hunted = agg->query_hunted();
	if(member_array(TO, hunted) != -1) return 1;
	return 0;
}
