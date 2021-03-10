#include <std.h>

inherit "/std/monster.c";
int build,reload;
string *outs,*exit_dir;

create() {
    ::create();
    set_name("keep archer");
    set_id( ({ "keep archer","orc", "archer" }) );
    set("race", "orc");
    set_gender("male");
    set("short","Keep archer");
    set("long","An elite archer assigned to guard Keep Blacktongue.\n"+
               "Obviously an orc because of his extreme smell and \n"+
               "stupid looks.\n");
    set_level(7);
    set_body_type("human");
    set_class("fighter");
    set("aggressive", 20);
    set_alignment(6);
    set_size(2);
    set_hd(7,1);
    set_stats("intelligence",12);
    set_stats("wisdom",12);
    set_stats("strength",18);
    set_stats("charisma",7);
    set_stats("dexterity",17);
    set_stats("constitution",16);
    set_hp(65);
    set_max_hp(query_hp());
    set_wielding_limbs( ({ "right hand", "left hand" }) );
    new("/d/common/obj/lrweapon/arrows")->move(TO);
    new("/d/common/obj/lrweapon/arrows")->move(TO);
    new("/d/common/obj/lrweapon/shortbow")->move(TO);
    new("/d/common/obj/weapon/longsword")->move(TO);
    command("wield longsword");
    add_money("electrum",random(50)+50);
    add_money("silver",random(100));
    add_money("gold",random(50));
    enable_commands();
}

void start_heart(){
	set_heart_beat(1);
}
void heart_beat(){
   object *ob;
   int inc,inc2,exits;

   build ++;reload++;
   if(build == 2){
    outs = ETP->query_destinations();
    exit_dir = ETP->query_exits();
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
	command("wield longsword");
    if( (reload == 300) && (!present("arrows",TO)) ){
        new("/d/common/obj/lrweapon/arrows")->move(TO);
	if((string)TO->query_weapon("right hand") == "longsword")
	    command("unwield longsword");
	if(!TO->query_weapon("right hand"))
	    command("wield bow in right hand and left hand");
	reload = 0;
    }
  ::heart_beat();
}
