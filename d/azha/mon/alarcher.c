// Imperial Light Archer (for use of Avatars)
// Thorn@ShadowGate
// 000913
// Imperial Army of Tsarven
// alarcher.c

#include <std.h>
#include "/d/shadow/mon/melnmarn.h"

inherit MONSTER;

int build,reload;
string *outs,*exit_dir;

void do_check();
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
  set_level(24);  
  set_hd(24,0);     
  set_exp(1500);  
  set_body_type("human");  
  set_property("full attacks",1);
  set("aggressive", 25);  
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
  ::heart_beat();
}

void do_check(){
    object *weapons;
    int i;
    
    weapons = TO->query_wielded();
    if(sizeof(weapons)){
        if((string)weapons[0]->query_name() != "bow"){
            if((object *)TO->query_attackers() == ({})){
                command("unwield sword");
                command("unwield sword");
                command("wield bow in right hand and left hand");
            }
        } else 
            if((string)weapons[0]->query_name() == "bow"){
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
