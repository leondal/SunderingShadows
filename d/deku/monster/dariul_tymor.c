#include <std.h>
#include <daemons.h>
#define LETS ({"a","b","c","d","e","f","g","h","i","j","k","l","m",\
"n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D",\
"E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","V",\
"W","X","Y","Z","1","2","3","4","5","6","7","8","9","10","11","12",\
"13"})
#define CTIME 86400
#define VCONTRACTS "valid_deku_contracts"
inherit NPC;

void remove_fine(string who, int gold);

void create() {
 ::create();
  set_race("golem");
  set_name("Dariul Tymor");
  set_id(({"dariul tymor","dariul","tymor","Dariul",
  "Tymor","Dariul Tymor","creature"}));
  set_short("Dariul Tymor, A strange looking creature");
  set_long("This pale white creature resembles a human that is "+
  "far more rigid than normal.  He stands roughly six feet tall "+
  "and is strikingly handsome by most standards,  His hair is a "+
  "light black that is kept short, his facial features "+
  "are rugged and firm, yet his ice blue eyes offer a "+
  "boyish gaze.  Its only once you lock eyes with him "+
  "that you realize he has no pupils to speak of and you understand "+
  "that he is not a human at all.  He still appears relatively "+
  "friendly and stands here waiting to serve this small "+
  "town of verbobone, night or day.");
  set_alignment(5);
  set_hd(20,2);
  set_hp(200 + random(101));
  set_exp(query_max_hp() * 8);
  set_stats("strength",19);
  set_stats("dexterity",14);
  set_stats("constitution",16);
  set_stats("wisdom",17);
  set_stats("intelligence",10);
  set_stats("charisma",15);
  set_gender("male");

}

void do_rewards(string what, string str, object who) {
    object ob;
    int *rewards, gold, x;

    if(member_array(str,SAVE_D->query_array("deku_names_seeking_array")) != -1) {
        if(what == "dead") {
        command("emote nods");
        command("say "+str+" is now reported dead.");
        }
        if(what == "alive") {
            if(ob = present(str,ETO)) {
                command("emote offers a thin smile");
                command("emoteat "+ob->query_name()+" motions for "+
                "an attendant to usher $N out for processing.");
                command("say "+str+" found alive, family will be "+
                "notified.");
                ob->move("/d/shadowgate/void");
                SAVE_D->remove_name_from_array("deku_names_seeking_array");

                "/d/deku/inherits/name_gen_d.c"->remove_name((string)ob->query_name());
                ob->remove();
            }
        }
        rewards = SAVE_D->query_array("deku_names_seeking_rewards_array");
        gold = rewards[member_array(str,SAVE_D->query_array("deku_names_seeking_array"))];
        SAVE_D->remove_name_from_array("deku_names_seeking_array",str);
        "/d/deku/inherits/name_gen_d.c"->remove_name(str);
        SAVE_D->remove_name_from_array("deku_names_seeking_reward_array",gold);
        command("say reward is "+gold+ " gold coins.");
        command("emoteat "+who->QCN+" hands a money pouch to $N");
        who->add_money("gold",gold);
        return 1;
    }
    command("say no such person has been reported missing.");
    return 1;

}

void catch_say(string msg){
    ::catch_say(msg);
    if(interactive(TP)) {
        call_out("response",1,msg,TP);
    }
}

void response(string msg, object ob){
    object ob1, ob2;
    int *fines, x;
    command("speak wizish");
    if(!objectp(ob)) return;
    if(base_name(ETO) != "/d/deku/town/info_office") return;
    if(ob->query_invis()) {
        force_me("say I cannot speak to invisible one.");
        return;
    }
    if(strsrch(msg,"request guard") != -1 || strsrch(msg,"request a guard") != -1) {
        if(ETO->query_guards_out() >= 2) {
            force_me("say All guards are out, wait for one "+
            "to return.");
            return 1;
        }
        if(!(present("guard",ETO))) {
            force_me("say guards appear to be gone.  Wait until later.");
            return 1;
        }
        if(member_array(ob->query_name(),SAVE_D->query_array("deku_has_guard")) != -1) {
            force_me("shake");
            fines = SAVE_D->query_array("deku_guard_fine");
            force_me("say "+ob->QCN+", you have not brought the "+
            "last guard you took out back.  You must pay a fine of "+
            fines[member_array(ob->query_name(),SAVE_D->query_array("deku_has_guard"))]+
            " gold coins before another will be entrusted to your "+
            "care.");
            return 1;
        }
        force_me("emote motions for one of the guards to turn "+
        "to "+ob->QCN+".");
        force_me("say listen to "+ob->QO);
        force_me("emote writes something down on a piece of "+
        "parchment");
        force_me("say guard out with "+ob->QCN+", officially logged.");
        SAVE_D->set_value("deku_has_guard",ob->query_name());
        x = 2000 + random(3001);
        if(member_array(x,SAVE_D->query_array("deku_guard_fine")) != -1) {
            x++;
        }
        SAVE_D->set_value("deku_guard_fine",x);
        ETO->add_guards_out(1);
        if((ob1 = present("guard",ETO))) {
            if(ob1->query_master()) {
                if((ob2 = present("guard 2",ETO))) {
                    if(ob2->query_master()) {
                        return;
                    }
                    ob2->set_master(ob->query_name());
                    return 1;
                }
                return;
            }
            ob1->set_master(ob->query_name());
            return 1;
        }
        return 1;
    }
}

void init() {
    ::init();
    if(base_name(ETO) == "/d/deku/town/info_office") {
        add_action("pay_fine","pay");
        add_action("show_prisoner","show");
        add_action("buy_contract","buy");
        add_action("estimate_me","estimate");
    }
}

void show_prisoner(string str) {
    object ob;
    if(!str) return;
    if((ob = present(str,ETP))) {
        if(living(ob)) {
           TP->force_me("emoteat dariul motions for $N to take "+
           "a hard look at "+ob->query_name()+".");
           TP->force_me("say introduce yourself.");
           if((string)ob->query_master() == (string)TP->query_name()) {
                ob->force_me("say I am "+ob->query_name());
                do_rewards("alive",(string)ob->query_name(),TP);
           }
           return 1;
        }
        return;
    }
    return;
}

void pay_fine(string str) {
    int coins, x, *fines;
    if(!str) return;
    if(str == "fine") {
        x = member_array(TP->query_name(),SAVE_D->query_array("deku_has_guard"));
        if(x != -1) {
            fines = ({});
            fines = SAVE_D->query_array("deku_guard_fine");
            if(TP->query_money("gold") < fines[x]) {
                force_me("say "+TP->QCN+" you do not have enough gold "+
                "to pay your fine.  Your fine is "+fines[x]+
                " gold pieces");
                return 1;
            }
            TP->add_money("gold",-fines[x]);
            TP->force_me("emoteat dariul hands $N a money pouch.");
            force_me("say "+TP->QCN+", your fine of "+
            fines[x]+ " gold coins is now paid.  Return guards that "+
            "accompany you from now on.");
            remove_fine((string)TP->query_name(),fines[x]);
             return 1;
         }
         force_me("say you owe no fine "+TP->QCN+".");
         return 1;
    }
    return;
}

void remove_fine(string who, int gold) {
    SAVE_D->remove_name_from_array("deku_has_guard",who);
    SAVE_D->remove_name_from_array("deku_guard_fine",gold);
}

void contract_okay(object who) {
    return 1;
}

void make_id_name() {
    string str;
    int x;
    for(x = 0;x < 8 + random(9);x++) {
        if(str) {
            str += LETS[random(sizeof(LETS))];
            continue;
        }
        str = LETS[random(sizeof(LETS))];
        continue;
    }
    if(member_array(str,SAVE_D->query_array(VCONTRACTS)) != -1) {
        return;
    }
    SAVE_D->set_value(VCONTRACTS,str);
    return str;
}


int buy_contract(string str) {
    int gold;
    object ob;
    string nam;
    if(!str) return 0;
    if(sscanf(str,"contract for %d gold",gold) == 1) {
        TP->force_me("emoteat dariul walks up to $N and says "+
        "something quietly to $O");
        if(gold > 5000) {
            force_me("say we offer contracts for only 5,000 or "+
            "fewer gold pieces.");
            return 1;
        }
        if(TP->query_money("gold") < gold) {
            force_me("say you have not shown enough gold.");
            return 1;
        }

        if(contract_okay(TP) == 1) {
            TP->force_me("emoteat dariul hands a money pouch over to "+
            "$N");
            TP->add_money("gold",-gold);
            force_me("say writing new contract for "+gold+" gold "+
            "pieces.");
            force_me("emoteat "+TP->query_name()+" hurridly writes "+
            "something onto a piece of parchment and then "+
            "drops it on the table for you.");
            force_me("emote writes something down into a thick book "+
            "in front of him.");
            ob = new("/d/deku/misc/contract");
            ob->set_gold_value(to_int(gold / 2));
            ob->set_bought_time(time());

            while(!nam) { nam = make_id_name(); }

            ob->set_id_name(nam);

            ob->set_read("Contract shall be considered valid by "+
            "the town of verbobone until officially voided.  "+
            "Contract shall, over the course of time, draw value "+
            "that will be honored by the town of verbobone upon "+
            "date of sell.\n"+
            "Signed, \n"+
            "Dariul Tymor, Official Represenative of Verbobone "+
            "by hand of Ruther Enuren, on "+day(time())+", "+
            date(time())+" "+month(time())+" in the year "+
            year(time())+".");
            ob->set_language("common");
            ob->move(ETO);
            return 1;
        }
    }
    return 0;
}

void calc_g_worth(object ob) {
    int val, true_val, t, x;
    val = ob->query_gold_value();
    t = ob->query_bought_time();
    x = to_int(time() - t);
    t = x / CTIME;
    true_val = (t * to_int(val / 25)) + val;
    if(true_val > (val * 4)) true_val = val * 4;
    return true_val;
}

void receive_given_item(object ob){
    int worth;
    if(ob->query_gold_value() && base_name(ETO) == "/d/deku/town/info_office") {
        force_me("emote quickly and carefully reads over "+
        "the contract.");
        force_me("emote nods and looks up something in "+
        "a large book in front of him.");
        if(member_array(ob->query_id_name(),SAVE_D->query_array(VCONTRACTS)) == -1) {
            force_me("shake");
            force_me("say this contract has been rendered officially "+
            "void.");
            force_me("drop "+ob->query_name());
            return 1;
        }
        worth = calc_g_worth(ob);

        force_me("say we honor contract for "+worth+" gold pieces.");
        force_me("emoteat "+TP->query_name()+" hands $N a pouch of "+
        "money and files the contract away.");
        TP->add_money("gold",worth);
        SAVE_D->remove_name_from_array(VCONTRACTS,ob->query_id_name());
        ob->remove();
        return 1;
    }
    else {
        force_me("emote examines "+ob->query_name()+" and shakes his head.");
        force_me("drop "+ob->query_name());
        if(base_name(ETO) != "/d/deku/town/info_office") {
            force_me("say I don't accept anything out of my office, "+
            "see me there if it is official.");
            return 1;
        }
        force_me("say that is not offical, I have no use for it.");
        return 1;
    }

}

int estimate_me(string str) {
    int x, y, gold;
    object ob, *inv;
    if(!str) return 0;
    if(strsrch(str,"contract") != -1) {
        if(ob = present(str,TP)) {
            TP->force_me("show "+str+ " to dariul");
            force_me("emoteat "+TP->query_name()+" nods to $N and "+
            "examines the "+str+" carefully");
            if(member_array(ob->query_id_name(),SAVE_D->query_array(VCONTRACTS)) == -1) {
                force_me("say that contract has been rendered "+
                "officially void.");
                return 1;
            }
            gold = calc_g_worth(ob);
            force_me("say that contract is worth about "+gold+" gold "+
            "pieces right now.");
            return 1;
         }
        write("You don't have that.");
        return 1;
    }
    return 0;

}
