// An acorn for SG -- Thorn 2/2

#include <std.h>

inherit "/std/food.c";

int exit_stat, add, count_points;
string *exit_name, *exit_path;

void create() {
	::create();
	set_name("acorn");
	set_id( ({ "acorn", "food" }) );
	set_short("An acorn");
	set_long("Type <go>.\n");
	set_weight(1);
}

init() {
	::init();
	add_action("go", "go");
}

void go() {
	notify_fail("Please input value\n");
	input_to("PP2");
}

void PP2(string str){
	int temp;
	int temp2, x;
	string tmp;

	if(!str) {
		input_to("PP2");
		return;
	}
	add = 0;
	write("["+str+"]");
	write(">> "+sizeof(str));
	for(x=0;x<strlen(str);x++) {
		temp2 = to_int(str[x]) - 48;
		if(temp2 == 0) add = add * 10;
		else add = temp2 + (add * to_int(pow(to_float(10), to_float(x))));
	}
	write(""+add);
	  if(add > 15){
			write("please input again -- under 15");
			input_to("PP2");
		}
		else{
			temp=TP->query_thief_skill("pick pockets");
			temp+=add;
			count_points+=add;
			if(temp > 95) temp = 95;
			TP->set_thief_skill("pick pocket",temp);
			write("> "+str);
			write("-> "+temp2);
			write("--> "+add);
		}
	}
