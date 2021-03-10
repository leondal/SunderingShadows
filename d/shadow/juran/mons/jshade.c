#include <std.h>

inherit NPC;

void create(){
   	::create();

   	set_name("Shade Caretaker");
   	set_short("Shade Caretaker");
   	set_id(({"monster","shade","caretaker","shade caretaker"}));
   	set_long("The shade stands before you and shimmers as the shadows "+
   		"caress and clothe him.  His form is indistinct and humanoid "+
   		"at the same time and you can see eyes that glow deep red like "+
   		"coals in the fire."
   	);
   	set_race("shade");
   	set_body_type("humanoid");
   	set_class("cleric");
   	set_hd(50,1);
   	set_hp(1000);
   	set_spells(({"flame strike","cause blindness","hold person","kiss of torment"}));
   	set_spell_chance(90);
   	set_diety("loviatar");
   	new("/d/shadow/obj/armor/robe")->move(TO);
   	command("wear robe");
   	set_unique(1);
     	set_alignment(3);
    	remove_std_db();
    	set_gender("male");
    	command("speech %^BOLD%^%^BLUE%^whisper %^MAGENTA%^hauntingly%^RESET%^");
    	set_spoken("wizish");

}
init(){
   	::init();
   	if (TP->query_ghost()) call_out("whisper_dead",1,TP);
}
void whisper_dead(object who){
   	command("whisper "+who->query_name()+" %^YELLOW%^Pray %^RESET%^ or %^YELLOW%^return%^RESET%^ to get a new body, "
"and stop your incessant wailing!");
}
