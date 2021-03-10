#include <std.h>
#include "../keep.h"
#include "/d/common/common.h"
#include <daemons.h>
#define P_RACES ({"half-orc","human","half-elf"})
#define PNAM "deku_prisoner_names"
inherit NPC;
string master;
int freed;

void set_master(string str);
void query_master();
void do_racial_stuff();

void create() 
{
    int x;
    ::create(); 
    set_hd(2 + random(5),1);
    x = random(2);
    set_gender(!random(2) ? "male" : "female");
    do_racial_stuff();
    set("aggressive", 0);
    set_alignment(5);
    set_size(2);
    set_stats("strength", 8);
    set_stats("wisdom", 9);
    set_stats("intelligence", 9);
    set_stats("charisma", 13);
    set_stats("dexterity", 8);
    set_stats("constitution", 8);
    new("/d/common/obj/armour/robe")->move(TO);
    command("wear robe");	    
    set_hp(1);
    set_exp(query_hp() * 5);  
    /*set_emotes(1, ({"%^RED%^The prisoner sighs sadly.%^RESET%^","%^YELLOW%^The prisoner "+
    "cowers in the back of the chamber.%^RESET%^","%^RED%^The prisoner looks around sadly."+
    "%^RESET%^","%^BOLD%^%^GREEN%^The prisoner picks at some of "+query_possessive()+ 
    "%^BOLD%^%^GREEN%^ infected wounds.%^RESET%^","%^YELLOW%^The prisoner grabs a handful of "+
    "the soggy sand and eats it.%^RESET%^","%^BLUE%^The prisoner shakes "+query_possessive()+
    "%^BLUE%^ head and sighs.%^RESET%^","%^RED%^The prisoner wipes "+query_possessive()+ 
    "%^RED%^ face.%^RESET%^"}), 0);*/
    command("speech lament");
    command("speak common");
    set_max_level(16);
}

void init() 
{
    ::init();
    add_action("free_me","free");
}

int free_me(string str) 
{
    if(!str) return 0;
    if(str == "prisoner" && strsrch(query_name(),"filthy") == -1) {
        force_me("emoteat "+TP->query_name()+" looks at $N "+
        "with a glint of hope back in "+QP+" eyes.");
        force_me("say please, lead me from here.");
        set_master((string)TP->query_name());
        freed = 1;
        return 1;
    }
    if(freed == 1 && strsrch(query_name(),"filthy") == -1) 
    {
        if((string)TP->query_name() == master) 
        {
            force_me("say just lead me from here!");
            return 1;
        }
        force_me("say someone has pledged to lead me from here "+
        "already!");
        return 1;
    }
    force_me("emoteat "+TP->query_name()+" glances at $N "+
    "with empty eyes and begins drooling.");
    return 1;
}

void choose_name() 
{
    string name, *names;
    names = SAVE_D->query_array("deku_missing_names_array");
    name = names[random(sizeof(names))];
    if(member_array(name,SAVE_D->query_array(PNAM)) == -1) {
        SAVE_D->set_value(PNAM,name);
        return name;
    }
}

void query_master() {
    return master;
}

void set_master(string str)
{
    master = str;
}

void do_racial_stuff() {
    string name;
    set_race(P_RACES[random(sizeof(P_RACES))]);
    set_lang("common",100);        
    if(query_race() == "half-elf" || query_race() == "human") {
        if(sizeof(SAVE_D->query_array(PNAM)) < 25 && !random(3)) {
            while(member_array(name,SAVE_D->query_array(PNAM)) == -1) {
                name = choose_name();
            }
        }
        if(sizeof(SAVE_D->query_array(PNAM)) > 25 || !name) {
            name = "A filthy "+query_gender()+" " +query_race();
        }
        set_name(name);
    }
    if(query_race() == "half-orc") {
        set_name("A filthy "+query_gender() + " " +query_race());
    }

    set_id(({query_race(),"prisoner",query_race()+" prisoner"}));
    set_short("A filthy "+query_gender()+ " "+query_race()+ " prisoner");
    set_long((:TO,"long_desc":));
}

void long_desc() {
    if((string)TP->query_name() == master) 
    {
        return "%^RED%^A putrid odor is being emitted by this "
		+query_gender()+ " "+query_race()+".  "+
        capitalize(query_possessive())+ "%^RED%^ body is covered "+
	  "in a thick layer of dirt and "+
        "grime, "+query_possessive()+ "%^RED%^ hair is greasy "+
	  "and matted with sweat.  More "+
        "disturbing is the condition of "+
	   query_possessive()+"%^RED%^ body, as it is entirely "+
        "flesh and bone.  "+capitalize(query_subjective())+ 
	  "%^RED%^ is more close to starvation "+
        "than probably anyone you have ever saw.  "+
	  capitalize(query_possessive())+ "%^RED%^ face, "+
        "hands, and legs are littered with wounds, most of "+
	  "which are shallow, all of which are in "+
        "varying stages of infection.  Not only does "+
	  query_subjective()+"%^RED%^ reek "+
        "from being unclean but from rot and infection.  Obviously "+
	  query_possessive()+ "%^RED%^ captors care nothing of "+
	  query_possessive()+"%^RED%^ welfare.  To top this off "+
        "you notice that "+query_possessive()+"%^RED%^ eyes offer "+
	  "only a blank stare, it is "+
	  "obvious that to " + query_possessive() + 
	  "%^RED%^ all hope has been lost.  "+
        capitalize(QS) + " will listen to you now, you can "+
        "tell "+QO+" to %^RESET%^<follow>%^RED%^ you or "+
        "%^RESET%^<wait>%^RED%^ for you.%^RESET%^";			
    }
   	   return "%^RED%^A putrid odor is being emitted by this "
	   +query_gender()+ " "+query_race()+".  "+
         capitalize(query_possessive())+ "%^RED%^ body is covered "+
	   "in a thick layer of dirt and "+
         "grime, "+query_possessive()+ "%^RED%^ hair is greasy "+
	   "and matted with sweat.  More "+
         "disturbing is the condition of "+query_possessive()+
	   "%^RED%^ body, as it is entirely "+
         "flesh and bone.  "+capitalize(query_subjective())+ 
	   "%^RED%^ is more close to starvation "+
         "than probably anyone you have ever saw.  "+
	   capitalize(query_possessive())+ "%^RED%^ face, "+
         "hands, and legs are littered with wounds, most of "+
	   "which are shallow, all of which are in "+
         "varying stages of infection.  Not only does "+
	   query_subjective()+"%^RED%^ reek "+
         "from being unclean but from rot and infection.  Obviously "+
	   query_possessive()+ "%^RED%^ captors care nothing of "+
	   query_possessive()+"%^RED%^ welfare.  To top this off "+
         "you notice that "+query_possessive()+"%^RED%^ eyes offer "+
	   "only a blank stare, it is "+
	   "obvious that to "+ query_possessive()+ 
	   "%^RED%^ all hope has been lost.  "+
         "You wonder what "+QP+" name is and think maybe asking "+
        "would be a good way to help "+QO+" trust again.%^RESET%^";
}

void fail() {
    if(strsrch(query_name(),"filthy") != -1) {
        command("emoteat "+TP->query_name()+ " shudders and "+
        "shakes violently, seemingly "+
        "oblivious to $N.");
        return 1;
    }
    command("say who are you?  can I trust you?");
}

void catch_say(string msg){
    ::catch_say(msg);
    if(interactive(TP)) {
        call_out("response",1,msg,TP);
    }
}

void response(string msg, object ob){   
    object ob1;
    int *fines, x;
    command("speak wizish");
    if(query_master() == "") return;
    if(!objectp(ob)) return;
    if(strsrch(msg,"halt") != -1 || strsrch(msg,"wait") != -1) {
        if((string)ob->query_name() == master) {
            command("say please hurry back.");
            if(!objectp(TO) || !objectp(ob)) return;
                ob->remove_follower(TO);
            return 1;
        }
        fail();
        return 1;
    }
    if(strsrch(msg,"follow") != -1) {
        if((string)ob->query_name() == master) {
            command("say just show me which way to go.");
            if(!objectp(TO) || !objectp(ob)) return;
                ob->add_follower(TO);
            return 1;
        }
        fail();
        return 1;
    }
    if(strsrch(msg,"name") != -1) {
        if(strsrch(query_name(),"filthy") == -1) {
            command("say I am "+query_name()+", please, help me!");
            return 1;
        }
        fail();
    }   
    if(strsrch(msg,"introduce") != -1) {
        if(strsrch(query_name(),"filthy") == -1
        && (string)ob->query_name() == master) {
            command("say I am "+query_name()+".");
            return 1;
        }
        fail();
    }
}
