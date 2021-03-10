// Inheritable for pepitom
#include <std.h>
inherit ROOM;
mapping monster;

int check_mons();

void create(){
	::create();
	check_mons();



}

int check_mons(){
	object ob;
	if(!ob=find_object_or_load("/d/shadow/room/pepitom/stella.c")){
		write("FAILED");
}
			write("SUCCEEDED");
write (file_name(ob));

}


