#include <std.h>
#include <security.h>
#include "../horse.h"

inherit OBJECT;



#define SAVE_FILE "/d/save/horse_race_stuff"


mapping horse_stats;

nosave mapping example_variable;

nosave string race_horses;
int edge1, edge2, edge3, edge4;
int weather;
int location;
int length;
int danger;
int purse, current_winner, winner_edge;
int h1, h2;
string new_horse_name;
int real1, real2, real3, real4;
string check_if_dead;

void create()
{

    horse_stats = ([]);

    restore_object(SAVE_FILE);

    setup_horses();
}

void setup_horses()
{

    if(!sizeof(horse_stats))
    {
        horse_stats[1] = ([]);
		horse_stats[1]["UID"] = 1;
		horse_stats[1]["name"] = "%^RESET%^%^BOLD%^Shi%^YELLOW%^n%^WHITE%^ing "+
		"S%^YELLOW%^t%^WHITE%^ar%^RESET%^";
        horse_stats[1]["speed"] = 23;
        horse_stats[1]["health"] = 12;
        horse_stats[1]["accel"] = 25;
		horse_stats[1]["jockey"] = 35;
        horse_stats[1]["win"] = 0;
        horse_stats[1]["loss"] = 0;
        horse_stats[1]["winnings"] = 0;
        horse_stats[1]["claim_winnings"] = 0;
        horse_stats[1]["owner"] = "The King Of Antioch";
		horse_stats[1]["real_owner"] = "loki";
		horse_stats[1]["stable"] = 3;
		horse_stats[1]["blurb1"] = 1;
		horse_stats[1]["blurb2"] = 1;
        horse_stats[1]["total_skills"] = 70;


        horse_stats[2] = ([]);
		horse_stats[2]["UID"] = 2;
		horse_stats[2]["name"] = "%^RESET%^%^ORANGE%^Ka%^BLACK%^%^BOLD%^"+
		"l%^RESET%^%^ORANGE%^a'rib%^RESET%^";
        horse_stats[2]["speed"] = 23;
        horse_stats[2]["health"] = 16;
        horse_stats[2]["accel"] = 15;
		horse_stats[2]["jockey"] = 30;
        horse_stats[2]["win"] = 0;
        horse_stats[2]["loss"] = 0;
        horse_stats[2]["winnings"] = 0;
        horse_stats[2]["claim_winnings"] = 0;
        horse_stats[2]["owner"] = "Sheik Talar";
		horse_stats[2]["real_owner"] = "loki";
		horse_stats[2]["stable"] = 1;
		horse_stats[2]["blurb1"] = 2;
		horse_stats[2]["blurb2"] = 6;
        horse_stats[2]["total_skills"] = 84;

        horse_stats[3] = ([]);
		horse_stats[3]["UID"] = 3;
		horse_stats[3]["name"] = "%^RESET%^%^BOLD%^Tou%^RESET%^%^CYAN%^"+
		"c%^RESET%^%^BOLD%^h of Frost%^RESET%^";
        horse_stats[3]["speed"] = 13;
        horse_stats[3]["health"] = 32;
        horse_stats[3]["accel"] = 15;
		horse_stats[3]["jockey"] = 25;
        horse_stats[3]["win"] = 0;
        horse_stats[3]["loss"] = 0;
        horse_stats[3]["winnings"] = 0;
        horse_stats[3]["claim_winnings"] = 0;
        horse_stats[3]["owner"] = "Dougan Frost";
		horse_stats[3]["real_owner"] = "loki";
		horse_stats[3]["stable"] = 3;
		horse_stats[3]["blurb1"] = 4;
		horse_stats[3]["blurb2"] = 5;
        horse_stats[3]["total_skills"] = 85;

        horse_stats[4] = ([]);
		horse_stats[4]["UID"] = 4;
		horse_stats[4]["name"] = "%^BLACK%^%^BOLD%^Our Gift%^RESET%^";
        horse_stats[4]["speed"] = 22;
        horse_stats[4]["health"] = 12;
        horse_stats[4]["accel"] = 9;
		horse_stats[4]["jockey"] = 32;
        horse_stats[4]["win"] = 0;
        horse_stats[4]["loss"] = 0;
        horse_stats[4]["winnings"] = 0;
        horse_stats[4]["claim_winnings"] = 0;
        horse_stats[4]["owner"] = "Tharis Co-op";
		horse_stats[4]["real_owner"] = "loki";
		horse_stats[4]["stable"] = 2;
		horse_stats[4]["blurb1"] = 7;
		horse_stats[4]["blurb2"] = 9;
		horse_stats[4]["total_skills"] = 75;

		horse_stats[5] = ([]);
		horse_stats[5]["UID"] = 5;
		horse_stats[5]["name"] = "%^BLUE%^%^BOLD%^Lu%^RESET%^c%^BLUE%^%^BOLD%^ky "+
		"Dancer%^RESET%^";
        horse_stats[5]["speed"] = 12;
        horse_stats[5]["health"] = 22;
        horse_stats[5]["accel"] = 26;
		horse_stats[5]["jockey"] = 12;
        horse_stats[5]["win"] = 0;
        horse_stats[5]["loss"] = 0;
        horse_stats[5]["winnings"] = 0;
        horse_stats[5]["claim_winnings"] = 0;
        horse_stats[5]["owner"] = "Lord Granger";
		horse_stats[5]["real_owner"] = "loki";
		horse_stats[5]["stable"] = 2;
		horse_stats[5]["blurb1"] = 4;
		horse_stats[5]["blurb2"] = 1;
		horse_stats[5]["total_skills"] = 72;

		horse_stats[6] = ([]);
		horse_stats[6]["UID"] = 6;
		horse_stats[6]["name"] = "%^MAGENTA%^S%^BOLD%^o%^RESET%^%^MAGENTA%^hritani%^RESET%^";
        horse_stats[6]["speed"] = 22;
        horse_stats[6]["health"] = 12;
        horse_stats[6]["accel"] = 20;
		horse_stats[6]["jockey"] = 32;
        horse_stats[6]["win"] = 0;
        horse_stats[6]["loss"] = 0;
        horse_stats[6]["winnings"] = 0;
        horse_stats[6]["claim_winnings"] = 0;
        horse_stats[6]["owner"] = "Magnus Durag";
		horse_stats[6]["real_owner"] = "loki";
		horse_stats[6]["stable"] = 4;
		horse_stats[6]["blurb1"] = 9;
		horse_stats[6]["blurb2"] = 3;
        horse_stats[6]["total_skills"] = 86;

		horse_stats[7] = ([]);
		horse_stats[7]["UID"] = 7;
		horse_stats[7]["name"] = "%^RESET%^%^GREEN%^Per%^BOLD%^f%^RESET%^%^GREEN%^ect "+
		"Melo%^BOLD%^d%^RESET%^%^GREEN%^y%^RESET%^";
        horse_stats[7]["speed"] = 12;
        horse_stats[7]["health"] = 32;
        horse_stats[7]["accel"] = 5;
		horse_stats[7]["jockey"] = 12;
        horse_stats[7]["win"] = 0;
        horse_stats[7]["loss"] = 0;
        horse_stats[7]["winnings"] = 0;
        horse_stats[7]["claim_winnings"] = 0;
        horse_stats[7]["owner"] = "Fflewdur Flam";
		horse_stats[7]["real_owner"] = "loki";
		horse_stats[7]["stable"] = 4;
		horse_stats[7]["blurb1"] = 7;
		horse_stats[7]["blurb2"] = 8;
        horse_stats[7]["total_skills"] = 70;

		horse_stats[8] = ([]);
		horse_stats[8]["UID"] = 8;
		horse_stats[8]["name"] = "%^BLACK%^%^BOLD%^Fu%^RESET%^%^MAGENTA%^r%^BLACK%^%^BOLD%^"+
		"y's M%^RESET%^%^MAGENTA%^a%^BLACK%^%^BOLD%^ntle%^RESET%^";
        horse_stats[8]["speed"] = 9;
        horse_stats[8]["health"] = 22;
        horse_stats[8]["accel"] = 20;
		horse_stats[8]["jockey"] = 22;
        horse_stats[8]["win"] = 0;
        horse_stats[8]["loss"] = 0;
        horse_stats[8]["winnings"] = 0;
        horse_stats[8]["claim_winnings"] = 0;
        horse_stats[8]["owner"] = "Kiervalan Telkaror";
		horse_stats[8]["real_owner"] = "loki";
		horse_stats[8]["stable"] = 2;
		horse_stats[8]["blurb1"] = 7;
		horse_stats[8]["blurb2"] = 3;
        horse_stats[8]["total_skills"] = 73;

		horse_stats[9] = ([]);
		horse_stats[9]["UID"] = 9;
		horse_stats[9]["name"] = "%^RESET%^%^ORANGE%^Bri%^BOLD%^d%^RESET%^%^ORANGE%^ged "+
		"over%^RESET%^";
        horse_stats[9]["speed"] = 5;
        horse_stats[9]["health"] = 32;
        horse_stats[9]["accel"] = 25;
		horse_stats[9]["jockey"] = 19;
        horse_stats[9]["win"] = 0;
        horse_stats[9]["loss"] = 0;
        horse_stats[9]["winnings"] = 0;
        horse_stats[9]["claim_winnings"] = 0;
        horse_stats[9]["owner"] = "Crown of Tabor";
		horse_stats[9]["real_owner"] = "loki";
		horse_stats[9]["stable"] = 1;
		horse_stats[9]["blurb1"] = 4;
		horse_stats[9]["blurb2"] = 1;
        horse_stats[9]["total_skills"] = 81;

		horse_stats[10] = ([]);
		horse_stats[10]["UID"] = 10;
		horse_stats[10]["name"] = "%^RESET%^%^BLUE%^She Shall Race%^RESET%^";
        horse_stats[10]["speed"] = 10;
        horse_stats[10]["health"] = 22;
        horse_stats[10]["accel"] = 25;
		horse_stats[10]["jockey"] = 12;
        horse_stats[10]["win"] = 0;
        horse_stats[10]["loss"] = 0;
        horse_stats[10]["winnings"] = 0;
        horse_stats[10]["claim_winnings"] = 0;
        horse_stats[10]["owner"] = "Tymora Co-op";
		horse_stats[10]["real_owner"] = "loki";
		horse_stats[10]["stable"] = 1;
		horse_stats[10]["blurb1"] = 2;
		horse_stats[10]["blurb2"] = 5;
        horse_stats[10]["total_skills"] = 69;


		horse_stats[11] = ([]);
		horse_stats[11]["UID"] = 11;
		horse_stats[11]["name"] = "%^BLACK%^%^BOLD%^In Me%^RESET%^m%^BLACK%^%^BOLD%^or"+
		"ium%^RESET%^";
        horse_stats[11]["speed"] = 30;
        horse_stats[11]["health"] = 19;
        horse_stats[11]["accel"] = 25;
		horse_stats[11]["jockey"] = 6;
        horse_stats[11]["win"] = 0;
        horse_stats[11]["loss"] = 0;
        horse_stats[11]["winnings"] = 0;
        horse_stats[11]["claim_winnings"] = 0;
        horse_stats[11]["owner"] = "Graez Veterans Ass.%^RESET%^";
		horse_stats[11]["real_owner"] = "loki";
		horse_stats[11]["stable"] = 4;
		horse_stats[11]["blurb1"] = 5;
		horse_stats[11]["blurb2"] = 2;
        horse_stats[11]["total_skills"] = 80;

		horse_stats[12] = ([]);
		horse_stats[12]["UID"] = 12;
		horse_stats[12]["name"] = "%^RESET%^%^BLUE%^Fa%^CYAN%^s%^RESET%^%^BLUE%^t"+
		"est %^CYAN%^R%^RESET%^%^BLUE%^oute%^RESET%^";
        horse_stats[12]["speed"] = 12;
        horse_stats[12]["health"] = 22;
        horse_stats[12]["accel"] = 21;
		horse_stats[12]["jockey"] = 15;
        horse_stats[12]["win"] = 0;
        horse_stats[12]["loss"] = 0;
        horse_stats[12]["winnings"] = 0;
        horse_stats[12]["claim_winnings"] = 0;
        horse_stats[12]["owner"] = "River Drivers United";
		horse_stats[12]["real_owner"] = "loki";
		horse_stats[12]["stable"] = 2;
		horse_stats[12]["blurb1"] = 3;
		horse_stats[12]["blurb2"] = 3;
        horse_stats[12]["total_skills"] = 70;

		horse_stats[13] = ([]);
		horse_stats[13]["UID"] = 13;
		horse_stats[13]["name"] = "%^MAGENTA%^%^BOLD%^Sec%^RESET%^%^MAGENTA%^o%^BOLD%^nd "+
		"Sight%^RESET%^";
        horse_stats[13]["speed"] = 12;
        horse_stats[13]["health"] = 12;
        horse_stats[13]["accel"] = 25;
		horse_stats[13]["jockey"] = 12;
        horse_stats[13]["win"] = 0;
        horse_stats[13]["loss"] = 0;
        horse_stats[13]["winnings"] = 0;
        horse_stats[13]["claim_winnings"] = 0;
        horse_stats[13]["owner"] = "Baron Eran";
		horse_stats[13]["real_owner"] = "loki";
		horse_stats[13]["stable"] = 4;
		horse_stats[13]["blurb1"] = 1;
		horse_stats[13]["blurb2"] = 4;
        horse_stats[13]["total_skills"] = 61;

		horse_stats[14] = ([]);
		horse_stats[14]["UID"] = 14;
		horse_stats[14]["name"] = "%^RESET%^%^GREEN%^Trib%^BOLD%^u%^RESET%^%^GREEN%^tary%^RESET%^";
        horse_stats[14]["speed"] = 22;
        horse_stats[14]["health"] = 32;
        horse_stats[14]["accel"] = 5;
		horse_stats[14]["jockey"] = 19;
        horse_stats[14]["win"] = 0;
        horse_stats[14]["loss"] = 0;
        horse_stats[14]["winnings"] = 0;
        horse_stats[14]["claim_winnings"] = 0;
        horse_stats[14]["owner"] = "Lady Pelas";
		horse_stats[14]["real_owner"] = "loki";
		horse_stats[14]["stable"] = 4;
		horse_stats[14]["blurb1"] = 6;
		horse_stats[14]["blurb2"] = 6;
        horse_stats[14]["total_skills"] = 78;

		horse_stats[15] = ([]);
		horse_stats[15]["UID"] = 15;
		horse_stats[15]["name"] = "%^YELLOW%^The P%^RESET%^%^ORANGE%^r%^YELLOW%^ince%^RESET%^";
        horse_stats[15]["speed"] = 11;
        horse_stats[15]["health"] = 22;
        horse_stats[15]["accel"] = 33;
		horse_stats[15]["jockey"] = 24;
        horse_stats[15]["win"] = 0;
        horse_stats[15]["loss"] = 0;
        horse_stats[15]["winnings"] = 0;
        horse_stats[15]["claim_winnings"] = 0;
        horse_stats[15]["owner"] = "Tal'na Kir";
		horse_stats[15]["real_owner"] = "loki";
		horse_stats[15]["stable"] = 1;
		horse_stats[15]["blurb1"] = 8;
		horse_stats[15]["blurb2"] = 2;
        horse_stats[15]["total_skills"] = 90;

		SAVE();
    }



}

void create_race()
{
    string *temp=({});
    string name;
    string *horses=({});
	int x,y,w,q,real_length;
	int aa,bb;
    temp = keys(horse_stats);
    while(sizeof(horses) != 4)
	    {
		aa = (random(sizeof(temp)));
		check_if_dead = horse_stats[/**/temp[aa]/**/]["name"];
		if(check_if_dead != "dead"){
            horses += ({ temp[aa] });
            horses = distinct_array(horses);
        }
		}

    race_horses = horses;
    weather = (random(3)+1);
    location = (random(4)+1);
    length = (random(4)+2);
	real_length = (length-1);
    danger = random(2);
    purse = random(100000);

    return;
}

void run_race()
{
    int highest, lap_to_beat, score_to_beat;
    string name;
    int lap;
    int speed, accel, health, jockey;
    int num, num2, num3, num4;
    int score, score2, score3, score4;
    int i,x;
	int win, loss;
	int yay_loss;
	int uid, old_winning;

        score = 0;
		score2 = 0;
		score3 = 0;
		score4 = 0;
		num = 0;
		num2 = 0;
		num3 = 0;
		num4 = 0;
		score_to_beat = 0;
		lap_to_beat = 0;

	lap = 1;
	tell_room(ETP,"Clarise %^CYAN%^relates%^RESET%^: And they're off!!!\n");
	for (lap=1;lap<length;lap++)
	{
        tell_room(ETP,"Clarise %^CYAN%^relates%^RESET%^: On the start of lap "+lap+".\n");


        name = horse_stats[/**/race_horses[0]/**/]["name"];
        speed = horse_stats[/**/race_horses[0]/**/]["speed"];
        accel = horse_stats[race_horses[0]]["accel"];
        health = horse_stats[race_horses[0]]["health"];
		jockey = horse_stats[race_horses[0]]["jockey"];

        num = ((accel / lap) + (speed / weather) + (health * lap) + (jockey * danger) +(random(50)) );
			switch(random(3)){
			case(0): tell_room(ETP,"Clarise %^CYAN%^relates%^RESET%^: On the start of the lap "+name+"%^RESET%^ has a strong start!");
			break;
			case(1): tell_room(ETP,"Clarise %^CYAN%^relates%^RESET%^: "+name+"%^RESET%^ has already found their pace!");
			break;
			case(2): tell_room(ETP,"Clarise %^CYAN%^relates%^RESET%^: And "+name+"%^RESET%^ heads for the inside track!");
			break;
			}
		score = (score + num);
	    highest = 0;
		lap_to_beat = num;

        name = horse_stats[/**/race_horses[1]/**/]["name"];
        speed = horse_stats[/**/race_horses[1]/**/]["speed"];
        accel = horse_stats[race_horses[1]]["accel"];
        health = horse_stats[race_horses[1]]["health"];
		jockey = horse_stats[race_horses[1]]["jockey"];

        num2 = ((accel / lap) + (speed / weather) + (health * lap) + (jockey * danger) +(random(50)) );
			switch(random(3)){
			case(0): tell_room(ETP,"Clarise %^CYAN%^relates%^RESET%^: "+name+"%^RESET%^ is trying to make their move!");
			break;
			case(1): tell_room(ETP,"Clarise %^CYAN%^relates%^RESET%^: "+name+"%^RESET%^ is on the outside!");
			break;
			case(2): tell_room(ETP,"Clarise %^CYAN%^relates%^RESET%^: Out of the box "+name+"%^RESET%^ heads for the inside track!");
			break;
			}
		score2 = (score2 + num2);
		if (num2 > lap_to_beat)
		{
		highest = 1;
		lap_to_beat = num2;
		}

        name = horse_stats[/**/race_horses[2]/**/]["name"];
        speed = horse_stats[/**/race_horses[2]/**/]["speed"];
        accel = horse_stats[race_horses[2]]["accel"];
        health = horse_stats[race_horses[2]]["health"];
		jockey = horse_stats[race_horses[2]]["jockey"];

        num3 = ((accel / lap) + (speed / weather) + (health * lap) + (jockey * danger) +(random(50)) );
			switch(random(3)){
			case(0): tell_room(ETP,"Clarise %^CYAN%^relates%^RESET%^: Blessed by Seija today "+name+"%^RESET%^ is really moving!");
			break;
			case(1): tell_room(ETP,"Clarise %^CYAN%^relates%^RESET%^: "+name+"%^RESET%^ is keeping a solid pace!");
			break;
			case(2): tell_room(ETP,"Clarise %^CYAN%^relates%^RESET%^: "+name+"%^RESET%^ seems to be struggling a little!");
			break;
			}
		score3 = (score3 + num3);
		if (num3 > lap_to_beat)
		{
		highest = 2;
		lap_to_beat = num3;
		}

        name = horse_stats[/**/race_horses[3]/**/]["name"];
        speed = horse_stats[/**/race_horses[3]/**/]["speed"];
        accel = horse_stats[race_horses[3]]["accel"];
        health = horse_stats[race_horses[3]]["health"];
		jockey = horse_stats[race_horses[3]]["jockey"];

        num4 = ((accel / lap) + (speed / weather) + (health * lap) + (jockey * danger) +(random(50)) );
			switch(random(3)){
			case(0): tell_room(ETP,"Clarise %^CYAN%^relates%^RESET%^: Out of the box "+name+"%^RESET%^ has a strong start!");
			break;
			case(1): tell_room(ETP,"Clarise %^CYAN%^relates%^RESET%^: "+name+"%^RESET%^ has already found their pace!");
			break;
			case(2): tell_room(ETP,"Clarise %^CYAN%^relates%^RESET%^: Out of the box "+name+"%^RESET%^ heads for the inside track!");
			break;
			}
		dramatic_pause(0);
		score4 = (score4 + num4);
		if (num4 > lap_to_beat)
		{
		highest = 3;
		lap_to_beat = num4;
		}

		if(danger = 1){
			switch(random(7)){
			    case(0): tell_room(ETP,"Clarise %^CYAN%^relates%^RESET%^: Seems like reports of danger on the track today were unwarrented!");
			    break;
			    case(1): tell_room(ETP,"Clarise %^CYAN%^relates%^RESET%^: Oh no! "+name+"%^RESET%^ stumbles into the wall as the course is attacked!");
			    break;
			    case(2): tell_room(ETP,"Clarise %^CYAN%^relates%^RESET%^: Several horses are injured as soldiers rush the track to dispatch monsters!");
			    break;
				case 3..6:
				break;
			}
		}

		    name = horse_stats[/**/race_horses[highest]/**/]["name"];
		    tell_room(ETP,"Clarise %^CYAN%^relates%^RESET%^: And out front of the pack leading by a nose, "+name+" %^RESET%^won the lap!");
			dramatic_pause(0);
		}

		highest = 0;
		score_to_beat = score;
		if (score2 > score_to_beat)
		{
		highest = 1;
		score_to_beat = score2;
		}
		if (score3 > score_to_beat)
		{
		highest = 2;
		score_to_beat = score3;
		}
		if (score4 > score_to_beat)
		{
		highest = 3;
		score_to_beat = score4;
		}
	name = horse_stats[/**/race_horses[highest]/**/]["name"];
	uid = horse_stats[/**/race_horses[highest]/**/]["UID"];
	old_winning = horse_stats[/**/race_horses[highest]/**/]["winnings"];
	switch(highest) {
	    case 0:
	        winner_edge = edge1;
		break;
		case 1:
		    winner_edge = edge2;
		break;
		case 2:
		    winner_edge = edge3;
		break;
		case 3:
		    winner_edge = edge4;
		break;
	}
    tell_room(ETP,"Clarise %^CYAN%^relates%^RESET%^: And crossing the line.... "+name+" %^RESET%^has won the race!\n");
	dramatic_pause(0);
	num = horse_stats[/**/race_horses[0]/**/]["loss"];
	num = (num+1);
	num2 = horse_stats[/**/race_horses[1]/**/]["loss"];
	num2 = (num2+1);
	num3 = horse_stats[/**/race_horses[2]/**/]["loss"];
	num3 = (num3+1);
	num4 = horse_stats[/**/race_horses[3]/**/]["loss"];
	num4 = (num4+1);
	score = horse_stats[/**/race_horses[0]/**/]["UID"];
	score2 = horse_stats[/**/race_horses[1]/**/]["UID"];
	score3 = horse_stats[/**/race_horses[2]/**/]["UID"];
	score4 = horse_stats[/**/race_horses[3]/**/]["UID"];
		horse_stats[score]["loss"] = num;
		horse_stats[score2]["loss"] = num2;
		horse_stats[score3]["loss"] = num3;
	    horse_stats[score4]["loss"] = num4;

	win = horse_stats[/**/race_horses[highest]/**/]["win"];
	yay_loss = horse_stats[/**/race_horses[highest]/**/]["loss"];
	yay_loss = (yay_loss-1);
	win = (win+1);
	horse_stats[uid]["win"] = win;
    horse_stats[uid]["loss"] = yay_loss;
	horse_stats[uid]["winnings"] = old_winning + purse;
    current_winner = uid;

	SAVE();
	return;

    }

void show_all_horses()
{
    string *temp=({});
	int i;
	string name,owner;
	int win, loss, winnings, uid;
    temp = keys(horse_stats);
write("You are looking at all of the horses on the books...");
write ("%^RED%^%^BOLD%^Number   Horse Name             Owner's Name              WIN / LOSS ");
write ("--------------------------------------------------------------------------");
    i = 0;
	for (i=0;i<sizeof(temp);i++)
	{
	name = horse_stats[/**/temp[i]/**/]["name"];
    name = arrange_string(name, 14);
    uid = horse_stats[/**/temp[i]/**/]["UID"];
	owner = horse_stats[/**/temp[i]/**/]["owner"];
    owner = arrange_string(owner, 20);
	win = horse_stats[/**/temp[i]/**/]["win"];
	loss = horse_stats[/**/temp[i]/**/]["loss"];
	winnings = horse_stats[/**/temp[i]/**/]["winnings"];
    check_if_dead = horse_stats[/**/temp[i]/**/]["name"];
	if(check_if_dead != "dead"){
	write(" "+uid+"\t "+name+"\t\t"+owner+"\t   "+win+"/"+loss+"");
	}
	}
}

void show_one_horse(string str)
{

string *temp=({});
string name,owner,app_speed, app_health, app_accel, app_jockey, app_stable, app_blurb1, app_blurb2, real_owner;
int win, loss, winnings, uid, aa, blurb1, blurb2, stable, speed, health, accel, jockey, invested;
temp = keys(horse_stats);

    aa = sizeof(temp);

    if(!sscanf(str,"%d",uid)) return notify_fail("Try research #.");

	if (aa < uid || uid == 0){
    write("%^ORANGE%^You flip through the book of horses, but it looks "+
	"like that horse doesn't exist. Perhaps you should look at the list "+
	"of all the horses on file and check to make sure that number is a valid one.\n");
	return 0;
    }

	check_if_dead = horse_stats[uid]["name"];
	if(check_if_dead == "dead"){
	    tell_object(TP, "%^RESET%^%^RED%^You flip through the book but find "+
		"this horse's number has the information removed. Perhaps some accident "+
		"befell the horse and it is dead?\n\n%^RESET%^");
	return;
	}



	if (aa >= uid){

    write("Horse "+uid+" ...");
    name = horse_stats[uid]["name"];
	owner = horse_stats[uid]["owner"];
	real_owner = horse_stats[uid]["real_owner"];
	win = horse_stats[uid]["win"];
	loss = horse_stats[uid]["loss"];
	winnings = horse_stats[uid]["winnings"];
	speed = horse_stats[uid]["speed"];
	accel = horse_stats[uid]["accel"];
	jockey = horse_stats[uid]["jockey"];
	blurb1 = horse_stats[uid]["blurb1"];
	blurb2 = horse_stats[uid]["blurb2"];
	stable = horse_stats[uid]["stable"];
    invested = horse_stats[uid]["invested"];

	if (accel < 10 || accel == 10){app_accel = "a horse that takes an extremely long time to get up to speed"; }
	if (accel > 10 && accel < 20 || accel == 20){app_accel = "a slow starter"; }
	if (accel > 20 && accel < 40 || accel == 40){app_accel = "a horse that is relatively quick out of the gate"; }
	if (accel > 40 && accel < 60 || accel == 60){app_accel = "a horse well trained to gain speed";}
	if (accel > 60 && accel < 85 || accel == 80){app_accel = "a horse gifted with incredible ability to gain speed"; }
	if (accel > 85 && accel < 100){app_accel = "a horse that launches like an arrow out of the gate"; }
	if (accel == 100){app_accel = "a horse with an unearthly ability to launch ahead of the pack";	 }

	if (speed < 10 || speed == 10){app_speed = "a stunningly slow runner"; }
	if (speed > 10 && speed < 20 || speed == 20){app_speed = "a slow runner"; }
	if (speed > 20 && speed < 40 || speed == 40){app_speed = "a good pace that keeps up with the pack"; }
	if (speed > 40 && speed < 60 || speed == 60){app_speed = "a well trained pace horse with great speed";}
	if (speed > 60 && speed < 85 || speed == 80){app_speed = "a long running fast steed"; }
	if (speed > 85 && speed < 100){app_speed = "a blindingly fast runner"; }
	if (speed == 100){app_speed = "a speed that must be the work of gods";	 }

	if (jockey < 10 || jockey == 10){app_jockey = "a completely untrained"; }
	if (jockey > 10 && jockey < 20 || jockey == 20){app_jockey = "a novice"; }
	if (jockey > 20 && jockey < 40 || jockey == 40){app_jockey = "a journeyman"; }
	if (jockey > 40 && jockey < 60 || jockey == 60){app_jockey = "a veteren";}
	if (jockey > 60 && jockey < 85 || jockey == 80){app_jockey = "a master"; }
	if (jockey > 85 && jockey < 100){app_jockey = "a more then masterful"; }
	if (jockey == 100){app_jockey = "a godly";	 }

    if (stable == 1){app_stable = "%^CYAN%^Antioch Royal Stables"; }
    if (stable == 2){app_stable = "%^YELLOW%^Azha Outpost Stables"; }
    if (stable == 3){app_stable = "%^RESET%^%^BOLD%^Seneca Stables and Aviary"; }
    if (stable == 4){app_stable = "%^MAGENTA%^Shadow Stables"; }

	if (blurb1 == 1){app_blurb1 = "The horse is known for its fear of animals."; }
	if (blurb1 == 2){app_blurb1 = "The horse was born under a full moon."; }
	if (blurb1 == 3){app_blurb1 = "Several times this horse has refused the gate."; }
	if (blurb1 == 4){app_blurb1 = "They come from a very proud line of race horses."; }
	if (blurb1 == 5){app_blurb1 = "The horse's coloring is considered unique."; }
	if (blurb1 == 6){app_blurb1 = "They refuse to practice before a race."; }
	if (blurb1 == 7){app_blurb1 = "The horse is known for its fear of armed soldiers."; }
	if (blurb1 == 8){app_blurb1 = "The horse refuses jockeys of half-blood."; }
	if (blurb1 == 9){app_blurb1 = "Strangely, they only accept half-blood jockeys."; }

	if (blurb2 == 1){app_blurb2 = "Training such a horse is always expensive."; }
	if (blurb2 == 2){app_blurb2 = "Some consider if all the gold spent on this horse is a wise investment."; }
	if (blurb2 == 3){app_blurb2 = "The trainer for this horse is a master, but has a secret past."; }
	if (blurb2 == 4){app_blurb2 = "This horse is only happy when training."; }
	if (blurb2 == 5){app_blurb2 = "The horse requires special shoes that most say are enchanted."; }
	if (blurb2 == 6){app_blurb2 = "They are known for a love of long races."; }
	if (blurb2 == 7){app_blurb2 = "There were omens and portents when this horse was born."; }
	if (blurb2 == 8){app_blurb2 = "This horse is strangely afraid of priests and clerics."; }
	if (blurb2 == 9){app_blurb2 = "This horse favors shorter races in hot climates."; }


    write("%^ORANGE%^You flip through the records of one horse.%^RESET%^\n");
    write("%^RESET%^%^RED%^ ----------------------------------------------------------------------- %^RESET%^");
	write("%^RESET%^%^ORANGE%^Number \t\t%^RESET%^%^BOLD%^"+uid+"\n%^RESET%^%^ORANGE%^"+
	"Horse Name\t%^RESET%^%^BOLD%^"+name+"\n%^RESET%^%^ORANGE%^Owner's Name\t"+
	"%^RESET%^%^BOLD%^%^"+owner+"\n%^RESET%^%^ORANGE%^Record\t\t%^RESET%^%^BOLD%^"+win+"/"+loss+" \n");

	write("%^RESET%^%^ORANGE%^According to records "+name+"%^RESET%^%^ORANGE%^ "+
	"was sired in the "+app_stable+"%^RESET%^%^ORANGE%^ and was purchased "+
	"by "+owner+"%^RESET%^%^ORANGE%^. "+app_blurb1+" %^RESET%^%^ORANGE%^While great "+
	"expense has been placed into the horse, it is notable that its training has "+
	"produced "+app_speed+"%^RESET%^%^ORANGE%^, "+app_accel+"%^RESET%^%^ORANGE%^"+
	", and "+app_jockey+" %^RESET%^%^ORANGE%^jockey has been hired."+
    " "+app_blurb2+"%^RESET%^%^ORANGE%^\n\nRecords show "+
	"that they have won races totalling "+winnings+"%^RESET%^%^ORANGE%^ gold. ");
	    if(avatarp(TP))
    {
        tell_object(TP,"%^CYAN%^%^BOLD%^\nAs an immortal you can see that the real "+
		"owner of this horse is %^RESET%^%^BOLD%^"+real_owner+" %^CYAN%^%^BOLD%^and "+
		"they have invested "+invested+" gold in its training. ");
    }


    return;
	}

    write("%^ORANGE%^You flip through the book of horses, but it looks "+
	"like that horse doesn't exist. Perhaps you should look at the list "+
	"of all the horses on file and check to make sure that number is a valid one.\n");
	return 0;

	}

void show_current_race()
{

    string *temp=({});
	int i;
    string common_weather, common_course, common_danger;
	string odds1, odds2, odds3, odds4;
	string name1, name2, name3, name4;
	int uid1, uid2, uid3, uid4, totaledge;

	edge1 = ((horse_stats[/**/race_horses[0]/**/]["win"]*4) - (horse_stats[/**/race_horses[0]/**/]["loss"]) + (horse_stats[/**/race_horses[0]/**/]["total_skills"]));
	edge2 = ((horse_stats[/**/race_horses[1]/**/]["win"]*4) - (horse_stats[/**/race_horses[1]/**/]["loss"]) + (horse_stats[/**/race_horses[1]/**/]["total_skills"]));
	edge3 = ((horse_stats[/**/race_horses[2]/**/]["win"]*4) - (horse_stats[/**/race_horses[2]/**/]["loss"]) + (horse_stats[/**/race_horses[2]/**/]["total_skills"]));
	edge4 = ((horse_stats[/**/race_horses[3]/**/]["win"]*4) - (horse_stats[/**/race_horses[3]/**/]["loss"]) + (horse_stats[/**/race_horses[3]/**/]["total_skills"]));

	totaledge = ((edge1 + edge2 + edge3 + edge4) / 4);

	edge1 = (totaledge - edge1);
	edge2 = (totaledge - edge2);
	edge3 = (totaledge - edge3);
	edge4 = (totaledge - edge4);

	odds1 = "blah";

    if (edge1 < -50){odds1 = ("1:5");}
	if ((edge1 > -49) && (edge1 < -40)){odds1 = ("1:6");}
	if ((edge1 > -39) && (edge1 < -30)){odds1 = ("1:5");}
	if ((edge1 > -29) && (edge1 < -20)){odds1 = ("1:4");}
	if ((edge1 > -19) && (edge1 < -10)){odds1 = ("1:3");}
	if ((edge1 > -9) && (edge1 < -0)){odds1 = ("1:2");}
    if (edge1 == 0){odds1 = ("1:1");}
	if ((edge1 > 0) && (edge1 < 5)){odds1 = ("2:1");}
	if ((edge1 > 4) && (edge1 < 10)){odds1 = ("3:1");}
	if ((edge1 > 9) && (edge1 < 15)){odds1 = ("4:1");}
	if ((edge1 > 14) && (edge1 < 20)){odds1 = ("5:1");}
	if ((edge1 > 19) && (edge1 < 30)){odds1 = ("6:1");}
	if ((edge1 > 29) && (edge1 < 40)){odds1 = ("7:1");}
    if (edge1 > 49){odds1 = ("8:1");}

    if (edge2 < -50){odds2 = ("1:5");}
	if ((edge2 > -49) && (edge2 < -40)){odds2 = ("1:6");}
	if ((edge2 > -39) && (edge2 < -30)){odds2 = ("1:5");}
	if ((edge2 > -29) && (edge2 < -20)){odds2 = ("1:4");}
	if ((edge2 > -19) && (edge2 < -10)){odds2 = ("1:3");}
	if ((edge2 > -9) && (edge2 < -0)){odds2 = ("1:2");}
    if (edge2 == 0){odds2 = ("1:1");}
	if ((edge2 > 0) && (edge2 < 5)){odds2 = ("2:1");}
	if ((edge2 > 4) && (edge2 < 10)){odds2 = ("3:1");}
	if ((edge2 > 9) && (edge2 < 15)){odds2 = ("4:1");}
	if ((edge2 > 14) && (edge2 < 20)){odds2 = ("5:1");}
	if ((edge2 > 19) && (edge2 < 30)){odds2 = ("6:1");}
	if ((edge2 > 29) && (edge2 < 40)){odds2 = ("7:1");}
    if (edge2 > 49){odds2 = ("8:1");}

    if (edge3 < -50){odds1 = ("1:5");}
	if ((edge3 > -49) && (edge3 < -40)){odds3 = ("1:6");}
	if ((edge3 > -39) && (edge3 < -30)){odds3 = ("1:5");}
	if ((edge3 > -29) && (edge3 < -20)){odds3 = ("1:4");}
	if ((edge3 > -19) && (edge3 < -10)){odds3 = ("1:3");}
	if ((edge3 > -9) && (edge3 < -0)){odds3 = ("1:2");}
    if (edge3 == 0){odds3 = ("1:1");}
	if ((edge3 > 0) && (edge3 < 5)){odds3 = ("2:1");}
	if ((edge3 > 4) && (edge3 < 10)){odds3 = ("3:1");}
	if ((edge3 > 9) && (edge3 < 15)){odds3 = ("4:1");}
	if ((edge3 > 14) && (edge3 < 20)){odds3 = ("5:1");}
	if ((edge3 > 19) && (edge3 < 30)){odds3 = ("6:1");}
	if ((edge3 > 29) && (edge3 < 40)){odds3 = ("7:1");}
    if (edge3 > 49){odds3 = ("8:1");}

    if (edge4 < -50){odds1 = ("1:5");}
	if ((edge4 > -49) && (edge4 < -40)){odds4 = ("1:6");}
	if ((edge4 > -39) && (edge4 < -30)){odds4 = ("1:5");}
	if ((edge4 > -29) && (edge4 < -20)){odds4 = ("1:4");}
	if ((edge4 > -19) && (edge4 < -10)){odds4 = ("1:3");}
	if ((edge4 > -9) && (edge4 < -0)){odds4 = ("1:2");}
    if (edge4 == 0){odds4 = ("1:1");}
	if ((edge4 > 0) && (edge4 < 5)){odds4 = ("2:1");}
	if ((edge4 > 4) && (edge4 < 10)){odds4 = ("3:1");}
	if ((edge4 > 9) && (edge4 < 15)){odds4 = ("4:1");}
	if ((edge4 > 14) && (edge4 < 20)){odds4 = ("5:1");}
	if ((edge4 > 19) && (edge4 < 30)){odds4 = ("6:1");}
	if ((edge4 > 29) && (edge4 < 40)){odds4 = ("7:1");}
    if (edge4 > 49){odds4 = ("8:1");}

    name1 = horse_stats[/**/race_horses[0]/**/]["name"];
	name2 = horse_stats[/**/race_horses[1]/**/]["name"];
    name3 = horse_stats[/**/race_horses[2]/**/]["name"];
    name4 = horse_stats[/**/race_horses[3]/**/]["name"];

	uid1 = horse_stats[/**/race_horses[0]/**/]["UID"];
	uid2 = horse_stats[/**/race_horses[1]/**/]["UID"];
    uid3 = horse_stats[/**/race_horses[2]/**/]["UID"];
    uid4 = horse_stats[/**/race_horses[3]/**/]["UID"];

	if (location == 1){common_course = ("Al'tari kada Races");}
    if (location == 2){common_course = ("Tharis underground");}
	if (location == 3){common_course = ("Northern star");}
	if (location == 4){common_course = ("Royal Asgard Yards");}

	if (weather == 1){common_weather = ("clear");}
	if (weather == 2){common_weather = ("foggy");}
	if (weather == 3){common_weather = ("storming");}

	if (danger == 0 && location == 1){common_danger = ("the course appears clear");}
	if (danger == 1 && location == 1){common_danger = ("there are reports of bandits near the course");}

	if (danger == 0 && location == 2){common_danger = ("the course appears safe");}
	if (danger == 1 && location == 2){common_danger = ("there have been reports of escaped rats and gelatinous cubes near the course");}

	if (danger == 0 && location == 3){common_danger = ("guards are patrolling the course");}
	if (danger == 1 && location == 3){common_danger = ("several undead were dispatched near the course");}

	if (danger == 0 && location == 4){common_danger = ("commandos have the course secured");}
	if (danger == 1 && location == 4){common_danger = ("It is rumroed Sysquatch raiders might be in the area");}

	write("%^ORANGE%^You look over the board on the wall that has the details of the race about to be run. You "+
	"can '%^BOLD%^place'%^RESET%^%^ORANGE%^ your bet once you decide if there is a horse here that looks lucky, "+
	"or %^BOLD%^'research'%^RESET%^%^ORANGE%^ a horse to learn more about them.\n%^RESET%^\n");
    write("%^RESET%^%^RED%^ ----------------------------------------------------------------------- %^RESET%^");
	write("%^RESET%^%^CYAN%^The next race will be run at the %^BOLD%^"+common_course+"%^RESET%^%^CYAN%^ "+
	"and has been planned for %^BOLD%^"+length+" laps%^RESET%^%^CYAN%^. "+
	"While the course is clear now, it is expected that the weather may be %^BOLD%^"+common_weather+" "+
	"%^RESET%^%^CYAN%^and %^BOLD%^"+common_danger+"%^RESET%^%^CYAN%^"+
	". The purse for the winning horse is %^YELLOW%^"+purse+"%^RESET%^%^CYAN%^. The following horses are running the race.\n");
	write("%^YELLOW%^#        Horse Name      Odds%^RESET%^\n");
    write(""+uid1+"\t "+name1+"\t "+odds1+" ");
	write(""+uid2+"\t "+name2+"\t "+odds2+" ");
	write(""+uid3+"\t "+name3+"\t "+odds3+" ");
	write(""+uid4+"\t "+name4+"\t "+odds4+" \n");
    return;
}

void dramatic_pause(int num)
{
    switch(num){
	    case(0):
		tell_room(ETP,"%^RESET%^%^MAGENTA%^%^RESET%^");
		break;
		case(1):
		break;
		return;
	}
    num++;
	call_out("dramatic_pause",2,num);
	return;
}

void SAVE()
{
	save_object(SAVE_FILE);
    return;
}

int return_winner()
{
return current_winner;
}

int return_edge()
{
return winner_edge;
}
