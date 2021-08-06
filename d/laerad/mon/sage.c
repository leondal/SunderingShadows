//Coded by Bane//
#include <std.h>
#include <daemons.h>
inherit NPC;
object ob;
void create(){
    ::create();
   set_nwp("forage",15,500);
    set_id(({"sage","man","old man","old sage"}));
    set_name("sage");
    set_short("An old sage");
    set_long(
	"Standing before you is a man easily a century old.  His white beard reaches "+
	"past his waist and he grips a cane to support his frail body."
    );
    set_body_type("human");
    set_race("human");
    set_size(2);
    set_gender("male");
    set_hd(1,0);
    set_hp(6);
    set_exp(-5000);
    set_emotes(5,({
	"%^MAGENTA%^Sage says%^RESET%^: Golly, I hope you are here to help my "+
	"people defeat the evil that has moved to our lands.","%^MAGENTA%^Sage says"+
	"%^RESET%^: Did you want to %^BOLD%^ask %^RESET%^me about the evil that has "+
	"come?","%^MAGENTA%^Sage says%^RESET%^: I sense terrible times ahead "+
	"my friends...","%^MAGENTA%^Sage says%^RESET%^: A powerful force of evil "+
	"will destroy our world if we don't stop it soon."
    }),0);
}
void init(){
    ::init();
    add_action("ask","ask");
    add_action("bring","bring");
}

void ask(string str){
    string tmp;
    if(!str) return 0;
    if(!sscanf(str,"sage about %s",tmp)) return notify_fail("Ask whom about what?\n");
    write("%^MAGENTA%^Sage says%^RESET%^: Ah yes, the quest...."
	"\nThere is a powerful undead force that has moved into our realms dear one.  "+
	"If it is not destroyed soon his armies will overrun our realms and that would "+
	"be disastrous.  I need you to defeat him and bring his life source to me so "+
	"I can put an end to his evil forever.\n\n%^MAGENTA%^Sage says%^RESET%^:"
        "  To do this you must hunt the beast out "+
	"and destroy it in its lair.  Defeating it outside its lair is useless!  "
	"I have a reward for the brave soul who actually kills this "
	"undead sorcerer in the caverns north of the Parnelli forest and will "
        "%^BOLD%^%^RED%^<bring> %^RESET%^its life force to me!"
    );
    return 1;
}

void bring(string str){
    object tooth;
    if(!str) return notify_fail("Bring what?\n");
    if(objectp(TP) && tooth = present("tooth",TP)){
	if(member_array("Killed Hansoth",TP->query_mini_quests()) == -1){
	  command("say Ah but I asked you to kill this beast yourself!  "
	      "Coward leave here!");
//	    write("%^MAGENTA%^Sage says%^RESET%^:  Ah but I asked you to kill this beast yourself!  Coward leave here!");
	    tooth->remove();
	    return 1;
	}
	if(member_array("Legacy of Hansoth",TP->query_quests()) != -1){
	    write("%^MAGENTA%^Sage says%^RESET%^:  Thank you for helping me yet again, here is a reward for your efforts.");
	    tooth->remove();
	    ob = new("/d/laerad/obj/boots_speed");
	    ob->move(TO);
            ob->set_size(TP->query_size());
	    force_me("give boots to "+TP->query_name());
	    return 1;
	}
	write("%^MAGENTA%^Sage says%^RESET%^:  Yes, you have the tooth!");
	tell_object(TP,"The Sage takes the tooth from you.");
	tell_room(ETO,"The Sage takes the tooth from "+TP->query_cap_name()+".",TP);
	tooth->move(TO);
	force_me("offer tooth");
	force_me("offerall");
	call_out("reward",1);
	return 1;
    }
    write("%^MAGENTA%^Sage says%^RESET%^:  You don't have the Lich's life source fool!");
    return 1;
}
void reward(){
  object *questors;
   int i,j;
   questors = ({});
   questors = filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
   j= sizeof(questors);
   if(!j) return;
   for(i=0;i<j;i++){
	   if(!objectp(questors[i])) { continue; }
	   if(member_array("Legacy of Hansoth",questors[i]->query_quests()) == -1 && member_array("Killed Hansoth",questors[i]->query_mini_quests()) != -1){
        tell_object(questors[i],"You have completed the Legacy of Hansoth quest!");
	    questors[i]->set_quest("Legacy of Hansoth");
	    questors[i]->fix_exp(6200000);
	   }
   }
return;
}
