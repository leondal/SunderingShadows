#include <std.h>
#include "../alliance.h"

#define JAIL "/d/guilds/alliance/hall/dungeon"
#define BDAEMON "/adm/daemon/bboard_d"
#define BOARD "alliance_board"

inherit MONSTER;

void jail_em();
void add_report(string str);
int report(int step);

object ob;
int timer, jailing, delay;
mapping reports, rfreq;

void create(){
    ::create();
    reports = ([ ]);
    set_name("White Guardsman");
    set_short("White Guardsman");
    set_id( ({"guardsman", "white guardsman", "guard", "alliance guard"}) );
    set_long(
@ALLIANCE
This is a member of the Alliance White Guard, the garrison of the 
Alliance Castle.  White Guardsmen are loyal and utterly devoted to the 
protection of their brethern and keeping the hall secure.  
ALLIANCE
        );
    set_body_type("human");
    set_race("human");
    set_overall_ac(7);
    set_hd(18, 1);
    set_class("fighter");
    set_mlevel("fighter", 18);
    set_property("no dominate",1);
    set_property("no animate",1);
    set_property("magic resistance",5);
    set_property("knock unconscious",1);
    set_property("swarm",1);
    add_search_path("/cmds/fighter");
    set_damage_bonus(1);
    set_attack_bonus(1);
    set_gender("male");
    set_property("full attacks",1);
    set_wielding_limbs(({"right hand","left hand"}));
      
    ob = new(STD_ADIR+"coif");
    ob->set_property("enchantment", 1);
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
    ob = new(STD_ADIR+"plate");
    ob->set_property("enchantment", 1);
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
        
    ob = new("/d/koenig/town/items/cloak_p2");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
    ob = new("/d/deku/armours/ring_p.c");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
    ob = new("/d/azha/obj/mr_ring.c");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
    ob = new("/realms/tristan/healing");
    ob->move(TO);
    ob->set_uses(20);
    
    ob = new("/d/guilds/alliance/obj/guardring");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
    ob = new("/d/guilds/alliance/obj/gtabard");
    ob->set_owner(TO);
    ob->move(TO);

    ob = new(STD_WDIR+"longsword");
    ob->set_property("monsterweapon", 1);
    ob->set_property("enchantment", 1);
    ob->move(TO);
    
    ob = new(STD_WDIR+"shortsword");
    ob->set_property("monsterweapon", 1);
    ob->set_property("enchantment", 1);
    ob->move(TO);
    
    command("wearall");
    command("remove band");
    command("wield long");
    command("wield short");
    set_stats("dexterity", random(8)+10);
    set_stats("strength", random(9)+10);
    set_max_hp(180);
    set_hp(query_max_hp());
    set_exp(2000);
}

void init(){
    ::init();
    add_action("pick","pick");
    if(wizardp(TP)) return;
    if("/daemon/guilds_d"->is_hc("Alliance Reborn", TP->query_name()))
    	force_me("salute "+TP->query_name());
    if(TP->in_guild("Alliance of Light")) return;
    if(present("alliance ring",TP)) return;
    if(TP->query_property("no detect")) return;
    if((string)TP->query_vehicle_type() == "riding animal") return;
    call_out("hurt_em", 0, TP);
}

void hurt_em(object targ){
    if(!present(targ, ETO)) return;
    force_me("wearall");
    cease_all_attacks();
    remove_call_out("break_em");
    if(random(1)) force_me("yell Rally to the Light!");
    else force_me("yell For the Alliance!");
    force_me("wearall");
    force_me("block up");
    force_me("rush "+targ->query_name());
    force_me("kill "+targ->query_name());
    force_me("parry");
}

void heart_beat(){
    int i, j;
    object *att;
    ::heart_beat();
    if((att = (object *)TO->query_attackers()) != ({})){
        timer = 1;
        j = sizeof(att);
        for(i=0;i<j;i++){
                force_me("rush "+att[i]->query_name());
        }
    }
    else if(timer) {
        timer++;
        if(!jailing) jail_em();
        if(timer == 5) {
            timer = 0;
            return;
        }
    }
    else if(!timer) {
    	if(delay) {
			tell_room(ETO, "%^BOLD%^The guard returns to his post.");
			TO->move("/d/shadowgate/void");
			TO->remove();
		}
		else delay = 1;
    }	

    if(present("kit",TO) && query_hp() < ((query_max_hp()/3)*2)){
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
    }
    if(present("bottle",TO)) force_me("offer bottle");
}

void jail_em() {
    object *room;
    object him;
    int i;
    
    jailing = 1;
    if(!objectp(ETO)) return;
    room = all_inventory(ETO);
    for(i=0;i<sizeof(room);i++) {
        him = room[i];
        if(wizardp(him)) continue;
        if(!living(him)) continue;
        if(him->in_guild("Alliance of Light")) continue;
        if(!him->query_unconscious()) continue;
        him->set_bound(200);
        him->set_gagged(200);
        force_me("strip "+him->query_name());
        him->move(JAIL);
        tell_room(ETO, "%^BOLD%^Some guards bind up and escort "+
                       him->query_cap_name()+" to a cell!", him);
        him->set_hp((int)him->query_max_hp()/2);
        him->do_damage(0,0);
        tell_object(him, "%^BOLD%^You wake up to find yourself bound and "
                         "dragged into a cell!");
		BDAEMON->direct_post(BOARD, "Duty Sergeant", "New prisoner", 
			"Brothers and sisters.  I have imprisoned "+
			lower_case(him->query_short())+" who was trespassing "+
			"within these halls.\n\nThis was done at:\n\n"+ctime(time())+"\n\n"+
			"Please ensure that this person is fed and dealt with as necessary.\n"+
			"\nFor the Alliance!\n\nSergeant-at-Arms on duty."
		);
    }
    jailing = 0;
}
