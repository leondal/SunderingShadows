inherit "/std/room";

#include <std.h>
void create() {
     ::create();
     set_storage(1);
     set_terrain(STONE_BUILDING);
     set_travel(PAVED_ROAD);
     set_light(2);
     set_indoors(1);
    set_property("no teleport",1);
    set_property("no pocket space",1);
    set_name("council chamber");
     set_short("High Council Chamber of the Kinnesaruda");
      set_long("
    You enter a large ornate room.  Glittering red drapes line the walls and the ceiling is accented by gold and colored glass.  A long, shiny, black table stretches out before you.  Around it sit ten chairs and a remarkable silver throne.  
    The lighting here seems to vary in brightness and fluctuates from very bright to almost pitch black.  At the far end of the room, two large black obelisks stand on either side of a glowing portal.
%^BOLD%^%^BLUE%^A Mysterious Portal is here.
");
     set_smell("default", "%^BOLD%^A glowing symbol appears on the table for a moment, then fades away.\n");
     set_items( ([
              "symbol" : "It is the ensignia of the Kinnesaruda.  It glows and fades atop a long obsidian table.",
              "obelisks" : "The opelisks are about 8 feet tall and are completely smooth.",
              "portal" : "It is a spinning vortex of blue light.",
              "drapes" : "The lavish drapes are a deep crimson velvet with ornate gold embroidery.",
              "throne" : "It is the chair of a ruler of an empire!",
            "ceiling" : "The high vaulted ceiling is decorated in a dizzying array of patterns and murals.",
            "table" : "The magnificent obsidian table is smoother and shinier than anything you have ever encountered.  Within it's translucent surface, an ancient symbol glows."
]) );
}
void reset() {
    int i;
    object *tmp;
  ::reset();
    tmp = all_living(TO);
    if(pointerp(tmp))
    {
        for(i=0;i<sizeof(tmp);i++)
        {
            if(tmp[i]->is_player() && !tmp[i]->query_true_invis()) { return; }
        }
    }
    if(!present("intruder"))
    if(!present("autarkis"))
      new("d/attaya/mon/intruder")->move(this_object());
}
void init() {
  ::init();
  add_action("whistle", "whistle");
   add_action("rebuke", "rebuke");
   add_action("rush", "rush");
  add_action("enter", "enter");
  add_action("master", "master");
}
int whistle(string str) {
  write("You whistle for backup.",TP);
       tell_room(TO,"As "+TPQCN+" whistles for backup "+TP->query_possessive()+" eyes concentrate on a spot on the floor nearby.",TP);
  write("You grin evilly as a dark figure begins to take shape.\n");
  say((string)this_player()->query_cap_name()+" grins to you evilly as a dark form begins to take shape.\n");
  this_player()->add_hp(-(random(5)));
        call_out("backup",1,TP);
  return 1;
}
void backup(object targ){
        object ob;
        if(objectp(targ)){
                if(present(targ->query_name())){
                        tell_room(TO,"The shadows congeal and begin to take the shape of a figure");
                        tell_room(TO,"A dark warrior emerges from the shadows nearby!");
                       ob=new("/d/attaya/mon/uwarrior");
                        ob->move(TO);
               }
          }
}

int enter(string str) {
  if(str=="portal") {
 if(present("intruder")) {
    write("The portal has been sealed by the evil in this room.");
    return 1;
}

  write("%^CYAN%^You enter the mysterious portal.\n");
  say((string)this_player()->query_cap_name()+" enters the mysterious portal.\n");
  this_player()->move_player("/d/attaya/firedock");
  return 1;
}
return 0;
}

int rebuke(string str) {
  if(str=="intruder") {
 if(present("intruder")) {
    write("%^BOLD%^Intruder laughs at your pathetic little god.");
    write("%^BOLD%^%^BLUE%^Intruder strikes you down with all the powers of darkness to teach you a lesson.");
 this_player()->do_damage(-(random(200)));
    return 1;
}
  write("%^CYAN%^You simply can't.\n");
  return 1;
}
return 0;
}
int rush(string str) {
  if(str=="intruder") {
 if(present("intruder")) {
   write("%^BOLD%^Intruder sees you break from your attack.");
  write("%^BOLD%^%^RED%^Intruder grabs you and slams your head against the ceiling.");
 this_player()->add_hp(-(random(300)));
   return 1;
}
 write("%^CYAN%^You simply can't.\n");
  return 1;
}
return 0;
}
int master(string str) {
       tell_room(TO,"As "+TPQCN+" dies, he mutters one final chant.
"+TP->query_possessive()+" soul escapes through the ceiling
and there is a sudden rush of ancient air.",TP);
       call_out("evil",1,TP);
  return 1;
}
void evil(object targ){
        object ob;
                      tell_room(TO,"%^BOLD%^%^RED%^Intruder's blood drips onto the massive glowing symbol.");
                       tell_room(TO,"%^BOLD%^A horrible entity begins to rise from the bloody symbol, and you feel an evil power unlike any you have known");
                       ob=new("/d/attaya/mon/autarkis");
                       ob->move(TO);
}
