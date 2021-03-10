#define SUFFOCATEOB "/d/dagger/suff_ob.c"
#include <std.h>
#include <daemons.h>

inherit CVAULT;

void create() {
  ::create();
  set_property("continue heartbeat", 1);
  set_property("vacuum", 1);
  set_property("used sticks", 1);
  set_property("indoors", 1);
  set_name("Vacuum");
  set_heart_beat(2);
}

void init(){
  ::init();
  add_action("cast", "cast");
  add_action("speak", "say");
}

int speak(string str){
  tell_object(TP, "You open your mouth to speak, but any %^BOLD%^%^CYAN%^"
    +"s%^RESET%^o%^CYAN%^u%^BOLD%^nd%^RESET%^ you make is lost in the"
    +" %^BOLD%^%^BLACK%^vac%^RESET%^%^BLUE%^uu%^BOLD%^%^BLACK%^m");
  tell_room(TO, TPQCN + "%^RESET%^ opens " + TP->QP + " mouth, but any"
    +" %^BOLD%^%^CYAN%^s%^RESET%^o%^CYAN%^u%^BOLD%^nd%^RESET%^" + TP->QS 
    +" makes is lost in the %^BOLD%^%^BLACK%^vac%^RESET%^%^BLUE%^uu"
    +"%^BOLD%^%^BLACK%^m", TP);
  return 1;
}

int cast(string str){
  int casting;
  if ("/daemon/feat_d.c"->usable_feat(TP, "silent spell")||
          present("vacuum_breath_ob", TP)|| 
          TP->query_property("vacuum breather")){
    return 0;
  }
  casting = TP->query_property("has cast");
  if (!casting){
    tell_object(TP, "%^BOLD%^%^CYAN%^You use some of your breath to cast"
      +" the spell");
    TP->set_property("has cast", 1);
    return 0;
  }  
  if (casting == 1){
    tell_object(TP, "%^BOLD%^%^CYAN%^You %^BOLD%^%^WHITE%^gasp %^CYAN%^out"
      +" the %^WHITE%^last %^CYAN%^of your breath to cast the spell!");
    TP->set_property("has cast", 2);
    return 0;
  }  
  if (casting > 1){
    tell_object(TP, "%^BOLD%^%^BLUE%^You have no %^CYAN%^br%^RESET%^e"
      +"%^BOLD%^%^WHITE%^a%^CYAN%^th %^BLUE%^left to cast the spell!");
    return 1;    
  }
}

void freeze(object ob){
  int dam, i;
  if (ob->id("unfettered")) return;
  i = 10 + random (5);
  dam = ob->query_max_hp()/i;
  ob->cause_typed_damage(ob,ob->return_target_limb(),dam,"cold");
  tell_object(ob, "%^BOLD%^%^BLACK%^The %^CYAN%^b%^WHITE%^i%^CYAN%^t"
    +"%^WHITE%^i%^CYAN%^ng %^WHITE%^c%^CYAN%^o%^WHITE%^ld"
    +" %^BOLD%^%^BLACK%^of the %^RESET%^%^BLUE%^vacuum%^BOLD%^%^CYAN%^"
    +" gn%^BLUE%^a%^CYAN%^ws %^BOLD%^%^BLACK%^at your limbs");
  tell_room(TO, ob->QCN + "%^BOLD%^%^CYAN%^ shivers with %^WHITE%^cold"
                                                                     , ob);
}

int is_vacuum(){
  return 1;
}

void heart_beat(){
  object * critters, ob;
  int i, count;
  ::heart_beat();
  critters = all_living(TO);
  count = sizeof(critters);
  if (sizeof(critters)<1 || !is_vacuum()){
    return;
  }
  for (i= 0;i<count;i++){
    if (critters[i]->query_true_invis()) continue;
    freeze(critters[i]);
    if (!present("suff_ob", critters[i])) {
      tell_object(critters[i], "You take a %^BOLD%^%^BLUE%^deep b%^CYAN%^r"
        +"%^WHITE%^e%^CYAN%^a%^BLUE%^th%^RESET%^ before entering the"
        +" %^BLUE%^vac%^BOLD%^%^BLACK%^uu%^RESET%^%^BLUE%^m");
      ob = new(SUFFOCATEOB);
      ob->move(critters[i]);
      ob->start_suffocation();
      if (critters[i]->query_property("has cast")){
        critters[i]->remove_property("has cast");
      }
    }
  }
}


