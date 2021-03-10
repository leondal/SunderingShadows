//Coded by Bane//
#include <std.h>
#include <daemons.h>
inherit "/d/laerad/mon/wander/asswander.c";
object ob, *attackers;
string mehunted, file, env, *files, *exts, outs;
int i;

void create(){
    ::create();
    set_id(({"assassin","nimbus"}));
    set_name("nimbus");
    set_short("Nimbus the Assassin");
    set_long(
	"Nimbus is an assassin bounty hunter.  He is rather short fellow "+
	"hooded in a black cloak.  His face is stern and chiseled, obviously a "+
	"veteran in the gentle art of making enemies."
    );
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_size(2);
    set_alignment(5);
    set_hd(random(25)+15,1);
    set_hp(query_hd()*12);
    set_exp(query_hd()*750);
    set_overall_ac(-15);
    set_class("assassin");
    set_guild_level("assassin",query_hd());
    set_mlevel("assassin",query_hd());
    set_class("thief");
    set_guild_level("thief",query_hd());
    set_mlevel("thief",query_hd());
//thief levels added so he'd wield weapons ~Circe~ 4/28/08
    set_stats("strength",19);
    set_stats("dexterity",19);
    set_stats("charisma",17);
    set_stats("constitution",20);
    set_stats("intelligence",16);
    set_stats("wisdom",20);
    set_mob_magic_resistance("average");
    set_property("full attacks",1);
    set_property("no dominate",1);
    set_property("no death",1);
    set_property("no rush",1);
    set_property("bounty hunter",1);
    add_money("gold",random(1200)+500);
    add_money("copper",random(2500)+2500);
    ob = new("/d/attaya/obj/screamer");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wield screamer");
    ob = new("/d/attaya/obj/screamer");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wield screamer");
    ob = new("/d/tharis/obj/wrist_sheath");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wear sheaths");
    ob = new("/d/attaya/obj/screamer");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("put screamer in sheaths");
    ob = new("/d/common/obj/potion/healing.c");
    ob->move(TO);
    ob->set_property("no animate",1);
    ob->set_uses(75);
    ob = new("/d/tharis/obj/bpowder");
    ob->move(TO);
     if(random(50)) ob->set_property("monsterweapon",1);
    ob->set_property("monsterweapon",1);
    add_search_path("/cmds/assassin");
    set_thief_skill("hide in shadows",95);
    set_thief_skill("move silently",95);
    set_invis();
    files = ({});
}
void init(){
    string *bounty;
    int money;
    mapping mbounty;
    ::init();
    if(wizardp(TP)) return 1;
    if((int)TP->query_level() < 20 && (int)TP->query_level() < (int)TO->query_level()) return 1;
    bounty = (string *)KILLING_D->query_bounties();
    mbounty = KILLING_D->query_personal_bounties();
    if(member_array(TP->query_name(),bounty) != -1){
	money = mbounty[TP->query_name()]["money"];
	force_me("say Aye! Looks like we have a wanted one here!");
	if(TP->query_invis()){
	    TP->set_invis();
	}
	call_out("stab_em",1,TP);
	mehunted = (string)TP->query_name();
	return 1;
    }
}
void stab_em(object ob){
    command("stab "+ob->query_name());
    TO->kill_ob(ob,1);
    set_invis();
    return 1;
}
void heart_beat(){
        int i, j;
	object *att;
        ::heart_beat();
        if((att = (object *)TO->query_attackers()) != ({})){
                j = sizeof(att);
                for(i = 0;i <j;i++){
			call_out("force_me",2,"crit "+att[i]->query_name());
			if((int)att[i]->query_property("powdered") != 1){
			    if(interactive(att[i])){
				force_me("throw powder at "+att[i]->query_name());
			    }
			}
                }
        }
    if((object *)TO->query_attackers() == ({})){
	if(TO->query_invis() == 0){
	    set_invis();
	}
    }
    if(query_hp() < 100 && present("kit",TO)){
	force_me("open kit");
	force_me("quaff kit");
	force_me("offer bottle");
	force_me("quaff kit");
	force_me("offer bottle");
	force_me("quaff kit");
	force_me("offer bottle");
	force_me("quaff kit");
	force_me("offer bottle");
	force_me("quaff kit");
	force_me("offer bottle");
	force_me("quaff kit");
	force_me("offer bottle");
	force_me("quaff kit");
	force_me("offer bottle");
    }
    if(present("bottle",TO)){
	force_me("offer bottle");
    }
    if(mehunted && !present(mehunted, ETO)){
	ob = find_player(mehunted);
	if(ob->query_ghost()){
	    mehunted = 0;
	    return 1;
	}
	if(!random(15)){
	    call_out("find_em",1);
	}
    }
}
void find_em(object ob){
    files = ({});
    ob = find_player(mehunted);
    if(!random(5)) mehunted = 0;
    if(!mehunted) return 1;
    env = environment(ob);
    file = file_name(env);
    files += ({file});
    exts = env->query_exits();
    for(i=0;i<sizeof(exts);i++){
	outs = find_object_or_load(env->query_exit(exts[i]));
	file = file_name(outs);
	files += ({file});
    }
    file = files[random(sizeof(files))];
    find_object_or_load(file);
    TO->move(file);
    return 1;
}
string query_mehunted(){return mehunted;}
string query_file(){return file;}
string *query_files(){return files;}
