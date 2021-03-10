//updated by Circe 12/29/04
#include <std.h>
inherit OBJECT;
void init(){
	::init();
	add_action("wear_per","wear");
}

int count;

void create(){
	::create();
	set_name("perfume");
	set_id(({"perfume","bottle of perfume","tharis perfume"}));
	set_short("a bottle of perfume");
	set_long("This is a bottle of finely scented perfume.  A "+
         "light fragrance of roses rises from the sculpted bottle.");
	set_value(5);
	set_weight(1);
}

int wear_per(string str){
string long;
	if(strsrch(str,"perfume")==-1)
		return 0;
	else {
if(count!=5){
count+=1; 
		write("You wear the perfume");
		tell_room(environment(TP),TPQCN+" wears some perfume.",TP);
long = TP->query_long();
TP->set("long",capitalize(nominative(TP))+" is wearing a wonderful fragrance");
		return 1;
 		}
else {
write("The bottle is empty.");
return 1;
        }
	}
}
