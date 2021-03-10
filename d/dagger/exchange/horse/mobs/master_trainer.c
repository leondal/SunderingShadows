
// Master Horse Trainer

#include "../horse.h"
#include <std.h>
#include <daemons.h>
//#include <security.h>

inherit NPC;

int x,y,w,q;
object horse_edit, buyer;

nosave mapping example_variable;

nosave string race_horses;
string new_horse_name, training_picked;

void create()
{
   	::create();
        set_name("Baffert");
        set_id( ({ "baffert", "master trainer", "baffert the master trainer"}) );
set_short("%^RESET%^%^RED%^Baff%^BOLD%^e%^RESET%^%^RED%^rt Yves, Mast%^RESET%^%^ORANGE%^"+
"e%^RESET%^%^RED%^r of Tr%^RESET%^%^ORANGE%^a%^RESET%^%^RED%^iners%^RESET%^");
   	set("aggressive", 0);
   	set_level(19);
    set_long("%^RESET%^%^RED%^Baffert is a half-elf dressed in a fine silk suit "+
	"that watches the comings and goings of the horse trainers. He was one of "+
	"the original three that started the horse racing circuit and has great "+
	"knowledge on what it takes to train a race horse. He uses his %^MAGENTA%^%^BOLD%^psionic "+
	"powers%^RESET%^%^RED%^ to send trainers to the tracks to manage the horses individually "+
	"and manages the owner's records. It is rumored he personally trained several of the "+
	"better horses in the circuit but maintains that since he does not have a financial "+
	"stake in any of the horses everything is on the up and up. His perfectly groomed "+
	"%^BLACK%^%^BOLD%^black hair%^RESET%^%^RED%^ does not hide the %^RESET%^%^ORANGE%^"+
	"slight elven point%^RED%^ to his ears and a set of %^RESET%^fine rimmed "+
	"eyeglasses%^RED%^ accentuate his delicate bone structure. %^RESET%^");
    set_gender("male");
   	set_alignment(3);
   	set("race", "half-elf");
   	add_money("gold", random(500));
   	set_property("no attack", 1);
   	set_hd(19,3);
   	set_max_hp(query_hp());
   	set_max_sp(query_hp());
   	set_sp(query_max_sp());
   	set_mp(random(500));
  	set_stats("strength", 18);
  	set_stats("constitution", 17);
  	set_stats("dexterity", 16);
  	set_stats("wisdom", 10);
  	set_stats("intelligence", 14);
  	set_exp(10);
  	set_hp(159);
   	set_class("fighter");
	set_spoken("wizish");
    command("speech %^ORANGE%^speak with a wry chuckle%^RESET%^");
	set_emotes(2, ({
"%^RESET%^%^RED%^with a %^BOLD%^flash of power%^RESET%^%^RED%^ Baffert touches a "+
"trainer and they disapear!%^RESET%^",
"%^RESET%^%^ORANGE%^Baffert adjusts his glasses",
"%^BLACK%^%^BOLD%^A squad of Dragoon soldiers does a quick patrol of the area",
"%^RED%^%^BOLD%^An owner speaks quietly with Baffert%^RESET%^",
}), 0);
    y = 1200;
}

void heart_beat(){
    ::heart_beat();
    x = random(20);
	y++;
    if(x == 1){
	if(y > 1200){
  force_me("reset_the_training");
    y = 0;
		return;
	}
    }

}

void receive_given_item(object obj){
    string *temp=({});
	object ob;
    int x;
	string real_owner_name;
    int i, uid_to_train;
    string name,owner;
    int value, type, true_value;
    name = TPQN;
    i = 0;
	x = 0;
    real_owner_name = TP->query_true_name();

    if(!objectp(obj)) return;

	if((string)obj->query_name() != "horse_upgrade") {
        force_me("say I doubt this will help your horse much...");
        force_me("give "+obj->query_name()+" to "+name+"");
    return;
    }
	value = (int)obj->check_value();
	type = (int)obj->check_type();

        horse_edit =find_object_or_load(STORAGE"horse_edit.c");
		horse_edit->item_fun(real_owner_name, type, value);
    obj->remove();
	}
