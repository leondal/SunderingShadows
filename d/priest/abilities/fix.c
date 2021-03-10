// Pator@ShadowGate
// Apr 2 1996
// This function 'fixes' a new mistletoe for druids
// It will also 'fix' the amulet when given the chance

#include <std.h>
#include <druids.h>

int fix_it(string str);

int fix_it(string str) {
object spell_obj;
string tmp;
                  // Ok non-druids may fix nothing !
       if (!((string)this_player()->query_class() == "druid"))
	 { tell_object(this_player(),
		       "You can't fix anything here !!\n");
	   return 1; }
                  // If no str we fix nothing !
       if (!str)
	 { notify_fail("You can't fix nothing here !!\n");
	   return 0; }
       switch(str) {
       case "mistletoe" :
	 if (!present("mistletoe",this_player())) {
	    tell_object(TP, "Restoring your mistletoe");  
	   new("/d/priest/mistletoe.c")->move(this_player());
	   this_player()->force_me("save"); }
	 else {
	   tell_object(TP, "Updating your mistletoe");
	   spell_obj = present("mistletoe",this_player());
	   spell_obj->dest_mistletoe();
	   this_player()->force_me("save");
	   new("/d/priest/mistletoe.c")->move(this_player());
	   this_player()->force_me("save"); }
	 tell_room(environment(this_player()),
		   capitalize((string)this_player()->query_true_name())+
		   " gets a Druidic mistletoe !!\n", ({})); 
	 return 1;
	 break;
       case "amulet" :
	 tmp = DRUID_OBJECT_DIR+"d_amulet.c";
	   if (!present("druidic_amulet",this_player())) {
	     new(tmp)->move(this_player());
	     this_player()->force_me("save"); }
	   else {
	     spell_obj = present("druidic_amulet",this_player());
	     this_player()->force_me("remove amulet");
	     spell_obj->dest_amulet();
	     this_player()->force_me("save");
	     new(tmp)->move(this_player());
	     this_player()->force_me("save"); }
	   tell_room(environment(this_player()),
		   capitalize((string)this_player()->query_true_name())+
		   " gets a Druidic amulet !!\n", ({})); 
	 return 1; 
	 break;
       default : tell_object(this_player(),
			     "Please tell something I can fix !!");
	         return 1;
	         break;
       }
	   
}
