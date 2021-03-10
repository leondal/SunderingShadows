//Added prop to prevent summon/dismissal of followers when in quest areas.  Also set to prevent summon/dismissal if room has no teleport prop - Octothorpe 8/31/10
// help expanded with guidelines regarding appropriate gear per suggestion by Cyric
#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit DAEMON;

#define RETINUE "/daemon/retinue"
#define MAGE "/cmds/mortal/followers/mage"
#define FIGHTER "/cmds/mortal/followers/fighter"
#define CLERIC "/cmds/mortal/followers/cleric"
#define THIEF "/cmds/mortal/followers/thief"
#define PSION "/cmds/mortal/followers/psion" // this is to load a plot granted follower only - this is not a standard-issue follower! N, 12/15.
#define BARD "/cmds/mortal/followers/bard" // this is to load a plot granted follower only - this is not a standard-issue follower! N, 1/18.
#define DUMBY "/cmds/mortal/followers/dumbyroom"
#define MONK "/cmds/mortal/followers/monk"

int help(){
    int i;
    mapping retinue;

     if(!avatarp(TP))
       if(!FEATS_D->usable_feat(TP,"leadership")){
           write("You need the leadership feat to view this help file.");
            return 0;
       }

    RETINUE->init_knights(TP);
    retinue = TP->get_retinue_mapping();

    write(
@OLI
    This will allow you to manage your followers.
    follower <name> summon
    follower <name> dismiss
    follower <name> <command>
    follower <name,name2> <command>

    This command allows you to summon, command, and dismiss your followers or retainers. They will come shortly after you summon them and will obey your every command.  You must use them wisely for if they die then they are lost. You must also learn what to order them to do.  You must RP to learn what is best for each follower.  Retainers are gained every 5 levels, or every 5 days of online time.  The <name> argument can be replaced with <all> and the command will be executed by all the retainers.
OLI
     +
@OLI

    Of special note:  Followers save themselves.  If you change the title of the follower it will save.  If your follower has 1 hp left it will also save.  If you give your follower a new sword it will save (it will not automatically rewield).

    A special "title" command has been added to allow you to set the title  of your followers: follower <name> title <string containing $N>

OLI
    );
    write("Your current followers are:");
    if (retinue && sizeof(values(retinue)) > 0) {

        for (i=0;i<sizeof(values(retinue));i++) {
            write(arrange_string(capitalize(values(retinue)[i]["name"]),15)+values(retinue)[i]["class"]);
        }
    } else {
        write("    You currently have no followers.");
    }
    write("\n Keep the following in mind:%^RESET%^\n\n"
	"   1)  Retainers should only have gear they can actually use.  Example:  "
	"if they cannot wear or wield the armor or weapons due to enchantment "
	"or class they should not have it - clerics with edged weapons, level "
	"8 with +2 gear.\n\n"
	"   2)  They should not have excess equipment they would not have need "
	"for, i.e. mages should not have two sets of bracers or robes.\n\n"
	"   3)  Keep sacks (and other similar storage - chests, baskets, extra "
	"pouches) limited to two since there is no reason for them to be "
	"carrying much in sacks.\n\n"
      "%^BOLD%^%^RED%^Please note:%^WHITE%^ We do not refund gear for followers. "
      "To help avoid gear loss, the following hints may help: 1) Dismiss before "
      "logging out. 2) Don't move when summoning. 3) Summon one follower at a time. 4) Command your follower to save when you are satisfied with their setup.%^RESET%^"
    );
    if(avatarp(TP))
	write("%^BOLD%^%^GREEN%^(Immortal eyes only) - you can ban or reinstate "
	   "the use of followers by using <follower [name] [lock|unlock]>.  "
	   "Killing one will also eliminate that specific follower permanently.");
    return 1;
}

object makeFollower(mapping map){
    string name;
    string c;
    int level;
    string race;
    object follower, ob;

    name = map["name"];
    c = map["class"];
    race = map["race"];
    level = map["level"];
    switch(c){
    case "fighter":
        follower = new ( FIGHTER);
        break;
    case "cleric":
        follower = new ( CLERIC);
        break;
    case "thief":
        follower = new ( THIEF);
        break;
    case "mage":
        follower = new ( MAGE);
        break;
    case "psion": // this is to load a plot granted follower only - this is not a standard-issue follower! N, 12/15.
        follower = new ( PSION);
        break;
    case "bard": // this is to load a plot granted follower only - this is not a standard-issue follower! N, 12/15.
        follower = new ( BARD);
        break;
    case "monk":
        follower = new ( MONK);
        break;
    default:
        error("Unknown class "+c);
    }

    follower->set_name(name);
    follower->set_short(capitalize(name)+", a bold retainer for "+TP->query_cap_name());
    follower->add_id(""+(string)TP->query_name()+" retainer");
//added the id to allow tracking for perfect caster exclusion
    follower->set_level(level);
    follower->set_mlevel(c,level);
    follower->set_guild_level(c,level);
    follower->set_hd(level,8);
    follower->set_max_hp(roll_dice(12,level));
    follower->set_hp(follower->query_max_hp());
    follower->set_alignment(TP->query_alignment());
    follower->set_diety(TP->query_diety());
    follower->equip_me();
    follower->set_race(race);
    if((string)TP->query("subrace") == "szarkai") follower->set_race("drow");

    if (c == "cleric") {
        //these races do not have clerics!
        if(race == "ogre") follower->set_race("ogre-mage");
        new ("/d/magic/symbols/holy_symbol")->move(follower);
        follower->set_stats("strength",15);
        follower->set_stats("constitution",14);
        follower->set_stats("dexterity",13);
        follower->set_stats("intelligence",15);
        follower->set_stats("wisdom",20);
        follower->set_stats("charisma",13);
    } else if (c == "mage") {
        //these races do not have mages!
        if(race == "dwarf" || race == "halfling") follower->set_race("gnome");
        if(race == "ogre" || race == "hobgoblin") follower->set_race("ogre-mage");
        if(race == "firbolg") follower->set_race("elf");
        if(race == "wemic" || race == "beastman") follower->set_race("human");
        if(race == "goblin" || race == "orc" || race == "ogre" || race == "bugbear" || race == "gnoll")
          follower->set_race("kobold");
        ob = new ("/d/magic/spellbook");
        ob->add_all();
        ob->move(follower);
        ob = new ("/d/magic/comp_bag");
        ob->move(follower);
        follower->set_stats("strength",12);
        follower->set_stats("constitution",14);
        follower->set_stats("dexterity",16);
        follower->set_stats("intelligence",20);
        follower->set_stats("wisdom",15);
        follower->set_stats("charisma",13);
    } else if(c == "thief"){
        //these races do not have thieves!
        if(race == "ogre") follower->set_race("goblin");
        follower->set_stats("strength",15);
        follower->set_stats("constitution",14);
        follower->set_stats("dexterity",20);
        follower->set_stats("intelligence",14);
        follower->set_stats("wisdom",15);
        follower->set_stats("charisma",13);
    } else if(c == "fighter"){
        follower->set_stats("strength",20);
        follower->set_stats("constitution",16);
        follower->set_stats("dexterity",14);
        follower->set_stats("intelligence",10);
        follower->set_stats("wisdom",13);
        follower->set_stats("charisma",12);
    } else if(c == "psion"){
        new ("/d/magic/psicrystal")->move(follower);
        follower->set_stats("strength",12);
        follower->set_stats("constitution",14);
        follower->set_stats("dexterity",16);
        follower->set_stats("intelligence",20);
        follower->set_stats("wisdom",13);
        follower->set_stats("charisma",15);
    } else if(c == "bard"){
        follower->set_stats("strength",12);
        follower->set_stats("constitution",14);
        follower->set_stats("dexterity",16);
        follower->set_stats("intelligence",15);
        follower->set_stats("wisdom",13);
        follower->set_stats("charisma",20);
    }
    return follower;
}


int cmd_follower(string str){
    mapping retinue;
    string who, what, *whoList, command, excess;
    object *npcs, whoObj, temp;
    mapping controller;
    int i;

    if(!FEATS_D->usable_feat(TP,"leadership")) return 0;

    RETINUE->init_knights(TP);
    retinue = TP->get_retinue_mapping();

    if (!str) {   return help();    }

    if (sscanf(str, "%s %s", who,what) != 2){
        return help();
    }

    sscanf(what, "%s %s", command, excess);
    if (!command) {
        command = what;
    }

    controller = TP->query("current retinue");
    if (!controller) {
        controller = ([]);
    }
    if (who == "all") {
        whoList = keys(retinue);
    } else {
        whoList = explode(who,",");
    }
    if (avatarp(TP) && what == "lock") {
        whoObj = find_player(who);
        whoObj->set("bad knight",1);
        tell_object(whoObj,"%^BOLD%^You have been flagged for abuse, your retainers will not answer your commands.");
        write("%^BOLD%^You have flagged "+who+" for abuse, please note "+whoObj->query_objective()+".");
        return 1;
    }

    if (avatarp(TP) && what == "unlock") {
        whoObj = find_player(who);
        whoObj->set("bad knight",0);
        tell_object(whoObj,"%^BOLD%^You have regained your good name, your retainers will answer your commands.");
        write("%^BOLD%^You have unflagged "+who+" for abuse, please note "+whoObj->query_objective()+".");
        return 1;
    }

    if (TP->query("bad knight")) {
        write("%^BOLD%^You have been forsaken by your retainers for abuse.");
        return 1;
    }
    switch(command){
    case "summon":
		if(ETP->query_property("no teleport"))
		{
		    tell_object(TP,"Your followers are unable to find their way to your current location.");
			return 0;
		}
		if(ETP->query_property("no follower"))
		{
		    tell_object(TP,"Your followers are unable to find their way to your current location.");
			return 0;
		}
        for (i = 0;i<sizeof(whoList);i++) {
            who = whoList[i];
            if (!retinue[who]) {
                continue;
            }
            if (!(whoObj = controller[who])) {
                whoObj = makeFollower (retinue[who]);
               whoObj->move(DUMBY); // Maybe this is the problem?
                controller[who]=whoObj;
                whoObj->set_followee(TP);
                whoObj->restoreFollower();
               whoObj->move(DUMBY); // Make sure they're there!
                whoObj->set_followee(TP);
                whoObj->add_id(""+(string)TP->query_name()+" retainer");
            }
            tell_room(ETP,"%^BOLD%^%^GREEN%^"+TPQCN+" summons a retainer.",TP);
          temp=new(base_name(TO));
          temp->start_summoning((random(3)+1)*ROUND_LENGTH, TP, whoObj);
            write("%^BOLD%^%^GREEN%^You summon "+capitalize(who)+" to you.");
//            call_out("summoning",random(20)+1,TP,whoObj);
        }
        break;
    case "dismiss":

        if(!objectp(TP)) { return 0; }

		if(ETP->query_property("no teleport"))
		{
		    tell_object(TP,"Your followers are unable to find their way out of your current location.");
			return 0;
		}

		if(ETP->query_property("no follower"))
		{
		    tell_object(TP,"Your followers are unable to find their way out of your current location.");
			return 0;
		}

        if(sizeof(TP->query_attackers()))
        {
            tell_object(TP,"You can't do that while being attacked!");
            return 1;
        }

        for (i = 0;i<sizeof(whoList);i++)
        {
            who = whoList[i];
            if (!retinue[who]) {
                continue;
            }
            if (!(whoObj = controller[who])) {
                continue;
            }
            tell_object(TP,"%^BOLD%^You dismiss "+capitalize(who)+".%^RESET%^");
            tell_room(environment(whoObj),"%^BOLD%^%^GREEN%^"+ capitalize(who)+" leaves the area.%^RESET%^");
            if(whoObj->query_invis()) whoObj->set_invis();
            whoObj->saveFollower();
            whoObj->move(DUMBY);
//           identify(catch(destruct(whoObj)));
           all_inventory(whoObj)->remove();

           whoObj->remove_without_save();
         }
        break;
    case "title":
        for (i = 0;i<sizeof(whoList);i++) {
            who = whoList[i];
            if (!retinue[who]) {
                continue;
            }
            if (!(whoObj = controller[who])) {
                continue;
            }
            if (strsrch(excess, "$N") == -1) {
                excess = "$N, "+excess;
            }
            excess = replace_string(excess,"$N",capitalize(whoObj->query_name()));
            whoObj->set_short(excess);
            tell_object(TP,"%^BOLD%^You change "+capitalize(whoObj->query_name())+"'s short to be "+excess+".");
        }
        break;
    default:
        for (i = 0;i<sizeof(whoList);i++) {
            who = whoList[i];
            if (!retinue[who]) {
                continue;
            }
            if (!(whoObj = controller[who])) {
                continue;
            }
            tell_object(TP,"%^BOLD%^You command "+capitalize(who)+" to "+what+".");
            whoObj->force_me(what);
        }
    }

    TP->set("current retinue", controller);
    return 1;
}

void start_summoning(int time, object tp, object whichmob ) {
           return call_out("summoning",time,tp,whichmob);
}
void summoning(object who, object what)
{
	if(!objectp(who)) { return; }
    	if(!objectp(what)) { return; }

    	tell_room(environment(who),"%^BOLD%^%^GREEN%^"+what->query_cap_name()+" arrives.");
    	what->move(environment(who));
    	what->remove_all_properties();
	what->set_property("knock unconscious", 1);
    	destruct(TO);
}
