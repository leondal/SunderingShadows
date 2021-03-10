#include <std.h>

#define JAIL "/d/guilds/alliance/hall2/dungeon"
#define BDAEMON "/adm/daemon/bboard_d"
#define BOARD "alliance_board"

inherit NPC;

void jail_em();
void add_report(string str);
int report(int step);

object ob;
int timer, jailing;
mapping reports, rfreq;

void create(){
    ::create();
    reports = ([ ]);
    set_name("Bors");
    set_short("Bors, the Alliance jailer");
    set_db("bors");
    set_random_act_db("borsrandom");
    set_id( ({"guard", "jailer", "alliance jailer", "bors"}) );
    set_long(
@ALLIANCE
Bors is the jailer of the Alliance dungeons.  He wears light, but 
strong woven coverings, more comfortable than metal armor, and very 
effective against unarmed prisoners.  Although Bors is a member of the 
Alliance of Light, he looks just as mean as any jailer would who is 
charged with guarding the most dangerous prisoners in the realms. 
Broad of shoulder, strong of arm, and ever vigilant, I wouldn't 
challenge with this guy unless you know what you are doing.

If you want to know what he does, just ask him what he does.
ALLIANCE
        );
    set_body_type("human");
    set_race("human");
    set_overall_ac(5);
    set_hd(45, 1);
    set_class("fighter");
    set_mlevel("fighter", 45);
    set_property("no dominate",1);
    set_property("no animate",1);
    set_mob_magic_resistance("average");
    set_property("knock unconscious",1);
    set_property("swarm",1);
    add_search_path("/cmds/fighter");
    set_damage_bonus(2);
    set_attack_bonus(2);
    set_gender("male");
    set_property("full attacks",1);
    set_wielding_limbs(({"right hand","left hand"}));
      
    ob = new("/d/antioch/ruins/obj/heavens_mace");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
    ob = new("/d/attaya/obj/lgauntlets");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
    ob = new("/d/attaya/obj/rgauntlets");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
    ob = new("/d/islands/tonerra/obj/hide.c");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
    ob = new("/d/islands/tonerra/obj/Lcloak");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
    ob = new("/d/deku/armours/ring_p.c");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
    ob = new("/d/azha/obj/gmr_ring.c");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
    ob = new("/realms/tristan/healing");
    ob->move(TO);
    ob->set_uses(75);
    
    ob = new("/d/guilds/alliance/obj/guardring");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
    ob = new("/d/guilds/alliance/obj/dkey");
    ob->set_owner(TO);
    ob->move(TO);

    command("wearall");
    command("remove band");
    command("wield mace");
    set_stats("dexterity", 17);
    set_stats("strength", 18);
    set_max_hp(450);
    set_hp(query_max_hp());
    set_exp(10000);
}

void init(){
    ::init();
    add_action("pick","pick");
    if(wizardp(TP)) return;
    if(interactive(TP)) {
        if(TP->in_guild("Alliance of Light"))
            add_report(TP->query_cap_name()+" stopped by.");
        else
            add_report("I saw "+lower_case(TP->getWholeDescriptivePhrase())+" that I don't recognize come in here.");        
    }
    if("/daemon/guilds_d"->is_hc("Alliance of Light", TP->query_name()))
    	force_me("salute "+TP->query_name());
    if(TP->in_guild("Alliance of Light")) return;
    if(present("alliance ring",TP)) return;
    call_out("warn_em", 0, TP);
}

void warn_em(object ob) {
    force_me("say %^BOLD%^%^YELLOW%^You're not allowed in here, leave immediately!%^RESET%^");
    force_me("emote grips his mace.");
    force_me("emote points to the exit.");
    call_out("hurt_em", 10, ob);
}

void hurt_em(object targ){
    if(!present(targ, ETO)) return;
    force_me("wearall");
    cease_all_attacks();
    remove_call_out("break_em");
    force_me("yell Brothers!  The jail is under attack!");
    force_me("wearall");
    force_me("block up");
    force_me("rush "+targ->query_name());
    force_me("kill "+targ->query_name());
    force_me("parry");
}

void break_em(object targ){
    cease_all_attacks();
    force_me("wearall");
    remove_call_out("hurt_em");
    force_me("yell Brothers!  The jail is under attack!");
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
                force_me("block up");
                force_me("rush "+att[i]->query_name());
        }
    }
    else if(timer) {
        timer++;
        if(!jailing) jail_em();
        if(timer == 5) {
            timer = 0;
            force_me("unblock up");
        }
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
        force_me("quaff kit");
        force_me("offer bottle");
        force_me("quaff kit");
        force_me("offer bottle");
    }
    if(present("bottle",TO)) force_me("offer bottle");
}

int pick(string str) {
    add_report("I noticed "+TP->query_short()+" trying to pick locks in here.");
    call_out("break_em", 2, TP);
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
        tell_room(ETO, "%^BOLD%^The jailer binds up "+him->query_cap_name()+
                       " and tosses him in a cell!", him);
        him->set_hp((int)him->query_max_hp()/2);
        him->do_damage(0,0);
        tell_object(him, "%^BOLD%^You wake up to find yourself bound and "
                         "dragged into a cell!");
        add_report("Had to throw "+lower_case(him->query_short())+" in a cell.");
		BDAEMON->direct_post(BOARD, "Bors", "New prisoner", 
			"Brothers and sisters.  I have imprisoned "+
			lower_case(him->query_short())+" who was trespassing "+
			"outside the dungeon.\n\nThis was done at:\n\n"+ctime(time())+"\n\n"+
			"Please ensure that this person is fed and dealt with as necessary.\n"+
			"\nWe are the Light in the Darkness!\n\nBrother Bors, the Jailer"
		);
    }
    jailing = 0;
}

void stand_down(object ob) {
    if(!present("alliance ring",ob)) {
		force_me("say Get going, before I'm forced to stick you in a cell.");
    	return;
    }
	if(!ob->in_guild("Alliance of Light")) {
		force_me("say I know the ring, but I don't know you.  Now, scram.");
		return;
	}

    TO->force_me("say Standing down.");
    TO->force_me("remove band");
    remove_call_out("hurt_em");
    remove_call_out("break_em");
}

void add_report(string str) {
    if(!reports) reports = ([ ]);
    if(!reports[str]) reports[str] = 1;
    else reports[str] += 1;
}

void start_report() {
	if(!events) {
		force_me("say Nothing to report.");
	}
    if(random(2)) force_me("say Here we go....");
    else force_me("say This is what I remember happening today....");
    call_out("report", 3, 0);
}

int report(int step) {
    int i;
    string *ikeys;
    
    if(!reports) reports = ([ ]);
    ikeys = keys(reports);
    force_me("say "+ikeys[step]);
    switch(reports[ikeys[step]]) {
        case 0:
        force_me("say That didn't happen at all.  Wait...that's impossible.");
        break;
        case 1:
        if(random(2)) force_me("say That happened once since I got on duty.");
        else force_me("say Only had that happen just the once on my shift, that I know of.");
        break;
        case 2:       
        if(random(2)) force_me("say That happened twice since I got here, as I recall.");
        else force_me("say Couldn't have happened more than twice since shift change.");
        break;
        case 3:
        force_me("say That happened three times, I remember.");
        break;
        case 4:
        case 5:
        force_me("say That musta happened four or five times lately.");
        break;
        case 6:
        case 7:
        case 8:
        force_me("say That went on at least a half dozen times.");
        break;
        default:
        force_me("say I lost count how many times that happened.");
        break;
    }
        
    if(step+1 >= sizeof(ikeys)) {
    	force_me("say That's the report.");
    	return 1;
    }
    switch(random(4)) {
    	case 0:
    	tell_room(ETO, "Bors thinks carefully.\n");
    	break;
    	case 1:
    	tell_room(ETO, "Bors ponders the situation.\n");
    	break;
    	case 2:
    	tell_room(ETO, "Bors pauses in deep thought.\n");
    	break;
    	default:
    	tell_room(ETO, "Bors screws up his face trying to recall something.\n");
    }
    call_out("report", 3, step+1);
    return 1;
}

void stop_blocking(object ob) {
    if(!present("alliance ring",ob)) {
		force_me("say I don't think so.");
    	return;
    }
	if(!ob->in_guild("Alliance of Light")) {
		force_me("say Not likely.");
		return;
	}
	force_me("say Excuse me.");
	force_me("unblock up");
}

void unlock_dungeon(object ob) {
    if(!present("alliance ring",ob)) {
		force_me("say I don't think so.");
    	return;
    }
	if(!ob->in_guild("Alliance of Light")) {
		force_me("say Unlock it yourself.");
		return;
	}
	force_me("say You got it.");
	force_me("unlock gordian lock on trap door with key");
	force_me("unlock deadbolt on trap door with key");
	force_me("emote steps aside.");
}

void lock_dungeon(object ob) {
    if(!present("alliance ring",ob)) {
		force_me("say I don't think so.");
    	return;
    }
	if(!ob->in_guild("Alliance of Light")) {
		force_me("say Unlock it yourself.");
		return;
	}
	force_me("say Whatever you want.");
	force_me("close trap door");
	force_me("lock gordian lock on trap door with key");
	force_me("lock deadbolt on trap door with key");
	force_me("emote nods and goes back to what he was doing.");
}

