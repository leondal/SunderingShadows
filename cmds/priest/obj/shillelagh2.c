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
   set_size(3);
   set("value", 0);
   set_wc(2,4);
   set_large_wc(1,4);
   set_type("magebludgeon");
   set_property("enchantment",1);
}
init(){
    ::init();
	if(TP != owner){ 
	    TO->remove();
	    return;
	}
add_action("quit","quit");
	old->remove();
	call_out("done",duration,old);
}
void set_obj(object str) {old = str;}
void set_owner(object ob){ owner = ob; }
void set_duration(int dur) { duration = dur; }
  void done(object ob){
   string name;
   int hold;

   sscanf(file_name(ob),"%s#%d",name,hold);
old = new(name);
	destruct(this_object());	// altered by Pator 11/9/'95
  old->move(TP);
	owner->force_me("wield staff");
}
int quit(){
		done(old);
return 0;
}
