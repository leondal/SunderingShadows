//Coded by Lujke//
#include <std.h>
#include <daemons.h>
#include "../tunnel.h"
#define DAY 24000   // 20 seconds in one minute
                    // 60 minutes in one hour
                    // 20 hours in one day

inherit TUNNELS + "passroom.c";

string long_desc();
string random_note();
void add_monsters();
int say_password(string str);

void create(){
  ::create();
  set_short("A guard's office");
  set_long( (:TO,"long_desc":));
  set_property("indoors",1);
  set_property("light",2);
  set_smell("default","The air smells grubby, with a strong smell of"
                     +" sweat and other less pleasant odours");
  set_listen("default","You can hear a few faint whimpers");
  set_exits( ([

        "north":TUNNELS+ "tun19",
        "south":TUNNELS+ "cell",
         "east":TUNNELS+"barracks"
    ]) ); 
  set_door("door",TUNNELS + "tun19","north",0);
  set_door("iron door",TUNNELS + "cell","south",0);
  set_lock_description("iron door","lock","%^MAGENTA%^A %^BOLD%^"
                                         +"%^YELLOW%^complex%^RESET%^"
                                         +"%^MAGENTA%^, cruciform lock");
  lock_difficulty("iron door",40,"lock");
  set_items( ([ 
            "desk" : "A plain desk, with a few papers on it",
            "chair": "A simple wooden chair",
           "papers": "Looks like some prisoner lists, a few odd scraps"
                    +" of notes, and some sort of log.",
({ "list","lists"}): ({"There aren't any names you recognise on the"
 +" list","There aren't any names you recognise on the list","common"}),
 "log" : ({"A log of some sort. You could probably read it.",(:"read_log":),"common"}), 
({ "note","notes"}): ({"There are a few notes written on odd scaps of"
      +" paper. You could probably read them.",(:"read_notes":),"common"}) 
  ]) );

  set_property("no teleport",1);

}

void init(){
  ::init();

}

void reset(){
  ::reset();
  if (sizeof(all_living(TO))<1)
  {
    new(MOB+"jerax")->move(TO);
  }
}

string long_desc(){
     return "Quite incongruous within the rest of the tunnel complex,"
           +" this is a plainly appointed office, with a desk and a chair"
           +" and not much else. A small sign on the desk says"
           +" 'Questions? Please ask your friendly neighbourhood guard.'"
           +" This has been scrawled in bright colours and may be"
           +" intended to be ironic. At the far end of the office, past"
           +" the desk, is a heavy iron door";
}

string read_log(){
  int i, day_num, now;
  string log;
  day_num = query_day_number();
  now = time();
  log = "The log reads:\n\n%^YELLOW%^Treasury Passwords\n";
  for (i=0;i<6;i++){
    log += "\n%^GREEN%^" + day(now) + "%^BOLD%^%^BLACK%^:%^RESET%^"
          +"%^CYAN%^\t" + query_commword(day_num) + "\n";
    day_num ++;
    now += DAY;
  }
//  tell_room(TO, TPQCN + " looks over the log on the desk", TP);
  return log;
}

string read_notes(){
  string note;
  note = "You pick up one of the notes at random and read:\n\n";
  switch (random(4)){
  case 0:
    note += "The orders are secret and will not be distributed until the"
          +" time is ready. Until then keep your mouths shut and your"
          +" ears open. And be ready.\n\n"
    
          +"Vashud jorrkzd ngzd vleshd unz den ngx kurgh lashurkazn"
          +" carrgl vashud turr ng neding. Carrgl orgx niptraz bhaarg"
          +" grumchunzd denhash unz bhaarg haratchzd hash. Unz kurgh"
          +" neding.";
    break;
  case 1:
    note += "There will be outside training over the next week. You will"
          +" conquer your fear of the light or else you will be the next"
          +" sacrifice to have their life ended.\n\n"

          +"Deneah ngx kurgh jrxszzat shlugduchn omzkhar vashud klem"
          +" nearkz. Bhag ngx inngzaz bhaarg znnuslah flsh vashud blershz"
          +" snk bhag ngx kurgh vashud klem krsplshacz glun praxag"
          +" vahoren denwarz nekzn.";
    break;
  case 2:
    note += "Make sure the devilkin nests are kept high out of reach, so"
          +" that the faeces do not drop down the walls to the floor.\n\n"

          +"Slarnglax vashud baatluz flenx ngzd niptrazn fleg jrx flsh"
          +" glush, glch vahkarr vashud kerlgrukz denverz klun hgden"
          +" vashud barglzd.";
    break;
  case 3:
    note += "The phylactery of health was most problematic to obtain."
          +" Ensure it is carefully stored in the treasury.\n\n"

          +"Vashud nrshgathz flsh spruz ngzn wrch ashgrazlerg glun nak."
          +" Slarnglax glt ng dentarkzn shnerrgurkhjing golm vashud"
          +" jarkhz";
    break;
  }
  return note;
}

