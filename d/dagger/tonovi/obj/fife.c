#include <std.h>
inherit OBJECT;

mapping aggressive;
object  *monsters;

void init(){
    ::init();
    add_action("charm", "charm");
}

void create(){
    ::create();
    set_name("Bard's fife");
    set_id( ({"fife", "brass fife", "instrument"}) );
    set_short("Brass Fife");
    set_long(
      "This small brass fife is made by the master musicians of the bards.  It is said that such instruments have the power to enhance a bard's voice,  This fife is said to be able to charm the savage beast."
    );
    set_value(500);
    set_weight(4);
}

int charm(string str){

    string what;
    int save, roll;
    object *inven,*living_items;
    int i,j,who, align;
    string file;


    inven = ({});
    living_items = ({});
    monsters = ({});
    aggressive = ([]);


    if(!TP->is_class("bard")) {
	tell_object(TP, "You must be a bard to use this fife.");
	return 1;
    }

    if(!str) return 0;
    align = TP->query_alignment();
    if(align==1 || align==3 || align==7 || align==9){
	notify_fail("You cannot use your bard skills unless you are of a neutral alignment!\n");
	return 0;
    }

    if(sscanf(str, "with %s",what)!= 1){
	notify_fail("Usage : charm with fife\n\n");
	return 0;
    }

    if(what != "fife"){
	notify_fail("You need to use the fife.\n");
	return 0;
    }

    tell_room(ETP, TPQCN+" plays a beautiful song on the fife", TP);
    tell_object(TP, "You play a beautiful song on the fife.");


    inven = all_inventory(environment(TP));
    if(!inven) {
	notify_fail("You really should try doing that to someone.\n");
	return 0;
    }
    i = sizeof(inven);

    while(i--)
	if(living(inven[i]) == 1)
	  living_items+= ({ inven[i] });

	  if(!living_items) {
	      notify_fail("Those rocks aren't listening.\n");
	      return 0;
	  }
	  j = sizeof(living_items);
	  while(j--){
	      file = file_name(living_items[j]);
		if(file[0..8] != "/std/user"){
		    monsters += ({living_items[j]});
		}

	    }

	      for(i=0;i<sizeof(monsters);i++) {
		  save = "daemon/saving_d"->return_throw("paralyzation_poison_death",(string)monsters[i]->query_class(),(int)monsters[i]->query_level());
		  save = save + (((int)TP->query_level())/3);
save += 3;
		  roll = random(19)+1;
		  if(roll < save){
		      monsters[i]->set_charmed(1);
		      aggressive[monsters[i]]= monsters[i]->query("aggressive");
		      monsters[i]->set("aggressive",3);
		  }
		  else {
		      monsters[i]->set_charmed(-1);
		      aggressive[monsters[i]]= monsters[i]->query("aggressive");
		      monsters[i]->set("aggressive",20);
		  }
	      }


	      call_out("return_agg",20);
	      return 1;
	  }


	  void return_agg(){

	      int i;

	      for(i=0;i<sizeof(monsters);i++){
		  monsters[i]->set("aggressive",aggressive[monsters[i]]);
		}
	      }

int is_instrument(){return 1;}