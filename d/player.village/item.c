#include "pvillage.h"

inherit OBJECT;

void create(){
    ::create();
  	set_name("pvitem");
  	set_id( ({  }) );
  	set_short("");
  	set_long("");
  	set_weight(0);
  	set_value(0);
}
get(str){
	write("Your hand passes right through it.");
	write("Strange, it seems real enough.");
	return 0;

}
void restoreit(string str){
	restore_object(str);
}
void saveit(string str){
	save_object(str,1);
}

