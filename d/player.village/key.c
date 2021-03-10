#include "pvillage.h"

inherit OBJECT;

string filename,player;

void create() {
    ::create();
    set_id( ({"key"}) );
    set_short("key");
    set_long("key");
    set_weight(0);
    set_value(0);
}

drop(){return 1;}
restore_me(){ ::restore_me();restore_object(KEYS+filename,1); }
save_me(){ save_object(KEYS+filename,1); }

void set_player(string str){
	player = str;
	filename = player+"key";

}
