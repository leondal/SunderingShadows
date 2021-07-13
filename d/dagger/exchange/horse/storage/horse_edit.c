#include <std.h>
#include <security.h>
#include "../horse.h"
inherit OBJECT;

#define SAVE_FILE "/d/save/horse_race_stuff"

mapping horse_stats;

nosave mapping example_variable;

nosave string race_horses;
string new_horse_name, training_picked;
int real1, real2, real3, real4, uid_to_train, uid_to_kill;
object horse_master;

void create()
{
    horse_stats = ([]);
    restore_object(SAVE_FILE);
}

void add_horse_name(string str)
{

	string *temp=({});
    string new_owner_name, real_owner_name, owner_on_file, choice;
    int x;
    int i;
    string name,owner;
     RELOAD();
    temp = keys(horse_stats);
    i = 0;
    real_owner_name = TP->query_true_name();

	for (i=0;i<sizeof(temp);i++)
	{
	    owner_on_file = horse_stats[/**/temp[i]/**/]["real_owner"];
	    if(real_owner_name == owner_on_file){
	    tell_object(TP,"%^RESET%^%^RED%^You already own a horse. "+
		"You can't buy another\n");
		return 1;
	    }

	}

	if (!TP->query_funds("gold",500000)){
        tell_object(TP, "%^BLACK%^%^BOLD%^You dig through your posessions and can't "+
		"find enough to pay for that. A horse costs 500,000 gold.%^RESET%^");
        tell_room(ETP, "%^BLACK%^%^BOLD%^"+TPQCN+"%^BLACK%^%^BOLD%^ steps up to "+
		"buy a horse, then looks embarassed.%^RESET%^",TP);
    return 1;
    }



    if(!str || str == "") {

	    tell_object(TP,"%^RESET%^%^ORANGE%^You sit down with a merchant and "+
		"arrange to buy a racing horse. They look through a large book of "+
		"diferent horses and flip through the pages quickly. You can see "+
		"each page has specifics on where a horse was bred, who its sire "+
		"was, and more information. They find a page that does not have an "+
		"owner's information on it and set it down to fill it out. \n%^RESET%^");

		tell_room(ETP,"%^RESET%^%^ORANGE%^Pulling out a chair, "+TPQCN+"%^RESET%^"+
		"%^ORANGE%^ starts the paperwork to buy a race horse. The merchant flips "+
		"through a book of horses before settling on one and pulling the "+
		"papers out for them. \n%^RESET%^",TP);

	    tell_object(TP,"%^RESET%^%^RED%^You are purchasing a fine young horse. "+
		"You must now give it a name. This is the name that the rest of the world "+
		"will see when it is researched or when it is racing. You can use color "+
		"codes here. Please keep the name under 14 characters  (not including "+
		"color codes). If you are unsure what to use yet, use ** to abort.\n%^RESET%^");
    input_to("add_horse_name",str);
	return;
	}

    new_horse_name = str;
    if(new_horse_name == "**"){
	return;
	}

    tell_object(TP,"%^RESET%^%^RED%^A fine name for a racing horse. Now your trainer "+
    "will know to only work with you, and knows you personally, but you choose how the "+
    "world knows you in relation to this horse. It is suggested you use your name so "+
    "you can share the glory in your horse's victories but if you have bought this "+
    "horse on behalf of a guild or group then you can certainly use that as an owner's "+
    "name. If you would like to end the process and think it over more then "+
    "enter ** to abort.\n%^RESET%^");
    input_to("add_owner_name",str);

return;
}

void add_owner_name(string str)
{

	string *temp=({});
    string new_owner_name, real_owner_name, owner_on_file;
    int x;
    int i;
	int a,b,c,d,e;
    string name,owner;
    temp = keys(horse_stats);
    i = 0;
    real_owner_name = TP->query_true_name();
    new_owner_name = str;

	    if( new_owner_name == "**"){
	return;
	}

    if(!str || str == "") {
    tell_object(TP,"%^BOLD%^%^RED%^\n\n A fine name for a racing horse. Now your trainer "+
    "will know to only work with you, and knows you personally, but you choose how the "+
    "world knows you in relation to this horse. It is suggested you use your name so "+
    "you can share the glory in your horse's victories but if you have bought this "+
    "horse on behalf of a guild or group then you can certainly use that as an owner's "+
    "name. If you would like to end the process and think it over more then "+
    "enter ** to abort.\n%^RESET%^");
    input_to("add_owner_name",str);

	new_owner_name = str;

	    if(new_owner_name == "**"){
	return;
	}
	return;
	}


temp = keys(horse_stats);
x = (sizeof(temp)+1);

	a = (random(10)+10);
	b = (random(10)+10);
	c = (random(10)+10);
	d = (random(10)+10);
	e = (a+b+c+d);

        horse_stats[x] = ([]);
		horse_stats[x]["UID"] = x;
		horse_stats[x]["name"] = new_horse_name;
        horse_stats[x]["speed"] = a;
        horse_stats[x]["health"] = b;
        horse_stats[x]["accel"] = c;
		horse_stats[x]["jockey"] = d;
		horse_stats[x]["total_skills"] = e;
        horse_stats[x]["win"] = 0;
        horse_stats[x]["loss"] = 0;
        horse_stats[x]["winnings"] = 0;
        horse_stats[x]["claim_winnings"] = 0;
        horse_stats[x]["owner"] = new_owner_name;
		horse_stats[x]["real_owner"] = real_owner_name;
		horse_stats[x]["stable"] = random(3)+1;
		horse_stats[x]["blurb1"] = random(9)+1;
		horse_stats[x]["blurb2"] = random(9)+1;
	SAVE();
	    TP->use_funds("gold", 500000);
	    tell_object(TP,"%^BOLD%^%^RED%^\n\nCongratulations, you are now the "+
		"proud owner of a race horse for all the world to see. The horse will "+
		"automatically be placed into the rotation and will race against all "+
		"of the other horses there. You will also find its information in the "+
		"books soon for others to research. Do not fear if your horse is not "+
		"as fast, or your jockey not as trained as other horses. The tracks "+
		"we race have many surprises and underdogs have a tendancy of beating "+
		"the favorites. You can also invest training time into your horse to "+
		"improve it, and its jockey over time to better compete against the "+
		"other horses. The sign here will help if you forget how to manage "+
		"your horse. And good luck.\n%^RESET%^");

}

void train_horse(string str)
{

	string *temp=({});
    string new_owner_name, real_owner_name, owner_on_file, choice;
    int x;
    int i;
    string name,owner;
     RELOAD();
    temp = keys(horse_stats);
    i = 0;
	x = 0;
    real_owner_name = TP->query_true_name();

	for (i=0;i<sizeof(temp);i++)
	{
	    owner_on_file = horse_stats[/**/temp[i]/**/]["real_owner"];
		if(real_owner_name == owner_on_file){
		    x = 1;
			uid_to_train = i;
	    tell_object(TP,"%^RESET%^%^ORANGE%^Your trainer enters the room and "+
		"beckons you over for a private conversation.\n\nAfter relating how your "+
		"horse is doing they ask you what you want to focus training on right "+
		"now. Your horse's '%^YELLOW%^speed%^RESET%^%^ORANGE%^', its ability "+
		"in '%^YELLOW%^acceleration%^RESET%^%^ORANGE%^', or the training of "+
		"it's '%^YELLOW%^jockey%^RESET%^%^ORANGE%^'. Anything else entered "+
		"will end the conversation.%^RESET%^\n");
		input_to("pick_training",str);
		return;
	    }
	}
    tell_object(TP,"%^RESET%^%^RED%^We can't find a horse that belongs to you.\n");
	return;
}

void pick_training(string str)
{
    string *temp=({});
    string new_owner_name, real_owner_name, owner_on_file, choice, status_of_training;
    int x;
    int i;
    string name,owner, blah;

    temp = keys(horse_stats);
    i = 0;
	x = 0;

	training_picked = str;
    if(training_picked == "speed"){

	    status_of_training = horse_stats[/**/temp[uid_to_train]/**/]["status"];
	    if(status_of_training == 1){
	        tell_object(TP,"%^RESET%^%^ORANGE%^Your trainer looks over the books "+
			"and reminds you that you are still training your horse in that.\n%^RESET%^");
			return;
    }
	tell_object(TP,"%^RESET%^%^ORANGE%^How much gold do you want to invest in that?\n%^RESET%^");
    input_to("train_speed",str);
		return;
	}

	if(training_picked == "acceleration"){
	    status_of_training = horse_stats[/**/temp[uid_to_train]/**/]["status"];
	    if(status_of_training == 1){
	        tell_object(TP,"%^RESET%^%^ORANGE%^Your trainer looks over the books "+
			"and reminds you that you are still training your horse in that.\n%^RESET%^");
			return;
    }
	tell_object(TP,"%^RESET%^%^ORANGE%^How much do you want to invest?\n%^RESET%^");
    input_to("train_acc",str);
		return;
	}
	if(training_picked == "jockey"){
	    status_of_training = horse_stats[/**/temp[uid_to_train]/**/]["status"];
	    if(status_of_training == 1){
	        tell_object(TP,"%^RESET%^%^ORANGE%^Your trainer looks over the books "+
			"and reminds you that you are still training your horse in that.\n%^RESET%^");
			return;
    }
	tell_object(TP,"%^RESET%^%^ORANGE%^How much do you want to invest?\n%^RESET%^");
    input_to("train_jockey",str);
		return;
    }

	tell_object(TP,"%^RESET%^%^ORANGE%^Your trainer thanks you for your time.\n%^RESET%^");
		return;
}

void train_speed(int num)
{

	string *temp=({});
    int x, i, y, invested_old, invested_new, invested, speed_old, difference, speed_new, status_of_training, old_total_stats, new_total_stats;
    string name,owner, blah;
    temp = keys(horse_stats);
    i = 0;
	x = 0;
	sscanf(num,"%d",invested);
	invested_old = horse_stats[/**/temp[uid_to_train]/**/]["invested"];
	speed_old = horse_stats[/**/temp[uid_to_train]/**/]["speed"];
	status_of_training = horse_stats[/**/temp[uid_to_train]/**/]["status"];
	old_total_stats = horse_stats[/**/temp[uid_to_train]/**/]["total_skills"];

	if(speed_old < 100){y = 1000000;}
	if(speed_old < 75){y = 150000;}
	if(speed_old < 50){y = 50000;}
	if(speed_old < 25){y = 10000;}

	difference = (invested / y);
	new_total_stats = (old_total_stats + difference);

	if (!TP->query_funds("gold",invested)){
        tell_object(TP, "%^BLACK%^%^BOLD%^You dig through your posessions and can't "+
		"find enough to pay for that%^RESET%^");
        tell_room(ETP, "%^BLACK%^%^BOLD%^"+TPQCN+"%^BLACK%^%^BOLD%^ steps up to "+
		"invest, then looks embarassed.%^RESET%^",TP);
    return 1;
    }

    TP->use_funds("gold", invested);

    tell_object(TP,"%^RESET%^%^ORANGE%^You hand over the gold and give your instructions. "+
	"You are informed by Baffert that the training will take some time, and you will not "+
	"be able to do any training in the mean time.\n%^RESET%^");

	if(difference > 5){difference = 5;}
	horse_stats[/**/temp[uid_to_train]/**/]["status"] = 1;
	invested_new = invested_old + invested;
	horse_stats[/**/temp[uid_to_train]/**/]["invested"] = invested_new;
	speed_new = speed_old + difference;
	if(speed_new > 100){speed_new = 100;}
	horse_stats[/**/temp[uid_to_train]/**/]["speed"] = speed_new;
	horse_stats[/**/temp[uid_to_train]/**/]["total_skills"] = new_total_stats;

		SAVE();

}

void train_acc(int num)
{

	string *temp=({});
    int x, i, y, invested_old, invested_new, invested, acc_old, difference, acc_new, status_of_training, old_total_stats, new_total_stats;
    string name,owner, blah;
    temp = keys(horse_stats);
    i = 0;
	x = 0;
	sscanf(num,"%d",invested);
	invested_old = horse_stats[/**/temp[uid_to_train]/**/]["invested"];
	acc_old = horse_stats[/**/temp[uid_to_train]/**/]["accel"];
	status_of_training = horse_stats[/**/temp[uid_to_train]/**/]["status"];
	old_total_stats = horse_stats[/**/temp[uid_to_train]/**/]["total_skills"];

	if(acc_old < 100){y = 1000000;}
	if(acc_old < 75){y = 150000;}
	if(acc_old < 50){y = 50000;}
	if(acc_old < 25){y = 10000;}

	difference = (invested / y);
	new_total_stats = (old_total_stats + difference);

	if (!TP->query_funds("gold",invested)){
        tell_object(TP, "%^BLACK%^%^BOLD%^You dig through your posessions and can't "+
		"find enough to pay for that%^RESET%^");
        tell_room(ETP, "%^BLACK%^%^BOLD%^"+TPQCN+"%^BLACK%^%^BOLD%^ steps up to "+
		"invest, then looks embarassed.%^RESET%^",TP);
    return 1;
    }

    TP->use_funds("gold", invested);

    tell_object(TP,"%^RESET%^%^ORANGE%^You hand over the gold and give your instructions. "+
	"You are informed by Baffert that the training will take some time, and you will not "+
	"be able to do any training in the mean time.\n%^RESET%^");

	if(difference > 5){difference = 5;}
	horse_stats[/**/temp[uid_to_train]/**/]["status"] = 1;
	invested_new = invested_old + invested;
	horse_stats[/**/temp[uid_to_train]/**/]["invested"] = invested_new;
	acc_new = acc_old + difference;
	if(acc_new > 100){acc_new = 100;}
	horse_stats[/**/temp[uid_to_train]/**/]["accel"] = acc_new;
	horse_stats[/**/temp[uid_to_train]/**/]["total_skills"] = new_total_stats;

		SAVE();
}

void train_jockey(int num)
{

	string *temp=({});
    int x, i, y, invested_old, invested_new, invested, jockey_old, difference, jockey_new, status_of_training, old_total_stats, new_total_stats;
    string name,owner, blah;
    temp = keys(horse_stats);
    i = 0;
	x = 0;
	sscanf(num,"%d",invested);
	invested_old = horse_stats[/**/temp[uid_to_train]/**/]["invested"];
	jockey_old = horse_stats[/**/temp[uid_to_train]/**/]["jockey"];
	status_of_training = horse_stats[/**/temp[uid_to_train]/**/]["status"];
	old_total_stats = horse_stats[/**/temp[uid_to_train]/**/]["total_skills"];

	if(jockey_old < 100){y = 1000000;}
	if(jockey_old < 75){y = 150000;}
	if(jockey_old < 50){y = 50000;}
	if(jockey_old < 25){y = 10000;}

	difference = (invested / y);
	new_total_stats = (old_total_stats + difference);

	if (!TP->query_funds("gold",invested)){
        tell_object(TP, "%^BLACK%^%^BOLD%^You dig through your posessions and "+
		"can't find enough to pay for that%^RESET%^");
        tell_room(ETP, "%^BLACK%^%^BOLD%^"+TPQCN+"%^BLACK%^%^BOLD%^ steps up to "+
		"invest, then looks embarassed.%^RESET%^",TP);
    return 1;
    }

    TP->use_funds("gold", invested);

    tell_object(TP,"%^RESET%^%^ORANGE%^You hand over the gold and give your instructions. "+
	"You are informed by Baffert that the training will take some time, and you will not "+
	"be able to do any training in the mean time.\n%^RESET%^");

	if(difference > 5){difference = 5;}
	horse_stats[/**/temp[uid_to_train]/**/]["status"] = 1;
	invested_new = invested_old + invested;
	horse_stats[/**/temp[uid_to_train]/**/]["invested"] = invested_new;
	jockey_new = jockey_old + difference;
	if(jockey_new > 100){jockey_new = 100;}
	horse_stats[/**/temp[uid_to_train]/**/]["jockey"] = jockey_new;
	horse_stats[/**/temp[uid_to_train]/**/]["total_skills"] = new_total_stats;

		SAVE();
}

void clear_all_training(string str)
{

	string *temp=({});
    string new_owner_name, real_owner_name, owner_on_file, choice;
    int x;
    int i,w,q;
    string name,owner;

    temp = keys(horse_stats);
    RELOAD();
    i = 0;
	q = 0;
    real_owner_name = TP->query_true_name();

	for (i=0;i<sizeof(temp);i++)
	{
	    horse_stats[/**/temp[i]/**/]["status"] = 0;
	    }
		tell_room(ETP,"%^RESET%^%^ORANGE%^trainers scurry around giving reports to Baffert%^RESET%^\n");
	    SAVE();
		return 1;

}

void kill_a_horse(string str)
{
    string *temp=({});
    string new_owner_name, real_owner_name, owner_on_file, choice;
    int x;
    int i;
    string name,owner;
      RELOAD();
    temp = keys(horse_stats);
    i = 0;
	x = 0;
    real_owner_name = TP->query_true_name();

	for (i=0;i<sizeof(temp);i++)
	{
	    owner_on_file = horse_stats[/**/temp[i]/**/]["real_owner"];
		if(real_owner_name == owner_on_file){
		    x = 1;
			uid_to_kill = i;
	    tell_object(TP,"%^RESET%^%^ORANGE%^Your trainer enters the "+
		"room and frowns. He asks are you sure you want to get rid of "+
		"your horse. %^BOLD%^%^WHITE%^This CANNOT be undone%^RESET%^%^ORANGE%^. "+
		"You will also receive no money for the horse. Enter '%^YELLOW%^yes%^RESET%^%^ORANGE%^' to continue, "+
		"anything else to abort. %^RESET%^\n");
		input_to("kill_the_horse",str);
		return;
	    }
	}
    tell_object(TP,"%^RESET%^%^RED%^We can't find a horse that belongs to you.\n");
	return;
}

void kill_the_horse(string str)
{

    string *temp=({});
    string new_owner_name, real_owner_name, owner_on_file, choice;
    int x;
    int i;
    string name,owner;
    temp = keys(horse_stats);
    i = sizeof(temp);
	    if( str != "yes"){
	return;
	}
	horse_stats[/**/temp[uid_to_kill]/**/]["name"] = "dead";
	horse_stats[/**/temp[uid_to_kill]/**/]["real_owner"] = "the afterlife";
    tell_object(TP,"%^RESET%^%^ORANGE%^Your trainer nods and hands paperwork to Baffert. "+
	"\nBaffert looks over with a serious expression and nods, then signs the paperwork "+
	"and hands it back. The trainer disapears to handle the horse. Baffert explains that "+
	"no one will want to buy a horse you gave up, so... other means must be taken.\n%^RESET%^\n");
	SAVE();
	return;
}

void item_fun(string str, int y, int x)
{

int type, true_value, value, stat_old, stat_new, old_total_stats, new_total_stats,i;
string *temp=({});
string owner_on_file, name_check;
type = y;
x = x + 1;
true_value = x;
owner_on_file = str;
temp = keys(horse_stats);
RELOAD();
for (i=0;i<sizeof(temp);i++)
	{
	    name_check = horse_stats[/**/temp[i]/**/]["real_owner"];
		if(owner_on_file == name_check){
		    x = 1;
			uid_to_train = i;
	if(type == 1){
		stat_old = horse_stats[/**/temp[uid_to_train]/**/]["speed"];
		old_total_stats = horse_stats[/**/temp[uid_to_train]/**/]["total_skills"];
		stat_new = (stat_old + true_value);
		new_total_stats = (old_total_stats + true_value);
		horse_stats[/**/temp[uid_to_train]/**/]["speed"] = stat_new;
	    horse_stats[/**/temp[uid_to_train]/**/]["total_skills"] = new_total_stats;
    tell_object(TP,"%^RESET%^%^BOLD%^Baffert hands the horse shoes to a trainer who "+
	"sends it to your jockey.%^RESET%^\n");
		SAVE();
		return;
		}

	if(type == 2){
		stat_old = horse_stats[/**/temp[uid_to_train]/**/]["accel"];
		old_total_stats = horse_stats[/**/temp[uid_to_train]/**/]["total_skills"];
		stat_new = (stat_old + true_value);
		new_total_stats = (old_total_stats + true_value);
		horse_stats[/**/temp[uid_to_train]/**/]["accel"] = stat_new;
	    horse_stats[/**/temp[uid_to_train]/**/]["total_skills"] = new_total_stats;
    tell_object(TP,"%^RESET%^%^ORANGE%^Baffert hands the spurs to a trainer who "+
	"sends it to your jockey.%^RESET%^\n");
		SAVE();
		return;
	    }

	if(type == 3){
		stat_old = horse_stats[/**/temp[uid_to_train]/**/]["jockey"];
		old_total_stats = horse_stats[/**/temp[uid_to_train]/**/]["total_skills"];
		stat_new = (stat_old + true_value);
		new_total_stats = (old_total_stats + true_value);
		horse_stats[/**/temp[uid_to_train]/**/]["jockey"] = stat_new;
	    horse_stats[/**/temp[uid_to_train]/**/]["total_skills"] = new_total_stats;
    tell_object(TP,"%^RESET%^%^RED%^Baffert hands the riding crop to a trainer who "+
	"sends it to your jockey.%^RESET%^\n");
		SAVE();
		return;
	    }
			tell_room(ETP,"%^RESET%^%^ORANGE%^not trained!%^RESET%^");
				return;
	    }
	}
    tell_object(TP,"%^RESET%^%^RED%^We can't find a horse that belongs to you.\n");
	return;
}

void reinvest(string str)
{

	string *temp=({});
    string new_owner_name, real_owner_name, owner_on_file, choice;
    int x;
    int i;
    string name,owner;
    RELOAD();
    temp = keys(horse_stats);
    i = 0;
	x = 0;
    real_owner_name = TP->query_true_name();

	for (i=0;i<sizeof(temp);i++)
	{
	    owner_on_file = horse_stats[/**/temp[i]/**/]["real_owner"];
		if(real_owner_name == owner_on_file){
		    x = 1;
			uid_to_train = i;
	    tell_object(TP,"%^RESET%^%^ORANGE%^Your trainer enters the room and "+
		"beckons you over for a private conversation.\n\nAfter relating how your "+
		"horse is doing they ask you what you want to reinvest your winnings right "+
		"now. Your horse's '%^YELLOW%^speed%^RESET%^%^ORANGE%^', its ability "+
		"in '%^YELLOW%^acceleration%^RESET%^%^ORANGE%^', or the training of "+
		"it's '%^YELLOW%^jockey%^RESET%^%^ORANGE%^'. Anything else entered "+
		"will end the conversation.%^RESET%^\n");
		input_to("pick_reinvest",str);
		return;
	    }
	}
    tell_object(TP,"%^RESET%^%^RED%^We can't find a horse that belongs to you.\n");
	return;
}

void pick_reinvest(string str)
{
    string *temp=({});
    string new_owner_name, real_owner_name, owner_on_file, choice, status_of_training;
    int x;
    int i;
	int amount_avail, winnings, claim_winnings;
    string name,owner, blah;

    temp = keys(horse_stats);
    i = 0;
	x = 0;

	training_picked = str;

	winnings = horse_stats[/**/temp[uid_to_train]/**/]["winnings"];
	claim_winnings = horse_stats[/**/temp[uid_to_train]/**/]["claim_winnings"];
	amount_avail = winnings - claim_winnings;

    if(training_picked == "speed"){
	    if(amount_avail < 1){
	        tell_object(TP,"%^RESET%^%^ORANGE%^Your trainer looks over the books "+
			"and reminds you that you have no winnings to reinvest.\n%^RESET%^");
			return;
    }
	tell_object(TP,"%^RESET%^%^ORANGE%^How much of your "+amount_avail+" available do "+
	"you want to reinvest?\n%^RESET%^");
    input_to("train_speed2",str);
		return;
	}

	if(training_picked == "acceleration"){
	    if(amount_avail < 1){
	        tell_object(TP,"%^RESET%^%^ORANGE%^Your trainer looks over the books "+
			"and reminds you that you have no winnings to reinvest.\n%^RESET%^");
			return;
    }
	tell_object(TP,"%^RESET%^%^ORANGE%^How much of your "+amount_avail+" available do "+
	"you want to reinvest?\n%^RESET%^");
    input_to("train_acc2",str);
		return;
	}
	if(training_picked == "jockey"){
	    if(amount_avail < 1){
	        tell_object(TP,"%^RESET%^%^ORANGE%^Your trainer looks over the books "+
			"and reminds you that you have no winnings to reinvest.\n%^RESET%^");
			return;
    }
	tell_object(TP,"%^RESET%^%^ORANGE%^How much of your "+amount_avail+" available do "+
	"you want to reinvest?\n%^RESET%^");
    input_to("train_jockey2",str);

		return;
    }

	tell_object(TP,"%^RESET%^%^ORANGE%^Your trainer thanks you for your time.\n%^RESET%^");
		return;
}

void train_speed2(int num)
{

	string *temp=({});
    int x, i, y, invested_old, invested_new, invested, speed_old, difference, speed_new, status_of_training, old_total_stats, new_total_stats;
	int winnings, claim_winnings, amount_avail;
    string name,owner, blah;
    temp = keys(horse_stats);
    i = 0;
	x = 0;
	sscanf(num,"%d",invested);

	invested_old = horse_stats[/**/temp[uid_to_train]/**/]["invested"];
	speed_old = horse_stats[/**/temp[uid_to_train]/**/]["speed"];
	status_of_training = horse_stats[/**/temp[uid_to_train]/**/]["status"];
	old_total_stats = horse_stats[/**/temp[uid_to_train]/**/]["total_skills"];

    winnings = horse_stats[/**/temp[uid_to_train]/**/]["winnings"];
	claim_winnings = horse_stats[/**/temp[uid_to_train]/**/]["claim_winnings"];
	amount_avail = winnings - claim_winnings;

	if(speed_old < 100){y = 1000000;}
	if(speed_old < 75){y = 150000;}
	if(speed_old < 50){y = 50000;}
	if(speed_old < 25){y = 10000;}

	difference = (invested / y);
	new_total_stats = (old_total_stats + difference);

	if (invested > amount_avail){
        tell_object(TP, "%^BLACK%^%^BOLD%^There is not that much available to re-invest%^RESET%^");
        tell_room(ETP, "%^BLACK%^%^BOLD%^"+TPQCN+"%^BLACK%^%^BOLD%^ frowns as they look over their paperwork.%^RESET%^",TP);
    return 1;
    }

    claim_winnings = claim_winnings + invested;
	horse_stats[/**/temp[uid_to_train]/**/]["claim_winnings"] = claim_winnings;


    tell_object(TP,"%^RESET%^%^ORANGE%^You hand over the paperwork to reinvest and give your instructions. "+
	"You are informed by Baffert that the training will take some time.\n%^RESET%^");

	if(difference > 5){difference = 5;}
	horse_stats[/**/temp[uid_to_train]/**/]["status"] = 1;
	invested_new = invested_old + invested;
	horse_stats[/**/temp[uid_to_train]/**/]["invested"] = invested_new;
	speed_new = speed_old + difference;
	if(speed_new > 100){speed_new = 100;}
	horse_stats[/**/temp[uid_to_train]/**/]["speed"] = speed_new;
	horse_stats[/**/temp[uid_to_train]/**/]["total_skills"] = new_total_stats;

		SAVE();

}

void train_acc2(int num)
{

	string *temp=({});
    int x, i, y, invested_old, invested_new, invested, acc_old, difference, acc_new, status_of_training, old_total_stats, new_total_stats;
    int winnings, claim_winnings, amount_avail;
    string name,owner, blah;
    temp = keys(horse_stats);
    i = 0;
	x = 0;
	sscanf(num,"%d",invested);
	invested_old = horse_stats[/**/temp[uid_to_train]/**/]["invested"];
	acc_old = horse_stats[/**/temp[uid_to_train]/**/]["accel"];
	status_of_training = horse_stats[/**/temp[uid_to_train]/**/]["status"];
	old_total_stats = horse_stats[/**/temp[uid_to_train]/**/]["total_skills"];

    winnings = horse_stats[/**/temp[uid_to_train]/**/]["winnings"];
	claim_winnings = horse_stats[/**/temp[uid_to_train]/**/]["claim_winnings"];
	amount_avail = winnings - claim_winnings;


	if(acc_old < 100){y = 1000000;}
	if(acc_old < 75){y = 150000;}
	if(acc_old < 50){y = 50000;}
	if(acc_old < 25){y = 10000;}

	difference = (invested / y);
	new_total_stats = (old_total_stats + difference);

	if (invested > amount_avail){
        tell_object(TP, "%^BLACK%^%^BOLD%^There is not that much available to re-invest%^RESET%^");
        tell_room(ETP, "%^BLACK%^%^BOLD%^"+TPQCN+"%^BLACK%^%^BOLD%^ frowns as they look over their paperwork.%^RESET%^",TP);
    return 1;
    }

    claim_winnings = claim_winnings + invested;
	horse_stats[/**/temp[uid_to_train]/**/]["claim_winnings"] = claim_winnings;

    tell_object(TP,"%^RESET%^%^ORANGE%^You hand over the paperwork to reinvest and give your instructions. "+
	"You are informed by Baffert that the training will take some time.\n%^RESET%^");

	if(difference > 5){difference = 5;}
	horse_stats[/**/temp[uid_to_train]/**/]["status"] = 1;
	invested_new = invested_old + invested;
	horse_stats[/**/temp[uid_to_train]/**/]["invested"] = invested_new;
	acc_new = acc_old + difference;
	if(acc_new > 100){acc_new = 100;}
	horse_stats[/**/temp[uid_to_train]/**/]["accel"] = acc_new;
	horse_stats[/**/temp[uid_to_train]/**/]["total_skills"] = new_total_stats;

		SAVE();
}

void train_jockey2(int num)
{

	string *temp=({});
    int x, i, y, invested_old, invested_new, invested, jockey_old, difference, jockey_new, status_of_training, old_total_stats, new_total_stats;
	int winnings, claim_winnings, amount_avail;
    string name,owner, blah;
    temp = keys(horse_stats);
    i = 0;
	x = 0;
	sscanf(num,"%d",invested);
	invested_old = horse_stats[/**/temp[uid_to_train]/**/]["invested"];
	jockey_old = horse_stats[/**/temp[uid_to_train]/**/]["jockey"];
	status_of_training = horse_stats[/**/temp[uid_to_train]/**/]["status"];
	old_total_stats = horse_stats[/**/temp[uid_to_train]/**/]["total_skills"];

    winnings = horse_stats[/**/temp[uid_to_train]/**/]["winnings"];
	claim_winnings = horse_stats[/**/temp[uid_to_train]/**/]["claim_winnings"];
	amount_avail = winnings - claim_winnings;

	if(jockey_old < 100){y = 1000000;}
	if(jockey_old < 75){y = 150000;}
	if(jockey_old < 50){y = 50000;}
	if(jockey_old < 25){y = 10000;}

	difference = (invested / y);
	new_total_stats = (old_total_stats + difference);

	if (invested > amount_avail){
        tell_object(TP, "%^BLACK%^%^BOLD%^There is not that much available to re-invest%^RESET%^");
        tell_room(ETP, "%^BLACK%^%^BOLD%^"+TPQCN+"%^BLACK%^%^BOLD%^ frowns as they look over their paperwork.%^RESET%^",TP);
    return 1;
    }

    claim_winnings = claim_winnings + invested;
	horse_stats[/**/temp[uid_to_train]/**/]["claim_winnings"] = claim_winnings;

    tell_object(TP,"%^RESET%^%^ORANGE%^You hand over the paperwork to reinvest and give your instructions. "+
	"You are informed by Baffert that the training will take some time.\n%^RESET%^");

	if(difference > 5){difference = 5;}
	horse_stats[/**/temp[uid_to_train]/**/]["status"] = 1;
	invested_new = invested_old + invested;
	horse_stats[/**/temp[uid_to_train]/**/]["invested"] = invested_new;
	jockey_new = jockey_old + difference;
	if(jockey_new > 100){jockey_new = 100;}
	horse_stats[/**/temp[uid_to_train]/**/]["jockey"] = jockey_new;
	horse_stats[/**/temp[uid_to_train]/**/]["total_skills"] = new_total_stats;

		SAVE();
}

void withdraw1(int num)
{
	string *temp=({});
    string new_owner_name, real_owner_name, owner_on_file, choice;
    int x;
    int i;
	int winnings, claim_winnings, amount_avail;
    string name,owner;
     RELOAD();
    temp = keys(horse_stats);
    i = 0;
	x = 0;
    real_owner_name = TP->query_true_name();

	winnings = horse_stats[/**/temp[uid_to_train]/**/]["winnings"];
	claim_winnings = horse_stats[/**/temp[uid_to_train]/**/]["claim_winnings"];
	amount_avail = winnings - claim_winnings;


	for (i=0;i<sizeof(temp);i++)
	{
	    owner_on_file = horse_stats[/**/temp[i]/**/]["real_owner"];
		if(real_owner_name == owner_on_file){
		    x = 1;
			uid_to_train = i;
	    tell_object(TP,"%^RESET%^%^ORANGE%^Your trainer enters the room and "+
		"congratulates you on your winnings! You have "+amount_avail+" to withdraw "+
		"from. Remember you will only get half of this as gold, as the house "+
		"takes the rest%^RESET%^\n");
		input_to("withdraw2",num);
		return;
	    }
	}
    tell_object(TP,"%^RESET%^%^RED%^We can't find a horse that belongs to you.\n");
	return;
}

void withdraw2(int num)
{
	string *temp=({});
    string new_owner_name, real_owner_name, owner_on_file, choice;
    int x;
    int i;
	int winnings, claim_winnings, amount_avail, withdraw;
    string name,owner;
     RELOAD();
    temp = keys(horse_stats);
    i = 0;
	x = 0;
    real_owner_name = TP->query_true_name();

	sscanf(num,"%d",withdraw);
	winnings = horse_stats[/**/temp[uid_to_train]/**/]["winnings"];
	claim_winnings = horse_stats[/**/temp[uid_to_train]/**/]["claim_winnings"];
	amount_avail = winnings - claim_winnings;

	if (withdraw > amount_avail){
        tell_object(TP, "%^BLACK%^%^BOLD%^There is not that much available to withdrawt%^RESET%^");
        tell_room(ETP, "%^BLACK%^%^BOLD%^"+TPQCN+"%^BLACK%^%^BOLD%^ frowns as they look over their paperwork.%^RESET%^",TP);
    return 1;
    }

	claim_winnings = claim_winnings + withdraw;
	horse_stats[/**/temp[uid_to_train]/**/]["claim_winnings"] = claim_winnings;

	withdraw = (withdraw / 2);
	TP->add_money("gold", withdraw);
    tell_object(TP, "%^BLACK%^%^BOLD%^Your trainer hands over "+withdraw+" gold.%^RESET%^");

	SAVE();
	return;
}

void SAVE()
{
    save_me(SAVE_FILE);

	horse_master =find_object_or_load(STORAGE"horse_master.c");
	horse_master->create();

    return;
}

void RELOAD()
{
    horse_stats = ([]);
    restore_object(SAVE_FILE);
}
