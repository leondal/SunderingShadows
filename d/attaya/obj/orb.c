#include <std.h>
inherit OBJECT;
   object ob;

void create() {
    ::create();
    set_name("orb of dispelling");
    set_id(({"orb","orb of dispelling"}));
    set_short("%^BOLD%^%^WHITE%^Orb of Dispelling%^RESET%^");
      set_obvious_short("%^BOLD%^%^BLACK%^tiny black orb%^RESET%^");
    set_long("This is a tiny little black orb. It is made of some"+
             " sort of volcanic rock. While solid, it looks fragile"+
             " enough to crush."
);
    set_weight(1);
    set_heart_beat(1);
}

void init() {
    ::init();
    add_action("break_func","crush");
}
 
int break_func(string str) {
    if( !str || str != "orb") {
        notify_fail ("crush what?\n");
        return 0;
    }
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }
   if(TP->query_paralyzed())
           return notify_fail(TP->query_paralyze_message()+"\n");
    message ( "my_action",
        "You crush the tiny orb in your hand! "
    ,TP);
    message ( "other_action",
        ""+TPQCN+" seemingly tightens an already closed hand. "
    ,environment(TP),TP);
   ob=new("/cmds/spells/d/_dispel_magic");
   ob->set_silent_casting(1);
   ob->set_cast_string("");
   ob->use_spell(ETO, 0,(ETO->query_lowest_level()), 100, "mage");
    TO->remove();
    return 1;
}

void heart_beat(){
   object ob;
   if((ob=present("orb of dispelling",ETO))&&living(ETO)&&ob!=TO){
      tell_object(ETO,"The orbs shake and then explode!");
      ETO->do_damage("torso",roll_dice(3,10));
      ETO->add_attacker(TO);
      ETO->continue_attack();
      ob->remove();
      TO->remove();
   } 

}