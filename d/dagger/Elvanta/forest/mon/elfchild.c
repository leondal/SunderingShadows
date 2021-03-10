#include <std.h>

inherit MONSTER;

void create(){
	object ob;	
	::create();
	set_name("elf");
	set_race("elf");
set_gender("male");
set_id(({"elf", "elf child", "child", "elven child"}));
set("short", "elf child");
	set("long",
@OLI
This is a small elven child, cute but mischevious.
OLI
	);
	set_hd(8,1);
	set_hp(30);
	set_exp(50);
	set_stats("strength",13);
	set_stats("dexterity",19);
	set_class("fighter");
	set("aggressive",2);
	set_body_type("humanoid");
	set_wielding_limbs(({"right hand","left and"}));
new("/d/dagger/Elvanta/forest/items/wpns/knife")->move(this_object());
command("wield knife in right hand");
}
