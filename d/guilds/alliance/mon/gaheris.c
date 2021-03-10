#include <std.h>

#define JAIL "/d/guilds/alliance/hall/dungeon"
#define BDAEMON "/adm/daemon/bboard_d"
#define BOARD "alliance_board"

inherit "/d/guilds/alliance/mon/wander";

void jail_em();
void add_report(string str);
int report(int step);

object ob;
int timer, jailing;
mapping reports, rfreq;

void create(){
    ::create();
    reports = ([ ]);
    set_name("Gaheris");
    set_short("Sir Gaheris, Knight-Captain of the White Guard");
    set_db("gaheris");
    set_random_act_db("gaherisrandom");
    set_id( ({"guard", "knight", "captain", "gaheris"}) );
    set_long(
@ALLIANCE
Captain Gaheris wears all white, broken only by the gleaming metal of 
his mirror-like plate armor and the symbol of the Alliance's White 
Guard: two gauntlets shaking hands.  The flower of knighthood, he may 
be without his horse, he is still more than capable of protecting the 
Alliance for the greater glory of Torm.
ALLIANCE
        );
    set_body_type("human");
    set_race("human");
    set_overall_ac(5);
    set_hd(45, 1);
    set_class("paladin");
    set_mlevel("paladin", 45);
    set_property("no dominate",1);
    set_property("no animate",1);
    set_mob_magic_resistance("average");
    set_property("knock unconscious",1);
    set_property("swarm",1);
    add_search_path("/cmds/fighter");
    set_damage_bonus(3);
    set_attack_bonus(3);
    set_gender("male");
    set_property("full attacks",1);
    set_wielding_limbs(({"right hand","left hand"}));
      
    ob = new("/d/attaya/obj/lgauntlets");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
    ob = new("/d/attaya/obj/rgauntlets");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
    ob = new("/d/shadow/room/city/cguild/paladin/hlycoif");
    ob->set_property("enchantment", 3);
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
    ob = new("/d/shadow/room/city/cguild/paladin/hlyhelm");
    ob->set_property("enchantment", 3);
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
    ob = new("/d/shadow/room/city/cguild/paladin/hlyplate");
    ob->set_property("enchantment", 3);
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
    ob = new("/d/antioch/ruins/obj/valor_cloak");
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
    
    ob = new("/d/guilds/alliance/obj/gtabard");
    ob->set_owner(TO);
    ob->move(TO);

    ob = new("/d/azha/equip/avenger");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    
    command("wearall");
    command("remove band");
    command("wield avenger");
    set_stats("dexterity", 17);
    set_stats("strength", 18);
    set_max_hp(450);
    set_hp(query_max_hp());
    set_exp(10000);
}

void init(){
    string *exits;
    int i;
    object *inven;
    exits = (string *)ETO->query_exits();
    for(i=0;i<sizeof(exits);i++)
        add_action("chase",exits[i]);
    ::init();
    add_action("pick","pick");
    if(wizardp(TP)) return;
    if(interactive(TP)) {
        if(TP->in_guild("Alliance of Light"))
            add_report(TP->query_cap_name()+" stopped by.");
        else
            add_report("I saw "+lower_case(TP->query_short())+" that I don't recognize come in here.");        
    }
    if("/daemon/guilds_d"->is_hc("Alliance of Light", TP->query_name()))
    	force_me("salute "+TP->query_name());
    if(TP->in_guild("Alliance of Light")) return;
    if(present("alliance ring",TP)) return;
    if(TP->query_property("no detect")) return;
    if((string)TP->query_vehicle_type() == "riding animal") return;
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
        force_me("strip "+him->query_name());
        him->move(JAIL);
        tell_room(ETO, "%^BOLD%^Gaheris calls in some guards to bind up and escort "+
                       him->query_cap_name()+" to a cell!", him);
        him->set_hp((int)him->query_max_hp()/2);
        him->do_damage(0,0);
        tell_object(him, "%^BOLD%^You wake up to find yourself bound and "
                         "dragged into a cell!");
        add_report("Had to throw "+lower_case(him->query_short())+" in a cell.");
		BDAEMON->direct_post(BOARD, "Gaheris", "New prisoner", 
			"Brothers and sisters.  I have imprisoned "+
			lower_case(him->query_short())+" who was trespassing "+
			"within these halls.\n\nThis was done at:\n\n"+ctime(time())+"\n\n"+
			"Please ensure that this person is fed and dealt with as necessary.\n"+
			"\nMay Torm's strong arm protect us!\n\nSir Gaheris, Captain of the White Guard"
		);
    }
    jailing = 0;
}

void stand_down(object ob) {
	if((object *)TO->query_attackers() != ({ })) {
		force_me("say Its a little late for that, don't you think?....");
		return;
	}
    if(!present("alliance ring",ob)) {
		force_me("say Begone tresspasser, or feel the wrath of Torm!");
    	return;
    }
	if(!ob->in_guild("Alliance of Light")) {
		force_me("say I recognize you not.");
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
	if((object *)TO->query_attackers() != ({ })) {
		force_me("say I am engaged in a battle at present.");
		return;
	}
	if(!events) {
		force_me("say Nothing to report.");
	}
    if(random(2)) force_me("say I have the following items to report.");
    else force_me("say I have recollection of the following....");
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
        if(random(2)) force_me("say That happened once, no more, no less.");
        else force_me("say I am only aware of that happening just the one time.");
        break;
        case 2:       
		force_me("say That happened precisely twice on my rounds.");
        break;
        case 3:
        force_me("say That happened three times, of that I am certain.");
        break;
        case 4:
        case 5:
        force_me("say That must have occurred four or five times of late.");
        break;
        case 6:
        case 7:
        case 8:
        force_me("say Six or seven, perhaps even eight occurrences of that.");
        break;
        case 9:
        case 10:
        case 11:
        force_me("say I would estimate that happened ten times, give or take.");        
        default:
        force_me("say I lost count how many times that happened.");
        break;
    }
        
    if(step+1 >= sizeof(ikeys)) {
    	force_me("say Report completed.");
    	return 1;
    }
    switch(random(4)) {
    	case 0:
    	tell_room(ETO, "Gaheris thinks carefully.\n");
    	break;
    	case 1:
    	tell_room(ETO, "Gaheris ponders the situation.\n");
    	break;
    	case 2:
    	tell_room(ETO, "Gaheris pauses in deep thought.\n");
    	break;
    	default:
    	tell_room(ETO, "Gaheris screws up his face trying to recall something.\n");
    }
    call_out("report", 3, step+1);
    return 1;
}

void stop_attacking(object ob) {
	if(!ob->in_guild("Alliance of Light")) {
		force_me("say You wish.");
		return;
	}
    if(!"/daemon/guilds_d"->is_hc("Alliance of Light", ob->query_name())) {
    	force_me("say Sorry, I answer only to the High Commanders in security matters.");
    	return;
    }
   	force_me("salute");
	force_me("say By your command.");
	cease_all_attacks();
}

int chase(){
    string *exits, verb;
    int i;
    verb = query_verb();
    if((object *)TO->query_attackers() != ({})){
        call_out("go",1,verb);
        return 0;
    }
}

void go(string verb){
    object att;
    att = TO->query_current_attacker();
    if(!objectp(att) || !present(att,ETO)){
        force_me(verb);
    }
}
