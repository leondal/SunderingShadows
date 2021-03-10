#include <std.h>
#include <daemons.h>

inherit "/std/fence";
//inherit "/std/vendor";

string *killers;

void create() {
   ::create();
   killers = ({});
   set_name("nicoli");
   set_id( ({ "nicoli","Nicoli","shopkeeper"}) );
   set_short("Nicoli, the Daggerdale guild's shopkeeper");
   set("aggressive", 0);
   set_level(19);
   set_long(
@STYX
His dark heritage is apparent through the dusky grey skin of his face, the only exposed part of his body.  Every other inch of his form is well concealed in black leather.  His eyes glow a sickly red color and although you doubt he cares about you or anyone, he seems to be content enough to do his job.
STYX
	);
   set_gender("male");
   set_alignment(6);
   set_class("thief");
   set("race", "half-drow");
   add_money("gold", random(500));
   set_body_type("human");
   //set_storage_room("/d/dagger/Daggerdale/shops/DDguild_storage");
   set_property("no bump", 1);
   set_hd(19,3);
   remove_random_act_dbs( ({ "/d/db/armorsrandom" }) );
   remove_std_db();
   set_exp(10);
}

/*
int should_interact(object ob) { 
//	if(TP->avatarp()) return 1;
	if( (!TP->is_class("thief")) || (!TP->is_class("bard")) ) return notify_fail("I'm sorry, but I can only sell to thieves or assassins.");
	return 1;
}
*/

void init(){
   ::init();
   //What is this doing here?? - Saide
   //add_action("buy_func","buy");
}

/*int buy_func(string str){
   if(!TP->is_class("thief") && !TP->is_class("bard") && !TP->avatarp()) { 
     tell_room(ETO, TPQCN+" seems to be trying to make a deal with Nicoli.", TP);
     tell_room(ETO, "%^MAGENTA%^Nicoli says:%^RESET%^ I'm sorry, but I can only deal with roguish types.");
   return 1;
   }
   return 0;
}*/

int kill_ob(object victim, int which){
    int hold;
    killers = SAVE_D->query_array("DDguild_killers");
    hold = ::kill_ob(victim, which);
    if(member_array(TPQN, killers) != -1) return hold;
    SAVE_D->set_value("DDguild_killers", TPQN);
    environment(TO)->remove_member(TPQN);
    return hold;
}
