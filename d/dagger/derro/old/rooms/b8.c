#include <std.h>
#include "../derrodefs.h"

inherit CROOM;

void create(){
  set_monsters( ({MON"derro1", MON"derro2", MON"derro3" }), ({1,1,1}) );
  ::create();
  set_repop(75);
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
   set_name("Sharply sloping ramp");
  set_short( "%^RED%^%^Sharply sloping ramp%^" );
  set_long(
  "%^RED%^%^Sharply sloping ramp%^RESET%^\n"
"  This ramp slopes up to the west and down to the east.   The roof here has a dimly glowing red globe that throws little light."
  "  The passageway continues up to a rock face and then stops there, leaving no way out."
  "\n"
  );
  set_smell("default",
  "You get the occasional whiff of the scent of decaying flesh."
  );
  set_listen("default",
  "You can hear nothing but the occasional chirp of a rat somewhere in the distance"
  );
  set_items(([
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "walls":"Carved from the roots of the world with a careful eye and a strong arm.",

  ({"rock","rock face","face"}):"It's a massive stone block that's been set over the passageway.  There is a small square depression in it.",
  "depression":"It's square and you're sure something could be pressed into it.",
  "globe":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"Damn near 25 feet at the peak from the floor, almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "east":ROOMS"b7",
  ]));
}
void init(){
  ::init();
  add_action("press_cube","press");
  add_action("pass_wall","pass");
}
int press_cube(string str){
  object *obs;
  int flag,x;
  if(!str || str !="cube against depression"){
    notify_fail ("Press what against what?\n");
  return 0;
    }
  flag=0;
  obs=all_inventory(TP);
  for (x=0;x<sizeof(obs);x++)
  if(obs[x]->id("stone cube")){
  flag=1;
  if(flag){
    message("my_action","You press the stone cube against the stone face and you suddenly sense that the rock knows you and will no longer impede your progress if you try to pass it.",TP);
 message("other_action",""+TPQCN+" presses a stone cube against the rock face and the cube is drawn into it!",environment(TP),TP);
  obs[x]->remove();
  flag=0;
  if(member_array("Friend of the Stone",TP->query_mini_quests())== -1) {
    TP->set_mini_quest("Friend of the Stone",100000,"You"
      " are a friend of the stones");
  }
  return 1;
  }
}
}
void reset(){
  ::reset();
/* changing to be controlled by CROOM for longer reboots since they wander *Styx*  11/28/02
  if(!present("derro warrior")){
  new(MON"derro1.c")->move(this_object());
  new(MON"derro2.c")->move(this_object());
  new(MON"derro3.c")->move(this_object());
  }
*/
}
int pass_wall()
{
    if(!objectp(TP)) { return 0; }
    if(!userp(TP)) { return 0; }
    
    if(TP->query_paralyzed() || TP->query_bound() || TP->query_unconscious())
    {
        return 0;
    }
    
    if(present("derro warrior"))
    {
        tell_object(TP,"The watchful Derro allow no one past!");
        return 0;
    }
    
    if(member_array("Friend of the Stone",TP->query_mini_quests())!=-1)
    {
        write("You trust the stone and attempt to walk through it.  It recognizes you and "
            "allows you to pass through");
        say("%^BOLD%^%^WHITE%^" +TPQCN+ " walks up the stone face and pauses for a second, "
            "then walks through it!",TP);
        TP->move_player(ROOMS"a1");
        return 1;
    } 
    else 
    {
        write("You attempt to walk through the wall and bang your head painfully!");
        say("%^BOLD%^%^WHITE%^"+TPQCN+" attempts to walk through the stone wall but "
            "just ends up with a sore nose!",TP);
        return 1;
    }
}
