#include "./melnmarn.h";

inherit MONSTER;
int build,reload;
string *outs,*exit_dir;

create() {
    ::create();
    set_name("archer");
    set_id( ({ "an archer", "archer" }) );
    set("race", "human");
    set_gender("male");
    set("short", "An archer");
    set("long", "An Elite archer assigned to guard the city walls\n");
    set_level(14);
    set_body_type("human");
    set_class("fighter");
    set("aggressive", 25);
    set_alignment(7);
    set_size(2);
    set_stats("intelligence",12);
    set_stats("wisdom",12);
    set_stats("strength",18);
    set_stats("charisma",10);
    set_stats("dexterity",14);
    set_stats("constitution",16);
    set_max_mp(0);
    set_mp(query_max_mp());
    set_hd(14, 1);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());	
    set_wielding_limbs( ({ "right hand", "left hand" }) );
    new(LRWEAPONDIR+"arrows")->move(this_object());
    new(LRWEAPONDIR+"shortbow")->move(this_object());
    command("wield bow in right hand and left hand");
    new(WEAPONDIR+"longsword")->move(this_object());
    new(ARMORDIR+"chain")->move(this_object());
    command("wear armor");
    add_money("electrum",random(10));
    add_money("silver",random(10));
    add_money("gold",random(5));
    add_money("copper",random(20));
}

void start_heart(){
	set_heart_beat(1);
}
void heart_beat(){
   object *ob;
   int inc,inc2,exits;

   build ++;reload++;
   if(build == 2){
    outs = environment(TP)->query_destinations();
    exit_dir = environment(TP)->query_exits();
     for(inc2 = 0;inc2<sizeof(outs);inc2++){
	if(!ob = all_inventory(find_object_or_load(outs[inc2])))
		continue;
	else
	for(inc = 0;inc < sizeof(ob);inc ++){
	if(interactive(ob[inc]))
		command("shoot "+ob[inc]->query_name()+" 1 "+exit_dir[inc2]);
	}
    }
    build = 0;
    }
    if(!TO->query_weapon("right hand")) 
	command("wield longsword in right hand");
    if( (reload == 300) && (!present("arrows",TO)) ){
	new(LRWEAPONDIR+"arrows")->move(TO);
	if((string)TO->query_weapon("right hand") == "longsword")
	    command("unwield longsword");
	if(!TO->query_weapon("right hand"))
	    command("wield bow in right hand and left hand");
	reload = 0;
    }
  ::heart_beat();
}
