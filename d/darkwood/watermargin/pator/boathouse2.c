//	Krugan's Boathouse
//	Pator@Shadowgate
//	04/06/95
//	Darkwood Forest Area
//      Pator@ShadowGate
//	boathouse2.c

#include <boathouse.h>

inherit ROOM;

int go_east(){
    if(present("hollow sword",this_player())){
    message("my action","A voice from inside your head tells you : Don't forget  to enter the hole !",this_player());  }
             }

int go_enter(){
    if(present("krugan")){
      if (!present("hollow sword",this_player())){
      write("Kurgan is annoyed when you try to move the chest !!!\n");
      tell_room(environment(this_player()),"Krugan grins as "+this_player()->query_cap_name()+" tries to move the chest",
                ({this_player()}));
      return 0;}
      else{
      tell_room(environment(this_player()),"Krugan smiles",
                ({this_player()}));
      return 1;}}
    else { return 1;}} 

int move(string str){
    if (!str) {
	notify_fail("Move what ???");
	return 0; }
    if (!(str="chest"))	{
	write("You think you are terrific trying to move the "+str);
	return 1;	} 
    else {
    if(present("krugan")){
      if (!present("hollow sword",this_player())){
      write("Kurgan is annoyed when you try to move the chest !!!\n");
      tell_room(environment(this_player()),"Krugan grins as "+this_player()->query_cap_name()+" tries to move the chest",
                ({this_player()}));
      return 0;}
      else{
      tell_room(environment(this_player()),"Krugan smiles",
                ({this_player()}));
      return 1;}}
    else { return 1;}}} 

void create() {
    ::create();
    set_light(1);
    set_indoors(1);
    set_short("Inside Krugan's Boathouse");
	set("day long",
@DAY
You are inside the boathouse.  As you look around you you see all sorts of boats.
Also many ropes are lying here and even more sail is hanging to dry here.
Also a chest get's your attention, but the lock seems to be very difficult
to pick.	
DAY
);
set("night long",
@NIGHT
You are inside the boathouse.  Only a torch lights the interior and you can hardly make out any details, but you see sail that is hanging to dry here.
Also a chest get's your attention, but the lock seems to be very difficult
to pick for there is also a dail on it.
NIGHT
);
    set_items( (["ropes" :
	         "The are lots and lots of ropes, more then enough to build a ropebridge",
		 "sail" : "Lots and lots of sails hang out here to dry",
		 "chest" : "The chest is really tucked away behind some ropes"
		]));
   
    set_listen("default" , "You hear someone carving of wood");
    set_listen("carving" , "What do you think you hear ??");
    set_listen("water" , "You aren't amazed that the rippling hasn't ceased");
    set_smell("default" , "The smell of tar whirles around in your nose.");
    set_smell("tar" , "The tar smells very very very ......");

    set_exits(
              (["west" : WATERM_BH+"boathouse3",
		"east" : WATERM_BH+"boathouse1",
		"enter" : WATERM_BH+"boathouse5"]) );
    set_invis_exits( ({"enter"}));
    set_pre_exit_functions( ({"east","enter"}), ({"go_east","go_enter"}));

}



reset() {
     ::reset();
     if(!present("krugan")) {
         new(WATERM_BH+"krugan")->move(this_object());
                           }
        }

       
