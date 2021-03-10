#include <std.h>

inherit "/std/weapon";
object old;
object owner;
int duration;

create() {
    ::create();
   set_id(({ "staff", "quarter", "quarter staff", "shillelagh" }));
   set_name("shillelagh");
   set_short("A magically enhanced quarter staff");
   set_long(
	"This is a fine looking quarter staff. \n"
	"It has been magically enhanced using the shillelagh spell."
   );
   set_weight(4);
   set_size(1);
   set("value", 0);
   set_type("magebludgeon");
   set_property("enchantment",1);
}
init(){
    ::init();
	if(TP != owner){ 
	    TO->remove();
	    return;
	}
    add_action("quit_setup","quit");
	call_out("done",duration,old);
}
void set_object(object ob){ old = ob; }
void set_owner(object ob){ owner = ob; }
void set_duration(int dur) { duration = dur; }
void done(object ob){

	message("shillelagh","The magic has dispelled from your staff!",TP);
    if(objectp(ob))
	ob->move(TP);
	TO->remove();
	TP->force_me("wield staff");
	destruct(TO);
}

int quit_setup()
{
    reset();
    return 0;
}
