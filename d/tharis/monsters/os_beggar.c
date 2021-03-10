// /d/tharis/mon/os_beggar.c   // 

#include <std.h>

inherit MONSTER;

void create() {
    ::create();
        set_name("beggar");
        set_id( ({ "beggar","elf" }) );
        set_race("elf");
        set_gender("male");
        set_short("a beggar");
   set_long("This beggar is making a particular scene.  He is being extremely loud and "
"obnoxious.  His pleas are vehement but the attention he draws from you "
"is of a sympathetic nature.");
      set_level(15);
      enable_commands();
      set_body_type("human");
      set("aggressive",0);
      set_alignment(5);
      set_size(2);
      set_stats("intelligence",18);
      set_stats("wisdom",10);
      set_stats("strength",13);
      set_stats("charisma",13);
      set_stats("dexterity",9);
      set_stats("constitution",10);
      set_max_mp(0);
      set_hd(15, 5);
      set_class("fighter");
      set_max_hp(query_hp());
      new("/d/tharis/obj/bnote.c")->move(TO);
}

void init(){
  ::init();
    add_action("give_stuff","give");
}

void reset(){
  ::reset();
    if(!present("note",TO))
      new("/d/tharis/obj/bnote.c")->move(TO);
}
     
int give_stuff(string str){
  if(strsrch(str, "beggar")!=-1){
    tell_room(ETO,"The beggar looks at you questioningly.");
    tell_room(ETO,"The beggar walks cautiously up to you.");
    tell_room(ETO,"He looks at "+TPQCN+".",TP);
    write("He looks at you and smiles.\n");
    write("You suddenly realize that it is an elf you see before you.\n");
    write("He slips you a piece of paper.\n");
    tell_room(ETO,"You see the beggar slip something to "+TPQCN+".",TP);
// adding this to be sure he has a note to give *Styx*  12/24/03, last change 9/17/01
    if(!present("note",TO))
      new("/d/tharis/obj/bnote.c")->move(TO);
    TO->force_me("give note to "+TPQN);
    tell_room(ETO,"The beggar disappears into the crowd.");
    TO->move("d/shadowgate/void");
    TO->remove();
  }
  return 1;
}
