/*Changed dramatically by Saide - he's now in Jail and will give PCs a key to a locked vault
for their assistance in helping him - by bringing him Lord Blacktongues Crown 10 / 04 / 03*/
#include <std.h>
#include "/d/deku/keep/keep.h"

inherit NPC;

int count, already_helped, choose, flag;

void do_help(object to) {
    object *alive;
    int people, x;
    
    if(!objectp(ETO)) return;
    if(!objectp(to)) return;
    if(already_helped == 1) return;
    
    alive = all_living(ETO);
    alive -= ({TO});

    for(x = 0;x < sizeof(alive);x++) {
        if(alive[x]->is_player()) {
            people++;
            break;  
        }
    }
	
    if(people > 0) {
        if(!objectp(to)) return;
            command("say please, will you do a favor for me?");
            if(!objectp(to)) return;
            call_out("do_help",60,to); 
            return;
	}
    else {
        if(!objectp(to)) return;
        command("yell please, somebody help me!");
        if(member_array("out",ETO->query_exits()) != -1) {
            command("knock "+ETO->query_door("out"));
        }
        if(!objectp(to)) return;
        call_out("do_help",60,to);
        return;
    }
	
}

void create() {
    ::create();
    set_name("a human");
    set_id(({"gareth","human","a human","alchemist"}));
    set_short("An old and stooped frail human");
    set_level(15);
    set_long("%^BOLD%^%^WHITE%^This old man has seen better days.  He is stooped now, the "+
    "bones in his back twisted and bent as a result of a difficult life.  His body is "+
    "little more than skin, with very readily visible bones.  This man is closer to "+
    "starvation than anyone you have ever beheld.  His hair is gray, thinning, and "+
    "unwashed for what looks like ages.  His eyes are a deep %^BLUE%^blue%^BOLD%^%^WHITE%^, "+
    "they reveal how tired and weary he is.  He carries no weapons and wears only a "+
    "simple robe, his last luxury in life.%^RESET%^");  
    set_gender("male");
    set_race("human");
    set_class("mage");
    set_guild_level("mage",15);
    set_mlevel("mage",15);
    set_mob_magic_resistance("average");
    set_spell_chance(100);
    set_spells(({"magic missile","scorcher","fireball"}));
    set_alignment(5);
    set_hd(15,1);
    set_max_hp(100 + random(50));
    set_hp(query_max_hp());
    new("/d/common/obj/armour/robe")->move(TO);
    command("wear robe");
    command("speech say quickly");
    command("speak common");
    add_search_path("/cmds/mortal/");
    flag = 0;
}

void reset() {
    ::reset();
    if(flag == 0) {
        call_out("do_help",30,TO);
        flag = 1;
    }
    already_helped = 0;
	if(!present("vault key",TO)) {
        new(KEEPO+"vaultkey")->move(TO);
    }
}

void catch_say(string msg)
{
    	::catch_say(msg);
    	if(interactive(TP)) 
	{
      	call_out("response",1,msg,TP);
    	}
}

void response(string msg, object ob){
    	command("speech say quickly");
    	command("speak common");
    	if(!objectp(ob)) return;
    	if(ob->query_invis()) 
	{
      	force_me("say Who goes there?  Please, I must ask a favor...");
        	force_me("say but I must be able to see you.");
        	return;
   	}
    	if(strsrch(msg, "favor") != -1 || strsrch(msg, "Favor") != -1 
	|| strsrch(msg, "help") != -1 || strsrch(msg, "Help") != -1) 
	{
      	if(already_helped == 0) 
		{
            	force_me("say yes, you have to help me, you must do me a favor.");
	            force_me("say my life is ending, I will die in this lonely place.  "+
			"I don't mind, but I want the life of the one who placed me "+
			"here.  The terrible Lord Blacktongue" +
            	" must die.  I'm not sure where he is, but I do know he "+
			"wears a golden crown, " + 
            	"bring it to me and I will reward you.  I will reward you "+
			"with the last thing of "+
            	"value that I have.");
            	force_me("say you must be very careful.... "+
			"Blacktongue is very powerful and " +
            	"well guarded, you must not fail.");
            	return;
        	}
    	}
    	if(strsrch(msg, "crown") != -1 || strsrch(msg, "Crown") != -1) 
	{
      	if(already_helped == 0) 
		{
            	force_me("say yes, I want his crown.  You must take "+
			"his life to get it though."+
	            "  You'll be able to recognize the crown, it is golden "+
			"and encrusted with jewels.");
	            return;
      	}
    	}
    	if(strsrch(msg, "blacktongue") != -1 || strsrch(msg, "Blacktongue") != -1) 
	{
      	force_me("say Blacktongue, this place has taken its name after the evil "+
        	"lord.  Like the beasts that dwell in this place, he's half-wolf, a "+
        	"type of wolf abomination, they are known as werewolves.  Lord Blacktongue is very" +
        	" evil and very powerful.  Be careful.");
        	return;
    	}
    	if(strsrch(msg, "wolf") != -1 || strsrch(msg, "werewolf") != -1) 
	{
      	force_me("say the beasts that dwell here are wolf hybrids, they are very evil "+
        	"creatures.  Known most everywhere as werewolves, they would never be able"+
        	" to stay united, without the leadership of something far more powerful "+
        	"and far more evil.");
        	return;
    	}
    	if(strsrch(msg, "hello") != -1 || strsrch(msg,"Hello") != -1 
	|| strsrch(msg,"greeting") != -1 ||
    	strsrch(msg,"Greeting") != -1) 
	{
      	if(already_helped == 0) 
		{
            	force_me("say Hello!  Please, will you do a favor for me?");
                	force_me("emoteat " + ob->query_name() + " looks at $N with a slight hope.");
            }
            else 
		{
            	force_me("emoteat " +ob->query_name() + " seems to ignore $N");
            }
        	return;
    	}
}

void do_received_stuff(object tp) 
{
	if(!objectp(tp)) return;
    	switch(count) 
	{
    		case 0:
			break;
    		case 1:
        		force_me("emote laughs happily and smiles");
        		break;
    		case 2:
        		break;
    		case 3:
        		force_me("emote mockingly places the crown above his head and laughs wildly");
	    		break;
    		case 4:
        		break;
		case 5:
        		force_me("say ahh yes... there is a matter of a reward.  Well, here you go!");
        		force_me("give vault key to " + TP->query_name());
        		if(member_array("Achieved: Retrieved BlackTongue's Crown",
			TP->query_mini_quests()) == -1) 
			{
            		TP->set_mini_quest("Achieved: Retrieved BlackTongue's Crown",
				25000,"Achieved:  Retrieved BlackTongues's Crown");
        		}          
        		break;
    		case 6:
        		break;
    		case 7:
        		force_me("say that key opens the vault in my old lab in "+
			"the keep, you can have "+
		      "everything, I don't want any of it!");
        		break;
    		case 8:
        		break;
    		case 9:
        		force_me("emote laughs crazily and begins dancing widly");
        		break;
  		case 10:
        		break;
    		case 11:
        		force_me("offer crown");
	    		force_me("say to the abyss with you!");
        		force_me("emote begins settling back down");
        		break;
    	}
	
    	if(count <= 10) 
	{
      	call_out("do_received_stuff",0,TP);
        	count++;
        	return;
    	}
    	return;

}

void receive_given_item(object ob)
{
	command("speech say quickly");
    	command("speak common");
    	if(already_helped == 0) 
	{
      	if(ob->id("blacktongue crown")) 
		{
            	already_helped = 1;
	            force_me("speech laugh");
            	force_me("say yes, yes, yes!");
            	force_me("say you've brought me the crown of the "+
			"foul creature!  I've had the last laugh!");
            	call_out("do_received_stuff",0,TP,0);
            	return;
        	}
   		else 
		{
            	force_me("emote looks over the " + ob->query_name());
            	force_me("emote sighs sadly");
            	force_me("say no, this is not what I wanted.");
            	force_me("give " + ob->query_name() + " to " + TP->query_name());
            	return;
        	}
    	}
   
}
   

   
 