 
#include "/d/shadow/mon/melnmarn.h";
#include <daemons.h>
inherit MONSTER;
void init(){
::init();
add_action("stab_func", "stab");
add_action("cast_func", "cast");
add_action("throw_func", "throw");
}
void create() {
    ::create();
set_name("herald");
set_id( ({"herald"}) );
set("race", "elf");
set_gender("female");
set_short("herald");
set_long("%^RED%^The herald stands at the vast doors to the throne room, erect and stiff.  She waits to announce whom will meet with the King and Queen, but she also is armed and poised to protect when she must.  She is heart-stoppingly beautiful, her skin golden in the candlelight and her eyelashes so long they touch her cheeks.  Her sword rests in a scabbard, hung from her waist.%^RESET%^");
	set_level(25);

	set_body_type("human");
        set_class("fighter");
        set("aggressive", 0);
        set_alignment(3);
        set_size(2);
set_stats("intelligence", 15);
set_stats("wisdom", 17);
set_stats("strength", 20);
set_stats("charisma", 20);
set_stats("dexterity", 20);
set_stats("constitution", 18);
	set_max_mp(query_hd());
        set_mp(query_max_mp());
set_hd(25,1);
set_hp(175);
set_exp(5000);
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
        set_wielding_limbs( ({ "right hand", "left hand" }) );
new("/d/shadow/obj/weapon/longsword")->move(this_object());
command("wield longsword in left hand");
new("/d/dagger/Elvanta/forest/items/armor/mithril")->move(this_object());
        command("wear armor");
new("/d/dagger/Elvanta/forest/items/armor/helm")->move(this_object());
command("wear helm on head");
add_money("silver",random(250));
add_money("gold",random(500));
} 
void do_stuff(){
	if(interactive(TP)){
	set("aggressive",18);
	call_out("attack",5,TP);
}
}
int stab_func(string str){
	write("%^BOLD%^RED%^The Herald says : You cannot do that!");
	return 1;
}
int cast_func(string str){
	write("%^BOLD%^RED%^The Herald says : Your magic will not function here!");
	return 1;
}
int throw_func(string str){
	write("%^BOLD%^RED%^The Herald stares you down!");
	return 1;
}
