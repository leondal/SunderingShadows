#include <std.h>
inherit MONSTER;

void create(){
    ::create();

    set_level(25);
    set_name("parrot");
    set_short("Salieka's %^MAGENTA%^BOLD%^c%^RESET%^%^BOLD%^WHITE%^o%^BLUE%^l%^WHITE%^o%^MAGENTA%^u%^CYAN%^r%^BLUE%^f%^MAGENTA%^u%^WHITE%^l%^RESET%^ parrot");
    set_id( ({"parrot", "bird", "a bird", "a parrot"}) );
    set_long("This is a colourful parrot that belongs to Salieka. It sits on its perch watching the comings and goings here. Some patrons think she is a pest, albeit cute as hell.");
    set_race("bird");
    set_gender("female");
    set_body_type("foul");
    set_class("fighter");
    set_alignment(8);
}

void catch_tell(string str){
    string who,what;
    if(sscanf(str, "%s says%%^RESET%%^:", who, what) !=2)
	return;

    call_out("repeat",2,what);
}
void repeat(string what){
    if(!this_object()) return;
    if(!environment()){
	destruct(this_object());
	return;
    }

    message("say",
      "The Parrot says: "+what,
      environment(),
      ({this_object()}) );
}

void someone_left(object whom,string who,string where){
    if(interactive(whom) && random(2))
	command(where);
}

